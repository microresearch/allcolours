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

TODO:

TODO from segmodes:

- start porting SRs - more generic from AC! and try to closely replicate classic SRs after notes in fromAC.c

//
- test use of manipulated routing tables for one SR
- trial RSR as random register with various routings for simulation of electronotes and TM.
- new ghost/segmode notes

DONE:

- set up clockins for basic pass/recirculate SRs and test with norm of CSR DAC to top TIM1 NSR pulse DONE for one...
tried now with a different DAC! say from RSR! DONE

//////
1/9 - test out some basic modes with no movement/frozen at topDONE-no freezes!

30+ - overlap notes/modes, multiple shifts, multiple feedbacks, work
with array of pointers to each SR (when we have structure, still in
brainstorm)

- 28/8/2021 - spotted major bug in passing on of bitn with LFSR as
  bitn is the lfsr returning bit not the bit coming out of the top! to
  try and fix but results are not so exciting - keep that version as another option!

- sort masks and re-do anything which is clearing bits - DONE but re-check and test

- *try pulse driven basic SR structure with ADC and DAC!*

- new overlap notes from notebook - testings!

- also pulse clock or cv advances number/x once eg for cycling ghost sr
or length of ghost sr, or we can have smaller degrees of that advance,
say 1/10 so is not such a big jump

- see all segmodes notes and port AC modes...

// check logic of overlaps and lengths

// August 2021: brainstorms still but start working/testing pulse driven speeds, fill in basics and final speed adjustments
// each mode has:

// speed from CV or from pulse/interrupts, speedCV has no speed at
// slowest end, think about how we norm left, right and lower ghost
// pulses to keep things running (as cannot be straight out or delayed out but we need to test this in practice)
// pulse ins usage, pulse outs/any division...

// from late July 2021 test sketches which show directions rather than full framework


/////////////////////////////////////////////////////
//older:
- DONEfix noise in DAC out (is from speed of ADC or DAC?, what speed can we aim for? - was smoothing of speed.

- do all speeds/modes and check feedback is working...
// new interrupt for these on TIM

- test out wheel for connection between SRs
- revisit LFSR and taps
- experiment with how sets of parallel SRs might sound -> CV

  */ 

//#include "main.h"
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

/////////////////////
extern __IO uint16_t adc_buffer[12];

#define FROZENSPEED 1024 // 
#define MAXVALUE 4095
#define SMOOTHINGS 512 // we can hold 65536 of our 16 bit ADC values...speed
uint32_t cc=0, totc=0, smoothc[SMOOTHINGS];
uint32_t ll=0, totl=0, smoothl[SMOOTHINGS];
uint32_t rr=0, totr=0, smoothr[SMOOTHINGS];
uint32_t nn=0, totn=0, smoothn[SMOOTHINGS];

uint16_t modec, moden, model, moder;

uint16_t lastmodec, lastmoden, lastmodel, lastmoder;
uint16_t lastlastmodec, lastlastmoden, lastlastmodel, lastlastmoder;

volatile uint32_t shift_registern=0xff; // 32 bit SR but we can change length just using output bit
volatile uint32_t shift_registerl=0xff;
volatile uint32_t shift_registerr=0xff;
volatile uint32_t shift_registerc=0xff;
volatile uint32_t shift_registerR=0xff; 
 
// ghosts, revenants
volatile uint32_t Gshift_registern=0xff; 
volatile uint32_t Gshift_registernn=0xff; // for routing we need 2x  - this is resolved in arrays of ghosts
volatile uint32_t Gshift_registerl=0xff;
volatile uint32_t Gshift_registerr=0xff;
volatile uint32_t Gshift_registerc=0xff; 

volatile uint32_t bitn, bitl, bitr, bitc=0, bitnx, bitnn=0;
volatile uint32_t speedn, speedl, speedr, speedc=0;

volatile uint32_t countern, counterl, counterr, counterc=0;
volatile uint32_t SRlengthn=31, SRlengthl=31, SRlengthr=31, SRlengthc=31, lengthbitn=15, Slengthbitl=15, lengthbitr=15, Slengthbitc=15;
volatile uint32_t GSRlengthn=31, GSRlengthl=31, GSRlengthr=31, GSRlengthc=31;

// and also need counters for "cogs"
volatile uint32_t coggn, coggl, coggr, coggc=0;

// experimental parallel SR
uint32_t shift_registerpar[32]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
uint16_t reg[32]={0};

// from AC
static uint32_t electroprob[8]={0, 3, 7, 15, 31, 63, 127, 255};

static uint32_t bits[8]={1, 2, 4, 8, 16, 32, 64, 128};

static uint32_t MASK[32]={4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294967040, 4294966785, 4294966275, 4294965255, 4294963215, 4294959135, 4294950975, 4294934655, 4294902015, 4294836735, 4294706175, 4294445055, 4293922815, 4292878335, 4290789375, 4286611455, 4278255615, 4261543935, 4228120575, 4161273855, 4027580415, 3760193535, 3225419775, 2155872255, 16777215};

static uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

static uint32_t lookuplenodd[16]={5, 5, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31}; 

static uint32_t lookuplenall[32]={3, 3, 3, 3, 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

static uint8_t bitsz[256]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8}; // this is for 8 bits

static uint32_t rightshift[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, // first 12 bits
				1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16, 17,18,19,20};

static uint32_t leftshift[32]= {11,10,9, 8,7,6,5, 4,3,2,1,
				0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

// fixed masks 31/8/2021

static uint32_t invmasky[32]={//0,0,0, // skip all zeroes or all ones ??? skip all ones

  //0b11111111111111111111111111111111,
0b11111111111111111111111111111110,
0b11111111111111111111111111111100,
0b11111111111111111111111111111000,
0b11111111111111111111111111110000,
0b11111111111111111111111111100000,
0b11111111111111111111111111000000,
0b11111111111111111111111110000000,
0b11111111111111111111111100000000,
0b11111111111111111111111000000000,
0b11111111111111111111110000000000,
0b11111111111111111111100000000000,
0b11111111111111111111000000000000,
0b11111111111111111110000000000000,
0b11111111111111111100000000000000,
0b11111111111111111000000000000000,
0b11111111111111110000000000000000,
0b11111111111111100000000000000000,
0b11111111111111000000000000000000,
0b11111111111110000000000000000000,
0b11111111111100000000000000000000,
0b11111111111000000000000000000000,
0b11111111110000000000000000000000,
0b11111111100000000000000000000000,
0b11111111000000000000000000000000,
0b11111110000000000000000000000000,
0b11111100000000000000000000000000,
0b11111000000000000000000000000000,
0b11110000000000000000000000000000,
0b11100000000000000000000000000000,
0b11000000000000000000000000000000,
0b10000000000000000000000000000000,
0b00000000000000000000000000000000
};

  
static uint32_t masky[32]={//0,0,0, // skip all zeroes or all ones ??? all 0
			   0b00000000000000000000000000000001,			  
			   0b00000000000000000000000000000011,			  
			   0b00000000000000000000000000000111,			  
			   0b00000000000000000000000000001111,			  
			   0b00000000000000000000000000011111,			  
			   0b00000000000000000000000000111111,			  
			   0b00000000000000000000000001111111,			  
			   0b00000000000000000000000011111111,			  
			   0b00000000000000000000000111111111,			  
			   0b00000000000000000000001111111111,			  
			   0b00000000000000000000011111111111,			  
			   0b00000000000000000000111111111111,			  
			   0b00000000000000000001111111111111,			  
			   0b00000000000000000011111111111111,			  
			   0b00000000000000000111111111111111,			  
			   0b00000000000000001111111111111111,			  
			   0b00000000000000011111111111111111,			  
			   0b00000000000000111111111111111111,			  
			   0b00000000000001111111111111111111,			  
			   0b00000000000011111111111111111111,			  
			   0b00000000000111111111111111111111,			  
			   0b00000000001111111111111111111111,			  
			   0b00000000011111111111111111111111,			  
			   0b00000000111111111111111111111111,			  
			   0b00000001111111111111111111111111,			  
			   0b00000011111111111111111111111111,			  
			   0b00000111111111111111111111111111,			  
			   0b00001111111111111111111111111111,			  
			   0b00011111111111111111111111111111,			  
			   0b00111111111111111111111111111111,			  
			   0b01111111111111111111111111111111,			   
			   0b11111111111111111111111111111111,
};

static uint32_t othermasky[32]={  // skip all zeroes or all ones ???
  //  0b00000000000000000000000000000000,
  0b10000000000000000000000000000000,
  0b11000000000000000000000000000000,
  0b11100000000000000000000000000000,
  0b11110000000000000000000000000000,
  0b11111000000000000000000000000000,
  0b11111100000000000000000000000000,
  0b11111110000000000000000000000000,
  0b11111111000000000000000000000000,
  0b11111111100000000000000000000000,
  0b11111111110000000000000000000000,
  0b11111111111000000000000000000000,
  0b11111111111100000000000000000000,
  0b11111111111110000000000000000000,
  0b11111111111111000000000000000000,
  0b11111111111111100000000000000000,
  0b11111111111111110000000000000000,
  0b11111111111111111000000000000000,
  0b11111111111111111100000000000000,
  0b11111111111111111110000000000000,
  0b11111111111111111111000000000000,
  0b11111111111111111111100000000000,
  0b11111111111111111111110000000000,
  0b11111111111111111111111000000000,
  0b11111111111111111111111100000000,
  0b11111111111111111111111110000000,
  0b11111111111111111111111111000000,
  0b11111111111111111111111111100000,
  0b11111111111111111111111111110000,
  0b11111111111111111111111111111000,
  0b11111111111111111111111111111100,  
  0b11111111111111111111111111111110,
  0b11111111111111111111111111111111,
};


// TODO: test much greater range of slow speeds - and stop indicator/value at end -> first establish basic speed for all modes and then
// we can do this...

static uint16_t logger[1024]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 32, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 47, 47, 47, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 59, 59, 59, 60, 60, 61, 61, 61, 62, 62, 63, 63, 64, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 69, 69, 69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 77, 78, 78, 79, 79, 80, 80, 81, 81, 82, 82, 83, 84, 84, 85, 85, 86, 86, 87, 88, 88, 89, 89, 90, 91, 91, 92, 93, 93, 94, 94, 95, 96, 96, 97, 98, 98, 99, 100, 100, 101, 102, 102, 103, 104, 105, 105, 106, 107, 107, 108, 109, 110, 110, 111, 112, 113, 113, 114, 115, 116, 117, 117, 118, 119, 120, 121, 121, 122, 123, 124, 125, 126, 127, 127, 128, 129, 130, 131, 132, 133, 134, 135, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 161, 162, 163, 164, 165, 166, 167, 168, 170, 171, 172, 173, 174, 175, 177, 178, 179, 180, 181, 183, 184, 185, 186, 188, 189, 190, 192, 193, 194, 196, 197, 198, 200, 201, 202, 204, 205, 206, 208, 209, 211, 212, 214, 215, 216, 218, 219, 221, 222, 224, 225, 227, 229, 230, 232, 233, 235, 236, 238, 240, 241, 243, 245, 246, 248, 250, 251, 253, 255, 257, 258, 260, 262, 264, 265, 267, 269, 271, 273, 275, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298, 300, 302, 304, 306, 308, 310, 312, 314, 317, 319, 321, 323, 325, 328, 330, 332, 334, 337, 339, 341, 343, 346, 348, 351, 353, 355, 358, 360, 363, 365, 368, 370, 373, 375, 378, 380, 383, 385, 388, 391, 393, 396, 399, 401, 404, 407, 410, 413, 415, 418, 421, 424, 427, 430, 433, 436, 439, 441, 444, 448, 451, 454, 457, 460, 463, 466, 469, 472, 476, 479, 482, 485, 489, 492, 495, 499, 502, 506, 509, 513, 516, 520, 523, 527, 530, 534, 537, 541, 545, 549, 552, 556, 560, 564, 567, 571, 575, 579, 583, 587, 591, 595, 599, 603, 607, 611, 616, 620, 624, 628, 632, 637, 641, 645, 650, 654, 659, 663, 668, 672, 677, 681, 686, 691, 695, 700, 705, 710, 715, 719, 724, 729, 734, 739, 744, 749, 754, 760, 765, 770, 775, 780, 786, 791, 796, 802, 807, 813, 818, 824, 830, 835, 841, 847, 852, 858, 864, 870, 876, 882, 888, 894, 900, 906, 912, 918, 925, 931, 937, 944, 950, 956, 963, 969, 976, 983, 989, 996, 1003, 1010, 1017, 1024}; //

// array for taps
// eg. 32-bit Galois LFSR with taps at 32, 30, 26, 25. Sequence length is 4294967295. 0 is a lock-up state.  -- minus one here - 31, 29, 25, 24
// bith= ((shift_registerh >> 31) ^ (shift_registerh >> 29) ^ (shift_registerh >> 25) ^ (shift_registerh >> 24)) & 1u; // 32 is 31, 29, 25, 24
// from: http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
// and reworked for length in test.c -> not so if we revert to basic code...
// note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

static uint8_t lfsr_taps[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 2, 1},
        {5, 4, 2, 1},
        {6, 5, 4, 3},
        {7, 5, 4, 3},
        {8, 7, 5, 4},
        {9, 8, 6, 5},
        {10, 9, 8, 6},
        {11, 10, 7, 5},
        {12, 11, 9, 8},
        {13, 12, 10, 8},
        {14, 13, 12, 10},
        {15, 13, 12, 10},
        {16, 15, 14, 13},
        {17, 16, 15, 12},
        {18, 17, 16, 13},
        {19, 18, 15, 13},
        {20, 19, 18, 15},
        {21, 18, 17, 16},
        {22, 21, 19, 17},
        {23, 22, 20, 19},
        {24, 23, 22, 21},
        {25, 24, 23, 19},
        {26, 25, 24, 21},
        {27, 26, 23, 21},
        {28, 27, 26, 24},
        {29, 28, 25, 23},
        {30, 29, 28, 27},
        {31, 29, 25, 24},
  };

