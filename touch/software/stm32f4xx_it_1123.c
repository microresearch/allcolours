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
#define BRK 64 // was 128 - for other toggles...
#define DELB 42 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK -- is delay we hold the the freeze/toggle
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

//static uint32_t SENSESHIFT=2, SENSEOFFSET=1800; // offset is minus!
//static uint32_t SENSESHIFT=1, SENSEOFFSET=560; // lower sensitivity
static uint32_t SENSESHIFT=0, SENSEOFFSET=0; // no shift now

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

inline static uint32_t speedsampleL(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples, uint32_t layer){
  uint32_t lowerPosition, upperPosition;
  float sample;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  if (layer==0){
  sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); // adapted for top bits
  }
  else {
  sample= ((samples[lowerPosition]>>16) + 
		 (res *
		  ((samples[upperPosition]>>16) - (samples[lowerPosition]>>16)))); // adapted for top bits
  }
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


typedef struct layers_ {
  uint32_t cnt;
  uint32_t end;
  uint32_t (*speedsamp)(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
} layers;

static layers lay[8][2];

void reclayerupper(uint32_t value, uint32_t daccount){
  recordings[daccount][lay[daccount][1].cnt]=(recordings[daccount][lay[daccount][1].cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t daccount){
  recordings[daccount][lay[daccount][0].cnt]=(recordings[daccount][lay[daccount][0].cnt]&TOPS)+(value);
}

// STARTY
void TIM2_IRQHandler(void) 
  {
    static uint32_t global_time=0; // also in resett
    static uint32_t daccount=0, entryp=0, entryn=0, entryr=0, entryo=0;
    static uint32_t speed=0;
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
    static uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10 NOW STATIC!
    static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
    static int32_t control[4];
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastvaluer[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayer[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayerr[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastspeed=0, lastspeedd=0;
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastplayspot[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playb[8]={0,0,0,0, 0,0,0,0};
    static uint32_t layerr[8]={0,0,0,0, 0,0,0,0}; // current layer... 0 or 1
    static uint32_t recd[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, secondrec=0, lastplay=0, added[8]={0}, modetoggle=0, newmode=0, counting=0, overlaid=0, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, freezetoggle[8]={0,0,0,0,0,0,0,0}, baseminor=0,recminor=0,playminor=0,overminor=0,nadaminor=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0}, lastlastrec=0, llrec=0,lastlastplay, lastlast;
    static int32_t endpoint, togrec=0, togplay=0, helder=0, heldon=0, modeheld=0, modechanged=1, first=0;
    static uint32_t testting=0;
    static uint32_t oncey=0,loop[8]={0,0,0,0, 0,0,0,0};
    
    uint32_t tmp, trigd, otherlayer;
    int32_t midder, subs;

    uint32_t speeddiv[4]={1, 4, 16, 32};
    float speeddivisor[4]={1.0, 0.25, 0.0625, 0.03125}; /// ???

    if (oncey==0){
      oncey=1;
    lay[0][0].cnt=0; lay[0][0].end=0;
    lay[0][1].cnt=0; lay[0][1].end=0;
    lay[1][0].cnt=0; lay[1][0].end=0;
    lay[1][1].cnt=0; lay[1][1].end=0;
    lay[2][0].cnt=0; lay[2][0].end=0;
    lay[2][1].cnt=0; lay[2][1].end=0;
    lay[3][0].cnt=0; lay[3][0].end=0;
    lay[3][1].cnt=0; lay[3][1].end=0;
    lay[4][0].cnt=0; lay[4][0].end=0;
    lay[4][1].cnt=0; lay[4][1].end=0;
    lay[5][0].cnt=0; lay[5][0].end=0;
    lay[5][1].cnt=0; lay[5][1].end=0;
    lay[6][0].cnt=0; lay[6][0].end=0;
    lay[6][1].cnt=0; lay[6][1].end=0;
    lay[7][0].cnt=0; lay[7][0].end=0;
    lay[7][1].cnt=0; lay[7][1].end=0;    
    lay[0][0].speedsamp=speedsample; // where to init these...
    lay[0][1].speedsamp=speedsampleloptop;
    lay[0][0].reclayer=reclayerlower;
    lay[0][1].reclayer=reclayerupper;

    lay[1][0].speedsamp=speedsample; // where to init these...
    lay[1][1].speedsamp=speedsampleloptop;
    lay[1][0].reclayer=reclayerlower;
    lay[1][1].reclayer=reclayerupper;

    lay[2][0].speedsamp=speedsample; // where to init these...
    lay[2][1].speedsamp=speedsampleloptop;
    lay[2][0].reclayer=reclayerlower;
    lay[2][1].reclayer=reclayerupper;

    lay[3][0].speedsamp=speedsample; // where to init these...
    lay[3][1].speedsamp=speedsampleloptop;
    lay[3][0].reclayer=reclayerlower;
    lay[3][1].reclayer=reclayerupper;

    lay[4][0].speedsamp=speedsample; // where to init these...
    lay[4][1].speedsamp=speedsampleloptop;
    lay[4][0].reclayer=reclayerlower;
    lay[4][1].reclayer=reclayerupper;

    lay[5][0].speedsamp=speedsample; // where to init these...
    lay[5][1].speedsamp=speedsampleloptop;
    lay[5][0].reclayer=reclayerlower;
    lay[5][1].reclayer=reclayerupper;

    lay[6][0].speedsamp=speedsample; // where to init these...
    lay[6][1].speedsamp=speedsampleloptop;
    lay[6][0].reclayer=reclayerlower;
    lay[6][1].reclayer=reclayerupper;

    lay[7][0].speedsamp=speedsample; // where to init these...
    lay[7][1].speedsamp=speedsampleloptop;
    lay[7][0].reclayer=reclayerlower;
    lay[7][1].reclayer=reclayerupper;
    }
    
    uint32_t playoverlay, playspeed, playspeedmod, playfreeze, playrun, playlast;
    uint32_t recspeed;
    uint32_t overoverlay, overfreeze, overlast, overrec, overspeedmod;
    
    //    itoa(prev[0], buffx, 10);
    //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
    //  send_command(0x05/* some interrupt ID */, m);
	
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=0; // TESTY 

	// so baseminor==0! just simple shift...
	//place all mods here even if we don't use them..
	/*
	baseminor=0;
	if (baseminor&1){
	  SENSESHIFT=2, SENSEOFFSET=1800; 
	}
	else
	  {
	    SENSESHIFT=1, SENSEOFFSET=560;
	  }
	*/
	SENSESHIFT=0, SENSEOFFSET=64; // TESTY fixed
		
	switch(mode){
	case 0: // 20/11/23 - testing bounce layer 1 at speed to overlay - as [mode5] previously
	  FREEZERS;
          REALADC;

	  if (rec && play){
	    if (lay[daccount][layerr[daccount]].end) overlaid=1; // TODO: should we enter overlaid with nothing??? in this case NO!
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
	  if ((!overlaid) && play){ // do we always enter on base layer
	  layerr[daccount]=frozen[daccount]; // 1 or 0 - does chosen layerr stay or is it reset
	    RESETFRP;
	    LASTPLAY;
	    lastmode=0;
	    speed=real[6]>>2; 
	    // if no other layer we play nada ???
	    // TESTING logfast_stop and logspeed_stop
	    if (lay[daccount][layerr[daccount]].end) values[daccount]=lay[daccount][layerr[daccount]].speedsamp(logspeed_stop[speed], lay[daccount][layerr[daccount]].end, daccount, recordings[daccount]); // speedsamp has its own cnt so there is a jump // see new speedsampleL - for MINORMODES
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
	    layerr[daccount]=frozen[daccount]; // 1 or 0 - does chosen layerr stay or is it reset - outside all???
	      LASTREC; 
	      RESETFRR;
	      lastmode=0;
	      //////
	      values[daccount]=(real[daccount]);
	      lay[daccount][layerr[daccount]].reclayer(real[daccount], daccount); // access to either layer
	      lay[daccount][layerr[daccount]].end=lay[daccount][layerr[daccount]].cnt;
	      //	      lay[daccount][1].end=lay[daccount][layerr[daccount]].cnt; // how we set the ends when we swop... they both have same ends...
	      lay[daccount][layerr[daccount]].cnt++; // TODO: toggle rec to overlay (also which counters we use???) // but bit odd as we have speed bounce in next which overwrites that!
	      if (lay[daccount][layerr[daccount]].cnt>MAXREC) {
		lay[daccount][layerr[daccount]].cnt=0;
		lay[daccount][layerr[daccount]].end=MAXREC;
		//		lay[daccount][1].end=MAXREC;
	      }
	    } // if rec
	  else {
	    lastrec=0;
	    entryr=0;
	  }
	    
          //////////////////////////////////////////////////////////////////////
          // OVERLAY*  bounces current layer into otherlayer!
          //////////////////////////////////////////////////////////////////////
	  if (overlaid){ 
	  layerr[daccount]=frozen[daccount]; // 1 or 0 - does chosen layerr stay or is it reset - outside all???
	      LSTRECPLAYD; // if we reset or not????
	      RESETFRO;
	      lastmode=1;
	      speed=real[6]>>2;
	      // swop of layers -
	      otherlayer=layerr[daccount]^1; // opposite...
	      values[daccount]=lay[daccount][layerr[daccount]].speedsamp(logfast[speed], lay[daccount][layerr[daccount]].end, daccount, recordings[daccount]); // current layer
	      if (daccount!=6) values[daccount]+=real[daccount]; // except [6]
	      if (values[daccount]>4095) values[daccount]=4095;
	      tmp=values[daccount];
	      //   recordings[daccount][over_cnt[daccount]]=(recordings[daccount][over_cnt[daccount]]&4095)+(tmp<<16);
	      // how that can be swopped
	      //	      recordings[daccount][lay[daccount][1].cnt]=(recordings[daccount][lay[daccount][1].cnt]&4095)+(tmp<<16);
	      lay[daccount][otherlayer].reclayer(tmp, daccount); // access to either layer
	      lay[daccount][otherlayer].cnt++;
	      ////
	      if (lay[daccount][otherlayer].cnt>MAXREC) {
		lay[daccount][otherlayer].cnt=0; 
		lay[daccount][otherlayer].end=MAXREC;
	      }
	  } // not overlaid//leaving ////
	    else {
	      lay[daccount][otherlayer].end=lay[daccount][otherlayer].cnt;
	      llrec=0;
	      entryo=0;
	    }

	    //////////////////////////////////////////////////////////////////////
	    // NADA*
	    //////////////////////////////////////////////////////////////////////
	  // testy loop
	  loop[daccount]++;
	  if (loop[daccount]>0){
	    loop[daccount]=0;
	  if (rec==0 && play==0 && overlaid==0) {
	      RESETFRN;
	      /*    if (freezetoggle[daccount])
	    {
	      lastvalue[daccount]=real[daccount];
	      freezetoggle[daccount]=0;
	    }
	  else { 
	    if (real[daccount]<lastvalue[daccount]) real[daccount]=lastvalue[daccount];
	    }*/
	      values[daccount]=(real[daccount]);
	      //	      if (val) values[4]=4095;
	      //	      else values[4]=0;
	    lastvalue[daccount]=values[daccount];
	    lastmode=0;
	    //	    values[0]=4095;
	    }
	    else entryn=0;
	  }
	  
	  break;
	case 666: // test new ADCs:
	  CTRL;
	  values[4]=control[0];
	  break;
	}
	  
	//	TOGGLES;      // only place where toggles - pulled out of ==8 section
	//	values[daccount]=0;
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
	  //testting^=1; // testy
	}	
	else if (modeheld<LONGMODE){ //inc minor mode matrix
	  modeheld=0; // ??? was commented just for testing
	  testting^=1; // testy triggers
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
