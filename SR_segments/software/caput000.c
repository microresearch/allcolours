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

// add in dactype, dacpar

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobespd, 16type, 17 route}
uint32_t matrixNN[18]={0,0,0,  1<<7,0,0, 31<<7, 1<<7,31<<7, 1<<7,0,0,4,    25<<7,2048, 0, 0, 8<<8}; // binroutfixed... last in len -- 12 bits  31<<7 is lowest length
uint32_t matrixLL[18]={0,0,0,  1<<7,0,0, 0<<7, 0,0,         1<<7,0,0,4,    25<<7,2048, 0, 0, 1<<8};
uint32_t matrixCC[18]={0,0,0,  1<<7,0,0, 0<<7, 0,0,         1<<7,0,0,4,    0<<7, 2048, 0, 0, 2<<8}; 
uint32_t matrixRR[18]={0,0,0,  1<<7,0,0, 0<<7, 0,0,         1<<7,0,0,4,    25<<7,2048, 0, 0, 4<<8};  // spdfracend TEST
uint32_t matrixTT[18]={0,0,0,  1<<7,0,0, 0<<7, 0,0,         1<<7,0,0,4,    25<<7,2048, 0, 0, 1<<8}; 
//                     speed   bit       len   adc,adc-cv   prob  alt      dac      strobespdindex, type, route

uint32_t *matrixNNN[18]={&CVL[0], &CV[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0], &CVL[0]};
uint32_t *matrixLLL[18]={&CVL[1], &CV[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1], &CVL[1]};
uint32_t *matrixCCC[18]={&CVL[2], &CV[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2], &CVL[2]};
uint32_t *matrixRRR[18]={&CVL[3], &CV[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3]};
uint32_t *matrixTTT[18]={&CVL[3], &CV[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3], &CVL[3]}; 


static uint32_t binary[9]={0,0,0,0}; // binary global routing
static uint32_t ADCin;

#define LOWEST 0.000016f // was but we now have 16 octs and can be lower also for RR 0.000031f // TODO/TEST - this might change if we change logspeed - changed 7/2/2022 // this is now our STOP

static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=1; // for tail choice
static uint32_t binroutetypecount=0; // for type of binroute - used in a few functions in geogen 

// TODO: clean these - do we use???
//static uint32_t dactypecnt=0;

// 1 means its used so do normed clocks - all one for testing
// replace this with just strobed set by mode/function itself and then passed to final part for normed clocks
// TODO: fix
uint32_t strobey[4][64]={
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

uint32_t mode[4]={0,0,0,0};
uint32_t smode[4]={0,0,0,0};
uint32_t lastmode[4]={1,1,1,1};
uint32_t clkr=7;
uint32_t lastmodec, lastmoden, lastmodel, lastmoder;
uint32_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;
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
static uint32_t LFSR__[4]={0xf0fff,0xf0ff,0xff00f,0xff};
static uint32_t ADCshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t ADCGshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t Gshift_[9]={0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff};

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

//static uint32_t nulll=0;

static uint32_t GGGshift_[4]; // gshift is 4 even though we don't use one // GG is ghost in ghost
static uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0}, Gshift_revrevcnt[4]={0,0,0,0};

uint32_t inputbit[4]={0,2,2,2}; //0-LFSR,1-ADC,2-none
//uint32_t adctype[4]={0,0,0,0}; // 0-basic, 1-one bit
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
static uint32_t flipd[4]={0,0,0,0};
static uint32_t pulsouts[8]={0, 0,  1<<2, 1<<15, 1<<4, 1<<12, 1<<3, 1<<11};

static uint32_t defdac=3;

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

//#include "gen.h" // new generators
#include "adcetc.h" // now all of the other functions so can work on modes
#include "geogen.h" // newer generators
#include "exp_port.h" // ports from exp...++etc includes L now
#include "geomantic.h" // new geomantic codebase in progress

// new ones now - check memory
//#include "geoC.h"
//#include "geoN.h"
//#include "geoLR.h"

#include "geoCC.h"
#include "geoNN.h"
#include "geoLL.h"
#include "geoRR.h"
//#include "test.h"
// check slowest speed
/*
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
*/

