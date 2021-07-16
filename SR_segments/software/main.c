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
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_hal_pwr.h"
#include "misc.h"
#include "adc.h"
#include "stm32f4xx_conf.h"

/*

PROG HEADER: yellow, green, blue, purple

*** SEGMENTS 

older: fast interrupt (TIM?) for all shift registers with counters,
interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for
default/normed clockings (set by speed pot)

or just one timer for all and run at max speed with counters

- ADC input schemes - number of bits, sigma/delta, bit equality (unary - no weighting) with x bits // what else?
- 4x pin interrupts, how many timers
- working with sigma delta ADC, DAC out, digital filter simulator and list first all possible modes and ways of operating
- clock from speed/cv, clock from external pulse, clock from other
  shift register // combos of thse so could be ext pulse AND/XOR/OR
  other shift reg or clocked speed pulse etc.
- bitdsp library borrowings?
- fakes, ghosts, SR_IN_SR, overlaps
- add artificial drift and dropped bits

Sigma/delta out as pulses and as DAC (low pass?)


/////

TODO: new notes, collect all notes, modes and speed/basic tests

Questions: how we use the 5 fake pulse outs normed to pulse ins: PB10-PB15 ! 

Newest PCB (14/5/2021) with new ADC(ADC12//on pin PC3) TESTED ALL FINE

9/7/2021: ADC in and DAC tested correctly with 11vPP for 0-4095

14/7/2021 - retested allFINE: 

all ADC ins: mode, spd and len x4

  // map ADCs: note all modes are inverted

  // 0: nspd, 1: nlen, 2: nmode
  // 3: lspd, 4: llen, 5: lmode
  // 6: rspd, 7: rlen, 8: rmode
  // 9: cspd, 10: , 11: cmode

/ pulse ins: PC7 is RSRIN, PC8 is LSRIN XDONE

/ interrupt ins: LSR, RSR, CSR, NSR -DONE / PWM outX, pulse outsXDONE

CSRCLKIN moved from PC3 to PB7

///

Newest PCB: all working 19/4 but we will need to re-work ADC entry -
test now with lower cap on say ADC0 - nspeedin c30->100pf//33k, removed cap (but leave on schematic)
and increased ADC speed, changed to continuous mode and we have a high
sample rate in 100kHZ
 
16/4/2021->19/4/2021:

- what needs testing? DAC outDONE, ADCs inDONE, 

- all pulses in //(and volts knob for ADC pulsed in: PC9->PC14-REDO)DONE

- pulses outDONE

TIM1-CH1 normings WORKING - so is TIM1 normed to top clock/NSR

----> could do with organizing all a bit better with arrays

///


TESTED/WORKING: ADC all tested, DAC out tested, pulses out all tested, TIM1-CH1 norming to top clock, volts knob/primitive ADC, pulse ins, interrupt pulse ins 

/////////

// copied over from TOUCH so we need to change ADCsDONE, DAC out is the same, add timers and change interrupt timing, add external interrupts, PWMS.

TODO: list our new I/O here, check interrupts and PWM

- general scheme of things

///// OLDER

Testing on STM32F446 NUCLEO. Prog header is same as TOUCH. STM is same as touch

This was copied from TOUCH so some things will need to change: 

But we can keep DAC on PA4


fast interrupt (TIM?) for all shift registers with counters, interrupt for ADCs (TIM?), interrupt for pulsed SR, PWM for default/normed clockings (set by speed pot)

I/O:

- pulse ins: PC3-5 + PB6 clkins(interrupts), PC7/8 pulsein, PC9-MSB, to PC14-LSB of 6 bits
- ADC 0-11 see adc.c
- DAC out PA4
- TIM1-CH1 drived normed top LFSR - and we need 2 extra internal timers! 
- 11 pulse outs: PB2,3,4,10,12,13,14 = 5 fakes and 6 real out + now we have changed for schematic: PA11=pulse6, PA12=pulse4, PC15=pulse5, PB15=pulse7

apparently there are 12x 16bit and 2x 32 bit timers (TIM2, TIM5) 

 */

/// Copied 23/2/2021 from TOUCH code...

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/

