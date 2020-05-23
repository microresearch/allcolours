/*

- I/O map from new schematic:

  - LF: PWM out-tim3c1->PB4X, clock pin interrupt in->PB5-EXTI5X, pulse in->PB6, 2X pulse out=inverted=PB13,14
  - HF: PWM out-tim1c1->PA8X, clock pin interrupt in->PB7=EXTI7X, pulse in->PB10//can be interrupt tooX, 2 pulse out=inverted=PC13,14

  + 4xcv adc - modeh CV, model cv, speedl cv, speedh cv = ADC0(modeh),1(model),2(speedh),3(speedl)=PA0,1,2,3 X

  + LF timer loop/interrupt (which updates all CVs) =timer4
  + HF timer loop =timer2

////////////////////////////////DONE////////////////////////////////////////

- test basic PWMs into filter/scope - to add LF PWM/timer 3 - DONE

- test clock interrupts ins, pulse in and outs DONE
- test each ADC, pot/cv where necessary 

- timer loops and all modes... timer action is in stm32f10x_it.c 

- one slower timer for update ADC -> modes and speeds, update PWM depending on mode
- one faster timer for both LF and HF shift registers
- interrupts for lf an hf shift reg and updates depending on mode

- nothing in main loop

*/

#include "stm32f10x.h"

__IO uint16_t ADCBuffer[] = {0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA };

int main(void)
{
  
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBase_InitStructure;
  TIM_OCInitTypeDef TIM_OC_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure;
  ADC_InitTypeDef ADC_InitStructure;
  DMA_InitTypeDef DMA_InitStructure;
  SystemInit();

  // DMA for ADC
  
  DMA_DeInit(DMA1_Channel1);

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCBuffer;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; //was so in WORM

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel1, &DMA_InitStructure);
 
  DMA_Cmd(DMA1_Channel1, ENABLE);
  
  RCC_ADCCLKConfig(RCC_PCLK2_Div8); //was Div6 - 8 is slowest
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO | RCC_APB2Periph_ADC1, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA1
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA2

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA3

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA4

  ADC_DeInit(ADC1);
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; // in worm was disable but works now
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Left; // in peaks and in worm is left
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_NbrOfChannel = 4; // unused in worm
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_Init(ADC1, &ADC_InitStructure);

  // this was fixed so makes sense now
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_239Cycles5); 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_239Cycles5);

  ADC_Cmd(ADC1, ENABLE);
  ADC_DMACmd(ADC1, ENABLE);
 
  ADC_ResetCalibration(ADC1);
  while(ADC_GetResetCalibrationStatus(ADC1));
  ADC_StartCalibration(ADC1);
  while(ADC_GetCalibrationStatus(ADC1));
 
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);

  
  //there are 4 timers -> 2 int->2 and 3 // global interrupts test, 2 pwm->1 and 4
  
  // two PWM - fast (speed range- 2MHz->x) and slow (speed range???) on 2 pins
  // example for A0
  // converted to timer1 -> T1C1= PA8    
  // this is HF PWM on PA8 - timer 1 channel 1
  
  TIM_DeInit(TIM1);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 1; // fastest gives 12 MHz our max for filter is 4 Mhz
  TIM_TimeBase_InitStructure.TIM_Prescaler = 1; // was 0 but use 1 for overclock!
  TIM_TimeBaseInit(TIM1, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 1; // pulse size
  TIM_OC1Init(TIM1, &TIM_OC_InitStructure); // T1C1E is pin A8?
  TIM_ARRPreloadConfig(TIM1, ENABLE); // we needed this!
  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM1, ENABLE);
  TIM_CtrlPWMOutputs(TIM1, ENABLE); // we needed this for timer1 to be added
  
  // this is LF PWM on PB4 - timer 3 channel 1 -> TESTED!

  TIM_DeInit(TIM3);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  //   RCC_APB2PeriphClockCmd(PWMTIM3RCC | RCC_APB2Periph_AFIO, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // needed to be Out_PP for basic test
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  //  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; AFIO->MAPR = AFIO_MAPR_SWJ_CFG_0; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  //  GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE );
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
  //  GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
  GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); // THIS is what we needed!
  
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //0
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 32; // ???? what should we have for LF?
  TIM_TimeBase_InitStructure.TIM_Prescaler = 1; // was 0 but use 1 for overclock
  TIM_TimeBaseInit(TIM3, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 16; // pulse size
  TIM_OC1Init(TIM3, &TIM_OC_InitStructure); // T3C1 is pin PB4
  TIM_ARRPreloadConfig(TIM3, ENABLE); // we needed this!
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM3, ENABLE);
  TIM_CtrlPWMOutputs(TIM3, ENABLE); // we needed this for timer3 to be added
  
  // TIM3->CCR1=pulse size
   
  // 2 pin interrupts (falling edge as inverted)
  // test on pin 0 - port B - check where EXTI lines go in manual

  //LF:PB5-EXTI5X  HF:PB7=EXTI7X
      
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource7);
 
  EXTI_InitStructure.EXTI_Line = EXTI_Line7;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
 
  NVIC_InitStructure.NVIC_IRQChannel =   EXTI9_5_IRQn;/// EXTI5_IRQn doesn't exist
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_Init(&NVIC_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);
 
  EXTI_InitStructure.EXTI_Line = EXTI_Line5;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
    
  // timer interrupts x2 fastest and slow - TIMER2 is fast and TIMER4 is slow

  // TIMER2 tested and working - but this will be FAST!
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 78;// peaks at 32/0 prescale with 730 KHz - 20/6 is fastest we can go 50 seems fastest with full modes
  // 48 with it.c - for func_it -> crashes even past 60???
  TIM_TimeBase_InitStructure.TIM_Prescaler = 8; // with period 32 and prescaler 8 this makes for 120 KhZ
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
 
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
 
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; // was 1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; // was 1
  NVIC_Init(&NVIC_InitStructure);
  TIM_Cmd(TIM2, ENABLE);

  // TIMER 4 - > working with same results as TIM2 -> 120KHz -> we want say 1000 Hz for updates
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 256;
  TIM_TimeBase_InitStructure.TIM_Prescaler = 2; // 256 is for 1 KHz - 16 now as we smooth our ADC - is there slower ADC?
  TIM_TimeBaseInit(TIM4, &TIM_TimeBase_InitStructure);
 
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
 
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_Init(&NVIC_InitStructure);
  TIM_Cmd(TIM4, ENABLE);
 
  // Configure pins as output push-pull -
  // FOR pulse outs: LF: PB13,14 HF: PC13,14

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  // for additional pulse ins: PB6 and PB10

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

    while(1)
    {
    }
}