// list of metaout functions... examples?
//uint32_t (*metaout[64])(uint8_t w, uint32_t mood)={itself};   // unused but keep for moment 

 void (*SRgeo_outer[4][64])(uint32_t w)=
{
       {SR_geo_outer_N00, SR_geo_outer_N01, SR_geo_outer_N02, SR_geo_outer_N03,  SR_geo_outer_N10, SR_geo_outer_N11, SR_geo_outer_N12, SR_geo_outer_N13, SR_geo_outer_N20, SR_geo_outer_N21, SR_geo_outer_N22, SR_geo_outer_N23, SR_geo_outer_N30, SR_geo_outer_N31, SR_geo_outer_N32, SR_geo_outer_N33,  /*SR_geo_outer_N40, SR_geo_outer_N41, SR_geo_outer_N42, SR_geo_outer_N43, SR_geo_outer_N50, SR_geo_outer_N51, SR_geo_outer_N52, SR_geo_outer_N53, SR_geo_outer_N60, SR_geo_outer_N61, SR_geo_outer_N62, SR_geo_outer_N63, SR_geo_outer_N70, SR_geo_outer_N71, SR_geo_outer_N72, SR_geo_outer_N73*/},
       {SR_geo_outer_L00, SR_geo_outer_L01, SR_geo_outer_L02, SR_geo_outer_L03,  SR_geo_outer_C10, SR_geo_outer_C11, SR_geo_outer_C12, SR_geo_outer_C12, SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C30, SR_geo_outer_C31, SR_geo_outer_C32, SR_geo_outer_C33,  SR_geo_outer_C40, SR_geo_outer_C41, SR_geo_outer_C42, SR_geo_outer_C43, SR_geo_outer_C50, SR_geo_outer_C51, SR_geo_outer_C52, SR_geo_outer_C53, SR_geo_outer_C60, SR_geo_outer_C61, SR_geo_outer_C62, SR_geo_outer_C63, SR_geo_outer_C70, SR_geo_outer_C71, SR_geo_outer_C72, SR_geo_outer_C73},
     {SR_geo_outer_C00, SR_geo_outer_C01, SR_geo_outer_C02, SR_geo_outer_C03,  SR_geo_outer_C10, SR_geo_outer_C11, SR_geo_outer_C12, SR_geo_outer_C13, SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C30, SR_geo_outer_C31, SR_geo_outer_C32, SR_geo_outer_C33,  SR_geo_outer_C40, SR_geo_outer_C41, SR_geo_outer_C42, SR_geo_outer_C43, SR_geo_outer_C50, SR_geo_outer_C51, SR_geo_outer_C52, SR_geo_outer_C53, SR_geo_outer_C60, SR_geo_outer_C61, SR_geo_outer_C62, SR_geo_outer_C63, SR_geo_outer_C70, SR_geo_outer_C71, SR_geo_outer_C72, SR_geo_outer_C73}, 
     {SR_geo_outer_R00, SR_geo_outer_R01, SR_geo_outer_R02, SR_geo_outer_R03,  SR_geo_outer_R10, SR_geo_outer_R11, SR_geo_outer_R12, SR_geo_outer_R13, SR_geo_outer_R20, SR_geo_outer_R21, SR_geo_outer_R22, SR_geo_outer_R23, SR_geo_outer_R30, SR_geo_outer_R31, SR_geo_outer_R32, SR_geo_outer_R33/*, SR_geo_outer_R40, SR_geo_outer_R41, SR_geo_outer_R42, SR_geo_outer_R43, SR_geo_outer_R50, SR_geo_outer_R51, SR_geo_outer_R52, SR_geo_outer_R53, SR_geo_outer_R60, SR_geo_outer_R61, SR_geo_outer_R62, SR_geo_outer_R63, SR_geo_outer_R70, SR_geo_outer_R71, SR_geo_outer_R72, SR_geo_outer_R73*/},

};

// 

//  {SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route, SR_geo_outer_route},
 
void mode_init(void){
  uint32_t x;

  gate[0].logspeed=logspeed;
  gate[1].logspeed=logspeed;
  gate[2].logspeed=logspeed;
  gate[3].logspeed=logspeed18;

  gate[0].lowest=0.000016f;
  gate[1].lowest=0.000016f;
  gate[2].lowest=0.000016f;
  gate[3].lowest=0.000005f;
  
  
  for (x=0;x<18;x++){
      gate[0].matrix[x]=matrixNN[x];
      gate[0].matrixp[x]=matrixNNN[x]; // these are just defaults

      gate[1].matrix[x]=matrixLL[x];
      gate[1].matrixp[x]=matrixLLL[x];
      
      gate[2].matrix[x]=matrixCC[x];
      gate[2].matrixp[x]=matrixCCC[x];

      gate[3].matrix[x]=matrixRR[x];
      gate[3].matrixp[x]=matrixRRR[x];

      gate[8].matrix[x]=matrixTT[x];
      gate[8].matrixp[x]=matrixTTT[x];
  }

  //  RESETC;
  
  for (x=0;x<4;x++){
    gate[x].flip=0;
    gate[x].route=0;
    gate[x].altroute=0;
    gate[x].routetype=0;
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
    gate[x].fake=1;
    gate[x].in=0;
    gate[x].globflag=1;
    gate[0].gsrcnt[x]=31;
    gate[1].gsrcnt[x]=31;
    gate[2].gsrcnt[x]=31;	
    gate[3].gsrcnt[x]=31;
  }

  gate[0].theroute=8; // defaults
  gate[1].theroute=1;
  gate[2].theroute=2; // was 2 but TESTY!
  gate[3].theroute=4;
    
  //  gate[0].adctype=0;

  //  gate[0].dactype=25; // now set to 25 // was 67
  //  gate[1].dactype=25; // default simpler version - now 4 bit version 
  //  gate[2].dactype=0; // set for out
  //  gate[3].dactype=25;
  //  gate[8].dactype=25;  
}


void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  static uint32_t www=0, ww=0, first=0, flipperrr=0;
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
  LFSR__[www]=LFSR_[www]&4095;
  
  // testings for meta mode handlers
  //uint32_t outindex=(*metaout[mode[www]])(www, mode[www]); // - functions which return geomantic indices nased on mode[www]

  uint32_t outindex=0;
  //  outindex=mode[www]; // test for 5 bits of mode 0-31 in geoC
  if (www==2 || www==1) outindex=mode[www]; // testing TYPE on CVL
  if (outindex>15) outindex=15;

  /*
  if (www==2 && gate[2].changed==1) {
  flipperrr^=1; // full speed 60 KHz
  if (flipperrr) GPIOB->BSRRH=clk_route_new[2]; // we get from tail // which one
  else GPIOB->BSRRL=clk_route_new[2];
  }
  */

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
 
