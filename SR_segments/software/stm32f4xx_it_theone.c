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

uint32_t testmodes[4]={60,60,60,60}; // TEST!

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
    dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	\
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
  if (pulsins[w]!=0){				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn^=xx;					\
  }						\
  }

#define PULSIN_OR {				\
  if (pulsins[w]!=0){				\
  xx=!(GPIOC->IDR & pulsins[w]);		\
  bitn|=xx;					\
  }						\
}

#define PULSIN_LOGOP {				\
    if (pulsins[w]!=0){				\
      xx=!(GPIOC->IDR & pulsins[w]);		\
      bitn=logop(bitn,xx,logtable[w]);		\
    }						\
}


// for this macro we need   par=0/or whatever for DAC outside and parr is for ADC					\
// X is adc_type, Y is dac_type
#define MULTROUTE(X, Y) {			\
  bitn=0;					\
  dactype[2]=Y;					\
  GSHIFT;						\
  if (w==0)      bitn=ADC_(0,SRlength[0],X,trigger[0],reggs[0],parr);	\
  tmp=binroute[count][w];						\
  for (x=0;x<4;x++){					\
  if (tmp&0x01){					\
  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;		\
  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;		\
  bitn^=bitrr;						\
  }							\
  tmp=tmp>>1;						\
  }							\
  PULSIN_XOR;						\
  BITN_AND_OUT;						\
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

// macro for alt routes for ADC and DAC
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[w],reggs[w],parr);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
  BINROUTE;						\
  }							\
}
// follow with else{ }


// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

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

static uint32_t GGshift_[4], cogg[4][4], GGGshift_[4]; // gshift is 4 even though we don't use one // GG is ghost in ghost

// and cycling/circling array of ghosts which can come back or go forwards/backwards - when these ghosts are copied over (on event)
// with 256 cycles/copies - or we can have variable length of this shifting array

static uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0}, Gshift_revrevcnt[4]={0,0,0,0};

// so for simple pass through by speed would be: speedfrom=0/inputbit=2/adctype=0/route=last one as bit/
//uint32_t speedfrom[4]={0,0,0,0}; //0 is CV, 1 is interrupt, 2 is DACspeedfrom_ + CV // unused so far...
uint32_t speedfrom_[4]={3,2,1,0}; // who we get dac offset from?
uint32_t inputbit[4]={0,2,2,2}; //0-LFSR,1-ADC,2-none
uint32_t LFSR[4]={0,1,2,3}; // which SR take the LFSR bits from! default is from itself -
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
uint32_t reggs[4]={3,3,3,3}; // take DACs all from last feedback reg
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
volatile uint32_t speed[4]={0,0,0,0};
volatile uint32_t dac[4]={0,0,0,0};
volatile uint32_t adc_[4]={0,0,0,0};
uint32_t counter_[4]={0,0,0,0};
static uint32_t pulsins[4]={0,1<<8,0,1<<7}; //N,L,C,R
static uint32_t pulsouts[8]={0, 0, 1<<2,1<<15, 1<<4,1<<12, 1<<3,1<<11};
volatile uint16_t *pulsoutHI[8]={&(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOB->BSRRL), &(GPIOC->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL), &(GPIOB->BSRRL), &(GPIOA->BSRRL) };
//                                  0              0              PB2            PC15           PB4            PA12           PB3            PA11 
volatile uint16_t *pulsoutLO[8]={&(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOB->BSRRH), &(GPIOC->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH), &(GPIOB->BSRRH), &(GPIOA->BSRRH) }; // both are 16 bit registers

