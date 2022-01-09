/**

20/12+ - see notes.org for changes

14/12: put in modechanging clearance into macro TOGGLE - still needs to be TESTED!

13/12: changes to freeze/toggle logic which seem to work well, new macrosDONE

6/12: try new freeze/toggle logics - working better so test for freezings, tested but try with other fingers before we put into TOGGLE MACRO TODO!

2/12: re-check freeze etc.logic as seems odd - was wrong way round so corrected but still not 100% as needs release

2/11: we have bleed on voltages - small but present and how can we fix this?

18/10: on mode change should we stop rec/playback as this will change reading of data (only in some cases).DONE in macro 14/12

14/10: filled in mode 0 to test all

13/10: TODO: code in freezers, mode switch and rec/play with simple case 0 and test!

11/10: TODO: simplify code sections and test all freezers, rec, mode, playback (basic mode)

- what are our modes and where are these defined? in it.c

Revisiting 30 Sept:

- 30/9 tests: 2 and 3 not closing: 3 was adc issue which fixed
   somehow, 2 still bleeds at 60mV, we adjusted TIM2 slower to get rid
   of bleed across VCAs (why now?), still to test new freeze
   functionality...also got rid of bitshift as was loud (to check on
   scope), maybe try different resistor values for closings, testing
   first freeze and seems to work


//////////////////////////

TODO: August 30+ 2021:

- new PCB - we have trig on PC6 which needs to go high only when we sense any of trigs (freezers, rec, play, mode)

- basic operations of VCA and voltage with new board (also now we have low pass in hardware)
- new freezer/trig code and test all

think it is in mode23 but we need to change the output pin here!

- figure out modes, timings, log etc.

  */ 

/* Includes ------------------------------------------------------------------*/
//#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "adc.h"
#include "resources.h"

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRK8 (64*8) // 64 at 4 in INT2 // so for 8 in main.c we need 32
#define BRK 64
#define DELB 200 // delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK
#define DELA 64 // for clear DAC

#define MAXMODES 4

GPIO_InitTypeDef GPIO_InitStructure;


// MACRO 

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

/*
#define REALADC {						\
  real[daccount]=adc_buffer[daccount]<<shifter[daccount];	\
  if (real[daccount]>4095) real[daccount]=4095;			\
  }
*/


// channel 5 case 2 doesn't work!
#define REALADC {						\
switch(daccount){						\
  case 0:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[0]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 1:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[1]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 2:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[2]=ADC_GetConversionValue(ADC1);					\
  break;								\
  case 3:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[3]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 4:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[4]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 5:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[5]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 6:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[6]=ADC_GetConversionValue(ADC1);				\
  break;								\
  case 7:							\
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_480Cycles);\
  ADC_ClearFlag (ADC1, ADC_FLAG_EOC);					\
  ADC_SoftwareStartConv(ADC1);						\
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);		\
  real[7]=ADC_GetConversionValue(ADC1);				\
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

extern __IO uint16_t adc_buffer[8];
static uint16_t recordings[8][7000]={0}; // 
static uint16_t rec_cnt[8]={0};
static float play_cnt[8]={0.0f};
//static uint16_t tgr_cnt[10]={0};
static uint16_t rec=0, play=0;

static uint16_t shifter[8]={2,2,2,2,2,2,2,2}; // shifter seperates vca from cv - VCA comes first
//static uint16_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here

//static uint16_t order[8]={7,6,5,4,3,2,1,0}; // 0-3 is VCA from bottom
//static uint16_t order[8]={5,5,5,5,5,5,5,5}; // 0-3 is VCA from bottom

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}


//	    values[daccount]=speedsample(speed, rec_cnt[daccount], recordings[daccount]);
// no filtering and we can't slow down here
uint16_t upspeedsample(uint32_t speedy, uint32_t lengthy, uint16_t dacc, uint16_t *samples){
  uint16_t value;
  // test construction in most basic mode
  /*
  value=(samples[play_cnt[dacc]])&4095;  // ignore top bits
	      play_cnt[dacc]++;
	      if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0; // but what if we overlap then play full...
  */
  // speedy is 1-32 ---> 1 is basic speed.
  speedy+=1;
  play_cnt[dacc]+=(float)speedy;
  if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0.0f;
  value=(samples[(int)(play_cnt[dacc])])&4095;  // ignore top bits
  return value;
}

// try now for float and interpolate speedsample - this seems to work but we need to figure out speed range
// with speed as 0.125 to 4.0f - or use logspeed.
uint16_t speedsample(float speedy, uint32_t lengthy, uint16_t dacc, uint16_t *samples){
  int lowerPosition, upperPosition;
  
  play_cnt[dacc]=mod0(play_cnt[dacc]+speedy, lengthy);

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt[dacc];
  upperPosition = mod0(lowerPosition + 1, lengthy);

    //  Return interpolated table value
      float sample= (samples[lowerPosition] +
              ((play_cnt[dacc] - lowerPosition) *
               (samples[upperPosition] - samples[lowerPosition])));

      return (int)sample;
}
  
void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t c=0, val=0;
    static uint32_t daccount=0;
    static uint32_t speed=1, overlap[8]={0};
    volatile uint32_t k;
    uint32_t j,fing;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t prev[8]={1,2,3,4,5,6,7,0};
    uint32_t bits;
    uint16_t values[8], real[8]; // not static
    static uint32_t frozen[8]={0};
    static uint32_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0}, ender[8]={7000}, recsp[8]={0};
    static uint32_t lasttriggered[11]={0}, breaker[11]={0};
    
    uint32_t tmp, trigd;
    int32_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=0; // testings

	switch(mode){
	case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing? or full speed?
	  // mode could also be no change of speed
	  FREEZERS;
	  
	  if (frozen[daccount]==0) {
	    REALADC;
	  }

	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=7000;
	    	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>7000) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1 && daccount!=6) { //TEST: don't add for speed!
	    if (real[daccount]>1023) real[daccount]=1023;
	    values[daccount]+=logval[(real[daccount])];
	  }
	  else {
	    if (real[daccount]>1023) real[daccount]=1023;
	    values[daccount]=logval[(real[daccount])];    // otherwise just values
	  }
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    // speed only increasing
	    DOSPEED;
	    TOGGLES;      
	  }       
	  break; ///// case 0
	  ///////////////////////////////////////////

	case 4: // speed test ONLY
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13;
	  //	  CLEARDAC;
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	  if (val==0) val=4095;
	  else val=0;
	  }
	  break;

	} // end of modes switch    
    }
  }
