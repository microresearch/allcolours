#include "stm32f10x.h"

void delay(unsigned long delay)
{
  int x=0;
  while(delay) {
    delay--;
 asm("");
  }
}


int main(void)
{
  uint32_t shift_register=0xff;
  uint32_t bit;

  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBase_InitStructure;
  TIM_OCInitTypeDef TIM_OC_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure;
  ADC_InitTypeDef ADC_InitStructure;
  DMA_InitTypeDef DMA_InitStructure;
  uint16_t ADCBuffer[] = {0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA };
  SystemInit();

  int x=0;

  
  /////////////////////// keep map of I/O for schematic:::
  
  // 4x analogue inputs -   DAC=PA0-PA7, PB0, PB1 (pref using DMA?)

  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCBuffer;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel1, &DMA_InitStructure);
 
  DMA_Cmd(DMA1_Channel1, ENABLE);
 
  RCC_ADCCLKConfig(RCC_PCLK2_Div6);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO | RCC_APB2Periph_ADC1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA1
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA2

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA3

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); // in PA4

  
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; // in worm was disable
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Left; // in worm is left
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  //  ADC_InitStructure.ADC_NbrOfChannel = 4; // unused in worm
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_Init(ADC1, &ADC_InitStructure);
 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 2, ADC_SampleTime_1Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 3, ADC_SampleTime_1Cycles5); 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 4, ADC_SampleTime_1Cycles5);

  ADC_Cmd(ADC1, ENABLE);
  ADC_DMACmd(ADC1, ENABLE);
 
  ADC_ResetCalibration(ADC1);
  while(ADC_GetResetCalibrationStatus(ADC1));
  ADC_StartCalibration(ADC1);
  while(ADC_GetCalibrationStatus(ADC1));
 
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);
  
  
  // two PWM - fast (speed range- 2MHz->x) and slow (speed range???) on 2 pins
  // example for A0
    
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 16; // fastest gives 12 MHz our max for filter is 4 Mhz
  TIM_TimeBase_InitStructure.TIM_Prescaler = 1;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
 
  TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OC_InitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
  TIM_OC_InitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
  TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OC_InitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC_InitStructure.TIM_Pulse = 4; // pulse size
  TIM_OC1Init(TIM2, &TIM_OC_InitStructure); // T2C1E is pin A0!
 
  TIM_Cmd(TIM2, ENABLE);
  
  
  // 2 pin interrupts (falling edge)
  // test on pin 0 - port B - check where EXTI lines go in manual
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
 
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // changed to falling->
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
 
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_Init(&NVIC_InitStructure);

  // timer interrupts x2 fastest and slow

  /*  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
 
  TIM_TimeBase_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBase_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBase_InitStructure.TIM_Period = 38;// peaks at 32/0 prescale with 730 KHz
  TIM_TimeBase_InitStructure.TIM_Prescaler = 0;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
 
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
 
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_Init(&NVIC_InitStructure);
 
  TIM_Cmd(TIM2, ENABLE);
  */  
  


  // Configure pin as output push-pull (led)
  //  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

    while(1)
    {
      // test with a 32 bit shift register structure
      //bit= ((shift_register >> 31) ^ (shift_register >> 29) ^ (shift_register >> 25) ^ (shift_register >> 24)) & 1u; // 32 is 31, 29, 25, 24
      //      shift_register=shift_register<<1; // we are shifting left << so bit 31 is out last one
      //      shift_register+=bit;         
      //      if (bit==1)      GPIOC->ODR = GPIO_Pin_13; // pin 13 on C - this one gives us 3.3 MHz with simple toggle -O3 compile
      //      else      GPIOC->ODR = 0;
      //          GPIOC->ODR ^= GPIO_Pin_13;
      //      TIM_TimeBase_InitStructure.TIM_Period = 2200+x; // fastest gives 12 MHz our max for filter is 4 Mhz - is this best way do this?
      //      TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
  TIM_TimeBase_InitStructure.TIM_Period = ADCBuffer[0]; // fastest gives 12 MHz our max for filter is 4 Mhz - is this best way do this?
  TIM_TimeBaseInit(TIM2, &TIM_TimeBase_InitStructure);
      //      x++;
      //      if (x>10000) x=0;
	  //            delay(5000000);
    }
}