#include "adcetc.h" // now all of the other functions so can work on modes - but shared by all/othjer it.c

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  uint32_t lengthbit=15, new_stat;
  uint32_t x, y, q, start=0;
  uint32_t bitn=0, bitnn, bitnnn, bitnnnn, bitrr, tmp, tmpp, xx;
  uint8_t trigger[4]={0,0,0,0};
  static uint32_t flipd[4]={0,0,0,0}, flipper=1, w=0, count=0;
  static uint32_t counter[4]={0,0,0,0};
  static uint32_t train[4]={0,0,0,0};
  static uint32_t tug[4]={0,0,0,0};
  
  int32_t tmpt,par=0, parr=0;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // crash detect ++ 32/64 in main.c is 14KHz
  /*       flipper^=1;
     if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
     else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

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

  case 0: // Just passes on/CSR is basic DAC 0 
    // TEST mode: start with basic pass through and basic routing - first try pass along as generic structure (no input, fixed routings, DAC out (8 bit)
    par=dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    
      // do different modes for ADC and DAC here...
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      PULSIN_XOR;
      BITN_AND_OUT;
    }// counterw
    break; 

  ///////////////////////////////////////////////////////////////////////// 
  case 1: // cycle round only
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    GSHIFT;
    bitn=(shift_[w]>>SRlength[w])& 0x01; //cycling bit
    
    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 2: // cycle and pass only
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;      

    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }// counterw
  break;

  case 3: 
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - LFSR 
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=1; // equiv DAC out, others are fixed as basic
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;
    GSHIFT;

    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],2,0); // XOR with LFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }
    PULSIN_LOGOP;    
    BITN_AND_OUT;
  }// counterw
  break; 

  case 4: // 
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - ADC1bit 
    // L: route from/bits in/logic - pass on/AND
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DAC1bit
    // R: route from/bits in/logic  - pass on/AND
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=2; 
    logtable[0]=0; logtable[1]=2; logtable[2]=0; logtable[3]=2;

    GSHIFT;

    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],1,0); // XOR with 1 bit audio
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }
    PULSIN_LOGOP;    
    BITN_AND_OUT;	 
  }// counterw
  break; 

    case 5: // 
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - ADCxbit 
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACspacers
    // R: route from/bits in/logic  - pass on/OR
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    // here we can set options
    dactype[2]=3; // spacerbit DAC out
    //    logtable[4]={0,1,0,1}; we set L and R to 1 which is OR
    logtable[0]=0; logtable[1]=3; logtable[2]=0; logtable[3]=3; // leaks

    GSHIFT;

    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],1,0); // XOR with 1 bit audio
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;    
  }
    break; 

  case 6: //
    // N: ADC/IN, route from/bits in/logic - cycleXORpass on/XOR - LFSR 
    // L: route from/bits in/logic - cycle/pass on/OR
    // C: DAC/OUT, route from/bits in/logic - cycle/pass on/XOR - DACequiv
    // R: route from/bits in/logic  - cycle/pass on/OR
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=1;
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;

    GSHIFT;

    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],2,0); // XOR with LFSR
      bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in - could be logop but...
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;        
  }// counterw
  break; 

  case 7: // 
    // N: ADC/IN, route from/bits in/logic - cyclepass on/XOR - ADC1bit 
    // L: route from/bits in/logic - cyclepass on/AND
    // C: DAC/OUT, route from/bits in/logic - cyclepass on/XOR - DAC1bit
    // R: route from/bits in/logic  - cyclepass on/AND
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=2; 
    logtable[0]=0; logtable[1]=2; logtable[2]=0; logtable[3]=2;

    GSHIFT;
    
    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],1,0); // XOR with 1 bit audio
      bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;    
  }// counterw
  break; 

    case 8: // 
    // N: ADC/IN, route from/bits in/logic - cyclepass on/XOR - ADCxbit 
    // L: route from/bits in/logic - cyclepass on/OR
    // C: DAC/OUT, route from/bits in/logic - cyclepass on/XOR - DACspacers
    // R: route from/bits in/logic  - cyclepass on/OR
    
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=3; // spacerbit DAC out
    logtable[0]=0; logtable[1]=3; logtable[2]=0; logtable[3]=3; // leaks
    
    GSHIFT;

 if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=ADC_(w,SRlength[w],1,0); // XOR with 1 bit audio
      bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    bitn^=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
      }

 PULSIN_LOGOP;    
 BITN_AND_OUT;    
  }// counterw
  break; 
  
  case 9: // just for TRIALs with other ADC/DAC options...  XXX
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - experiment with ADCs
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR

  if (counter[w]>speed[w] && speed[w]!=1024){
    // here we can set options
    dactype[2]=0; 
    //    logtable[4]={0,1,0,1}; we set L and R to 1 which is OR - just for bits in
    logtable[0]=0; logtable[1]=0; logtable[2]=0; logtable[3]=0;
    GSHIFT;
      
    //2.5-shifting of which bits <<
  
    //3-what is routing for incoming SR bits, cycling bit
    // we have default route here
    // BUT for LFSR in we have another route
    if (w==0){// w below can be zeroed...
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;
      //      bitn=0;
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
      //ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar){
      bitn^=ADC_(w,SRlength[w],0,0,0,0); // XOR with: EQUIV BITS-TESTED!

      //      bitn^=ADC_(w,SRlength[w],27,bitn); // 27 - incoming bits switch lfsr direction - will need to change all params here
      //      tmp=SRlength[w]>>1;
      //      bitn^=ADC_(0,SRlength[w],6,0); // param[0]
      //      bitn^=ADC_(0,SRlength[w],7,0); // comparator with param[0]
      //      bitn^=ADC_(0,SRlength[w],8,0); // strobe
      //      bitn^=ADC_(w,param[0],4,param[0]>>4);
      //      bitn^=ADC_(0,SRlength[w],10,trigger[0]); // strobe ADC in
      //      bitn^=ADC_(0,SRlength[w],12,3); // one bit DAC in //param is reg to get DAC from
      // new adc strobe modes: 12,13,14,15,16
      /// XXXX MARker
      //      bitn^=ADC_(0,SRlength[w],25,dac[3]>>7); // 5 bits is 32 for length
      //      bitn^=ADC_(0,SRlength[w],26,dac[3]>>7); // we want 10 bits for comparator function
      /// comparator modes - compare to: CV/INTonly, xDAC, CV+DAC/INTonly, to clksr_, to param - feed these into otherpar
      //      bitn^=ADC_(0,SRlength[w],26,clksr_[0]&1023); // we want 10 bits for comparator function
      //      bitn^=ADC_(0,SRlength[w],25,param[0]>>8); // we don't know range of param but this is about right
      // spaced bits in - 17 is padded mode// 3 is re-worked equiv bits TO TEST! // 18 is clkin bits
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;    
      }// counterw
  break; 

  /////////////////////////////////////////////////////////////////////
  
  case 10: // probability mode 0: TM cycling bit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (trigger[w]==1){
      dactype[2]=0;

      GSHIFT;
      
      bitn=(shift_[w]>>SRlength[w])& 0x01;
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 11: // probability mode 1: TM routein bit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert routed-in-bit or not, pulsbit is ORed in (TM)

    if (trigger[w]==1){ 
      dactype[2]=0; 

      GSHIFT;

      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
            
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 12: // probability mode 2: TM routein/and cycle
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycle+routed-in-bit or not, pulsbit is ORed in (TM)

    if (trigger[w]==1){ 
      dactype[2]=0;

      GSHIFT;
        
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(shift_[w]>>SRlength[w])& 0x01; 
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 13: // probability mode 3: Wiard/EN new input from pulsebit
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //3. new input (from pulsbit) or cycling bit (wiard and EN)  - if we don't have pulsebit then route
    
    if (trigger[w]==1){
      dactype[2]=0;

      GSHIFT;
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      }
      else
	{
	  if (pulsins[w]!=0) bitn=!(GPIOC->IDR & pulsins[w]); 
	  else { // if we don't use pulseins
	    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	  }	  	  
	}      
      BITN_AND_OUT;
    }
    break; 

  case 14: // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    if (trigger[w]==1){ 
      dactype[2]=0; 

      GSHIFT;
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 15: // probability mode 5 for ADC - TODO:match with other LRC modes!
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route/ADC) or cycling bit - and OR in pulsebit if...
    /// or in case of w==0 NSR we have ADC/LFSR in depending on type - but THIS is not extra to mode 14 as it will simply repeat those except for NSR
    // but now we change this so is inverted routing bit
    if (trigger[w]==1){ 
      dactype[2]=0; // basic DAC out

      GSHIFT;      
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
      bitn=(shift_[w]>>SRlength[w])& 0x01; //cycling bit XOR in     
      }
      else{
	if (w==0){
	  bitn=ADC_(w,SRlength[w],0,0,0,0);
	}
	else
	  {
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
	bitn^=1;
	  }
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 16: // probability mode 6
    //1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //6. new input (from ADCtypeX) or route in     
    // how these match/repeat above when we don't have ADC ??? - maybe do inverted route bit in for others // with cycling bit
    
    if (trigger[w]==1){
      dactype[2]=0; 

      GSHIFT;      
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) {
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
      }
      else{
	if (w==0){
	  bitn=ADC_(w,SRlength[w],0,0,0,0); 
	}
	else
	  {
	    bitn=(!(shift_[w]>>SRlength[w])) & 0x01; 
 	  }
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 
    
  case 17: // probability mode: 7
    // if SR<DAC+CV // int mode from 10-16 repeat with sr<adc+dac[2]
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (trigger[w]==1){
      dactype[2]=0;

      GSHIFT;      

      bitn=(shift_[w]>>SRlength[w])& 0x01;
      tmpt=dac[dacroute[w]]-(4095-adc_buffer[lookupadc[w]]);
      if (tmpt<0) tmpt=0; // or just add them      
      if ((LFSR_[w] & 4095 )<tmpt) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 18: // probability mode
    //    LFSR<DAC
    // first for CV modes and prob - copy of 17 which is copy of 10
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      

    bitn=(shift_[w]>>SRlength[w])& 0x01;
    if ((LFSR_[w] & 4095 )<dac[dacroute[w]]) {
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 19: // probability mode
    // first for CV modes and prob - copy of 17 which is copy of 10
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //    1. invert cycling bit or not, pulsbit is ORed in (TM)

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      

    bitn=(shift_[w]>>SRlength[w])& 0x01;

      if ((LFSR_[w] & 4095 )<param[w]) { 
	bitn=bitn^1;
      }
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 20: //as case 3 but for INT modes and with test ADC 11 mode in! CV as comparator
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - LFSR 
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR

    if (trigger[w]==1){ 
      dactype[2]=0; 
      logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;
    
      GSHIFT;
    
      if (w==0){
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	bitn^=ADC_(w,SRlength[w],11,0,0,0); // XOR with LFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }
    PULSIN_LOGOP;    
    BITN_AND_OUT;          
    }// counterw
  break; 

  case 21: // triadex inspired mode where we XOR in bits from the other SRs
    // but which bits and do we use static SR or shift ghostSRs round...
    // try ghosted SRs...
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    GSHIFT;
    
    bitn = (Gshift_[others[w][0]][w]>>SRlength[others[w][0]]) & 0x01; 
    Gshift_[others[w][0]][w]=(Gshift_[others[w][0]][w]<<1)+bitn;

    bitnn = (Gshift_[others[w][1]][w]>>SRlength[others[w][1]]) & 0x01; 
    Gshift_[others[w][1]][w]=(Gshift_[others[w][1]][w]<<1)+bitnn;

    bitnnn = (Gshift_[others[w][2]][w]>>SRlength[others[w][2]]) & 0x01; 
    Gshift_[others[w][2]][w]=(Gshift_[others[w][2]][w]<<1)+bitnnn;

    bitn^=((shift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 22: // triadex inspired mode where we XOR in bits from the other SRs
    // but which bits and do we use static SR or shift ghostSRs round...
    // this one with static SR!
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
  
    bitn = (shift_[others[w][0]]>>SRlength[others[w][0]]) & 0x01; 
    bitnn = (shift_[others[w][1]]>>SRlength[others[w][1]]) & 0x01; 
    bitnnn = (shift_[others[w][2]]>>SRlength[others[w][2]]) & 0x01; 
    bitn^=((shift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 23: // pass on but trigger bumps on default route
    // can also be multiple routes in/change to binary routing table
    
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    if (trigger[w]){
      ourroute[w]++;
      if (ourroute[w]>3) ourroute[w]=0;
    }
    
    GSHIFT;
    bitn = (Gshift_[ourroute[w]][w]>>SRlength[ourroute[w]]) & 0x01; 
    Gshift_[ourroute[w]][w]=(Gshift_[ourroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 24: // can also be multiple routes in/change to binary routing table
    // first implementation of multiple routing table
          if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic

    if (trigger[w]){ // bump up binary routing table which is route[]
      route[w]++;
      if (route[w]>15) route[w]=0; // 15 is all routes, 8,4,2,1
    }
    
    GSHIFT;

    // work with the binary routing table
    bitn=0;
    tmp=route[w]; // route can also be another SR!
    // if route to ourself then is cycling bit but we still need to cycle <<1 above!
    for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn^=bitrr;//logop(bitn,bitrr,logopp[w]); // but what if we want different logical opps for each?
    }
    tmp=tmp>>1;
    }
    
    PULSIN_XOR;
    BITN_AND_OUT;
  }// counterw
  break; 

  case 25: // can also be multiple routes in/change to binary routing table
    // implementation of multiple routing table
    // this is an INT mode with CV as the routing table
    // table is 4 bits but we can have DAC selection on extra 2 bits for all SRs
    // how this works with ADC in or we don't route that one - default route in...
    // and use bits to select types there... TRY THIS

    if (trigger[w]){ 

      tmpp=adc_buffer[lookupadc[w]]>>4; // this can also be RSR DAC! 12 bits down to 6 bits - 9/11 add 2 bits for logopps

      GSHIFT;      
      bitn=0;
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitn=logop(bitn,bitrr,(tmpp>>6)&3); // but what if we want different logical opps for each?
	//	bitn|=bitrr;

    }
    tmp=tmp>>1;
    }

    PULSIN_XOR;
    shift_[w]+=bitn;  
    dac[w]=DAC_(w, SRlength[w], (tmpp>>4)&3,param[w],trigger[w]); // all DACTypes changed here - top bits
    PULSOUT;
  }// counterw
  break; 

  case 26: // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
      if (counter[w]>speed[w] && speed[w]!=1024){
	//      tmpp=dac[dacroute[w]]>>4; 
	tmpp=shift_[dacroute[w]]&255; // 8 bits - we can also interpret bits as single ones... we just seem to use 6 bits here
      GSHIFT;      
      bitn=0;
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
	if (tmp&0x01){  
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	  Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	  //	  bitn^=bitrr;//logop(bitn,bitrr,logopp[w]); // but what if we want different logical opps for each?
	  bitn=logop(bitn,bitrr,(tmpp>>6)&3); // but what if we want different logical opps for each?
	}
	tmp=tmp>>1;
    }

      PULSIN_XOR;
      shift_[w]+=bitn;							\
      dac[w]=DAC_(w, SRlength[w], (tmpp>>4)&3,param[w],trigger[w]); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 27:     // w==0 4 bit adc entry on adc_ mode 13
    // we need to cycle in at spac points from routed one...
    
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=6; // others are fixed as basic - but should be 4 bits spaced dac out = 5/6 6 for equiv bits
    
    GSHIFT;      

    if (w==0){ // do our adc 4 bits in mode 13
      ADC_(0,SRlength[0],13,0,0,0); // pulls in bits 
    }
    else
      { // we need to extract the advanced bits from the last one
	// shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
	shift_[w]&=spacmask[SRlength[w]]; //cleared
	
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  shift_[w]+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      shift_[w]+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

	PULSIN_XOR;    
      }
    bitn=shift_[w]&1;
    shift_[w]+=bitn;				
    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]); 
    PULSOUT;
    }
  break; 

  case 28:     // w==0 4 bit adc entry on adc_ mode 13 - pass on 4 bits - this one with feedback into ADC/NSR 0
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=6; // others are fixed as basic - but should be 4 bits spaced dac out = 5/6 6 for equiv bits

    GSHIFT;      

    if (w==0){ // do our adc 4 bits in mode 13
      ADC_(0,SRlength[0],13,0,0,0); // pulls in bits 
      // we want to xor bits back in;;
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  shift_[w]^=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      shift_[w]^=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

    }
    else
      { // we need to extract the advanced bits from the last one
	// shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
	shift_[w]&=spacmask[SRlength[w]]; //cleared
	
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  shift_[w]+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      shift_[w]+=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }

      }
    PULSIN_XOR;
    
    bitn=shift_[0]&1;
    shift_[w]+=bitn;			        
    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]); 
    PULSOUT;
    }
  break;
  
  /////////////////////////////////////////////////////////////////////////
  /// new modes testings from 2/11/2021+
  /////////////////////////////////////////////////////////////////////////

  case 29: // copy of 19 trial for ADC in probablity modes - adc_buffer[12] 12 bits
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    
    GSHIFT;
    
    bitn=(shift_[w]>>SRlength[w])& 0x01;
    if ((LFSR_[w] & 4095 )<adc_buffer[12]) {
      bitn=bitn^1;
    }
    PULSIN_OR;
    BITN_AND_OUT;
  }
  break; 

  case 30:    //    ownDAC<DAC
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
    bitn=(shift_[w]>>SRlength[w])& 0x01; 
    if ((dac[w] )<dac[dacroute[w]]) { 
      bitn=bitn^1;
    }
    PULSIN_OR;
    BITN_AND_OUT;
  }
    break; 

 case 31: // speedfrom/CV.DAC template to test - 4 options here to test...
      if (counter[w]>(speed[w]+dac[speedfrom_[w]])){// add means we always slow down - other options (wrap, lookup) //1//
  
    //2//    tmpt=(dac[speedfrom_[w]]>>2)-(1024-speed[w]);
   //    if (tmpt<0) tmpt=0; 

   //3//tmpt= speed[w]-(dac[speedfrom_[w]]>>2);
   //   if (tmpt<0) tmpt=0; 

   //4//   if (counter[w]>((dac[speedfrom_[w]]>>2)%speed[w])){ // wrap

     //2/3  if (counter[w]>tmpt){
	dactype[2]=0; 

	GSHIFT;
     
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 33: // strobe case withOUT looping option
    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
    GGGshift_[w]=GGGshift_[w]<<1;
    
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    
    GGGshift_[w]+=bitn;
   
    if (trigger[w]==1) { // strobe
      shift_[w]&=invmasky[SRlength[w]]; 
      shift_[w]+=(GGGshift_[w]&masky[SRlength[w]]);
    }

    PULSOUT;
    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]);
    
    }// counterw
  break; 

  
  case 34: // strobe case with looping option
    //accumulate into GGGshift and then bang in to realSR on a CLKIN (how many accumulated bits or just whole SR length?)
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;      
    GGGshift_[w]=GGGshift_[w]<<1;

    tmp=(shift_[w]>>SRlength[w])& 0x01;
    shift_[w]+=tmp;
    
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    
    GGGshift_[w]+=bitn;
   
    if (trigger[w]==1) { // strobe
      shift_[w]&=invmasky[SRlength[w]]; 
      shift_[w]+=(GGGshift_[w]&masky[SRlength[w]]);
    }

    PULSOUT;
    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]);
    }// counterw
  break; 

  case 35: // TRIADEX 2
    //    - triadex: we could use params from clkins as indicator of which bits from which SR to parity-in
    // so table would be for 4 bits from 4x maxSRlength=32*4=128 (ignore lengths)
    //    bt = ((shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;

      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      
     // convert to param - just not sure how many bits param will have - depends?
    s[0]=(param[0]>>5)&3; // select which one... 0,1,2,3
    ss[0]=param[0]%32; // 32 bits
    s[1]=(param[1]>>5)&3; // select which one... 0,1,2,3
    ss[1]=param[1]%32; // 32 bits
    s[2]=(param[2]>>5)&3; // select which one... 0,1,2,3
    ss[2]=param[2]%32; // 32 bits
    s[3]=(param[3]>>5)&3; // select which one... 0,1,2,3
    ss[3]=param[3]%32; // 32 bits

    bitn = (shift_[s[0]] >> ss[0]) & 0x01;
    bitnn = (shift_[s[1]] >> ss[1]) & 0x01;
    bitnnn = (shift_[s[2]] >> ss[2]) & 0x01; 	
    bitnnnn = (shift_[s[3]] >> ss[3]) & 0x01; 
    
    bitn^=((shift_[w]>>SRlength[w])& 0x01)^bitnn^bitnnn^bitnnnn; 

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 36: // pulse triggers exchange between ghost and real
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    if (trigger[w]==1) { // at start we place it...
      shift_[w]=Gshift_[w][w];
    }
    
    GSHIFT;      
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    BITN_AND_OUT;
    }// counterw
  break; 

  case 37: // pulse triggers un/holding of the ghost
      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    counter[w]=0;
    
    if (trigger[w]==1) {
      GSHIFT;
    }
      
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    bitnn = (Gshift_[w][w]>>SRlength[w]) & 0x01; 
    Gshift_[w][w]=(Gshift_[w][w]<<1)+bitnn;  

    PULSIN_XOR;
    
    shift_[w]+=bitn^bitnn;

    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]);
    PULSOUT;
    }// counterw
  break; 

  case 38: // pass through or cycle is toggled by clkin bit
    // this can also be for ADC - toggle entry of ADC bit or pass through/cycle
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=9; // test the sieve 

    GSHIFT;      

    if (trigger[w]) tug[w]^=1; // tuggle
    
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  // route in
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    if (tug[w]) bitn=(shift_[w]>>SRlength[w])& 0x01;  // cycle...

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }// counterw
  break;

  /* // this only works to add dac[3] - so not very useful
  case 39:
    // additive DACs into DAC2 - except 2 itself? is this done here though?
    // = multiple DACs - but how we do this as a single mode (add/sub/wrap other DACS, additive DAC into DAC[2])
    // how could this work as a mode... we do dac[w] here so we don't want to add all...
    // and what if all modes are set to this... mode[w] i am dac out and add all...
    //    if (w==0) dac[2]=0; // ???

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0;
    
    GSHIFT;      
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;
    
    shift_[w]+=bitn;

    PULSOUT;    
    dac[2]+=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]); // additive DAC - TODO: could also be modulus dacs
    dac[2]=dac[2]&4095;
    
    }// counterw    
    break;
  */
  
  case 40: // swap over SRs on pulse in?!! or swop in only (can swop in previous SR or another?) 
    // do regular pass through and then swop with previous on trigger
    par=dac[3]; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=13; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;
    
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

      if (trigger[w]) shift_[w]=shift_[oppose[w]]; // sieve is previous one but could be opposite one
      
      PULSIN_XOR;
      BITN_AND_OUT;
    }// counterw
    break; 

  case 41: //  TM in TM: from it.c seems to use 2x comparators - one
	   //  for inv of cycling bit, one for inv of incoming bit (so
	   //  could be CV and DAC comped to LFSR/DAC)
    if (trigger[w]==1){
      dactype[2]=0;

      GSHIFT;
      
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { // cycling bit
	bitn^=1;
      }

      bitnn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitnn;  
      
      if ((LFSR_[w] & 4095 )<dac[dacroute[w]]) {
	bitnn^=1;
      }
      bitn|=bitnn;
      
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 42: // - reverse direction of shift register - could be done on a toggle: >> and << and blank/fill in bitn/complicated
    // simple feed through/pass on based on case 0 - we reverse GSR
    // OPTIONS: devroute or revroute and also maybe just reverse incoming GSR and not itself
    
    par=0; 
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      counter[w]=0;
      Gshift_[w][0]=shift_[w];
      Gshift_[w][1]=shift_[w];
      Gshift_[w][2]=shift_[w];
      Gshift_[w][3]=shift_[w];

    if (trigger[w]) tug[w]^=1; // tuggle
    if (tug[w]){
      shift_[w]=shift_[w]<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    PULSIN_OR; 
    BITN_AND_OUT;
    }
    else //in reverse - can be defroute or revroute - 2 options but revroute doesn't seem to work so well
      {
	shift_[w]=shift_[w]>>1;
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);
	PULSIN_OR;
	shift_[w] &= ~(1UL << SRlength[w]);
	shift_[w] +=(bitn << SRlength[w]);
	dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	
      }
    PULSOUT;
    }// counterw
    break; 
    ////
  case 43: // reverse of case 1 - cycle round only - not so exciting...
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic
    counter[w]=0;
    Gshift_[w][0]=shift_[w];
    Gshift_[w][1]=shift_[w];
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w];

    if (trigger[w]) tug[w]^=1; // tuggle
    if (tug[w]){
      shift_[w]=shift_[w]<<1;
      bitn=(shift_[w]>>SRlength[w])& 0x01; //cycling bit
      PULSIN_OR; 
      BITN_AND_OUT;
    }
    else //in reverse 
      {
	bitn=shift_[w]&0x01; // lowest bit
	shift_[w]=shift_[w]>>1;
	PULSIN_OR;
	shift_[w] &= ~(1UL << SRlength[w]);
	shift_[w] +=(bitn << SRlength[w]);
	dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	
      }
    PULSOUT;
    }// counterw
    break; 

  case 44: // reverse of case 2 - feed in and cycle round
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; // basic DAC out, others are fixed as basic
    counter[w]=0;
    Gshift_[w][0]=shift_[w];
    Gshift_[w][1]=shift_[w];
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w];

    if (trigger[w]) tug[w]^=1; // tuggle
    if (tug[w]){
      shift_[w]=shift_[w]<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(shift_[w]>>SRlength[w])& 0x01; 
      PULSIN_OR; 
      BITN_AND_OUT;
    }
    else //in reverse 
      {
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);

	bitn^=shift_[w]&0x01; // lowest bit
	shift_[w]=shift_[w]>>1;
	
	PULSIN_OR;
	shift_[w] &= ~(1UL << SRlength[w]);
	shift_[w] +=(bitn << SRlength[w]);
	dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	
      }
    PULSOUT;
    }// counterw
    break; 

  case 45: // - PROBABILITY to reverse direction of shift register - could be done on a toggle: >> and << and blank/fill in bitn/complicated
    // simple feed through/pass on based on case 0 - we reverse GSR
    // OPTIONS: devroute or revroute and also maybe just reverse incoming GSR and not itself
    par=0; 
    if (trigger[w]==1){
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      counter[w]=0;
      Gshift_[w][0]=shift_[w];
      Gshift_[w][1]=shift_[w];
      Gshift_[w][2]=shift_[w];
      Gshift_[w][3]=shift_[w];

      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
      shift_[w]=shift_[w]<<1;
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
    PULSIN_OR; 
    BITN_AND_OUT;
    }
    else //in reverse - can be defroute or revroute - 2 options but revroute doesn't seem to work so well
      {
	shift_[w]=shift_[w]>>1;
	bitn = (Gshift_[defroute[w]][w] & 0x01); // just the lowest bit 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]>>1);
	Gshift_[defroute[w]][w] &= ~(1UL << SRlength[defroute[w]]);
	Gshift_[defroute[w]][w] += (bitn << SRlength[defroute[w]]);
	PULSIN_OR;
	shift_[w] &= ~(1UL << SRlength[w]);
	shift_[w] +=(bitn << SRlength[w]);
	dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	
      }
    PULSOUT;
    }// counterw
    break; 

  case 46: //- cycling array of ghosts toggle in/how to toggle out
