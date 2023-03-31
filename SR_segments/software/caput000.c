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

static heavens gate[5]; // for parallell SR doubled + tail

static uint32_t CV[4]={0,0,0,0};
static uint32_t CVL[4]={0,0,0,0};

#define LOWEST 0.000005f

// {0speedfrom/index, 1speedcv1, 2speedcv2, 3bit/index, 4bitcv1, 5bitcv2, 6lencv, 7adc, 8adccv, 9prob/index, 10probcv1, 11probvcv2, 12altfuncindex, 13dactype, 14dacpar, 15strobespd, 16troutetype, 17 route->now strobe function index}, 18 is abstract CV/unused, 19 is now glob, 20 is now abstract index, 21 is mix
uint32_t matrixNN[22]={0<<7,4095,0,  0,2047,2047,31<<7, 0,0<<7, 0,4095,0,0,      31<<7,0, 0, 3<<9, 0, 2048, 0, 0, 1024}; // trial types 16]
uint32_t matrixLL[22]={0,4095,0,  0,2047,0, 31<<7,   0,0,        0,2048,0,0,      31<<7,0, 0, 0, 0, 0, 0, 0, 1024};
uint32_t matrixCC[22]={1<<7,4095,0,  0,2047,0, 31<<7, 0,0,       0,2048,0,0,      0<<7,0, 0, 0, 0, 0, 0, 0, 1024}; 
uint32_t matrixRR[22]={2<<7,4095,0,2047,0,2047, 31<<7, 0,0,      0,2048,0,0,      0<<7,0, 0, 3<<9, 0, 0, 0, 0, 1024};  // spdfracend
//uint32_t matrixTT[22]={0,4095,0,  0,0,0, 31<<7, 0,0,         0,2048,0,0,    0<<7,0, 0, 0, 0, 0, 0, 0, 2048}; 
//                     speed   bit       len   adc,adc-cv    prob   alt     dac, dacpar      strobespdindex, type, route, abstrct cv, glob, abstract index, mixer

//static uint32_t nul=0;

static uint32_t binary[5]={0,0,0,0}; // binary global routing
static uint32_t ADCin;

static uint32_t count=0; // for route
static uint32_t daccount=0; // for dacfrom
static uint32_t spdcount=0; // for spdfrom
static uint32_t tailcount=0; // for tail choice

#include "macros.h"

#define FULL 0b11111111111111111111111111111111 //32 bits full
#define HALB 0b10101010101010101010101010101010 //32 bits 1010
#define MAXVALUE 4095
#define SMOOTHINGS 32 // we can hold 65536 of our 16 bit ADC values...speed

uint32_t cc=0, totc=0, smoothc[SMOOTHINGS]={0};
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS]={0};
uint32_t rr=0, totr=0, smoothr[SMOOTHINGS]={0};
uint32_t nn=0, totn=0, smoothn[SMOOTHINGS]={0};

uint32_t ccc=0, totcc=0, smoothcc[SMOOTHINGS]={0};
uint32_t lll=0, totll=0, smoothll[SMOOTHINGS]={0};
uint32_t rrr=0, totrr=0, smoothrr[SMOOTHINGS]={0};
uint32_t nnn=0, totnn=0, smoothnn[SMOOTHINGS]={0};


uint32_t mode[4]={0,0,0,0};
uint32_t lastmode[4]={1,1,1,1};
//uint32_t lastmodec, lastmoden, lastmodel, lastmoder;
//uint32_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;

volatile uint32_t intflag[4]={0,0,0,0}; // interrupt flag...
uint32_t SRlength_[5]={31,31,31,31,31};
static uint32_t SRlength[5]={31,31,31,31,31};

uint32_t clksr_[4]={HALB,HALB,HALB,HALB};
uint32_t clksr__[4]={0,0,0,0};
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
static uint32_t LFSR__[4]={0xff,0xff,0xff,0xff};
static uint32_t ADCshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t ADCGshift_[4]={0xffff,0xffff,0xffff,0xffff};
static uint32_t Gshift__[5]={0,0,0,0,0};

static uint32_t GGshift_[4][4]={ // for freezers
 {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff}
};

static uint32_t GGGshift_[4]; // gshift is 4 even though we don't use one // GG is ghost in ghost

#include "tables.h" // routing and other tables

uint32_t sieve[4]={3,3,3,3}; // previous one... - changed to R 21/12/2021
uint32_t oppose[4]={2,3,0,1};

static uint32_t train[4]={0,0,0,0};

static uint32_t prev_stat[4]={0,0,0,0};

static uint32_t pulsins[4]={0,1<<8,0,1<<7}; //N,L,C,R
static uint32_t pulse[4]={0,1,0,1};
static uint32_t LR[4]={0,1,0,1};
static uint32_t flipd[4]={0,0,0,0};
static uint32_t pulsouts[8]={0, 0,  1<<2, 1<<15, 1<<4, 1<<12, 1<<3, 1<<11};

