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

uint32_t speedh, speedl, counterh=0, speedhh, speedll, counterl=0, hfpulsecount, lfpulsecount;
uint16_t model, modeh;
uint8_t modelpwm, modehpwm, modelsr, modehsr, hcount=0;

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

void delay(unsigned long delay)
{
  int x=0;
  while(delay) {
    delay--;
 asm("");
  }
}


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
uint32_t bitl, probh, probl;
uint8_t SRlengthh=31, SRlengthl=31, hstack[4]; // length minus 1;

uint32_t looker[32]={2147483648U, 3221225472U, 3758096384U, 4026531840U, 4160749568U, 4227858432U, 4261412864U, 4278190080U, 4286578688U, 4290772992U, 4292870144U, 4293918720U, 4294443008U, 4294705152U, 4294836224U, 4294901760U, 4294934528U, 4294950912U, 4294959104U, 4294963200U, 4294965248U, 4294966272U, 4294966784U, 4294967040U, 4294967168U, 4294967232U, 4294967264U, 4294967280U, 4294967288U, 4294967292U, 4294967294U, 4294967295U}; // we look up length in this from 0-31

// array for taps
// eg. 32-bit Galois LFSR with taps at 32, 30, 26, 25. Sequence length is 4294967295. 0 is a lock-up state.  -- minus one here - 31, 29, 25, 24
// bith= ((shift_registerh >> 31) ^ (shift_registerh >> 29) ^ (shift_registerh >> 25) ^ (shift_registerh >> 24)) & 1u; // 32 is 31, 29, 25, 24

// from: http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
// and reworked for length in test.c

// note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

static uint8_t lfsr_taps[32][4] = {
        {30, 30, 30, 30},
        {29, 29, 29, 29},
        {28, 28, 28, 28},
        {31, 30, 27, 27},
        {31, 30, 29, 28},
        {31, 30, 28, 27},
        {31, 30, 29, 28},
        {31, 29, 28, 27},
        {31, 30, 28, 27},
        {31, 30, 28, 27},
        {31, 30, 29, 27},
        {31, 30, 27, 25},
        {31, 30, 28, 27},
        {31, 30, 28, 26},
        {31, 30, 29, 27},
        {31, 29, 28, 26},
        {31, 30, 29, 28},
        {31, 30, 29, 26},
        {31, 30, 29, 26},
        {31, 30, 27, 25},
        {31, 30, 29, 26},
        {31, 28, 27, 26},
        {31, 30, 28, 26},
        {31, 30, 28, 27},
        {31, 30, 29, 28},
        {31, 30, 29, 25},
        {31, 30, 29, 26},
        {31, 30, 27, 25},
        {31, 30, 29, 27},
        {31, 30, 27, 25},
        {31, 30, 29, 28},
        {31, 29, 25, 24},
};

static uint8_t lfsr_taps_mirrored[32][4] = { // TO TEST! seems to work so far!
        {30, 31, 31, 31},
        {29, 31, 31, 31},
        {28, 31, 31, 31},
        {31, 28, 31, 31},
        {31, 27, 28, 29},
        {31, 26, 28, 29},
        {31, 25, 26, 27},
        {31, 25, 26, 27},
        {31, 23, 25, 26},
        {31, 22, 24, 25},
        {31, 21, 22, 24},
        {31, 20, 23, 25},
        {31, 19, 21, 22},
        {31, 18, 20, 22},
        {31, 17, 18, 20},
        {31, 17, 18, 20},
        {31, 15, 16, 17},
        {31, 14, 15, 18},
        {31, 13, 14, 17},
        {31, 12, 15, 17},
        {31, 11, 12, 15},
        {31, 12, 13, 14},
        {31, 9, 11, 13},
        {31, 8, 10, 11},
        {31, 7, 8, 9},
        {31, 6, 7, 11},
        {31, 5, 6, 9},
        {31, 4, 7, 9},
        {31, 3, 4, 6},
        {31, 2, 5, 7},
        {31, 1, 2, 3},
        {31, 1, 5, 6},
};



