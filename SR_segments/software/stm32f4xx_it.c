/*
0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  1  1  1  1  1  1  1  1  1  1  1  
0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0  
0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  
1  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  0  0  1  1  1  1  0  1  1  
1  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  1  0  0  1  1  1  1  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  0  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  1  
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  1  1  1  
0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  1  1  0  0  0  0  1  1  1  1  1  1  1  0  0  
1  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  0  1  0  
1  0  0  0  0  0  0  0  1  0  1  1  1  1  1  1  1  1  1  1  1  0  0  0  1  1  0  0  0  0  1  0  
1  0  0  0  0  0  0  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  0  
1  0  0  0  0  0  0  0  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  1  1  1  0  0  1  1  1  1  
  */ 

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

/////////////////////
extern __IO uint16_t adc_buffer[12];

volatile uint32_t shift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff;
volatile uint32_t shift_registerr=0xff;
volatile uint32_t shift_registerc=0xff; 

// ghosts, revenants
volatile uint32_t Gshift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t Gshift_registerl=0xff;
volatile uint32_t Gshift_registerr=0xff;
volatile uint32_t Gshift_registerc=0xff; 

volatile uint32_t bitn, bitl, bitr, bitc=0;
volatile uint32_t moden, model, moder, modec=0;
volatile uint32_t speedn, speedl, speedr, speedc=0;
volatile uint32_t countern, counterl, counterr, counterc=0;
volatile uint32_t SRlengthn=31, SRlengthl=31, SRlengthr=31, SRlengthx=31, lengthbitn=15, Slengthbitl=15, lengthbitr=15, Slengthbitc=15;

// and also need counters for "cogs"
volatile uint32_t coggn, coggl, coggr, coggc=0;

// experimental parallel SR
uint32_t shift_registerpar[32]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

// from AC
static uint32_t electroprob[8]={0, 3, 7, 15, 31, 63, 127, 255};

static uint32_t bits[8]={1, 2, 4, 8, 16, 32, 64, 128};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 

static uint8_t bitsz[256]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

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