/* DMA buffer for ADC  & copy */
__IO uint16_t adc_buffer[13];

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
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
       GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
       GPIO_Init(GPIOA, &GPIO_InitStructure);

       /* DAC channel 1 Configuration */
       DAC_InitTypeDef DAC_InitStructure1;
       DAC_InitStructure1.DAC_Trigger = DAC_Trigger_None;
       DAC_InitStructure1.DAC_WaveGeneration = DAC_WaveGeneration_None;
       DAC_InitStructure1.DAC_OutputBuffer = DAC_OutputBuffer_Enable; // leave as enable for impedance BUFFER???
       // enable better in this case
       DAC_Init(DAC_Channel_1, &DAC_InitStructure1);
       /* Enable DAC Channel 1 */
       DAC_Cmd(DAC_Channel_1, ENABLE);
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
  EXTI_InitTypeDef EXTI_InitStructure;

  
  unsigned int i, adcr, j, k=0, otherk=0, flipped, prev_state, value, offset;
    i = adcr = j = k = 0;

    initClock();

    // 12 channels
    ADC1_Init((uint16_t *)adc_buffer);

    GPIO_InitTypeDef GPIO_InitStructure;

    // TODO: organise ins and outs
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  // out pulses are on: PB2,3,4,10,12,13,14,15
  // PC15, PA11, PA12

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  
  //  TIM1-CH1 norming to top clock is on PA8
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  

  
  // inpulse interrupts to attach are: CSR: PC3-moved to PB7, NSR: PC4, RSR: PC5, LSR: PB6

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; // now is PB7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // PC7/8 pulsein (LSR/RSR), PC9-MCB, to PC14-LSB of 6 bits
  

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* // no longer used 
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  */
    
  io_config2();

  // TIM1 on PA8 to set up // working!
  
  TIM_DeInit(TIM1);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // 
  TIM_TimeBase_InitStructure.TIM_Prescaler = 256; // 
  TIM_TimeBaseInit(TIM1, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC1Init(TIM1, &TIM_OC_InitStructure); // T1C1E is pin A8?
  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this!
  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 

  TIM_Cmd(TIM1, ENABLE);
  TIM_CtrlPWMOutputs(TIM1, ENABLE); // we needed this for timer1 to be added

TIM_BDTRInitTypeDef TIM_BDTRInitStruct;
TIM_BDTRStructInit(&TIM_BDTRInitStruct);
TIM_BDTRConfig(TIM1, &TIM_BDTRInitStruct);
TIM_CCPreloadControl(TIM1, ENABLE);
TIM_CtrlPWMOutputs(TIM1, ENABLE);
    
  // TIMER2 with clock settings and period=1024, prescale of 32 gives toggle of: 1 KHz exactly (so is double at 2 KHZ and this seems to work well)
  // which translates to 65 MHZ clock from APB1 - but above APB1 is 45 MHZ ???
// 32 and 8 is 100 KHz but why can't we sample so fast...
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 8; // was 32768 // was 1024
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // what speed is this 18khz toggle = 36k  - how we can check - with one of our pins as out
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; // was 1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01; // was 1
  NVIC_Init(&NVIC_InitStructure);
  TIM_Cmd(TIM2, ENABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  
  // inpulse interrupts to attach are: CSR: PC3->now PB7, NSR: PC4, RSR: PC5, LSR: PB6

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource4);
  EXTI_InitStructure.EXTI_Line = EXTI_Line4; // PC4
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource5);
  EXTI_InitStructure.EXTI_Line = EXTI_Line5; // PC5
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource6);
  EXTI_InitStructure.EXTI_Line = EXTI_Line6; // PB6
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource7); // adding PB7
  EXTI_InitStructure.EXTI_Line = EXTI_Line7; // PB7
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
  
  
  
    while(1) {

  // test in gives out on PB4 - always inverted...

      // test pulse ins on... PC7 PC8?

      //      if ((GPIOC->IDR & (1<<8)))  GPIOB->BSRRH = (1)<<4;  // clear bits PB4
      //      else   GPIOB->BSRRL=(1)<<4; //  write bits   

      
      // test pulse outs one by one:
      // L1-PB2, L2-PC15, R1-PB3, R2-PA11, C1-PB4, C2-PA12

      // normed/fake pulses are: LSR-pulse8=PB10, RSR-pulse7=PB15, LSRCLK-pulse9=PB12, RSRCLK-pulse10=PB13, CSRCLCK-pulse11=PB14

       // toggle bits test
      // out pulses are on: PB2,3,4,10,12,13,14,15 // checked and all working!
      /*
      GPIOC->BSRRH = (1<<15) ;  // clear bits            
      GPIOB->BSRRH = (1)<<2 | (1<<3) | (1<<4) | (1<<10) | (1<<12)  | (1<<13)  | (1<<14) | (1<<15) ;  // clear bits
      GPIOA->BSRRH = (1)<<11 | (1<<12);// | (1<<4) | (1<<10) | (1<<12)  | (1<<13)  | (1<<14) | (1<<15) ;  // clear bits
      delay();
      GPIOC->BSRRL = (1<<15) ;  // clear bits            
      GPIOB->BSRRL = (1)<<2 | (1<<3) | (1<<4) | (1<<10) | (1<<12)  | (1<<13)  | (1<<14) | (1<<15) ;  // clear bits
      GPIOA->BSRRL = (1)<<11 | (1<<12);// | (1<<4) | (1<<10) | (1<<12)  | (1<<13)  | (1<<14) | (1<<15) ;  // clear bits
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

