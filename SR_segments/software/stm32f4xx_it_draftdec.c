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
#include "resources.h"

uint32_t testmodes[4]={2,12,1,1}; // TEST!

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

#define BITN_AND_OUT {				\
    shift_[w]+=bitn;					\
    dac[w]=DAC_(w, SRlength[w], dactype[w],dacpar,trigger[w]);	\
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
  bitrr = (shift_[w]>>SRlength[x]) & 0x01;		\
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
// follow with else{ }

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
      BINROUTE;							\
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

uint16_t ADCLR[3]={5,32,30}; // non-adc ADC modes

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
//uint32_t LFSR[4]={0,1,2,3}; // which SR take the LFSR bits from! default is from itself -
uint32_t adctype[4]={0,0,0,0}; // 0-basic, 1-one bit
uint32_t dactype[4]={0,0,0,0}; // 0-basic, 1-equiv bits, 2-one bit
uint32_t doit[4]={1,0,0,0}; // covers what we do with cycling bit - 0 nada, 1=invert if srdacvalue[x]<param// param is 12 bits - can be other options
uint32_t whichdoit[4]={8,8,8,8}; // dac from???

uint32_t route[4]={8,1,2,1}; // route[4]={1,9,9,9}; NLCR=1248 0->15 binary routing table

uint32_t defroute[4]={3,0,1,0}; // 0,1,2,3 NLCR - not binary code but just one!
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
  {8,1,2,1}, // 
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
uint32_t sieve[4]={3,0,1,2}; // previous one...
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

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  uint32_t lengthbit=15, new_stat, prob;
  uint32_t x, y, q, start=0;
  uint32_t bitn=0, bitnn, bitnnn, bitnnnn, bitrr, tmp, tmpp, xx;
  uint8_t trigger[4]={0,0,0,0};
  static uint32_t flipd[4]={0,0,0,0}, flipper=1, w=0, count=0;
  static uint32_t counter[4]={0,0,0,0};
  static uint32_t train[4]={0,0,0,0};
  static uint32_t tug[4]={0,0,0,0};
  
  int32_t tmpt, dacpar=0, adcpar=0;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  //  flipper^=1;
  //  if (param[0]>4090){
  //  if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  //  else   GPIOB->BSRRL=(1)<<12; //  write bits   
  //  }

    /* // we don't deal with CLKs now!  
    //TODO: ghostSRs for normed clks (with speed of these from what, from RDAC?)
  if (w==2 && counter[2]>speed[w] && speedfrom[2]==1){ // 2 is Cspeed - but we have a problem when Cspeed is from an interrupt as this is never generated...FIXED HERE
      counter[2]=0;
      flipper^=1;
      if (flipper) GPIOB->BSRRH = clk_route[clkr];  // clear bits of fake_one - clkr is 7 so all of them
      // or we can set L and R from an independent SR with only CSR as clocked from here
      else   GPIOB->BSRRL=clk_route[clkr]; //  write bits       
    }
  */

  // for the time between counts
  counter_[0]++;  counter_[1]++;  counter_[2]++;  counter_[3]++;
  
  w++;
  if (w>3) w=0;

  if (intflag[w]) { // process INT
    trigger[w]=1;
    intflag[w]=0;
    clksr_[w]=(clksr_[w]<<1)+1;     // shift on to CLKSR
  }
  else  {
    trigger[w]=0;
    clksr_[w]=(clksr_[w]<<1);
  }
  // genericLFSR for all probability modes
  tmp= ((LFSR_[w] >> 31) ^ (LFSR_[w] >> 29) ^ (LFSR_[w] >> 25) ^ (LFSR_[w] >> 24)) & 1u; // 32 is 31, 29, 25, 24
  LFSR_[w] = (LFSR_[w]<<1) + tmp;
  
  counter[w]++;

   mode[w]=testmodes[w];

  switch(mode[w]){

    /* // basic mode to test ADC/DAc modes with equiv LR modes
 
case x:
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; par=0; // for DAC
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1; // logic for ops
    GSHIFT;

    if (w==0)      {
    BITNNN;
    bitn^=ADC_(w,SRlength[w],2,0); // choose mode and params - can return 0 from adc for no effect
    }
    else
    {
    BITNNN;
    }
    PULSIN_LOGOP;    
    BITN_AND_OUT;
  }// counterw
  break; 
*/

  case 0: // for all just cycle  - ADC NONE/cycle, LR cycle, DAC 0/cycle
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC_
      dactype[2]=0;
      GSHIFT;
      JUSTCYCLE;
      if (LR[w]) {
	PULSIN_XOR;
      }
      BITN_AND_OUT;
    }
    break;
    
  case 1: // for all just pass through - ADC NONE/pass, LR pass, DAC 0/pass
    if (counter[w]>speed[w] && speed[w]!=1024){
    dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC_
    dactype[2]=0;
    GSHIFT;
    BINROUTE;
    if (LR[w]){
      PULSIN_XOR;
    }
    BITN_AND_OUT;
    }
    break;

    // 2-15 will be most important ADC/DAC modes and basics/global routes/prob modes etc.
    //- otherpar modes: 24(len), 25(len), 26(comp), 28(prob), 29(len), 30(lengthforosc), 31 (lengthforosc)
    //- REGG modes: 2/lfsr, 4/lfsr, 5/lfsr. 6/DACX. 11/lfsr, 12/lfsr, 13/lfsr, 19/dac, 27/lfsr, 

    /////////////////////////////////////////////////////////// 
  case 2: // start to draft first set of ADC and DAC modes 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(0, 1); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTEANDCYCLE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
      }
      BITN_AND_OUT;
    }
  break;
  ///////////////////////////////////////////////////////////
  // fill in LR modes from here
  /////////////////////////////////////////////////////////// 
  case 3: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=2048; adcpar=0; reggg=0; // params - reggg is for ADC - dacpar for betaf one bit filter
      ADCDACETC1(1, 2); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/*
      // exp mode just for trial - XX - strobe advances/freezes incoming GHOSTSR
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  if (trigger[w]) Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	}
	*/
      /////////////////////////////////////...
      //      prob=param[w]&31;
      prob=shift_[w]&31; // this seems to work somehow 8/12/2021
      PULSIN_LEAK; // try xor vs leak vs or...
      }
    BITN_AND_OUT;
    }
  break;

