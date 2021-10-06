/**

Revisiting 30 Sept:

- 30/9 tests: 2 and 3 not closing: 3 was adc issue which fixed
   somehow, 2 still bleeds at 60mV, we adjusted TIM2 slower to get rid
   of bleed across VCAs (why now?), still to test new freeze
   functionality...also got rid of shift as was loud (to check on
   scope), maybe try different resistor values for closings, testing
   first freeze and seems to work


//////////////////////////

TODO: August 30+ 2021:

- new PCB - we have trig on PC6 which needs to go high only when we sense any of trigs (freezers, rec, play, mode)

- basic operations of VCA and voltage with new board (also now we have low pass in hardware)
- new freezer/trig code and test all

think it is in mode23 but we need to change the output pin here!

- figure out modes, timings, log etc.

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

#define TRG 4 // trigger - was 100 but /8 - these are for freeze
#define BRK 8 // off hold was 1200 but /8

#define TRG8 1 // these for rec/play etc
#define BRK8 2 // 27 is best figure
#define DELB 10000 // delay for pin changes in new trigger code

#define MAXMODES 4

    GPIO_InitTypeDef GPIO_InitStructure;


// rev log doesn't work
//const uint16_t logval[1024]  __attribute__ ((section (".flash"))) = {0, 33, 66, 98, 131, 163, 195, 226, 257, 289, 319, 350, 380, 410, 440, 470, 499, 528, 557, 586, 614, 642, 670, 698, 726, 753, 780, 807, 833, 860, 886, 912, 938, 963, 989, 1014, 1039, 1064, 1088, 1113, 1137, 1161, 1184, 1208, 1231, 1255, 1278, 1300, 1323, 1345, 1368, 1390, 1412, 1433, 1455, 1476, 1498, 1519, 1540, 1560, 1581, 1601, 1621, 1641, 1661, 1681, 1701, 1720, 1739, 1758, 1777, 1796, 1815, 1833, 1851, 1870, 1888, 1905, 1923, 1941, 1958, 1975, 1993, 2010, 2027, 2043, 2060, 2076, 2093, 2109, 2125, 2141, 2157, 2173, 2188, 2204, 2219, 2234, 2249, 2264, 2279, 2294, 2308, 2323, 2337, 2351, 2365, 2379, 2393, 2407, 2421, 2434, 2448, 2461, 2474, 2488, 2501, 2513, 2526, 2539, 2552, 2564, 2576, 2589, 2601, 2613, 2625, 2637, 2649, 2661, 2672, 2684, 2695, 2706, 2718, 2729, 2740, 2751, 2762, 2773, 2783, 2794, 2804, 2815, 2825, 2836, 2846, 2856, 2866, 2876, 2886, 2896, 2905, 2915, 2924, 2934, 2943, 2953, 2962, 2971, 2980, 2989, 2998, 3007, 3016, 3025, 3033, 3042, 3050, 3059, 3067, 3076, 3084, 3092, 3100, 3108, 3116, 3124, 3132, 3140, 3148, 3155, 3163, 3170, 3178, 3185, 3193, 3200, 3207, 3215, 3222, 3229, 3236, 3243, 3250, 3256, 3263, 3270, 3277, 3283, 3290, 3296, 3303, 3309, 3316, 3322, 3328, 3334, 3341, 3347, 3353, 3359, 3365, 3371, 3377, 3382, 3388, 3394, 3400, 3405, 3411, 3416, 3422, 3427, 3433, 3438, 3443, 3449, 3454, 3459, 3464, 3469, 3474, 3479, 3484, 3489, 3494, 3499, 3504, 3509, 3514, 3518, 3523, 3528, 3532, 3537, 3541, 3546, 3550, 3555, 3559, 3563, 3568, 3572, 3576, 3580, 3585, 3589, 3593, 3597, 3601, 3605, 3609, 3613, 3617, 3621, 3624, 3628, 3632, 3636, 3640, 3643, 3647, 3651, 3654, 3658, 3661, 3665, 3668, 3672, 3675, 3679, 3682, 3685, 3689, 3692, 3695, 3698, 3702, 3705, 3708, 3711, 3714, 3717, 3720, 3723, 3726, 3729, 3732, 3735, 3738, 3741, 3744, 3747, 3750, 3752, 3755, 3758, 3761, 3763, 3766, 3769, 3771, 3774, 3777, 3779, 3782, 3784, 3787, 3789, 3792, 3794, 3797, 3799, 3802, 3804, 3806, 3809, 3811, 3813, 3816, 3818, 3820, 3822, 3825, 3827, 3829, 3831, 3833, 3835, 3837, 3840, 3842, 3844, 3846, 3848, 3850, 3852, 3854, 3856, 3858, 3859, 3861, 3863, 3865, 3867, 3869, 3871, 3873, 3874, 3876, 3878, 3880, 3881, 3883, 3885, 3887, 3888, 3890, 3892, 3893, 3895, 3897, 3898, 3900, 3901, 3903, 3904, 3906, 3908, 3909, 3911, 3912, 3914, 3915, 3916, 3918, 3919, 3921, 3922, 3924, 3925, 3926, 3928, 3929, 3930, 3932, 3933, 3934, 3936, 3937, 3938, 3940, 3941, 3942, 3943, 3945, 3946, 3947, 3948, 3949, 3951, 3952, 3953, 3954, 3955, 3956, 3958, 3959, 3960, 3961, 3962, 3963, 3964, 3965, 3966, 3967, 3968, 3969, 3970, 3971, 3972, 3973, 3974, 3975, 3976, 3977, 3978, 3979, 3980, 3981, 3982, 3983, 3984, 3985, 3986, 3986, 3987, 3988, 3989, 3990, 3991, 3992, 3993, 3993, 3994, 3995, 3996, 3997, 3997, 3998, 3999, 4000, 4001, 4001, 4002, 4003, 4004, 4004, 4005, 4006, 4007, 4007, 4008, 4009, 4009, 4010, 4011, 4011, 4012, 4013, 4013, 4014, 4015, 4015, 4016, 4017, 4017, 4018, 4019, 4019, 4020, 4021, 4021, 4022, 4022, 4023, 4023, 4024, 4025, 4025, 4026, 4026, 4027, 4027, 4028, 4029, 4029, 4030, 4030, 4031, 4031, 4032, 4032, 4033, 4033, 4034, 4034, 4035, 4035, 4036, 4036, 4037, 4037, 4038, 4038, 4039, 4039, 4040, 4040, 4040, 4041, 4041, 4042, 4042, 4043, 4043, 4043, 4044, 4044, 4045, 4045, 4046, 4046, 4046, 4047, 4047, 4048, 4048, 4048, 4049, 4049, 4049, 4050, 4050, 4051, 4051, 4051, 4052, 4052, 4052, 4053, 4053, 4053, 4054, 4054, 4054, 4055, 4055, 4055, 4056, 4056, 4056, 4057, 4057, 4057, 4058, 4058, 4058, 4059, 4059, 4059, 4059, 4060, 4060, 4060, 4061, 4061, 4061, 4061, 4062, 4062, 4062, 4063, 4063, 4063, 4063, 4064, 4064, 4064, 4064, 4065, 4065, 4065, 4065, 4066, 4066, 4066, 4066, 4067, 4067, 4067, 4067, 4067, 4068, 4068, 4068, 4068, 4069, 4069, 4069, 4069, 4069, 4070, 4070, 4070, 4070, 4070, 4071, 4071, 4071, 4071, 4071, 4072, 4072, 4072, 4072, 4072, 4073, 4073, 4073, 4073, 4073, 4074, 4074, 4074, 4074, 4074, 4074, 4075, 4075, 4075, 4075, 4075, 4075, 4076, 4076, 4076, 4076, 4076, 4076, 4077, 4077, 4077, 4077, 4077, 4077, 4077, 4078, 4078, 4078, 4078, 4078, 4078, 4078, 4079, 4079, 4079, 4079, 4079, 4079, 4079, 4080, 4080, 4080, 4080, 4080, 4080, 4080, 4080, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4081, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4082, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4083, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4084, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4085, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4086, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4088, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4089, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4095};

const uint16_t logval[1024]  __attribute__ ((section (".flash"))) = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 41, 42, 42, 42, 43, 43, 43, 44, 44, 45, 45, 45, 46, 46, 46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 53, 53, 54, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72, 73, 73, 74, 75, 75, 76, 77, 77, 78, 79, 79, 80, 81, 81, 82, 83, 83, 84, 85, 85, 86, 87, 87, 88, 89, 90, 90, 91, 92, 93, 93, 94, 95, 96, 97, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107, 108, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 138, 139, 140, 141, 142, 143, 145, 146, 147, 148, 149, 151, 152, 153, 154, 156, 157, 158, 160, 161, 162, 164, 165, 166, 168, 169, 170, 172, 173, 175, 176, 178, 179, 180, 182, 183, 185, 186, 188, 190, 191, 193, 194, 196, 197, 199, 201, 202, 204, 206, 207, 209, 211, 213, 214, 216, 218, 220, 221, 223, 225, 227, 229, 231, 233, 235, 236, 238, 240, 242, 244, 246, 248, 250, 252, 255, 257, 259, 261, 263, 265, 267, 269, 272, 274, 276, 278, 281, 283, 285, 288, 290, 292, 295, 297, 300, 302, 305, 307, 310, 312, 315, 317, 320, 323, 325, 328, 331, 333, 336, 339, 342, 344, 347, 350, 353, 356, 359, 362, 365, 368, 371, 374, 377, 380, 383, 386, 389, 392, 396, 399, 402, 405, 409, 412, 415, 419, 422, 426, 429, 433, 436, 440, 443, 447, 451, 454, 458, 462, 466, 470, 473, 477, 481, 485, 489, 493, 497, 501, 505, 509, 514, 518, 522, 526, 531, 535, 539, 544, 548, 553, 557, 562, 566, 571, 576, 580, 585, 590, 595, 600, 605, 610, 615, 620, 625, 630, 635, 640, 645, 651, 656, 661, 667, 672, 678, 683, 689, 694, 700, 706, 712, 717, 723, 729, 735, 741, 747, 753, 760, 766, 772, 778, 785, 791, 798, 804, 811, 817, 824, 831, 838, 844, 851, 858, 865, 872, 879, 887, 894, 901, 909, 916, 924, 931, 939, 946, 954, 962, 970, 978, 986, 994, 1002, 1010, 1018, 1027, 1035, 1044, 1052, 1061, 1069, 1078, 1087, 1096, 1105, 1114, 1123, 1132, 1141, 1151, 1160, 1170, 1179, 1189, 1198, 1208, 1218, 1228, 1238, 1248, 1258, 1269, 1279, 1290, 1300, 1311, 1321, 1332, 1343, 1354, 1365, 1376, 1388, 1399, 1410, 1422, 1433, 1445, 1457, 1469, 1481, 1493, 1505, 1518, 1530, 1542, 1555, 1568, 1581, 1593, 1606, 1620, 1633, 1646, 1660, 1673, 1687, 1701, 1715, 1729, 1743, 1757, 1771, 1786, 1800, 1815, 1830, 1845, 1860, 1875, 1890, 1906, 1921, 1937, 1953, 1969, 1985, 2001, 2018, 2034, 2051, 2067, 2084, 2101, 2119, 2136, 2153, 2171, 2189, 2206, 2224, 2243, 2261, 2279, 2298, 2317, 2336, 2355, 2374, 2393, 2413, 2433, 2453, 2473, 2493, 2513, 2534, 2554, 2575, 2596, 2618, 2639, 2661, 2682, 2704, 2726, 2749, 2771, 2794, 2816, 2839, 2863, 2886, 2910, 2933, 2957, 2981, 3006, 3030, 3055, 3080, 3105, 3131, 3156, 3182, 3208, 3234, 3261, 3287, 3314, 3341, 3368, 3396, 3424, 3452, 3480, 3508, 3537, 3566, 3595, 3624, 3654, 3684, 3714, 3744, 3775, 3805, 3837, 3868, 3899, 3931, 3963, 3996, 4028, 4061, 4095};


#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < DELB; ++ix)				\
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

static uint16_t recordings[8][7000]; // 
static uint16_t rec_cnt[8]={0};
static uint16_t play_cnt[8]={0};
static uint16_t tgr_cnt[10]={0};
static uint16_t rec=0, play=0;

//static uint16_t shifter[8]={2,2,2,2,1,1,1,1}; // shifter seperates vca from cv
static uint16_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here
/* TODO:

resolve: voltage levels, freezing Qs, toggling timings

- are levels different for VCA, voltage and for speed  // voltage too high

- decide on behaviour on rec and play: if rec is pressed during play or vice versa

options: 

- rec starts. rec stops play. play stops rec and starts play (this is what we have)
- rec starts. rec stops rec. play doesn't stop rec but records add/overlay


///

- test all modes and resolve questions of zeroing freezers (after playback), level of voltages/ADC (left or right adc), freezing of speed or of value/or both?

- question of midpoint thing. different speeds across modes - how many major modes we have?

- new mode TODO/TEST: that we can also attach and detach recordings for each cv (what then does rec do-> reattaches all of them)

14/5:

- with test code in mode 23 and BRK3 at 27 we have good triggers with centre circle covered...

TODO on top panel:

Break centre circle at edges, add new vias to keep design and just
have each part of drop to 40106/freeze, cover with soldermask the
sensors, and maybe have circle there at gnd and also covered...


13/5:

- added one line for trigger code to be implemented in all modes for rec and freeze but freeze timing still not quite right
- major problems as with finger on ADC or B then we have no triggers... B is virtual GND in, ADC is grounding?

- TOUCH issues: pull down from triggers when we touch adc or virtual
  ground B and all signals also go high when we touch power - only
  solution is to rework trigger from 50Hz with timing and do away with
  power centre circle and blood power… and no pull up before 40106

Break centre circle at edges, add new vias to keep design and just
have each part of drop to 40106/freeze


3/5:

- testing in mode 0 and adjusting timings for play/record/freeze, added shifter so different shifts for vca etc, speed control seems fine,,,
- in mode 0 we freeze speed AND underlying cv overlay... (this could be different)
- question of whether we should overlay on playback for the cv associated with speed?

- extra modes where we re-start playback/rec from place where we left off rather than resetting to zero
- additive mode where we add next rec section and play plays all joined sections!


30/4:
TODO: mode 16DONE

- we need to think about how to freeze speed in all/some cases: freeze speed and/or freeze underlying voltage
- also what/if is unfrozen when we come out of play in some cases - need to return to last frozen value if we come out!

real[daccount]=adc_buffer[daccount]<<2;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
if (real[daccount]>4095) real[daccount]=4095;

- to implement to get full voltage or shall we revert to right shift of ADC?


27/4: 

- remove freezer tagging/system and re-testDONE
- what is length of recording (as now we have 1khz/32=30hz so 7000/30=233 seconds...TEST THIS!

///////////////////////////////////////////

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

8 - press freeze and plays back for that section the last x seconds (so always recording) - how do we determine the x seconds? (next freeze sets that?)
       [ but how does this operate when we enter this mode from nothing and freeze - start recording on entry and max will be length]
       [ what do rec and play buttons do?]
- IN TESTING
9
10
11

12 - freezers reverse the last section for playback, and can overlay (no freeze allowed tho) 
[ so in rec and non-playback freeze also freezes]
- IMPLEMENTED but needs testings

13
14
15

16 - freezers free/detach that section or start playback again in that section... again with overlays (what then does play button do?)
[ play button plays them all!] DONE
17
18
19

20 - each voltage changes speed of that specific playback section and
we use freeze, unfreeze to record those changes, overlays also only
for VCA and for speed. speeds for each sample are set in top 5 or 6 bits?
- IMPLEMENTED but needs more testings

21
22
23


others: 

- [voltage controlled speed of all playback from top voltage ????what does this mean? that we can record speed of playback (how?)]

- that we can also attach and detach recordings for each cv (what then does rec do-> reattaches all of them)

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
    static uint16_t count=0, triggered[11]={0}, lasttriggered[11]={0}, breaker[11]={0}, mode=0, starter[8]={0}, ender[8]={7000}, recsp[8]={0};

    uint16_t tmp, trigd;
    int16_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	/* first of all get mode and do all modes as cases - all seperate even though might repeat same logic
	   - mode is on: PB6 
	 */

	////////////// getting modes on count:
	/*    if (count%(32)==0) { //for xxx HZ?

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
	} */

