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

#include "adc.h"
/*

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
__IO uint16_t adc_buffer[5];

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

#define CS_HIGH GPIOA->BSRRL = GPIO_BSRR_BS_15;
#define CS_LOW GPIOA->BSRRH = GPIO_BSRR_BS_15;

    void SPI3_Config(void){
      
      SPI_InitTypeDef SPI_InitStructure;
      GPIO_InitTypeDef GPIO_InitStructure;
     
      //      SPI_Cmd(SPI3, DISABLE);
     
      //      GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
      //      GPIO_PinRemapConfig(GPIO_Remap_SPI3, ENABLE);  
      
      //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      //                            SCK          MISO MOSI
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      GPIO_Init(GPIOB, &GPIO_InitStructure);

      //                            MISO
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      //      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
      GPIO_Init(GPIOB, &GPIO_InitStructure);  
      
      // Configure CS pin as output floating - CS as is
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
      GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
      GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
      GPIO_Init(GPIOA, &GPIO_InitStructure);
      
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI3);
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI3);
      GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI3);

      // SPI configuration -------------------------------------------------------
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);

      //      SPI_I2S_DeInit(SPI3);
      SPI_InitStructure.SPI_Direction = SPI_Direction_Tx;///2Lines_FullDuplex; // or just Tx
      SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
      SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
      SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
      SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; // was 2Edge
      SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
      SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128; // was 8
      SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
      SPI_InitStructure.SPI_CRCPolynomial = 7;
      SPI_Init(SPI3, &SPI_InitStructure);
      SPI_Cmd(SPI3, ENABLE);

      // this is working now but DAC not responds
      
      //      SPI_SSOutputCmd(SPI3,DISABLE);
     
      //      SPI_I2S_ITConfig(SPI3,SPI_I2S_IT_RXNE,ENABLE);

      //      SPI_NSSInternalSoftwareConfig(SPI3, SPI_NSSInternalSoft_Set);
      CS_HIGH;
    }

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
  unsigned int i, adcr, j, k=0, otherk=0, flipped, prev_state, value;
    i = adcr = j = k = 0;
    // ADC - now just 5 channels - skip pin 4 as we use this for the DAC ???
    ADC1_Init((uint16_t *)adc_buffer);

    // output pins for addressing = x3 + 2 for enables is 5 total
    // say: PB8, 9, 10, 13, 14

    GPIO_InitTypeDef GPIO_InitStructure;
    
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // TEST - PC8 input from 40106 for freezing/rec/play etc. power it with 3.3v

  // led first
  GPIOA->MODER = (1 << 10); // set pin PA5 to be general purpose output

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

    
    // and maybe add timer for updating all in interrupt
    
    io_config2 ();
    //DAC_Cmd( DAC_Channel_2, ENABLE);
    DAC_Cmd( DAC_Channel_1, ENABLE);

    // set enable=say 13 and 14 pin (active LOW) and pins for 4051: PB8,9,10

    /* TODO: testing for external DAC such as MPC492X (one or two DACs) - test with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test 
    */

    SPI3_Config();
    uint8_t firstByte, secondByte, configBits;
    
    while(1) {
      // test SPI comms - what message to send a value to the DAC1!?
      // from arduino code: https://github.com/michd/Arduino-MCP492X/blob/master/MCP492X.cpp
      value=k;
      configBits = 1 << 3 | 0 << 2 | 1 << 1 | 1;
      // configBits = odd << 3 | buffered << 2 | gain << 1 | active;      
      // Compose the first byte to send to the DAC:
      // the 4 control bits, and the 4 most significant bits of the value
      firstByte = configBits << 4 | (value & 0xF00) >> 8;
      // Second byte is the lower 8 bits of the value
      secondByte = value & 0xFF;

      CS_LOW;
      while (SPI_I2S_GetFlagStatus(SPI3, SPI_FLAG_TXE) == RESET)
	{}
      SPI_I2S_SendData(SPI3, firstByte);

      while (SPI_I2S_GetFlagStatus(SPI3, SPI_FLAG_TXE) == RESET)
	{}
      SPI_I2S_SendData(SPI3, secondByte);
      
      CS_HIGH;
      
      //      delay();
      // flip-flop from PC8
      //      GPIOA->ODR ^= (1 << 5);      

      /*
      
      if (GPIOC->IDR & 0x0100){ // pin 8 
      if (flipped==0) {
	flipped=1;
	prev_state=0;
      }
	}
	else flipped=0;
	  
	if (flipped==1 && prev_state==0)
	  {
	  prev_state=1;
	  GPIOA->ODR ^= (1 << 5);
	  }
      */
      
      /// multiplex and DAC tests
            
      //    GPIOB->ODR = 0b0000000100000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    // Y1 is S1 on 4051 high which is 11 on 4051 which is pin PB8
      otherk++;
      if (otherk>32){
	otherk=0;
      k++;
      if (k>4095) k=0;
      }
      //      k=0;
      //    DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
      //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();
    //    GPIOB->ODR = 0b0000000000000000;  //13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-k); // 1000/4096 * 3V3 == 0V8
    //    j = DAC_GetDataOutputValue (DAC_Channel_1);
    //    delay();
    
      // testing transistor switch of 4066 on and off
    //    GPIOB->ODR = 0b0000000100000000;  //PB8-13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    delayy();
    //    GPIOB->ODR = 0b0000000000000000;  //PB8-13? - for Y0 which is on pin 13 (4051): first output on TL074 on prototype!
    //    delayy();
      
      
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