case 4: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(2, 3); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      //      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
	/*
      // XX = strobe fixes length       
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (trigger[w]) storedlength[x][w]=SRlength[x];
	  bitrr = (Gshift_[x][w]>>storedlength[x][w]) & 0x01;
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	*/
      ///////////////////////
	// trial of generic bit options - bits from which SR, from param etc.
	// route in and logop bits:
	// 1111 4 route in bits x 3 logopx = 2 bits per... 0, none, 1, xor, 2or, 3inv XOR = 8 bits = 255 too much for CV
	tmp=shift_[dacroute[w]]&255; // 8 bits - we can also interpret bits as single ones... we just seem to use 6 bits here
	for (x=0;x<4;x++){ 
	  if ((tmp&0x03) !=0){  
	    bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; 
	    Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	    bitn=logopx(bitn,bitrr,(tmp)&0x03); 
	  }
	  tmp=tmp>>2; // 4 bits
	}
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 5: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(3, 4); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	/*
      // XX = strobe reverses ghostSR in - can also use same algo to reverse our own SR
      // is it fast enough? or just have one route in
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  if (trigger[w]){
	    tmpp=Gshift_[x][w];
	    REV32; // reverse 32 bits
	    tmpp=tmpp&othermasky[SRlength[x]]; // mask the top length bits
	    Gshift_[x][w]=tmpp>>(31-SRlength[x]); // and shift 31-length bits
	  }
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; // 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
	} */   
      /////////////////////////////////////...
	// next set of generic bit options - this time for probabilities
	/*
	  00 1-TM invert cycling bit - OR with BITIN (OR *(routed^pulse)*) // OR (routedORpulse) ??
	  01 2-BITIN or loopback
	  10 3-INV of above
	  11 4- BITIN or not into cycling
	  
	  - so is 2 bits for type of prob
	  - BITN is routed / routed XOR puls so is 1 bit
	  - where we get prob is 2 bits let's say = 5 bits = 32
	*/
	BINROUTE;
	
      bitrr = (shift_[w]>>SRlength[x]) & 0x01; 

      tmpp=shift_[dacroute[w]]&31; // 5 bits
      if ((tmpp>>4)&1) {
	PULSIN_XOR;
      }

      if (tmpp==0){ 	  // invert cycling bit and OR with bitn
	if (otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn |= !(bitrr);
	  }
	else bitn |=bitrr;	
      }
      else if (tmpp&1){ // BITN or loopback
	if (!otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=bitrr;
	}
      }
      else if (tmpp&2){ // BITN or INV loopback
	if (!otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=!bitrr;
	}
      }
	else if (tmpp&3) { // 4- BITIN or not into cycling
	if (otherprobableCV(w, ((tmpp>>2&0x03)))) {
	  bitn=bitrr^bitn;
	}
	else bitn=bitrr;
	}	
      } // LR!
      BITN_AND_OUT;
    }
    break;

