
#include "stm32f10x_it.h"

extern __IO uint16_t ADCBuffer[];

volatile uint32_t speedh, speedl, counterh=0, speedhh, speedll, counterl=0, hfpulsecount, lfpulsecount;
volatile uint32_t modelpwm, modehpwm, modelsr=0, modehsr=0, hcount=0, countbitsh=0, coutbitsl=0, bithh=0; // testing for modes

volatile uint8_t new_state[32], prev_state[32]={0}, flipped[32]={0}, probh, probl;

volatile uint32_t shift_registerh=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t SRlengthh=31, SRlengthl=31, hstack[4]; // length minus 1;
volatile uint32_t model, modeh, lengthbith=(1<<15), lengthbitl=(1<<15);



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

uint32_t looker[32]={1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647}; // now for lower bits

// array for taps
// eg. 32-bit Galois LFSR with taps at 32, 30, 26, 25. Sequence length is 4294967295. 0 is a lock-up state.  -- minus one here - 31, 29, 25, 24
// bith= ((shift_registerh >> 31) ^ (shift_registerh >> 29) ^ (shift_registerh >> 25) ^ (shift_registerh >> 24)) & 1u; // 32 is 31, 29, 25, 24

// from: http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
// and reworked for length in test.c -> not so if we revert to basic code...

// note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

static uint8_t lfsr_taps[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 2, 1},
        {5, 4, 2, 1},
        {6, 5, 4, 3},
        {7, 5, 4, 3},
        {8, 7, 5, 4},
        {9, 8, 6, 5},
        {10, 9, 8, 6},
        {11, 10, 7, 5},
        {12, 11, 9, 8},
        {13, 12, 10, 8},
        {14, 13, 12, 10},
        {15, 13, 12, 10},
        {16, 15, 14, 13},
        {17, 16, 15, 12},
        {18, 17, 16, 13},
        {19, 18, 15, 13},
        {20, 19, 18, 15},
        {21, 18, 17, 16},
        {22, 21, 19, 17},
        {23, 22, 20, 19},
        {24, 23, 22, 21},
        {25, 24, 23, 19},
        {26, 25, 24, 21},
        {27, 26, 23, 21},
        {28, 27, 26, 24},
        {29, 28, 25, 23},
        {30, 29, 28, 27},
        {31, 29, 25, 24},
  };

static uint8_t lfsr_taps_mirrored[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {3, 2, 2, 0},
        {4, 2, 1, 0},
        {5, 3, 2, 0},
        {6, 2, 1, 0},
        {7, 3, 2, 1},
        {8, 3, 2, 0},
        {9, 3, 2, 0},
        {10, 3, 1, 0},
        {11, 5, 3, 0},
        {12, 3, 2, 0},
        {13, 4, 2, 0},
        {14, 3, 1, 0},
        {15, 4, 2, 1},
        {16, 2, 1, 0},
        {17, 4, 1, 0},
        {18, 4, 1, 0},
        {19, 5, 3, 0},
        {20, 4, 1, 0},
        {21, 4, 3, 2},
        {22, 4, 2, 0},
        {23, 3, 2, 0},
        {24, 2, 1, 0},
        {25, 5, 1, 0},
        {26, 4, 1, 0},
        {27, 5, 3, 0},
        {28, 3, 1, 0},
        {29, 5, 3, 0},
        {30, 2, 1, 0},
        {31, 6, 5, 1},
	 };


