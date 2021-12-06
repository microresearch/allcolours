/**

6/12: try new freeze/toggle logics - working better so test for freezings, tested but try with other fingers before we put into TOGGLE MACRO

2/12: re-check freeze etc.logic as seems odd - was wrong way round so corrected but still not 100% as needs release

2/11: we have bleed on voltages - small but present and how can we fix this?

18/10: on mode change should we stop rec/playback as this will change reading of data (only in some cases).

14/10: filled in mode 0 to test all

13/10: TODO: code in freezers, mode switch and rec/play with simple case 0 and test!

11/10: TODO: simplify code sections and test all freezers, rec, mode, playback (basic mode)

- what are our modes and where are these defined? in it.c

Revisiting 30 Sept:

- 30/9 tests: 2 and 3 not closing: 3 was adc issue which fixed
   somehow, 2 still bleeds at 60mV, we adjusted TIM2 slower to get rid
   of bleed across VCAs (why now?), still to test new freeze
   functionality...also got rid of bitshift as was loud (to check on
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

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRK8 (64*8) // 64 at 4 in INT2 // so for 8 in main.c we need 32
#define BRK 64
#define DELB 100 // delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK

#define MAXMODES 4

GPIO_InitTypeDef GPIO_InitStructure;

const uint16_t logval[1024]  __attribute__ ((section (".flash"))) = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 40, 40, 41, 41, 41, 42, 42, 42, 43, 43, 43, 44, 44, 45, 45, 45, 46, 46, 46, 47, 47, 48, 48, 48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 53, 53, 54, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 67, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72, 73, 73, 74, 75, 75, 76, 77, 77, 78, 79, 79, 80, 81, 81, 82, 83, 83, 84, 85, 85, 86, 87, 87, 88, 89, 90, 90, 91, 92, 93, 93, 94, 95, 96, 97, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107, 108, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 138, 139, 140, 141, 142, 143, 145, 146, 147, 148, 149, 151, 152, 153, 154, 156, 157, 158, 160, 161, 162, 164, 165, 166, 168, 169, 170, 172, 173, 175, 176, 178, 179, 180, 182, 183, 185, 186, 188, 190, 191, 193, 194, 196, 197, 199, 201, 202, 204, 206, 207, 209, 211, 213, 214, 216, 218, 220, 221, 223, 225, 227, 229, 231, 233, 235, 236, 238, 240, 242, 244, 246, 248, 250, 252, 255, 257, 259, 261, 263, 265, 267, 269, 272, 274, 276, 278, 281, 283, 285, 288, 290, 292, 295, 297, 300, 302, 305, 307, 310, 312, 315, 317, 320, 323, 325, 328, 331, 333, 336, 339, 342, 344, 347, 350, 353, 356, 359, 362, 365, 368, 371, 374, 377, 380, 383, 386, 389, 392, 396, 399, 402, 405, 409, 412, 415, 419, 422, 426, 429, 433, 436, 440, 443, 447, 451, 454, 458, 462, 466, 470, 473, 477, 481, 485, 489, 493, 497, 501, 505, 509, 514, 518, 522, 526, 531, 535, 539, 544, 548, 553, 557, 562, 566, 571, 576, 580, 585, 590, 595, 600, 605, 610, 615, 620, 625, 630, 635, 640, 645, 651, 656, 661, 667, 672, 678, 683, 689, 694, 700, 706, 712, 717, 723, 729, 735, 741, 747, 753, 760, 766, 772, 778, 785, 791, 798, 804, 811, 817, 824, 831, 838, 844, 851, 858, 865, 872, 879, 887, 894, 901, 909, 916, 924, 931, 939, 946, 954, 962, 970, 978, 986, 994, 1002, 1010, 1018, 1027, 1035, 1044, 1052, 1061, 1069, 1078, 1087, 1096, 1105, 1114, 1123, 1132, 1141, 1151, 1160, 1170, 1179, 1189, 1198, 1208, 1218, 1228, 1238, 1248, 1258, 1269, 1279, 1290, 1300, 1311, 1321, 1332, 1343, 1354, 1365, 1376, 1388, 1399, 1410, 1422, 1433, 1445, 1457, 1469, 1481, 1493, 1505, 1518, 1530, 1542, 1555, 1568, 1581, 1593, 1606, 1620, 1633, 1646, 1660, 1673, 1687, 1701, 1715, 1729, 1743, 1757, 1771, 1786, 1800, 1815, 1830, 1845, 1860, 1875, 1890, 1906, 1921, 1937, 1953, 1969, 1985, 2001, 2018, 2034, 2051, 2067, 2084, 2101, 2119, 2136, 2153, 2171, 2189, 2206, 2224, 2243, 2261, 2279, 2298, 2317, 2336, 2355, 2374, 2393, 2413, 2433, 2453, 2473, 2493, 2513, 2534, 2554, 2575, 2596, 2618, 2639, 2661, 2682, 2704, 2726, 2749, 2771, 2794, 2816, 2839, 2863, 2886, 2910, 2933, 2957, 2981, 3006, 3030, 3055, 3080, 3105, 3131, 3156, 3182, 3208, 3234, 3261, 3287, 3314, 3341, 3368, 3396, 3424, 3452, 3480, 3508, 3537, 3566, 3595, 3624, 3654, 3684, 3714, 3744, 3775, 3805, 3837, 3868, 3899, 3931, 3963, 3996, 4028, 4061, 4095};

// MACRO 

#define TOGGLES {				  \
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	trigd=0;				\
	for (j=0;j<8;j++){			\
	  if (!(GPIOB->IDR & (1<<2))) trigd++;	\
	}					\
	if (trigd>3) trigd=1;			  \
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	delay(); \
	if (trigd==1 && triggered[9]==0) triggered[9]=1; \
	if (!trigd && triggered[9]==1) breaker[9]++; \
	if (trigd && triggered[9]==1) breaker[9]=0; \
	if (breaker[9]>BRK8) { \
	  breaker[9]=0; \
	  triggered[9]=0; \
	  play^=1; \
	  if (rec && play) rec=0; \
	  	} \
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	trigd=0;				\
	for (j=0;j<8;j++){			\
	  if (!(GPIOB->IDR & (1<<10))) trigd++;	\
	}					\
	if (trigd>3) trigd=1;			  \
	GPIOC->BSRRH=(1)<<6; \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	delay(); \
	if (trigd==1 && triggered[8]==0) triggered[8]=1; \
	if (!trigd && triggered[8]==1) breaker[8]++; \
	if (trigd && triggered[8]==1) breaker[8]=0; \
	if (breaker[8]>BRK8) { \
	  breaker[8]=0; \
	  triggered[8]=0; \
	  rec^=1; \
	  if (play && rec) play=0; \
	} \
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	delay(); \
	trigd=0;				\
	for (j=0;j<8;j++){			\
	  if (!(GPIOB->IDR & (1<<6))) trigd++;	\
	}					\
	if (trigd>3) trigd=1;			  \
	GPIOC->BSRRH=(1)<<6;\
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	delay(); \
	if (trigd==1 && triggered[10]==0) triggered[10]=1; \
	if (!trigd && triggered[10]==1) breaker[10]++; \
	if (trigd && triggered[10]==1) breaker[10]=0; \
	if (breaker[10]>BRK8) { \
	  breaker[10]=0; \
	  triggered[10]=0; \
	  mode+=1; \
	 if (mode>=MAXMODES) mode=0; \
	}		 \
	}


void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}


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

extern __IO uint16_t adc_buffer[8];
static uint16_t recordings[8][7000]; // 
static uint16_t rec_cnt[8]={0};
static uint16_t play_cnt[8]={0};
static uint16_t tgr_cnt[10]={0};
static uint16_t rec=0, play=0;

//static uint16_t shifter[8]={2,2,2,2,1,1,1,1}; // shifter seperates vca from cv
static uint16_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
  {
    static uint16_t c=0;
    static uint16_t daccount=0;
    static uint16_t speed=1;
    volatile uint16_t k;
    uint16_t j,fing;
    // array to map freeze but exception is FR8 on PC4! 
    uint16_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    uint16_t bits;
    static uint16_t values[8], real[8];
    static uint16_t frozen[8]={0};
    static uint16_t lastrec=0, lastplay=0, lastvalue[8], added[8]={0}, lastmode=0;
    static uint16_t count=0, triggered[11]={0}, mode=0, starter[8]={0}, ender[8]={7000}, recsp[8]={0};
    static uint16_t lasttriggered[11]={0}, breaker[11]={0};
    
    uint16_t tmp, trigd;
    int16_t midder;
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	/*
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay

	if (!(GPIOB->IDR & (1<<6))) {
	  triggered[10]=1; // finger OFF is HIGH, finger ON is low
	  lasttriggered[10]=breaker[10];
	  breaker[10]=0;
	}
	else breaker[10]++;

	GPIOC->BSRRH=(1)<<6; //  LOW!

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	delay();
	
	if (triggered[10] && lasttriggered[10]>BRK8) { // 0 
	  mode^=1; // TEST
	}

	// for testing!
			
	GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low
       	if (mode)     DAC_SetChannel1Data(DAC_Align_12b_R, 2048); // 1000/4096 * 3V3 == 0V8
	else     DAC_SetChannel1Data(DAC_Align_12b_R, 0); // 1000/4096 * 3V3 == 0V8  // FINGER DOWN!
	j = DAC_GetDataOutputValue (DAC_Channel_1);
	GPIOC->BSRRL=(daccount)<<13; //  write DAC bits
    	    daccount++;
	    if (daccount==8) {
	      daccount=0;
	      count++;
	      	    }
	
*/

	
// mode selector is in TOGGLE MACRO
    
