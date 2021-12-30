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
#include "adc.h"
#include "stm32f4xx_conf.h"
/*

PROG: from top: 3.3v, SWCLK, SWDIO, GND (lower 2 swopped)

// latest PCB now April 2021:

// 13/4/2021: toggling and freezing implemented, all hardware tested and working...

TODO:

- basic recording mode, how we handle freezes and length

- different modes to list out and implement for record and playback

//NOTES 14/4:

STM32F446RETx: 128KB memory. so if we have 2bytes for each cell x8 = 16 per step at 1 KHz

say we use 8k for other variables =120,000 remaining

7500 steps for each max = 7.5 seconds at 1KHz (fastest)

75 seconds at 100Hz

- run at max speed and record at slower speed

//

10/2/2020 - start to set up TIM2 interrupt

26/1/2020 - new code base for testing on latest PCB -> note on pcb PROG HEADER we swop last 2 gnd and swdio 

// test fixed DAC outs to voltages out and to VCAs.

// test ADCs in from pads to voltages out an VCAs.

// test FR1-8 inputs, rec, play and push

- implement recording, playback and any logic/scalings

- internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15

- ADC0-3 on PA0/1/2/3
- ADC5-7 on PA5/6/7
- ADC4 on PC0

- rec on PB2, play on PB4, push on PB6
- FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!)

On PCB panel (clockwise): 
- top one(3): ADC5 and ADC4, F6 and F5 (is adc5top or 4 the one for VCA?)
- 4: ADC7 and ADC6, F8, F7
- 1: ADC1, ADC0, F1, F2
- 2: AS+DC3, ADC2, F3, F4

/////////////////////////////////////////////////////////////

New note - now we will use onboard DAC as we only use 12x ADC

Testing on STM32F446 NUCLEO

For new touch module/own touch things: 

- read from say 12x ADC and output signals on DAC - which will be multiplexed
- so we need input ADC and eventually toggle input pins for rec/play with, output address and enable for 4051  

- first steps: ADC inputs, DAC output (should be on PA4 (DAC_OUT1) which is marked A2 on lower left of board!

but we can only have 15 ADC ins as one doubles up as DAC!

// PROGRESS: now DAC seems to work...

// ADCs, output pins, input pins...

refs:  https://stackoverflow.com/questions/45718493/stm32-f446re-simple-dac-output-what-am-i-missing

https://csserver.evansville.edu/~blandfor/Engr101/NucleoBoardUserManual.pdf

// TODO: testing for external DAC such as MPC492X (one or two DACs) - tested with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test - SPI seems to be working now with enable to +V and schematic as in: 

http://community.axoloti.com/t/gpio-i-o-example-dac-mcp4x22-spi/134

MOSI is on PB5, SCK is on PB3, CS is on PA15

 */

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/

/* DMA buffer for ADC  & copy */
__IO uint16_t adc_buffer[8];

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
       //       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_Init(GPIOA, &GPIO_InitStructure);

       /* DAC channel 1 Configuration */
       DAC_InitTypeDef DAC_InitStructure1;
       DAC_InitStructure1.DAC_Trigger = DAC_Trigger_None;
       DAC_InitStructure1.DAC_WaveGeneration = DAC_WaveGeneration_None;
       DAC_InitStructure1.DAC_OutputBuffer = DAC_OutputBuffer_Disable; // was Enable but disable gets rid of offset! both bleed
       DAC_Init(DAC_Channel_1, &DAC_InitStructure1);
       //       DAC_StructInit(&DAC_InitStructure1);
       /* Enable DAC Channel 1 */
       DAC_Cmd(DAC_Channel_1, ENABLE);
       DAC_Cmd(DAC_Channel_2, DISABLE);

}

//Initialize clock config

//Siehe: https://github.com/jkerdels/stm32edu/blob/master/src/rcc.c

#define false 0