static uint8_t ghost_tapsL[32][4] = { // left hand path
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {3, 2, 0, 0},
        {4, 3, 2, 1},
        {5, 4, 2, 1},
        {6, 5, 4, 3},
        {7, 5, 4, 3},
        {8, 7, 5, 4},
        {9, 8, 6, 5},
        {10, 9, 8, 6},
        {11, 10, 7, 5},
        {12, 11, 9, 8},
        {13, 12, 10, 8},
        {14, 13, 12, 10},
        {15, 13, 12, 10},
        {16, 15, 14, 13},
        {17, 16, 15, 12},
        {18, 17, 16, 13},
        {19, 18, 15, 13},
        {20, 19, 18, 15},
        {21, 18, 17, 16},
        {22, 21, 19, 17},
        {23, 22, 20, 19},
        {24, 23, 22, 21},
        {25, 24, 23, 19},
        {26, 25, 24, 21},
        {27, 26, 23, 21},
        {28, 27, 26, 24},
        {29, 28, 25, 23},
        {30, 29, 28, 27},
        {31, 29, 25, 24},
  };


static uint8_t lfsr_taps_mirrored[32][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {3, 2, 2, 0},
        {4, 2, 1, 0},
        {5, 3, 2, 0},
        {6, 2, 1, 0},
        {7, 3, 2, 1},
        {8, 3, 2, 0},
        {9, 3, 2, 0},
        {10, 3, 1, 0},
        {11, 5, 3, 0},
        {12, 3, 2, 0},
        {13, 4, 2, 0},
        {14, 3, 1, 0},
        {15, 4, 2, 1},
        {16, 2, 1, 0},
        {17, 4, 1, 0},
        {18, 4, 1, 0},
        {19, 5, 3, 0},
        {20, 4, 1, 0},
        {21, 4, 3, 2},
        {22, 4, 2, 0},
        {23, 3, 2, 0},
        {24, 2, 1, 0},
        {25, 5, 1, 0},
        {26, 4, 1, 0},
        {27, 5, 3, 0},
        {28, 3, 1, 0},
        {29, 5, 3, 0},
        {30, 2, 1, 0},
        {31, 6, 5, 1},
	 };