void TIM2_IRQHandler(void){ // handle LF and HF SR for selected modes - speed of this should change!
  // but as is for both LF an HF periods how do we handle this
  // run as fast as possible and use a counter for each period
  
  //  uint32_t bitxh, bitxl;
  uint8_t shifterl, shifterh;

  SRlengthl=31;  // TESTING!
  SRlengthh=31;  // TESTING!

  modelsr=0; // TESTING!
  modehsr=7; // TESTING!

  //length is always -1 - so 32 = 31
  shifterh=31-SRlengthh;
  shifterl=31-SRlengthl;
  
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    ////////////////////////////////////////////->>>    /// low side
    counterl++;
    if (counterl>speedll){
    counterl=0;
    
    //    GPIOB->ODR ^= GPIO_Pin_13;

    //        if( !(GPIOB->IDR & 0x0040)) GPIOB->ODR ^= GPIO_Pin_13;
	
    switch(modelsr){ // use mirrored taps also!

      // 	GPIOB->IDR & 0x0020 // GPIOB->IDR & 0x0040 = PB5 /toggle and PB6 /input bit

    case 0:
	//->>>>>>>>>>>>>> 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)
      
	bitl = shift_registerl>>31; // bit which would be shifted out - always 31 as at the end
	shift_registerl=shift_registerl<<1; // we are shifting left << so bit 31 is out last one

	if( !(GPIOB->IDR & 0x0020)) shift_registerl+= ((bitl | !(GPIOB->IDR & 0x0040))<<shifterl); // PB5 and PB6
	else shift_registerl+= (!(GPIOB->IDR & 0x0040))<<shifterl;
      // shift register bits output - inverted also on PB13 and 14;
	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  // clear PB13 else write one
	// not sure what spacing we will use? say here bit 16 (/2) of this. spacing also depenss on length  
	if (shift_registerl & (1<<(31-(SRlengthl/2)))) GPIOB->BRR = 0b0100000000000000;  // clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOB->BSRR = 0b0100000000000000;  // clear PB14 else write one // clear PB14 else write one
	break;

	//       case 9: // 9- noise only with varying taps depending on length - *for LF we can do mirroring!*

	
    // /END of LF SR side/..................................................................................................................    
	    }
    }
    ////////////////////////////////////////////->>>    /// high side
    
    counterh++;
        if (counterh>speedhh){
      counterh=0;

      // test raw speed of this - pin toggles at 160 KHz so double that
      //      GPIOC->ODR ^= GPIO_Pin_13;
      
      switch(modehsr){

	// TODO: before we fill out all modes, deal with length and spacings - SRlengthh should not be <4
	
      case 0:
	//->>>>>>>>>>>>>> 0- pulse (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	bith = shift_registerh>>31; // bit which would be shifted out - always 31 as at the end
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    
	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= ((bith | !(GPIOB->IDR & 0x0400))<<shifterh); // PB7 and PB10
	else shift_registerh+= (!(GPIOB->IDR & 0x0400))<<shifterh;

      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there - but this changes with length
    if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
    else GPIOC->BSRR = 0b0010000000000000;  
    if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOC->BSRR = 0b0100000000000000;  
    break;

      case 1:
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bith = shift_registerh>>31; // bit which would be shifted out
      shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    //    if PB5 is low (inverted) then bitxh=bith  | PB6=inverted
    // but do we need to access PB5 through interrupt maybe? - but this seems to work
    
	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= ((bith ^ !(GPIOB->IDR & 0x0400))<<shifterh); // PB7 and PB10
	else shift_registerh+= (!(GPIOB->IDR & 0x0400))<<shifterh;

      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there
    if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
    else GPIOC->BSRR = 0b0010000000000000; 
    if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOC->BSRR = 0b0100000000000000; 
    break;
    
      case 2:
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR (how we select these?)
	// we could select these with a counter or ...
	if (hcount>SRlengthh) hcount=0;
	hcount++;
	bith = shift_registerh>>31; // bit which would be shifted out
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	shift_registerh+=(bith | !(GPIOB->IDR & 0x0400))<<shifterh; // PB10
	// if we have pulse and hcount then flip that bit inside SR... rest all the same...
	if( !(GPIOB->IDR & 0x0080)) shift_registerh ^= (1<<hcount);

      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;
    
      case 3:
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (no extra input bit)
	bith = shift_registerh>>31; // bit which would be shifted out
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += (!bith)<<shifterh;
	else shift_registerh += bith<<shifterh;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 4:
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in (how long do we keep these as selected and how do we select bits)
	// say select bits again with pulse and queue 
	if (hcount>SRlengthh) hcount=0;
	hcount++;
	if( !(GPIOB->IDR & 0x0080)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+shifterh; // bump it on to the hstack
	}	  

	bith= ((shift_registerh >> hstack[0]) ^ (shift_registerh >> hstack[1]) ^ (shift_registerh >> hstack[2]) ^ (shift_registerh >> hstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	//	shift_registerh+=bith; // alone bith can go to silence         
	shift_registerh+=(bith | !(GPIOB->IDR & 0x0400))<<shifterh; // PB10

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 5:
#	//->>>>>>>>>>>>>> 5- wiard1: pulse selects new data or loop old back into SR
	bith = shift_registerh>>31; // bit which would be shifted out
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += 	(!(GPIOB->IDR & 0x0400))<<shifterh; // PB10
	else shift_registerh += bith<<shifterh;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 6:
	//->>>>>>>>>>>>>> 6- wiard2: pulse selects new data or inverted loop old back into SR
	bith = shift_registerh>>31; // bit which would be shifted out
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += 	(!(GPIOB->IDR & 0x0400))<<shifterh; // PB10
	else shift_registerh += (!bith)<<shifterh;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 7:
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed
	// so to test we need to run first SR - we ignore its length for now
	// but we need x bits of probability switches and x bits
	// test on LAP! somehow...
	// **** or we move this to pulsed mode and cv selects number of bits to 1!
	bith = shift_registerh>>31; // bit which would be shifted out
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one

	if (hcount>8) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) probh^=(1<<(31-hcount));
	hcount++;
	if (((probh | shift_registerl) & looker[7] ) == looker[7]) shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter
	//	shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter - testing simple swopover
	// do we need to mask lower bits?
	else shift_registerh += bith<<shifterh;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 8: // 8- the pulses one or we double up all modes to do the pulses thing!?!>AS mode 0 CGS here
	//	->>>>>>>>>>>>>> 0- pulse (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	bith = shift_registerh>>31; // bit which would be shifted out - always 31 as at the end
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    
	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= ((bith | !(GPIOB->IDR & 0x0400))<<shifterh); // PB7 and PB10
	else shift_registerh+= (!(GPIOB->IDR & 0x0400))<<shifterh;

	// todo as pulses but what length?
	if (bith) {
	  GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  delay(64); // 10uS
	  GPIOC->BSRR = 0b0010000000000000;  
	}
	  
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) {
	  GPIOC->BRR = 0b0100000000000000;  
	  delay(64); // 10uS
	  GPIOC->BSRR = 0b0100000000000000;  
	}
	break;


      case 9: // 9- noise only with varying taps depending on length (we could OR in PB10 though) - for LF we can do mirroring!
	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	//	shift_registerh+= (bith <<shifterh); // PB7 and PB10
	shift_registerh+= ((bith | !(GPIOB->IDR & 0x0400))<<shifterh); // PB7 and PB10
	//	GPIOC->ODR=shift_registerh;  // testing this, also is a close tap-> and no works with varying lengths

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & (1<<(31-(SRlengthh/2)))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;  
	break;
    // /END of HF SR side/..................................................................................................................    
      }

      // place in each case so then we don't need an IF for this!
      //      2- pwm follows DAC from SR (not same on LF as DAC bits ?what this means?>) -> speed for DAC style updates is from speed cv
      
    // test PWM from SR bits out -> but no speed offset is possible
    // say 8 bits - what is spacing again?

      //      if (modehpwm==2) {
    //    uint16_t pwmbitsh=shift_registerh>>24; //  but could be more spaced out - **should be /is now upper bits as we work on length with these TO TEST!
    //    uint16_t sph=pwmbitsh+512;//period
    //    TIM1->ARR =sph;
    //    TIM1->CCR1 = sph/2; // pulse  
     
          }
}