case 6: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(4, 5); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      //      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/*
      // XX - we XOR on STROBE our shift with the GHOST
  tmp=binroute[count][w];
  for (x=0;x<4;x++){
  if (tmp&0x01){
    if (trigger[w]) Gshift_[x][w]^=shift_[w];
    bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
    if (trigger[w]) 
      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
    bitn^=bitrr;
  }
  tmp=tmp>>1;
  }
	*/
	// - basic prob mode of entry of routed or not (into cycling). and just xor puls in...
	if ((LFSR_[w] & 4095 ) < (param[w] & 4095)){
	  BINROUTE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[x]) & 0x01; 
	}

	/////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 7: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(5, 6); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	// trial toggle/tug of above: entry of routed or not (into cycling). and just xor puls in...
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[x]) & 0x01; 
	}	
      /////////////////////////////////////...	
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 8: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=3; // params - reggg is for ADC  - here is 3 for previous DAC
      ADCDACETC1(6, 7); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	// as above but without toggle...
	if (trigger[w]){
	BINROUTE;	}
	else {
	  bitn=(shift_[w]>>SRlength[x]) & 0x01; 
	}	
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 9: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(7, 8); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	//      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/*
	  00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
	  01 2-BITIN or loopback
	  10 3-INV of above
	  11 4- BITIN or not into cycling - above
	*/
	// trial these with strobe - 00 invert bit here
	BINROUTE;
	if (trigger[w]) tug[w]^=1;
	if (tug[w])	  bitrr=(shift_[w]>>SRlength[x]) & 0x01;
	else bitrr=!((shift_[w]>>SRlength[x]) & 0x01); 
	bitn|=bitrr;
	
      /////////////////////////////////////...
      PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 10: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(8, 10); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	/*
	  00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
	  01 2-BITIN or loopback
	  10 3-INV of above
	  11 4- BITIN or not into cycling - above
	*/
	// trial these with strobe - 01 BITIN or loopback
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTE;
	}
	else bitn=((shift_[w]>>SRlength[x]) & 0x01); 
	/////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 11: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(9, 11); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
	/*
	  00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
	  01 2-BITIN or loopback
	  10 3-INV of above
	  11 4- BITIN or not into cycling - above
	*/
	// trial these with strobe - 10 BITIN or loopback//INV
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTE;
	}
	else bitn=!((shift_[w]>>SRlength[x]) & 0x01); 
	
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 12: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(10, 12); // ADCETC has GSHIFT
      if (LR[w]){
	//////////////////////////////////HERE!
	// trial of non-adc style entry and pass on here;;
	// which modes of ADC_?: 5:LFSR, 30:1bitOSC, 32: clock
	reggg=w; adcpar=param[w];
	// can also bump up type in list with a trigger[w] TODO/TEST - here we just select from 5 and 32 as 30 used param
	if (trigger[w]) tug[w]^=1;
	bitn=ADC_(w,SRlength[w],ADCLR[tug[w]],trigger[w],reggg,adcpar);  //5,30,32 as selections - 32 maybe not so interesting
	BINROUTE;
	PULSIN_XOR;
      } 
    BITN_AND_OUT;
  }
  break;

  case 13: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(11, 13); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 14: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(12, 14); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 15: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=param[2]; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(13, 2); // ADCETC has GSHIFT
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

/////////////////////from here we can't use ADCDACETC1 as we will vary the DAC but we need some macro - ADCONLY
// DAC back to 0 here

case 16:
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCONLY(14, 0);
      if (w==2){
      BINROUTEANDCYCLE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31 
    }
      else if (LR[w]) {
	//////////////////////////////////HERE!
	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/////////////////////////////////////...
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
break;

case 17:
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCONLY(15, 1); 
      if (w==2)      {
	BINROUTEANDCYCLE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31 
      }
      else if (LR[w])
	{
	  //////////////////////////////////HERE!
	  BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	  /////////////////////////////////////...
	  PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;


///////////////////////////////////////////////////////////   
  case 32:     // draft for CV+DAC and variations 0
    if (counter[w]>(speed[w]+dac[speedfrom_[w]])){ 
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
      ADCDACETC1(0, 0);
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
    PULSIN_XOR;
    } 
    BITN_AND_OUT;	
}
break;

case 33:     // draft for CV+DAC and variations 1
    tmpt=(dac[speedfrom_[w]]>>2)-(1024-speed[w]);
    if (tmpt<0) tmpt=0; 
    if (counter[w]>tmpt){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
      ADCDACETC1(0, 0);
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
      } 
      BITN_AND_OUT;	
}
break;

    case 34:     // draft for CV+DAC and variations 2
      tmpt= speed[w]-(dac[speedfrom_[w]]>>2);