static uint8_t ghost_tapsR[32][4] = { // right hands path
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {3, 2, 2, 0},
        {4, 2, 1, 0},
        {5, 3, 2, 0},
        {6, 2, 1, 0},
        {7, 3, 2, 1},
        {8, 3, 2, 0},
        {9, 3, 2, 0},
        {10, 3, 1, 0},
        {11, 5, 3, 0},
        {12, 3, 2, 0},
        {13, 4, 2, 0},
        {14, 3, 1, 0},
        {15, 4, 2, 1},
        {16, 2, 1, 0},
        {17, 4, 1, 0},
        {18, 4, 1, 0},
        {19, 5, 3, 0},
        {20, 4, 1, 0},
        {21, 4, 3, 2},
        {22, 4, 2, 0},
        {23, 3, 2, 0},
        {24, 2, 1, 0},
        {25, 5, 1, 0},
        {26, 4, 1, 0},
        {27, 5, 3, 0},
        {28, 3, 1, 0},
        {29, 5, 3, 0},
        {30, 2, 1, 0},
        {31, 6, 5, 1},
	 };


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
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
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

// TEST: inpulse interrupts to attach are: CSR: PC3nowPB7, NSR: PC4, RSR: PC5, LSR: PB6

void EXTI4_IRQHandler(void){ // working NSR 
  static uint16_t flipper=0;
  uint32_t tmp, tmpp;
if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
  
  // flip PB4 to test interrupt on NSR PC4
  //    flipper^=1;
  //    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
  //    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  //////////////////////////////////////////
  // simple code to test pulse in
  //////////////////////////////////////////
  /*  
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  */
  //////////////////////////////////////////
  //  1- Turing Machine: cycle bit if noise vs. comp > than X, otherwise invert cycling bit so goes from probability - all flips to no flips
  // so we can get probability from: SR (x bits are 1), SR DAC (x bits),
  // CV in as comparator for SR DAC, CV as comparator for ADC in, ADC as
  // comparator for SR DAC -- DAC routing for this
  // rough and ready - to abstract out more what we have here
  // but seems to work if a bit unstable
  // can also imagine variations of this and TM within TM - eg. cycling of its own bitn (try this now and works very well)
  // or of LFSR bits TODO!
  //////////////////////////////////////////
  // this more complex version works very well - again how to abstract it with routings for DACs
  // let's use DAC from RSR 12 lower bits as probability vs CV.
  bitn=(Gshift_registern>>SRlengthn) & 0x01; // try overlap with/without this shift
  shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    // say bitr is cycling bit
    //      tmp=((shift_registerc & masky[SRlengthc-3])>>(rightshift[SRlengthc-3]))<<leftshift[SRlengthc-3]; // we want 12 bits but is not really audible difference
    tmp=shift_registerr>>19; // top 12 bits -32-19
    tmpp=shift_registerl>>19; // top 12 bits -32-19
    // but sRR is not really random - we would need a proper LFSR/dedicated
    // where can we get another comparator for bitn from? - unless we use length here
    if (tmp<adc_buffer[0]) bitn^=1;
    //    if (tmp<adc_buffer[0]) { // or try to compare to other SR? eg SRL
    if (tmp<tmpp) { // or try to compare to other SR? eg SRL
      if (coggr==0)    shift_registern+= bitr | bitn;
      else shift_registern+= ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01) | bitn;
    }
    else
      {
      if (coggr==0)    shift_registern+= !bitr | bitn;
      else shift_registern+= !((shift_registerr>>(SRlengthr-(coggr-1)))&0x01) | bitn;
      }
      
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;


  EXTI_ClearITPendingBit(EXTI_Line4);
 }
 }

void EXTI9_5_IRQHandler(void){ // PC5 RSR works and PB6 LSR share same line but both work out
  // added PB7 now for CSRCLKIN CSR which moved from PC3!!!

  static uint16_t flipper=0;
if (EXTI_GetITStatus(EXTI_Line5) != RESET) {

  // CSR: PC3->now PB7, NSR: PC4, RSR: PC5, LSR: PB6
  
  // flip PB4 to test interrupt on  RSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   
  
  EXTI_ClearITPendingBit(EXTI_Line5);
 }

 if (EXTI_GetITStatus(EXTI_Line6) != RESET) {

  // flip PB4 to test interrupt on LSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line6);
 } 

  if (EXTI_GetITStatus(EXTI_Line7) != RESET) {

  // flip PB4 to test interrupt on PB7 -> CSR
    flipper^=1;
    if (flipper) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  EXTI_ClearITPendingBit(EXTI_Line7);
 } 

}

uint16_t leaks(uint16_t x, uint16_t y, uint16_t prob){ // try lazy, stickyt, leaky, decaying logic here...
  static uint16_t timer=0;
  uint16_t z;
  // p as probability or time
  // keep track of how many times this is called and flip bit

  // or we can track bits recording their position for a certain lifespan
  // one bit per SR is tracked and lost... so would be leakNSR for example for that bit
  
  // but that is too deterministic... but if we share timers or if timer is across different speeds
  //  prob=1;
  // leaky XOR to test
  if (prob>31) prob=31;
  
  if (x^y==0) return 0;
  shift_registerR=(shift_registerR<<1)+z; // we are shifting left << so bit 31 is out last one
  if ((shift_registerR&masky[prob])==0) return 1;
  //  else if (rand()%prob==0) return 1;
  return 0;
  
  /*  timer++;
  if (timer>p){
    timer=0;
    d^=1;
    }*/
}

void TIM4_IRQHandler(void) 
// HERE we do speed and modes

{
  uint32_t temp;
  volatile static uint16_t tmp;

  TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 

  /*  
      tmp^=1;
      if (tmp) GPIOB->BSRRH = (1)<<4;  // clear bits PB2
      else   GPIOB->BSRRL=(1)<<4; //  write bits   
  */

    // map ADCs: note all modes are inverted

    // 0: nspd, 1: nlen, 2: nmode
    // 3: lspd, 4: llen, 5: lmode
    // 6: rspd, 7: rlen, 8: rmode // adc6 fixed hw
    // 9: cspd, 10: clen, 11: cmode

  // deal with PWM for normings (always follows speedn - or now we think it should follow DAC out)
  
  // double-check inversion of modes? as doesn't seem so!
  // modes are NOT inverted!
  
  //moden
  temp=(adc_buffer[2]+lastlastmoden+lastmoden)/3; //smoothing necessary for higher speeds - TEST!
  lastlastmoden=lastmoden;
  lastmoden=temp;
  moden=(temp>>6); // 64 modes = 6 bits  

  // modec
  temp=(adc_buffer[11]+lastlastmodec+lastmodec)/3; //smoothing necessary for higher speeds - TEST!
  lastlastmodec=lastmodec;
  lastmodec=temp;
  modec=(temp>>6); // 64 modes = 6 bits  

  // model
  temp=(adc_buffer[5]+lastlastmodel+lastmodel)/3; //smoothing necessary for higher speeds - TEST!
  lastlastmodel=lastmodel;
  lastmodel=temp;
  model=(temp>>6); // 64 modes = 6 bits  

  // moder
  temp=(adc_buffer[8]+lastlastmoder+lastmoder)/3; //smoothing necessary for higher speeds - TEST!
  lastlastmoder=lastmoder;
  lastmoder=temp;
  moder=(temp>>6); // 64 modes = 6 bits  
   
  // speedn
  totn=totn-smoothn[nn];
  smoothn[nn]=adc_buffer[0];
  totn+=smoothn[nn];
  nn++;
  if (nn>=SMOOTHINGS) nn=0;
  temp=totn/SMOOTHINGS;  
  speedn=logger[temp>>2];

  // speedl
  totl=totl-smoothl[ll];
  smoothl[ll]=adc_buffer[3];
  totl+=smoothl[ll];
  ll++;
  if (ll>=SMOOTHINGS) ll=0;
  temp=totl/SMOOTHINGS;  
  speedl=logger[temp>>2];

  // speedr
  totr=totr-smoothr[rr];
  smoothr[rr]=adc_buffer[6];
  totr+=smoothr[rr];
  rr++;
  if (rr>=SMOOTHINGS) rr=0;
  temp=totr/SMOOTHINGS;  
  speedr=logger[temp>>2];

    // speedc
  totc=totc-smoothc[cc];
  smoothc[cc]=adc_buffer[9];
  totc+=smoothc[cc];
  cc++;
  if (cc>=SMOOTHINGS) cc=0;
  temp=totc/SMOOTHINGS;  
  speedc=logger[temp>>2];

  
  
  // lens from 4 to 32
  // test now 1/9/2021 constraining to odd numbers and we can go small...

  temp=31-(adc_buffer[1]>>7); // 12 bits to 5 bits 
  SRlengthn=lookuplenall[temp];

  temp=31-(adc_buffer[4]>>7); // 12 bits to 5 bits 
  SRlengthl=lookuplenall[temp];

  temp=31-(adc_buffer[7]>>7); // 12 bits to 5 bits 
  SRlengthr=lookuplenall[temp];

  temp=31-(adc_buffer[10]>>7); // 12 bits to 5 bits 
  SRlengthc=lookuplenall[temp];

  /*
  SRlengthl=31-(adc_buffer[4]>>7); // 12 bits to 5 bits
  if (SRlengthl<4) SRlengthl=4;

  SRlengthr=31-(adc_buffer[7]>>7); // 12 bits to 5 bits
  if (SRlengthr<4) SRlengthr=4;

  SRlengthc=31-(adc_buffer[10]>>7); // 12 bits to 5 bits
  if (SRlengthc<4) SRlengthc=4; // can we have lengths down to 0=1
  */  

}

