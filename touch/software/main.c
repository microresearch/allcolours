#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_hal_pwr.h"
#include "misc.h"
#include "stm32f4xx_conf.h"

extern void resett(uint32_t dacc);

#define WRITEDACX {						\
  GPIOC->BSRRL = 1<<11;						\
  DAC_SetChannel1Data(DAC_Align_12b_R, 4095);	\
  j = DAC_GetDataOutputValue (DAC_Channel_1);			\
  GPIOC->BSRRH = 0b1110100000000000;				\
  GPIOC->BSRRL=(4)<<13;					\
}


/*

PROG: from top: 3.3v, SWCLK, SWDIO, GND (lower 2 swopped)

/* DMA buffer for ADC  & copy */
//__IO uint16_t adc_buffer[8];

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)


void io_config2 (void) {

       // Enable clocks for port A and DAC
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
       RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
       GPIO_InitTypeDef GPIO_InitStructure;

       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       //       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_Init(GPIOA, &GPIO_InitStructure);

       // PWM TIM1 on PA8
       GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOA, &GPIO_InitStructure);

       // PWMx TIM2 CH2 on PB5
       
       GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM2);
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOB, &GPIO_InitStructure);

       
       // PWM TIM4 on  //TIM4_CH2 - PB7 pin 59 
       GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOB, &GPIO_InitStructure);

       // PWM - TIM8_CH2 - PC7 pin 38 
       GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOC, &GPIO_InitStructure);

       // - TIM12_CH1 PB14 pin 35 // moved FR6 was pin PB14
       GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOB, &GPIO_InitStructure);

       /*
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       //       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_Init(GPIOA, &GPIO_InitStructure);
       */
       
       
       /* DAC channel 1 Configuration */
       DAC_InitTypeDef DAC_InitStructure1;
       DAC_InitStructure1.DAC_Trigger = DAC_Trigger_None;
       DAC_InitStructure1.DAC_WaveGeneration = DAC_WaveGeneration_None;
       DAC_InitStructure1.DAC_OutputBuffer = DAC_OutputBuffer_Disable; // was Enable but disable gets rid of offset!
       DAC_Init(DAC_Channel_1, &DAC_InitStructure1);
       //       DAC_StructInit(&DAC_InitStructure1);
       /* Enable DAC Channel 1 */
       DAC_Cmd(DAC_Channel_1, ENABLE);
       DAC_Cmd(DAC_Channel_2, DISABLE);

}

#define false 0

void clocksetup413 (void)
{
  //  FLASH_SetLatency(LL_FLASH_LATENCY_3); - no HAL
  FLASH->ACR = (1<<8) | (1<<9)| (1<<10)| (3<<0);
      RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
    RCC_DeInit();//a must
    
    do{
       RCC_HSEConfig(RCC_HSE_ON);
      }
     while (!RCC_WaitForHSEStartUp());

    RCC_PLLConfig(RCC_PLLSource_HSE, 4, 100, 2, 2);//100MHZ

    do{
       RCC_PLLCmd(ENABLE);
      }
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)!=SET);

    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);

    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
   SystemCoreClockUpdate();
}

//DAC_InitTypeDef dac_init_s;