volatile uint16_t *pulsoutHI[8]={&(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOC->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL) };
//                                  0              0              PB2                PC15           PB4               PA12           PB3                PA11 
volatile uint16_t *pulsoutLO[8]={&(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOC->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH) }; // both are 16 bit registers

volatile uint32_t *clkins[4]={&(GPIOC->IDR), &(GPIOB->IDR), &(GPIOB->IDR), &(GPIOC->IDR)}; // checked
uint32_t clkinpins[4]={1<<4, 1<<6, 1<<7, 1<<5};

#define DELAY_SIZE 6 // was 40 --- 3*width=16 = 3*16=48-5=43 - use 7 for simplea // used but just to hit 1
static int32_t delay_buffer[4][2] = { 0 }; // was 48 but it doesn't need to be so big

static inline void new_data(uint32_t data, uint32_t ww)
{
  delay_buffer[ww][0] = delay_buffer[ww][1];
    delay_buffer[ww][1] = data;
}

static uint32_t ordercount=0;
static uint32_t resetz=1;
static uint32_t glob=0; // glob is now global index for global funcs 

#include "adcetc.h" // now all of the other functions so can work on modes
#include "geogen.h" // newer generators
#include "exp_port.h" // ports from exp...++etc includes L now
#include "geomantic.h" // new geomantic codebase in progress
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
*/

