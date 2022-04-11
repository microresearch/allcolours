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

#include "macros.h"

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
uint32_t dactype[4]={66,66,0,66}; // 0-basic, 1-equiv bits, 2-one bit - 66 is new default one for all except out
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
  //{0,1,2,4},
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
  static uint32_t flipd[4]={0,0,0,0}, flipper[4]={1}, w=0, count=0;
  static uint32_t counter[7]={0,0,0,0,0,0,0};  // last counter is for fake clks
  static uint32_t which[4]={0,0,0,0};
  static uint32_t tug[4]={0,0,0,0};
  static uint32_t orde;

  
  int32_t tmpt, dacpar=0, adcpar=0;
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

  // crash detect ++ 32/64 in main.c is 14KHz //and/or speed check...
  //    flipper^=1;
  //  if (param[0]>4090){
  //    if (flipper) GPIOB->BSRRH = (1)<<12;  // clear bits PB12 - left normed clock I think
  //    else   GPIOB->BSRRL=(1)<<12; //  write bits   
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
  if (w>3) {
    w=0;
  }

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

    mode[w]=testmodes[w]; // TESTY!
    //  if (mode[w]>19)  mode[w]=19;
  // trial ADCs 0-17 for now
  //XXXXX
    //    mode[0]=7;
    //    mode[1]=17; // 17-ADC input into left
  //  mode[2]=5;
  //  mode[3]=11; 

  
  switch(mode[w]){
    // for ADC in we just have/no route in!
  case 0: // for all just pass through - ADC NONE/pass, LR pass, DAC 0/pass
    if (counter[w]>speed[w] && speed[w]!=1024){
    dacpar=0; adcpar=param[0]; reggg=3; // params - reggg is for ADC_ // chooses DAC
    dactype[2]=0;
    GSHIFT;
    if (w==0){// ADC just IN no route in
      bitn=ADC_(0,SRlength[0],0,trigger[0],reggg,adcpar); 
      //      BINROUTEOR;
    }
    else BINROUTE;
    if (LR[w]){
      PULSIN_XOR;
    }
    /*
      // maybe lose this or not - is useful if we need no feed through but to run SR
    if (w==3){    // R hand side set GSR to 0 so no pass thru - but then we need extra w==3 mode to pass through
      // live with it as we have the leaky pulse in
      Gshift_[3][0]=0; // so we never feed back in from 3 to anywhere but can use the pulses still
      Gshift_[3][1]=0;
      Gshift_[3][2]=0;
      Gshift_[3][3]=0;
      }
    */
    BITN_AND_OUT;
    }
    break;

    // maybe lose just cycle mode - replace with
  case 1: // CHANGED//just cycle  - ADC NONE/and route in - where to place this as is confusing and if we have 0/0R nothing happens
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC_
      dactype[2]=0;
      GSHIFT;
      if (w==0){
	// or we have ADC 0 in
	bitn=ADC_(0,SRlength[0],0,trigger[0],reggg,adcpar);
	BINROUTEOR;
      }
      else BINROUTE;
      if (LR[w]) {
	PULSIN_XOR;
      }
      BITN_AND_OUT;
    }
    break;
    
    // 2-15 will be most important ADC/DAC modes and basics/global routes/prob modes etc.
    //- adcpar modes: 24(len), 25(len), 26(comp), 28(prob), 29(len), 30(lengthforosc), 31 (lengthforosc)
    //- REGG modes: 2/lfsr, 4/lfsr, 5/lfsr. 6/DACX. 11/lfsr, 12/lfsr, 13/lfsr, 19/dac, 27/lfsr, 
    /*
      Basic modes:
      2- cycle and route 
      3 pass on //leaks_pulsin - where we could decide on logop without multiplying modes
      4 cycles/pass //leakpuls

      5 00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
      6 01 2-BITIN or loopback
      7 10 3-INV of above
      8 11 4- BITIN or not into cycling

      9 4 probs with SR<DAC// choose dac - dac is opposing dac or always 3 except for itself? LFSR[]
      [or these can be toggles - TEST!
      10
      11
      12

      proto for SR>DAC is: 

//      if ((LFSR_[w] & 4095 ) < (shift_[LFSR[w]] & 4095)) or 
//      if ((LFSR_[w] & 4095 ) < dac[LFSR[w]]) // as that is 12 bits and shifted already - TRIAL this

    */
    
  case 2: // start to draft first set of ADC and DAC modes 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(1, 1); // ADCETC has GSHIFT - we start DAC at 1 as we had 0 above
      if (LR[w]){
      BINROUTEANDCYCLE; 
      PULSIN_XOR;
      }
      BITN_AND_OUT;
    }
  break;
  
  case 3: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=2048; adcpar=param[0]; reggg=0; // params - reggg is for ADC - dacpar for betaf one bit filter
      ADCDACETC1(2, 2); // ADCETC has GSHIFT
      if (LR[w]){
      BINROUTE;
      prob=shift_[w]&31; // this seems to work somehow 8/12/2021
      PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param
      }
      BITN_AND_OUT;
    }
  break;

  case 4: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(3, 3); // ADCETC has GSHIFT
      if (LR[w]){
      BINROUTEANDCYCLE;
      prob=shift_[w]&31; // this seems to work somehow 8/12/2021
      PULSIN_LEAK; // try xor vs leak vs or... - uses prob as param
      } 
      BITN_AND_OUT;
    }
    break;

  case 5: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(4, 4); // ADCETC has GSHIFT
      if (LR[w]){ 	//00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) 
	BINROUTE;
	if (trigger[w])	  bitrr=(shift_[w]>>SRlength[w]) & 0x01;
	else bitrr=!((shift_[w]>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
	PULSIN_XOR;
      } // LR!
      BITN_AND_OUT;
    }
    break;
    
case 6: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(5, 5); // ADCETC has GSHIFT
      if (LR[w]){ 	//	01 2-BITIN or loopback
	if (trigger[w]){
	  BINROUTE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}
	
	PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 7:
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(6, 6); // ADCETC has GSHIFT - for adc in 6 there is no route in with larger lengths
      if (LR[w]){ 	//10 3-INV of above
	if (trigger[w]){
	  BINROUTE;
	}
	else {
	  bitn=!(shift_[w]>>SRlength[w]) & 0x01; 
	}	
	PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 8: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=3; // params - reggg is for ADC  - here is 3 for previous DAC
      ADCDACETC1(7, 7); // ADCETC has GSHIFT
      if (LR[w]){ //11 4- BITIN or not into cycling
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}	
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
  }
    break;

  case 9: // what happened? missing mode
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(8, 8); // ADCETC has GSHIFT
      if (LR[w]){ 
	BINROUTE;
	PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  /*
X3 strobe advances/freezes GHOST
X5 strobe reverses ghost - can also reverse own SR
6 strobe XOR shift with ghost???
  */
  
case 10:
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(9, 9); // ADCETC has GSHIFT
      if (LR[w]){
      tmp=binroute[count][w];
      for (x=0;x<4;x++){
	if (tmp&0x01){
	  bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	  if (trigger[w]) Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr; 
	  bitn^=bitrr;
	}
	tmp=tmp>>1;
      }
	PULSIN_XOR;
      }
    BITN_AND_OUT;
  }
  break;

  case 11: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(10, 10); // ADCETC has GSHIFT
      if (LR[w]){ 
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
      }
	PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

case 12: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=param[2]; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(11, 12); // ADCETC has GSHIFT - DAC loses case 11
      if (LR[w]){
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
	PULSIN_XOR;
      } 
    BITN_AND_OUT;
  }
  break;

  ///////////////LR modes free for all from here 13->31
  //13/14/15 until we repeat DACs so what makes most sense for next 3
  
  case 13: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=param[2]; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(12, 13); // ADCETC has GSHIFT
      if (LR[w]){//00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ?? -- 9 below
	BINROUTE;
	if (((LFSR_[w] & 4095 ) < dac[LFSR[w]])){
	  bitrr=(shift_[w]>>SRlength[w]) & 0x01;
	}
	else bitrr=!((shift_[w]>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
    PULSIN_XOR;
      }
      BITN_AND_OUT;
    }
  break;
  
case 14: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=param[2]; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(13, 14); // ADCETC has GSHIFT
      if (LR[w]){	//	01 2-BITIN or loopback
	if (((LFSR_[w] & 4095 ) < dac[LFSR[w]])){
	  BINROUTE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}		//
	PULSIN_XOR;
      }//LR
    BITN_AND_OUT;
  }
  break;

case 15: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=4095-(param[2]&4095); adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCDACETC1(14, 2); // ADCETC has GSHIFT - is DAC 2 again but with param for filter!
      if (LR[w]){ // 11 mode //11 4- BITIN or not into cycling
	if (((LFSR_[w] & 4095 ) < dac[LFSR[w]])){
	  BINROUTEANDCYCLE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}	
    PULSIN_XOR;
      }//LR
    BITN_AND_OUT;
  }
  break;