uint32_t lastspeedhh, lastspeedll;

void TIM4_IRQHandler(void){ // select modes, speed and if necessary handle PWM depending on mode 1KHz
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    // read modes - do we need smoothing here?
    // mode should be inverted maybe? but we can just treat them as inverted
    
    model=ADCBuffer[1];
    modeh=ADCBuffer[0];

    modelpwm=model>>14; // 2 bits remaining
    modehpwm=modeh>>14; // 2 bits remaining

    //    modelsr=(model>>10)%16; // 6 bits=64 and then 0-15 repeats
    //    modehsr=(modeh>>10)%16; // 6 bits=64 and then 0-15 repeats

    // read speeds
    speedh=(ADCBuffer[2]>>4)+512; // adjust these base settings
    speedhh=ADCBuffer[2]>>6;     // test changing counter for LF and HF IRQ 
    speedhh=((speedhh+lastspeedhh)/2); //smoothing necessary for higher speeds
    lastspeedhh=speedhh;
    
    speedl=(ADCBuffer[3]>>2)+256;
    speedll=ADCBuffer[3]>>6;     // test changing counter for LF and HF IRQ 
    speedll=((speedll+lastspeedll)/2); //smoothing necessary for higher speeds
    lastspeedll=speedll;
    
    // and if mode is correct then deal with PWM here
    // TESTING
      TIM1->ARR = speedh;//period
      TIM1->CCR1 = speedh/2; // pulse  

    
    // 0- pwm follows speed cv
    
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

    // testing pulse count to PWM mode - but pulsecount is wrong way round so...FIXED

    // 1- pwms follow clock pulse in for each - how we do this? speed CV as divider/multiplier 
    
/* 
uint32_t stopped=hfpulsecount;
if (stopped>32) stopped=32;
uint32_t frompulse=(((ADCBuffer[2]>>8)+1)*(32-stopped))+256; // good if was dividing and multiplying maybe with lookup table

hfpulsecount=0;
TIM1->ARR = frompulse;//period
TIM1->CCR1 = frompulse/2; // pulse  
*/
}


 //void EXTI0_IRQHandler(void){