//    mode=0; // testings



    switch(mode){
    case 0: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage is only increasing? or full speed?
      // or no change of speed?

	/////// TOGGLING for freezers	
      
      if (daccount==7){

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay
      
	if (!(GPIOB->IDR & (freezer[7]))) {
	  triggered[7]=1; // finger OFF is HIGH, finger ON is low
	  lasttriggered[7]=breaker[7];
	  breaker[7]=0;
	}
	else breaker[7]++;

	
	GPIOC->BSRRH=(1)<<6; //  LOW!

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	delay();

	if (triggered[7] && lasttriggered[7]>BRK) { // 0 
	  frozen[7]^=1;
	}

	
      }
	// daccount==7
  else
    {
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // was Mode_IN!
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
      
	GPIOC->BSRRL=(1)<<6; //  HIGH!
	delay(); // seems to work with delay
      
	//	if (GPIOB->IDR & (freezer[daccount])) trigd=0;  // finger OFF
	//	else trigd=1; // finger ON
	if (!(GPIOB->IDR & (freezer[daccount]))) {
	  triggered[daccount]=1; // finger OFF is HIGH, finger ON is low
	  lasttriggered[daccount]=breaker[daccount];
	  breaker[daccount]=0;
	}
	else {
	  breaker[daccount]++;
	  if (breaker[daccount]>1024) breaker[daccount]=1024;
	}
	
	GPIOC->BSRRH=(1)<<6; //  LOW!

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // was Mode_IN!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	delay();

	if (triggered[daccount] && lasttriggered[daccount]>BRK) { // 0 
	  frozen[daccount]^=1;
	}
    }

      /////////
      
  if (frozen[daccount]==0) {
    ADC_SoftwareStartConv(ADC1);

    real[daccount]=adc_buffer[daccount]<<shifter[daccount];// shift a bit so louder now 10 bits for logval // was >>4; // 16 bits to 12 - but is it not 12 bits but aligned left
    if (real[daccount]>4095) real[daccount]=4095;

    // try another log!?
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
    
    GPIOC->BSRRH = 0b1110100000000000;  // clear bits -> PC11 - clear pc11 and top bits -> low

    DAC_SetChannel1Data(DAC_Align_12b_R, values[daccount]); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1);
    GPIOC->BSRRL=(daccount)<<13; //  write DAC bits
    
    daccount++;
    if (daccount==8) {
      daccount=0;
      count++;
   
      // speed increasing for playback ??? is this it?
      ADC_SoftwareStartConv(ADC1);
      speed=(adc_buffer[6]>>6); // how to handle freezes of speed and how to record speed - 12 bits to 4 bits
      if (speed>32) speed=32;
      speed=32-(speed); //4 bits=16 256/16=
      ///do toggles
      TOGGLES;      
    }       
          break; ///// case 0
	       
      
    } // end of modes switch    

    } 
  }
  