static uint8_t ghost_tapsH[32][4] = {
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

static uint8_t ghost_tapsL[32][4] = {
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

///////////////////////////////////////////////////////////////////////// 

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

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
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

// TEST: inpulse interrupts to attach are: CSR: PC3nowPB7, NSR: PC4, RSR: PC5, LSR: PB6

void EXTI4_IRQHandler(void){ // working NSR
  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  
  // flip PB4 to test interrupt on NSR PC4
    flipper^=1;
    //    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    //    else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  // added PB7 now for CSRCLKIN CSR which moved from PC3!!!

  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line5) != RESET) {

  // CSR: PC3->now PB7, NSR: PC4, RSR: PC5, LSR: PB6
  
  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  EXTI_ClearITPendingBit(EXTI_Line5);
 }

 if (EXTI_GetITStatus(EXTI_Line6) != RESET) {

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {

  // flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line7);
 } 

}

#define MAXVALUE 4095

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static volatile uint16_t k=0,ll=0, n=0, accum, cnt=4;
  static volatile int16_t integrator=0, oldValue=0, tmp=0;
  uint16_t j, bit;
    //low pass test
  static float SmoothData=0.0;
  float LPF_Beta = 0.02; // 0<ß<1
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

    // TODO 16/7/2021: test simple delta/sigma ADC and DAC (first bits say on PB4 then low pass) out
    // concept works fine...DONE

    // map ADCs: note all modes are inverted

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode
    // 9: cspd, 10: , 11: cmode

  // test speed for all - from cspd
  counterc++;
  speedc=adc_buffer[9]<<4; // ??? and smoothings/logger but just test here
  // can also be with modes in another interrupt
  if (counterc>speedc){
    counterc=0;
  
  ///////////////////////////////////////////////////////
  // from late July 2021 test sketches which show directions rather than full framework

  ///////////////////////////////////////////////////////
  // test with SR in SR for digital filter simulator - works with simple pass through
  // how we could simplify with more arrays, masks?
  // how we can substitute leaky logic for logic ops

  // 4 bits go into NSR as in original AC and are shifted
  // can also be feedback so is micro-SR in largerSR
  k=(adc_buffer[12])>>8;//+tmp)>>8; // now 12 bits only -> 4 bits
  // copy into ghost reg so we can feedback bits if we like
  Gshift_registern=shift_registern;
  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in
  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
  shift_registern=(shift_registern<<1); // here or later/earlier?
  
  // 4 bits into LSR
  shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  // test feeding back some of the bits
  shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
  //  shift_registerl += (((shift_registern&(1<<7))>>7) ^ ((shift_registerl&(1<<7))>>7)  ) + (((shift_registern&(1<<15))>>7) ^ ((shift_registerl&(1<<15))>>7)) + (((shift_registern&(1<<23))>>7) ^ ((shift_registerl&(1<<23))>>7)) + (((shift_registern&(1<<31))>>7) ^ ((shift_registerl&(1<<31))>>7));

  shift_registerl=(shift_registerl<<1); // here or later/earlier?
  
  // 4 bits into CSR and out
  shift_registerc &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  shift_registerc += (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>7) + ((shift_registerl&(1<<23))>>7) + ((shift_registerl&(1<<31))>>7));
  shift_registerc=(shift_registerc<<1); // here or later/earlier?

  // output it! 
  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8;
  //  tmp=rand()%4095;

  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  /////
  } // close of speedc
  
  ///////////////////////////////////////////////////////
  // test for parallell SR in top NSR
  ///////////////////////////////////////////////////////

  
    ///////////////////////////////////////////////////////
  // test for x(say 4) ADC bits in spaced out, feed through and DAC out, to lead towards digital filter simulation
  // not really working but kind of interesting - question is order of bits, also return of bits

  // sr in sr, parallel SR, feedback as bits or as addition into ADC in from DAC
  /*
  if (cnt==4){
  k=(adc_buffer[12])>>8; // now 12 bits only -> 4 bits
  cnt=0;
  // out - question is what is order of first bit? and return of bits
  }
  */
  /*  // can also be just 4 simple bits eg.
  k=(adc_buffer[12])>>4; // 8 bits
  if (k<64) tmp=1;
  else if (k<128) tmp=3;
  else if (k<192) tmp=7; // these values can also shift
  else tmp=15;

  // how to do as 4 independent bits ie. number of bits is the important thing - more about dac out from this one as is same no?
  */
  /*
  bitn = (shift_registern>>31) & 0x01; // bit which would be shifted out
  shift_registern=(shift_registern<<1); // here or later?
  shift_registern+=((k&(1<<cnt))>>cnt);// ^ bitc;
  */
  /* // older not workings
  // try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in
  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
  // without clearing bits is interesting also we can have other options like delay of some bits which would happen anyways
  // eg. sample and then put bit in one by one
  */
  
  // pass to shiftregl
  /*
  bitl = (shift_registerl>>31) & 0x01; // bit which would be shifted out
  shift_registerl=(shift_registerl<<1)+bitn;

  // pass to shiftregc
  bitc = (shift_registerc>>31) & 0x01; // bit which would be shifted out
  shift_registerc=(shift_registerc<<1)+bitl;

  tmp= ( (shift_registerc&1) + (shift_registerc&(1<<1)) + (shift_registerc&(1<<2)) + (shift_registerc&(1<<3)))<<8; 
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
 
  
  cnt++;
  */
  
  // and output
  //  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8; // much further bits  // msb first
  //  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
 //  tmp= (((shift_registerc&(1<<7))>>4) + ((shift_registerc&(1<<15))>>13) + ((shift_registerc&(1<<23))>>22) + ((shift_registerc&(1<<31))>>31))<<8; // much further bits
      
  ///////////////////////////////////////////////////////

    
    /* test for sigma/delta
    
  n++;
  if (n>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     //     GPIOB->BSRRL=(1)<<4; //  write bits 
     bit=4095;
  }
   else
   {
      oldValue=0;
      //      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
      bit=0;
   }
  
   // low pass to our DAC!
   SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit));
   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

    */
   
}