/////////////////////from here we can't use ADCDACETC1 as we will vary the DAC but we need some macro - ADCONLY
// DAC back to 0 here

// 4x4 DAC modes
  /*
1-cycle and route 16 below
2-2x strobe=prob from below
3
4-4 bit shuffle
  
00 1-TM invert cycling bit - OR with BITIN (OR (routed^pulse)) // OR (routedORpulse) ??
01 2-BITIN or loopback
   [10 3-INV of above]
11 4- BITIN or not into cycling

what are the next 16x LR modes

  */
  
case 16:
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCONLY(15, 0); // has gshift
      if (w==2){
      BINROUTEANDCYCLE; // TODO: substitute alt routes here for DAC. eg cycle, probability etc. 4x4 for 16-31 
    }
      else if (LR[w]) {
	//	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	// trial for bump up our route by trigger:
	if (trigger[w]) which[w]++;
	if (which[w]>8) which[w]=0;
	
	tmp=binroute[which[w]][w];
	for (x=0;x<4;x++){
	  if (tmp&0x01){
	    bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01;
	    Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;
	    bitn^=bitrr;
	  }	
	  tmp=tmp>>1;
	}

	
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
break;

  case 17: 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCONLY(16,0); 
      if (w==2)      { // 1st trigger=prob 00 TM
	BINROUTE;
	if (trigger[w])	  bitrr=(shift_[w]>>SRlength[w]) & 0x01;
	else bitrr=!((shift_[w]>>SRlength[w]) & 0x01); 
	bitn|=bitrr;
      }
      else if (LR[w])
	{
	  //////////////////////////////////HERE!
	  //	  BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	  // test for ADC in to LR also from extramodes.c
	  // which modes of ADC_?: from 22 is non_adc style entries eg, 29 1 bit osc
	reggg=w; adcpar=param[w];
	// can also bump up type in list with a trigger[w]: 
	//	if (trigger[w]) tug[w]^=1;
        // ADCLR is now changed as we changed modes
        bitn=ADC_(w,SRlength[w],0,trigger[w],reggg,adcpar);  //
	BINROUTE;
	/////////////////////////////////////...
	  PULSIN_XOR;
    } 
    BITN_AND_OUT;
  }
  break;

  case 18: //2nd trigger=prob 11 ENOTES 
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      ADCONLY(17, 0); // has gshift
      if (w==2){
	if (trigger[w]) tug[w]^=1;
	if (tug[w]){
	  BINROUTEANDCYCLE;
	}
	else {
	  bitn=(shift_[w]>>SRlength[w]) & 0x01; 
	}	
    }
      else if (LR[w]) {
	//	BINROUTE; // TODO: fill in L and R modes here - BINROUTE is standard routings
	PULSIN_XOR;
      } 
      BITN_AND_OUT;
    }