void initClock(){

  //Enable HSI-clock -> 16MHz

  RCC -> CR |= RCC_CR_HSION;

  //Wait for HSI is stable running

  while((RCC -> CR & RCC_CR_HSIRDY) == 0){}

  

  //Switch SYSCLK to HSI, SW -> 00

  RCC -> CFGR &= ~RCC_CFGR_SW_0;

  RCC -> CFGR &= ~RCC_CFGR_SW_1;

  //Wait for switching SYSCLK is ready

  while((RCC -> CFGR & RCC_CFGR_SWS_0 == false) && (RCC -> CFGR & RCC_CFGR_SWS_1 == false)){}

  //Config waitstates for flash memory, cpu should run with nearly 180MHz@3,3V -> 5ws after table, page 64

  FLASH -> ACR |= FLASH_ACR_LATENCY_5WS;

  //Config realtime clock, set LSI as clocksource

  RCC -> CSR |= RCC_CSR_LSION;

  //Set AHB clock prescaler for main bus matrix, psc=1 for running with maximum speed -> 180MHz, Presc. =1

  RCC -> CFGR |= RCC_CFGR_HPRE_DIV1;

  //Set clock for APB1 to AHB/4 => 180MHz/4 -> 45MHz

  RCC -> CFGR |= RCC_CFGR_PPRE1_DIV4;

  //Set clock for APB2 to AHB/2 => 180MHz/2 -> 90MHz

  RCC -> CFGR |= RCC_CFGR_PPRE2_DIV2;

  //Set phase lock loop

  //Disable PLL for config

  RCC -> CR &= ~RCC_CR_PLLON;

  RCC -> CR &= ~RCC_CR_PLLI2SON;

  //Select HSI for pll clock source

  RCC -> PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI;

  //Set prescaler for pll clock input: HSI(16MHz) -> input should be 2MHz -> Prescaler =8

  RCC -> PLLCFGR |= RCC_PLLCFGR_PLLM_3;

  //Clock = fin*(N/M) -> 2MHz*(360/4) for 180MHz

  //Set N=360 -> 0b1 0110 1000

  RCC -> PLLCFGR |= RCC_PLLCFGR_PLLN_8 | RCC_PLLCFGR_PLLN_6 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_3;

  //Set M=4 0b100

  RCC -> PLLCFGR |= RCC_PLLCFGR_PLLM_2;

  //Set 48MHz for VCO, -> 2*(N/Q) -> Set Q=15 -> 0b1111

  RCC -> PLLCFGR |= RCC_PLLCFGR_PLLQ_3 | RCC_PLLCFGR_PLLQ_2 | RCC_PLLCFGR_PLLQ_1 | RCC_PLLCFGR_PLLQ_0;

  //Enable PLL-Modul

  RCC -> CR |= RCC_CR_PLLON;

  //Wait for PLL is stable running

  while(RCC -> CR & RCC_CR_PLLRDY){}

  //Switch SYSCLK to PLL_P, SW -> 10

  RCC -> CFGR |= RCC_CFGR_SW_1 & ~RCC_CFGR_SW_0;

  //Wait for clock switch is ready -> SWS = 10

  while(RCC -> CFGR & RCC_CFGR_SWS_PLL){};

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
    //      SystemClock_Config();
    //                initClock();

    // instead: 29/12/2021 - 180 MHz we should have from HSE external 8 MHz clock
    // as in SEG but do we need to update timings
    //Enable HSE clock
        RCC_HSEConfig(RCC_HSE_ON);
    //Wait for clock to stabilize
       while (!RCC_WaitForHSEStartUp());

    
    // 8 channels
	    //	    ADC1_Init((uint16_t *)adc_buffer);

	    
	    // testing


    // Enable clock for ADC1
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;// as pin 4 is DAC
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // changes nothing
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	    	// adc8 is adc1_10 =pc0
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;// | GPIO_Pin_1; PC10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    ADC_CommonInitTypeDef ADC_CommonInitStructure;
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div8;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);    
    
    // Init ADC1
    ADC_InitTypeDef ADC_InitStruct;
    ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStruct.ADC_ExternalTrigConv = DISABLE;
    ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStruct.ADC_NbrOfConversion = 1;
    ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStruct.ADC_ScanConvMode = DISABLE;
    ADC_Init(ADC1, &ADC_InitStruct);
    ADC_Cmd(ADC1, ENABLE);

    //   ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_84Cycles);

    //- rec on PB2, play on PB4 - swopped with FR3, push on PB6 
    //- FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!)
    
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
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


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
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
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

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
    
  io_config2 ();

  // TIMER2 with clock settings and period=1024, prescale of 32 gives toggle of: 1 KHz exactly (so is double at 2 KHZ and this seems to work well)
  // which translates to 65 MHZ clock from APB1 - but above APB1 is 45 MHZ ???

  // 1024/4 is 8x 862Hz (toggle speed so 2x that which is fine for us but we need to lower the sample/hold cap...

  // 16/12 stay with 1024/8 for 1.5 KHz I think - check this
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 1024; // was 1024 divide by 4 should work TEST! = 256 doesn't run
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // what speed is this 18khz toggle = 36k  - how we can check - with one of our pins as out
  // 4 is orig
  // 48 is too slow...
  // 30/9/3021: changed prescaler to 16 and then 32 to get rid of bleed
  // 6/10/2021: still tiny bleed but can live with it!
 TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; // was 1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01; // was 1
  NVIC_Init(&NVIC_InitStructure);
  TIM_Cmd(TIM2, ENABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  
  // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10
  //    GPIOC->BSRRH = 0b1110100000000000;  // clear PC11 - clear pc11 and top bits -> low

  //    uint8_t firstByte, secondByte, configBits;
    
    while(1) {

      
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
  //      dacval[daccount]=4095;
      //  k=0;
      //  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //  j = DAC_GetDataOutputValue (DAC_Channel_1);
      //  daccount++;
      //  if (daccount==8) daccount=0;  
      //    delay();
      

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
