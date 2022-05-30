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
#include "stdlib.h"
#include <math.h>
#include "resources.h"
#include "modes.h"

static heavens gate[9]; // for paralell SR doubled + tail

static uint32_t binary[9]={0,0,0,0}; // binary global routing

#define LOWEST 0.000063f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022

static uint32_t count=0;
static uint32_t daccount=0;
static uint32_t spdcount=0;

// 1 means its used so do normed clocks - all one for testing
// replace this with just strobed set by mode/function itself and then passed to final part for normed clocks
uint8_t strobey[4][64]={
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
};

#include "macros.h"

//extern __IO uint16_t adc_buffer[13];

#define FULL 0b11111111111111111111111111111111 //32 bits full
#define HALB 0b10101010101010101010101010101010 //32 bits 1010
#define MAXVALUE 4095
#define SMOOTHINGS 512 // we can hold 65536 of our 16 bit ADC values...speed
uint32_t cc=0, totc=0, smoothc[SMOOTHINGS];
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS];
uint32_t rr=0, totr=0, smoothr[SMOOTHINGS];
uint32_t nn=0, totn=0, smoothn[SMOOTHINGS];
uint32_t mde;

uint16_t mode[4]={0,0,0,0};
uint16_t lastmode[4]={1,1,1,1};
uint8_t clkr=7;
uint16_t lastmodec, lastmoden, lastmodel, lastmoder;
uint16_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;
//uint16_t whichDAC=2;

volatile uint32_t intflag[4]={0,0,0,0}; // interrupt flag...
volatile uint32_t param[4]={0,0,0,0}; // interrupt flag...
uint32_t SRlength_[9]={31,31,31,31,31,31,31,31,31};
uint32_t SRlength[9]={31,31,31,31,31,31,31,31,31};

uint32_t clksr_[4]={HALB,HALB,HALB,HALB};
uint32_t clksrG_[4]={0,0,0,0};
 

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
static uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0}, Gshift_revrevcnt[4]={0,0,0,0};

uint32_t inputbit[4]={0,2,2,2}; //0-LFSR,1-ADC,2-none
uint32_t adctype[4]={0,0,0,0}; // 0-basic, 1-one bit
//uint32_t dactype[4]={66,66,66,66}; // 0-basic, 1-equiv bits, 2-one bit - 66 is new default one for all except out
uint32_t doit[4]={1,0,0,0}; // covers what we do with cycling bit - 0 nada, 1=invert if srdacvalue[x]<param// param is 12 bits - can be other options
uint32_t whichdoit[4]={8,8,8,8}; // dac from???

uint32_t route[4]={8,1,2,1}; // route[4]={1,9,9,9}; NLCR=1248 0->15 binary routing table
uint32_t defroute[4]={3,0,1,0}; // 0,1,2,3 NLCR - not binary code but just one!
uint32_t revroute[4]={1,2,3,0}; // 0,1,2,3 NLCR - reverse route
uint32_t defroutee[4]={3,0,1,1}; // 0,1,2,3 NLCR - in this one 3 routes from 1 too
uint32_t altroute[4]={3,0,0,1}; // 0,1,2,3 NLCR - not binary code but just one! // N->C, N->L, L->R, R->N = 
uint32_t reggg=0;
uint32_t ourroute[4]={0,0,0,0};

// can also have array of binary or singular routing tables to work through:
// these could also be 4x4 = 16 bit values... as maybe easier to decode...
uint32_t binroute[17][4]={ // add more routes, also what seq change of routes makes sense now we have 16 routes
    {8,1,2,4}, // new default: 8 1 2 4 // default was 8121 // now we have full route 8124
  //  {0,0,1,0}, //  test
	{8,1,2,2}, // notexpanding
	{8,1,2,1}, // notexpanding
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
    {0,0,0,0} // drop all routes
}; // TODO: add 8,1,1,1 and different expansions so could be 32 of these

uint32_t inroute[16][4]={ // who we have main incoming route from 0-3 - from above
        {3,0,1,2}, // default 8121 // now 8124
	{3,0,1,1}, // expanding
	{3,0,1,2}, // expanding
	{3,0,1,3}, // expanding
	{3,0,1,3}, // expanding
	{3,0,1,1}, // expanding
	{3,0,1,2}, // expanding
	{3,0,1,2}, // route in one big circle	
	{0,0,1,2},
	{3,2,2,0}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
	{0,1,2,3}, // only loop - this is what is added to get loop too for prob
	{3,0,1,1}, // as defroutee 3/0/1/1
	{3,0,0,1}, // as altroute 3/0/0/1
	{3,3,0,1}, // bounce L and R back and forth
	{3,0,1,2}, // others
	{1,2,3,0}, // reverse round route
}; // TODO: add 8,1,1,1 and different expansions so could be 32 of these

