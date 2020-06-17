#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"

/*

Testing on STM32F446 NUCLEO

For new touch module/own touch things: 



- read from say 12x ADC and output signals on DAC - which will be multiplexed
- so we need input ADC and eventually toggle input pins for rec/play with, output address and enable for 4051  

- first steps: ADC inputs, DAC output (should be on PA4 (DAC_OUT1) which is marked A2 on lower left of board!

// PROGRESS: now DAC seems to work...

// ADCs, output pins, input pins...

refs:  https://stackoverflow.com/questions/45718493/stm32-f446re-simple-dac-output-what-am-i-missing

https://csserver.evansville.edu/~blandfor/Engr101/NucleoBoardUserManual.pdf

 */

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/


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
       DAC_InitStructure1.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
       DAC_Init(DAC_Channel_1, &DAC_InitStructure1);
       //       DAC_StructInit(&DAC_InitStructure1);
       /* Enable DAC Channel 1 */
       DAC_Cmd(DAC_Channel_1, ENABLE);
}


//DAC_InitTypeDef dac_init_s;

int main(void)
{
    unsigned int i, adcr, j, k;
    i = adcr = j = k = 0;

    io_config2 ();
    //DAC_Cmd( DAC_Channel_2, ENABLE);
    DAC_Cmd( DAC_Channel_1, ENABLE);
    DAC_SetChannel1Data(DAC_Align_12b_R, 4095); /* 1000/4096 * 3V3 == 0V8 */

      j = DAC_GetDataOutputValue (DAC_Channel_1);

    while(1) {

    }
}

	    /*
	    int main(void)
{
  // this is for flashing onboard LED LD2 on pin PA5

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // enable the clock to GPIOD
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // enable TIM2 clock
     
    GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output
     
    NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ
     
    TIM2->PSC = 0xff; // no prescaler, timer counts up in sync with the peripheral clock
    TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
    TIM2->ARR = 0xffff; // count to 1 (autoreload value 1)
    TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
    TIM2->EGR = 1; // trigger update event to reload timer registers
      
    while (1);
}
	    */


#ifdef  USE_FULL_ASSERT
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
    {
    }
}
#endif

#if 1
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
