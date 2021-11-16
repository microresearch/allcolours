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

uint32_t testmodes[4]={0,0,0,0}; // TEST!

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
  if (w==0)      bitn=ADC_(0,SRlength[0],X,trigger[w],reggs[w],parr);	\
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

// if we go with singular defroute
#define BITNNN {								\
  bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;	\
  Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;		\
  }

// macro for alt routes for ADC and DAC
#define ADCDACETC1(X, Y){			\
  bitn=0;					\
  dactype[2]=Y;					\
  if (w==3) count=0;					\
  GSHIFT;						\
  if (w==0)      {					\
  bitn=ADC_(0,SRlength[0],X,trigger[0],reggs[0],parr);	\
  BINROUTE;						\
  }							\
  if (w==2)      {					\
  BINROUTE;						\
  }							\
  else {						\
}
// follow with else{ }


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

#include "adcetc.h" // now all of the other functions so can work on modes

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

  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  flipper^=1;
  if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  else   GPIOB->BSRRL=(1)<<12; //  write bits   
  

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
  case 0: // start to draft first set of ADc and DAC modes
    if (counter[w]>speed[w] && speed[w]!=1024){
          par=0; parr=0;     // for this macro we need   par=0/or whatever for DAC outside and parr is for ADC 
	  ADCDACETC1(0, 0);
	  ///////HERE!
	  BINROUTE; // fill in L and R modes here
	  /////...
    }
  PULSIN_XOR;
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
