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

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRK 8 // was 8 when we have have divider in main as 32...
#define DELB 200 // delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK
#define DELA 64 // for clear DAC // was 64

#define HOLDRESET 200 // time for full reset when hold the mode down - over 2 seconds
#define SHORTMODE 2 // was 20ms could be shorter...
#define LONGMODE 100 // 1sec
#define MAXMODES 4
#define MAXMINOR 128 // 128 minor/modifiers - not all used...
//#define MAXREC 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#define MAXREC 3800 // for older STM
// with F413 we have 9000 which is how long - 26 seconds as runs a bit faster,,, 32// now div64 and 9500 gives us 55 seconds...

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
static float ownplay_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
//static uint32_t tgr_cnt[10]={0};
static uint32_t rec=0, play=0;

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
    static uint32_t daccount=0;
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
    uint32_t bits, recspeed, lengg, where;
    uint32_t values[8];
    static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastspeed=0, lastspeedd=0;
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playb[8]={0,0,0,0, 0,0,0,0};
    static uint32_t recd[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrecy[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, lastplay=0, added[8]={0}, modetoggle=0, newmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, minormode=0,starter[8]={0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0};
    static uint32_t lasttriggered[11]={0}, breaker[11]={0}, lastlastrec=0, lastlastplay, lastlast;
    static int32_t endpoint, togrec=0, togplay=0, modeheld=0, modechanged=1, first=0;
    
    uint32_t tmp, trigd;
    int32_t midder;

    uint32_t speeddiv[4]={1, 4, 16, 32};
    float speeddivisor[4]={1.0, 0.25, 0.0625, 0.03125};

    
    //    itoa(prev[0], buffx, 10);
    //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
    //  send_command(0x05/* some interrupt ID */, m);

    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=0; // testy

	switch(mode){
	case 0: // 6/6/2023 - now with minor mode adjustments
	  FREEZERS;
	  REALADC;

	  if (play==0) {
	  if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
	  else real[daccount]=lastvalue[daccount];// frozen
	  }
	  
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    if (!(minormode&8)) {
	      LASTPLAY;
	    }
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;

	    if (minormode&2) { // speed as real or recorded
	      if (minormode&32){ // freeze just freezes speed and not real
		if (frozen[6]==0) {
		  lastspeedd=(lastspeed>>2)+(real[6]>>2);
		  if (lastspeedd>1023) lastspeedd=1023;
	      }
	      }
		else { // freeze freezes real only and not speed
		if (frozen[6]==0) {
		  lastvalue[6]=real[6];
		}
		else {
		  real[6]=lastvalue[6];
		  lastspeedd=(lastspeed>>2)+(real[6]>>2);
		  if (lastspeedd>1023) lastspeedd=1023;
		}
		}
		speed=lastspeedd;
	  }
	  else {
	    if (minormode&32){ // freeze just freezes speed and not real
	      if (frozen[6]==0) lastspeedd=real[6];
	    }
	    else // freeze freezes real only and not speed
	      {
		if (frozen[6]==0) {
		  lastvalue[6]=real[6];
		  lastspeedd=real[6];
		}
		else {
		  lastspeedd=reall[6];
		  real[6]=lastvalue[6];
		}
	      }
	      speed=lastspeedd>>2; // 24/4 // 25/4 now 12 to 10 bits
	  }

	    //	    minormode=64;
	    if (minormode&64){	    // freeze stops playback
	    if (frozen[daccount]==0) {
	      if (minormode&1) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    }
	    else values[daccount]=lastvalue[daccount];
	    }
	    else { // freeze just holds overlap
	      if (minormode&1) values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);

	      if (frozen[daccount]==0) lastvalue[daccount]=real[daccount];
	      else real[daccount]=lastvalue[daccount];// frozen
	    }
	    if (daccount==6) lastspeed=values[6];

	    values[daccount]+=real[daccount];
	    if (minormode&4){
	    if (values[daccount]>4095) values[daccount]=4095;
	    }
	    else values[daccount]=values[daccount]&4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]); 
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      if (!(minormode&16)) {
	      LASTREC; // reset all
	      }
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    //	    values[4]=0; //TESTY! 4 is lowest voltage   
	  break; ///// 

	  ////////////////////////////////////////////
	  // adding 6/6 - but these will need to be changed for minormode scheme

	  //	  2) overlay on next rec only (with/without reset - so without reset overlay would carry on from end of last rec...)
	  //	       if no reset then this changes length of rec/play
	  // but to overlay we need to play
          case 1: 
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY; // reset bits
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // speed bits
	    values[daccount]+=real[daccount]; // overlap bits
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset bits // *add no-reset opts*
	      if (modechanged) {
		modechanged=0;
		// rec all new until we stop first one
		first=1;
	      }		
	      if (first==1) recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      else {
		recordings[daccount][rec_cnt[daccount]]+=real[daccount];
		if (recordings[daccount][rec_cnt[daccount]]>4095) recordings[daccount][rec_cnt[daccount]]=4095;
		// also overlay bits but we need to play
		speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
		values[daccount]=recordings[daccount][rec_cnt[daccount]]; // no speed
	      }
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      first=0;
	    }       
	  break; ///// 

	  /// 7/6
	case 2: // FIXED speed - add in other modifiers TODO
	  // fixed speeds and slower fixed rec//// modifiers used here for rec and speed dividers
	  // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed
	  // dividers can be out of sync also
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	    tmp=minormode&3;

	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    //	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(0.0625, rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]=speedsample(speeddivisor[tmp], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  
	  recspeed=speeddiv[tmp]; // TESTY was 16 fixed 1/16 speed=0.0625
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (recsp[daccount]>recspeed){
		recsp[daccount]=0;
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	  ////////////////////////////////////////////

	  
	case 8: // now changing speed and slower fixed rec////
	  // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(0.0625, rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=8; // TESTY was 16 fixed 1/16 speed=0.0625
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (recsp[daccount]>recspeed){
		recsp[daccount]=0;
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 9: // looped recording and overlay - so it is always playing/recording - 
	  // rec and play length held change start and end points
	  // or they could just operate as start rec, start play...???
	  // could also be fixed speed
	  // 2 diff versions or more
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  ////
	  LASTREC; // reset all
	  LASTPLAY;
	  RECLONG; // lastlastrec stores reclong which just increments itself 
	  RECPLAY;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits

	  endpoint=MAXREC-lastlastplay;
	  if (endpoint<lastlastrec) {
	    lastlastplay=0;
	    endpoint=MAXREC;
	  }
	  
	  if (lastlastrec>endpoint) lastlastrec=0;
	  lengg=endpoint-lastlastrec;
	  if (lengg<1) lengg=1;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	  values[daccount]=speedsamplestart(logfast[speed], lengg, lastlastrec, daccount, recordings[daccount]); 
	  values[daccount]+=real[daccount];
	  if (values[daccount]>4095) values[daccount]=4095;
	  recordings[daccount][rec_cnt[daccount]]=values[daccount];
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>endpoint) {
	    rec_cnt[daccount]=lastlastrec;
	    }
	  break; ///// 

	case 10: // start on looped recording and overlay - so it is always playing/recording - 
	  // 2nd version with different recordings scheme
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  ////
	  LASTREC; // reset all
	  LASTPLAY;
	  RECLONG; // lastlastrec stores reclong which just increments itself 
	  RECPLAY;

	  endpoint=MAXREC-lastlastplay;
	  if (endpoint<lastlastrec) {
	    lastlastplay=0;
	    endpoint=MAXREC;
	  }
	  
	  if (lastlastrec>endpoint) lastlastrec=0;
	  lengg=endpoint-lastlastrec;
	  if (lengg<1) lengg=1;
	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	  values[daccount]=speedsamplestart(logspeed[speed], lengg, lastlastrec, daccount, recordings[daccount]); 
	  values[daccount]+=real[daccount];
	  if (values[daccount]>4095) values[daccount]=4095;
	  recordings[daccount][rec_cnt[daccount]]+=real[daccount];
	  if (recordings[daccount][rec_cnt[daccount]]>4095) recordings[daccount][rec_cnt[daccount]]=4095;
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>endpoint) {
	    rec_cnt[daccount]=lastlastrec;
	    }
	    
	  break; ///// 

	case 11: // trial record speed - tap freeze to record speed as top voltage, tap to stop rec...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || daccount==6 ) { // freeze always holds except in case of 6TOP
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAYCNT;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    speed+=(ownspeedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]))>>2;
	    if (speed>1023) speed=1023; // or modulus
	    if (frozen[6]==1){ // we record the speed
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[6]<<16); // top 16 bits are speed -- overwrites last speed
	      }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording - we need to reset speeds at top but they will be overwritten...
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break;

	case 12: // trial record speed - tap freeze to record speed as top voltage, tap to stop rec...
	  // freeze stops rec/playback and starts again...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || daccount==6 ) { // freeze always holds except in case of 6TOP
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAYCNT;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[6]==1){ // we record the speed and play it back...
	      speed+=(ownspeedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]))>>2;
	      if (speed>1023) speed=1023; // or modulus
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(speed<<18); // top 16 bits are speed
	      }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording - we need to reset speeds at top but they will be overwritten...
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break;

	  //- 13, 14, 15: global/detach mode... rec and play as usual:
	  // 13 - freeze overdubs a section in playback mode
	  //to overdub a section only-freeze, to free/detach/pull a section out of playback, re-attach // can this be on same mode?
          case 13: 
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;

	    if (frozen[daccount]){ // overdub start and stop but must overdub where we are as in playcnt
	      recordings[daccount][(int)play_cnt[daccount]]=values[daccount];
	    }
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	case 14: // not overdub but just record new
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;

	    if (frozen[daccount]){ // overdub start and stop but must overdub where we are as in playcnt
	    values[daccount]=real[daccount];
	    recordings[daccount][(int)play_cnt[daccount]]=values[daccount];
	    }
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	  
	case 15: // see above. just detach that section from playback...
	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]); // TESTY logfast
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	      if (frozen[daccount]==0) { 
		values[daccount]+=real[daccount];
		if (values[daccount]>4095) values[daccount]=4095;
	      }
	      else values[daccount]=real[daccount];
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 

	case 16: // trial for slew of touch outside
	  // so fixed speed and slew from [6] global
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  /// slew our real - so target is whenever we hit target...
	  
	  speedy=1.0f/((real[6]>>2)+1.0f);
	  //	  speedy=0.001f;

	    result[daccount] = ((float)target[daccount] * alpha[daccount]) + ((float)starty[daccount] * (1.0f - alpha[daccount])); // interpol but is just last and before last
	    alpha[daccount]+=speedy;
	    if (alpha[daccount]>1.0f) alpha[daccount]=1.0f;
	    
	    //	    if (target[daccount]==starty[daccount]) target[daccount]=real[daccount];
	    
	    if (target[daccount]>=starty[daccount] && result[daccount]>=target[daccount]) {
	    starty[daccount]=target[daccount]; // present value
	    target[daccount]=real[daccount];
	    alpha[daccount]=0.0f;
	    }
	    else if (target[daccount]<=starty[daccount] && result[daccount]<=target[daccount]) {
	    starty[daccount]=target[daccount];
	    target[daccount]=real[daccount];
	    alpha[daccount]=0.0f;
	    }

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=result[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=result[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(result[daccount]); 
	  }
	  break; ///// 

	  // global: freezer shifts start of each particular section towards the end
	case 17: 
	  REALADC;
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    RECFREEZE;
	    if (starter[daccount]>=rec_cnt[daccount]) starter[daccount]=0;
	    lengg=rec_cnt[daccount]-starter[daccount];
	    if (lengg<1) lengg=1;
	    values[daccount]=speedsamplestart(logfast[speed], lengg, starter[daccount], daccount, recordings[daccount]); 
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; ///// 


	case 19: // as 0 but if we are in playback mode, freeze holds playback/rec voltage...
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || play) { // as we don;t want freeze in play 
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]==0) {
	      values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	      lastvalue[daccount]=values[daccount];
	    }
	    else values[daccount]=lastvalue[daccount];
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    break; ///// 

	case 20: // as 19 above but different kind of freeze... speed still moves on samples...
	  // as 0 but if we are in playback mode, freeze holds playback/rec voltage... 
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || play) { // as we don;t want freeze in play 
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    if (!frozen[daccount]) lastvalue[daccount]=values[daccount];

	    if (frozen[daccount]) values[daccount]=lastvalue[daccount]; // 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    break; ///// 
	    
	case 21: // as 0 but no reset of rec_cnt
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      //	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; ///// 

	case 22: // - slew which doesn't wait until target - TODO:how to do rise and fall independent speeds??
	  // so fixed speed and slew from [6] global
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
	  
	  speedy=1.0f/((real[6]>>2)+1.0f); // 0 is fastest
	  //	  speedy=1.0f-speedy; invert
	  //	  speedy=0.001f;
	  //	  speedy=0.01f;

	    result[daccount] = ((float)target[daccount] * alpha[daccount]) + ((float)starty[daccount] * (1.0f - alpha[daccount])); // interpol but is just last and before last
	    alpha[daccount]+=speedy;
	    if (alpha[daccount]>1.0f) alpha[daccount]=1.0f;
	    
	    //	    if (target[daccount]==starty[daccount]) target[daccount]=real[daccount];

	    if (target[daccount]>=starty[daccount]) { // we are going up//
	      if ((result[daccount]>=target[daccount]) || (real[daccount]<target[daccount])){
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	      }
	    }
	    else { // going down
	      if ((result[daccount]<=target[daccount]) || (real[daccount]>target[daccount])){
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	      }
	    }

	    /*
	    if ((target[daccount]>=starty[daccount] && result[daccount]>=target[daccount]) || (target[daccount]<=starty[daccount] && result[daccount]<=target[daccount])) {
	    starty[daccount]=result[daccount]; // present value
	    alpha[daccount]=0.0f;
	    target[daccount]=real[daccount];
	    }
	    */

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=result[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	  // if playback add
	    if (play==1) { 
	    values[daccount]+=result[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(result[daccount]); 
	  }
	  break; ///// 

          case 23:
	    // - overlay mirror: all follow say lowest/bottom voltage [4] but add own 
	    //  overlay (live and/or in recording/playback - what makes sense
	    //  here) + rec/speed versions of this
	    //and variations on this eg. all voltages only, all VCA, all

	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    if (daccount==4) values[daccount]=(real[daccount]);
	    else {
	      values[daccount]=(real[4]+real[daccount]);
	      if (values[daccount]>4095) values[daccount]=4095;
	    }
	  }

	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (daccount!=4) {
		real[daccount]+=(real[4]);
	      if (real[daccount]>4095) real[daccount]=4095;
	    }

	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; /////23

          case 24:
	    //this one: freeze just plays back with own overlay the previous section ADC (does not copy), unfreeze reverts to own record...
	    /////- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]) {
	      values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]]); // all cnts are same in globals
	    }
	    else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; ///// 24

	case 25:
	    //- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    if (frozen[daccount]) {
	      values[daccount]=speedsamplecopy(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]], recordings[daccount]); // all cnts are same in globals
	    }
	    else values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; /////25 

          case 26:
	    // - these also suggest another mode which overlays the previous one on playback - so adds the 2 recs...
	    //this one: freeze just plays back with own overlay the previous section ADC (does not copy), unfreeze reverts to own record...
	    /////- global and local: freeze copies previous section ADC - copy as we play back into rec buffer, unfreeze just stops this process

	  FREEZERS;
	  
	  //	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	    //	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	    if (frozen[daccount]) {
	      values[daccount]+=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[previousone[daccount]]); // all cnts are same in globals
	    }
	    else 
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	    values[daccount]=(real[daccount]);
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	  break; /////26
	  
	  //////////////////////////////////////////////////////
	  //////////////////////////////////////////////////////
	  
	  // starty of LOCAL modes...
	case 30: // 
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (togrec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (togplay){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 
	  
	  /// start on local modes - freeze is toggle rec/play
	case 31: // basic mode with NO freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // rec and play overrides ... does this logic make sense as we can have play and rec at same time?
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (rec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (play){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if ((play || playb[daccount]) && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (rec || recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if ((play || playb[daccount]) && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 32:
	  // as mode 30?XX but we reset rec_cnt once...
	  // basic mode with NO freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    if (!lastrecy[daccount]){
	    rec_cnt[daccount]=1; // just once...
	    }
	    lastrecy[daccount]=0;
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    lastrecy[daccount]=1;
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (togrec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (togplay){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 33: // as 30 but - *rec freezes all, play resets all counters*
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  if (rec==0){ // global freezer
	  REALADC;
	  }
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 34: // as 33 but rec holds playback: as 30 but - *rec freezes all, play resets all counters*
	  FREEZERS;
	  REALADC;
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }
	  
	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    if (rec==0){
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	    lastvalue[daccount]=values[daccount];
	    }
	    else values[daccount]=lastvalue[daccount];	    
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	case 35: // alt hold as 34 above 
	  FREEZERS;
	  REALADC;
	  
	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once

	  if (togplay){
	    LASTPLAY;
	    LASTREC
	  }
	  else {
	    lastplay=0;
	    lastrec=0;
	      }
	  
	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	    lastvalue[daccount]=values[daccount];

	    if (rec) values[daccount]=lastvalue[daccount];	    
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	  
	  ///////////////////////
	  //////////////////////

	case 666: // speed test ONLY 166.7Hz // on 413 now we have 190+Hz with divider...
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13; // multiplex
	  //CLEARDAC; // why we remove this but is there on writedac - timing?
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	  if (val==0) val=4095;
	  else val=0;
	  }
	  //	  RESETT; // all resets... drops us to 15Hz so we lose 1/30th second... on full reset
	  //	  RESET0; // one reset... drops to 142Hz so not so bad... 
	  break;

	case 777: // tests of all toggles! rec, play, mode and freeze
	  FREEZERS;
	  
	  if (frozen[daccount] || rec || play || modetoggle ) { // freeze always holds
	    values[daccount]=4095;
	  }
	  else values[daccount]=0;
	  break; /////

	} // end of modes switch

	// start to test for long or short mode hits
	static uint32_t testting=0;
	if (modeheld>HOLDRESET && newmode) { //reset all
	  newmode=0;
	  modeheld=0;
	  RESETT;
	  //	  testting^=1; // testy
	}
	else if (modeheld>LONGMODE && modeheld<HOLDRESET && newmode) { // increment major mode
	  newmode=0;
	  modeheld=0;
	  MODECHANGED;
	  //  testting^=1; // testy
	}	
	else if (modeheld>SHORTMODE && modeheld<LONGMODE && newmode){ //inc minor mode matrix
	  newmode=0;
	  modeheld=0; // ??? was commented just for testing
	  //	  testting^=1; // testy
	  minormode++;
	  if (minormode>MAXMINOR) minormode=0;
	  }

	/*
	  // decoding minor modes or is this done in modes...


	  // what they are and how they are decoded...
	  1-overlay:modulo/peak 
	  23-speeds: add, add from below, nofreeze, freeze
	  45-resets: play, rec
	 */
	
//	if (testting) values[daccount]=4095; // TESTY
//	else values[daccount]=0; // TESTY
	
	
	// pulled this out here...
	WRITEDAC;
	daccount++;
	if (daccount==8) {
	  daccount=0;
	  count++;
	  TOGGLES;      
	}
	
	
    }
  }
