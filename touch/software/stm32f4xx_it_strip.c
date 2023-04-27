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

// MACRO 

#define RESETT {					\
  for (x=0;x<8;x++){				\
  for (y=0;y<MAXREC;y++){			\
    recordings[x][y]=0;				\
  }						\
  }						\
}

#define MODECHANGED {				\
  freezer[0]=0;					\
  freezer[1]=0;					\
  freezer[2]=0;					\
  freezer[3]=0;					\
  freezer[4]=0;					\
  freezer[5]=0;					\
  freezer[6]=0;					\
  freezer[7]=0;					\
  rec=0;					\
  play=0;					\
}

#define TOGGLES {				  \
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<2))) {		\
	lasttriggered[9]=breaker[9];		\
	breaker[9]=0;				\
	}					\
	else {					  \
	breaker[9]++;				  \
	if (breaker[9]>1024) breaker[9]=1024;	  \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	delay(); \
	if (lasttriggered[9]>BRK) {	\
	  lasttriggered[9]=0;				\
	  play^=1;					\
	  if (rec && play) rec=0;			\
	}						\
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	\
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<10))) {		\
	lasttriggered[8]=breaker[8];		\
	breaker[8]=0;				\
	}					\
	else {					  \
	breaker[8]++;				  \
	if (breaker[8]>1024) breaker[8]=1024;	  \
	}					  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	delay(); \
	if (lasttriggered[8]>BRK) {	\
	  lasttriggered[8]=0;				\
	  rec^=1; \
	  if (play && rec) play=0; \
	} \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;     \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	if (!(GPIOB->IDR & (1<<6))) {		\
	lasttriggered[10]=breaker[10];		\
	breaker[10]=0;				\
	}					\
	else {					  \
	breaker[10]++;				  \
	if (breaker[10]>1024) breaker[10]=1024;	  \
	}					     \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;    \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure);			  \
	delay(); \
	if (lasttriggered[10]>BRK) {	\
	  lasttriggered[10]=0;				\
	  mode+=1;					\
	  if (mode>=MAXMODES) mode=0;			\
	  MODECHANGED;					\
	}						\
}

#define FREEZERS {					\
  if (daccount==7){							\
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			\
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
    GPIO_Init(GPIOC, &GPIO_InitStructure);				\
    GPIOC->BSRRL=(1)<<6;						\
    delay();								\
    if (!(GPIOC->IDR & (freezer[7]))) {					\
      lasttriggered[7]=breaker[7];					\
      breaker[7]=0;							\
    }									\
    else {								\
      breaker[7]++;							\
      if (breaker[7]>1024) breaker[7]=1024;				\
    }									\
    GPIOC->BSRRH=(1)<<6;						\
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			\
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			\
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;			\
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
    GPIO_Init(GPIOC, &GPIO_InitStructure);				\
    delay();								\
    if (lasttriggered[7]>BRK) {						\
      frozen[7]^=1;							\
      lasttriggered[7]=0;						\
    }									\
  }									\
  else									\
    {									\
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			\
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
      GPIO_Init(GPIOC, &GPIO_InitStructure);				\
      GPIOC->BSRRL=(1)<<6;						\
      delay();								\
      if (!(GPIOB->IDR & (freezer[daccount]))) {			\
	lasttriggered[daccount]=breaker[daccount];			\
	breaker[daccount]=0;						\
      }									\
      else {								\
	breaker[daccount]++;						\
	if (breaker[daccount]>1024) breaker[daccount]=1024;		\
      }									\
      GPIOC->BSRRH=(1)<<6;						\
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				\
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;			\
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			\
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;			\
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			\
      GPIO_Init(GPIOC, &GPIO_InitStructure);				\
      delay();								\
      if (lasttriggered[daccount]>BRK) {				\
	frozen[daccount]^=1;						\
	lasttriggered[daccount]=0;					\
      }									\
    }									\
  }


#define REALADC {						\
switch(daccount){						\
  case 0:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[0]=ADC_GetConversionValue(ADC1);					\
  if (real[0]>1023) real[0]=1023;					\
  reall[0]=real[0];							\
  real[0]=logval[(real[0])];						\
  break;								\
  case 1:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[1]=ADC_GetConversionValue(ADC1);				\
  if (real[1]>1023) real[1]=1023;					\
  reall[1]=real[1];							\
  real[1]=logval[(real[1])];						\
  break;								\
  case 2:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[2]=ADC_GetConversionValue(ADC1);					\
  if (real[2]>1023) real[2]=1023;					\
  reall[2]=real[2];							\
  real[2]=logval[(real[2])];						\
  break;								\
  case 3:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[3]=ADC_GetConversionValue(ADC1);				\
  if (real[3]>1023) real[3]=1023;					\
  reall[3]=real[3];							\
  real[3]=logval[(real[3])];						\
  break;								\
  case 4:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[4]=ADC_GetConversionValue(ADC1);				\
  real[4]=real[4]<<1;						\
  if (real[4]>4095) real[4]=4095;				\
  break;							\
  case 5:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));			\
  real[5]=ADC_GetConversionValue(ADC1);				\
  real[5]=real[5]<<1;						\
  if (real[5]>4095) real[5]=4095;					\
  break;								\
  case 6:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[6]=ADC_GetConversionValue(ADC1);				\
  real[6]=real[6]<<1;						\
  if (real[6]>4095) real[6]=4095;					\
  break;								\
  case 7:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[7]=ADC_GetConversionValue(ADC1);				\
  real[7]=real[7]<<1;							\
  if (real[7]>4095) real[7]=4095;					\
  break;								\
   }									\
}


