/*

<--------------+-------^-------+-------<
               |       |       |       |
               |       |       |       |
               +-------+       +-------+

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

*at the moment we don't deal with fake CLKouts...*

  */ 

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
#include <math.h>
#include "resources.h"
#include "modes.h"

heavens gate[4]; 



static uint32_t count=0;
uint32_t neworder[4]={3,2,1,0}; // order backwards

uint32_t neworders[24][4]={
  {0,1,2,3},
  {0,1,3,2},
  {0,2,1,3},
  {0,2,3,1},
  {0,3,1,2},
  {0,3,2,1},
  {1,2,3,0},
  {1,2,0,3},
  {1,3,2,0},
  {1,3,0,2},
  {1,0,2,3},
  {1,0,3,2},
  {2,3,0,1},
  {2,3,1,0},
  {2,0,1,3},
  {2,0,3,1},
  {2,1,3,0},
  {2,1,0,3},
  {3,0,1,2},
  {3,0,2,1},
  {3,1,2,0},
  {3,1,0,2},
  {3,2,1,0},
  {3,2,0,1}  
};

// 1 means its used so do normed clocks - all one for testing
uint8_t strobey[4][64]={
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
};
  
#include "macros.h"

extern __IO uint16_t adc_buffer[12];
float LPF_Beta = 0.4; // 0<ß<1
uint32_t lookupadc[4]={0,3,9,6}; // CVs for speed to use in INTmodes and other modes
uint32_t dacroute[4]={2,3,3,1}; // DAC routing for probability modes etc...

#define FULL 0b11111111111111111111111111111111 //32 bits full
#define MAXVALUE 4095
#define SMOOTHINGS 512 // we can hold 65536 of our 16 bit ADC values...speed
uint32_t cc=0, totc=0, smoothc[SMOOTHINGS];
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS];
uint32_t rr=0, totr=0, smoothr[SMOOTHINGS];
uint32_t nn=0, totn=0, smoothn[SMOOTHINGS];

uint16_t mode[4]={0,0,0,0};
uint8_t clkr=7;
uint16_t lastmodec, lastmoden, lastmodel, lastmoder;
uint16_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;
//uint16_t whichDAC=2;

volatile uint32_t intflag[4]={0,0,0,0}; // interrupt flag...
volatile uint32_t param[4]={0,0,0,0}; // interrupt flag...
uint32_t SRlength[4]={31,31,31,31};

uint16_t ADCLR[3]={29,30,31}; // non-adc ADC modes - this has changedDONE

uint32_t s[4]={0,0,0,0};
uint32_t ss[4]={0,0,0,0};
uint32_t clksr_[4]={0,0,0,0};

// for generic CLK fake puls routing
//LSRCLK-pulse9=PB12, RSRCLK-pulse10=PB13, CSRCLCK-pulse11=PB14
// 000,001,010,011,100,101,110,111
static uint32_t clk_route[8]={0,
			      (1<<12),
			      (1<<13),
			      (1<<12) | (1<<13),
			      (1<<14),
			      (1<<12) | (1<<14),
			      (1<<14) | (1<<13),
			      (1<<12) | (1<<13) | (1<<14)
};

static uint32_t LFSR_[4]={0xf0fff,0xf0ff,0xff00f,0xff};
static uint32_t shift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t mask[4]={0,0,0,0};
static uint32_t ADCshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t ADCGshift_[4]={0xffff,0xffff,0xffff,0xffff};

static uint32_t GGshift_[4][4]={ // for freezers
 {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff}
};

static uint32_t storedlength[4][4]={
  {31,31,31,31},
  {31,31,31,31},
  {31,31,31,31},
  {31,31,31,31}
};

static uint32_t GGGshift_[4]; // gshift is 4 even though we don't use one // GG is ghost in ghost

// and cycling/circling array of ghosts which can come back or go forwards/backwards - when these ghosts are copied over (on event)
// with 256 cycles/copies - or we can have variable length of this shifting array

static uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0}, Gshift_revrevcnt[4]={0,0,0,0};

// so for simple pass through by speed would be: speedfrom=0/inputbit=2/adctype=0/route=last one as bit/
//uint32_t speedfrom[4]={0,0,0,0}; //0 is CV, 1 is interrupt, 2 is DACspeedfrom_ + CV // unused so far...
uint32_t speedfrom_[4]={3,3,3,3}; // who we get dac speed offset from?
uint32_t inputbit[4]={0,2,2,2}; //0-LFSR,1-ADC,2-none
uint32_t LFSR[4]={3,3,3,1}; // which SR take the LFSR bits from! default is from itself - but could be opposites eg. {2,3,0,1}
uint32_t adctype[4]={0,0,0,0}; // 0-basic, 1-one bit
uint32_t dactype[4]={66,66,0,66}; // 0-basic, 1-equiv bits, 2-one bit - 66 is new default one for all except out
uint32_t doit[4]={1,0,0,0}; // covers what we do with cycling bit - 0 nada, 1=invert if srdacvalue[x]<param// param is 12 bits - can be other options
uint32_t whichdoit[4]={8,8,8,8}; // dac from???