//could be keep recording into array and on INT we cycle through (XOR/OR in pass through) until we get to last recorded of max x
//uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0};

    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;      

      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=(shift_[w]>>SRlength[w])& 0x01; 
      PULSIN_XOR;    
      BITN_AND_OUT;    
      Gshift_rev[w][Gshift_revcnt[w]]=shift_[w]; // record
      Gshift_revcnt[w]++;
      if (Gshift_revcnt[w]>255) Gshift_revcnt[w]=0;

      if (trigger[w]){
      shift_[w]=Gshift_rev[w][Gshift_revrevcnt[w]]; 
      Gshift_revrevcnt[w]++;
      if (Gshift_revrevcnt[w]>255) Gshift_revrevcnt[w]=0;
      }      
  }// counterw
  break;

case 47: // GSR runs at CV speed in INT mode (try)
  // or vice versa NOW - GSR is on trigger
  bitn=0;
  if (trigger[w]==1){
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
  }

  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 48: // GSR doesn't change (becomes a revenant) 
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    //    GSHIFT;      
    shift_[w]=shift_[w]<<1;
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }// counterw
  break;

  case 49: // GSR doesn't change (becomes a revenant) on TOGGLE
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    if (trigger[w]) tug[w]^=1; // tuggle
    if (tug[w]){
        GSHIFT;
    }
    else    shift_[w]=shift_[w]<<1;
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
    }// counterw
  break;

  case 50: // GSR is masked in on trigger
    if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 
    GSHIFT;
    // do we do bitn even if is ANDed in
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
    //    bitn^=(shift_[w]>>SRlength[w])& 0x01; 
    if (trigger[w]) shift_[w]&=Gshift_[defroute[w]][w];

    PULSIN_XOR;    
    BITN_AND_OUT;    
    }// counterw
  break;
  
  case 51: // GSR only moves on trigger - not so exciting
  bitn=0;

  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      if (trigger[w]==1){
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }
      bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 52: // GSR double move on trigger in and out of main loop
    if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0;
      GSHIFT;      

      if (trigger[w]==1){
	bitnn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitnn;  
      }
      
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      //      bitn^=bitnn;
      //      bitn^=(shift_[w]>>SRlength[w])& 0x01; 

    PULSIN_XOR;    
    BITN_AND_OUT;    
  }
    break;

  case 53: // just for TRIALs with other ADC/DAC options...  XXX INT TRIGGER!!!
    // N: ADC/IN, route from/bits in/logic - pass on/XOR - experiment with ADCs
    // L: route from/bits in/logic - pass on/OR
    // C: DAC/OUT, route from/bits in/logic - pass on/XOR - DACequiv
    // R: route from/bits in/logic  - pass on/OR

    if (trigger[w]==1){
    dactype[2]=0; 
    logtable[0]=0; logtable[1]=0; logtable[2]=0; logtable[3]=0;
    GSHIFT;
      
    if (w==0){// w below can be zeroed...
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;
      tmp=lookuplenall[(adc_buffer[lookupadc[w]]>>7)];// // 12 bits to 5 bits 
      bitn^=ADC_(w,SRlength[w],29,0,0,tmp); // otherpar for length from 12 -> 5 bits
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    PULSIN_LOGOP;    
    BITN_AND_OUT;    
      }// counterw
  break; 
    
  case 54: // as 14 but now SR comped to adc
    // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    if (trigger[w]==1){ 
      dactype[2]=0; 

      GSHIFT;
      
      if ((shift_[w] & 4095 )<adc_buffer[lookupadc[w]]) { // can be another routed SR.
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 55: // as 14 but now SR comped to next SR
    // probability mode 4: wiard/en
    //    1. if SR<CV  // int mode --- SR is customSR or RSR(routed SR)
    //4. new input (from route) or cycling bit - and OR in pulsebit if...    
    //    if (trigger[w]==1){ 
  if (counter[w]>speed[w] && speed[w]!=1024){
      dactype[2]=0; 

      GSHIFT;
      
      if ((shift_[w] & 4095 )< (shift_[defroute[w]] & 4095) ) { // can be other routed SRs
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      }
      else{
	bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
	Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
	}
      PULSIN_OR;
      BITN_AND_OUT;
    }
    break; 

  case 56:
    // this one adds probability and logopx
    // was 26 but use for experimenting with routings
    // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
      if (counter[w]>speed[w] && speed[w]!=1024){
	tmpp=shift_[dacroute[w]]&255; // 8 bits - we use 8 bits
	GSHIFT;      
	bitn=0;
	// 2 bits for singular routes
	tmp=tmpp&3;
	bitn = (Gshift_[tmp][w]>>SRlength[tmp]) & 0x01; 
	Gshift_[tmp][w]=(Gshift_[tmp][w]<<1)+bitn;  
	// 2 bits or more for probability
	tmp=(tmpp>>2)&3;
	// LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
	// prob of cycling bit let's say or ADC bit in or...
	// prob of change to routes
	if (probableCV(w,tmp)){
	  tmp=(tmpp>>4)&3; // 2 bits for logopx
	  bitn=logopx(bitn, ((shift_[w]>>SRlength[w])& 0x01), tmp);  // just put in cycling bit or we can XOR in etc... could be logic bits now to test
	}
	
      PULSIN_XOR;
      shift_[w]+=bitn;
      // 2 bits for DAC
      dac[w]=DAC_(w, SRlength[w], (tmpp>>6)&3,param[w],trigger[w]); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 57: // as 56 but try with CV
    // was 26 but use for experimenting with routings
    // multiple routes in/change to binary routing table
    // implementation of multiple routing table - CV mode with dacrouted dac as source for table...
    // could also be bits from plain SR TODO
    //      if (counter[w]>speed[w] && speed[w]!=1024){
        if (trigger[w]==1){ 
	  tmpp=adc_buffer[lookupadc[w]]>>4; // this can also be RSR DAC! 12 bits down to 6 bits - 9/11 add 2 bits for logopps
	  
	GSHIFT;      
	bitn=0;
	// 2 bits for singular routes
	tmp=tmpp&3;
	bitn = (Gshift_[tmp][w]>>SRlength[tmp]) & 0x01; 
	Gshift_[tmp][w]=(Gshift_[tmp][w]<<1)+bitn;  
	// 2 bits or more for probability
	tmp=(tmpp>>2)&3;
	// LFSR<SR // LFSR<otherSR // SR<otherSR // LFSR<PARAM // or CV but we are not in INTmode
	// prob of cycling bit let's say or ADC bit in or...
	// prob of change to routes
	if (probableCV(w,tmp)){// do
	  tmp=(tmpp>>4)&3; // 2 bits for logopp
	  bitn=logopx(bitn, ((shift_[w]>>SRlength[w])& 0x01), tmp);  // just put in cycling bit or we can XOR in etc... could be logic bits now to test
	}
	
      PULSIN_XOR;
      shift_[w]+=bitn;
      // 2 bits for DAC
      dac[w]=DAC_(w, SRlength[w], (tmpp>>6)&3,param[w],trigger[w]); // all DACTypes changed here - top bits
      PULSOUT;
      }// counterw
      break; 

  case 58: // try for generic probability mode...
    // what is generic TMetc functions for prob: invert cycling bit, 
    // 4 bits for routings, 2 bits prob to modify routings (in what way?), 2 bits logic, fixed DAC
    dactype[2]=0; // basic DAC out    
    tmpp=0b11000101; // test bits for this SR 

    if (counter[w]>speed[w] && speed[w]!=1024){
	GSHIFT;      
	bitn=0;
	tmp=(tmpp>>6)&3; // top 2 bits for probability
	if (probableCV(w,tmp)){
	  tmpp &= ~(1 << w); // eg. remove loopback = clear bit w
	}

	// how we deal with modes for ADC and DAC here
	
      tmp=tmpp&15; // bottom 4 bits 
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	xx=(tmpp>>4)&3;
	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	//bitn^=bitrr;
    }
    tmp=tmp>>1;
      }	
      PULSIN_XOR;
      BITN_AND_OUT;
      PULSOUT;
      }// counterw
      break; 

  case 59: // NEW generic routing mode including ADC - replaces mode 9
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021
    
    if (counter[w]>speed[w] && speed[w]!=1024){ // speed stoppageDONE
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 

      if (w==3) {//change the global route - trigger[3] bumps the route up
	if (trigger[3]) count++;
	if (count>7) count=0;
      }      // TODO: in other w==3 modes we can set count to 0 or fix it somewhere else
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	//	xx=(tmpp>>4)&3;
	//	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

  case 60: // as generic routing but testing use of MACRO with arguments
    if (counter[w]>speed[w] && speed[w]!=1024){
    par=0; parr=0;     // for this macro we need   par=0/or whatever for DAC outside and parr is for ADC 
    MULTROUTE(31, 0);     // X is adc_type, Y is dac_type
  }
    break;

  case 61: // as generic routing but testing use of MACRO with arguments - speedCV but complimented by trigger
    if (counter[w]>speed[w] && speed[w]!=1024){
      if (trigger[w]){
    par=0; parr=0;     // for this macro we need   par=0/or whatever for DAC outside and parr is for ADC 
    MULTROUTE(0, 0);     // X is adc_type, Y is dac_type, REGG is where to take from for adc
      }
  }
    break;

    ////// modes from it.c but not using coggn so tricky
  case 62: // 
    // NEW generic routing mode including ADC - replaces mode 9
    par=0;//dac[3]&0x03; // TODO: use par for setting DAC parameter now on 4/11/2021

    if (trigger[w]){ // adc_buffer[lookupadc[w]]
      dactype[2]=0; // 1 for equiv bits //10 for clksr sieving//11 for param bits//12 for sequential
      GSHIFT;    

      // do different modes for ADC and DAC here...
      if (w==0)      bitn=ADC_(0,SRlength[0],0,0,0,0); 
      if (w==3) count=0; // default route
      
      tmp=binroute[count][w]; // was route[w]
      for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	//	xx=(tmpp>>4)&3;
	//	bitn=logop(bitn,bitrr,xx); // but what if we want different logical opps for each?
	bitn^=bitrr;
      }
      tmp=tmp>>1;
      }	
	PULSIN_XOR;
	BITN_AND_OUT;
    }// counterw
    break; 

    
    

    
    /////////////////////////////////////////////////////////////////////////
    /// extra experimental cases // tested
    /////////////////////////////////////////////////////////////////////////
  case 104:  // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
    // INT can also start new train or let old one carry on (now it starts new train...)
    if (trigger[w]==1){ 
      train[w]=1; // we can use train as counter      
    }
    if (train[w]!=0 && train[w]<(speed[w]+1)){ // number of pulses
      // do train so first we need speed counter
      if (counter[w]>dac[dacroute[w]]){ // or another dac
	train[w]++;
	// from DACR now but can be dacfrom!
	counter[w]=0;
	// now we can do any kind of SR, but guess makes sense for NSR to be LFSR or so???
	// so we borrow some from mode 3
	dactype[2]=0; // basic DAC out
    
	GSHIFT;

	if (w==0){
	  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0,0,0); // XOR with LFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    PULSIN_XOR;    
    BITN_AND_OUT;    
      }
    }
    else train[w]=0; // train ran out
    break;
    ///////////
  case 105:// this is the vice versa of the above
    // let's try INT driven one for pulse train mode
  // INT triggers train of CV pulses at speed DAC - and can also be vice versa
    // INT can also start new train or let old one carry on (now it starts new train...)
    if (trigger[w]==1){ 
      train[w]=1; // we can use train as counter      
    }
    if (train[w]!=0 && train[w]<dac[3]){ // number of pulses
      // do train so first we need speed counter
        if (counter[w]>speed[w] && speed[w]!=1024){ // or another dac
	train[w]++;
	dactype[2]=0; // basic DAC out    

	GSHIFT;
	
	if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0,0,0); // XOR with lFSR
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

	PULSIN_XOR;    
	BITN_AND_OUT;    
      }
    }
    else train[w]=0; // train ran out
    break;
  

    /////////////////////////////////////////////////////////////////////////     /////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////// 
    // what other simple modes can be: to list:

    //2-pass and cycle with other logics in L and R, other options PLUS-ADC in options, LFSR for NSR, different DACs out for CSR
  // so L and R have other logics and we go thru DAC and ADC options with simple pass through say
  // see how many modes we can manage then...
  
    // ????eg. cycle with adc, cycle with lfsr, pass with adc, pass with lfsr, pass and cycle with adc, pass and cycle with lfsr    (only for top)

    ///////////////////////////////////////////////////////////////////////// 
  } // switch

  // DAC output - but does this need to be done 4x???? 9/11/2021??? 
  // or to think about multiple DAC outputs - additive, sequential, what else?

  // for the moment we just output from dac[2] ->[0,1,2C,3]=2 is C
  //  set whichever DAC if there is a special, over-riding mode
  //  DAC_SetChannel1Data(DAC_Align_12b_R, dac[w]); // 1000/4096 * 3V3 == 0V8 
  
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
