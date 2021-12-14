/**

14.12: put in modechanging clearance into macro TOGGLE - still needs to be TESTED!

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

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRK8 (64*8) // 64 at 4 in INT2 // so for 8 in main.c we need 32
#define BRK 64
#define DELB 100 // delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK

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
    if (!(GPIOB->IDR & (freezer[7]))) {					\
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
  ADC_SoftwareStartConv(ADC1);					\
  real[daccount]=adc_buffer[daccount]<<shifter[daccount];	\
  if (real[daccount]>4095) real[daccount]=4095;			\
  }

#define LASTPLAY {					\
    if (lastplay==0) {					\
      lastplay=1;					\
      play_cnt[0]=0;					\
      play_cnt[1]=0;					\
      play_cnt[2]=0;					\
      play_cnt[3]=0;					\
      play_cnt[4]=0;					\
      play_cnt[5]=0;					\
      play_cnt[6]=0;					\
      play_cnt[7]=0;					\
    }							\
  }

#define LASTREC {					\
    if (lastrec==0) {					\
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

#define WRITEDAC {				\
  GPIOC->BSRRH = 0b1110100000000000;				\
  DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]);	\
  j = DAC_GetDataOutputValue (DAC_Channel_1);			\
  GPIOC->BSRRL=(daccount)<<13;					\
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

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

extern __IO uint16_t adc_buffer[8];
static uint16_t recordings[8][7000]; // 
static uint16_t rec_cnt[8]={0};
static uint16_t play_cnt[8]={0};
static uint16_t tgr_cnt[10]={0};
static uint16_t rec=0, play=0;

static uint16_t shifter[8]={2,2,2,2,1,1,1,1}; // shifter seperates vca from cv - VCA comes first
//static uint16_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint32_t c=0, val=0;
    static uint32_t daccount=0;
    static uint32_t speed=1;
    volatile uint32_t k;
    uint32_t j,fing;
    // array to map freeze but exception is FR8 on PC4! 
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint32_t bits;
    static uint32_t values[8], real[8];
    static uint32_t frozen[8]={0};
    static uint32_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0}, ender[8]={7000}, recsp[8]={0};
    static uint32_t lasttriggered[11]={0}, breaker[11]={0};
    
    uint32_t tmp, trigd;
    int32_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	mode=4; // testings

	switch(mode){
	case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing? or full speed?
	  // mode could also be no change of speed
	  FREEZERS;
      	  if (frozen[daccount]==0) {
	    REALADC;
	  }

	  if (play){
	    LASTPLAY;
	    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
	    speed=32;
	    if ((count%speed)==0){ // speed goes from 1 to X what
	      play_cnt[daccount]++;
	      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	    }
	  } // if play
	  else lastplay=0;
    
	  ///// recordings
	  if (count%(32)==0) { //for 1 KHZ?
	    if (rec){ // we are recording
	      LASTREC;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
	    } // if rec
	    else lastrec=0;
	    	  } // count32

	  ////// write to DAC
	  // if playback add
	  if (play==1) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else values[daccount]=real[daccount];    // otherwise just values
    
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    // speed only increasing
	    ADC_SoftwareStartConv(ADC1);
	    speed=(adc_buffer[6]>>6); // 6 bits on purpose? and we don't freeze speed... 
	    if (speed>32) speed=32;
	    speed=32-(speed); 
	    TOGGLES;      
	  }       
	  break; ///// case 0
	  ///////////////////////////////////////////

	case 1: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all
	  // speed also decreasings
	  FREEZERS;
      	  if (frozen[daccount]==0) {
	    REALADC;
	  }

	  if (play){
	    LASTPLAY;
	    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
	    if ((count%speed)==0){ // speed goes from 1 to X what
	      play_cnt[daccount]++;
	      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	    }
	  } // if play
	  else lastplay=0;
    
	  ///// recordings
  	  if (count%(32)==0) { //for xxx HZ?
	    if (rec){ // we are recording
	      LASTREC;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
	    } // if rec
	    else lastrec=0;
	  } // count32

	  ////// write to DAC
	  // if playback add
	  if (play==1) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else values[daccount]=real[daccount];    // otherwise just values
    
	  WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    // speed only increasing
	    ADC_SoftwareStartConv(ADC1);
	    speed=(adc_buffer[6]>>4); // 8 bits
	    if (speed>127) speed=127;
	    speed=127-(speed); //4 bits=16 256/16=
	    TOGGLES;      
	  }       
	  break; ///// case 1
	  ///////////////////////////////////////////

	case 2: //basic mode 0 with overlay as midpoint thing
	  FREEZERS;
      	  if (frozen[daccount]==0) {
	    REALADC;
	  }

	  if (play){
	    LASTPLAY;
	    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
	    if ((count%speed)==0){ // speed goes from 1 to X what
	      play_cnt[daccount]++;
	      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	    }
	  } // if play
	  else lastplay=0;
    
	  ///// recordings
  	  if (count%(32)==0) { //for xxx HZ?
	    if (rec){ // we are recording
	      LASTREC;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
	    } // if rec
	    else lastrec=0;
	  } // count32

	  ////// write to DAC
	  // if playback mid
    if (play==1) {
      //      values[daccount]+=real[daccount]; // to take to the midpoint so 4096/2=2048 is mid
      midder=values[daccount]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      values[daccount]=midder;
    }
    else values[daccount]=real[daccount];    // otherwise just values

    WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    // speed only increasing
	    ADC_SoftwareStartConv(ADC1);
	    speed=(adc_buffer[6]>>6); // 6 bits on purpose? and we don't freeze speed... 
	    if (speed>32) speed=32;
	    speed=32-(speed); 
	    TOGGLES;      
	  }       
	  break; ///// case 2
	  ///////////////////////////////////////////

	case 3: //basic mode 0 with overlay as modulo
	  FREEZERS;
      	  if (frozen[daccount]==0) {
	    REALADC;
	  }

	  if (play){
	    LASTPLAY;
	    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
	    if ((count%speed)==0){ // speed goes from 1 to X what
	      play_cnt[daccount]++;
	      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	    }
	  } // if play
	  else lastplay=0;
    
	  ///// recordings
  	  if (count%(32)==0) { //for xxx HZ?
	    if (rec){ // we are recording
	      LASTREC;
	      recordings[daccount][rec_cnt[daccount]]=values[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
	    } // if rec
	    else lastrec=0;
	  } // count32

	  ////// write to DAC
	  // if playback mid
    if (play==1) {
      values[daccount]+=real[daccount];
      values[daccount]=values[daccount]%4096;
    }
    else values[daccount]=real[daccount];    // otherwise just values

    WRITEDAC;
	  
	  daccount++;
	  if (daccount==8) {
	    daccount=0;
	    count++;
	    // speed only increasing
	    ADC_SoftwareStartConv(ADC1);
	    speed=(adc_buffer[6]>>6); // 6 bits on purpose? and we don't freeze speed... 
	    if (speed>32) speed=32;
	    speed=32-(speed); 
	    TOGGLES;      
	  }       
	  break; ///// case 3

	case 4:
	  GPIOC->BSRRH = 0b1110100000000000;		       
	  DAC_SetChannel1Data(DAC_Align_12b_R, val);
	  j = DAC_GetDataOutputValue (DAC_Channel_1);		
	  GPIOC->BSRRL=(daccount)<<13;
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