void EXTI9_5_IRQHandler(void){ // both working now - LF and HF pulse in on falling edges...
  // to distinguish WORKING!

  // in each mode case we also do PWM:
  /*
      //      if (modehpwm==2) {
2/clock- pwm follows DAC from SR (not same on LF as DAC bits ?what
this means?>)- ... or speed for DAC updates is from clock pulse in
depending on other mode, thus speed is same speed as DAC/shiftreg
speed!  -> these depend on SR mode -> speed CV as offset for PWM-> in
pulse mode only
  */
  
  
  uint32_t pending = EXTI->PR;
  // --------------------LF
  if(pending & (1 << 5)) { // LF on 5 out on B
    EXTI->PR = 1 << 5; // clear pending flag, otherwise we'd get endless interrupts -!!!!!!!!!!!!!!!!!!!!!!!!!        // handle pin 5 here
    lfpulsecount++;
    //  GPIOB->ODR ^= GPIO_Pin_13;
    //  GPIOB->ODR ^= GPIO_Pin_14;
    }

  // --------------------HF
  
  if(pending & (1 << 7)) { // HF on 7/out on C
    EXTI->PR = 1 << 7;        // handle pin 7 here
    hfpulsecount++;
    //  GPIOC->ODR ^= GPIO_Pin_13;
    //  GPIOC->ODR ^= GPIO_Pin_14;

      /* 

// ---> PULSE MODES from 10+

options:L CGS, TM, wiard1/2, LFSR - lfsr would be nice on pulses

10- entry into SR from CV (as threshold for bit or as ADC?) - TM no input bit
11- CV selects length of SR which will stay with us - bit in ORed with loop bit .. or LFSR
12- CV threshold determines if input bit ORed last bit CGS
13- CV threshold determines if input bit XORed last bit CGS
14- use CV as speed divider... where we don't use CV otherwise -> input bit ORed with loop bit...
15- as above with xor rungler: XOR out with input bit

note also flipflop as clock divider

  */

    switch(modehsr){
      
    case 10:
      // 10- entry into SR from CV (as threshold for bit or as ADC?)
      
      break;
    }
  }
  
}

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
