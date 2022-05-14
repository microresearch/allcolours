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

#define LOWEST 0.000063f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022

static uint32_t count=0;
static uint32_t daccount=0;
static uint32_t spdcount=0;

// 1 means its used so do normed clocks - all one for testing
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
uint32_t dactype[4]={66,66,66,66}; // 0-basic, 1-equiv bits, 2-one bit - 66 is new default one for all except out
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

void new_data(uint32_t data, uint32_t ww)
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

void testnull(void){
}

static modez newmodes[128]={ // then call mode by number
  {1,1,1,1, SRx_x, innertest}
};

uint32_t testmodes[4]={0,0,0,0};

// collect modes: Lmultiplespeednew // tag modesx modex
void (*dofunc[4][64])(uint8_t w)=
{//NLcutfeedback86
  {adc_onebitmid}, 
  {SRX0}, // SRX0 is basic route/xor
  {dac2}, // dac0 SR_insert_zero_dac2
  {SRX0}
};

/*
nogshift=SR0nogstrobe, SR0nogtoggle, SRLprobnog, SRintprobnog

  {adcLbinprob}, //adcLseladcdac5th //adcbumproutebin0 // adc95bins // adcLpatternbin95 // adcbin1_0 // adccipher2 // ADCholdcycle
  {adcLbinprob}, //adcLabstractI binspeedcycle SRsigma noSRxorroutes noSRdelay_line SRmultiplespeednewdac0 SRmatch SRprobxortogx SR_switchspeed SR_switchspeed SR_vienna SRxorroutes SRaddroutes SR_clksrG SRothers dacbusothers_clk dacbusothers_sr dacbusothers_own SRhold SRholdspd SR_speedx SR_splitx SR_recbin
  {adcspeedstream}, dacNbinprob NLRprobinINT1311seldac abstractoutinterpolnoshift 
  {adcLbinprob} SRpattern_unshare
*/

// TODO: start to catalogue groups of modes - but this could also be dofunc? // eg. first group is runglers
/* void (*funcgroups[4][64])(uint8_t w)=
{//NLcutfeedback86
  {adcLrung0, adcLrung1, adcLrung2, adcrung0, adcLbinprob, noSRadc2s, noSRadc2s, adcLabstractLD, stream4_unshare}, 
  {SRrung0,SRrung1, SRrung2, SRrung3, SRLrung0, adcLbinprob, SRshroute, noSRcopy, adcLabstractLD, stream4_unshare}, 
  {dacLrung0, dacLrung0, dacNLRin, dacNLRinlogic, adcLbinprob, dac2, noSRdac2s, dacNLRprobin, stream4_unshare}, // dacNLRprobinINT1311
  {SRRrung0, SRRrung1, SRRrung2, SRRrung3, adcLbinprob, SRX0, SRX0, adcLabstractLD, stream4_unshare}
};
*/

// so if we wanted to select these how would that work - as major mode but with no minor modes>>>???
// or like sliding against this - just as numbers, or... R selects funcgroup as major mode, L selects which one in group... CN as params for our list???
// then other major modes...
// - at moment just use as suggested groupings...


