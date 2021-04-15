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

static uint16_t recordings[8][7000]; // top bit signifies frozen and then lower 15 are the length/counter max 32766
static uint16_t rec_cnt[8]={0};
static uint16_t play_cnt[8]={0};
static uint16_t tgr_cnt[8]={0};
static uint16_t rec=0, play=0;

/* for record:

8 values each 16 bits (well 12 bits plus one bit for freeze) = 16 bytes per step

- for say 120K we have 7500 steps - so at 100Hz this is 75 seconds, at 1KHz 7.5 seconds

[but now is 1 KHz divided by 8 - changed to faster update (divided 1024 by 4) in main.c and test]

- rec places into record mode, at limit we overwrite.
- play stops record mode and plays back, we can play over or record over
- mode (was push) sets mode for overwrites etc: what else?

 */

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint16_t c=0;
    static uint16_t daccount=0;
  volatile uint16_t k;
  uint16_t j;
  // array to map freeze but exception is FR8 on PC4! 
  uint16_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
  uint16_t bits;
  static uint16_t values[8];
    static uint16_t frozen[8]={0};
    static uint16_t laststate[8]={0}, state[8]={0}, laststaterec=0, laststateplay=0, lastrec=0, staterec=0, stateplay=0;
    static uint16_t count=0;
    uint16_t newstate[8], newstaterec, newstateplay;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	// handle buttons
	
 
  // GPIOB 2 is lower rightPLAY, 6 is topMODE, 10 is leftREC
  // with adc_buffer[4] as speed in certain modes... = lower voltage one!
	/*
	
    if (count%(40)==0) { //for xxx HZ?

      if (!(GPIOB->IDR & (1<<10))) newstaterec=1; // seems to work for test case if is slow enough here...
      else newstaterec=0;
      
      if (laststaterec==0 && newstaterec==1) rec^=1; // build in delay
      laststaterec=newstaterec;	
 

    if (!(GPIOB->IDR & (1<<2))) newstateplay=1; // seems to work for test case
    else newstateplay=0;
    
    if (laststateplay==0 && newstateplay==1) play^=1; 
    laststateplay=newstateplay;

    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;
    
  if (rec==1){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      rec_cnt[0]=0;
      lastrec=1;
    }
    recordings[daccount][rec_cnt[0]]=values[daccount];
    if (daccount==7) { // last one
      rec_cnt[0]++; // for now just use this one and later implement freeze which will change this
    if (rec_cnt[0]>7000) rec_cnt[0]=0;
    }


  }
  else lastrec=0;
  }*/

	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead
      if (!(GPIOC->IDR & (freezer[7]))) newstate[7]=1; 
      else newstate[7]=0;

	if (laststate[7]!=newstate[7]) tgr_cnt[7]=0;

    	if (tgr_cnt[7]>40){
	  if (newstate[7]!=state[7]){
	    state[7]=newstate[7];
	    if (state[7]==1) frozen[7]^=1;
	  }
	  }
	laststate[7]=newstate[7];	

	tgr_cnt[7]++;
	} // daccount==7
  else
    {
      if (!(GPIOB->IDR & (freezer[daccount]))) newstate[daccount]=1; 
      else newstate[daccount]=0;

	if (laststate[daccount]!=newstate[daccount]) tgr_cnt[daccount]=0;

    	if (tgr_cnt[daccount]>40){
	  if (newstate[daccount]!=state[daccount]){
	    state[daccount]=newstate[daccount];
	    if (state[daccount]==1) frozen[daccount]^=1;
	  }
	  }
	
	laststate[daccount]=newstate[daccount];	
	tgr_cnt[daccount]++;
	  }	  

	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0 && play==0){
    ADC_SoftwareStartConv(ADC1);
  values[daccount]=adc_buffer[daccount]>>4; // 16 bits to 12
  }

  if (play){
    values[daccount]=recordings[daccount][play_cnt[daccount]];
    if ((count%40)==0){
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[0]) play_cnt[daccount]=0;
    }
  }
  
  //  values[daccount]=4095; // 16 bits to 12 
  GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
  DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);
  GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

  daccount++;
  if (daccount==8) {
    daccount=0;
    count++;
  }  
  	
  /* /////////////////////////////

  // test code only for toggling: this works so implement for all!

	if (!(GPIOB->IDR & (1<<10))) newstaterec=1; 
	else newstaterec=0;

	if (laststaterec!=newstaterec) tgr_cnt[0]=0;

    	if (tgr_cnt[0]>40){
	  if (newstaterec!=staterec){
	    staterec=newstaterec;
	    if (staterec==1) rec^=1;
	  }
	}
	
	laststaterec=newstaterec;	
	tgr_cnt[0]++;

///////////////////////////////////////////////////////////////////////  
  if (rec) k=4095; // 2 6 and 10
      else k=0;
  
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);
  GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
  GPIOC->BSRRL=(0)<<13; //  write DAC bits 
  */
    }  
}
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
