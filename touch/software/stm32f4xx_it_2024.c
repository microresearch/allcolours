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

#define MAXMODES 8
#define MINORMAX 1024

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

//static uint32_t SENSESHIFT=2, SENSEOFFSET=1800; // offset is minus!
//static uint32_t SENSESHIFT=1, SENSEOFFSET=560; // lower sensitivity
static uint32_t SENSESHIFT=0, SENSEOFFSET=0; // no shift now

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}


static uint32_t recordings[8][MAXREC+1]={0}; // 

typedef struct layers_ {
  uint32_t rec_cnt;
  uint32_t rec_end;
  uint32_t play_cnt;
  uint32_t play_len;
  uint32_t (*speedsamp)(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
} layers;

static layers lay[8][2];

    typedef struct listy_ { 
      uint32_t start[120];  
      uint32_t length[120];
      uint8_t layer;
    } playl;

    enum STATE {
      N,
      R,
      P,
      RP
    };

    typedef struct xx_ {
      enum STATE state; 
      uint32_t active;
      uint32_t masterL; // current layer
      uint32_t majormode;
      uint32_t minormode;
      uint32_t playspeed; // index into playreff
      uint32_t toggle, ttoggle;
      layers layer[2]; // rec layers count and functions for access
      playl playlist;// list of playbacks
      uint32_t playcnt; // 
      uint32_t playfull; // how many elements in the playlist
      uint32_t overlaid; /// how we enter RP
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t entryp, entryr, entryrp; // for resets
    } hands;

static hands fingers[8];


inline static void resetx(uint32_t which){
  for (uint32_t y=0;y<MAXREC;y++){ 
    recordings[which][y]=0;
  }
}

void reclayerupper(uint32_t value, uint32_t daccount){
  recordings[daccount][lay[daccount][1].rec_cnt]=(recordings[daccount][lay[daccount][1].rec_cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t daccount){
  recordings[daccount][lay[daccount][0].rec_cnt]=(recordings[daccount][lay[daccount][0].rec_cnt]&TOPS)+(value);
}

inline static void changemode(uint32_t dacc){
  fingers[dacc].majormode++;
  if (fingers[dacc].minormode>MAXMODES) fingers[dacc].minormode=0;
  fingers[dacc].toggle=0;					
  fingers[dacc].ttoggle=0;
  fingers[dacc].play=0;					
  fingers[dacc].rec=0;
  fingers[dacc].state=N; // NADA  
  // TODO: what else we reset here
}

inline static void resett(uint32_t dacc){
  fingers[dacc].majormode=0;
  fingers[dacc].minormode=0;
  fingers[dacc].toggle=0;					
  fingers[dacc].ttoggle=0;
  fingers[dacc].state=N; // NADA
  fingers[dacc].playcnt=0;					
  fingers[dacc].playfull=0;
  fingers[dacc].play=0;					
  fingers[dacc].rec=0;
  fingers[dacc].layer[0].rec_cnt=0;
  fingers[dacc].layer[1].rec_cnt=0;
  fingers[dacc].layer[0].play_cnt=0;
  fingers[dacc].layer[1].play_cnt=0;
  fingers[dacc].layer[0].rec_end=0;
  fingers[dacc].layer[1].rec_end=0;

}

inline static uint32_t speedsamplelower(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  fingers[dacc].layer[0].play_cnt=mod0(fingers[dacc].layer[0].play_cnt+speedy, lengthy);
  lowerPosition = (int)fingers[dacc].layer[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(fingers[dacc].layer[0].play_cnt - (float)lowerPosition);
  float sample= ((samples[lowerPosition+start]&4095) + 
		 (res *
		  ((samples[upperPosition+start]&4095) - (samples[lowerPosition+start]&4095))));

      return (uint32_t)sample;
}

inline static uint32_t speedsampleupper(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  fingers[dacc].layer[1].play_cnt=mod0(fingers[dacc].layer[1].play_cnt+speedy, lengthy);
  lowerPosition = (int)fingers[dacc].layer[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(fingers[dacc].layer[1].play_cnt - (float)lowerPosition);
  float sample= ((samples[lowerPosition+start]>>16) + 
		 (res *
		  ((samples[upperPosition+start]>>16) - (samples[lowerPosition+start]>>16)))); 

      return (uint32_t)sample;
}

// STARTY
void TIM2_IRQHandler(void) 
  {
    static uint32_t daccount=0;
    uint32_t j,x,y;
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    static uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10 NOW STATIC!
    static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
    static int32_t control[4];
    static uint32_t modetoggle=0, newmode=0, count=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0};
    static int32_t togrec=0, togplay=0, helder=0, heldon=0, helldone=0, modeheld=0, modechanged=1, first=0;
    static uint32_t oncey=0;
    
    if (oncey==0){// can we put this init elsewhere?
      oncey=1;
      for (x=0;x<8;x++){
	fingers[x].layer[0].rec_cnt=0;
	fingers[x].layer[1].rec_cnt=0;
	fingers[x].layer[0].play_cnt=0;
	fingers[x].layer[1].play_cnt=0;
	fingers[x].layer[0].rec_end=0;
	fingers[x].layer[1].rec_end=0;
	fingers[x].layer[0].speedsamp=speedsamplelower; // where to init these...
	fingers[x].layer[1].speedsamp=speedsampleupper;
	fingers[x].layer[0].reclayer=reclayerlower;
	fingers[x].layer[1].reclayer=reclayerupper;
    }
    }
    
    const float *playreff[4]={logspeed, logfast, logspeed_stop, logfast_stop}; 

    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	// SENSESHIFT=2, SENSEOFFSET=1800; 
	// SENSESHIFT=1, SENSEOFFSET=560;
	SENSESHIFT=0, SENSEOFFSET=64; // TESTY fixed

	// micromode logic outside mode switches
	// eg. mask
	/*	so we could have as masks for each section bit groups:

		N: sens, global, invert  // 3 bits
		111
		R as above
		P,RP: 11 live overlay, 11 speedarray, 1sync // 5 bits
		RP: 11 recorded overlay if any // 2 bits
		111 11111 11 = 10 bits // or do we want to say only set voltage settings in N and R so is not so long... but we would go back for that...
		we can just shift so stay with 10 bits
	*/

	// functions outside switch
	  FREEZERS;
          REALADC;
	  CTRL;

	// TODO: is the finger active = long freeze - we need to implement this
	
	// togplay and togrec
	if (fingers[daccount].active && togplay) fingers[daccount].play^=1;
	if (fingers[daccount].active && togrec) fingers[daccount].rec^=1;
	togplay=0; togrec=0;
	// logic of states now
	  if (fingers[daccount].rec && fingers[daccount].play){
	    if (fingers[daccount].layer[fingers[daccount].masterL].rec_end){
	    fingers[daccount].state=RP;
	  }
	    else {
	      fingers[daccount].state=R; // nothing to play
	    }
	  }
	  else if (fingers[daccount].lastmode==1 && fingers[daccount].play==0) { // if we leave overlaid via. exit from play
	    fingers[daccount].state=N;
	  }
	  else if (fingers[daccount].rec)	fingers[daccount].state=R;
	  else if (fingers[daccount].play && (fingers[daccount].layer[fingers[daccount].masterL].rec_end)) fingers[daccount].state=P;
	  else fingers[daccount].state=N;
	  
	  // do main mode/state work maybe with switches within this 
	
	// end of modes 
	
	WRITEDAC2;
	daccount++;
	if (daccount==8) {
	  daccount=0;
	  count++;
	  TEST_TOGGLES;      // only place where toggles - TESTY - newer toggles
	  // handle micromodes, resett, and  
	  // how - depends on active positions // states we deal with later - go up to 10 bits

	  if (newmode){
	    newmode=0;
	    breaker[10]=0;

	    if (modeheld>HOLDRESET) { //reset all
	      modeheld=0;
	      if (fingers[0].active) resett(0); 	      //	      if active reset that one;
	    }
	else if (modeheld>LONGMODE && modeheld<HOLDRESET) { // increment major mode if active
	  modeheld=0;
	  if (fingers[0].active) changemode(0);
	  if (fingers[1].active) changemode(1);
	  if (fingers[2].active) changemode(2);
	  if (fingers[3].active) changemode(3);
	  if (fingers[4].active) changemode(4);
	  if (fingers[5].active) changemode(5);
	  if (fingers[6].active) changemode(6);
	  if (fingers[7].active) changemode(7);
	  
	}	
	else if (modeheld<LONGMODE){ //inc minor mode 
	  modeheld=0; 
	  if (fingers[0].active) {
	    fingers[0].minormode++;
	    if (fingers[0].minormode>MINORMAX) fingers[0].minormode=0;
	  }
	  if (fingers[1].active) {
	    fingers[1].minormode++;
	    if (fingers[1].minormode>MINORMAX) fingers[1].minormode=0;
	  }
	  if (fingers[2].active) {
	    fingers[2].minormode++;
	    if (fingers[2].minormode>MINORMAX) fingers[2].minormode=0;
	  }
	  if (fingers[3].active) {
	    fingers[3].minormode++;
	    if (fingers[3].minormode>MINORMAX) fingers[3].minormode=0;
	  }
	  if (fingers[4].active) {
	    fingers[4].minormode++;
	    if (fingers[4].minormode>MINORMAX) fingers[4].minormode=0;
	  }
	  if (fingers[5].active) {
	    fingers[5].minormode++;
	    if (fingers[5].minormode>MINORMAX) fingers[5].minormode=0;
	  }
	  if (fingers[6].active) {
	    fingers[6].minormode++;
	    if (fingers[6].minormode>MINORMAX) fingers[6].minormode=0;
	  }
	  if (fingers[7].active) {
	    fingers[7].minormode++;
	    if (fingers[7].minormode>MINORMAX) fingers[7].minormode=0;
	  }
	  
	}
	} // newmode

	  
	}
    }
  }

