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


uint32_t funccmax[64][9]={
  {8,2,17,61,23}, // maximum value if x>funcmax... // update these as we add more functions
};

uint32_t cvmax[64][10]={
  {19,19,19,19,19,19,19,19,19,19}, // update for max number of cv options
};

//fspeed, flength, fadc, fbit, fdac,  fnew, fout, gs, out // fnew is parameter function // fout outside
//1       2        3     4     5     6     7     8   9

//basic but remeove adc
//out and fout mixed up in comments

//{1, 1, 1, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'zadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
//{5, 0, 6, 0, 0, 8, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
/*
uint32_t funcNN[64][9]={
  {1, 1, 21, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'zadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
  {1,1,18,2, 0,0,0,0,0}, //  - 18 is select adc with CVM // 20 is new prob test on CVL select on CVM
  {2,0,18,0, 0,0,0,0,0},
};

uint32_t funcLL[64][9]={
  {1, 1, 0, 2, 0, 2, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero'] // altering some
  {1,1,0,1, 0,0,0,0,0}, // 
  {2,0,0,59,0,0,0,0,0},
};

uint32_t funcCC[64][9]={
  //  {1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {1, 1, 0, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero'] // altered for delaylineIn and OUT
  {1,1,0,1, 26,0,0,0,0}, //  - 11 is select speed with CVM 26 dac with cvm
  {1,1,0,60, 0,0,0,0,0}, // rung - speed from cv, route from R //
};

uint32_t funcRR[64][9]={
  {1, 1, 0, 2, 0, 0, 0, 0, 0}, //['spdfrac2', 'rlen', 'noadcx', 'binroutfixed', 'ddac0', 'zero', 'vgen', 'gshift0', 'OUT_zero']
  {1,1,0,1, 0,0,0,0,0}, // 
  {2,1,0,61,0,0,0,0,0}, // route from L, speed from N
};
*/
// cvspeed, cvspeedmod, cvlength, cvdac, cvadc, cvadcIN,  cvbit, cvbitcomp, cvnew, cvout
// 1        2            3         4      5       6        7      8          9      10  

// 0 null 1 0dac 2 1dac 3 2dac 4 3dac 5 CV 6 CVL 7 CVM 8 ADCin 9 Gs0 10 Gs1 11 Gs2 12 Gs3 13 clksr_ 14 param 15 par 16 oldcv 17 oldcvl 18 oldcvm
/*
uint32_t cvNN[64][10]={
  {5, 0, 6, 0, 6, 8, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,0,6,0,6,8, 0,0,0,0}, // 8 is ADC itself IN
  {5,6,6,0,6,8,6,7,0,0},
};

uint32_t cvLL[64][10]={
  {15, 0, 6, 0, 0, 0, 0, 0, 7, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null'] // altering some
  {5,0,6,0,6,0,4,0,0,0},
  {5,6,6,0,6,0,6,7,0,0}, // rung2 but modded...
};

uint32_t cvCC[64][10]={
  //{1,1,0,2,1, 5,0,6,0,6,0,1,0},
  {5, 0, 6, 0, 0, 0, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,0,6,7, 6,0,7,0,0,0},
  {5,0,6,7, 0,0,4,0,0,0}, // rung - speed from cv, route from R //
};

uint32_t cvRR[64][10]={
  {5, 0, 6, 0, 0, 0, 0, 0, 0, 0}, //['CV', 'null', 'CVL', 'null', 'null', 'ADCin', 'null', 'null', 'null', 'null']
  {5,1,6,0,6, 0,7,7,0,0},
  {5,6,6,0,0, 0,1,0,0,0}, // route from L, speed from N
};
*/
static uint32_t binary[9]={0,0,0,0}; // binary global routing

static uint32_t ADCin;

#define LOWEST 0.000031f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022 // this is now our STOP

static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=0; // for tail choice
static uint32_t adcfunccount=0; // for adctype
static uint32_t dactypecount=0; // for dactype
static uint32_t binroutetypecount=0; // for type of binroute - UNUSED?
//static uint32_t cvcount=0; // for type of CV

// would be nice to have 8 so is 3 bits - logic? logiccount

//uint32_t *countfield[8]={&count, &daccount, &spdcount, &adctypecount, &dactypecount, &binroutetypecount};

//uint32_t *funcfield[8]={&dactypecnt, &spdfuncnt, &lengthfunccnt, &adctypecnt, &bitfunccnt}; // only 5 there
static uint32_t dactypecnt=0;
static uint32_t spdfunccnt=0;
static uint32_t lengthfunccnt=0;
static uint32_t adcfunccnt=0;
static uint32_t bitfunccnt=0;
static uint32_t extfunccnt=0;
static uint32_t outfunccnt=0;
static uint32_t gscnt=0;
static uint32_t outcnt=0;