void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz - how fast can we run this?
// period 32, prescaler 8 = toggle of 104 KHz
// 4 and 4 we go up to 800 KHz
{
  // test pointering WORKS! so we can have array of pointers for easier bit access
  //also we can make bit access (eg. GPIOC->IDR & 0x0010 - can we access register as pointer TEST???, counters speed etc. all arrays 0,1,2,3
  volatile uint32_t *bitz;
  bitz=&(GPIOC->IDR);

  static volatile uint16_t k=0,ll=0, n=0, accum, cnt=0, sl=0;
  static volatile int16_t integrator=0, oldValue=0, tmp=0, tmpp=0;
  uint16_t j, bit, xx, x;
uint64_t longer;
uint32_t shift_register; // tmp
  int16_t tmpt;
    //low pass test
  static float SmoothData=0.0;
  float LPF_Beta = 0.02; // 0<ß<1
  
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // needed

   // basic tests!
  /*
  k=(adc_buffer[0]); // now 12 bits only
  DAC_SetChannel1Data(DAC_Align_12b_R, k); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  */

  // time PB4 with period=9 prescaler=8 we have 300KHz
  //    tmpp^=1;
  //    if (tmpp) GPIOB->BSRRH = (1)<<4;  // clear bits PB4
  //    else   GPIOB->BSRRL=(1)<<4; //  write bits   

  /////////////////////////////////////////////////////////////////////////////////////////
  // simple test of routing with NSR as clocked (above) and generate NSR clock bit from DAC!
  /////////////////////////////////////////////////////////////////////////////////////////

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;

  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;

  tmp=((shift_registerc & masky[SRlengthc-3])>>(rightshift[SRlengthc-3]))<<leftshift[SRlengthc-3]; // we want 12 bits but is not really audible difference
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  

  // DAC for normed NSR but should be from other SR so is not locked to output speed
  //  tmp+=320; 
  //  TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
  //  TIM1->CCR1 = tmp/2; // pulse width
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;

  // DAC for normed NSR 
  tmp=((shift_registerr & masky[SRlengthr-3])>>(rightshift[SRlengthr-3]))<<leftshift[SRlengthr-3]; // we want 12 bits but is not really audible difference
  tmp+=320; 
  TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
  TIM1->CCR1 = tmp/2; // pulse width

  
  }    
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // how to re-think overlap with new scheme
  // TODO: new routing to test:
  //
  // *NSR->LSR->CSR* // *could be default routing*
  //     ->RSR->NSR // and adjusting CSR length business - but length is important if we re-circulate
  //
  // TODO: also to test re-introduction of our cycling bit!
  //       test PWM which is normed to NSR top clock  DONE - needs work on ranges
  /////////////////////////////////////////////////////////////////////////////////////////

  //  if (speedn!=FROZENSPEED){ // testing freeze here at top  - not so exciting
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    // copy now to ghost
    Gshift_registern=shift_registern; // this could also be ORed or other logic operation with former ghost!
    Gshift_registernn=shift_registern; 

    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    
    bitr=(Gshift_registerr>>SRlengthr) & 0x01;
    Gshift_registerr=(Gshift_registerr<<1)+bitr;

    shift_registern+= bitn ^ bitr;// ^ (!(*bitz & 0x0010)); // or goes to 1s, xor is risky, AND works...
    //        shift_registern+= (!(*bitz & 0x0010)); // or goes to 1s, xor is risky, AND works...
  }
  //  }
  
  // do LSR - input from shift_registern
  // try overlap here...
  // can also just be a big shift
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerl=shift_registerl; // this could also be ORed or other logic operation with former ghost!

  sl=lookuplenall[model>>2]; // TESTY - but we need to get this value from somewhere else
  // does sl need to be odd number too? NO!
  //  sl=1;
  //  for (x=0;x<sl;x++){// multiple shift
  bitn=(Gshift_registern>>SRlengthn) & 0x01; // try overlap with/without this shift
  Gshift_registern=(Gshift_registern<<1)+bitn;
  //  }
    
  shift_registerl=(shift_registerl<<1);
    // overlap bottom x bits of l with top x bits of Gn
  tmpp=shift_registerl&masky[sl];
  shift_registerl&=invmasky[sl]; // clear lower - masks don't match but we did one shift - see if it makes sense? - try in test2.c
  // tested and we fixed the two masky arrays
  tmp=Gshift_registern>>(32-sl); // top x bits
  tmpp^=tmp;
  shift_registerl+=tmpp;
  }    

  // do CSR and output - input from L
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerc=shift_registerc; // this could also be ORed or other logic operation with former ghost!

  bitl=(Gshift_registerl>>SRlengthl) & 0x01;
  Gshift_registerl=(Gshift_registerl<<1)+bitl;
  
  shift_registerc=(shift_registerc<<1)+(bitl ^ bitc); // or is this after out? // testing re-circulation

  //////////////OUT!
  //  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-3))<<9; // older one
  tmp=((shift_registerc & masky[SRlengthc-3])>>(rightshift[SRlengthc-3]))<<leftshift[SRlengthc-3]; // we want 12 bits but is not really audible difference
  // unless we reduce down as we have done here - adjust length/array accordingly
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  // also set PWM - TIM1 period and pulse - see AllColours... TESTed but needs control over range
  tmp+=320;
  TIM1->ARR =tmp; // what range this should be? - connect to SRlengthc
  TIM1->CCR1 = tmp/2; // pulse width
  }

  // routes from top N
  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerr=shift_registerr; // this could also be ORed or other logic operation with former ghost!

  bitn=(Gshift_registernn>>SRlengthn) & 0x01;
  Gshift_registernn=(Gshift_registernn<<1)+bitn;

  shift_registerr=(shift_registerr<<1)+(bitn ^ bitr); // testing re-circulation
  }
  */
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // *thinking also that coggs are a bit like small shift registers* -
  // as below with SRs as coggs but now we try different routings:
  // NSR->LSR->CSR
  //    ->RSR->NSR
  // but then we need 2 ghostn srs or DONE
  //
  // changing into
  // NSR->LSR->CSR
  //   ->RSR->CSR 
  // this seems to work well
  //
  // try putting LFSR feedback into smaller coggSRs!DONE
  // also testing LFSR as structure for all... - but this is maybe too noisy
  /////////////////////////////////////////////////////////////////////////////////////////
  
  // isolate generic structure and re-do for pointer arrays... - see test2.c
  /*  
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    // copy now to ghost
    Gshift_registern=shift_registern; // this could also be ORed or other logic operation with former ghost!
    Gshift_registernn=shift_registern; // this could also be ORed or other logic operation with former ghost!

    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    
    //    bitr=(Gshift_registerr>>SRlengthr) & 0x01; // we can only shift this ghost register in one case...  ie. we use it elsewhereg
    //    Gshift_registerr=(Gshift_registerr<<1)+bitr; 

    shift_registern+= bitn;// & bitr;// ^ (!(GPIOC->IDR & 0x0010)); // or goes to 1s, xor is risky, AND works... and clockbit PC4
  }
  //////
  
  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  // try adding in LFSR for each stage
  bitnn = ((shift_registerl >> (lfsr_taps[SRlengthl][0])) ^ (shift_registerl >> (lfsr_taps[SRlengthl][1])) ^ (shift_registerl >> (lfsr_taps[SRlengthl][2])) ^ (shift_registerl >> (lfsr_taps[SRlengthl][3]))) & 1u;
  
  Gshift_registerl=shift_registerl; // this could also be ORed or other logic operation with former ghost!

  // try putting LFSR feedback into smaller coggSRs! DONE!
    bitn=(Gshift_registern>>SRlengthn) & 0x01;
  //  bitn = ((Gshift_registern >> (lfsr_taps[SRlengthn][0])) ^ (Gshift_registern >> (lfsr_taps[SRlengthn][1])) ^ (Gshift_registern >> (lfsr_taps[SRlengthn][2])) ^ (Gshift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

  Gshift_registern=(Gshift_registern<<1)+bitn;

  shift_registerl=(shift_registerl<<1)+(bitn ^ bitnn);
  }    

  // do CSR and output - input from l and r
  counterc++;  
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  bitnn = ((shift_registerc >> (lfsr_taps[SRlengthc][0])) ^ (shift_registerc >> (lfsr_taps[SRlengthc][1])) ^ (shift_registerc >> (lfsr_taps[SRlengthc][2])) ^ (shift_registerc >> (lfsr_taps[SRlengthc][3]))) & 1u;


  Gshift_registerc=shift_registerc; // this could also be ORed or other logic operation with former ghost!

  bitl=(Gshift_registerl>>SRlengthl) & 0x01;
  Gshift_registerl=(Gshift_registerl<<1)+bitl;

  bitr=(Gshift_registerr>>SRlengthr) & 0x01;
  Gshift_registerr=(Gshift_registerr<<1)+bitr;
  
  shift_registerc=(shift_registerc<<1)+ (bitl^bitr^bitnn); // or is this after out?

  //////////////OUT!
  //  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  // testing how to get multiple bit lengths out
  //  SRlengthc=modec>>1;
  tmp=((shift_registerc & masky[SRlengthc])>>(rightshift[SRlengthc]))<<leftshift[SRlengthc];
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }
  
  // NSR to RSR now
  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  bitnn = ((shift_registerr >> (lfsr_taps[SRlengthr][0])) ^ (shift_registerr >> (lfsr_taps[SRlengthr][1])) ^ (shift_registerr >> (lfsr_taps[SRlengthr][2])) ^ (shift_registerr >> (lfsr_taps[SRlengthr][3]))) & 1u;

  Gshift_registerr=shift_registerr; // this could also be ORed or other logic operation with former ghost!

  bitn=(Gshift_registernn>>SRlengthn) & 0x01;
  Gshift_registernn=(Gshift_registernn<<1)+bitn;

  shift_registerr=(shift_registerr<<1)+(bitn^bitnn);
  }
*/
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // *thinking also that coggs are a bit like small shift registers* -
  //  what could be done with these - rotating/looping SRs handle
  //  feedthrough of registers TODO! - also that this is more like overlap
  //  we had in mind:
  //
  // on new data we copy across say NSR->ghostSR and shift out maybe with loops or other feedback, inc incoming bits
  // question is how this works as generic mode - or if we use this instead of coggs, as could be more flexible
  // but then we need new set of ghost shift regs for other operations
  /////////////////////////////////////////////////////////////////////////////////////////
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    // copy now to ghost
    Gshift_registern=shift_registern; // this could also be ORed or other logic operation with former ghost!
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    
    bitr=(Gshift_registerr>>SRlengthr) & 0x01;
    Gshift_registerr=(Gshift_registerr<<1)+bitr;

    shift_registern+= bitn & bitr; // or goes to 1s, xor is risky, AND works...
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerl=shift_registerl; // this could also be ORed or other logic operation with former ghost!

  bitn=(Gshift_registern>>SRlengthn) & 0x01;
  Gshift_registern=(Gshift_registern<<1)+bitn;

  shift_registerl=(shift_registerl<<1)+bitn;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerc=shift_registerc; // this could also be ORed or other logic operation with former ghost!

  bitl=(Gshift_registerl>>SRlengthl) & 0x01;
  Gshift_registerl=(Gshift_registerl<<1)+bitl;
  
  shift_registerc=(shift_registerc<<1)+bitl; // or is this after out?

  //////////////OUT!
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }
  
  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  Gshift_registerr=shift_registerr; // this could also be ORed or other logic operation with former ghost!

  bitc=(Gshift_registerc>>SRlengthc) & 0x01;
  Gshift_registerc=(Gshift_registerc<<1)+bitc;

  shift_registerr=(shift_registerr<<1)+bitc;
  }
  */   

  
  /////////////////////////////////////////////////////////////////////////////////////////
  // - experimental mode for LSR, RSR and CSR only advance with cogg=0 from previous (maybe logic op with other bits)???
  //   works but with all 4
  // can also mix up dependency loop
  // xor etc with other bits
  /////////////////////////////////////////////////////////////////////////////////////////
  /*  
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    if (coggr==0) {
      shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
      shift_registern+= bitn | bitr;
      coggn=0; // we still need to reset this! - but do we do that even if we don't advance? -> 2 options here and below!
          }
    coggr=1;
    //if (coggr==0)    shift_registern+= bitn | bitr;
    //    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    //    coggr++;
    //    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    //    coggn=0; // we still need to reset this! - but do we do that even if we don't advance?
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0) {
    shift_registerl=(shift_registerl<<1)+bitn;
    coggl=0;
  }
  //  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  //  else {
  //    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerl=(shift_registerl<<1)+tmp;
  //  }
    coggn=1;
  //  if (coggn>(SRlengthn+1)) coggn=0;
    //  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  //  shift_registerc=(shift_registerc<<1)+bitl;
  if (coggl==0) {
    shift_registerc=(shift_registerc<<1)+bitl;
    coggc=0;
  }
  //if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  //  else {
  //    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerc=(shift_registerc<<1)+tmp;
  //  }
    coggl=1;
  //  if (coggl>(SRlengthl+1)) coggl=0;
  // coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  //shift_registerr=(shift_registerr<<1)+bitc;

  if (coggc==0)  {
    shift_registerr=(shift_registerr<<1)+bitc;
    coggr=0;
  }
  //  else {
  //    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerr=(shift_registerr<<1)+tmp;
  //  }
    coggc=1;
  //  if (coggc>(SRlengthc+1)) coggc=0;
    //    coggr=0;
  }    
  */
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // testing what happens when one SR has no coggs
  // TODO: say LSR has no coggs! DONE
  // TODO: try all with no coggs now! DONE and seems interesting but chokes a bit
  /////////////////////////////////////////////////////////////////////////////////////////
  //  speedn=2048;
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    shift_registern+= bitn | bitr;
    
    //if (coggr==0)    shift_registern+= bitn | bitr;
    //    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    //    coggr++;
    //    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0; // we still need to reset this!
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  shift_registerl=(shift_registerl<<1)+bitn;
  //  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  //  else {
  //    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerl=(shift_registerl<<1)+tmp;
  //  }
  //  coggn++;
  //  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  shift_registerc=(shift_registerc<<1)+bitl;

  //if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  //  else {
  //    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerc=(shift_registerc<<1)+tmp;
  //  }
  //  coggl++;
  //  if (coggl>(SRlengthl+1)) coggl=0;
    coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  shift_registerr=(shift_registerr<<1)+bitc;

  //  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  //  else {
  //    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
  //    shift_registerr=(shift_registerr<<1)+tmp;
  //  }
  //  coggc++;
  //  if (coggc>(SRlengthc+1)) coggc=0;
    coggr=0;
  }    
  */

  
  /////////////////////////////////////////////////////////////////////////////////////////
  // 2nd OVERLAP attempt
  // overlap is always from following SR
  // works but needs tweaks connected with the length
  // or we just leave length as 31
  /////////////////////////////////////////////////////////////////////////////////////////
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }


  // do LSR - input from shift_registern - TEST overlap here
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01;
  // overlap - shift it, copy sl x bits and place shifted bit in x+1
  // question is if sl>length of register?
  sl=(model>>2)+1; // TESTY - but we need to get this value from somewhere else
  shift_registerl=(shift_registerl<<1);
  shift_registerl&=invmasky[sl]; // clears itNOT TESTY/FIXED
  // take sl-1 x bits from top of shift_registern
  // but this depends on length? or do we just ignore and assume length of 31?
  tmpp=(shift_registern>>(31-SRlengthn))&(othermasky[sl]>>(31-SRlengthn));
  // shift them x bits
  tmpt=SRlengthn-sl;
  if (tmpt<sl) tmpt=sl; // ???
  tmpp=tmpp>>(tmpt);
  // and place bitn at sl+1 bit
  shift_registerl+=(bitn<<sl+1);
  // also no COGG here and a test for what happens when one SR doesn't implement coggs
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
  */  
  /////////////////////////////////////////////////////////////////////////////////////////
  //.. try shifting x number of bits across for each register
  // but we then need to hold x bits and copy across to next reg
  // so for modes both would need to be in agreement which is not so GREAT!
  // TODO: try to fix that issue so we only do in following SR.
  // DONE but need to check logic of this
  /////////////////////////////////////////////////////////////////////////////////////////  

  /*
    countern++;
  if (countern>=speedn){ 
    countern=0;
    //    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // try with input now - consecutive bits in
    if (n==8) {
      k=(adc_buffer[12])>>4;//+tmpp; // now 8 bits only
      n=0;
    }
    bitn = (k>>n)&0x01;
    n++;    
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }

  
  // do LSR - input from shift_registern - but now bitn is many bits so need to be masked and input - trying to fix as now bitn is one bit
  // but then cogs is funny but try it anyways

  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  //  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  sl=(model>>2)+1; // need to get this from somewhere else?

  // handling overlap with new test code in binary.c
  // but that is not right! as is at top end not length
  // TODO: to fix
  if (coggn==0)  {
    // we shift round shift_regn and dump overlapx bits into bottom part of SRL
    if (sl>SRlengthn) sl=SRlengthn;
    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    //    if (tmpt<(sl-1)) tmpt=(sl-1); // double check this!
    //    shift_registerl=((shift_registerl<<1)^masky[sl]); // checked
    shift_registerl=((shift_registerl<<1) & (invmasky[sl-1])); // make new masky with ~ & (invmasky[sl-1])

    // we want top sl-1 bits which are at length x
    //    shift_registerl+=( (shift_registern&((othermasky[sl-1]>>(31-SRlengthn)))) >> tmpt);// FIX
    shift_registerl+=( (shift_registern&((othermasky[sl-1]>>(32-SRlengthn))))>> tmpt);

    shift_registerl+=(bitn<<(sl-1)); // but that bit needs to be empty - it is masked
	}
  // COGGN should also be x bits across!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TODO-DONE TO TEST
  else {
    longer=shift_registern;
    longer=longer<<coggn; // shifter must be below length which we check below
    if (sl>SRlengthn) sl=SRlengthn;
    //    shift_register=(longer&othermasky[sl])+((longer&(0b1111111111111111111111111111111100000000000000000000000000000000))>>(sl+1)); // so this seems to workNOT
    shift_register=(longer&masky[SRlengthn])+((longer&((0b1111111111111111111111111111111100000000000000000000000000000000)+othermasky[31-SRlengthn]))>>(SRlengthn+1)); // working now from binary.c

    
    tmpt=SRlengthn-sl;
    // we want overlap_length=x which is top x bits of shift_register shifted to bottom bits and anded for cogg
    // clear 
    //    shift_registerl=((shift_registerl<<1)^masky[sl]); // XOR doesn;t clear - number &= ~(1UL << n);
    shift_registerl=((shift_registerl<<1) & (invmasky[sl-1])); // checked TOFIX make new masky with ~
    // shift to lower x bits
    shift_register=(shift_register>>tmpt)&masky[sl];
    shift_registerl+=shift_register;     
  }

  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    

  */

  /////////////////////////////////////////////////////////////////////////////////////////  
  // SR within SR - returning bit will have to be LOGICAL OPed with place in larger SR
  // ideas to try: different lengths of the SR in the SR, changing barrier bits which temporarily stop the
  // flow of the main SR - which is maybe better as keeping bits static -
  // so that we only shift a part of that SR - to try this!
  // so do we tag in an extra SR: Gshift_register?
  // bit is chosen as start of loop ->Gshift advances (length) and returns to xor with bit x
  // - how we choose length and returning bit (also speed matches overall speed or?

  // works well but we need control over return bit and length (right now we use model and moder which works well but
  // will have to use either cv for one and pulses//

  // how extra loops could work for all SRs?
  /////////////////////////////////////////////////////////////////////////////////////////
  /*
  
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }

 
   // do LSR - input from shift_registern - this one has the extra loop inside
  counterl++;
  if (counterl>=speedl){
    counterl=0;
    bitl = (shift_registerl>>SRlengthl) & 0x01;
    tmpp=(Gshift_registerl>>GSRlengthl) & 0x01;
    // xor tmmp with tmpp at bit sl
    sl=model>>1; //++ to change TEST
//    shift_registerl=shift_registerl^(tmpp<<sl);
   shift_registerl=shift_registerl& ~(tmpp<<sl); // TESTY/FIXED
    if (coggn==0)  shift_registerl=(shift_registerl<<1)+(bitn);
    else {
      tmp=((shift_registern>>(SRlengthn-(coggn-1)))&0x01); // double check length of coggn - for length 31 we can go to 32
      shift_registerl=(shift_registerl<<1)+tmp;
    }
    coggn++;
    if (coggn>(SRlengthn+1)) coggn=0;
    coggl=0;
    // entry of bit sl into Gshift_register
    sl=moder>>1; //++ to change TEST
    Gshift_registerl=(Gshift_registerl<<1)+((shift_registerl>>sl)&0x01);    
  }    

    // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
  */

  
  /////////////////////////////////////////////////////////////////////////////////////////
  // try basics but with leaky SR and probability set from pulses or from CV depending on mode...
  /////////////////////////////////////////////////////////////////////////////////////////
  /*  
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= leaks(bitn,bitr, 8);
    //    if (coggr==0)    shift_registern+= bitn ^ bitr;
    else shift_registern+= leaks(bitn, ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01), 8); // was better with only coggr as leaky above but can have both
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }


  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  } 

   //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
  */

  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  // - NLC 8 bit cipher simulation: only makes sense for NSR and CSR where we have many bits in
  // so for NSR - with ADC input we can try to have bits only entering CSR register on strobe
  // so we need to feed them into ghost reg then copy over on strobe...
  // test this which doesn't work so well with NSR/ADC but could work with CSR (remember feedback bit is only renewed on strobe)
  // what is CSR clkin= //   if (!(GPIOB->IDR & (1<<7)))    shift_registerpar[xx]+= bitn;
  // working well - we can use top and bottom strobes and lots of potential variations
  /////////////////////////////////////////////////////////////////////////////////////////
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    if (n==8) {
      k=(adc_buffer[12])>>4;//+tmpp; // now 8 bits only
      n=0;
    }
    bitn = (shift_registern>>SRlengthn) & 0x01; 
    shift_registern=(shift_registern<<1)+(((k>>n)&0x01));//|bitc); with or without bitc
    n++;    
    coggn=0;
  }  

  // just try passing this down to CSR with latch on output 
  // do CSR and output - input from n
  counterc++;
  if (counterc>=speedc){
    counterc=0;

    if (!(GPIOC->IDR & (1<<4))) {
      tmpp=(shift_registerc & 0xff)<<4; // 8 bits and we could also change the number of bits dynamically
      bitc = ((shift_registerc>>SRlengthc) & 0x01) ^  (shift_registerc&0x01); // in 8 bit cipher is XOR with bit0
    }

    if (coggn==0)  shift_registerc=(shift_registerc<<1)+bitn;
    else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
    }
    coggn++;
    if (coggn>(SRlengthn+1)) coggn=0;
    coggc=0;
  //  tmpt=SRlengthc-8;
  //  if (tmpt<0) tmpt=0;
  //  tmp=((shift_registerc & masky[SRlengthc])>>(tmpt))<<4; // 8 bits out - but mask doesn't work
  DAC_SetChannel1Data(DAC_Align_12b_R, tmpp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }
  */
  
  /*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    if (n==8) {
      k=(adc_buffer[12]); // now 8 bits only
      n=0;
    }
    // feed those bits in to GSR one by one
    bit = (Gshift_registern>>SRlengthn) & 0x01; 
    Gshift_registern=(Gshift_registern<<1)+(((k>>n)&0x01)^bitc);
    // if strobe bit - NSR CLKIN PC4 - copy bits
    if (!(GPIOC->IDR & (1<<4))) shift_registern=Gshift_registern;
    
    bitn = (shift_registern>>SRlengthn) & 0x01; 
    shift_registern=(shift_registern<<1)+bitn; // or we can use other bits here
    n++;    
    coggn=0;
  }  

  // just try passing this down to CSR with latch on output TODO later
  // do CSR and output - input from n
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerc=(shift_registerc<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggc=0;
  //  tmpt=SRlengthc-8;
  //  if (tmpt<0) tmpt=0;
  //  tmp=((shift_registerc & masky[SRlengthc])>>(tmpt))<<4; // 8 bits out - but mask doesn't work
  tmp=(shift_registerc &0xff)<<4; // 8 bits
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  }
  */
  
  /////////////////////////////////////////////////////////////////////////////////////////  
  // try overlap with entry point after that overlap - but then it would eat the overlap
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // test idea of overlaps across 2 SR (for testing just use top LFSR/NSR and CSR for output and use modes as length?)
  // this one is overlap from NSR into CSR
  // try now NSR into LSR
  /*  
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;

    // copy bits into CSR for overlap length before we SHIFT!
    tmp=model>>1; // for max 31?
    // ignore length of CSR
    //    tmp=31; tmp of 31 will kill all...
    if (tmp==31) tmp=30;
    shift_registerl &= (invmasky[tmp]); // clear overlap - TEST

    shift_registerl+=((shift_registern>>(31-tmp))&masky[tmp]); // push top bits into that overlap gap
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn;// | bitr;
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
  */
  
  /////////////////////////////////////////////////////////////////////////////////////////
  
  // Full pass through of NSR->LSR->CSR->RSR->NSR(logic) -tested and works well below

  // do NSR - LFSR

  // test with SD
  /*    n++;
  if (n>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     bit=1;
  }
   else
   {
      oldValue=0;
      bit=0;
   }
  */

 
