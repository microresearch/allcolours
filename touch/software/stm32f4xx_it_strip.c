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

#define TOPS 0b11111111111111110000000000000000

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRKF 8 // for freezer. 8 with 24 divider ////now 48 with divider of 8; was 8 when we have have divider in main as 32... too high causes issues for speed of freezes
#define BRK 8 // was 128 - for other toggles...
#define DELB 64 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK
#define DELA 32 // for clear DAC // was 64

#define HOLDRESET 800 // time for full reset when hold the mode down - over 4 seconds
#define SHORTMODE 8 // was 20ms could be shorter...
#define LONGMODE 140 // 1sec

#define MAXMODES 8

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
static float play_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
static float play_cnt_lop[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
static float ownplay_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
//static uint32_t tgr_cnt[10]={0};
static uint32_t rec=0, play=0;

static uint32_t SENSESHIFT=2, SENSEOFFSET=1800; // for lowest sensitivity, higher would be 2 and 1800

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

inline static uint32_t ownspeedsample(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){ // for upper speed bits
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


// STARTY
void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t daccount=0, entryp=0, entryn=0, entryr=0, entryo=0;
    static uint32_t speed=1, overlap[8]={0};
    static float speedy, alpha[8]={0,0,0,0, 0,0,0,0};
    static uint32_t starty[8]={0,0,0,0, 0,0,0,0}, target[8]={0,0,0,0, 0,0,0,0};
    static int32_t result[8]={0,0,0,0, 0,0,0,0};
    volatile uint32_t k;
    uint32_t j,x,y;//
    static uint32_t val;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t prev[8]={1,2,3,4,5,6,7,0};
    uint32_t maxovermin[MAXMODES]={254,0,0,0, 0,0,0,0}; // to fill in
    uint32_t maxplaymin[MAXMODES]={63,0,0,0, 0,0,0,0};
    uint32_t maxrecmin[MAXMODES]={31,0,0,0, 0,0,0,0};
      
    uint32_t bits, lengg, where;
    uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10
    static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayer[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayerr[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastspeed=0, lastspeedd=0;
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t first_round[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayspot[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playb[8]={0,0,0,0, 0,0,0,0};
    static uint32_t recd[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, secondrec=0, lastplay=0, added[8]={0}, modetoggle=0, newmode=0, counting=0, overlaid=0, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0,0,0,0,0,0,0,0}, freezetoggle[8]={0,0,0,0,0,0,0,0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, enderr[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0}, baseminor=0,recminor=0,playminor=0,overminor=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0}, lastlastrec=0, llrec=0,lastlastplay, lastlast;
    static int32_t endpoint, togrec=0, togplay=0, helder=0, heldon=0, modeheld=0, modechanged=1, first=0, firsty[8]={0};
    static uint32_t testting=0;
    
    uint32_t tmp, trigd;
    int32_t midder, subs;

    uint32_t speeddiv[4]={1, 4, 16, 32};
    float speeddivisor[4]={1.0, 0.25, 0.0625, 0.03125}; /// ???

    uint32_t playreset, playoverlay, playspeed, playfreeze, playrun, playlast;
    uint32_t recreset, recspeed;
    uint32_t overreset, overoverlay, overspeed, overfreeze, overrun, overlast, overrec;
    
    //    itoa(prev[0], buffx, 10);
    //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
    //  send_command(0x05/* some interrupt ID */, m);

    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=0; // TESTY - 0 was 78. now new default to work on
	
	switch(mode){
	  /// MODE 0! ///////////////////////
	case 0: 
	    /*
	     *Instead of new mode 77: rec started during play is overlay* (play started during rec is also overlay?)
	     so we have 4 states:
	     - NADA
	     - rec/resets start of reccount, stop
	     - play
	     - rec+play: OVERLAY! stop rec: stops overlay, carries on playing// stop play: into NADA... (so are there 2 ways out?)
	     // or should stop play just revert to rec with no overlay// and reset on entry // but there is no entry as we are there, so carries on/extends.. ?
	     // *question of stop play returning to bare reset rec - which it shouldn't*

	     TODO:
	     - add doubling up of rec...DONE
	     - implement all minormodes - see new_modes.org
	    */

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
	  // play
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && play && ender[daccount]){// only play if we have something in rec
	    RESETFRP; // clear freezers but only on entering
	    // minormodes for play!
	    //	    playminor=0;
	    playreset=playminor&1; // to reset or not XX
	    playoverlay=((playminor>>1)&3); // 4 types of overlay
	    playspeed=((playminor>>3)&1); // 2 types speed
	    playfreeze=((playminor>>4)&3);// now reworked as 4 types of freeze: overlay only, stop play, keep play-hold value, hold speed
	    lastmode=0;
	    //	    if (overlap[daccount]) ender[daccount]=DOUBLEMAXREC;

	    // rework playback and freezings
	    if (playfreeze==3 && daccount==6){ // freeze speed // 		  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	      if (freezetoggle[6])
	    {
	      lastvalue[6]=real[6];
	      freezetoggle[6]=0;
	    }
	  else { 
	    if (real[6]<lastvalue[6]) speed=lastvalue[6];
	    else speed=real[6];
	  }
	    }

	    if (playfreeze!=1 && !frozen[daccount]){ // playback in any case except that freezer
	      if (playspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	      }

	    if (playfreeze==0){ // overlay only
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
	      }
	      else if (playfreeze==2){//		run play and yet hold last play value
		if (frozen[daccount]==0) lastplayerr[daccount]=lastplayer[daccount];
		else values[daccount]=lastplayerr[daccount];// frozen
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
	  ///// rec
	  //////////////////////////////////////////////////////////////////////
	  if ((!overlaid) && rec){ // we are recording // on entry but not 2nd time
	    RESETFRR; // clear freezers
	    recreset=recminor&1; // to reset or not XX	    
	    recspeed=((recminor>>1)&15)+1;
	    
	    if (!recreset) LASTREC; // reset all only on entering
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
	      recsp[daccount]++;
	      if (recsp[daccount]>=recspeed){
		recsp[daccount]=0;
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
	  }
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	  //////////////////////////////////////////////////////////////////////
	  // overlay
	  //////////////////////////////////////////////////////////////////////
	    if (overlaid){
	      RESETFRO; // clear freezers
	      overminor=0;
	      overreset=overminor&1; // to reset or not XX
	      overoverlay=((overminor>>1)&3); // 4 types of overlay
	      overspeed=((overminor>>3)&1); // 2 types speed
	      //	      overfrsix=((overminor>>4)&1); // freeze
	      overrun=((overminor>>5)&1); // stop/start player
	      overlast=((overminor>>6)&1); // freeze it
	      overrec=((overminor>>7)&2); // type of recorded overlay

	      // test one by one! TODO!
	    // TESTING each one in turn // tested regular behaviour
	      ///	      overreset=1;
	      //	      overoverlay=3; // 0,1,2,3
	    //	    overspeed=1;
	    //	    overdetsix=1;
	    //	    overrun=1; // freeze
	    //	    overlast=1; // freeze
	      // overrec= /// 0,1,2,3
	      
	      if (!overreset) LSTRECPLAYD; 
	      lastmode=1;
	      speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits

	      if (overrun){
	      if (frozen[daccount]==0){
		if (overspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
		else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
		lastplayer[daccount]=values[daccount];
	      }
	      else values[daccount]=lastplayer[daccount];
	    }
	    else {
	      if (overspeed) values[daccount]=speedsampleD(logspeed[speed], ender[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsampleD(logfast[speed], ender[daccount], daccount, recordings[daccount]);
	      lastplayer[daccount]=values[daccount];
	    }
	    
	    // freeze of just overlay/real or not
	    	    if (!overlast) {
	      if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { // ***we have just one type of overlap on top of the freeze
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	  }
	    } // overlast ==1 // freeze player value but keep running or not (depends on overrun)
		    else {
		      if (frozen[daccount]==0) lastplayerr[daccount]=lastplayer[daccount];
		      else values[daccount]=lastplayerr[daccount];// frozen
		    }
		
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
	      tmp=(recordings[daccount][rec_cnt[daccount]]&4095) + values[daccount];
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
	      tmp=(recordings[daccount][(int)play_cnt[daccount]]&4095) + values[daccount];
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
	    // nada
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
	    lastmode=0;
	    }
	    else entryn=0;
	    break; 

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
	  //testting^=1; // testy
	}	
	else if (modeheld<LONGMODE){ //inc minor mode matrix
	  modeheld=0; // ??? was commented just for testing
	  testting^=1; // testy triggers
	  //	  baseminor++;
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
