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

static uint32_t ADCin;

#define LOWEST 0.000062f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022 // this is now our STOP


static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=0; // for tail choice
static uint32_t adcfunccount=0; // for adctype
static uint32_t dactypecount=0; // for dactype
static uint32_t binroutetypecount=0; // for type of binroute - UNUSED?
static uint32_t cvcount=0; // for type of CV

// would be nice to have 8 so is 3 bits - logic? logiccount

//uint32_t *countfield[8]={&count, &daccount, &spdcount, &adctypecount, &dactypecount, &binroutetypecount};

//uint32_t *funcfield[8]={&dactypecnt, &spdfuncnt, &lengthfunccnt, &adctypecnt, &bitfunccnt}; // only 5 there
static uint32_t dactypecnt=0;
static uint32_t spdfunccnt=0;
static uint32_t lengthfunccnt=0;
static uint32_t adcfunccnt=0;
static uint32_t bitfunccnt=0;

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

//#include "modeN.h"
//#include "modeL.h"
//#include "modeR.h"
//#include "modeC.h"
//#include "probability.h" // probability modes

//#include "basis.h" // basics from commented ones just to speed up tests
#include "geomantic.h" // new geomantic codebase in progress
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

//void (*dotail[64])(void)= {basictail};



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


void mode_init(void){
  uint32_t x;

  RESETR;
  
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
  static uint32_t flipper[4]={1}, www=0, kk=0, ww=0;
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
  
  // trial of new: *order can also change eg. 0012, to determine from a table... - but table must be longer than 3 so we always have, table is like an SR?*
  // or table can be XORed - with SR or somehow altered from there - as a skip could be an option so maybe we don't need tables...
  ww++;
  if (ww>orderings[ordercount][0]){
    ww=1;
    resetz=1;
  }
  www=orderings[ordercount][ww];
  //  if (www==3) (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case...
  
  // genericLFSR for all probability modes
  tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 19) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 19, 25, 24
  LFSR_[www] = (LFSR_[www]<<1) + tmp;

  // sliding modes 
    
      mde=mode[3]; // upto13 - test for the frozen one // 11odd 3/genericbitsissilentmostly
      if (mde>GROUP) mde=GROUP;
      /*  if (www==0) mde=((mode[3]+mode[0])%128);
  else if (www==1) mde=((mode[3]+mode[1])%128);
  else if (www==2) mde=((mode[3]+mode[2])%128);
  else mde=mode[3]; // case for 3:
      */    

      //  (*funcgroups[www][mde])(www);
      

  // trial here different version of Vienna with interpoll and new bit recurse options
  //  major_vienna(www);

  // do func
  //  (*dofunc[www][0])(www);

  
  if (www==2)  {
      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
      }

  // where are these used and is too long as counts every time
  //      counter[4]++; counter[5]++; counter[6]++;
  counter[www]++; // used I think for multiple speeds
  counterd[www]++; 

}
 