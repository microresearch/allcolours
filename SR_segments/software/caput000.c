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

static heavens gate[9]; // for parallell SR doubled + tail

static uint32_t CV[4]={0,0,0,0};
static uint32_t CVL[4]={0,0,0,0};
static uint32_t CVM[4]={0,0,0,0};

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex}
uint32_t matrixNN[13]={0,0,0, 2<<7,0,0, 31<<7, 1<<7,0, 0,0,0,0}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
uint32_t matrixLL[13]={0,0,0, 2<<7,0,0, 31<<7, 0,0, 0,0,0,0};
uint32_t matrixCC[13]={0,0,0, 1<<7,0,0, 31<<7, 0,0, 2<<7,0,0,1}; // C has sprobbits, altfunc is 1 but then that needs cv too
uint32_t matrixRR[13]={0,0,0, 2<<7,0,0, 31<<7, 0,0, 0,0,0,0}; 
//                     speed  bit       len    adc  prob

uint32_t *matrixNNN[13]={&CVL[0], &CV[0], &CVL[0], &CV[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0]}; 

static uint32_t binary[9]={0,0,0,0}; // binary global routing
static uint32_t ADCin;

#define LOWEST 0.000031f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022 // this is now our STOP

static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=0; // for tail choice
static uint32_t binroutetypecount=0; // for type of binroute - used in a few functions in geogen 

// TODO: clean these - do we use???
//static uint32_t dactypecnt=0;

// 1 means its used so do normed clocks - all one for testing
// replace this with just strobed set by mode/function itself and then passed to final part for normed clocks
// TODO: fix
uint8_t strobey[4][64]={
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
  {1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1},
};

#include "macros.h"

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
static uint32_t SRlength[9]={31,31,31,31,31,31,31,31,31};

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

// for single clk routes
static uint32_t clk_route_new[4]={0, // no clk route 0 
			      (1<<12),
  			      (1<<14),
			      (1<<13)
};



static uint32_t LFSR_[4]={0xf0fff,0xf0ff,0xff00f,0xff};
static uint32_t ADCshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t ADCGshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t Gshift_[8]={0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff};

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

static uint32_t ordercount=0;

static uint32_t resetz=1;
static uint32_t glob=0; // glob is now global index for global funcs 

#include "gen.h" // new generators
#include "adcetc.h" // now all of the other functions so can work on modes
#include "geogen.h" // newer generators
#include "exp_port.h" // ports from exp...++etc includes L now
#include "geomantic.h" // new geomantic codebase in progress

// check slowest speed
void SRspeedtest(uint8_t w){ // null
  static uint32_t tgg[4]={0,0,0,0};
  //  HEADSIN;
  speedf_[w]=logspeed[CV[w]>>2]; // 10 bits
  //  speedf_[w]=slowerlog[CV[w]>>2]; // 10 bits
  gate[w].time_now += speedf_[w];
  gate[w].last_time = gate[w].int_time;
  gate[w].int_time = gate[w].time_now;

  if(gate[w].last_time<gate[w].int_time)      {
    tgg[w]^=1;
    if (tgg[w]==1) gate[w].dac=4095;
    else gate[w].dac=0;
    gate[w].time_now-=1.0f;
    gate[w].int_time=0;	

  }
}

uint32_t itself(uint8_t w, uint32_t mood){ //
    return mood;
  }

// list of metaout functions... examples?
uint32_t (*metaout[64])(uint8_t w, uint32_t mood)={itself};   // unused but keep for moment 

 void (*SRgeo_outer[4][64])(uint32_t w)=
{
   {SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr},
   {SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr},
   {SR_geomantic_outer_binr, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, SR_geomantic_outer_rung1, }, // test for various functions eg speed/strobe now... // now trial selection across these - T1 is flexi so first lot
   {SR_geomantic_outerS0, SR_geomantic_outerRglobselandset, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr},
   //     {SR_geomantic_outerRglobsel, SR_geomantic_outerRglobsel, SR_geomantic_outerRglobsel, SR_geomantic_outerRglobsel, SR_geomantic_outerRglobset, SR_geomantic_outerRglobset, SR_geomantic_outerRglobset, SR_geomantic_outerRglobset}
   // SR_geomantic_outerRglobselandset
   //SR_geomantic_outer_binr
};