// 1 means its used so do normed clocks - all one for testing
// replace this with just strobed set by mode/function itself and then passed to final part for normed clocks
uint8_t strobey[4][64]={
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
};

static uint8_t strobed[4]={0,0,0,0};

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
uint32_t param[4]={0,0,0,0}; // interrupt flag...
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
static uint32_t Gshift_[4]={0xffff,0xffff,0xffff,0xffff};

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

static uint32_t nulll=0;

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

#include "tables.h" // routing and other tables

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

uint32_t orderings[16][16]={ // orderings - first is length
  {4,0,1,2,3},
  {7,0,0,1,2,1,2,3}
};

uint32_t ordercount=0;

static uint32_t resetz=1;

// extra files to check...

#include "gen.h" // new generators
#include "adcetc.h" // now all of the other functions so can work on modes
#include "geogen.h" // newer generators
#include "geomantic.h" // new geomantic codebase in progress

//#include "modeN.h"
//#include "modeL.h"
//#include "modeR.h"
//#include "modeC.h"
//#include "probability.h" // probability modes

//#include "basis.h" // basics from commented ones just to speed up tests
//#include "experiment.h" // more functional modes - can also shift some things here... trials
//#include "bit.h" // bitmodes but some are still in modeL
//#include "rungler.h"

void testnull(void){
}

uint32_t testmodes[4]={0,0,0,0};

// collect modes: Lmultiplespeednew // tag modesx modex
/*void (*dofunc[4][64])(uint8_t w)=
{
  {SR_geomantic}, 
  {SR_geomantic}, 
  {SR_geomantic}, 
  {SR_globalbin}
};
*/

void (*dotail[64])(void)= {basictail};



// how many groups
#define GROUP 14 // for 16

  //re-test all new for crash  {adc2, adc0, adc0, SRminor_vienna, SRrunggenericbitsadcX, SRrunghead0NX, adcLrung0-fixed18/6, adcLrung1fixed, adcLrung2fixed,   adcrung0fixed, adcLbinprobX, noSRadc2sX, noSRadc2sX, adcLabstractLDX, stream4_unshareX, streamX}, //128

 /* 
void (*funcgroups[4][128])(uint8_t w)=
{
    {adc2, adc0, adc0, SRminor_vienna, SRrunggenericbitsadc, SRrunghead0N, adcLrung0, adcLrung1, adcLrung2,   adcrung0, adcLbinprob, noSRadc2s, noSRadc2s, adcLabstractLD, stream4_unshare, stream}, //128
  //    {adc2, adc0, adc2, adc0,  adc2,   adc0, adc2, adc0,adc2,  adc0,adc2, adc0, adc2, adc0, adc2, adc0},
  
  {SRX0, SRX0, SR_layer1, SRminor_vienna, SRrunggenericbitsgenopp, SRrunghead0L, SRrung0,   SRrung1,   SRrung2, SRrung3,  adcLbinprob, SRshroute, noSRcopy, adcLabstractLD, stream4_unshare, stream},  // 128

  {newdac2, dac0, dac0, SRminor_vienna, SRrunggenericbits, SRrungout, dacLrung0, dacLrung0, dacNLRin, dacNLRinlogic, adcLbinprob, dac2, noSRdac2s, dacNLRprobin,   stream4_unshare, stream}, 
  
  {SRX0, SRX0, SR5_feedback, SRminor_vienna, SRrunggenericbitsgen, SRrungbody0, SRRrung0, SRRrung1, SRRrung2, SRRrung3,     adcLbinprob, SRX0,     SRX0, adcLabstractLD, stream4_unshare, stream} //64 
}; // 13 so far -- to add more for lisbon - select at random from 50 - how to do from cards...
*/  
// card for each = 16 possibles... we need 50! - q of slidings - we can slide +-64 except modeR cannot slide so should be most generic

 /*
- how else we can express matrices which makes sense - to match up:

as array for each side:

eg. speed, length, bit FUNCS, adc, which dac // them CV indices

thus:
*/
 
