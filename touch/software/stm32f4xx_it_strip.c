#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_tim.h"
#include <sys/unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/times.h>
#include "misc.h"
#include "resources.h"
#include "macros.h"

// TODO: fix at the end
#define MAXMODES 8
#define MAXBASE 15

uint32_t maxovermin[MAXMODES]={15,15,31,0, 0,0,0,0}; // to fill in as we go
uint32_t maxplaymin[MAXMODES]={31,15,31,0, 0,0,0,0};
uint32_t maxrecmin[MAXMODES]={1,1,1,0, 0,0,0,0};


#define TOPS 0b11111111111111110000000000000000

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRKF 8 // for freezer. 8 with 24 divider ////now 48 with divider of 8; was 8 when we have have divider in main as 32... too high causes issues for speed of freezes
#define BRK 8 // was 128 - for other toggles...
#define DELB 64 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK -- is delay we hold the the freeze/toggle
#define DELA 32 // for clear DAC // was 64

#define HOLDRESET 800 // time for full reset when hold the mode down - over 4 seconds
#define SHORTMODE 8 // was 20ms could be shorter...
#define LONGMODE 140 // 1sec

#ifdef fouronethree
#define MAXREC 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#define DOUBLEMAXREC 19000
#else
#define MAXREC 3800 // for older STM
#define DOUBLEMAXREC 7600
#endif
// with F413 we have 9000 which is how long - 21 seconds now on 24 divider

GPIO_InitTypeDef GPIO_InitStructure;

void send_command(int command, void *message)
{
   asm("mov r0, %[cmd];"
       "mov r1, %[msg];"
       "bkpt #0xAB"
         :
         : [cmd] "r" (command), [msg] "r" (message)
         : "r0", "r1", "memory");
}

char buffx[10];

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}


#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < DELB; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delay2()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < DELA; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)


#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)


extern __IO uint32_t adc_buffer[8];
static uint32_t recordings[8][MAXREC+1]={0}; // 
static uint32_t rec_cnt[8]={0,0,0,0, 0,0,0,0};
static uint32_t spd_cnt[8]={0,0,0,0, 0,0,0,0};
static uint32_t over_cnt[8]={0,0,0,0, 0,0,0,0};
static uint32_t play_spd_cnt[8]={0,0,0,0, 0,0,0,0};
static float play_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
static float play_cnt_lop[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
static float ownplay_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
//static uint32_t tgr_cnt[10]={0};
static uint32_t rec=0, play=0;

static uint32_t SENSESHIFT=2, SENSEOFFSET=1800; // offset is minus!
//static uint32_t SENSESHIFT=1, SENSEOFFSET=560; // lower sensitivity

//static uint32_t shifter[8]={2,2,2,2,2,2,2,2}; // shifter seperates vca from cv - VCA comes first
//static uint32_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here
uint32_t previousone[8]={3,0,1,2, 7,4,5,6}; // lowest voltage=4?, then VCAs from bottom order=0,1,2,3, 4,5,6,7

//static uint32_t order[8]={7,6,5,4,3,2,1,0}; // 03 is VCA from bottom
//static uint32_t order[8]={5,5,5,5,5,5,5,5}; // 0-3 is VCA from bottom

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}

inline static uint32_t speedsample(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); // adapted for top bits

      return (uint32_t)sample;
}

inline static uint32_t speedsampleD(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){ // double length
  uint32_t lowerPosition, upperPosition;
  uint32_t samplelower, sampleupper;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  if (lowerPosition<MAXREC) samplelower=(samples[lowerPosition]&4095);
  else samplelower=(samples[lowerPosition-MAXREC]>>16);

  if (upperPosition<MAXREC) sampleupper=(samples[upperPosition]&4095);
  else sampleupper=(samples[upperPosition-MAXREC]>>16);

  
  float sample= ((samplelower) + 
		 (res *
		  ((sampleupper) - (samplelower))));

      return (uint32_t)sample;
}

inline static uint32_t speedsampletop(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]>>16) + 
		 (res *
		  ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); // adapted for top bits

      return (uint32_t)sample;
}

inline static uint32_t speedsamplelop(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt_lop[dacc]=mod0(play_cnt_lop[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt_lop[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt_lop[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); // adapted for top bits

      return (uint32_t)sample;
}

inline static uint32_t speedsampleloptop(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt_lop[dacc]=mod0(play_cnt_lop[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt_lop[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt_lop[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]>>16) + 
		 (res *
		  ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); // adapted for top bits

      return (uint32_t)sample;
}


inline static uint32_t speedsamplecopy(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples, uint32_t *copyinto){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); // adapted for top bits

  copyinto[lowerPosition]=samples[lowerPosition];
  
  return (uint32_t)sample;
}

inline static uint32_t ownspeedsample(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){ // for upper speed bits // returns these
  uint32_t lowerPosition, upperPosition;
  
  ownplay_cnt[dacc]=mod0(ownplay_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)ownplay_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(ownplay_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]>>16) + 
		 (res *
		  ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); // adapted for top bits

      return (uint32_t)sample;
}

inline static uint32_t speedsamplestart(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition+start]&4095) + 
		 (res *
		  ((samples[upperPosition+start]&4095) - (samples[lowerPosition+start]&4095)))); // adapted for top bits

      return (uint32_t)sample;
}