uint32_t routeto[16][4]={ // as above but who we route TO! and as single routes - first one/major
  {1,2,2,0}, // default 8121
  {1,2,2,0}, // expanding
  {1,2,3,0}, // expanding ok
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,2,0}, // expanding
  {1,2,3,0}, // route in one big circle
  {1,2,3,3},
  {1,2,2,1}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
  {0,1,2,3}, // only loop - this is what is added to get loop too for prob
  {1,2,3,0}, // as defroutee 3/0/1/1
  {1,3,2,0}, // as altroute 3/0/0/1
  {1,4,3,0}, // bounce L and R back and forth
  {1,3,3,0}, // others
  {3,0,1,2}, // reverse round route
}; 

uint32_t dacfrom[16][4]={ // TODO and needs to match lengthy of binroute TEST!  and also relate to binroute // or use different count
  {3,3,3,1}, // default
  {1,3,1,1}, // new one for rungling 24/1/2022
  {3,0,1,2}, // from latest notebook prev ones: 3,0,1,2
  {0,1,2,3}, // itself
  {3,2,1,0}, // reverse
  {3,3,3,3},
  {2,2,2,2},
  {1,1,1,1},
  {3,3,1,1},
  {1,1,3,3},
  {2,3,0,1}, // opposites
  {1,0,3,2},
  {1,2,3,0}, // nexts
  {3,2,1,0}, /// rev
  {1,3,1,1},
  {1,3,1,1}
};

