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

uint32_t testmodes[4]={9,0,0,0}; // TEST!

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
uint32_t intcnt[4]={0,0,0,0};
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
uint32_t revroute[4]={1,2,3,0}; // 0,1,2,3 NLCR - reverse route
uint32_t defroutee[4]={3,0,1,1}; // 0,1,2,3 NLCR - in this one 3 routes from 1 too
uint32_t altroute[4]={3,0,0,1}; // 0,1,2,3 NLCR - not binary code but just one! // N->C, N->L, L->R, R->N = 
uint32_t ourroute[4]={0,0,0,0};

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


static inline uint32_t countbits(uint32_t i)
{
    return( countbts[i&0xFFFF] + countbts[i>>16] );
}

// 0: xbits in, 1: 1bit 2: LFSR 3: equivalent bits 4: oscillator/clock 5: DACfrom_reg 6:param_from_reg
// 7:param as comparator for a single bit - now 31 with cv
// 8: seperate LFSR running here with length/length
static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t strobe, uint32_t regg, uint32_t otherpar){
  static uint32_t n[4]={0,0,0,0}, nn[4]={0,0,0,0}, nnn[4]={0,0,0,0}; // counters
  static int32_t integrator=0, oldValue=0;
  static uint32_t k, lastbt=0; // 21/9 - we didn't have k for one bits as static - FIXED/TEST!
  static uint8_t toggle=0;
  uint32_t bt=0;

  switch(type){
  case 0: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 1: // one bit audio input
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n[reg]=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;
  case 2: // LFSR
     // if we never change that default we can replace LFSR[reg] with reg!
    bt = ((shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    break;

  case 3: // equivalent bits: we don't need limit on number of bits
    if (n[reg]>length) {
      k=(adc_buffer[12]); //
      k=k/divy[length];
      n[reg]=0;
    }
    if (k!=0) {
      bt=1;
      k--;
    }
    else bt=0;
    n[reg]++;    
    break;

  case 4:// // 1 bit oscillator - train of length 1 bits followed by y 0 bits // here we need 2 params... we use otherpar
    // otherpar can also be CV for INTmodes
    otherpar=otherpar>>8; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt=0;
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt=1;
       n[reg]++;
       nn[reg]=0;
     }         
     break;    

  case 5: // dac[otherpar] seq input we use otherpar - or just have in otherpar?
    if (length>11) length=11; //XXX //XXX12 bits or 8 bits -> padded as case 20
      if (n[reg]>length) {
	k=(dac[regg])>>(11-length); // dac is 12 bits
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 6: //param[reg] seq input - what is size of param? /or we can also just feed in otherpar
      if (length>11) length=11; //XXX12 bits or 8 bits
      if (n[reg]>length) {
	k=(param[reg])>>(11-length); 
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 7:// run LFSR-ADCshift and output a bit - again if we don't use redirection of LFSR[reg] then ...
    bt = ((ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    ADCshift_[LFSR[reg]]=(ADCshift_[LFSR[reg]]<<1)+bt;
    break;
    
  case 8:     // we accumulate bits onto a ghosted register TO TEST
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (length>11) length=11;//XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 9: // basic sequential length of bits cycling in but zeroed by param which is trigger
  if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    } 
     if (strobe) bt=0;
      else bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 10: // one bit audio input
    n[reg]++;
  if (n[reg]>50) {
    k=dac[regg];
    n[reg]=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   
   break;

  case 11:  // special case for spaced bit entry depending on length
    shift_[reg]&=spacmask[length]; //cleared
    k=(adc_buffer[12])>>8; // we want 4 bits
    shift_[reg]+=(k&1)+((k&2)<<spacc[length][0])+((k&4)<<spacc[length][1])+((k&8)<<spacc[length][2]);
    // 4 bits goes in
    // no bt return
    bt=0;
    break;   

    // strobe // latch modes - strobe becomes toggle
  case 12:     // 1-we keep on cycling ADC bits but only enter new bit on strobe - or vice versa
    if (strobe) toggle^=1;

    if (length>11) length=11; //XXXmax12bits
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      if (toggle) {// strobe
      bt = (k>>n[reg])&0x01;
      lastbt=bt;
      }
      else bt=lastbt;
    n[reg]++;    
    break;
    
  case 13:     // 2-we only cycle ADC on strobe/toggle  - or vice versa
    if (strobe) toggle^=1;
    if (length>11) length=11; //XXXmax12bits

  if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;

      if (toggle) {// strobe
    n[reg]++;    
      }
    break;

  case 14: // STROBE: 3-one bit entry
    if (strobe) toggle^=1;
    n[reg]++;
  if (n[reg]>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n[reg]=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bt=1;
  }
   else
   {
      oldValue=0;
      bt=0;
   }   

      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;
   break;

     case 15:// STROBE: run LFSR-ADCshift and output a bit - again if we don't use redirection of LFSR[reg] then ..
       if (strobe) toggle^=1;
    bt = ((ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    ADCshift_[LFSR[reg]]=(ADCshift_[LFSR[reg]]<<1)+bt;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    break;

  case 16: // STROBE for other LFSR too
     // if we never change that default we can replace LFSR[reg] with reg!
    if (strobe) toggle^=1;
    bt = ((shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
      if (toggle) {// strobe
	lastbt=bt;
      }
      else bt=lastbt;    
    break;

  case 17: // basic sequential length as in 0 but with padding if >11 bits
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 18: // otherpar/clkbit as bits in
    bt=strobe;
    break;

  case 19: // sequential clksr in TESTED!
    if (n[reg]>length) {
      k=(clksr_[reg])>>(31-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

    //// adding these modes 4/11/2021+

  case 20: // case 5 - dac[otherpar] seq input we use otherpar - or just have in otherpar?
    // padded length version
    if (n[reg]>length) {
      if (length<12) k=(dac[regg])>>(11-length); //
      else k=(dac[regg])<<(length-11);
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 21: // padded case 8    // we accumulate bits onto a ghosted register TO TEST
    // STROBE places these onto the shift register in one chunk?
    // so we don't use returned bt
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    // then bt goes into newghostSR
    ADCGshift_[reg]=(ADCGshift_[reg]<<1)+bt;

    if (strobe) { // strobe
      shift_[reg]&=invmasky[length]; // clear length bits
      shift_[reg]+=(ADCGshift_[reg]&masky[length]);
    }
    break;

  case 22:     // padded case 13 - 2-we only cycle ADC on strobe/toggle  - or vice versa
    if (strobe) toggle^=1;
      if (n[reg]>length) {
	if (length<12) k=(adc_buffer[12])>>(11-length); //
	else k=(adc_buffer[12])<<(length-11);
	n[reg]=0;
    }
      bt = (k>>n[reg])&0x01;
      if (toggle) {// strobe
    n[reg]++;    
      }
    break;

  case 23: // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
        ////// full length regardless of len    
      if (n[reg]>11) {
	k=adc_buffer[12]; //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 24: // len is otherpar but there is no shift
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
    // maybe restrict otherpar
      if (n[reg]>otherpar) {
	k=adc_buffer[12]; //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;
    
  case 25: // len is otherpar but there is shift from otherpar
    //basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
      if (n[reg]>otherpar) {
	if (otherpar<12) k=(adc_buffer[12])>>(11-otherpar); //
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

    /// comparator modes - compare to: CV/INTonly, DAC, CV+DAC/INTonly, to clksr_, to param - feed these into otherpar

  case 26: // otherpar as comparator - 10 bits standard here
     bt=0;
     if ((adc_buffer[12]>>2)>otherpar) bt=1;
     break;

  case 27: // incoming bit switches direction of LFSR
    //      case 7:// run LFSR-ADCshift and output a bit - again if we don't use redirection of LFSR[reg] then ...
    if (strobe) toggle^=1;
    if (toggle){
    bt = ((ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    ADCshift_[LFSR[reg]]=(ADCshift_[LFSR[reg]]<<1)+bt;
    }
    else {
    bt = ((ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (ADCshift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    ADCshift_[LFSR[reg]]=(ADCshift_[LFSR[reg]]>>1)+(bt<<31);
    }
    break;

  case 28:// ADC prob mode using otherpar - 10 bits in this case
      // basic sequential length of upto 12 bits cycling in - can also be xbits from param, max bits etc...
      if ((LFSR_[reg] & 1023 )<otherpar) { 
  if (length>11) length=11;
      if (n[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;
      }
    break;

    // we use otherpar to determine number of bits - equal or otherwise
     // we can also use otherpar=CV or otherwise as padding, length of bits which is not LEN!
  case 29:   // as case 17: // basic sequential length as in 0 but with padding if >11 bist
    // maybe restrict otherpar
      if (n[reg]>length) {
	if (otherpar<12) {
	  k=(adc_buffer[12])>>(11-otherpar); //
	}
	else k=(adc_buffer[12])<<(otherpar-11);
	n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
    break;

  case 30: // XOR or OR of case 4 - 1 bit oscillator and input bits
  if (length>11) length=11;
      if (nnn[reg]>length) {
	k=(adc_buffer[12])>>(11-length); //
      nnn[reg]=0;
    }
    bt = (k>>nnn[reg])&0x01;
    nnn[reg]++;    

    otherpar=otherpar>>8; // how long? it should be?
     if (n[reg]>length) { // 0s
       bt|=0; // XOR TODO
       if (nn[reg]>otherpar) {
	 n[reg]=0;
       }
       nn[reg]++;
     }
     else {
       bt|=1; // XOR TODO
       n[reg]++;
       nn[reg]=0;
     }         
     break;    
     
    ////////    
    // INT MODES ONLY FROM HERE ON!
  case 31: // INT // CV as comparator - for INT modes ONLY which don't use CV! can also be CV+DAC
    // we can also compare to: DAC, CV+DAC, to clksr_, to param - feed these into otherpar or have as options
    // 10 bits?
     bt=0;
     if (adc_buffer[12]>adc_buffer[lookupadc[reg]]) bt=1;
     break;
     
     // TODO: CV+ADC as input for some of the INT modes perhaps

     
     // cv can modulus ADC input
     
  } // switch
  return bt;
}


static inline uint16_t leaks(uint16_t x, uint16_t y, uint16_t prob, uint16_t who){ // try lazy, stickyt, leaky, decaying logic here... // who is new 20/9 for which SR we take logic from...
  //  static uint16_t timer=0;
  //  uint16_t z;
  // p as probability or time
  // keep track of how many times this is called (for each register/bit position) and flipit

  // or we can track bits recording their position for a certain lifespan
  // one bit per SR is tracked and lost... so would be leakNSR for example for that bit
  
  // but that is too deterministic... but if we share timers or if timer is across different speeds
  //  prob=1;
  // leaky XOR to test
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  //  shift_registerR=(shift_registerR<<1)+z; // we are shifting left << so bit 31 is out last one
  if ((shift_[who]&masky[prob])==0) return 1;
  //  else if (rand()%prob==0) return 1;
  return 0;
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}


//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
// logop: 0-XOR, 1-OR, 2-&, 3leaks - 0,1,2,3
static inline uint16_t logop(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // 0 is XOR< 1 is OR etc
  uint32_t ty;
  if (type==0)  return (bita ^ bitaa);
  else if (type==1) return (bita | bitaa);
  else if (type==2) return (bita ^ (!bitaa));
  else if (type==3) {
    ty=leaks(bita, bitaa,3,3);
    return ty; // leaks using RSR as random // where we get 8 from...
  }
  return bita ^ bitaa; // default
}

// 0: xbit DAC, 1: equiv DAC, 2: 1bit 3: spacers 4: strobed xbit DAC UNTESTED 5: 4 bits spaced dac/no equv 6: 
// TODO: what we add to this: shifty_spacers, sequential x bit DAC, sequential equiv DAC, seq spaced DAC
// also we can have one bit data with selection of params for BETA/filter!

static inline uint32_t DAC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t otherpar, uint32_t parame){ //
  // DAC is 12 bits
  uint32_t y,x=0;
  static uint32_t n[4]={0,0,0,0};
  static float SmoothData[4]={0.0, 0.0, 0.0, 0.0};
  static uint32_t lastout=0;
  static uint8_t toggle=0;
  
  switch(type){
  case 0:// standard bit DAC for x bits
    //    if (reg<4 && length>3 && length<32) 
    // why (length-3)? to get down to 1 bit so could also have option for full bits!
    //    length=3;
    x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; // we want 12 bits but is not really audible difference    
    break;
  case 1:
    // equivalent bit DAC for x bits - 3/11 - 32 bits max now
    x=countbits(shift_[reg]&masky[length]); // lower length bits only
    y=divy[length]; // added table for this 7/10 - updated for 32 bits
    x*=y;
    break;
  case 2: // one bit audio
    // top bit
    y=(shift_[reg]>>length)&1;
    if (y==1) x=4095;
    else x=0;
    SmoothData[reg] = SmoothData[reg] - (LPF_Beta * (SmoothData[reg] - x)); // how do we adjust beta for speed?
    x=(int)SmoothData[reg];
    break;
  case 3: //spacers - how did we do this?
    x = (shift_[reg]&0xFF)<<4; // just the lower 8 bits - no spacings
    if (length>7){ // real length >8
      x = ((shift_[reg] & 0x01) + ((shift_[reg]>>pos[length][1])&0x02) + ((shift_[reg]>>pos[length][2])&0x04) + ((shift_[reg]>>pos[length][3])&0x08) + ((shift_[reg]>>pos[length][4])&0x10) + ((shift_[reg]>>pos[length][5])&0x20) + ((shift_[reg]>>pos[length][6])&0x40) + ((shift_[reg]>>pos[length][7])&0x80))<<4;
      //       {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31 - check sense of this
    }
    break;
  case 4: // only output standard DAC on param->strobe/clock! so just maintain lastout
    if (parame) {
      x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout=x;
    }
    else x=lastout;
    break;
    /*  case 5: // hold last DAC on strobe/clk is inverse of 5// REMOVE!
    if (parame) {
      x=lastout;
    }
    else {
      x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout=x;
    }      
    break;*/    
  case 6: // toggle to hold/release DAC
    if (parame) toggle^=1;
    if (toggle) {
      x=lastout;
    }
    else {
      x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
      lastout=x;
    }      
    break;

  case 7: // 4 spaced bits out! equiv bits or not - in this case not
    x= ( ( (shift_[reg]& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift_[reg]& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift_[reg]& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift_[reg]& (1<<lastspac[length][3]))>>lastspacbac[length][3]) )<<8; // 4 bits to 12 bits
    break;

  case 8: // 4 spaced bits out! equiv bits
    x= ( ((shift_[reg]& (1<<lastspac[length][0]))>>lastspacbac[length][0]) + ((shift_[reg]& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((shift_[reg]& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((shift_[reg]& (1<<lastspac[length][3]))>>lastspacbac[length][3]) ); 
    x=countbts[x]*1023;
    break;

  case 9: // one SR is sieved out over another? as DAC option. XOR as sieve? AND as mask! TODO
    // which one...
    x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^(shift_[sieve[reg]] &masky[length-3]); // seived through previous SR
    break;

  case 10: //  one SR is sieved out over clksr for that sr. XOR as sieve? 
    x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3]; 
    x=x^(clksr_[reg] &masky[length-3]); // seived through bitsr // 
    break;

  case 11:// standard bit DAC for x bits     ///bitx length as other param rather than length:
    // but then we don't really use len? unless is cycle back
    // bit length can also be CV - how to put this in as DAC is quite fixed in macro?
    parame=parame&31; //5 bits
    x=((shift_[reg] & masky[parame])>>(rightshift[parame]))<<leftshift[parame]; 
      break;

      // sequential DACs
  case 12: // we wait for length bits then output that many bits from the top of the SR (len bit)
    if (n[reg]>length) {
      n[reg]=0;
      x=((shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length]; 
    }
    n[reg]++;              
    break;

  case 13: // we wait for parame bits then output that many bits from the top of the SR (len bit)
    if (n[reg]>parame) {
      n[reg]=0;
      x=((shift_[reg] & masky[length])>>(rightshift[length]))<<leftshift[length]; 
    }
    n[reg]++;              
    break;

  case 14:// par is mask on standard bit DAC for x bits
    //    if (reg<4 && length>3 && length<32) 
    // why (length-3)? to get down to 1 bit so could also have option for full bits!
    x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x|=otherpar;
      break;

  case 15:/// we record mask and use this to mask the regular DAC... - could also be other-than-standard DACs
    if (parame) // we record the mask 
	{
	  mask[reg]=shift_[otherpar]; // or reg can be otherpar/SR
	  }
    x=((shift_[reg] & masky[length-3])>>(rightshift[length-3]))<<leftshift[length-3];
    x|=mask[reg];
    break;

    
    ///////
  } // switch    
  return x;
}



///////////////////////////////////////////////////////////////////////// 

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 1000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void EXTI4_IRQHandler(void){ // working NSR 
  uint32_t tmp, tmpp;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  intflag[0]=1; //NSR
  intcnt[0]++;
  if (intcnt[0]>128) intcnt[0]=0;
  param[0]=counter_[0];
  counter_[0]=0;
  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  uint32_t tmp, tmpp;
  uint16_t j, bit, xx, x;
  uint32_t lengthbitl=15, new_statl, new_statr,new_statc, lengthbitc=15, lengthbitr=15; // for 2nd bit on lsr, rsr and csr
    
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) { //RSR  
    intflag[3]=1; //RSR
    intcnt[3]++;
    if (intcnt[3]>128) intcnt[0]=0;
    param[3]=counter_[3];
      counter_[3]=0;
    EXTI_ClearITPendingBit(EXTI_Line5);
 }

  if (EXTI_GetITStatus(EXTI_Line6) != RESET) { //LSR
    intflag[1]=1; //LSR
    intcnt[1]++;
    if (intcnt[1]>128) intcnt[0]=0;
    param[1]=counter_[1];
    counter_[1]=0;
    EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {// CSR
    intflag[2]=1; //CSR
    intcnt[2]++;
    if (intcnt[2]>128) intcnt[0]=0;
    param[2]=counter_[2];
    counter_[2]=0;
    EXTI_ClearITPendingBit(EXTI_Line7);
 } 
}

void TIM4_IRQHandler(void) 

{
  uint32_t temp;
  volatile static uint16_t tmp;

  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

  // map ADCs:

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode // adc6 fixed hw
    // 9: cspd, 10: clen, 11: cmode

  // modes are NOT inverted!
  
  //moden
  temp=(adc_buffer[2]+lastlastmoden+lastmoden)/3; 
  lastlastmoden=lastmoden;
  lastmoden=temp;
  mode[0]=(temp>>6); // 64 modes = 6 bits  

  // modec
  temp=(adc_buffer[11]+lastlastmodec+lastmodec)/3; 
  lastlastmodec=lastmodec;
  lastmodec=temp;
  mode[2]=(temp>>6); // 64 modes = 6 bits  

  // model
  temp=(adc_buffer[5]+lastlastmodel+lastmodel)/3; 
  lastlastmodel=lastmodel;
  lastmodel=temp;
  mode[1]=(temp>>6); // 64 modes = 6 bits  

  // moder
  temp=(adc_buffer[8]+lastlastmoder+lastmoder)/3; 
  lastlastmoder=lastmoder;
  lastmoder=temp;
  mode[3]=(temp>>6); // 64 modes = 6 bits  
  
  // speedn
  totn=totn-smoothn[nn];
  smoothn[nn]=adc_buffer[0];
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  speed[0]=logger[temp>>2];

  // speedl
  totl=totl-smoothl[ll];
  smoothl[ll]=adc_buffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;  
  speed[1]=logger[temp>>2];

  // speedr
  totr=totr-smoothr[rr];
  smoothr[rr]=adc_buffer[6];
  totr+=smoothr[rr];
  rr++;
  if (rr>=SMOOTHINGS) rr=0;
  temp=totr/SMOOTHINGS;  
  speed[3]=logger[temp>>2];

    // speedc
  totc=totc-smoothc[cc];
  smoothc[cc]=adc_buffer[9];
  totc+=smoothc[cc];
  cc++;
  if (cc>=SMOOTHINGS) cc=0;
  temp=totc/SMOOTHINGS;  
  speed[2]=logger[temp>>2];
  
  // lens from 4 to 32 - 8/11/2021 we reversed the list to save some time!

  temp=(adc_buffer[1]>>7); // 12 bits to 5 bits 
  SRlength[0]=lookuplenall[temp];

  temp=(adc_buffer[4]>>7); // 12 bits to 5 bits 
  SRlength[1]=lookuplenall[temp];

  temp=(adc_buffer[7]>>7); // 12 bits to 5 bits 
  SRlength[3]=lookuplenall[temp];

  temp=(adc_buffer[10]>>7); // 12 bits to 5 bits 
  SRlength[2]=lookuplenall[temp];

}

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  uint32_t lengthbit=15, new_stat;
  uint32_t x, y, q, start=0;
  uint32_t bitn, bitnn, bitnnn, bitnnnn, bitrr, tmp, tmpp, xx;
  uint8_t trigger[4]={0,0,0,0};
  static uint32_t flipd[4]={0,0,0,0}, flipper=1, w=0, count=0;
  static uint32_t counter[4]={0,0,0,0};
  static uint32_t train[4]={0,0,0,0};
  static uint32_t tug[4]={0,0,0,0};
  
  int32_t tmpt,par=0;
  
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
      bitn^=ADC_(w,SRlength[w],30,0,0,dac[3]); // XOR with: EQUIV BITS-TESTED!

      //      bitn^=ADC_(w,SRlength[w],27,bitn); // 27 - incoming bits switch lfsr direction - will need to change all params here
      //      tmp=SRlength[w]>>1;
      //      bitn^=ADC_(0,SRlength[w],6,0); // param[0]
      //      bitn^=ADC_(0,SRlength[w],7,0); // comparator with param[0]
      //      bitn^=ADC_(0,SRlength[w],8,0); // strobe
      //      bitn^=ADC_(w,param[0],4,param[0]>>4);
      //      bitn^=ADC_(0,SRlength[w],10,trigger[0]); // strobe ADC in
      //      bitn^=ADC_(0,SRlength[w],12,3); // one bit DAC in //param is reg to get DAC from
      // int ADC_(uint32_t reg, uint32_t length, uint32_t type, uint32_t otherpar){ // here we use length as number of bits max is 12 bits
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
	tmpp=shift_[dacroute[w]]&255;
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
    //    - triadex: we could use counters from clkins as indicator of which bits from which SR to parity-in
    // so table would be for 4 bits from 4x maxSRlength=32*4=128 (ignore lengths)
    //    bt = ((shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][0])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][1])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][2])) ^ (shift_[LFSR[reg]] >> (lfsr_taps[SRlength[LFSR[reg]]][3]))) & 1u;
    // 4 bits are each other SR counters: length 128 of counter...

      if (counter[w]>speed[w] && speed[w]!=1024){
    dactype[2]=0; 

    GSHIFT;      

    s[0]=intcnt[0]>>5; // select which one... 0,1,2,3
    ss[0]=intcnt[0]%32; // 32 bits
    s[1]=intcnt[1]>>5; // select which one... 0,1,2,3
    ss[1]=intcnt[1]%32; // 32 bits
    s[2]=intcnt[2]>>5; // select which one... 0,1,2,3
    ss[2]=intcnt[2]%32; // 32 bits
    s[3]=intcnt[3]>>5; // select which one... 0,1,2,3
    ss[3]=intcnt[3]%32; // 32 bits

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
