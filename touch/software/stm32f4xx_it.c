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

#define MAXMODES 4

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

27/4: 

- remove freezer tagging/system and re-testDONE
- what is length of recording (as now we have 1khz/32=30hz so 7000/30=233 seconds...

- we need to think about how to freeze speed in all/some cases: freeze speed and/or freeze underlying voltage
- also what/if is unfrozen when we come out of play in some cases

Modes redux: say 32 modes and variations - question is different speed approaches which might double this

0 - basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing...
1 - basic mode 0 with speed also decreasing
2 - basic mode 0 with overlay as midpoint thing - what of speed?
3 - basic mode 0 with overlay as modulo (so these are all the same) - what of speed?
DONE

4 - with freezers as recording, stopping recording the additions which
then play back alongside temp additions (and as above variations)
record sets back to original
play returns to no playback but can still record additions
5 
6 midpoint - seems go to silence??? so maybe lose THIS ONE!
7 modulo

//////TODO::::::::::::::::::::

8 - press freeze and plays back for that section the last x seconds (so always recording) - how do we determine the x seconds? (next freeze sets that?)
       [ but how does this operate when we enter this mode from nothing and freeze - start recording on entry and max will be length]
       [ what do rec and play buttons do?]
- IN TESTING
9
10
11

12 - freezers reverse the last section for playback, and can overlay (no freeze allowed tho) 
13
14
15

16 - freezers free/detach that section or start playback again in that section... again with overlays (what then does play button do?)
[ 
17
18
19

others: 

voltage controlled speed of all playback from top voltage

20 - each voltage changes speed of that specific playback section and
we use freeze, unfreeze to record those changes, overlays also only
for VCA and for speed. speeds for each sample are set in top 5 or 6 bits?

21
22
23

24
25
26
27
28

29
30
31
32

/////////////////////////////

- maybe add logarithmic for all touch and for speed so we get full range!
- test rec/play across all 4 areas - seems to work 15/4 - need more testsDONE
- test freeze with rec and playback for each - seems to work 15/4 - need more testsDONE

- do we keep rec buffer across modes (if so we need to work out freeze/over-record issue)DONE


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

new mode - playback has overlay, but when press freeze (zero on
playback) it records this until unpress, and can still add overlay

playback has overlay with freeze as usual (default mode)

problem with all overlay modes is that freeze recording scheme doesn't work as we would need to keep expanding and shifting??? (possible but...)

new mode - press freeze and plays back for that section the last x seconds (so always recording)

playback with all seperate speeds...

use of freeze and other buttons in all modes

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
    static uint16_t values[8], real[8];
    static uint16_t frozen[8]={0};
    static uint16_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint16_t count=0, triggered[11]={0}, lasttriggered[11]={0}, breaker[11]={0}, mode=0, starter[8]={0}, ender[8]={7000};

    uint16_t tmp;
    int16_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	/* first of all get mode and do all modes as cases - all seperate even though might repeat same logic
	   - mode is on: PB6 
	 */

	////////////// getting modes on count:
    if (count%(32)==0) { //for xxx HZ?

      if (!(GPIOB->IDR & (1<<6)) && triggered[10]==0 && breaker[10]>BRK8) {
	  triggered[10]=1;
	 mode+=1;
	 if (mode>=MAXMODES) mode=0;
	  breaker[10]=0;
	}

	if ( (GPIOB->IDR & (1<<2)) && triggered[10]==0) breaker[10]++; 
	
	if (triggered[10]==1 && lasttriggered[10]==0) { // new trigger
	  tgr_cnt[10]=0;
	  lasttriggered[10]=1;
	}
	
	if (lasttriggered[10]==1) 	tgr_cnt[10]++;

	if (tgr_cnt[10]>TRG8){
	  triggered[10]=0;
	  lasttriggered[10]=0;
	}
    } // end of mode selector, each mode needs to take care of everything
    
    mode=8; // testings
    
    switch(mode){
    case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing...
      
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
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
      //      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits 7 bits=128
      // for frozen speed instead:
      speed=values[6]>>7;
      if (speed>31) speed=31;
      speed=32-(speed); //4 bits=16 256/16=
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
    break; ///// case 0
      
    case 1: // basic mode 0 with speed also decreasing
  
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
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
      speed=(adc_buffer[6]>>4); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>127) speed=127;
      speed=128-(speed); //4 bits=16 256/16=
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
    break; // mode 1

    case 2: // 2 - basic mode 0 with overlay as midpoint thing - what of speed?
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
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      //      values[daccount]+=real[daccount]; // to take to the midpoint so 4096/2=2048 is mid
      midder=values[daccount]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      values[daccount]=midder;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
    break;// mode 2      

    case 3: // 3 - basic mode 0 with overlay as modulo (so these are all the same) - what of speed?
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
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0;
      play_cnt[1]=0;
      play_cnt[2]=0;
      play_cnt[3]=0;
      play_cnt[4]=0;
      play_cnt[5]=0;
      play_cnt[6]=0;
      play_cnt[7]=0;
    }
    // take care of frozen/repeats - top bit is toggled and we just repeat last value...
    // we can re-use frcount and freezern as rec and play never happen at same time - and we zero them on entry

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      values[daccount]=values[daccount]%4096;
      //     if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
    break; // mode 3      

    case 4: // RECCCC
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
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
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
    break; // mode 4  

    case 5: // as RECC overlay but with speed lowered
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
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
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

        if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
      speed=(adc_buffer[6]>>4); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>127) speed=127;
      speed=128-(speed); //4 bits=16 256/16=
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
      break; // mode 5

    case 6: // as mode 4 (regular speed) with overlay as midpoint
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
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
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      //      recordings[daccount][play_cnt[daccount]]+=real[daccount];

      midder=recordings[daccount][play_cnt[daccount]]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      recordings[daccount][play_cnt[daccount]]=midder;
      
      //      if (recordings[daccount][play_cnt[daccount]]>4095) recordings[daccount][play_cnt[daccount]]=4095;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      midder=values[daccount]+real[daccount]-2048;     
      if (midder<0) midder=0;
      if (midder>4095) midder=4095;
      values[daccount]=midder;
      //      values[daccount]+=real[daccount];
      //      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
      break; // mode 6

    case 7: // as 4 but with modulo
      /* with freezers as recording, stopping recording the additions which
	 then play back alongside temp additions (and as above variations -> speed, midpoint, modulo)
	 record sets back to original with freezing as possible
	 play returns to no playback but can still record additions ???
      */
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
	
	if (frozen[daccount]==0 || play==1) {
	  ADC_SoftwareStartConv(ADC1);
	  //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	  real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
	}

  if (play){
    if (lastplay==0) {     // is it a new play?
      // we need to undo freezers
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; frozen[0]=0; added[0]=0;
      play_cnt[1]=0; frozen[1]=0; added[1]=0;
      play_cnt[2]=0; frozen[2]=0; added[2]=0;
      play_cnt[3]=0; frozen[3]=0; added[3]=0;
      play_cnt[4]=0; frozen[4]=0; added[4]=0;
      play_cnt[5]=0; frozen[5]=0; added[5]=0;
      play_cnt[6]=0; frozen[6]=0; added[6]=0;
      play_cnt[7]=0; frozen[7]=0; added[7]=0;
    }

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]]);

    // in play if frozen then add the value to the recording
    // otherwise nothing - but only do this once even if we are still here....
    if (frozen[daccount] && added[daccount]==0){
      recordings[daccount][play_cnt[daccount]]+=real[daccount];
      recordings[daccount][play_cnt[daccount]]=recordings[daccount][play_cnt[daccount]]%4096;
      //            values[daccount]+=real[daccount];
      //      values[daccount]=values[daccount]%4096;
      added[daccount]=1;
    }
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    added[daccount]=0;
    }
  } // if play
  else lastplay=0;

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are recording
    if (lastrec==0) {     // is it a new recording?
      lastrec=1;
      // zero all of them
      rec_cnt[0]=0; 
      rec_cnt[1]=0; 
      rec_cnt[2]=0; 
      rec_cnt[3]=0; 
      rec_cnt[4]=0; 
      rec_cnt[5]=0; 
      rec_cnt[6]=0; 
      rec_cnt[7]=0; 
    }

    recordings[daccount][rec_cnt[daccount]]=values[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  // if we come out of recording we need to undo the freezers
  else {
    if (lastrec==1) {
      frozen[0]=0;
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
    lastrec=0;
  }
  } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      //      values[daccount]+=real[daccount];
      //      if (values[daccount]>4095) values[daccount]=4095;
      values[daccount]+=real[daccount];
      values[daccount]=values[daccount]%4096;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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
    break; // mode 7

    case 8:
      ///8 - press freeze and plays back for that section the last x seconds (so always recording) - how do we determine the x seconds? (next freeze sets that?)
      //       [ but how does this operate when we enter this mode from nothing and freeze - start recording on entry and max will be length]
      // question is if we loop - so continue recording in a loop even if we play back...
      // what does rec do : (play deals with playback)
      // rec button could reset everything
      
      // if we just entered start recording and continue
      if (lastmode!=mode){ // assign lastmode in other modes
	rec=1;
	starter[0]=0; ender[0]=7000;	
	starter[1]=0; ender[1]=7000;	
	starter[2]=0; ender[2]=7000;	
	starter[3]=0; ender[3]=7000;	
	starter[4]=0; ender[4]=7000;	
	starter[5]=0; ender[5]=7000;	
	starter[6]=0; ender[6]=7000;	
	starter[7]=0; ender[7]=7000;	
      }
	/////// TOGGLING for freezers	
      // in this case freezer=1 sets start point, 0 sets end point for each one... in starter and ender...
      // for playback

      if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  if (frozen[7]==1) {
	    starter[7]=rec_cnt[7];
	    play_cnt[7]=rec_cnt[7];
	  }
	  else ender[7]=rec_cnt[7];
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
	  if (frozen[daccount]==1) {
	    starter[daccount]=rec_cnt[daccount];
	    play_cnt[daccount]=rec_cnt[daccount];
	  }
	  else ender[daccount]=rec_cnt[daccount];
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
	
      ADC_SoftwareStartConv(ADC1);
      real[daccount]=adc_buffer[daccount]<<1;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left

  if (play){

    values[daccount]=(recordings[daccount][play_cnt[daccount]]);
    
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>ender[daccount]) play_cnt[daccount]=starter[daccount];
    }
  } // if play

    
  ///// recordings
  
    if (count%(32)==0) { //for xxx HZ?
    
  if (rec){ // we are always recording 

    recordings[daccount][rec_cnt[daccount]]=real[daccount]&4095; // ignore top bits
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
    }
    else values[daccount]=real[daccount];    // otherwise just values
    
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

      // in this case what does rec do?
      
      /*            
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
      */
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
      	
	//    if (play) rec=0; // how to resolve this - what happens if we press play in record mode?
	//    if (rec) play=0;
    }
    lastmode=8;      
      break; // mode 8

    case 20:
      /* 20 - each voltage changes speed of that specific playback section and
	 we use freeze, unfreeze to record those changes, overlays also only
	 for VCA and for speed. speeds for each sample are set in top 5 or 6 bits?
	 
	 - so is speed for VCA and voltage for each section
	 - rec and non-playback is all as usual (freeze is freeze)
	 - playback mode - speed changes for each section (overlay also), freeze to rec, unfreeze to stop rec...

      */


      
      break: // mode 20
      
    } // end of modes switch    
    } 
  }
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