#define DOSPEED {				\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles); \
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  speed=ADC_GetConversionValue(ADC1);					\
  if (speed>1023) speed=1023;			\
  }

#define LASTPLAY {					\
    if (lastplay==0) {					\
      lastplay=1;					\
      play_cnt[0]=0.0f;					\
      play_cnt[1]=0.0f;					\
      play_cnt[2]=0.0f;					\
      play_cnt[3]=0.0f;					\
      play_cnt[4]=0.0f;					\
      play_cnt[5]=0.0f;					\
      play_cnt[6]=0.0f;					\
      play_cnt[7]=0.0f;					\
      overlap[0]=0;					\
      overlap[1]=0;					\
      overlap[2]=0;					\
      overlap[3]=0;					\
    }							\
  }

#define LASTREC {					\
    if (lastrec==0) {					\
      overlap[0]=0;					\
      overlap[1]=0;					\
      overlap[2]=0;					\
      overlap[3]=0;					\
      lastrec=1;					\
      rec_cnt[0]=0;					\
      rec_cnt[1]=0;					\
      rec_cnt[2]=0;					\
      rec_cnt[3]=0;					\
      rec_cnt[4]=0;					\
      rec_cnt[5]=0;					\
      rec_cnt[6]=0;					\
      rec_cnt[7]=0;					\
    }							\
  }

// closest we get - bleed from one to next is minimal
// BSRRH is low, L is high
#define CLEARDAC {						\
      DAC_SetChannel1Data(DAC_Align_12b_R, 0);			\
      j = DAC_GetDataOutputValue (DAC_Channel_1);		\
  }

#define WRITEDAC {						\
  DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]);	\
  j = DAC_GetDataOutputValue (DAC_Channel_1);			\
  GPIOC->BSRRH = 1<<11;						\
  GPIOC->BSRRH = 0b1110000000000000;				\
  GPIOC->BSRRL=(daccount)<<13;					\
  delay2();							\
  GPIOC->BSRRL = 1<<11;						\
  CLEARDAC;							\
}

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
static uint32_t recordings[8][MAXREC]={0}; // 
static uint32_t rec_cnt[8]={0};
static float play_cnt[8]={0.0f};
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

// try now for float and interpolate speedsample - this seems to work but we need to figure out speed range
// with speed as 0.125 to 4.0f - or use logspeed. - we use logspeed now to call this
uint32_t speedsample(float speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int res=(play_cnt[dacc] - (float)lowerPosition);
    //  Return interpolated table value
  float sample= ((samples[lowerPosition]&4095) + 
		 (res *
		  ((samples[upperPosition]&4095) - (samples[lowerPosition]&4095)))); // adapted for top bits

      return (uint32_t)sample;
}
  
void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t daccount=0;
    static uint32_t speed=1, overlap[8]={0};
    volatile uint32_t k;
    uint32_t j,x,y;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t prev[8]={1,2,3,4,5,6,7,0};
    uint32_t bits, recspeed;
    uint32_t values[8], real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static
    static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
    static uint32_t playy[8]={0,0,0,0, 0,0,0,0};
    static uint32_t recc[8]={0,0,0,0, 0,0,0,0};
    static uint32_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0};
    static uint32_t lasttriggered[11]={0}, breaker[11]={0};
    
    uint32_t tmp, trigd;
    int32_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=9; // testy

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
	      //	      overlap[daccount]=0;
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

	case 9: // start on looped recording and overlay - so it is always playing/recording - 
	  // rec and play length held change start and end points
	  // or they could just operate as start rec, start play...
	  // fixed speed but additional speed mode could be interesting as re-records at different speeds
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  ////
	  LASTREC; // reset all
	  LASTPLAY;

	  speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	  values[daccount]=speedsample(1.0f, MAXREC, daccount, recordings[daccount]);
	  values[daccount]+=real[daccount];

	  recordings[daccount][rec_cnt[daccount]]=values[daccount];
	  rec_cnt[daccount]++;
	  if (rec_cnt[daccount]>MAXREC) {
	    rec_cnt[daccount]=0;
	  }

	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    TOGGLES;      
	  }       
	  break; ///// 

	  
	  ///////////////////////////

	} // end of modes switch    
    }
  }