/*

N: N0-3, C10,12,13,20, N20-23, C30-33, N40-N53, L50-51, C70-73 C80-153
L: L00, C01-40, L41-63, C70-153
C: all
R: R00-3, C10-40 now R13, L41-63, [now R52, 53, R60, R62,63] C70-C113, R120-R153 (globals)

 */

 void (*SRgeo_outer[4][64])(uint32_t w)=
{
   {SR_geo_outer_N00, SR_geo_outer_N01, SR_geo_outer_N02, SR_geo_outer_N03, SR_geo_outer_C10, SR_geo_outer_C12, SR_geo_outer_N13, SR_geo_outer_C13, /**/SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_N22, SR_geo_outer_N23, /**/SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C31, SR_geo_outer_C32, /**/SR_geo_outer_N40, SR_geo_outer_N41, SR_geo_outer_N42, SR_geo_outer_N43, SR_geo_outer_N50, SR_geo_outer_N51, SR_geo_outer_N52, SR_geo_outer_N53, /**/SR_geo_outer_L50, SR_geo_outer_L51, SR_geo_outer_L52, SR_geo_outer_L53, SR_geo_outer_C70, SR_geo_outer_C71, SR_geo_outer_C72, SR_geo_outer_C73, SR_geo_outer_C80, SR_geo_outer_C81, SR_geo_outer_C82, SR_geo_outer_C83, SR_geo_outer_C90, SR_geo_outer_C91, SR_geo_outer_C92, SR_geo_outer_C93, SR_geo_outer_C100, SR_geo_outer_C101, SR_geo_outer_C102, SR_geo_outer_C103, SR_geo_outer_C110, SR_geo_outer_C111, SR_geo_outer_C112, SR_geo_outer_C113, SR_geo_outer_C120, SR_geo_outer_C121, SR_geo_outer_C122, SR_geo_outer_C123, SR_geo_outer_C130, SR_geo_outer_C131, SR_geo_outer_C132, SR_geo_outer_C133, SR_geo_outer_C140, SR_geo_outer_C141, SR_geo_outer_C142, SR_geo_outer_C143, SR_geo_outer_C150, SR_geo_outer_C151, SR_geo_outer_C152, SR_geo_outer_C153},

  {SR_geo_outer_L00, SR_geo_outer_C01, SR_geo_outer_C02, SR_geo_outer_C03,  SR_geo_outer_L10, SR_geo_outer_L11, SR_geo_outer_C12, SR_geo_outer_C13, SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C30, SR_geo_outer_C31, SR_geo_outer_C32, SR_geo_outer_C33,  SR_geo_outer_C40, /**/SR_geo_outer_L41, SR_geo_outer_L42, SR_geo_outer_L43, SR_geo_outer_L50, SR_geo_outer_L51, SR_geo_outer_L52, SR_geo_outer_L53, SR_geo_outer_L60, SR_geo_outer_L61, SR_geo_outer_L62, SR_geo_outer_L63, /**/SR_geo_outer_C60, SR_geo_outer_C61, SR_geo_outer_C62, SR_geo_outer_C63,  SR_geo_outer_C80, SR_geo_outer_C81, SR_geo_outer_C82, SR_geo_outer_C83, SR_geo_outer_C90, SR_geo_outer_C91, SR_geo_outer_C92, SR_geo_outer_C93, SR_geo_outer_C100, SR_geo_outer_C101, SR_geo_outer_C102, SR_geo_outer_C103, SR_geo_outer_C110, SR_geo_outer_C111, SR_geo_outer_C112, SR_geo_outer_C113, SR_geo_outer_C120, SR_geo_outer_C121, SR_geo_outer_C122, SR_geo_outer_C123, SR_geo_outer_C130, SR_geo_outer_C131, SR_geo_outer_C132, SR_geo_outer_C133, SR_geo_outer_C140, SR_geo_outer_C141, SR_geo_outer_C142, SR_geo_outer_C143, SR_geo_outer_C150, SR_geo_outer_C151, SR_geo_outer_C152, SR_geo_outer_C153},

  {SR_geo_outer_C00, SR_geo_outer_C01, SR_geo_outer_C02, SR_geo_outer_C03,  SR_geo_outer_C10, SR_geo_outer_C11, SR_geo_outer_C12, SR_geo_outer_C13, SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C30, SR_geo_outer_C31, SR_geo_outer_C32, SR_geo_outer_C33,  SR_geo_outer_C40, SR_geo_outer_C41, SR_geo_outer_C42, SR_geo_outer_C43, SR_geo_outer_C50, SR_geo_outer_C51, SR_geo_outer_C52, SR_geo_outer_C53, SR_geo_outer_C60, SR_geo_outer_C61, SR_geo_outer_C62, SR_geo_outer_C63, SR_geo_outer_C70, SR_geo_outer_C71, SR_geo_outer_C72, SR_geo_outer_C73, SR_geo_outer_C80, SR_geo_outer_C81, SR_geo_outer_C82, SR_geo_outer_C83, SR_geo_outer_C90, SR_geo_outer_C91, SR_geo_outer_C92, SR_geo_outer_C93, SR_geo_outer_C100, SR_geo_outer_C101, SR_geo_outer_C102, SR_geo_outer_C103, SR_geo_outer_C110, SR_geo_outer_C111, SR_geo_outer_C112, SR_geo_outer_C113, SR_geo_outer_C120, SR_geo_outer_C121, SR_geo_outer_C122, SR_geo_outer_C123, SR_geo_outer_C130, SR_geo_outer_C131, SR_geo_outer_C132, SR_geo_outer_C133, SR_geo_outer_C140, SR_geo_outer_C141, SR_geo_outer_C142, SR_geo_outer_C143, SR_geo_outer_C150, SR_geo_outer_C151, SR_geo_outer_C152, SR_geo_outer_C153}, 

  {SR_geo_outer_R00, SR_geo_outer_R01, SR_geo_outer_R02, SR_geo_outer_R03,  SR_geo_outer_R10, SR_geo_outer_C11, SR_geo_outer_C12, SR_geo_outer_R13, SR_geo_outer_C20, SR_geo_outer_C21, SR_geo_outer_C22, SR_geo_outer_C23, SR_geo_outer_C30, SR_geo_outer_C31, SR_geo_outer_C32, SR_geo_outer_C33,  SR_geo_outer_C40, /**/SR_geo_outer_L41, SR_geo_outer_L42, SR_geo_outer_L43, SR_geo_outer_L50, SR_geo_outer_L51, SR_geo_outer_R52, SR_geo_outer_R53, SR_geo_outer_R60, SR_geo_outer_L60, SR_geo_outer_R62, SR_geo_outer_R63, /**/SR_geo_outer_C60, SR_geo_outer_C61, SR_geo_outer_C62, SR_geo_outer_C63,  SR_geo_outer_C80, SR_geo_outer_C81, SR_geo_outer_C82, SR_geo_outer_C83, SR_geo_outer_C90, SR_geo_outer_C91, SR_geo_outer_C92, SR_geo_outer_C93, SR_geo_outer_C100, SR_geo_outer_C101, SR_geo_outer_C102, SR_geo_outer_C103, SR_geo_outer_C110, SR_geo_outer_C111, SR_geo_outer_C112, SR_geo_outer_C113, /**/SR_geo_outer_R120, SR_geo_outer_R121, SR_geo_outer_R122, SR_geo_outer_R123, SR_geo_outer_R130, SR_geo_outer_R131, SR_geo_outer_R132, SR_geo_outer_R133, SR_geo_outer_R140, SR_geo_outer_R141, SR_geo_outer_R142, SR_geo_outer_R143, SR_geo_outer_R150, SR_geo_outer_R151, SR_geo_outer_R152, SR_geo_outer_R153}, 
};