void mode_init(void){
  uint32_t x,y;
  /*  
  for (x=0;x<64;x++){
    for (y=0;y<9;y++){
      gate[0].func[x][y]=funcNN[x][y];
      gate[1].func[x][y]=funcLL[x][y];
      gate[2].func[x][y]=funcCC[x][y];
      gate[3].func[x][y]=funcRR[x][y];
    }
  }

  for (x=0;x<64;x++){
    for (y=0;y<10;y++){
      gate[0].cv[x][y]=cvNN[x][y];
      gate[1].cv[x][y]=cvLL[x][y];
      gate[2].cv[x][y]=cvCC[x][y];
      gate[3].cv[x][y]=cvRR[x][y];
    }
  }
  */
  
  RESETR;
  
  for (x=0;x<4;x++){

      
    // tests for stack
  pushspeed(3, x); // spdfrac
  pushspeedcv(CVlist[x][cvpair[0][0]], CVlist[x][cvpair[0][1]], x);
  // trial functions with length

  //   0:zeros 1:binrout 2:binroutfixed 3:binroutor 4:zsingleroutebits 5:zbinrouteINVbits 6:zbinroutebits_noshift_transit 7:zbinroutebits_noshift 8:zbinroutebitscycle 9:zbinroutebitscyclestr 10:zbinroutebitscycle_noshift 11:zbinroutebitscyclestr_noshift 12:zbinrouteORbits 13:zbinrouteANDbits 14:zbinrouteSRbits 15:zbinroutebitsI 16:zbinroutebitsI_noshift 17:zbinroutebitscycleI_noshift 18:zbinroutebitscyclestrI 19:zosc1bits 20:sigmadelta 21:cipher 22:osceq 23:zSRclksr 24:zSRclksrG 25:zSRNbits 26:zSRLbits 27:zSRCbits 28:zSRRbits 29:zpulsebits 30:zprobbits 31:zprobbitsxorstrobe 32:zprobbitsxortoggle 33:zsuccbits 34:zsuccbitsI 35:zreturnbits 36:zreturnnotbits 37:zosc1bits 38:zwiardbits 39:zwiardinvbits 40:zTMsimplebits 41:zonebits 42:zlfsrbits 43:zllfsrbits 44:zflipbits 45:zosceqbitsI 46:zosc1bitsI 47:zTMsimplebitsI 48:zwiardbitsI 49:zwiardinvbitsI 50:zonebitsI 51:zlfsrbitsI 52:zllfsrbitsI 53:zflipbitsI 54:zpattern4bits 55:zpattern8bits 56:zpattern4bitsI 57:zpattern8bitsI 58:Rtest 59:gensel 60:binroutfixed_prob1R 61:binroutfixed_prob1L 62:binroutfixed_prob2 63:binroutfixed_prob3 64:binroutfixed_prob4 65:SRdelay_lineOUT

  pushbit(28, x);  //2: fixed binroute
  pushbitcv(CVlist[x][0], CVlist[x][0], x);

  gate[x].adcindex=1;
  gate[x].adccvindex=6; // CVL

    gate[x].delcnt=0;
    gate[x].cvcnt=0;
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
    gate[x].oldcvcnt=1;
    gate[x].lengthindex=6; // all CVL now    

    gate[x].changedspeed=1;
    gate[x].changedspeedcv=1;
    gate[x].changedbit=1;
    gate[x].changedbitcv=1;
    
    gate[x].oldspeedfunc=0;
    gate[x].speedfunc=3;

    gate[x].oldspeedcv=0;
    gate[x].speedcv=1;
        
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
  static uint32_t flipper[4]={1}, www=0, kk=0, ww=0, glob=0; // global count for sync=glob
  uint32_t tmp;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed
  //////////////////////////////////////////////////////
  /* 
  www++;
 
  if (www>3) {
    www=0;
    resetz=1;
    (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  }
  */

  // testing
//  spdfunccnt=cvcount=dactypecnt=lengthfunccnt=adcfunccnt=bitfunccnt=glob;
  
  // trial of new: *order can also change eg. 0012, to determine from a table... - but table must be longer than 3 so we always have, table is like an SR?*
  // or table can be XORed - with SR or somehow altered from there - as a skip could be an option so maybe we don't need tables...
  ww++;
  if (ww>orderings[ordercount][0]){
    ww=1;
    resetz=1;
    // do the tail here
    (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  }
  www=orderings[ordercount][ww];
  //  if (www==3) (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  
  // genericLFSR for all probability modes
  tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 19) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 19, 25, 24
  LFSR_[www] = (LFSR_[www]<<1) + tmp;

  // sliding modes 
    
  //      mde=mode[3]; // upto13 - test for the frozen one // 11odd 3/genericbitsissilentmostly
  //      if (mde>GROUP) mde=GROUP;
      /*  if (www==0) mde=((mode[3]+mode[0])%128);
  else if (www==1) mde=((mode[3]+mode[1])%128);
  else if (www==2) mde=((mode[3]+mode[2])%128);
  else mde=mode[3]; // case for 3:
      */    

      //      (*funcgroups[www][mde])(www);
      

  // trial here different version of Vienna with interpoll and new bit recurse options
  //  major_vienna(www);

  // do func
  //  (*dofunc[www][0])(www);
  //      SR_geomanticxx(www); // just for testings -> is full matrix one
  // run as META function...
  
  SR_geomanticxxx(www); // xxx new one just for testings, is stack one... xxxx is new one which needs reduced matrices...
  
  if (www==2)  {
      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
      }

  // where are these used and is too long as counts every time
  //      counter[4]++; counter[5]++; counter[6]++;
  counter[www]++; // used I think for multiple speeds
  counterd[www]++; 

}
 