uint32_t route[4]={8,1,2,1}; // route[4]={1,9,9,9}; NLCR=1248 0->15 binary routing table
uint32_t defroute[4]={3,0,1,0}; // 0,1,2,3 NLCR - not binary code but just one!
//uint32_t defroute[4]={0,0,0,0}; // 0,1,2,3 NLCR - not binary code but just one!
//uint32_t prev[4]    ={3,0,1,0}; // previous
uint32_t revroute[4]={1,2,3,0}; // 0,1,2,3 NLCR - reverse route
uint32_t defroutee[4]={3,0,1,1}; // 0,1,2,3 NLCR - in this one 3 routes from 1 too
uint32_t altroute[4]={3,0,0,1}; // 0,1,2,3 NLCR - not binary code but just one! // N->C, N->L, L->R, R->N = 
//uint32_t reggs[4]={3,3,3,3}; // take DACs all from last feedback reg
uint32_t reggg=0;
uint32_t ourroute[4]={0,0,0,0};

// can also have array of binary or singular routing tables to work through:
// these could also be 4x4 = 16 bit values... as maybe easier to decode...
uint32_t binroute[16][4]={ // add more routes, also what seq change of routes makes sense now we have 16 routes
        {8,1,2,1}, // default
	{8,1,2,2}, // expanding
	{8,1,2,4}, // expanding
	{8,1,2,8}, // expanding
	{8,1,2,9}, // expanding
	{8,1,2,11}, // expanding
	{8,1,2,12}, // expanding
	{8,1,2,4}, // route in one big circle
	{0,1,2,4},
	{9,3,6,9}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
	{1,2,4,8}, // only loop - this is what is added to get loop too for prob
	{8,1,2,2}, // as defroutee 3/0/1/1
	{8,1,1,2}, // as altroute 3/0/0/1
	{8,9,1,2}, // bounce L and R back and forth
	{8,1,2,5}, // others
	{2,4,8,1}, // reverse round route
};

// can also have lists for each one to bump along
uint32_t myroute[4][16]={
  {8, 4, 2, 1,  9, 5, 3, 1,  2, 4, 8, 1,  3, 5, 9, 1},
  {1, 8, 4, 2,  3, 10, 6, 2,  4, 8, 1, 2,  6, 10, 3, 2},
  {2, 1, 8, 4,  6, 5, 12, 4,  8, 1, 2, 4,  12, 5, 6, 4},
  {4, 2, 1, 8,  12, 10, 9, 8,  1, 2, 4, 8,  9, 10, 12, 8}
};

//uint32_t binroutex[8]={4632, 38457, 33825, 8728, 8472, 8600, 21016, 6210}; // above routes generated by test.c as sets of 4 bits values with first route as lowest 

uint32_t singroute[4][4]={ // singular table for single routes - old prob modes
  {3,0,1,0},
  {3,0,1,1},
  {3,0,0,1},
  {3,0,2,1}
};
  
uint32_t dacfrom[4]={0,0,0,0};
uint32_t sieve[4]={3,3,3,3}; // previous one... - changed to R 21/12/2021
uint32_t oppose[4]={2,3,0,1};

static uint32_t prev_stat[4]={0,0,0,0};
static volatile uint32_t CV[4]={0,0,0,0};
static volatile float speedf_[4]={0,0,0,0};

volatile uint32_t dac[4]={0,0,0,0};
volatile uint32_t adc_[4]={0,0,0,0};
uint32_t counter_[4]={0,0,0,0};
static uint32_t pulsins[4]={0,1<<8,0,1<<7}; //N,L,C,R
static uint32_t LR[4]={0,1,0,1};
static uint8_t flipd[4]={0,0,0,0};
static uint16_t pulsouts[8]={0, 0,  1<<2, 1<<15, 1<<4, 1<<12, 1<<3, 1<<11};

volatile uint16_t *pulsoutHI[8]={&(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOC->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL) };
//                                  0              0              PB2                PC15           PB4               PA12           PB3                PA11 
volatile uint16_t *pulsoutLO[8]={&(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOC->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH) }; // both are 16 bit registers

int32_t oldValue, integrator, k, bt;

static uint32_t counter[7]={0,0,0,0, 0,0,0};  // last 3 for fake clks


// new speed stuff

#define DELAY_SIZE 6 // was 40 --- 3*width=16 = 3*16=48-5=43 - use 7 for simplea
static int32_t delay_buffer[4][2] = { 0 }; // was 48 but it doesn't need to be so big

