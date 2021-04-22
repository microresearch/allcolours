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

#define TRG 10 // trigger - was 100 but /8 - thse for frz
#define BRK 100 // off hold was 1200 but /8

#define TRG8 15 // these for rec/play etc
#define BRK8 150

// rev log doesn't work
//const uint16_t logval[1024]  __attribute__ ((section (".flash"))) = {0, 33, 66, 98, 131, 163, 195, 226, 257, 289, 319, 350, 380, 410, 440, 470, 499, 528, 557, 586, 614, 642, 670, 698, 726, 753, 780, 807, 833, 860, 886, 912, 938, 963, 989, 1014, 1039, 1064, 1088, 1113, 1137, 1161, 1184, 1208, 1231, 1255, 1278, 1300, 1323, 1345, 1368, 1390, 1412, 1433, 1455, 1476, 1498, 1519, 1540, 1560, 1581, 1601, 1621, 1641, 1661, 1681, 1701, 1720, 1739, 1758, 1777, 1796, 1815, 1833, 1851, 1870, 1888, 1905, 1923, 1941, 1958, 1975, 1993, 2010, 2027, 2043, 2060, 2076, 2093, 2109, 2125, 2141, 2157, 2173, 2188, 2204, 2219, 2234, 2249, 2264, 2279, 2294, 2308, 2323, 2337, 2351, 2365, 2379, 2393, 2407, 2421, 2434, 2448, 2461, 2474, 2488, 2501, 2513, 2526, 2539, 2552, 2564, 2576, 2589, 2601, 2613, 2625, 2637, 2649, 2661, 2672, 2684, 2695, 2706, 2718, 2729, 2740, 2751, 2762, 2773, 2783, 2794, 2804, 2815, 2825, 2836, 2846, 2856, 2866, 2876, 2886, 2896, 2905, 2915, 2924, 2934, 2943, 2953, 2962, 2971, 2980, 2989, 2998, 3007, 3016, 3025, 3033, 3042, 3050, 3059, 3067, 3076, 3084, 3092, 3100, 3108, 3116, 3124, 3132, 3140, 3148, 3155, 3163, 3170, 3178, 3185, 3193, 3200, 3207, 3215, 3222, 3229, 3236, 3243, 3250, 3256, 3263, 3270, 3277, 3283, 3290, 3296, 3303, 3309, 3316, 3322, 3328, 3334, 3341, 3347, 3353, 3359, 3365, 3371, 3377, 3382, 3388, 3394, 3400, 3405, 3411, 3416, 3422, 3427, 3433, 3438, 3443, 3449, 3454, 3459, 3464, 3469, 3474, 3479, 3484, 3489, 3494, 3499, 3504, 3509, 3514, 3518, 3523, 3528, 3532, 3537, 3541, 3546, 3550, 3555, 3559, 3563, 3568, 3572, 3576, 3580, 3585, 3589, 3593, 3597, 3601, 3605, 3609, 3613, 3617, 3621, 3624, 3628, 3632, 3636, 3640, 3643, 3647, 3651, 3654, 3658, 3661, 3665, 3668, 3672, 3675, 3679, 3682, 3685, 3689, 3692, 3695, 3698, 3702, 3705, 3708, 3711, 3714, 3717, 3720, 3723, 3726, 3729, 3732, 3735, 3738, 3741, 3744, 3747, 3750, 3752, 3755, 3758, 3761, 3763, 3766, 3769, 3771, 3774, 3777, 3779, 3782, 3784, 3787, 3789, 3792, 3794, 3797, 3799, 3802, 3804, 3806, 3809, 3811, 3813, 3816, 3818, 3820, 3822, 3825, 3827, 3829, 3831, 3833, 3835, 3837, 3840, 3842, 3844, 3846, 3848, 3850, 3852, 3854, 3856, 3858, 3859, 3861, 3863, 3865, 3867, 3869, 3871, 3873, 3874, 3876, 3878, 3880, 3881, 3883, 3885, 3887, 3888, 3890, 3892, 3893, 3895, 3897, 3898, 3900, 3901, 3903, 3904, 3906, 3908, 3909, 3911, 3912, 3914, 3915, 3916, 3918, 3919, 3921, 3922, 3924, 3925, 3926, 3928, 3929, 3930, 3932, 3933, 3934, 3936, 3937, 3938, 3940, 3941, 3942, 3943, 3945, 3946, 3947, 3948, 3949, 3951, 3952, 3953, 3954, 3955, 3956, 3958, 3959, 3960, 3961, 3962, 3963, 3964, 3965, 3966, 3967, 3968, 3969, 3970, 3971, 3972, 3973, 3974, 3975, 3976, 3977, 3978, 3979, 3980, 3981, 3982, 3983, 3984, 3985, 3986, 3986, 3987, 3988, 3989, 3990, 3991, 3992, 3993, 3993, 3994, 3995, 3996, 3997, 3997, 3998, 3999, 4000, 4001, 4001, 4002, 4003, 4004, 4004, 4005, 4006, 4007, 4007, 4008, 4009, 4009, 4010, 4011, 4011, 4012, 4013, 4013, 4014, 4015, 4015, 4016, 4017, 4017, 4018, 4019, 4019, 4020, 4021, 4021, 4022, 4022, 4023, 4023, 4024, 4025, 4025, 4026, 4026, 4027, 4027, 4028, 4029, 4029, 4030, 4030, 4031, 4031, 4032, 4032, 4033, 4033, 4034, 4034, 4035, 4035, 4036, 4036, 4037, 4037, 4038, 4038, 4039, 4039, 4040, 4040, 4040, 4041, 4041, 4042, 4042, 4043, 4043, 4043, 4044, 4044, 4045, 4045, 4046, 4046, 4046, 4047, 4047, 4048, 4048, 4048, 4049, 4049, 4049, 4050, 4050, 4051, 4051, 4051, 4052, 4052, 4052, 4053, 4053, 4053, 4054, 4054, 4054, 4055, 4055, 4055, 4056, 4056, 4056, 4057, 4057, 4057, 4058, 4058, 4058, 4059, 4059, 4059, 4059, 4060, 4060, 4060, 4061, 4061, 4061, 4061, 4062, 4062, 4062, 4063, 4063, 4063, 4063, 4064, 4064, 4064, 4064, 4065, 4065, 4065, 4065, 4066, 4066, 4066, 4066, 4067, 4067, 4067, 4067, 4067, 4068, 4068, 4068, 4068, 4069, 4069, 4069, 4069, 4069, 4070, 4070, 4070, 4070, 4070, 4071, 4071, 4071, 4071, 4071, 4072, 4072, 4072, 4072, 4072, 4073, 4073, 4073, 4073, 4073, 4074, 4074, 4074, 4074, 4074, 4074, 4075, 4075, 4075, 4075, 4075, 4075, 4076, 4076, 4076, 4076, 4076, 4076, 4077, 4077, 4077, 4077, 4077, 4077, 4077, 4078, 4078, 4078, 4078, 4078, 4078, 4078, 4079, 4079, 4079, 4079, 4079, 4079, 4079, 4080, 4080, 4080, 4080, 4080, 4080, 4080, 4080, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4095};


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
static uint16_t tgr_cnt[10]={0};
static uint16_t rec=0, play=0;