break;

  case 19: // trial 4 bit shuffle MODE
    if (counter[w]>speed[w] && speed[w]!=1024){
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC
      //      ADCONLY(16, 0); // has gshift - 4 bit mode matches 16 - now 4
      // special mode for spaced entry so needs to be handled differently
      bitn=0;							
      dactype[2]=6;					       
    if (w==3) count=0;					
    GSHIFT;						
    if (w==0)						
  {							
    bitn=ADC_(0,SRlength[0],4,trigger[0],reggg,adcpar); // this is now adc mode 4 - we don't use bitn and do spacmask in adc

        if (mode[3]!=0){ /// no route in TESTY FIXED!
	if (SRlength[defroute[w]]>=SRlength[w]){ // need to >> 
	  //	  tmp=(SRlength[defroute[w]]>>2)-(SRlength[w]>>2); // /4
	  // changed to OR and not ADD in 30/12/2021 to test
	  shift_[w]|=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0])) >>(lastspac[SRlength[defroute[w]]][0]))+ \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))          >> ((lastspac[SRlength[defroute[w]]][1]) - spacc[SRlength[w]][0]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))         >>((lastspac[SRlength[defroute[w]]][2]) - spacc[SRlength[w]][1]))  + \
		      ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))         >>((lastspac[SRlength[defroute[w]]][3]) - spacc[SRlength[w]][2]))); 
	  }
	  else // shift up <<
	    {
	      shift_[w]|=(((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][0]))>>(lastspac[SRlength[defroute[w]]][0])) + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][1]))<< ((spacc[SRlength[w]][0]) - lastspac[SRlength[defroute[w]]][1]))  + \
			   ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][2]))<< ((spacc[SRlength[w]][1]) - lastspac[SRlength[defroute[w]]][2]))  + \
			  ((shift_[defroute[w]]&(1<<lastspac[SRlength[defroute[w]]][3]))<< ((spacc[SRlength[w]][2]) - lastspac[SRlength[defroute[w]]][3])));
	    }
	    }
  }							            
    else if (w==2){ // DAC out
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
    } // w==2
      else if (LR[w]) { // we have 4 bit mode here to match
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
    bitn=shift_[w]&1; // fixed this 29/12/2021 - bu
    shift_[w]+=bitn;				
    dac[w]=DAC_(w, SRlength[w], dactype[w],param[w],trigger[w]); 
    PULSOUT;
    }