void new_data(uint32_t data, uint32_t ww)
{
  //    for (u8 ii=0;ii<DELAY_SIZE-5;ii++)	
  delay_buffer[ww][0] = delay_buffer[ww][1];
    delay_buffer[ww][1] = data;
}

#include "adcetc.h" // now all of the other functions so can work on modes
#include "modeN.h"
#include "modeL.h"
#include "modeR.h"
#include "modeC.h"


void testnull(void){
}

uint32_t testmodes[4]={0,0,0,0};


// we list our modes here...
void (*dofunc[4][64])(void)=
{
  {Ndacghostitself0, N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12, N13, N10, N11, N12, N13, N14, N15, N16, N17, N18, N19, N20, N21, N22, N23, N24, N25, N26, N27, N28, N29, N30, N31, N32},
  {L0, L2, L0},
  {C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15},
  {R0, R0, R1}
};

void mode_init(void){
  uint32_t y;

  gate[0].shift_=0x15;
  gate[1].shift_=0x15;
  gate[2].shift_=0x15;
  gate[3].shift_=0x15;
  
  gate[0].adctype=0;

  gate[2].dactype=0; // set for out
  gate[1].dactype=66; // default simpler version
  gate[3].dactype=66;
  gate[0].dactype=66;  
}


void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  uint32_t tmp;
  static uint32_t flipper[4]={1}, www=0, kk=0;

  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed
  
  // for the time between counts
  counter_[0]++;  counter_[1]++;  counter_[2]++;  counter_[3]++;
  
  www++;
  if (www>3) {
    www=0;
  }

  if (intflag[www]) { // process INT
    gate[www].trigger=1;
    intflag[www]=0;
    clksr_[www]=(clksr_[www]<<1)+1;     // shift on to CLKSR
  }
  else  {
    gate[www].trigger=0;
    clksr_[www]=(clksr_[www]<<1);
  }
  // genericLFSR for all probability modes
  tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 29) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 29, 25, 24
  LFSR_[www] = (LFSR_[www]<<1) + tmp;

  // do the modes
  
  mode[www]=testmodes[www];
  //  mode[1]=0;mode[2]=0;mode[3]=0; // test adc mode 0
  //    mode[0]=0;mode[1]=0;mode[3]=0; // test dac
  //
  //      if (mode[2]>15) mode[2]=15;
  //    (*gate[www].dofunc[mode[www]])();
      //      mode[2]=5;
  (*dofunc[www][mode[www]])();
  
  // this runs at full speed? - can also be in functions/modes // do we have option to have another DAC out?
  if (www==2)  {
    //    kk^=1; // test code
    //    if (kk)    gate[2].dac=4095;
    //    else gate[2].dac=0;
    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8 
    int j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }

  // DAC for normed NSR/PWM
  if (www==3 && strobey[0][mode[0]]){
      tmp= gate[3].dac; // right hand
      tmp+=320; 
      TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
      TIM1->CCR1 = tmp/2; // pulse width
  }
  else // we need to test this
    {
      TIM1->ARR =0; 
      TIM1->CCR1 = 0;
    }
  // else we need to generate 0 pulse/
  // TESTY with INTmodes
      
      if (counter[4]>gate[3].dac){ // L side
	counter[4]=0;
	if (strobey[1][mode[1]]){
	flipper[0]^=1;
	if (flipper[0]) GPIOB->BSRRH = clk_route[1];  // clear bits of fake_one
	else   GPIOB->BSRRL=clk_route[1]; //  write bits
	}
      }      

      if (counter[5]>gate[1].dac){ // R side
	counter[5]=0;
	if (strobey[3][mode[3]]){
	flipper[1]^=1;
	if (flipper[1]) GPIOB->BSRRH = clk_route[2];  
	else   GPIOB->BSRRL=clk_route[2]; //  write bits
      }      
      }
      /*
      if (counter[2]>(gate[3].dac)){ // now trying DAC 29/12/2021 - // C side!
	counter[2]=0;
	flipper[2]^=1;
	if (flipper[2]) GPIOB->BSRRH = clk_route[4];  
	else   GPIOB->BSRRL=clk_route[4]; //  write bits
	}
      */

      // trial just using lowest bit 30/12/2021 ??? TEST???? C side
      // - DONEtrial of another approach to fake clocks (but would be better as own ghosts???) - NOTEfrom segmodes but not sure what that means?
            if (strobey[2][mode[2]]){
	      if ((gate[3].shift_>>SRlength[3])&0x01) GPIOB->BSRRH = clk_route[4];
	      else GPIOB->BSRRL=clk_route[4]; //  write bits
	    }
      
      counter[4]++; counter[5]++; counter[6]++;

}
 