int main(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBase_InitStructure;
  TIM_OCInitTypeDef TIM_OC_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  
  unsigned int i, adcr, j, k=0, otherk=0, flipped, prev_state, value, offset;
    i = adcr = j = k = 0;
    unsigned int dacval[8]={};
    GPIO_InitTypeDef GPIO_InitStructure;
    //SystemClock_Config();
    //                initClock();

    // instead: 29/12/2021 - 180 MHz we should have from HSE external 8 MHz clock
    // as in SEG but do we need to update timings
    //Enable HSE clock
    
    //    RCC_HSEConfig(RCC_HSE_ON);
    //Wait for clock to stabilize
    //    while (!RCC_WaitForHSEStartUp());
#ifdef fouronethree
        clocksetup413(); // leave out for 446 but how do we get that clock 413!!!!!TESTY
#endif
    // 8 channels
	    //	    ADC1_Init((uint16_t *)adc_buffer);

      for (uint32_t x=0;x<8;x++){
	resett(x); 
      }
	    
    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    /* enable clocks for DMA2, ADC1, GPIOA ----------------------------------*/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
    //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* ADC Common Init ------------------------------------------------------*/
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2; // was 2
 	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; // was 5?
	ADC_CommonInit(&ADC_CommonInitStructure);

	/* ADC1 Init ------------------------------------------------------------*/
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; // was enable
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_ExternalTrigConv = DISABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; // was right - in CLOUDS is left? so is 12 bits
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	//	ADC_InitStructure.ADC_NbrOfChannel = 10; not existing
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_Cmd(ADC1, ENABLE);
	/*
	  PA0->PA3 4
	  PA5->PA7 3
	  PC0->PC2 3
	  PB0(ADC4), PB1(ADC8) ???
	*/

    
  io_config2 ();



    //   ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_84Cycles);
	// adding new ADCs
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;// as pin 4 is DAC
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    //    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // changes nothing
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // adc8 is adc1_10 =pc0
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;// | GPIO_Pin_1; PC10  and 11 12 + added some
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;// | GPIO_Pin_2;// | GPIO_Pin_1; PC10  and 11 12
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    
    //- DONE rec on PB2, play on PB4 - swopped with FR3, push on PB6 
    //- FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!) // FR8 is now PB4
    /*
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
    */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; // FR8 now
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // 19/8/2024 now use as PWM so swopped -> PB3 DONE // FR6
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /// TO TEST: as output
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  //  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /*
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  */
  
  // TEST - PC8 input from 40106 for freezing/rec/play etc. power it with 3.3v

  // led first
  //  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output

  // internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  // TIMER2 with clock settings and period=1024, prescale of 32 gives toggle of: 1 KHz exactly (so is double at 2 KHZ and this seems to work well)
  // which translates to 65 MHZ clock from APB1 - but above APB1 is 45 MHZ ???

  // 1024/4 is 8x 862Hz (toggle speed so 2x that which is fine for us but we need to lower the sample/hold cap...

  // 16/12 stay with 1024/8 for 1.5 KHz I think - check this
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 1024; // was 1024 divide by 4 should work TEST! = 256 doesn't run
  /// XXXXX
  TIM_TimeBase_InitStructure.TIM_Prescaler = 24; // 24! was 32... for 413 try 16/// was 8 ///  what speed is this 18khz toggle = 36k  - how we can check - with one of our pins as out
  // for 413 which seems run 8x slower now we have 5 which matches our old speed with 446
  // 4 is orig
  // 48 is too slow...
  // 30/9/3021: changed prescaler to 16 and then 32 to get rid of bleed
  // 6/10/2021: still tiny bleed but can live with it!
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; // was 1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; // was 1
  NVIC_Init(&NVIC_InitStructure);
  TIM_Cmd(TIM2, ENABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  
  
  // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10
  //    GPIOC->BSRRH = 0b1110100000000000;  // clear PC11 - clear pc11 and top bits -> low

  //    uint8_t firstByte, secondByte, configBits;
      uint32_t daccount=0;    

      /* TRIAL PWM on
	 35: TIM12_CH1
	 38: TIM8_CH2
	 41: TIM1_CH1 PA8
	 59: TIM4_CH2
	 //	 prev PWM code from: segments
      */
  // TIM1 on PA8      
  TIM_DeInit(TIM1);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // 
  TIM_TimeBaseInit(TIM1, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC1Init(TIM1, &TIM_OC_InitStructure); // 
  //  TIM_OC2Init(TIM1, &TIM_OC_InitStructure); // 
  //  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this! // for TIM1 to update we needed to comment out - as opposed to in AC but there was TIM3 2/9/2021
  //  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM1, ENABLE);
  TIM_CtrlPWMOutputs(TIM1, ENABLE); // we needed this for timer1 to be added

 //TIM4_CH2 - PB7 pin 59
  TIM_DeInit(TIM4);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // 
  TIM_TimeBaseInit(TIM4, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC2Init(TIM4, &TIM_OC_InitStructure); 
  //  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this! // for TIM1 to update we needed to comment out - as opposed to in AC but there was TIM3 2/9/2021
  //  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM4, ENABLE);
  TIM_CtrlPWMOutputs(TIM4, ENABLE); // we needed this for timer1 to be added

  //- TIM8_CH2 - PC7 pin 38 
  TIM_DeInit(TIM8);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // 
  TIM_TimeBaseInit(TIM8, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC2Init(TIM8, &TIM_OC_InitStructure); 
  //  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this! // for TIM1 to update we needed to comment out - as opposed to in AC but there was TIM3 2/9/2021
  //  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM8, ENABLE);
  TIM_CtrlPWMOutputs(TIM8, ENABLE); // we needed this for timer1 to be added

  // TIM12_CH1 PB14 pin 35 
  TIM_DeInit(TIM12);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // 
  TIM_TimeBaseInit(TIM12, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC1Init(TIM12, &TIM_OC_InitStructure);
  //  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this! // for TIM1 to update we needed to comment out - as opposed to in AC but there was TIM3 2/9/2021
  //  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM12, ENABLE);
  TIM_CtrlPWMOutputs(TIM12, ENABLE); // we needed this for timer1 to be added

  // what timer we need to add for centre pads -> PWMx is TIM3_CH2

  // TIM3

  TIM_DeInit(TIM3);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // 
  TIM_TimeBaseInit(TIM3, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC2Init(TIM3, &TIM_OC_InitStructure);
  //  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this! // for TIM1 to update we needed to comment out - as opposed to in AC but there was TIM3 2/9/2021
  //  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM3, ENABLE);
  TIM_CtrlPWMOutputs(TIM3, ENABLE); // we needed this for timer1 to be added
      
  
  while(1) {
    
    TIM1->ARR=100;
    TIM1->CCR1 = 50; // pulse width
    //    TIM1->CCR2 = 80; // channel 2 

    TIM4->ARR=100;
    TIM4->CCR1 = 50; // pulse width
    
    TIM8->ARR=100;
    TIM8->CCR1 = 50; // pulse width

    TIM12->ARR=100;
    TIM12->CCR1 = 50; // pulse width // 110 KHz
    
    TIM3->ARR=100;
    TIM3->CCR2 = 50; // pulse width
    
    
    //		WRITEDACX;       /// TESTY
      // all now placed in interrupt so is well timed
      // TODO - test freeze and all buttons
      //  daccount=1;
      //    GPIOC->BSRRH = 0b1110100000000000;  // clear PC11 - clear pc11 and top bits -> low
      //      delay();
      //      GPIOC->BSRRL = 0b1110000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
  //  GPIOC->BSRRL=(daccount)<<13; // for now just top bits
  //  GPIOC->BSRRL = 0b001000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
      //      GPIOC->BSRRL = 0b1000000000000000;      // now we want to test the VCAs-> lower bits so 1 is lower right
  //k=4095; // peak 6.6v      
  //DAC_SetChannel1Data(DAC_Align_12b_R, dacval[daccount]); // 1000/4096 * 3V3 == 0V8
  //      k=4095;
      //    ADC_SoftwareStartConv(ADC1);
    //  k=adc_buffer[daccount]>>4; // adc[1] is dac0, 3 is dac 1, 5 is dac 2, 7 is dac 3 - we can organise this in adc.c
  // but still question of bleed of adc0 into adc3 - check if is vice versa? seems in software as changed when re-org
  
  // TEST setting k to ADC1
  //        value =(float)adc_buffer[SELX]/65536.0f; 
  //dacval[daccount]=0;//adc_buffer[daccount]>>4; // 12 bits for DAC
      //  k=0;
      //  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //  j = DAC_GetDataOutputValue (DAC_Channel_1);
      //  daccount++;
      //  if (daccount==8) daccount=0;  
      //    delay();
    /*    
    GPIOA->BSRRH = 1<<9;//0b0000000010000000;  // PA8
    delay();
    GPIOA->BSRRL = 1<<9;//0b0000000010000000;     
    delay();
    */
    }
}

#ifdef  USE_FULL_ASSERT
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
    {
    }
}
#endif

#if 0
void NMI_Handler(void)
{ 
  while(1){};
}

void HardFault_Handler(void)
{ 
  while(1){};
  }


void MemManage_Handler(void)
{ 
  while(1){};
}

void BusFault_Handler(void)
{ 
  while(1){};
}

void UsageFault_Handler(void)
{ 
  while(1){};
}

void SVC_Handler(void)
{ 
  while(1){};
}

void DebugMon_Handler(void)
{ 
  while(1){};
}

void PendSV_Handler(void)
{ 
  while(1){};
}
#endif