break;

// DAC=1 - as above for next set of 3x4 DAC modes with LR modes to fill in
///////////////// 
 
  

///////////////////////////////////////////////////////////   
  case 32:     // draft for CV+DAC and variations 0
    if (counter[w]>(speed[w]+dac[speedfrom_[w]])){ 
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
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
      dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
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
  dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
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
  dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
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
  dacpar=0; adcpar=param[0]; reggg=0; // params - reggg is for ADC // adcpar=adc_buffer[lookupadc[w]] - 12 bits
  param[w]=adc_buffer[lookupadc[w]]; //****
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

  case 121: // test case for DAC thru...
    if (counter[w]>speed[w] && speed[w]!=1024){
      counter[w]=0;
      // test 1 bit audio straight through
      k=(adc_buffer[12]); // from 0 to 4095 but where is the middle?
      //      k=0;
    integrator+=(k-oldValue);
   if(integrator>2048)
  {
     oldValue=4095;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

   dac[2]=oldValue;
    }
    break;
 
    ///////////////////////////////////////////////////////////////////////// 
} // switch

  //  dac[2]=4095;
    if (w==2)  {
    DAC_SetChannel1Data(DAC_Align_12b_R, 4095-dac[2]); // 1000/4096 * 3V3 == 0V8 
    int j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
          }


      // DAC for normed NSR/PWM
  if (w==3){
      tmp= dac[3]; // right hand
      tmp+=320; 
      TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
      TIM1->CCR1 = tmp/2; // pulse width

      // TESTY with INTmodes
      
      // fake CLKINs for L,R,C are from Cspeed==2 - this needs to be in speeds then but...
      // or we can set L and R from an independent SR with only CSR as clocked from here
      // then we would need 5,6 counters and more flippers... TRIAL

      if (counter[5]>dac[3]){ // L side
	counter[5]=0;
	flipper[0]^=1;
	if (flipper[0]) GPIOB->BSRRH = clk_route[1];  // clear bits of fake_one
	else   GPIOB->BSRRL=clk_route[1]; //  write bits
      }      

      if (counter[6]>dac[1]){ // R side
	counter[6]=0;
	flipper[1]^=1;
	if (flipper[1]) GPIOB->BSRRH = clk_route[2];  
	else   GPIOB->BSRRL=clk_route[2]; //  write bits
      }      
      
      //      if (counter[4]>(speed[2]>>1)){ // changed to >>1 or freezes some strobe modes so is x2 speed
      
      if (counter[4]>(dac[3])){ // now trying DAC 29/12/2021
	counter[4]=0;
	flipper[2]^=1;
	if (flipper[2]) GPIOB->BSRRH = clk_route[4];  
	else   GPIOB->BSRRL=clk_route[4]; //  write bits
	}
      // trial just using lowest bit 30/12/2021
      if ((shift_[3]>>SRlength[3])&0x01) GPIOB->BSRRH = clk_route[4];
      else GPIOB->BSRRL=clk_route[4]; //  write bits
      
      counter[4]++; counter[5]++; counter[6]++;

  }
}