inline static void resetx(uint32_t which){
  for (uint32_t y=0;y<MAXREC;y++){ 
    recordings[which][y]=0;
  }
}

typedef struct listy_ { 
  uint32_t start[120];  
  uint32_t gap[120];
  uint32_t length[120];
  float speed[120];
} hands;

static hands fingers[8];
static uint32_t howmanyfingers[8]={0,0,0,0, 0,0,0,0};

// STARTY
void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t global_time=0; // also in resett
    static uint32_t daccount=0, entryp=0, entryn=0, entryr=0, entryo=0;
    static uint32_t speed=0, overlap[8]={0};
    static float speedy, alpha[8]={0,0,0,0, 0,0,0,0};
    static uint32_t starty[8]={0,0,0,0, 0,0,0,0}, target[8]={0,0,0,0, 0,0,0,0};
    static int32_t result[8]={0,0,0,0, 0,0,0,0};
    volatile uint32_t k;
    uint32_t j,x,y;//
    static uint32_t val;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t prev[8]={1,2,3,4,5,6,7,0};
    uint32_t bits, lengg, where;
    uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10
    static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastvaluer[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayer[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayerr[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastspeed=0, lastspeedd=0;
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t first_round[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayspot[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playb[8]={0,0,0,0, 0,0,0,0};
    static uint32_t recd[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, secondrec=0, lastplay=0, added[8]={0}, modetoggle=0, newmode=0, counting=0, overlaid=0, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0,0,0,0,0,0,0,0}, freezetoggle[8]={0,0,0,0,0,0,0,0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, enderr[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, enderspd[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0}, baseminor=0,recminor=0,playminor=0,overminor=0,nadaminor=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0}, lastlastrec=0, llrec=0,lastlastplay, lastlast;
    static int32_t endpoint, togrec=0, togplay=0, helder=0, heldon=0, modeheld=0, modechanged=1, first=0, firsty[8]={0};
    static uint32_t testting=0;
    
    uint32_t tmp, trigd;
    int32_t midder, subs;

    uint32_t speeddiv[4]={1, 4, 16, 32};
    float speeddivisor[4]={1.0, 0.25, 0.0625, 0.03125}; /// ???

    uint32_t playoverlay, playspeed, playspeedmod, playfreeze, playrun, playlast;
    uint32_t recspeed;
    uint32_t overoverlay, overfreeze, overrun, overlast, overrec, overspeedmod;
    
    //    itoa(prev[0], buffx, 10);
    //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
    //  send_command(0x05/* some interrupt ID */, m);
	
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=778; // TESTY - 0 was 78. now new default to work on

	// so baseminor==0! just simple shift...
	//place all mods here even if we don't use them..
	baseminor=0;
	if (baseminor&1){
	  SENSESHIFT=2, SENSEOFFSET=1800; 
	}
	else
	  {
	    SENSESHIFT=1, SENSEOFFSET=560;
	  }

	//rec -nada
	
	//overlay
	overoverlay=((overminor>>1)&3); // 2 types of overlay
	overrec=((overminor>>3)&3); // type of recorded overlay 
	overspeedmod=((overminor>>5)&1);// 

	//play
	playoverlay=((playminor>>1)&3); // 4 types of overlay
	playspeed=((playminor>>3)&1); // 2 types speed 
	playfreeze=((playminor>>4)&1); // 2 types freeze
	playspeedmod=((playminor>>5)&2);  //

	//	mode=fingers[0].length[10]; // just to test array	
	switch(mode){
	case 111: // test noise/glitch
	  values[daccount]=4095;
	  break;

	case 112: // test if we have 0 for silence modes
	  REALADC;
	  if (real[daccount]==0) values[daccount]=0;
	  else values[daccount]=4095;
	  break;
	  
	  /// MODE 0! ///////////////////////	  
	case 0: 
	  FREEZERS;
          REALADC;
	  // manage 4 states: play, rec, overlay, nada
	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  } // rec and play
	  else overlaid=0;
	  // if we leave overlaid via. exit from play
	  if (lastmode==1 && play==0) { // lastmode==1 was overlaid
	    rec=0; 
	    lastmode=0;
	    overlaid=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // PLAY*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    RESETFRP; // clear freezers but only on entering
	    lastmode=0; 
	    //	    if (overlap[daccount]) ender[daccount]=DOUBLEMAXREC;

	    // rework playback and freezings - now 12/10
	    // TODO: re-work [6] so playback is VALUE and real is speed which can be frozen
	    //	    speed=real[6]>>2;
	    if (daccount==6){ // freeze speed only // 		  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits // we don't overlay on [6]
		if (freezetoggle[6])
	    {
	      lastvalue[6]=real[6];
	      freezetoggle[6]=0;
	    }
	  else { 
	    if (real[6]<lastvalue[6]) speed=lastvalue[6]>>2;
	    else speed=real[6]>>2;
	  }

		if (playspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
		else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	    } 
	    else { /// NOT [6]
	    if (playfreeze==0){  	    // 0 just freeze overlay and keep playing, 1 stops - what of speed in [6] though
	      if (playspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    }
	      else if (playfreeze==1){ // stop play above
		if (frozen[daccount]) values[daccount]=lastplayer[daccount];
		else {
	      if (playspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		}
	      }
	    }
		    /////////////////////		    
	    if (playoverlay==0){ //usual
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (playoverlay==1){ // mod
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (playoverlay==2){ // >
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]%4096;
	    }
	    else if (playoverlay==3){ // subtract
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	  } //play
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  ///// REC*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	    RESETFRR; // clear freezers
	    LASTREC; // reset all only on entering
	    lastmode=0;

	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	      values[daccount]=(real[daccount]);
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + real[daccount]; // keep top values...
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(real[daccount]<<16); // top bits
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>DOUBLEMAXREC) {
		rec_cnt[daccount]=0; // overwrites now top and bottom - but should keep top
		//		overlap[daccount]=1;
		ender[daccount]=DOUBLEMAXREC-1;
	      }
	  }
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // OVERLAY*
	  //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      RESETFRO; // clear freezers
	      
	      LSTRECPLAYD; 
	      lastmode=1;
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits

	    if (daccount==6){ // freeze speed // 		  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      if (freezetoggle[6])
	    {
	      lastvalue[6]=real[6];
	      freezetoggle[6]=0;
	    }
	  else { 
	    if (real[6]<lastvalue[6]) speed=lastvalue[6]>>2;
	    else speed=real[6]>>2;
	  }
	      values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      lastplayer[daccount]=values[daccount];
	    } // [6]
	    else {
	      values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    /////////	      
	    if (overoverlay==0){ //usual - now swopped for >
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (overoverlay==1){ // mod
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (overoverlay==2){
	      values[daccount]+=real[daccount];
	      values[daccount]=values[daccount]%4096;
	    }
	    else if (overoverlay==3){
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	    }	      
	    // different overlays
	    if (overrec==0){
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(values[daccount]<<16); // top bits
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==1){
	      tmp=(recordings[daccount][rec_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + tmp; 
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(tmp<<16); // top bits
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==2){
	      if ((int)play_cnt[daccount]<MAXREC) recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + values[daccount];
	      else recordings[daccount][(int)play_cnt[daccount]-MAXREC]=(recordings[daccount][(int)play_cnt[daccount]-MAXREC]&4095)+(values[daccount]<<16); // top bits	      
	    }
	    else if (overrec==3){
	      tmp=(recordings[daccount][(int)play_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      if ((int)play_cnt[daccount]<MAXREC) recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + tmp;
	      else recordings[daccount][(int)play_cnt[daccount]-MAXREC]=(recordings[daccount][(int)play_cnt[daccount]-MAXREC]&4095)+(tmp<<16); // top bits	      
	    }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }
	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	    }
	      values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	    /// MODE 1! ///////////////////////
	case 1: // as 0 but with no speed on [6]
	  FREEZERS;
          REALADC;

	  // manage 4 states: play, rec, overlay, nada
	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  } // rec and play
	  else overlaid=0;
	  // if we leave overlaid via. exit from play
	  if (lastmode==1 && play==0) { // lastmode==1 was overlaid
	    rec=0; 
	    lastmode=0;
	    overlaid=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // PLAY*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    RESETFRP; // clear freezers but only on entering
	    lastmode=0; 
	    //	    if (overlap[daccount]) ender[daccount]=DOUBLEMAXREC;

	    // rework playback and freezings - now 12/10
	    // TODO: re-work [6] so playback is VALUE and real is speed which can be frozen
	    speed=0;

	    if (playfreeze==0){  	    // 0 just freeze overlay and keep playing, 1 stops - what of speed in [6] though
	      values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	      }
	      else if (playfreeze==1){ // stop play above
		if (frozen[daccount]) values[daccount]=lastplayer[daccount];
		else {
		  values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		}
	      }

		    /////////////////////		    
	    if (playoverlay==0){ //usual
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (playoverlay==1){ // mod
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (playoverlay==2){ // >
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]%4096;
	    }
	    else if (playoverlay==3){ // subtract
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	  } //play
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  ///// REC*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	    RESETFRR; // clear freezers
	    LASTREC; // reset all only on entering
	      lastmode=0;

	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	      values[daccount]=(real[daccount]);
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + real[daccount]; // keep top values...
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(real[daccount]<<16); // top bits
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>DOUBLEMAXREC) {
		rec_cnt[daccount]=0; // overwrites now top and bottom - but should keep top
		//		overlap[daccount]=1;
		ender[daccount]=DOUBLEMAXREC-1;
	      }
	  }
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // OVERLAY*
	  //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      RESETFRO; // clear freezers
	      
	      LSTRECPLAYD; 
	      lastmode=1;
	      speed=0; // 24/4 // 25/4 now 12 to 10 bits

 	      values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    /////////	      
	    if (overoverlay==0){ //usual - now swopped for >
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (overoverlay==1){ // mod
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (overoverlay==2){
	      values[daccount]+=real[daccount];
	      values[daccount]=values[daccount]%4096;
	    }
	    else if (overoverlay==3){
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);	   
	    }
	    // different overlays
	    if (overrec==0){
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(values[daccount]<<16); // top bits
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	      }	    
	    }
	    else if (overrec==1){
	      tmp=(recordings[daccount][rec_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (rec_cnt[daccount]<MAXREC) recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + tmp; 
	      else recordings[daccount][rec_cnt[daccount]-MAXREC]=(recordings[daccount][rec_cnt[daccount]-MAXREC]&4095)+(tmp<<16); // top bits
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==2){
	      if ((int)play_cnt[daccount]<MAXREC) recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + values[daccount];
	      else recordings[daccount][(int)play_cnt[daccount]-MAXREC]=(recordings[daccount][(int)play_cnt[daccount]-MAXREC]&4095)+(values[daccount]<<16); // top bits	      
	    }
	    else if (overrec==3){
	      tmp=(recordings[daccount][(int)play_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      if ((int)play_cnt[daccount]<MAXREC) recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + tmp;
	      else recordings[daccount][(int)play_cnt[daccount]-MAXREC]=(recordings[daccount][(int)play_cnt[daccount]-MAXREC]&4095)+(tmp<<16); // top bits	      
	    }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }
	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 2: // global record of speeds in [6] top
	  FREEZERS;
          REALADC;

	  // manage 4 states: play, rec, overlay, nada
	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  } // rec and play
	  else overlaid=0;
	  // if we leave overlaid via. exit from play
	  if (lastmode==1 && play==0) { // lastmode==1 was overlaid
	    rec=0; 
	    lastmode=0;
	    overlaid=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // PLAY*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    RESETFRP; // clear freezers but only on entering
	    lastmode=0; 
	    //	    if (overlap[daccount]) ender[daccount]=DOUBLEMAXREC;

	    // rework playback and freezings - now 12/10
	    // TODO: re-work [6] so playback is VALUE and real is speed which can be frozen
	    // ??? if (daccount==6)
	    if (!playspeedmod) {
	      speed=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if ((real[6]>>2)>speed) speed=real[6]>>2; // only if is more than
	    }
	    else {
	      speed=real[6]>>2;
	      speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023; // other option is > : // test this now
	    }
	    if (frozen[6]==1){ // we record the speed
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[6]<<16); // top 16 bits are speed <<18 as we shifted // ALT to above
	      }
	    ////////
	    if (daccount==6) // we just playback
	      {
		speed=real[6]>>2; // no speedrec used ever
	      if (playspeed) values[daccount]=speedsample(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	      }
	    else // [6]
	      {
		if (frozen[daccount]) speed=real[6]>>2; // toggle recorded speed on/off
	      if (playspeed) values[daccount]=speedsample(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      lastplayer[daccount]=values[daccount];
	      
	      /////////////////////		    
	    if (playoverlay==0){ //usual
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (playoverlay==1){ // mod
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (playoverlay==2){ // >
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]%4096;
	    }
	    else if (playoverlay==3){ // subtract
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	      } // NOT 6
	  } //play
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  ///// REC*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	    RESETFRR; // clear freezers
	    LASTREC; // reset all only on entering
	      lastmode=0;

	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount]; // don;t keep top values to erase speed on new rec!
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0; // overwrites now top and bottom - but should keep top
		//		overlap[daccount]=1;
		ender[daccount]=MAXREC-1;
	      }
	  }
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // OVERLAY*
	  //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      RESETFRO; // clear freezers
	      LSTRECPLAYD; 
	      lastmode=1;
	      
	    if (daccount==6){ // we just playback - no speedrec ever used...
	      speed=real[6]>>2; // no speedrec used ever
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      lastplayer[daccount]=values[daccount];
	    } // [6]
	    else {
	    if (!playspeedmod) {
	      speed=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if ((real[6]>>2)>speed) speed=real[6]>>2; // only if is more than
	    }
	    else {
	      speed=real[6]>>2;
	      speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023; // other option is > : // test this now
	    }
	      if (frozen[daccount]) speed=real[6]>>2; // toggle recorded speed on/off
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    /////////	      
	    if (overoverlay==0){ //usual - now swopped for >
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (overoverlay==1){ // mod
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (overoverlay==2){
	      values[daccount]+=real[daccount];
	      values[daccount]=values[daccount]%4096;
	    }
	    else if (overoverlay==3){
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	    } // NOT [6]	      
	    // different overlays
	    if (overrec==0){
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...= speed
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==1){
	      tmp=(recordings[daccount][rec_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + tmp; 
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==2){
	      recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + values[daccount];
	    }
	    else if (overrec==3){
	      tmp=(recordings[daccount][(int)play_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + tmp;
	    }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }
	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 
	    //////////////////////

	case 3: /// 3. record local speeds - could be local triggering and all take [6] as voltage - so no other use of freeze and [6] left alone
	  // so can be as case 2 mods but no freeze/triggers ....
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;

	    speed=real[6]>>2;
	    speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	    if (speed>1023) speed=1023; 

	    if (frozen[daccount]==1){ // we record the speed with toggle on any daccount...
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[6]<<16); // top 16 bits are speed <<18 as we shifted // ALT to above
	    }
	    
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      //	      speed=real[6]>>2;
	      speed=real[6]>>2;
	      speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023;

	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  
	      values[daccount]+=real[daccount]; 
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...= speed
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	    ////

	case 4: /// 4. record local speeds using local voltage:
	  // so use TOGGLE to initiate speed rec, use voltage as speed - in play only...
	  // what is speed in overlay - always recorded speed - not added to [6] ?
	  // and overlay in overlay = not except for VCAs
	  
	  // note from case 3 above: so can be as case 2 mods but no freeze/triggers ....
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;

	    speed=real[daccount]>>2;
	    speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	    if (speed>1023) speed=1023; 

	    if (frozen[daccount]==1){ // we record the speed with toggle on any daccount...
	      where=(int)ownplay_cnt[daccount];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[daccount]<<16); // 
	    }
	    
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (daccount<4){ // // not for voltages but for VCA or vice versa... so no overlap obviously for voltages
	    values[daccount]+=real[daccount]; 
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ // what does toggle/freeze do in this case?
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      //	      speed=real[6]>>2;
	      speed=real[daccount]>>2;
	      speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023;

	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);  
	      if (daccount<4) {
		values[daccount]+=real[daccount];  // VCA only overlay
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...= speed
	      } // recordings overlay only for VCA or not???
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	    /////////////
	case 5: // loopy overlay
	  /*
	    overlay one repeating section with different overlays *REWORK mode 79, we can store original loop there(where?), and expand overlay in top bits ???*
	    so we store loop in bottom (so rec stays same) and expanding overlay is up to max length. decide what to do with speed but attempt as basic speed
	    rework play and overlay. rec will rewrite all... top and bottom
	  */
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    // add overlay from top bits // question of seperate length for this...  enderr using speedsampleloptop
	    if (!frozen[daccount] && enderr[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
		enderr[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
	  // records to layer2(overlay) speed changes from layer1 and we hear those changes (we are in 1)
	  // what toggle can do!?
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      LSTRECPLAYD; // if we reset or not????
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (!enderr[daccount] || over_cnt[daccount]>enderr[daccount]) tmp=0; // plus we don't want to go past last enderr
	      else tmp=speedsampleloptop(logfast[speed], MAXREC, daccount, recordings[daccount]); // is fine I think as we don;t go past
	      if (!frozen[daccount]) values[daccount]+=tmp; // but we shouldnt add real to tmp???
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][over_cnt[daccount]]=(recordings[daccount][over_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
	      over_cnt[daccount]++;
	      if (over_cnt[daccount]>MAXREC) {
		over_cnt[daccount]=0;
		enderr[daccount]=MAXREC;
		firsty[0]=0; // first time round...
	      }
	  } // not overlaid//leaving
	    else {
	      enderr[daccount]=over_cnt[daccount];
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	case 6: // loopy overlay - as 5 but we keep length of overlay the same
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else tmp=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (!frozen[daccount]) values[daccount]+=tmp; // what toggle should do in this case??? just on playback
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 
	    
	case 7: // loopy overlay - as 5 but now toggle clears overlay in overlaid // toggle playback of it in play (as we had it)
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    // add overlay from top bits // question of seperate length for this...  enderr using speedsampleloptop
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
		enderr[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0] || frozen[daccount]) tmp=0;
	      else tmp=speedsampleloptop(logfast[speed], MAXREC, daccount, recordings[daccount]);
	      values[daccount]+=tmp; 
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		//		enderr[daccount]=MAXREC;
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 
	    
	case 8: // loopy overlay - as 6 but now toggle clears overlay in overlaid // toggle playback of it in play (as we had it) //so as above but no enderr
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0] || frozen[daccount]) tmp=0;
	      else tmp=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      values[daccount]+=tmp; 
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) {
		rec_cnt[daccount]=0;
	
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	case 9: // as 5: loopy overlay
	  /*
	    - stop/start overlay playback(also for other trad overlays) - if we stop playback there is no hold/frozen value...
	    but then we can't hear overlay playback... so makes no sense to record...
	  */
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    // add overlay from top bits // question of seperate length for this...  enderr using speedsampleloptop
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
		enderr[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else if (!frozen[daccount])
		{
		  tmp=speedsampleloptop(logfast[speed], MAXREC, daccount, recordings[daccount]);
		  values[daccount]+=tmp; 
		}
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      if (!frozen[daccount]) // minormode could also be if we keep running rec_cnt
		{
		  recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
		  enderr[daccount]=rec_cnt[daccount];
		  rec_cnt[daccount]++;
		  if (rec_cnt[daccount]>MAXREC) {
		    rec_cnt[daccount]=0;
		  }
		}
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	case 10: // as 5: loopy overlay
	  /*
	 /// for 10:	    - stop/start overlay recordings (is more like an island then) but playback still runs...
	  */
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    // add overlay from top bits // question of seperate length for this...  enderr using speedsampleloptop
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
		enderr[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else 
		{
		  if (!frozen[daccount]) tmp=speedsampleloptop(logfast[speed], MAXREC, daccount, recordings[daccount]);
		  else tmp=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]);
		  values[daccount]+=tmp; 
		}
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      if (!frozen[daccount]) // minormode could also be if we keep running rec_cnt - 
		{
		  recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
		  enderr[daccount]=rec_cnt[daccount];
		  rec_cnt[daccount]++;
		  if (rec_cnt[daccount]>MAXREC) {
		    rec_cnt[daccount]=0;
	      }
	    }
	  }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 	   

	    ///

	case 11: // loopy overlay - as 5 but we keep length of overlay the same - so as 6
	  /*
	    - stop/start overlay playback(also for other trad overlays) - if we stop playback there is no hold/frozen value...
	    but then we can't hear overlay playback... so makes no sense to record...
	  */
	  // and as 9 now above
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else if (!frozen[daccount])
		{
		  tmp=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		  values[daccount]+=tmp; 
		}
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      if (!frozen[daccount]) // minormode could also be if we keep running rec_cnt
		{
		  recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
		  rec_cnt[daccount]++;
		  if (rec_cnt[daccount]>ender[daccount]) {
		    rec_cnt[daccount]=0;
		  }
		}
	    }
	  else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break;

	case 12: // loopy overlay - as 5 but we keep length of overlay the same - so as 6
	  /*
	    - stop/start overlay playback(also for other trad overlays) - if we stop playback there is no hold/frozen value...
	    but then we can't hear overlay playback... so makes no sense to record...
	  */
	  // and as 10 now above
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else {
		tmp=speedsampleloptop(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		values[daccount]+=tmp; 
	      }
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      if (!frozen[daccount]) // minormode could also be if we keep running rec_cnt
		{
		  recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
		  rec_cnt[daccount]++;
		  if (rec_cnt[daccount]>ender[daccount]) {
		    rec_cnt[daccount]=0;
		  }
		}
	    }
	  else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break;	    

	case 13: // loopy overlay as 5 but...
	  /*
	    // 13 - works just for 5 - long length - freezetoggle 
	  */
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  }
	  else overlaid=0;

	  if (lastmode==1 && play==0) {
	    rec=0; // if we leave overlaid via. exit from play
	    lastmode=0;
	    overlaid=0;
	  }
          //////////////////////////////////////////////////////////////////////
          // PLAY*
          //////////////////////////////////////////////////////////////////////

	  if ((!overlaid) && play && ender[daccount]){
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    if (overlap[daccount]) ender[daccount]=MAXREC;
	    speed=0; // fixed speed for the moment 
	    values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	    // add overlay from top bits // question of seperate length for this...  enderr using speedsampleloptop
	    if (!frozen[daccount]) values[daccount]+=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]); // minormode of other freezes
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    lastplay=0;
	    entryp=0;
	  }
	  
          //////////////////////////////////////////////////////////////////////
          // REC*
          //////////////////////////////////////////////////////////////////////	  
	  if ((!overlaid) && rec){ 
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      ender[daccount]=rec_cnt[daccount];
	      enderr[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
		ender[daccount]=MAXREC;
		enderr[daccount]=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	      if (llrec==0)	      // when we enter we want to record from zero in top! but this can also be an option MINORMODE! alongside other reset...
		{
		  firsty[0]=1; // as we are all synced can be any firsty...
		  enderr[1]=MAXREC;
		  enderr[2]=MAXREC;
		  enderr[3]=MAXREC;
		  enderr[4]=MAXREC;
		  enderr[5]=MAXREC;
		  enderr[6]=MAXREC;
		  enderr[7]=MAXREC;
		}
	      else firsty[0]=0;
	      LSTRECPLAYD;
	      RESETFRO;
	      lastmode=1;
	      speed=0; 
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      if (firsty[0]) tmp=0;
	      else tmp=speedsampleloptop(logfast[speed], enderr[daccount], daccount, recordings[daccount]);
	      values[daccount]+=tmp; // but we shouldnt add real to tmp???
	      values[daccount]+=real[daccount];
	      tmp+=real[daccount];
	      if (tmp>4095) tmp=4095;
	      if (values[daccount]>4095) values[daccount]=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&4095)+(tmp<<16); // do we need another counter...??
	      if (freezetoggle[daccount]) {
		ender[daccount]=rec_cnt[daccount]; // could also be minormode to reset this or not...
		enderr[daccount]=rec_cnt[daccount];
		freezetoggle[daccount]=0;
	      }
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>enderr[daccount]) {
		rec_cnt[daccount]=0;
		//		enderr[daccount]=MAXREC;
	      }
	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

	case 14: // - try with new spd_cnt/play_spd_cnt: global record of speeds in [6] top
	  // when/where do we reset spd_cnt - it is another kind of tape - or rather tape counter!
	  // - *fix end of newer speed playback [14] so we dont go past - if it also matches recend or just loops*
	  FREEZERS;
          REALADC;

	  // manage 4 states: play, rec, overlay, nada
	  if (rec && play){
	    if (ender[daccount]) overlaid=1;
	    else {
	      overlaid=0;
	      play=0; // we have nothing to play
	    }
	  } // rec and play
	  else overlaid=0;
	  // if we leave overlaid via. exit from play
	  if (lastmode==1 && play==0) { // lastmode==1 was overlaid
	    rec=0; 
	    lastmode=0;
	    overlaid=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // PLAY*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    RESETFRP; // clear freezers but only on entering
	    lastmode=0; 
	    //	    if (overlap[daccount]) ender[daccount]=DOUBLEMAXREC;

	    // rework playback and freezings - now 12/10
	    // TODO: re-work [6] so playback is VALUE and real is speed which can be frozen
	    // ??? if (daccount==6)
	    if (!playspeedmod) {
	      speed=recordings[daccount][play_spd_cnt[daccount]]>>18;//(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if ((real[6]>>2)>speed) speed=real[6]>>2; // only if is more than
	    }
	    else {
	      speed=real[6]>>2;
	      speed+=(recordings[daccount][play_spd_cnt[daccount]]>>18); //(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023; // other option is > : // test this now
	    }
	    
	    if (frozen[6]==1){ // we record the speed
	      //	      where=(int)ownplay_cnt[6];
	      recordings[daccount][play_spd_cnt[daccount]]=(recordings[daccount][spd_cnt[daccount]]&4095)+(real[6]<<16); // top 16 bits are speed <<18 as we shifted // ALT to above
	    }
	    ////////
	    if (daccount==6) // we just playback
	      {
		speed=real[6]>>2; // no speedrec used ever
	      if (playspeed) values[daccount]=speedsample(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	      }
	    else // not [6]
	      {
		if (frozen[daccount]) speed=real[6]>>2; // toggle recorded speed on/off
		if (playspeed) values[daccount]=speedsample(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
		else values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	      }
	      /////////////////////		    
	    if (playoverlay==0){ //usual
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (playoverlay==1){ // mod
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (playoverlay==2){ // >
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]%4096;
	    }
	    else if (playoverlay==3){ // subtract
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	      play_spd_cnt[daccount]++;
	      if (play_spd_cnt[daccount]>rec_cnt[daccount]) { // loop on rec_cnt or we could force a loop// or use enderspd!
		play_spd_cnt[daccount]=0; 
	      }
	      spd_cnt[daccount]++;
	      if (enderspd[daccount]!=rec_cnt[daccount]) enderspd[daccount]=spd_cnt[daccount];
	      if (spd_cnt[daccount]>rec_cnt[daccount]) { 
		enderspd[daccount]=rec_cnt[daccount];
		spd_cnt[daccount]=0; 
	      }
	    } //play
	  else {
	    lastplay=0;
	    entryp=0;
	  }	  
	  //////////////////////////////////////////////////////////////////////
	  ///// REC*
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	    RESETFRR; // clear freezers
	    LASTREC; // reset all only on entering
	      lastmode=0;

	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	      values[daccount]=(real[daccount]);
	      recordings[daccount][rec_cnt[daccount]]=real[daccount]; // don;t keep top values to erase speed on new rec!
	      ender[daccount]=rec_cnt[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0; // overwrites now top and bottom - but should keep top
		//		overlap[daccount]=1;
		ender[daccount]=MAXREC-1;
	      }
	  }
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // OVERLAY*
	  //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      RESETFRO; // clear freezers
	      LSTRECPLAYD; 
	      lastmode=1;
	      
	    if (daccount==6){ // we just playback - no speedrec ever used...
	      speed=real[6]>>2; // no speedrec used ever
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      lastplayer[daccount]=values[daccount];
	    } // [6]
	    else {
	    if (!playspeedmod) {
	      speed=recordings[daccount][play_spd_cnt[daccount]]>>18;//speed=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if ((real[6]>>2)>speed) speed=real[6]>>2; // only if is more than
	    }
	    else {
	      speed=real[6]>>2;
	      speed+=(recordings[daccount][play_spd_cnt[daccount]]>>18);//speed+=(ownspeedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023; // other option is > : // test this now
	    }
	      if (frozen[daccount]) speed=real[6]>>2; // toggle recorded speed on/off
	      values[daccount]=speedsample(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
		if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    /////////	      
	    if (overoverlay==0){ //usual - now swopped for >
	      if (real[daccount]>values[daccount]) values[daccount]=real[daccount]; // only if is more than
	    }
	    else if (overoverlay==1){ // mod
	      values[daccount]+=real[daccount];
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else if (overoverlay==2){
	      values[daccount]+=real[daccount];
	      values[daccount]=values[daccount]%4096;
	    }
	    else if (overoverlay==3){
	      subs=values[daccount]-real[daccount];
	      values[daccount]=abs(subs);
	    }
	    play_spd_cnt[daccount]++;
	    if (play_spd_cnt[daccount]>rec_cnt[daccount]) { // 
	      play_spd_cnt[daccount]=0; 
	      }

	    } // NOT [6]	      
	    // different overlays
	    if (overrec==0){
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + values[daccount]; // keep top values...= speed
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==1){
	      tmp=(recordings[daccount][rec_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      recordings[daccount][rec_cnt[daccount]]=(recordings[daccount][rec_cnt[daccount]]&TOPS) + tmp; 
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>ender[daccount]) { // other micromodes here to extend maybe???
		rec_cnt[daccount]=0;
	    }
	    }
	    else if (overrec==2){
	      recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + values[daccount];
	    }
	    else if (overrec==3){
	      tmp=(recordings[daccount][(int)play_cnt[daccount]]&4095) + real[daccount];
	      if (tmp>4095) tmp=4095;
	      recordings[daccount][(int)play_cnt[daccount]]=(recordings[daccount][(int)play_cnt[daccount]]&TOPS) + tmp;
	    }

	    }
	    else {
	      llrec=0;
	      entryo=0;
	    }
	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	    if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    values[daccount]=(real[daccount]);
	    lastvaluer[daccount]=values[daccount];
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 
	    //////////////////////

	    
	    //////////////////////////////////////////////////////////////////////
	    //TESTING modes:
	    //////////////////////////////////////////////////////////////////////
	    
	case 777: // tests of all toggles! rec, play, mode and freeze
	  FREEZERS;
	  if (modetoggle) {  // frozen[daccount] //modetoggle // rec is fine...
	    values[4]=4095;
	  }
	  else values[4]=0;
	  break; /////

	case 778: // for hold timing tests below:
	  //	  if (baseminor==4) 	  {
	  //	    testting^=1; // testy
	  //	    baseminor=0;
	  //	  }
	  if (testting) { 
	    values[4]=4095;
	  }
	  else values[4]=0;
	  
	  //	  values[4]=baseminor*10;
	  break; /////	    
	}

	//	TOGGLES;      // only place where toggles - pulled out of ==8 section
	// see if works best there?
	
	WRITEDAC2;
	daccount++;
	if (daccount==8) {
	  global_time++;
	  daccount=0;
	  count++;
	  TOGGLES;      // only place where toggles
	// start to test for long or short mode hits
	  if (newmode){
	    newmode=0;
	    breaker[10]=0;
	    /* if (modeheld>10) { // 1000 is around 4 seconds and works // 10 is short */
	    /* modeheld=0; */
	    /* testting^=1; // testy */
	    /* } */

	    if (modeheld>HOLDRESET) { //reset all
	  modeheld=0;
	  RESETT;
	  //	  testting^=1; // testy
	}
	else if (modeheld>LONGMODE && modeheld<HOLDRESET) { // increment major mode
	  modeheld=0;
	  MODECHANGED;
	  mode++;
	  if (mode>MAXMODES) mode=0;
	  testting^=1; // testy
	}	
	else if (modeheld<LONGMODE){ //inc minor mode matrix
	  modeheld=0; // ??? was commented just for testing
	  //	  testting^=1; // testy triggers
	  baseminor++;
	  if (baseminor>MAXBASE) baseminor=0;
	  //  if (rec==0 && play==0) baseminor++; // we dont use so far
	  if (rec && play) {
	    overminor++;
	    if (overminor>maxovermin[mode]) overminor=0; // maxplaymin[mode]=xxx;
	  }
	  else if (rec) {
	    recminor++;
	    if (recminor>maxrecmin[mode]) recminor=0;
	  }
	  else if (play) {
	    playminor++;
	    if (playminor>maxplaymin[mode]) playminor=0;
	  }
	  }
	  } // newmode
    }
    }
  }