if (tmpt<0) tmpt=0; 
if (counter[w]>tmpt){
  dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
      ADCDACETC1(0, 0);
      if (LR[w]){
      //////////////////////////////////HERE!
      BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
      /////////////////////////////////////...
      PULSIN_XOR;
      } 
      BITN_AND_OUT;	
      }
      break;

case 35:     // draft for CV+DAC and variations 3
if (counter[w]>((dac[speedfrom_[w]]>>2)%speed[w])){ // wrap
  dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
  ADCDACETC1(0, 0);
  if (LR[w]){
  //////////////////////////////////HERE!
  BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
  /////////////////////////////////////...
PULSIN_XOR;
 } 
BITN_AND_OUT;	
}
break;

// draft for INTmodes
case 48:	
if (trigger[w]){ 
  dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
  ADCDACETC1(0, 0);
  if (LR[w]){
  //////////////////////////////////HERE!
  BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
  /////////////////////////////////////...
PULSIN_XOR;
 } 
BITN_AND_OUT;
}
break;

// draft for CV with INT - where to place this?
case 49:
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (trigger[w]){ 
	dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
	ADCDACETC1(0, 0);
	if (LR[w]){
	//////////////////////////////////HERE!
	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	/////////////////////////////////////...
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
}
break;

	
    /// new experimental modes to test
    
  case 333: // TEST mode - with new cumulative/adding mode which joins in previous SR 26/11 from notebook/pages
    // not sure if this makes sense
    // alts are also:
    // -[ copy as enter mode - we need to flag this and also store length of routed in reg we copied]
    // - length as overlap?
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
      ADCDACETC1(0, 0);
      if (LR[w]){
      //	  BINROUTE; // fill in L and R modes here - BINROUTE is standard routings
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  //	      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	  Gshift_[x][w]=(Gshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }	  
      /////...
PULSIN_XOR;
    } 
BITN_AND_OUT;
  }
    break;

  case 334: // TEST mode as 333 but with strobe
     // - in strobe copy routed GSR to GGSR and then cycle through with/without shift back in? so they form one long SR now
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=0; reggg=0; // params - reggg is for ADC
	  ADCDACETC1(0, 0);
      if (LR[w]){
	  //	  BINROUTE; // fill in L and R modes here - BINROUTE is standard routings
	  if (trigger[w]) { 
	    tmp=binroute[count][w];
	    for (x=0;x<4;x++){
	      if (tmp&0x01){
		storedlength[x][w]=SRlength[x];
		GGshift_[x][w]=Gshift_[x][w];
		bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
		GGshift_[x][w]=(Gshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
		bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }
	  }
	  else
	    { // but we must have had a trigger to fill GGshift
	  tmp=binroute[count][w];
	  for (x=0;x<4;x++){
	    if (tmp&0x01){
	      bitrr = (GGshift_[x][w]>>storedlength[x][w]) & 0x01;
	      //	      Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	      GGshift_[x][w]=(GGshift_[x][w]<<1) + ((shift_[w]>>SRlength[w]) & 0x01);
	      bitn^=bitrr;
	    }
	    tmp=tmp>>1;
	  }	  
	    }
	  /////...
  PULSIN_XOR;
     } 
 BITN_AND_OUT;
  }
    break;
 
    ///////////////////////////////////////////////////////////////////////// 
} // switch

  if (w==2)  {
    DAC_SetChannel1Data(DAC_Align_12b_R, dac[2]); // 1000/4096 * 3V3 == 0V8 
    int j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }

  // and fake CLKs TODO - top NSR is from R/3
      // DAC for normed NSR/PWM
  if (w==3){
      tmp= dac[3]; // right hand
      tmp+=320; 
      TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
      TIM1->CCR1 = tmp/2; // pulse width
  }
      //TODO
      // fake CLKINs for L,R,C are from Cspeed==2 - this needs to be in speeds then but...
      /*
      flipper^=1;
      if (flipper) GPIOB->BSRRH = clk_route[clkr];  // clear bits of fake_one - clkr is 7 so all of them
      // or we can set L and R from an independent SR with only CSR as clocked from here
      else   GPIOB->BSRRL=clk_route[clkr]; //  write bits       
      */
}