/* TODO:

- maybe add logarithmic for all touch and for speed so we get full range!

- test rec/play across all 4 areas - seems to work 15/4 - need more tests
- test freeze with rec and playback for each - seems to work 15/4 - need more tests
- all modes to implement/test and then see what works

Modes:

- Speed modes (works only for playback or ...) - also speed/no speed across all modes 

- Overlay modes (addition to max, mid addition=if below mid subtract otherwise add, modulo addition, subtraction, multiplication) 

question of overlay with speed is Q - how we do this...

- Sectional modes (half and half?)
- How we can also record speed changes (on playback these are stored? Where stored - as upper voltage -> adc_buffer[6]?

but not in record function but overlaid - or can add/subtract from what was there?

- Backwards?
- Higher resolution recording and only slows down on playback/variable speed
- Only record the VCA and not the voltages and vice versa…
- Playback starts from same position it ended or from beginning

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
    static uint16_t speed=1;
    volatile uint16_t k;
    uint16_t j;
    // array to map freeze but exception is FR8 on PC4! 
    uint16_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint16_t bits;
    static uint16_t values[8];
    static uint16_t frozen[8]={0}, freezern[8]={0}, frcount[8]={0};
    static uint16_t target[8]={0}, lastrec=0, lastplay=0, lastvalue[8];
    static uint16_t count=0, triggered[10]={0}, lasttriggered[10]={0}, breaker[10]={0};

    uint16_t tmp;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	
	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  breaker[7]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[7])) && triggered[7]==0) breaker[7]++; 

	if (triggered[7]==1 && lasttriggered[7]==0) { // new trigger
	  tgr_cnt[7]=0;
	  lasttriggered[7]=1;
	}
	
	if (lasttriggered[7]==1) 	tgr_cnt[7]++;

	if (tgr_cnt[7]>TRG){
	  triggered[7]=0;
	  lasttriggered[7]=0;
	}	 	  
	} // daccount==7
  else
    {
	if (!(GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0 && breaker[daccount]>BRK) {
	  triggered[daccount]=1;
	  frozen[daccount]^=1;
	  breaker[daccount]=0;
	}
	
	if ( (GPIOB->IDR & (freezer[daccount])) && triggered[daccount]==0) breaker[daccount]++; 

	if (triggered[daccount]==1 && lasttriggered[daccount]==0) { // new trigger
	  tgr_cnt[daccount]=0;
	  lasttriggered[daccount]=1;
	}
	
	if (lasttriggered[daccount]==1) 	tgr_cnt[daccount]++;

	if (tgr_cnt[daccount]>TRG){
	  triggered[daccount]=0;
	  lasttriggered[daccount]=0;
	}
    }
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0 && play==0){
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    values[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  // if play stops and we were in freeze before entering we need to restore the last value
  //

  
  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;       freezern[0]=0;       frcount[0]=0; lastvalue[0]=values[0];
      play_cnt[1]=0;       freezern[1]=0;       frcount[1]=0; lastvalue[1]=values[1];
      play_cnt[2]=0;       freezern[2]=0;       frcount[2]=0; lastvalue[2]=values[2];
      play_cnt[3]=0;       freezern[3]=0;       frcount[3]=0; lastvalue[3]=values[3];
      play_cnt[4]=0;       freezern[4]=0;       frcount[4]=0; lastvalue[4]=values[4];
      play_cnt[5]=0;       freezern[5]=0;       frcount[5]=0; lastvalue[5]=values[5];
      play_cnt[6]=0;       freezern[6]=0;       frcount[6]=0; lastvalue[6]=values[6];
      play_cnt[7]=0;       freezern[7]=0;       frcount[7]=0; lastvalue[7]=values[7];
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry
    if ( ((recordings[daccount][play_cnt[daccount]]) & (1<<15)) && freezern[daccount]==0  ){ // top bit is toggled
      freezern[daccount]=1;
      frcount[daccount]=0;
      target[daccount]=recordings[daccount][play_cnt[daccount]] - (1<15);
    }
	
    if (freezern[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    else { // freezern!
      if (play_cnt[daccount]==0) tmp=(recordings[daccount][6999]);
      else tmp=(recordings[daccount][play_cnt[daccount]-1]);
      values[daccount]=tmp;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
      if (freezern[daccount]==1){
	frcount[daccount]++;
	if (frcount[daccount]==target[daccount]) {
	  if (rec_cnt[daccount]==1) { // then just loop on freeze
	    frcount[daccount]=0;
	  }
	else {
	  freezern[daccount]=0;
	  play_cnt[daccount]++;
	  if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
	}
	}
      } // freezern
      else {
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
      }
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
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
      freezern[daccount]=1;  //toggle freezern[daccount] to signal we start
      frcount[daccount]=0;
      if (rec_cnt[daccount]==0) { // there is no previous value...
	recordings[daccount][0]=values[daccount];
	rec_cnt[daccount]=1;
	}

    }
    // and start counting until freeze goes to zero then write this counter to lower bits(make sure is not>max=32767 + toggle top bit
    if (freezern[daccount]){
      frcount[daccount]++;
      recordings[daccount][rec_cnt[daccount]]=frcount[daccount]+(1<<15);
      if (frozen[daccount]==0 || frcount[daccount]==32767){ // so there is a max frozen time?
	freezern[daccount]=0;
	frcount[daccount]=0;
	rec_cnt[daccount]++;
	if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
      }
    } // in freezern
    else { 
    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
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
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      //      speed=32;

      // only toggle rec and play after all dacs
            
    	if (!(GPIOB->IDR & (1<<10)) && triggered[8]==0 && breaker[8]>BRK8) {
	  triggered[8]=1;
	  rec^=1;
	  breaker[8]=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered[8]==0) breaker[8]++; 
	
	if (triggered[8]==1 && lasttriggered[8]==0) { // new trigger
	  tgr_cnt[8]=0;
	  lasttriggered[8]=1;
	}
	
	if (lasttriggered[8]==1) 	tgr_cnt[8]++;

	if (tgr_cnt[8]>TRG8){
	  triggered[8]=0;
	  lasttriggered[8]=0;
	}
      
	//play	
      
    	if (!(GPIOB->IDR & (1<<2)) && triggered[9]==0 && breaker[9]>BRK8) {
	  triggered[9]=1;
	  play^=1;
	  breaker[9]=0;
	}

	if ( (GPIOB->IDR & (1<<2)) && triggered[9]==0) breaker[9]++; 
	
	if (triggered[9]==1 && lasttriggered[9]==0) { // new trigger
	  tgr_cnt[9]=0;
	  lasttriggered[9]=1;
	}
	
	if (lasttriggered[9]==1) 	tgr_cnt[9]++;

	if (tgr_cnt[9]>TRG8){
	  triggered[9]=0;
	  lasttriggered[9]=0;
	}
      
	
    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
    if (rec) play=0;

	
  }  

  
	   /////////////////////////////

	/*			
	// this new version seems to work - TODO: implement for all

	if (!(GPIOB->IDR & (1<<10)) && triggered==0 && breaker>BRK) {
	  triggered=1;
	  rec^=1;
	  breaker=0;
	}

	if ( (GPIOB->IDR & (1<<10)) && triggered==0) breaker++; 
	
	if (triggered==1 && lasttriggered==0) { // new trigger
	  tgr_cnt[0]=0;
	  lasttriggered=1;
	}
	
	if (lasttriggered==1) 	tgr_cnt[0]++;

	if (tgr_cnt[0]>BRK){
	  triggered=0;
	  lasttriggered=0;
	}
	*/

	/*
	if (laststaterec!=newstaterec) tgr_cnt[0]=0;

    	if (tgr_cnt[0]>20){
	  if (newstaterec!=staterec){
	    staterec=newstaterec;
	    if (staterec==0) rec^=1;
	  }
	}
	
	laststaterec=newstaterec;	
	tgr_cnt[0]++;
	*/	

///////////////////////////////////////////////////////////////////////  
/*  if (rec) k=4095; // 2 6 and 10
      else k=0;
  
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1);
  GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
  GPIOC->BSRRL=(0)<<13; //  write DAC bits 
    */
    }  
}
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