// TODO/above: can there also be gap to allow for insertion of own mode eg. for DAC
// eg. blank function which uses mode[w] 

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
  uint32_t tmp;
  static uint32_t flipper[4]={1}, www=0, kk=0;

  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed
  
  // for the time between counts
  counter_[0]++;  counter_[1]++;  counter_[2]++;  counter_[3]++;

  // would be easier to pass in modes structure... but...
  //  SRitselftryagain(0, moodsw[0].spdfr, moodsw[0].probfr, moodsw[0].incfr, moodsw[0].incor, moodsw[0].last, moodsw[0].par1,  moodsw[0].par2,  moodsw[0].par3,  moodsw[0].par4, moodsw[0].logic);  
  //  SRitselftry2(0, &moodsw[0]);
  
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

  // do the modes
  mode[www]=testmodes[www];
   
   //    mode[1]=0;mode[2]=0;mode[3]=0; // test adc mode 0
  //  mode[0]=4;
  //  mode[1]=0;mode[3]=0; // test dac
  //  if (mode[2]>15) mode[2]=15;
  //  if (mode[0]>5) mode[0]=5;
  //    (*gate[www].dofunc[mode[www]])();
  //mode[2]=12;

  // *TODO*: sync mode from RSR modes - we sync all modes so are same as LSR
   // needs mirror rmode to work...
   //   if (rmode==1) { mode[1]=mode[0];mode[2]=mode[0]; mode[3]=mode[0];
   // or we have mode[3] as no mirror and simple pass through
   if (www==3) {
     spdcount=0; count=0; daccount=0; // so when we leave modes which set this reverts to 0...
   }

   ///   adcallone(0); // TESTY all onebits in
   (*dofunc[www][mode[www]])(www);
   // test to call 
   // static modez newmodes[128]={ // then call mode by number
   //  {0,0,0,0, SRx_x, innertest}
   //};
   uint8_t choice=0;
   //   (*newmodes[choice].func)(www, newmodes[choice].strobey, newmodes[choice].detachlen, newmodes[choice].detachspeed, newmodes[choice].interpoll, newmodes[choice].innerfunc);   
   
   //   (*moodsfuncs[0])(www, &moodsw[0]); //see experiment.h - mode=0;b
  
  // this runs at full speed? - can also be in functions/modes // do we have option to have another DAC out?
    if (www==2)  {
      //              kk^=1; // test code
	      //    	  if (kk)    gate[2].dac=4095;
      //    	  else gate[2].dac=0; // 20 KHz!
      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
      ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_144Cycles); 
      //      ADC_SoftwareStartConv(ADC1); 
      //      while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
      //      kk=ADC_GetConversionValue(ADC1);
    //    kk=2050;
      //      DAC_SetChannel1Data(DAC_Align_12b_R, 4095-kk); // 1000/4096 * 3V3 == 0V8 
      //int j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
      }

    
  // DAC for normed NSR/PWM
    if (www==dacfrom[daccount][0] && strobey[0][mode[0]]){
      tmp= gate[dacfrom[daccount][0]].dac; // now is set by count/array
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
      
      if (counter[4]>gate[dacfrom[daccount][1]].dac){ // L side
	counter[4]=0;
	if (strobey[1][mode[1]]){
	flipper[0]^=1;
	if (flipper[0]) GPIOB->BSRRH = clk_route[1];  // clear bits of fake_one
	else   GPIOB->BSRRL=clk_route[1]; //  write bits
	}
      }      

      /*
      if (counter[5]>gate[dacfrom[daccount][3]].dac){ // R side
	counter[5]=0;
	if (strobey[3][mode[3]]){
	flipper[1]^=1;
	if (flipper[1]) GPIOB->BSRRH = clk_route[2];  
	else   GPIOB->BSRRL=clk_route[2]; //  write bits
      }      
      }*/
      // 5th tail could be used...??? but might be from right side!
      if (LFSR_[3]>>31) GPIOB->BSRRH = clk_route[2]; // now noise as tends to run out on feedback but slower noise or comp would be nice
	else   GPIOB->BSRRL=clk_route[2]; //  write bits
    
//      if (counter[2]>(gate[3].dac)){ // now trying DAC 29/12/2021 - // C side!
//	counter[2]=0;
//	flipper[2]^=1;
//	if (flipper[2]) GPIOB->BSRRH = clk_route[4];  
//	else   GPIOB->BSRRL=clk_route[4]; //  write bits
//	}


      // trial just using lowest bit 30/12/2021 ??? TEST???? C side
      // - DONEtrial of another approach to fake clocks (but would be better as own ghosts???) - NOTEfrom segmodes but not sure what that means?
            if (strobey[2][mode[2]]){
	      if ((gate[dacfrom[daccount][2]].shift_>>SRlength[2])&0x01) GPIOB->BSRRH = clk_route[4]; /// can mean to die out
	      else GPIOB->BSRRL=clk_route[4]; //  write bits
	    }
      
      counter[4]++; counter[5]++; counter[6]++;
      counter[0]++; counter[1]++; counter[2]++; counter[3]++;
      counterd[0]++; counterd[1]++; counterd[2]++; counterd[3]++;
      counterl++; counterr++;

}
 
