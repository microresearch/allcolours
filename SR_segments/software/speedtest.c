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

uint32_t testmodes[4]={0,0,0,0}; // TEST!

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
  
//for INTmodes
#define CVin31 (31-(adc_buffer[lookupadc[w]]>>7)); 

#define GSHIFT {				\
  counter[w]=0;					\
  Gshift_[w][0]=shift_[w];			\
  Gshift_[w][1]=shift_[w];			\
  Gshift_[w][2]=shift_[w];			\
  Gshift_[w][3]=shift_[w];			\
  shift_[w]=shift_[w]<<1;			\
}

#define GS(X) {					\
  Gshift_[X][0]=shift_[X];			\
  Gshift_[X][1]=shift_[X];			\
  Gshift_[X][2]=shift_[X];			\
  Gshift_[X][3]=shift_[X];			\
}

#define BITN_AND_OUT {				\
    shift_[w]+=bitn;						\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
    tmp=(w<<1);							\
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}

#define PULSOUT {				  \
  tmp=(w<<1);					  \
  if (bitn) *pulsoutLO[tmp]=pulsouts[tmp];	  \
  else *pulsoutHI[tmp]=pulsouts[tmp];		  \
  lengthbit=(SRlength[w]>>1);			      \
  new_stat=(shift_[w] & (1<<lengthbit))>>lengthbit;   \
  if (prev_stat[w]==0 && new_stat==1) flipd[w]^=1;    \
  prev_stat[w]=new_stat;			      \
  tmp++;					      \
  if (flipd[w]) *pulsoutLO[tmp]=pulsouts[tmp];	      \
  else *pulsoutHI[tmp]=pulsouts[tmp];		      \
}


#define PULSIN_XOR {				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }

#define PULSIN_OR {				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
}

// prob is upto 32 // 5 bits
#define PULSIN_LEAK {				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn=otherleaks(bitn,xx,prob,w);			\
}


#define PULSIN_LOGOP {				\
      xx=!(GPIOC->IDR & pulsins[w]);		\
      bitn=logop(bitn,xx,logtable[w]);		\
}

// reverse 32 bits for tmpp - but how to reverse based on length - reverse lowest srlength bits ?
#define REV32 {				\
  tmpp = ((tmpp >> 1) & 0x55555555) | ((tmpp & 0x55555555) << 1);	\
  tmpp = ((tmpp >> 2) & 0x33333333) | ((tmpp & 0x33333333) << 2);	\
  tmpp = ((tmpp >> 4) & 0x0F0F0F0F) | ((tmpp & 0x0F0F0F0F) << 4);	\
  tmpp = ((tmpp >> 8) & 0x00FF00FF) | ((tmpp & 0x00FF00FF) << 8);	\
  tmpp = ( tmpp >> 16             ) | ( tmpp               << 16);	\
  }

#define BINROUTE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define BINROUTEANDCYCLE {				\
  tmp=binroute[count][w];				\
  for (x=0;x<4;x++){					\
    if ((tmp&0x01) || (x==w)){				\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  }

#define JUSTCYCLE {				\
  bitrr = (shift_[w]>>SRlength[w]) & 0x01;		\
  bitn^=bitrr;						\
  }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

//if w==3 count=0 means just to reset binroute when we are out of modes which altered it
// macro for alt routes for ADC and DAC
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  if (w==3) count=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
  BINROUTE;						\
  }							\
}

#define ADCDACNOGS(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  if (w==3) count=0;					\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
  BINROUTE;						\
  }							\
}

// we still specify type of DAC here but we leave
//  if (w==2)      {
//  BINROUTE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31
//  }
//  else {

// still we have DACtype here
#define ADCONLY(X, Y){						\
    bitn=0;							\
    dactype[2]=Y;						\
    if (w==3) count=0;						\
    GSHIFT;							\
    if (w==0)							\
  {								\
      bitn=ADC_(0,SRlength[0],X,trigger[0],reggg,adcpar);	\
      BINROUTE;						\
  }								\
}