// end of mode selector, each mode needs to take care of everything
    
    mode=0; // testings
    
    switch(mode){
    case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing...
      
	// this runs always at full speed!
	// handle playback here too
	// what happens if play and rec are both ON!?
	
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);
    // retrying log
    //    tmp=adc_buffer[daccount];
    //    if (tmp>1023) tmp=1023;
    //    real[daccount]=logval[tmp];
    
    //            values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
        real[daccount]=adc_buffer[daccount]<<shifter[daccount];// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
        if (real[daccount]>4095) real[daccount]=4095;

    // try another log!
    
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

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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
    //    values[daccount]=4095; // TESTY
    //    values[daccount]=0;
    //    if (daccount==0){
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits
    //    }
    
    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
      // toggle PC6 to send high trigger and read finger
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay
      
            if ((GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in
            else trigd=0; // finger off
	    
	    GPIOC->BSRRH=(1)<<6; //  LOW!

            if (!(GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in 0 this is rec
            else trigd=0; // finger off

	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	    //	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_Init(GPIOC, &GPIO_InitStructure);
	    delay();

	    // how to get this as toggle!
	    
	    if (trigd==1 && triggered[0]==0) triggered[0]=1;

	    if (!trigd && triggered[0]==1) breaker[0]++;  // finger off
           if (trigd && triggered[0]==1) breaker[0]=0; // finger on or 50hz

	    if (breaker[0]>BRK8) { // 0 
	      //	      rec^=1;
	      frozen[0]^=1; // test code 30/09/2021
	      breaker[0]=0;
	      triggered[0]=0;
	    }
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

    values[daccount]=(recordings[daccount][play_cnt[daccount]]) & 4095;  // ignore top bits
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits;

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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

        if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;  // ignore top bits;

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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits

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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    if (added[daccount]==0) values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits;

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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

    recordings[daccount][rec_cnt[daccount]]=real[daccount];
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

	 - speed say is 1-64 so 5 bits... (always plus one in case there are zeroes)

      */

	/////// TOGGLING for freezers	
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  frozen[7]^=1;
	  recsp[7]=frozen[7];
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
	  recsp[daccount]=frozen[daccount];
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
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    } // lastplay

    uint16_t speeder[8]={4,5,6,7,4,5,6,7};
    // if we are recording speed then do it here - we need to know what pairs have what?
    // ie. which is control mapping to which - 4,5,6,7 -> 0,1,2,3 I guess - test this!
      ADC_SoftwareStartConv(ADC1);
      // speed is for 2x daccounts - how to handle...
      speed=(adc_buffer[speeder[daccount]]>>5); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>64) speed=64;
      speed=64-(speed); //4 bits=16 256/16=

    if (recsp[daccount]) {
      recordings[daccount][play_cnt[daccount]]=(recordings[daccount][play_cnt[daccount]]&4095)+(speed<<10); // top 5 bits
     }
    else { // we have speed already    
    speed+=((recordings[daccount][play_cnt[daccount]])>>10)+1; // top 5 bits - question of overlay?
    }
    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095;
    if ((count%speed)==0){ // speed goes from 1 to X what
    play_cnt[daccount]++;
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else {
    lastplay=0;
    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
    }
  }
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
    rec_cnt[daccount]++; // 
    if (rec_cnt[daccount]>7000) rec_cnt[daccount]=0;
  } // if rec
  else lastrec=0;
    } // count32

    ////// write to DAC
    // if playback add
    if (play==1) {
      if (daccount<4) {
	values[daccount]+=real[daccount];
      if (values[daccount]>4095) values[daccount]=4095;
      }
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
      /*
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=33-(speed); //4 bits=16 256/16=
      */
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
            
    break; // mode 20

    // THIS ONE TO TEST
    
    case 12:// - freezers reverse the last section for playback, and can overlay (no freeze allowed tho) 
      //[ so in rec and non-playback freeze also freezes]
	/////// TOGGLING for freezers	- use recsp for the reverse or not
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  if (play==0) frozen[7]^=1;
	  else recsp[7]^=1;
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
	  if (play==0) frozen[daccount]^=1;
	  else recsp[daccount]^=1;
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
    real[daccount]=adc_buffer[daccount]<<2;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    if (real[daccount]>4095) real[daccount]=4095;
    //    real[daccount]=4095;
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    }

    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits
    
    if ((count%speed)==0){ // speed goes from 1 to X what
      if (recsp[daccount]==0) play_cnt[daccount]++;
      else {
	if (play_cnt[daccount]==0) play_cnt[daccount]= rec_cnt[daccount]+1;
	play_cnt[daccount]--;
	    }	
    if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
  } // if play
  else
    {
    lastplay=0;
    /*    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
      }*/
    }
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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
      break; // mode 12

    case 16: // freezers free/detach that section or start playback again in that section... again with overlays (what then does play button do?)
      //[ play button plays them all!] - so play starts off the process
      // in rec or no-play freeze works as always
	if (daccount==7){
    // handle GPIOC instead

	if (!(GPIOC->IDR & (freezer[7])) && triggered[7]==0 && breaker[7]>BRK) {
	  triggered[7]=1;
	  if (play==0) frozen[7]^=1;
	  else recsp[7]^=1; // so recsp is for on off of individual plays
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
	  if (play==0) frozen[daccount]^=1;
	  else recsp[daccount]^=1;
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
    real[daccount]=adc_buffer[daccount]<<2;// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    if (real[daccount]>4095) real[daccount]=4095;
    //    real[daccount]=4095;
  }

  if (play){
    if (lastplay==0) {     // is it a new play?
      lastplay=1;
      // zero all of them
      play_cnt[0]=0; recsp[0]=0;
      play_cnt[1]=0; recsp[1]=0;
      play_cnt[2]=0; recsp[2]=0;
      play_cnt[3]=0; recsp[3]=0;
      play_cnt[4]=0; recsp[4]=0;
      play_cnt[5]=0; recsp[5]=0;
      play_cnt[6]=0; recsp[6]=0;
      play_cnt[7]=0; recsp[7]=0;
    }
    // if recsp==1 then we detach that one and stop playback
    if (recsp[daccount]==0){
    values[daccount]=(recordings[daccount][play_cnt[daccount]])&4095; // ignore top bits    
    if ((count%speed)==0){ // speed goes from 1 to X what
      play_cnt[daccount]++;
      if (play_cnt[daccount]>rec_cnt[daccount]) play_cnt[daccount]=0;
    }
    }
    else values[daccount]=0; // this is what is added
  } // if play
  else
    {
    lastplay=0;
    /*    if (lastplay==1) { // we just left play
      frozen[0]=0; // we don't want freezers still on...
      frozen[1]=0;
      frozen[2]=0;
      frozen[3]=0;
      frozen[4]=0;
      frozen[5]=0;
      frozen[6]=0;
      frozen[7]=0;      
      }*/
    }
    
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

    recordings[daccount][rec_cnt[daccount]]=values[daccount];
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

      break; // mode 16

    case 23: // mode to test freeze timings on middle and freeze pads // BRK8
      // testing new freeze/trigger code on FR1

      // pc6 is new trigger OUT pin!
      
      
   GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
    //    values[daccount]=4095; // TESTY
   //   if (frozen[daccount]) values[daccount]=4095;
   //   if (rec) values[daccount]=4095;
   //   else values[daccount]=0;
      if (rec){
    ADC_SoftwareStartConv(ADC1);
                values[daccount]=logval[adc_buffer[daccount]>>2];// now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
     values[daccount]=adc_buffer[daccount];// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
       if (values[daccount]>4095) values[daccount]=4095;
          }
   
    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits


    
    //    daccount++;
    //    if (daccount==8) {
      daccount=4;
      //      count++;

      // now we attached 1->15 to outside of first - 1->8 - attached from r49 right hand side but how to test bleed...
      // test toggling of 1->15
      // with this code and no pullup seems to work as we handle both cases...

      // toggle PC6 to send high trigger and read finger
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
      //      delay();
      
            if ((GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in
            else trigd=0; // finger off
	    
	    GPIOB->BSRRH=(1)<<6; //  LOW!

            if (!(GPIOB->IDR & (1<<8))) trigd=1; // finger on - low out = high in 0 this is rec
            else trigd=0; // finger off

	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	    //	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_Init(GPIOC, &GPIO_InitStructure);
	    delay();

	    // how to get this as toggle!
	    
	    if (trigd==1 && triggered[0]==0) triggered[0]=1;

	    if (!trigd && triggered[0]==1) breaker[0]++;  // finger off
           if (trigd && triggered[0]==1) breaker[0]=0; // finger on or 50hz

	    if (breaker[8]>BRK8) { // 0 
	      rec^=1;
	      breaker[8]=0;
	      triggered[8]=0;
	    }

	      
	    

      	  
      // test rec button - works fine with TRG8 as 8 and BRK8 as 60!
      /*      
//      if ((GPIOB->IDR & (1<<8))) {
 //	triggered[8]=1;
//      }

      if (!(GPIOB->IDR & (1<<8)) && triggered[8]==1) breaker[8]++;  // finger off
      //      if ( (GPIOB->IDR & (1<<8)) && triggered[8]==1) breaker[8]=0; // finger on or 50hz

      if (breaker[8]>BRK8) { // 0 
	rec^=1;
	breaker[8]=0;
	triggered[8]=0;
	}*/
      //      delay();
      //      GPIOB->BSRRH=(1)<<15; //  LOW!
      

      /*
	
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
	    //  }
    break; /// end of TEST button mode 23      
      
    } // end of modes switch    
    } 
  }
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
