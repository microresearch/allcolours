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
#define BRK 8 // when we have have divider in main as 32...
#define DELB 200 // delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK
#define DELA 64 // for clear DAC

#define MAXMODES 4
#define MAXREC 3800 // depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...

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
static uint32_t rec_cnt[8]={0};
static float play_cnt[8]={0.0f};
static float ownplay_cnt[8]={0.0f};
//static uint32_t tgr_cnt[10]={0};
static uint32_t rec=0, play=0;

static uint32_t shifter[8]={2,2,2,2,2,2,2,2}; // shifter seperates vca from cv - VCA comes first
//static uint32_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here

//static uint32_t order[8]={7,6,5,4,3,2,1,0}; // 0-3 is VCA from bottom
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

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t daccount=0;
    static uint32_t speed=1, overlap[8]={0};
    volatile uint32_t k;
    uint32_t j,x,y,val;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t prev[8]={1,2,3,4,5,6,7,0};
    uint32_t bits, recspeed, lengg, where;
    uint32_t values[8], real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playy[8]={0,0,0,0, 0,0,0,0};
    static uint32_t recc[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0};
    static uint32_t lasttriggered[11]={0}, breaker[11]={0}, lastlastrec=0, lastlastplay, lastlast;
    static int32_t endpoint;
    
    uint32_t tmp, trigd;
    int32_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=11; // testy

	switch(mode){
	case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // overlay is peak
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all inc overlap only once
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0; // ???
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
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    TOGGLES;      
	  }       
	  break; 

	case 1: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // overlay is mod
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
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
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) {
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]&4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    TOGGLES;      
	  }       
	  break; 
	  
	case 2: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
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
	    if (play==1 && daccount!=6) { //TEST: don't add for speed! as speed shouldnt effect rec cv is independent
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; 

	case 3: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // modulo version
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 10 bits
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    values[daccount]=values[daccount]&4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; 
	  ///////////////////////////////////////////
	  
	case 4: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage gets slower
	  /// speed lowering as case 2
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    speed=1;
	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break;

	case 5: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // with only speed upwards
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
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; 

	  
	case 6: // a fixed speed with slow down
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
	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=16; // TESTY fixed
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
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; 

	case 7: // TEST for local speeds on each voltage - so we don't add any values there 
	  // doesn't work so well as global as some have no contents
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    // speed depends on real how we treat it!
	    if (daccount>3) { // 4,5,6,7 voltages
	    speed=real[daccount]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    }
	    else {
	      speed=reall[daccount]; // 10 bits
	    }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	    if (play==0)	    values[daccount]=(real[daccount]); 
	    
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; ///// 

	case 8: // fixed speed and slower fixed rec////
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
	    values[daccount]=speedsample(0.0625, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=16; // TESTY fixed
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
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; 

	case 9: // looped recording and overlay - so it is always playing/recording - 
	  // rec and play length held change start and end points
	  // or they could just operate as start rec, start play...???
	  // fixed speed but additional speed mode could be interesting as re-records at different speeds
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
	    
	  WRITEDAC;
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    ///	    TOGGLES;       // we dont use rec or play
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
	  values[daccount]=speedsamplestart(logspeed[speed], lengg, lastlastrec, daccount, recordings[daccount]); 
	  values[daccount]+=real[daccount];
	  if (values[daccount]>4095) values[daccount]=4095;
	  
	  recordings[daccount][rec_cnt[daccount]]+=real[daccount];
	  if (recordings[daccount][rec_cnt[daccount]]>4095) recordings[daccount][rec_cnt[daccount]]=4095;
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>endpoint) {
	    rec_cnt[daccount]=lastlastrec;
	    }
	    
	  WRITEDAC;
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    ///	    TOGGLES;       // we dont use rec or play
	  }       
	  break; ///// 

	case 11: // trial record speed - tap freeze to top voltage
	  FREEZERS;
	  
	  if (frozen[daccount]==0 || daccount==6 ) { // freeze always holds except in case of 6TOP
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    speed+=(ownspeedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]))>>2;
	    if (frozen[6]==1){ // we record the speed
	      where=(int)ownplay_cnt[6];
	      recordings[daccount][where]=(recordings[daccount][where]&4095)+(real[6]<<16); // top 16 bits are speed
	      }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
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
	    if (play==1 && daccount!=6) { //TEST: don't add for speed! as speed shouldnt effect rec cv is independent
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break;
	  
	  ///////////////////////////
	case 666: // speed test ONLY 166.7Hz
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

	  
	} // end of modes switch    
    }
  }