uint32_t speedfrom[16][4]={ // now for speedfrom just copied from above! TODO: changing: synced speeds...
  {3,0,0,0}, // default
  {0,0,0,0}, // synced...
  {1,1,1,1}, // synced...
  {2,2,2,2}, // synced...
  {3,3,3,3}, // synced...
  {0,1,2,3}, // itself...
  /*  
  {1,3,1,1}, // new one for rungling 24/1/2022
  {3,0,1,2}, // from latest notebook prev ones: 3,0,1,2
  {0,1,2,3}, // itself
  {3,2,1,0}, // reverse
  {3,3,3,3},
  {2,2,2,2},
  {1,1,1,1},
  {3,3,1,1},
  {1,1,3,3},
  {2,3,0,1}, // opposites
  {1,0,3,2},
  {1,2,3,0}, // nexts
  {3,2,1,0}, /// rev
  {1,3,1,1},
  {1,3,1,1}*/
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
  
uint32_t sieve[4]={3,3,3,3}; // previous one... - changed to R 21/12/2021
uint32_t oppose[4]={2,3,0,1};

static uint32_t train[4]={0,0,0,0};

static uint32_t prev_stat[4]={0,0,0,0};
static uint32_t CV[4]={0,0,0,0};
static uint32_t CVL[4]={0,0,0,0};
static uint32_t CVM[4]={0,0,0,0};
static volatile float speedf_[9]={1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f,1.0f,1.0f};
static volatile float speedf[9]={1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f};

uint32_t counter_[4]={0,0,0,0};

static uint32_t pulsins[4]={0,1<<8,0,1<<7}; //N,L,C,R
static uint32_t pulse[4]={0,1,0,1};
static uint32_t LR[4]={0,1,0,1};
static uint8_t flipd[4]={0,0,0,0};
static uint16_t pulsouts[8]={0, 0,  1<<2, 1<<15, 1<<4, 1<<12, 1<<3, 1<<11};

static uint8_t defdac=3;

volatile uint16_t *pulsoutHI[8]={&(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOC->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL) };
//                                  0              0              PB2                PC15           PB4               PA12           PB3                PA11 
volatile uint16_t *pulsoutLO[8]={&(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOC->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH) }; // both are 16 bit registers

//int32_t oldValue, integrator, k, bt;

static uint32_t counter[7]={0,0,0,0, 0,0,0};  // last 3 for fake clks
static uint32_t counterd[4]={0,0,0,0};  // extra counter
static uint32_t counterr=0, counterl=0;

#define DELAY_SIZE 6 // was 40 --- 3*width=16 = 3*16=48-5=43 - use 7 for simplea
static int32_t delay_buffer[9][2] = { 0 }; // was 48 but it doesn't need to be so big

static inline void new_data(uint32_t data, uint32_t ww)
{
  delay_buffer[ww][0] = delay_buffer[ww][1];
    delay_buffer[ww][1] = data;
}

uint32_t options[4][24]={
      {1,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 0,3,3},
      {0,3,3, 2,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 1,3,3},
      {0,3,3, 1,3,3, 3,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 2,3,3},
      {0,3,3, 1,3,3, 2,3,3, 0,1,3, 0,2,3, 2,1,3, 0,1,2, 3,3,3}
    };

static uint32_t resetz=1;

// extra files to check...

#include "gen.h" // new generators
#include "adcetc.h" // now all of the other functions so can work on modes

//#include "modeN.h"
//#include "modeL.h"
//#include "modeR.h"
//#include "modeC.h"
//#include "probability.h" // probability modes

#include "basis.h" // basics from commented ones just to speed up tests
#include "experiment.h" // more functional modes - can also shift some things here... trials
//#include "bit.h" // bitmodes but some are still in modeL
#include "rungler.h"

void testnull(void){
}

uint32_t testmodes[4]={0,0,0,0};

// collect modes: Lmultiplespeednew // tag modesx modex
void (*dofunc[4][64])(uint8_t w)=
{
  {SRrunggenericbitsadc}, // 7 // binroute type not so important here
  {SRrunggenericbits}, // SRX0 is basic route/xor // 25 prob modes
  {SRrungout}, 
  {SRrunggenericbits}
};

void (*funcgroups[4][64])(uint8_t w)=
{
  {adc0, SRrunggenericbitsadc, SRrunghead0N, adcLrung0, adcLrung1, adcLrung2,   adcrung0, adcLbinprob, noSRadc2s, noSRadc2s,adcLabstractLD, stream4_unshare}, 
  {SR_layer1, SRrunggenericbits, SRrunghead0L, SRrung0,   SRrung1,   SRrung2, SRrung3,  adcLbinprob, SRshroute, noSRcopy, adcLabstractLD, stream4_unshare}, 
  {dac0, SRrunggenericbits, SRrungout, dacLrung0, dacLrung0, dacNLRin,dacNLRinlogic, adcLbinprob, dac2,noSRdac2s,dacNLRprobin,   stream4_unshare}, // dacNLRprobinINT1311
  {SR5_feedback, SRrunggenericbits, SRrungbody0, SRRrung0, SRRrung1, SRRrung2,SRRrung3,     adcLbinprob, SRX0,     SRX0,adcLabstractLD, stream4_unshare}
}; // 12 so far

void mode_init(void){
  uint32_t x;
  
  for (x=0;x<4;x++){
    gate[x].delcnt=0;
    gate[x].changed=0;
    gate[x].paramx=0;
    gate[x].shift_=0x15;
    gate[x].Gshift_[0]=0;
    gate[x].Gshift_[1]=0;
    gate[x].Gshift_[2]=0;
    gate[x].Gshift_[3]=0;
    gate[x].reset[0]=0;
    gate[x].reset[1]=0;
    gate[x].reset[2]=0;
    gate[x].reset[3]=0;

    gate[0].gsrcnt[x]=31;
    gate[1].gsrcnt[x]=31;
    gate[2].gsrcnt[x]=31;	
    gate[3].gsrcnt[x]=31;
  }
  
  gate[0].adctype=0;

  gate[0].dactype=67;
  gate[1].dactype=67; // default simpler version - now 4 bit version 
  gate[2].dactype=0; // set for out
  gate[3].dactype=67;
  gate[8].dactype=67;  
}


void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static uint32_t flipper[4]={1}, www=0, kk=0;
  uint32_t tmp;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed
  //////////////////////////////////////////////////////
  
  www++;
  if (www>3) {
    www=0;
    resetz=1;
  }
  
  if (intflag[www]) { // process INT
    gate[www].trigger=1;
    intflag[www]=0;
    clksrG_[www]=clksr_[www]; // copy in to ghost
    tmp=(clksr_[www]>>31)& 0x01; // length is 31
    clksr_[www]=(clksr_[www]<<1)+tmp;     // shift round CLKSR - we can also insert in/copy in
  }
  else  {
    gate[www].trigger=0;
    //    clksr_[www]=(clksr_[www]<<1); 
  }

  // genericLFSR for all probability modes
  tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 19) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 19, 25, 24
  LFSR_[www] = (LFSR_[www]<<1) + tmp;

  /*
    mde=mode[3];
  if (mde>11) mde=11; // 12 groups so far
  (*funcgroups[www][mde])(www);
  */   

  // trial here different version of Vienna with interpoll and new bit recurse options
  // do as a a function

  major_vienna(www);
  
  if (www==2)  {
      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
      }
      
      counter[4]++; counter[5]++; counter[6]++;
      counter[0]++; counter[1]++; counter[2]++; counter[3]++;
      counterd[0]++; counterd[1]++; counterd[2]++; counterd[3]++;
      counterl++; counterr++;

}
 