//  if (speedn<1000){// TEST stopping but value of 1000 will change
/*
  countern++;
  if (countern>=speedn){ 
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    bitnn = (shift_registern>>SRlengthn) & 0x01; 
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    //    bitn |=bit;
    if (coggr==0)    shift_registern+= bitn & bitr; // and only works here with new code
    else shift_registern+= bitn | ((shift_registerr>>(SRlengthr-(coggr-1)))&0x01);
    coggr++;
    if (coggr>(SRlengthr+1)) coggr=0; // we always update the cogg which is feeding into this one
    coggn=0;
  }
//  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitnn; // re-testing with new bitn 28/8/2021
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  coggl=0;
  }    

  // do CSR and output - input from l
  counterc++;
  if (counterc>=speedc){
    counterc=0;
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggl==0)  shift_registerc=(shift_registerc<<1)+bitl;
  else {
    tmp=(shift_registerl>>(SRlengthl-(coggl-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerc=(shift_registerc<<1)+tmp;
  }
  coggl++;
  if (coggl>(SRlengthl+1)) coggl=0;
  coggc=0;
  
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting  
  
  //   try other outputs
   // low pass to our DAC!
  
//  if (bitc==1) bit=4095;
//  else bit=0;
//  SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit)); // how do we adjust beta for speed?
//   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
//   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  }
  
  //rsr is now the feedback register

  counterr++;
  if (counterr>=speedr){
    counterr=0;
  bitr = (shift_registerr>>SRlengthr) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggc==0)  shift_registerr=(shift_registerr<<1)+bitc;
  else {
    tmp=(shift_registerc>>(SRlengthc-(coggc-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerr=(shift_registerr<<1)+tmp;
  }
  coggc++;
  if (coggc>(SRlengthc+1)) coggc=0;
  coggr=0;
  }    
*/  
  /*
  // do NSR - LFSR
  countern++;
  if (countern>=speedn){
    countern=0;
    bitn = ((shift_registern >> (lfsr_taps[SRlengthn][0])) ^ (shift_registern >> (lfsr_taps[SRlengthn][1])) ^ (shift_registern >> (lfsr_taps[SRlengthn][2])) ^ (shift_registern >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
    if (shift_registern==0)     shift_registern=0xff;
    
    shift_registern=shift_registern<<1; // we are shifting left << so bit 31 is out last one
    shift_registern+= bitn | bitl;    // but we should also use cogg for bitl in this case
    coggn=0;
  }

  // do LSR - input from shift_registern
  counterl++;
  if (counterl>=speedl){
    counterl=0;
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out but we don't use it so far
  if (coggn==0)  shift_registerl=(shift_registerl<<1)+bitn;
  else {
    tmp=(shift_registern>>(SRlengthn-(coggn-1)))&0x01; // double check length of coggn - for length 31 we can go to 32
    shift_registerl=(shift_registerl<<1)+tmp;
  }
  coggn++;
  if (coggn>(SRlengthn+1)) coggn=0;
  }    

  // test output for now from l:
  tmp=((shift_registerl & masky[SRlengthl])>>(SRlengthl-4))<<8; // other masks but then also need shifter arrays for bits - how to make this more generic
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
  */  
  
  // TEST SINGLE counter for sketches below...
  //  counterc++;
  //  if (counterc>=speedc){
  //    counterc=0;

  ///////////////////////////////////////////////////////
    // TODO: try parallel SRs with few bits, delay of different bits (but how to assign these - testing with bits in)
    // delay would be different lengths
    ///////////////////////////////////////////////////////
    /*
    k=(adc_buffer[12])>>4; // 8 bits

    if (k<64) tmp=1;
    else if (k<128) tmp=3;
    else if (k<192) tmp=7; // these values can also shift
    else tmp=15;
    k=tmp;
    tmp=0;    
    for (xx=0;xx<4;xx++){
      if (!(GPIOB->IDR & (1<<7))){
	reg[xx]++; // reg could also be from cv if we are pulse driven
      }
      if (reg[xx]>SRlengthn) reg[xx]=SRlengthn-1; 
      bitn=(shift_registerpar[xx]>>(SRlengthn-reg[xx]))&0x01; // bit shifted out
      //      shift_registerpar[xx]=(shift_registerpar[xx]<<1)+(((k>>xx)&0x01)^bitn); // with feeddbacks which could also be selected by pulse
      shift_registerpar[xx]=(shift_registerpar[xx]<<1)+((k>>xx)&0x01); // we are shifting left << so bit 31 is out last one
      if (bitn) tmp+=1023; // 4 possible bitns 4095/4=
    }

    // and potential feedback of those bits
    
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

    */
    
    ///////////////////////////////////////////////////////
    // sketch two-headed SR
    ///////////////////////////////////////////////////////
    //    SRlengthn=11;
    // one length transition seems to kill it...
    // shift left one reg
    /*
    bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;

    // right other reg
    
//    bitn = ((shift_registerpar[1] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[1] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    bitn = ((shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[1] >> (SRlengthn-lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    // to handle length we need to do something about top bit which would otherwise shift down in!
    shift_registerpar[1]&= ~(1<<(SRlengthn+1));
    shift_registerpar[1]=shift_registerpar[1]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);
    // glue half of one to the other?, merge or other bit ops and one/other
    shift_registerpar[2]=shift_registerpar[1] ^ shift_registerpar[0]; // tried with xor and and workings! and is good...
    if (shift_registerpar[0]==0)     shift_registerpar[0]=0xff;
    if (shift_registerpar[1]==0)     shift_registerpar[1]=0xff;

    tmp= ( (shift_registerpar[2]&1) + (shift_registerpar[2]&(1<<1)) + (shift_registerpar[2]&(1<<2)) + (shift_registerpar[2]&(1<<3)))<<8; 
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */
    
    // another approach with same SR

    /*
        bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;
    
    // right other reg
    
    bitn = ((shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (SRlengthn-lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    shift_registerpar[0]=shift_registerpar[0]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);

    // extra shift or nothing happens
    // this shift could depend on CSR bit for example but quite often this dies out...
        
    if (!(GPIOB->IDR & (1<<7))){
      bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]<<1; // we are shifting left << so bit 31 is out last one
    shift_registerpar[0]+= bitn;
    }
       else {
    bitn = ((shift_registerpar[0] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[0] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24
    shift_registerpar[0]=shift_registerpar[0]>>1 | (bitn<<SRlengthn); //    lfsr = (lfsr >> 1) | (bit << 15);
    }
    
    tmp= ( (shift_registerpar[0]&1) + (shift_registerpar[0]&(1<<1)) + (shift_registerpar[0]&(1<<2)) + (shift_registerpar[0]&(1<<3)))<<8; 
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */
    
    ///////////////////////////////////////////////////////
    // test for parallell SR in top NSR
    // - feed data into top of parallel LFSRs, data read out from all bit outs: test for 12 bits, 12 parallel streams
    // - runs quite slowly so maybe ditch...
    ///////////////////////////////////////////////////////
    
    //    SRlengthn=12;
    /*
    k=(adc_buffer[12]); // now 12 bits only    
    tmp=0;
    for (xx=0;xx<12;xx++){

    bitn = ((shift_registerpar[xx] >> (lfsr_taps[SRlengthn][0])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][1])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][2])) ^ (shift_registerpar[xx] >> (lfsr_taps[SRlengthn][3]))) & 1u; // 32 is 31, 29, 25, 24

    //    bitn=leaks(bitn,8);
    
    shift_registerpar[xx]=shift_registerpar[xx]<<1; // we are shifting left << so bit 31 is out last one
    // test with say clkin on CSR PB7 as toggling which bit goes in!
    // is inverted I guess ???
    if (!(GPIOB->IDR & (1<<7)))    shift_registerpar[xx]+= bitn;
    else shift_registerpar[xx]+=(k>>xx)&0x01;
    tmp+=(bitn<<xx);
    }
    
    DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
    j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */    

  ///////////////////////////////////////////////////////
  // test with SR in SR for digital filter simulator - works with simple pass through
  // how we could simplify with more arrays, masks?
  // how we can substitute leaky logic for logic ops

  // 4 bits go into NSR as in original AC and are shifted
  // can also be feedback so is micro-SR in largerSR
    //  k=(adc_buffer[12])>>8;//+tmp)>>8; // now 12 bits only -> 4 bits
  // copy into ghost reg so we can feedback bits if we like

    //    k=(adc_buffer[12])>>8; // 4 bits // 8 bits

    /*  if (k<64) tmp=1;
  else if (k<128) tmp=3;
  else if (k<192) tmp=7; // these values can also shift
  else tmp=15;
  k=tmp;
  */

    /*
  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in
  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
  shift_registern=(shift_registern<<1); // here or later/earlier?
  
  // 4 bits into LSR
  shift_registerl &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  // test feeding back some of the bits
    shift_registerl += (((shift_registern&(1<<7))>>7) + ((shift_registern&(1<<15))>>7) + ((shift_registern&(1<<23))>>7) + ((shift_registern&(1<<31))>>7));
  //    shift_registerl += (((shift_registern&(1<<7))>>7) ^ ((shift_registerl&(1<<7))>>7)  ) + (((shift_registern&(1<<15))>>7) ^ ((shift_registerl&(1<<15))>>7)) + (((shift_registern&(1<<23))>>7) ^ ((shift_registerl&(1<<23))>>7)) + (((shift_registern&(1<<31))>>7) ^ ((shift_registerl&(1<<31))>>7));

  shift_registerl=(shift_registerl<<1); // here or later/earlier?
  
  // 4 bits into CSR and out
  shift_registerc &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
  // put the 4 bits in there
  shift_registerc += (((shift_registerl&(1<<7))>>7) + ((shift_registerl&(1<<15))>>7) + ((shift_registerl&(1<<23))>>7) + ((shift_registerl&(1<<31))>>7));
  shift_registerc=(shift_registerc<<1); // here or later/earlier?

  // output it! 
  //  tmp=rand()%4095;
  // four basic bits to output - same as above
  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8;
  // just the number of bits is important
  //tmp=bitsz[tmp]*1024;
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
    */
  /////

  
    ///////////////////////////////////////////////////////
  // test for x(say 4) ADC bits in spaced out, feed through and DAC out, to lead towards digital filter simulation
  // not really working but kind of interesting - question is order of bits, also return of bits

  // sr in sr, parallel SR, feedback as bits or as addition into ADC in from DAC

    // try with different lengths
  /*
  if (cnt==4){
  k=(adc_buffer[12])>>8; // now 12 bits only -> 4 bits
  // test using moden as comparator in: adc_buffer[2]
  // but we can also use 4 bits and work like that
  // shifting these values, or spacings of these values...
  //  if (k<64) tmp=1;
//  else if (k<128) tmp=3;
//  else if (k<192) tmp=7; // these values can also shift
//  else tmp=15;
//  k=tmp;


  // comparator just outputs high if above level.
 
  if (k>(adc_buffer[2]>>8)) k=4094;
  
  cnt=0;
  // out - question is what is order of first bit? and return of bits
  }
  
  // how to do as 4 independent bits ie. number of bits is the important thing - more about dac out from this one as is same no?
  
  bitn = (shift_registern>>SRlengthn) & 0x01; // bit which would be shifted out
  shift_registern=(shift_registern<<1); // here or later?
  shift_registern+=((k&(1<<cnt))>>cnt);// ^ bitc; or internal feedback of bits on bits...
//  shift_registern^=(shift_registerc&masky[SRlengthc]); // other kinds of logical opps but we need to mask for length FIXED TEST
shift_registern&=~(shift_registerc&masky[SRlengthc]); // other kinds of logical opps but we need to mask for length FIXED TEST
  // how do we mask for length?
  
// older not workings 
// try for 4 bits in - at intervals of 32/4= 8 bits: 1, 8, 16, 24
//  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
// put the 4 bits in
//  shift_registern += ((k&0x01) + ((k&0x02)<<7) + ((k&0x04)<<14) + ((k&0x08)<<21)); // would be 0 8-1 16-2 24-3 -
// without clearing bits is interesting also we can have other options like delay of some bits which would happen anyways
// eg. sample and then put bit in one by one
  
  // pass to shiftregl
  
  bitl = (shift_registerl>>SRlengthl) & 0x01; // bit which would be shifted out
  shift_registerl=(shift_registerl<<1)+bitn;

  // pass to shiftregc
  bitc = (shift_registerc>>SRlengthc) & 0x01; // bit which would be shifted out - but we never use it so length effects nothing
  shift_registerc=(shift_registerc<<1)+bitl;

  // output based on SRlengthc or we can just accumulate bitc
  
  //  tmp= ( (shift_registerc&1) + (shift_registerc&(1<<1)) + (shift_registerc&(1<<2)) + (shift_registerc&(1<<3)))<<8; // olde one
  tmp=((shift_registerc & masky[SRlengthc])>>(SRlengthc-4))<<8;
  DAC_SetChannel1Data(DAC_Align_12b_R, tmp); // 1000/4096 * 3V3 == 0V8 
  j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting
 
  cnt++;
*/  
  
  // and output
  //  tmp= (((shift_registerc&(1<<7))>>7) + ((shift_registerc&(1<<15))>>14) + ((shift_registerc&(1<<23))>>21) + ((shift_registerc&(1<<31))>>28))<<8; // much further bits  // msb first
  //  shift_registern &= 0b11111110111111101111111011111110; // inverted mask: 0b11111110111111101111111011111110 LSB is at end
 //  tmp= (((shift_registerc&(1<<7))>>4) + ((shift_registerc&(1<<15))>>13) + ((shift_registerc&(1<<23))>>22) + ((shift_registerc&(1<<31))>>31))<<8; // much further bits
      
  ///////////////////////////////////////////////////////

    
  /* 
  //test for sigma/delta
    
  n++;
  if (n>50) {
    k=(adc_buffer[12]); // now 12 bits only // 16 bits to 12 bits - this is now our ADCin!
    n=0;
  }

  integrator+=k-oldValue;
   if(integrator>0)
  {
     oldValue=MAXVALUE;
     //     GPIOB->BSRRL=(1)<<4; //  write bits 
     bit=4095;
  }
   else
   {
      oldValue=0;
      //      GPIOB->BSRRH = (1)<<4;  // clear bits PB4
      bit=0;
   }
  
   // low pass to our DAC!
   SmoothData = SmoothData - (LPF_Beta * (SmoothData - bit));
   DAC_SetChannel1Data(DAC_Align_12b_R, (int)SmoothData); // 1000/4096 * 3V3 == 0V8 
   j = DAC_GetDataOutputValue (DAC_Channel_1); // DACout is inverting

  */

  //    } // close of speedc FOR TEST sketches
 
    
}