void mode_init(void){
  uint32_t x,y;
  
  for (x=0;x<22;x++){
    gate[0].offset[x]=0;
    gate[1].offset[x]=0;
    gate[2].offset[x]=0;	
    gate[3].offset[x]=0;
    
    gate[0].matrix[x]=matrixNN[x];
    gate[1].matrix[x]=matrixLL[x];
    gate[2].matrix[x]=matrixCC[x];
    gate[3].matrix[x]=matrixRR[x];

    gate[0].matrixX[x]=matrixNN[x];
    gate[1].matrixX[x]=matrixLL[x];
    gate[2].matrixX[x]=matrixCC[x];
    gate[3].matrixX[x]=matrixRR[x];

    gate[3].matrixpG[x]=&gate[3].matrix[x];
    gate[2].matrixpG[x]=&gate[2].matrix[x];
    gate[1].matrixpG[x]=&gate[1].matrix[x];
    gate[0].matrixpG[x]=&gate[0].matrix[x];

    gate[0].matrixp[x]=&gate[0].matrix[x]; 
    gate[1].matrixp[x]=&gate[1].matrix[x];
    gate[2].matrixp[x]=&gate[2].matrix[x];
    gate[3].matrixp[x]=&gate[3].matrix[x];    
  }

    // testy attach 
  //  gate[2].matrixp[1]=&CV[2];

  //  RESETC;

  for (x=0;x<64;x++){
    gate[0].modes[x]=0;
    gate[1].modes[x]=0;
    gate[2].modes[x]=0;
  }

    gate[4].flip=0;
    gate[4].shift_=0x15;
    gate[4].Gshift_[0]=0;
    gate[4].Gshift_[1]=0;
    gate[4].Gshift_[2]=0;
    gate[4].Gshift_[3]=0;
    gate[4].reset[0]=0;
    gate[4].reset[1]=0;
    gate[4].reset[2]=0;
    gate[4].reset[3]=0;
    gate[4].route=0;
    
    gate[4].gsrcnt[0]=31;
    gate[4].gsrcnt[1]=31;
    gate[4].gsrcnt[2]=31;	
    gate[4].gsrcnt[3]=31;
  
  for (x=0;x<4;x++){
    gate[x].inner=SR_geo_inner_globalC;
    gate[x].flip=0;
    gate[x].altroute=0;
    gate[x].routetype=gate[x].matrix[16]>>9; // fixed!
    
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
    gate[x].gsrcnt[0]=31;
    gate[x].gsrcnt[1]=31;
    gate[x].gsrcnt[2]=31;	
    gate[x].gsrcnt[3]=31;

  gate[x].funcbit=routebits_nodepth_typesz;
  gate[x].extent=6;
  gate[x].depths=depth_routebits_nodepth_typesz;
  gate[x].str_funcbit=routebits_nostrobe_depth_typesz; 
  gate[x].str_extent=7;
  gate[x].str_depths=depth_routebits_nostrobe_depth_typesz;
  }
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
    clksr__[www]=clksr_[www]&4095;
  }
  else gate[www].trigger=0;
    
  ww++;
  if (ww>orderings[ordercount][0]){
    ww=1;
    resetz=1;
    (*dotail[tailcount])(); // or this is 5th [www==4] www  - can also be seperate case... // fixed bug in use of Gshift_[4] now...
  }
  
    www=orderings[ordercount][ww];
    
   tmp= ((LFSR_[www] >> 31) ^ (LFSR_[www] >> 19) ^ (LFSR_[www] >> 25) ^ (LFSR_[www] >> 24)) & 1u; // 32 is 31, 19, 25, 24
   LFSR_[www] = (LFSR_[www]<<1) + tmp;
   LFSR__[www]=LFSR_[www]&4095; // MUST be 12 bits
  
  //  uint32_t outindex=0;
  uint32_t outindex=mode[www]; 
  //  if (www==3) outindex=18;//mode[www]; // testing TYPE on CVL
  //  if (outindex>15) outindex=15;

  /*  
  if (www==2) {
  flipperrr^=1; // full speed 60 KHz
  if (flipperrr) GPIOB->BSRRH=clk_route_new[2]; // we get from tail // which one
  else GPIOB->BSRRL=clk_route_new[2];
  }
  */

  (*SRgeo_outer[www][outindex])(www); 
  (*gate[www].inner)(www); 
  
  //    SRspeedtest(www); // test slowest speed
 
if (www==2)  {
  DAC_SetChannel1Data(DAC_Align_12b_R, 4095-gate[2].dac); // 1000/4096 * 3V3 == 0V8
 }
 
 if (www!=0){ 
   if (gate[strobefrom[www]].shift_ &0x01) GPIOB->BSRRH=clk_route_new[www]; // try dacfrom
   else GPIOB->BSRRL=clk_route_new[www];
 }
 else ///// www==0 TOP has TAIL only
   {
       //   tmp= gate[speedfrom[spdcount][0]].dac; // now is set by count/array
     tmp= (gate[strobefrom[www]].shift_)&4095; // now is set by count/array //fixed 20/2/2023
      tmp+=320;
      TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
      TIM1->CCR1 = tmp/2; // pulse width
    }
}