// 

//  {SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr, SR_geomantic_outer_binr},
 
void mode_init(void){
  uint32_t x,y;

  for (y=0;y<13;y++){
      gate[0].matrix[y]=matrixNN[y];
      gate[1].matrix[y]=matrixLL[y];
      gate[2].matrix[y]=matrixCC[y];
      gate[3].matrix[y]=matrixRR[y];

      gate[0].matrixp[y]=matrixNNN[y]; // these are just defaults
      gate[1].matrixp[y]=matrixNNN[y];
      gate[2].matrixp[y]=matrixNNN[y];
      gate[3].matrixp[y]=matrixNNN[y];

  }

  RESETR;
  
  for (x=0;x<4;x++){
    gate[x].flip=0;
    gate[x].route=0;
    gate[x].shift_=0x15;
    gate[x].Gshift_[0]=0;
    gate[x].Gshift_[1]=0;
    gate[x].Gshift_[2]=0;
    gate[x].Gshift_[3]=0;
    gate[x].reset[0]=0;
    gate[x].reset[1]=0;
    gate[x].reset[2]=0;
    gate[x].reset[3]=0;
    gate[x].route=0;
    
    gate[0].gsrcnt[x]=31;
    gate[1].gsrcnt[x]=31;
    gate[2].gsrcnt[x]=31;	
    gate[3].gsrcnt[x]=31;
  }
  
  gate[0].adctype=0;

  gate[0].dactype=25; // now set to 25 // was 67
  gate[1].dactype=25; // default simpler version - now 4 bit version 
  gate[2].dactype=0; // set for out
  gate[3].dactype=25;
  gate[8].dactype=25;  
}


void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static uint32_t www=0, ww=0;
  uint32_t tmp;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed
  //////////////////////////////////////////////////////

  if (intflag[www]) { // process INT
    gate[www].trigger=1;
    intflag[www]=0;
    clksrG_[www]=clksr_[www]; // copy in to ghost
    tmp=(clksr_[www]>>31)& 0x01; // length is 31
    clksr_[www]=(clksr_[www]<<1)+tmp;     // shift round CLKSR - we can also insert in/copy in
  }
  else  {
    gate[www].trigger=0;
  }

  
  // trial of new: *order can also change eg. 0012, to determine from a table... - but table must be longer than 3 so we always have, table is like an SR?*
  // or table can be XORed - with SR or somehow altered from there - as a skip could be an option so maybe we don't need tables...
  ww++;
  if (ww>orderings[ordercount][0]){
    ww=1;
    resetz=1;
    // do the tail here
    (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case... // fixed bug in use of Gshift_[8] now...
  }
  www=orderings[ordercount][ww];

  tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 19) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 19, 25, 24
  LFSR_[www] = (LFSR_[www]<<1) + tmp;

  // testings for meta mode handlers
  //uint32_t outindex=(*metaout[mode[www]])(www, mode[www]); // - functions which return geomantic indices nased on mode[www]

  uint32_t outindex=0;//mode[www]>>3; // now only 3 bits - from 6 bits (64) to 3 bits...mode is 64.32.16>>8
  (*SRgeo_outer[www][outindex])(www); // or we just use mode[www] as index and all we need is done in inner and outer geomantics - except we can't manipulate these or stalk/stack through them
  (*gate[www].inner)(www); // this one is now set by outer which we need to call from a list

  //    SRspeedtest(www); // test slowest speed
 
if (www==2)  {
   DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
 }

 // implement fake strobe using gate[w].strobed (we will miss the first one but...)

 if (www!=0){ 
 if (gate[www].strobed){ // still q of strobey
   if (gate[8].shift_ &0x01) GPIOB->BSRRH=clk_route_new[www]; // we get from tail
     else GPIOB->BSRRL=clk_route_new[www];
   }
 } /// www==0
 else
   {
     if (gate[www].strobed){ // still q of strobey
      tmp= gate[dacfrom[daccount][0]].dac; // now is set by count/array
      tmp+=320; 
      TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
      TIM1->CCR1 = tmp/2; // pulse width
     }
  else 
    {
      TIM1->ARR =0; 
      TIM1->CCR1 = 0;
    }
   }

  counter[www]++; // used I think for multiple speeds
  counterd[www]++; 

}
 
