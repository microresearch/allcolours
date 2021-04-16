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
#include "stm32f4xx_exti.h"
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

extern __IO uint16_t adc_buffer[12];

// TEST: inpulse interrupts to attach are: CSR: PC3, NSR: PC4, RSR: PC5, LSR: PB6

void EXTI3_IRQHandler(void){ // working CSR
  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
  /*
  // flip PB4 to test interrupt on PC3 -> CSR
    flipper^=1;
  if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
   else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */
  EXTI_ClearITPendingBit(EXTI_Line3);
 }
 }

void EXTI4_IRQHandler(void){ // working NSR
  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  /*
  // flip PB4 to test interrupt on PC3 -> CSR
    flipper^=1;
  if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
   else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line5) != RESET) {
  /*
  // flip PB4 to test interrupt on PC3 -> CSR
    flipper^=1;
  if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
   else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */
  EXTI_ClearITPendingBit(EXTI_Line5);
 }
 else if (EXTI_GetITStatus(EXTI_Line6) != RESET) {

  // flip PB4 to test interrupt on PC3 -> CSR
    flipper^=1;
  if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
   else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line6);
 } 
 }




void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  
{
  static volatile uint16_t k=0,ll=0;
  uint16_t j;
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // test pulse ins   // inpulse interrupts to attach are: CSR: PC3, NSR: PC4, RSR: PC5, LSR: PB6
  // PC7/8 pulsein (RSR-7/LSR-8), PC9-MCB, to PC14-LSB of 6 bits

  // test in gives out on PB4 - always inverted...
  //  if ((GPIOB->IDR & (1<<6)))  GPIOB->BSRRH = (1)<<4;  // clear bits PB4
  //  else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  //  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  //  ADC_SoftwareStartConv(ADC1);
  //  k=(adc_buffer[1]>>4); // 16 bits to 12 bits // tested all knobs - working // test CV ins - all workings
  //    k++; // inverted // DAC works but not amp?
    //  if (k>4095) k=0;
  //    k=0;
  //  k=2500; //
  //  k=4095;

  // test the primitive ADC
  //  PC9-MSB, to PC14-LSB of 6 bits // 6 bits to 12 bits of DAC
  // !(GPIOC->IDR & 0x0020)
  //        k=(((!(GPIOC->IDR & (1<<9)))<<11) + (((!(GPIOC->IDR & (1<<10)))<<10)  + ((!(GPIOC->IDR & (1<<11)))<<9) + ((!(GPIOC->IDR & (1<<12)))<<8) + ((!(GPIOC->IDR & (1<<13)))<<7) + ((!(GPIOC->IDR & (1<<14)))<<6)));//  - 2048;// probably easier way to do this
    if (!(GPIOC->IDR & (1<<9))) k=4095; // msb
  else if (!(GPIOC->IDR & (1<<10))) k=2048; // 
  else if (!(GPIOC->IDR & (1<<11))) k=1024;// works
  else if (!(GPIOC->IDR & (1<<12))) k=512; // works
  else if (!(GPIOC->IDR & (1<<13))) k=256; // no
  else if (!(GPIOC->IDR & (1<<14))) k=128; // no
  else k=0;
  k=4095-k;
    //    if (k==(2048)) k=4095;
  
  //    k=(((GPIOC->IDR & (1<<9)))<<11) + (((GPIOC->IDR & (1<<10)))<<9) + (((GPIOC->IDR & (1<<11)))<<7) + (((GPIOC->IDR & (1<<12)))<<5) + (((GPIOC->IDR & (1<<13)))<<3) + (((GPIOC->IDR & (1<<14)))<<1) ;//  - 2048;// probably easier way to do this
  // check each one
  //  k=((!(GPIOC->IDR & (1<<14)))<<11); //14 haas issues
  //  k=(1<<11); //puts us in middle
  //      k=4095; // with
	//  k=4000; // with R35 as 150k and R34 as 66.5k we have 4095 as -4.96 and 0 as 5.6k // 180k puts us opposite (-5.6) so we need like 160k
  // we leave buffer on DAC or these values change
  //  k=rand()%4095;
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);

  //  if(ll)      GPIOB->BSRRH = (1)<<2;  // clear bits PB2
  //   else   GPIOB->BSRRL=(1)<<2; //  write bits 

  
}
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
