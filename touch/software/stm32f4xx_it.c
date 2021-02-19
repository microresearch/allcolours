/**
  ******************************************************************************
  * @file    stm32f4xx_it.c 
  * @author  Xavier Halgand
  * @version
  * @date
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
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

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)


/* ---------------------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles TIM2 global interrupt request.
  * @param  None
  * @retval None
  */

extern __IO uint16_t adc_buffer[8];

static uint16_t lastadcs[8];
static uint16_t frozen[8]={0};
static uint16_t frozenvals[8]={0};
static uint32_t avv[8];

void TIM2_IRQHandler(void)
{
  static uint16_t c=0;
  static uint16_t daccount=0;
  volatile uint16_t k;
  uint16_t j;
  // array to map freeze but exception is FR8 on PC4! 
  uint16_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
  uint16_t bits;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

  // read
    //  GPIOC->BSRRL = 0b0000000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
  //  GPIOC->BSRRL = 0b1110000000000000;       // write PC13/14/15  -> DAC8 which is v4 top right, 7 is v3 top left, 6 is v2 lower left, 5 is v1 lower right
  //      GPIOC->BSRRL = 0b1000000000000000;      // now we want to test the VCAs-> lower bits so 1 is lower right
  //k=4095; // peak 6.6v      
  //DAC_SetChannel1Data(DAC_Align_12b_R, dacval[daccount]); // 1000/4096 * 3V3 == 0V8
  //      k=4095;
  // but Voltages are mixed up as ADC0 is not there
  //  daccount=0;
  ADC_SoftwareStartConv(ADC1);
  k=adc_buffer[daccount]>>4; // 16 bits to 12 
  //  k=0;
  //  if (daccount!=1) k=0;
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);
  // wait for dac to settle
  //  delay();
  GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
  GPIOC->BSRRL=(daccount)<<13; //  write DAC bits 
  daccount++;
  if (daccount==8) daccount=0;
 
}

  
  /*
    if (!(bits & (freezer[daccount]))) { // inverted and mistake on PCB but mid ones work now with higher res pullup
    frozen[daccount]=1; // toggle but for now just test
    frozenvals[daccount]=k;
  }
  
    if (frozen[daccount]) k= frozenvals[daccount];
  */

  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
