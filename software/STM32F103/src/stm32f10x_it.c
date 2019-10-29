/**
  ******************************************************************************
  * @file    EXTI/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

extern __IO uint16_t ADCBuffer[];

uint32_t speedh, speedl, counterh=0, counterl=0;
uint16_t model, modeh;
uint8_t modelpwm, modehpwm, modelsr, modehsr;

/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup EXTI_Example
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
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
  * @brief  This function handles PendSV_Handler exception.
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
void SysTick_Handler(void)
{
}


/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

uint32_t shift_registerh=0xff; // 32 bit SR but we can change length just using output bit
uint32_t bith;
uint32_t shift_registerl=0xff; // 32 bit SR but we can change length just using output bit
uint32_t bitl;
uint8_t SRlengthh, SRlengthhl;

void TIM2_IRQHandler(void){ // handle LF and HF SR for selected modes - speed of this should change!
  // but as is for both LF an HF periods how do we handle this
  // run as fast as possible and use a counter for each period
  
  uint32_t bitxh, bitxl;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    // test simple SR mode here for output pulses on LF side-WORKING

    //->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)

    bitl = shift_registerl>>31; // bit which would be shifted out
    shift_registerl=shift_registerl<<1; // we are shifting left << so bit 31 is out last one
    //    if PB5 is low (inverted) then bitxh=bith  | PB6=inverted
    // but do we need to access PB5 through interrupt maybe? - but this seems to work
    
    if( !(GPIOB->IDR & 0x0020)) shift_registerl+=bitl | !(GPIOB->IDR & 0x0040);
    else shift_registerl+= !(GPIOB->IDR & 0x0040);
    // shift register bits output - inverted also on PB13 and 14;
    if (shift_registerl & 1u) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
    else GPIOB->BSRR = 0b0010000000000000;  // clear PB13 else write one
      // not sure what spacing we will use? say here bit 24 of this. spacing also depens on length  
    if (shift_registerl & (1<<24)) GPIOB->BRR = 0b0100000000000000;  // clear PB13 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOB->BSRR = 0b0100000000000000;  // clear PB13 else write one // clear PB14 else write one

    // test simple SR mode here for output pulses on HF side
    // clock pin interrupt in->PB7=EXTI7X, pulse in->PB10//can be interrupt tooX, 2 pulse out=inverted=PC13,14

    //->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)

    bith = shift_registerh>>31; // bit which would be shifted out
    shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    //    if PB5 is low (inverted) then bitxh=bith  | PB6=inverted
    // but do we need to access PB5 through interrupt maybe? - but this seems to work
    
    if( !(GPIOB->IDR & 0x0080)) shift_registerh+=bith | !(GPIOB->IDR & 0x0400); // PB7 and PB10
    else shift_registerh+= !(GPIOB->IDR & 0x0400);
    // shift register bits output - inverted also on PC13 and 14;
    if (shift_registerh & 1u) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
    else GPIOC->BSRR = 0b0010000000000000;  // clear PC13 else write one
      // not sure what spacing we will use? say here bit 24 of this. spacing also depens on length  
    if (shift_registerh & (1<<24)) GPIOC->BRR = 0b0100000000000000;  // clear PC13 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOC->BSRR = 0b0100000000000000;  // clear PC13 else write one // clear PC14 else write one

    // test PWM from SR bits out -> but we want to use speed for speed of this interrupt so we can't use as offset here...
    // say 8 bits - what is spacing again?
    uint8_t pwmbitsh=shift_registerh & 0xff; // just lowest 8 bits
    uint16_t speedhh=pwmbitsh+512;//period
    TIM1->ARR =speedhh;
    TIM1->CCR1 = speedhh/2; // pulse  

}

void TIM4_IRQHandler(void){ // select modes
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    // read modes - do we need smoothing here?
    // mode should be inverted maybe?
    
    model=ADCBuffer[1];
    modeh=ADCBuffer[0];

    modelpwm=model>>14; // 2 bits remaining
    modehpwm=modeh>>14; // 2 bits remaining

    modelsr=(model>>10)%16; // 6 bits=64 and then 0-15 repeats
    modehsr=(modeh>>10)%16; // 6 bits=64 and then 0-15 repeats

    // read speeds
    speedh=(ADCBuffer[2]>>4)+256;
    speedl=(ADCBuffer[3]>>2)+256;

    // test changing counter for LF and HF IRQ
    
    // and if mode is correct then deal with PWM here
    /*
    if (modelpwm==0) {
      TIM3->ARR = speedl;//period
      TIM3->CCR1 = speedl/2; // pulse  
    }

    if (modehpwm==0) {
      TIM1->ARR = speedh;//period
      TIM1->CCR1 = speedh/2; // pulse  
    }
    */
}


 //void EXTI0_IRQHandler(void){
void EXTI9_5_IRQHandler(void){ // both working now
  //  EXTI_ClearITPendingBit(EXTI_Line5);

  // to distinguish WORKING!
  
  uint32_t pending = EXTI->PR; 
  if(pending & (1 << 5)) { // LF on B
    //  GPIOB->ODR ^= GPIO_Pin_13;
    //  GPIOB->ODR ^= GPIO_Pin_14;


  EXTI->PR = 1 << 5; // clear pending flag, otherwise we'd get endless interrupts -!!!!!!!!!!!!!!!!!!!!!!!!!
        // handle pin 5 here
    }
    if(pending & (1 << 7)) { // HF on C
      //  GPIOC->ODR ^= GPIO_Pin_13;
      //  GPIOC->ODR ^= GPIO_Pin_14;
  EXTI->PR = 1 << 7;
        // handle pin 7 here
    }
  
}

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