void TIM2_IRQHandler(void){ // handle LF and HF SR for selected modes - speed of this should change!
  // but as is for both LF an HF periods how do we handle this
  // run as fast as possible and use a counter for each period
  uint32_t bith, bitl;
  
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    ////////////////////////////////////////////->>>    /// low side
    counterl++;
    if (counterl>speedll){
    counterl=0;
    
    //    GPIOB->ODR ^= GPIO_Pin_13;

    //        if( !(GPIOB->IDR & 0x0040)) GPIOB->ODR ^= GPIO_Pin_13;

    // new SR model =   bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out 
    // and now no shifter needed!
    
    switch(modelsr){ // use mirrored taps also!

      // 	GPIOB->IDR & 0x0020 // GPIOB->IDR & 0x0040 = PB5 /toggle and PB6 /input bit

    case 0: // tested - new model
      //->>>>>>>>>>>>>> 0- pulse (PB5) toggles loopback to OR with new input bit (PB6) /or just accept new input bit (CGS)
      // TO TEST - as can result in all 1s - re-test with new codes for SR!
      // MODDED//RETEST = tested but can go to all 1s
      
      bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out -
      //      shift_registerl=shift_registerl<<1; // we are shifting left << so bit 31 is out last one

      //      if( !(GPIOB->IDR & 0x0020)) shift_registerl+= (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
      //	else shift_registerl+= (!(GPIOB->IDR & 0x0040));

      if((GPIOB->IDR & 0x0020)) shift_registerl= (shift_registerl<<1) + (!(GPIOB->IDR & 0x0040)); // switched around for speed
      else shift_registerl = (shift_registerl<<1) + (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
      // shift register bits output - inverted also on PB13 and 14;
      	
	if (bitl) GPIOB->BRR = 0b0010000000000000;  // clear PB13 else write one
	else GPIOB->BSRR = 0b0010000000000000;  // clear PB13 else write one
	// not sure what spacing we will use? say here bit 16 (/2) of this. spacing also depenss on length  
	if (shift_registerl & lengthbitl) GPIOB->BRR = 0b0100000000000000;  // clear PB14 else write one BRR is clear, BSRR is set bit and leave alone others
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
	
      case 0:
	//->>>>>>>>>>>>>> 0- pulse (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	// TO TEST - as can result in all 1s
	// MODDED//RETEST = tested but can go to all 1s
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	//	shift_registerh=shift_registerh<<1; // we are shifting left
    
	//	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= (bith | !(GPIOB->IDR & 0x0400)); // PB7 and PB10
	//	else shift_registerh+= (!(GPIOB->IDR & 0x0400));

	if((GPIOB->IDR & 0x0080)) shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400)); // switched round
	else shift_registerh = (shift_registerh<<1) + (!(GPIOB->IDR & 0x0400));
	
      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there - but this changes with length
	
	/*    if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
    else GPIOC->BSRR = 0b0010000000000000;  
    if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOC->BSRR = 0b0100000000000000; */
          bithh^=1;
      if (bithh) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
      else GPIOC->BSRR = 0b0010000000000000; 
    break;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////TODO
      case 1: // mod - tested
	//->>>>>>>>>>>>>> 1- pulse (PB5) toggles loopback to XOR with new input bit (PB6) /or just accept new input bit (CGS)
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    //    if PB5 is low (inverted) then bitxh=bith  | PB6=inverted
    // but do we need to access PB5 through interrupt maybe? - but this seems to work
    
	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= ((bith ^ !(GPIOB->IDR & 0x0400))); // PB7 and PB10
	else shift_registerh+= (!(GPIOB->IDR & 0x0400));

      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there
    if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
    else GPIOC->BSRR = 0b0010000000000000; 
    if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
    else GPIOC->BSRR = 0b0100000000000000; 
    break;
    
      case 2: // mod - still bit odd...
	//->>>>>>>>>>>>>> 2- loopback ORed with input bit and pulses flip/leak bits INSIDE the SR (how we select these?)
	// we could select these with a counter or ...
	hcount++;
	if (hcount>SRlengthh) hcount=0;
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	shift_registerh+=(bith | !(GPIOB->IDR & 0x0400)); // PB10
	// if we have pulse and hcount then flip that bit inside SR... rest all the same...
	if( !(GPIOB->IDR & 0x0080)) shift_registerh ^= (1<<hcount);

      // shift register bits output - inverted also on PC13 and 14; // for GPIOC we could also try dump whole thing onto ODR as I think nothing else is on there
	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	//	GPIOC->BSRR = 0b0100000000000000; // this is a zero 
	
	break;
    
      case 3: // mod - tested
	//->>>>>>>>>>>>>> 3- pulse(1) inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (no extra input bit)
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += (!bith);
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 4: // mod - tested
	//->>>>>>>>>>>>>> 4- parity for loopback XOR is determined by pulsed bits in (how long do we keep these as selected and how do we select bits)
	// say select bits again with pulse and queue 
	hcount++;
	if (hcount>SRlengthh) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) {
	  hstack[3]=hstack[2];
	  hstack[2]=hstack[1];
	  hstack[1]=hstack[0];
	  hstack[0]=hcount+1; // bump it on to the hstack
	}	  

	bith= ((shift_registerh >> hstack[0]) ^ (shift_registerh >> hstack[1]) ^ (shift_registerh >> hstack[2]) ^ (shift_registerh >> hstack[3])) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh=shift_registerh<<1; // we are shifting left 
	//	shift_registerh+=bith; // alone bith can go to silence         
	shift_registerh+=(bith | !(GPIOB->IDR & 0x0400)); // PB10

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 5: // modded - tested
	//->>>>>>>>>>>>>> 5- wiard1: pulse selects new data or loop old back into SR
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += 	(!(GPIOB->IDR & 0x0400)); // PB10
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 6: // modded - tested
	//->>>>>>>>>>>>>> 6- wiard2: pulse selects new data or inverted loop old back into SR
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0080)) shift_registerh += 	(!(GPIOB->IDR & 0x0400)); // PB10
	else shift_registerh += (!bith);

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 7: //mod - tested  but  maybe check again
	//->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed
	// so to test we need to run first SR - we ignore its length for now
	// but we need x bits of probability switches and x bits
	// test on LAP! somehow...TESTED
	// !note: swop l and h when port to low!
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	
	if (hcount>7) hcount=0;
	if( !(GPIOB->IDR & 0x0080)) probh^=(1<<hcount);
	hcount++;
	// question might be if shiftregisterl is shorter than this... -> could adapt above for its length
	if (((probh | shift_registerl) & looker[7] ) == looker[7]) shift_registerh+=(shift_registerl>>SRlengthl) & 0x01; // new bits enter from shiftregleft
	//	shift_registerh+=((shift_registerl>>31)<<1); // new bits enter - testing simple swopover
	// do we need to mask lower bits?
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

      case 8: //mod - tested
	// 8- the pulses one or we double up all modes to do the pulses thing!?!>AS mode 0 CGS here
	//	->>>>>>>>>>>>>> 0- pulse (PB7) toggles loopback to OR with new input bit (PB10) /or just accept new input bit (CGS)
	// TO TEST - as can result in all 1s

	//	bith = shift_registerh>>31; // bit which would be shifted out - always 31 as at the end
		bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
    
	if( !(GPIOB->IDR & 0x0080)) shift_registerh+= ((bith | !(GPIOB->IDR & 0x0400))); // PB7 and PB10
	else shift_registerh+= (!(GPIOB->IDR & 0x0400));

	// todo as pulses but what length?
	if (bith) {
	  GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	  delay(64); // 64=10uS - short = lower voltage...
	  GPIOC->BSRR = 0b0010000000000000;  
	}
	  
	if (shift_registerh & (1<<(SRlengthh/2))) {
	  GPIOC->BRR = 0b0100000000000000;  
	  delay(64); // 64=10uS
	  GPIOC->BSRR = 0b0100000000000000;  
	  }
	//	GPIOC->BSRR = 0b0100000000000000;  
	break;

      case 9: // tested - mod so we can use PB7 to select input <OR> or not
	// 9- noise only with varying taps depending on length (we could OR in PB10 though) - for LF we can do mirroring!
	// MODDED//RETEST = tested and works fine...

	if (shift_registerh==0) shift_registerh=0xff;
	bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	//	shift_registerh+= (bith <<shifterh); // PB7 and PB10
	if( !(GPIOB->IDR & 0x0080))	shift_registerh+= (bith | !(GPIOB->IDR & 0x0400)); // PB7 and PB10
	else shift_registerh+= (bith);
	//	GPIOC->ODR=shift_registerh;  // testing this, also is a close tap-> and no works with varying lengths

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
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
  uint32_t bith, bitl;

  
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
    speedh=(ADCBuffer[2]>>4)+312; // adjust these base settings
    speedhh=ADCBuffer[2]>>6;     // test changing counter for LF and HF IRQ 
    speedhh=((speedhh+lastspeedhh)/2); //smoothing necessary for higher speeds
    lastspeedhh=speedhh;
    
    speedl=(ADCBuffer[3]>>4)+256;
    speedll=ADCBuffer[3]>>6;     // test changing counter for LF and HF IRQ 
    speedll=((speedll+lastspeedll)/2); //smoothing necessary for higher speeds
    lastspeedll=speedll;
    
    // and if mode is correct then deal with PWM here
    // TESTING
      TIM1->ARR = speedh;//period
      TIM1->CCR1 = speedh/2; // pulse  

    
    // 0- pwm follows speed cv
      modehpwm=0; // TESTY!
      modelpwm=0; // TESTY! 
    
    if (modelpwm==0) {
      TIM3->ARR = speedl;//period
      TIM3->CCR1 = speedl/2; // pulse  
    }

    if (modehpwm==0) {
      TIM1->ARR = speedh;//period
      TIM1->CCR1 = speedh/2; // pulse  
    }
   
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

  uint8_t x, numflips;
  uint8_t bith, origbith, bitl;


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

  */

    /// !!!! can also add CV as probablity for TM flipping as in electronotes style probability or buchla 266 !!!!!!!!!!!!!!!!!!!!!
    
    switch(modehsr){
    case 10: //mod - tested
      //10- entry into SR from CV (as threshold for bit or as ADC? ) - TM = no input bit // TESTED/
      // our cv is ADCBuffer[2]>>8 for 8 bits and select counting bit
      countbitsh++;
      if (countbitsh>7) countbitsh=0;
      //bith = shift_registerh>>31; // bit which would be shifted out
      bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -

      shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one

      if((ADCBuffer[2]>>(8+countbitsh))&1) shift_registerh += (!bith); // or we could & with input bit - TO TEST!
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

    case 11: ///mod - tested
      //11- CV selects length of SR which will stay with us .. -> LFSR here
      // max len is 31, min len is say 4 - so that's 5 bits
      //length is always -1 - so 32 = 31
      SRlengthh=31-(ADCBuffer[2]>>11);
      if (SRlengthh<4) SRlengthh=4;
      //      SRlengthh=8;
      lengthbith=(1<<SRlengthh/2);
      if (shift_registerh==0) shift_registerh=0xff;
      bith= ((shift_registerh >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	//	shift_registerh+= (bith <<shifterh); // PB7 and PB10
	shift_registerh+= ((bith | !(GPIOB->IDR & 0x0400))); // PB7 and PB10
	//	GPIOC->ODR=shift_registerh;  // testing this, also is a close tap-> and no works with varying lengths

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;  
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000;  
	break;
	
    case 12: ///mod - works but might need some tweakings!
      //12- CV threshold determines if input bit ORed (or could be XOR) last bit CGS -> this results in ON/OFF 
      // try others: this one works from: 	//->>>>>>>>>>>>>> 5- wiard1: pulse selects new data or loop old back into SR
      //	bith = shift_registerh>>31; // bit which would be shifted out
           bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -

	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if (ADCBuffer[2]>32768) shift_registerh += 	(!(GPIOB->IDR & 0x0400)); // PB10
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
      break;

    case 13: // mod - seems working
	//13- electronotes: CV selects which bits to set to 1 = chance of change
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	probh=ADCBuffer[2]>>8; // shift to lowest 8 bits now
	// question might be if shiftregisterl is shorter than this... -> could adapt above for its length
	if (((probh | shift_registerl) & looker[7] ) == looker[7]) shift_registerh+=(shift_registerl>>SRlengthl) & 0x01; // new bits enter from shiftregleft
	//	shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter - testing simple swopover
	// do we need to mask lower bits? no as we AND with looker[7]
	else shift_registerh += bith;

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000; 
	if (shift_registerh & (1<<(SRlengthh/2))) GPIOC->BRR = 0b0100000000000000;  // clear PC14 else write one BRR is clear, BSRR is set bit and leave alone others
	else GPIOC->BSRR = 0b0100000000000000; 
	break;

    case 14: // = mod working 
	//	14- use CV as speed divider// -> which one?  //note also flipflop as clock divider
	// from3- pulse(1)//now on pb10 instead of clock/pulse inverts the cycling bit in - this is Turing Machine - cycle bit or invert bit (no extra input bit)

	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	origbith=bith;
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	if( !(GPIOB->IDR & 0x0400)) shift_registerh += (!bith);
	else shift_registerh += bith;

	// flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
	// so we need prev state, new state and bit to flip...
	// how do we chain these?

	//	numflips=16; // say limit to 16
	numflips=(ADCBuffer[2]>>12); //or 15-(ADCBuffer[2]>>12) if we wish it to go in the opposite direction
	new_state[0]=bith;
	if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
	prev_state[0]=new_state[0];	

	for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
	}
	if (numflips>0)	bith=flipped[numflips-1];
	
	// out the bit

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;
	if (origbith) GPIOC->BRR = 0b0100000000000000;  // 	/////// this bit - original bith 
	else GPIOC->BSRR = 0b0100000000000000;
	break;
	
    case 15: // tested
	//15- as 14//speed divider with xor rungler: XOR out with input bit
	//	bith = shift_registerh>>31; // bit which would be shifted out
	bith = (shift_registerh>>SRlengthh) & 0x01; // bit which would be shifted out -
	origbith=bith;
	shift_registerh=shift_registerh<<1; // we are shifting left << so bit 31 is out last one
	//	if( !(GPIOB->IDR & 0x0400)) shift_registerh += (!bith);
	//	else shift_registerh += bith;
	shift_registerh += (bith) ^ (!(GPIOB->IDR & 0x0400));
	// flip flop: rising edge - if last was 0 and now is 1 then we trigger flip 1-0 or 0-1
	// so we need prev state, new state and bit to flip...
	// how do we chain these?

	//	numflips=16; // say limit to 16
	numflips=(ADCBuffer[2]>>12); //or 15-(ADCBuffer[2]>>12) if we wish it to go in the opposite direction
	new_state[0]=bith;
	if (prev_state[0]==0 && new_state[0]==1) flipped[0]^=1;
	prev_state[0]=new_state[0];	

	for (x=1;x<numflips;x++){ 
	new_state[x]=flipped[x-1];
	if (prev_state[x]==0 && new_state[x]==1) flipped[x]^=1;
	prev_state[x]=new_state[x];
	}
	if (numflips>0)	bith=flipped[numflips-1];
	
	// out the bit

	if (bith) GPIOC->BRR = 0b0010000000000000;  // clear PC13 else write one
	else GPIOC->BSRR = 0b0010000000000000;
	if (origbith) GPIOC->BRR = 0b0100000000000000;  // 	/////// this bit - original bith 
	else GPIOC->BSRR = 0b0100000000000000;
	break;

	//////////////////////////->>>>>>>>>>>>>>>>>	
	/// end of HF modes
    }
  }
  
}

