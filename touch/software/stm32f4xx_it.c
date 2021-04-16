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
static uint16_t tgr_cnt[8]={0}, tgr_rec=0, tgr_play=0;
static uint16_t rec=0, play=0;

/* TODO:

- test rec/play across all 4 areas - seems to work 15/4 - need more tests
- test freeze with rec and playback for each - seems to work 15/4 - need more tests
- all modes to implement/test and then see what works

 */

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
    static uint16_t frozen[8]={0}, freezern[8]={0}, frcount[8]={0};
    static uint16_t laststate[8]={0}, state[8]={0}, target[8]={0}, laststaterec=0, laststateplay=0, lastrec=0, lastplay=0,staterec=0, stateplay=0;
    static uint16_t count=0;
    uint16_t newstate[8], newstaterec, newstateplay, tmp;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	
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
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;       freezern[0]=0;       frcount[0]=0;
      play_cnt[1]=0;       freezern[1]=0;       frcount[1]=0;
      play_cnt[2]=0;       freezern[2]=0;       frcount[2]=0;
      play_cnt[3]=0;       freezern[3]=0;       frcount[3]=0;
      play_cnt[4]=0;       freezern[4]=0;       frcount[4]=0;
      play_cnt[5]=0;       freezern[5]=0;       frcount[5]=0;
      play_cnt[6]=0;       freezern[6]=0;       frcount[6]=0;
      play_cnt[7]=0;       freezern[7]=0;       frcount[7]=0;
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry
    if ( ((recordings[daccount][play_cnt[daccount]]) & (1<<15)) && freezern[daccount]==0  ){ // top bit is toggled
      freezern[daccount]==1;
      frcount[daccount]=0;
      target[daccount]=recordings[daccount][play_cnt[daccount]] - (1<15);
    }
	
    if (freezern[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    else { // freezern!
      if (play_cnt[daccount]==0) tmp=(recordings[daccount][6999]);
      else tmp=(recordings[daccount][play_cnt[daccount]-1]);
      values[daccount]=tmp;
    }

    if ((count%40)==0){
      if (freezern[daccount]==1){
	frcount[daccount]++;
	if (frcount[daccount]==target[daccount]) {
	  freezern[daccount]=0;
	  play_cnt[daccount]++;
	  if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	}
      }
      else {
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
      }
    }
  } // if play
  else lastplay=0;
  
  ///// recordings
  
    if (count%(40)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0;       freezern[0]=0;       frcount[0]=0;
      rec_cnt[1]=0;       freezern[1]=0;       frcount[1]=0;
      rec_cnt[2]=0;       freezern[2]=0;       frcount[2]=0;
      rec_cnt[3]=0;       freezern[3]=0;       frcount[3]=0;
      rec_cnt[4]=0;       freezern[4]=0;       frcount[4]=0;
      rec_cnt[5]=0;       freezern[5]=0;       frcount[5]=0;
      rec_cnt[6]=0;       freezern[6]=0;       frcount[6]=0;
      rec_cnt[7]=0;       freezern[7]=0;       frcount[7]=0;
    }
    // TODO: implement freeze:  marked by upper bit and value is length of repeat...
    if (frozen[daccount] && freezern[daccount==0]) {
      freezern[daccount]==1;  //toggle freezern[daccount] to signal we start
      frcount[daccount]=0;
	}
    // and start counting until freeze goes to zero then write this counter to lower bits(make sure is not>max=32767 + toggle top bit
    if (freezern[daccount]){
      frcount[daccount]++;
      recordings[daccount][rec_cnt[daccount]]=frcount[daccount]+(1<<15);
      if (frozen[daccount]==0 || frcount[daccount]==32767){ // so there is a max frozen time?
	freezern[daccount]=0;
	frcount[daccount]=0;
	rec_cnt[daccount]++; // for now just use this one and later implement freeze which will change this
	if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
      }
    }
    else { // in freezern
    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    //    if (daccount==7) { // last one
      rec_cnt[daccount]++; // for now just use this one and later implement freeze which will change this
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
    //    }
    }

  } // if rec
  else lastrec=0;
  }

    ////// write to DAC

    //  values[daccount]=4095; // 16 bits to 12 
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits

    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;

      // only toggle rec and play after all dacs
      	if (!(GPIOB->IDR & (1<<10))) newstaterec=1; 
	else newstaterec=0;

	if (laststaterec!=newstaterec) tgr_rec=0;

    	if (tgr_rec>40){
	  if (newstaterec!=staterec){
	    staterec=newstaterec;
	    if (staterec==1) rec^=1;
	  }
	}
	
	laststaterec=newstaterec;	
	tgr_rec++;

	//play	
	if (!(GPIOB->IDR & (1<<2))) newstateplay=1; 
	else newstateplay=0;

	if (laststateplay!=newstateplay) tgr_play=0;

    	if (tgr_play>40){
	  if (newstateplay!=stateplay){
	    stateplay=newstateplay;
	    if (stateplay==1) play^=1;
	  }
	}
	
	laststateplay=newstateplay;	
	tgr_play++;

    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;

	
  }  

    
  
  /* /////////////////////////////

  // test code only for toggling: this works so implemented for all!

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