extern __IO uint16_t adc_buffer[12];
float LPF_Beta = 0.4; // 0<ß<1
uint32_t lookupadc[4]={0,3,9,6}; // CVs for speed to use in INTmodes
uint32_t dacroute[4]={2,3,3,1}; // DAC routing for probability modes etc...

#define FULL 0b11111111111111111111111111111111 //32 bits full
#define FROZENSPEED 1024 // 
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
static uint32_t Gshift_[4][4]={
 {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff},
  {0xff,0xff,0xff,0xff}
};

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
uint32_t speedfrom_[4]={3,2,1,0}; // who we get dac offset from?
uint32_t inputbit[4]={0,2,2,2}; //0-LFSR,1-ADC,2-none
uint32_t LFSR[4]={3,3,3,1}; // which SR take the LFSR bits from! default is from itself - but could be opposites eg. {2,3,0,1}
uint32_t adctype[4]={0,0,0,0}; // 0-basic, 1-one bit
uint32_t dactype[4]={0,0,0,0}; // 0-basic, 1-equiv bits, 2-one bit
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
uint32_t binroute[8][4]={ // add more routes, also what seq change of routes makes sense
    {8,1,2,1}, // default
  //  {8,1,2,4}, // route in one big circle
  //  {0,1,2,4},
  {9,3,6,9}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
  {1,2,4,8}, // only loop - this is what is added to get loop too for prob
  {8,1,2,2}, // as defroutee 3/0/1/1
  {8,1,1,2}, // as altroute 3/0/0/1
  {8,9,1,2}, // bounce L and R back and forth
  {8,1,2,5}, // others
  {2,4,8,1}, // reverse round route
};

uint32_t binroutex[8]={4632, 38457, 33825, 8728, 8472, 8600, 21016, 6210}; // above routes generated by test.c as sets of 4 bits values with first route as lowest 

  uint32_t singroute[4][4]={ // singular table for single routes - old prob modes
  {3,0,1,0},
  {3,0,1,1},
  {3,0,0,1},
  {3,0,2,1}
};
  
uint32_t dacfrom[4]={0,0,0,0};
uint32_t sieve[4]={3,3,3,3}; // previous one... - changed to R 21/12/2021
uint32_t oppose[4]={2,3,0,1};

volatile uint32_t prev_stat[4]={0,0,0,0};
static volatile uint32_t speed[4]={0,0,0,0};
volatile uint32_t dac[4]={0,0,0,0};
volatile uint32_t adc_[4]={0,0,0,0};
uint32_t counter_[4]={0,0,0,0};
static uint32_t pulsins[4]={0,1<<8,0,1<<7}; //N,L,C,R
static uint32_t LR[4]={0,1,0,1};
static uint32_t pulsouts[8]={0, 0, 1<<2,1<<15, 1<<4,1<<12, 1<<3,1<<11};
volatile uint16_t *pulsoutHI[8]={&(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOC->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL) };
//                                  0              0              PB2            PC15           PB4            PA12           PB3            PA11 
volatile uint16_t *pulsoutLO[8]={&(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOC->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH) }; // both are 16 bit registers

#include "adcetc.h" // now all of the other functions so can work on modes

int32_t oldValue, integrator, k, bt;

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  uint32_t lengthbit=15, new_stat, prob;
  uint32_t x, y, q, start=0;
  uint32_t bitn=0, bitnn, bitnnn, bitnnnn, bitrr, tmp, tmp2, tmpp, xx;
  uint32_t trigger[4]={0,0,0,0};
  static uint32_t flipd[4]={0,0,0,0}, flipper[4]={1}, w=0, count=0, flippr=0;
  static uint32_t counter[7]={0,0,0,0,0,0,0};  // last counter is for fake clks
  static uint32_t which[4]={0,0,0,0};
  static uint32_t tug[4]={0,0,0,0};
  static uint32_t orde;

  
  int32_t tmpt, dacpar=0, adcpar=0;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
    flippr^=1;
    if (flippr) GPIOB->BSRRH = (1)<<4;  // clear bits PB4
    else   GPIOB->BSRRL=(1)<<4; //  write bits   
}
