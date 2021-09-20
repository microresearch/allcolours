#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "time.h"

#define MAXVALUE 4095


// simplest generic shifter without counter and with one route!

uint32_t shift_[4]={0xff,0xff,0xff,0xff}, Gshift_[4][4], GGshift_[4], cogg[4][4];// route[4]={1,9,9,9}; // gshift is 4 even though we don't use one
// GG is ghost in ghost

// and cycling/circling array of ghosts which can come back or go forwards/backwards - when these ghosts are copied over (on event)
// with 256 cycles/copies - or we can have variable length of this shifting array

uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0};
uint32_t default_route[4]={3,0,1,2}; // for 0,1,2,3 N,L,C,R - but routing is routing FROM!
uint32_t single_route[4]={1,2,4,8};
uint32_t sroute=0; // counter for single routes so we can share this
uint32_t *speedroute[4][5]; // speed from our CV, CV as offset for DAC from (1,2,3,4) // just for speedCV modes - pointer to these

uint32_t speedfrom[4]={0,0,0,0};
uint32_t intflag[4]={0,0,0,0};
uint32_t speed[4]={0,0,0,0};
uint32_t dac[4]={0,0,0,0};
uint32_t inputbit[4]={0,0,0,0};
//uint32_t LFSR[4]={0,1,2,3};
uint32_t adctype[4]={0,0,0,0};
uint32_t logopp[4]={0,0,0,0};
uint32_t adc_[4]={0,0,0,0};
uint32_t counter_[4]={0,0,0,0};


uint32_t route[4]={8,4,2,1}; // route[4]={1,9,9,9};
uint32_t LFSR[4]={0,1,2,3}; // which SR take the LFSR bits from!


static uint32_t rightshift[32]={0,0,0,0, 0,0,0,0, 0,0,0,0, // first 12 bits
				1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16, 17,18,19,20};

static uint32_t leftshift[32]= {11,10,9, 8,7,6,5, 4,3,2,1,
				0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

static uint32_t countbts[4096]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 6, 7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 7, 8, 8, 9, 8, 9, 9, 10, 8, 9, 9, 10, 9, 10, 10, 11, 8, 9, 9, 10, 9, 10, 10, 11, 9, 10, 10, 11, 10, 11, 11, 12};

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

void print32bits(uint32_t bitz){
  int x,y;
  unsigned char bitt;
  uint32_t cc=0b10000000000000000000000000000000; 

  for (y=0;y<32;y++){
    if ((bitz&cc)!=0) bitt=1;
    else bitt=0;
    cc=cc>>1;
    printf("%d",bitt);
  }
printf("\n");
}

static inline int bits_(uint32_t reg, uint32_t length){ // function returns bottom length bits of SR reg
  uint32_t x=0;
  if (reg<4) x=shift_[reg]>>(31-length);
  return x;
}

// and another inline function which returns different kinds of DAC from
// a certain SR eg. standard DAC of x bits, equivalent dac of x bits,
// what about one bit dac (more involved as takes time but we should have
// a pointer to that value

float LPF_Beta = 0.02; // 0<ß<1

int adc_buffer[13];

// TODO: generic ADC functions for bit insertions into shift registers! - for single bits only we return bit which is to be used here

static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type){ // here we use length as number of bits max is 12 bits
  static int n[4]={0,0,0,0};
  static int32_t integrator=0, oldValue=0;

  int k, bt;

  if (type==0){ // basic sequential length of bits cycling in
  if (length>11) length=11;
      if (n[reg]==length) {
	k=(adc_buffer[12])>>(11-length); //
      n[reg]=0;
    }
    bt = (k>>n[reg])&0x01;
    n[reg]++;    
  }
  else { // one bit audio input
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

    // other options are: comparator, equivalent sets of x bits incoming (how to do this cleanly for x number of bits)

    }
    
    return bt;
}

//bitr=logop(bitr,bitrr,logopp[w]); // or other op TODO
static inline int logop(uint32_t bita, uint32_t bitaa, uint32_t type){ //TODO: xor, or, and, leaky, others?
  // for now is just OR
  return (bita ^ bitaa);
  
}
  
static inline int DAC_(uint32_t reg, uint32_t length, uint32_t type){ // 3 types 0,1,2 - but we can also add more types for spacings with array of spacers (which we
                                                                      // did have somewhere
  uint32_t y,x=0;
  static float SmoothData[4]={0.0, 0.0, 0.0, 0.0};

  if (type==0){ // standard bit DAC for x bits
    if (reg<4 && length>3 && length<32) 
      x=((shift_[reg] & masky[length-3])>>(rightshift[length]))<<leftshift[length]; // we want 12 bits but is not really audible difference    
  }
  else if (type==1){
      // equivalent bit DAC for x bits - we need a table for this!
      // or more like set of tables for each bit
      // and we need divide highest but number - eg. for 8 bits we have max 8 (all 1s) - max 12 bits DAC is 4096 4096/8=512 4096/12=341
      // we can have another table for this - but just taking maybe max of 12 bits otherwise lookup is too long (max 12 bits=4096)
      if (reg<4){
	if (length>11) length=11;
	x=countbts[shift_[reg]&masky[length]]; // lower length bits only
	y=4096/(length+1);
	  x*=y;
      }
  }
  else { // one bit audio
    // top bit
    y=(shift_[reg]>>length)&1;
    if (y==1) x=4095;
    else x=0;
    SmoothData[reg] = SmoothData[reg] - (LPF_Beta * (SmoothData[reg] - x)); // how do we adjust beta for speed?
    x=(int)SmoothData[reg];
  }
  return x;
}

int main(void)   // try to re-learn pointer arrays
{
  uint32_t SRlength[4]={31,31,31,31};
  uint32_t c, b, g, x, w, y, clkr=0, start=0;
  uint32_t bitn, bitr, bitrr, tmp, param;
  uint32_t counter[4]={0,0,0,0};

  /*
  b=0; //this is us
  route[b]=1; // lowest 4 bits of routing NLCR 1000 so C would be 0010 = 2  - or we use binary weighted

  for (y=0;y<32;y++){
  
  //  g=2; // n=0,l=1,c=2,r=3 // so feedback here is from c 
    //  bitn = ((shift_[b] >> (lfsr_taps[SRlength[b]][0])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][1])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][2])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][3]))) & 1u; // we would use this in final...
  
  // copy now to ghost
  //we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)
  Gshift_[b][0]=shift_[b]; 
  Gshift_[b][1]=shift_[b]; 
  Gshift_[b][2]=shift_[b];
  Gshift_[b][3]=shift_[b]; // ghosts for l,c,r only but let's keep one spare
  
  // need to catch it
  if (shift_[b]==0)     shift_[b]=0xff;

  cogg[b][0]=0;
  cogg[b][1]=0;
  cogg[b][2]=0;
  cogg[b][3]=0;

  shift_[b]=shift_[b]<<1;

  // for 0 // NSR // -  we have routes from R(3) and itself(0);
  
  bitr = ((Gshift_[0][b]>>SRlength[0]) & 0x01);
  Gshift_[0][b]=(Gshift_[0][b]<<1)+bitr;
  bitrr =  ((Gshift_[3][b]>>SRlength[3]) & 0x01) ; // or other logical opp for multiple bits/accum
  Gshift_[b][3]=(Gshift_[3][b]<<1)+bitrr;
  bitr|=bitrr;
  shift_[b]+= bitr;// & bitr;// ^ (!(GPIOC->IDR & 0x0010)); // or goes to 1s, xor is risky, AND works... and clockbit PC4
  }
  */


  ////////////////////////////////////////////////////
  // - to attempt generic SR for most basic/nearly all cases
  // we can still have specialised ones but they should all be repeatable
  // so can be placed in a loop!

  // looks like it works so far but to test now in it.c
  // so also that each mode then has a code for: speedfrom/inputbit/adctype/route/ - later add in DAC etc.

  // so for simple pass through by speed would be: speedfrom=0/inputbit=2/adctype=0/route=last one as bit/
  
  ////////////////////////////////////////////////////
  for (y=0;y<12800;y++){
    for (w=0;w<4;w++){

  //1-Where do I get speed from? implement it!
  // cases are interrupt flag, CV, CV+DACroute

  counter[w]++;
  
  if (speedfrom[w]==1 && intflag[w]==1){ // interrupt flag
    intflag[w]=0;
    start=1;
    param=adc_[w]; // we can use speed adc as is interrupt
  }
  else if (speedfrom[w]==0 && counter[w]>speed[w]){
      counter[w]=0; 
      start=1;
      param=counter_[w]; // we use pulse counter as param - where to count this TODO
    }
    else if (speedfrom[w]==2 && counter[w]>(speed[w]+dac[w])){
      counter[w]=0; 
      start=1;
    }
  // also more cases eg. for AND with chosen SR bit!
  
  if (start==1){ // all trigger one SR operation
    //2.1-deal with housekeeping    
    start=0;
  // copy now to ghost
  //we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)
  Gshift_[w][0]=shift_[w]; 
  Gshift_[w][1]=shift_[w]; 
  Gshift_[w][2]=shift_[w];
  Gshift_[w][3]=shift_[w]; // ghosts for l,c,r only but let's keep one spare
  
  // need to catch it
  if (shift_[w]==0)     shift_[w]=0xff;

  cogg[w][0]=0;
  cogg[w][1]=0;
  cogg[w][2]=0;
  cogg[w][3]=0;

  //2-where is the input bit from (LFSR, ADC type?)- can also be from another LFSR? ADC types we have in test2.c - or no inputbit
    if (inputbit[w]==0){ // LFSR from SR in LFSR[w]
      bitn = ((shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][0])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][1])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][2])) ^ (shift_[LFSR[w]] >> (lfsr_taps[SRlength[LFSR[w]]][3]))) & 1u; // we would use this in final...
    }
    else if (inputbit[w]==1) {// do input from type of ADC specified
      // static inline int ADC_(uint32_t reg, uint32_t length, uint32_t type){ // here we use length as number of bits max is 12 bits
      bitn=ADC_(shift_[w],SRlength[w],adctype[w]);
    }
    else bitn=0;
    
    //2.5-shifting of which bits <<
    shift_[w]=shift_[w]<<1;
  
    //3-what is routing for incoming SR bits, cycling bit
    // how we do routing table? as binary/

    bitr=bitn; 
    tmp=route[w]; // route can also be another SR!
    // if route to ourself then is cycling bit but we still need to cycle <<1 above!
    for (x=0;x<4;x++){
      if (tmp&0x01){  
	bitrr = (Gshift_[x][w]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
	Gshift_[x][w]=(Gshift_[x][w]<<1)+bitrr;  // we had x and w wrong way round - x is ghost SR number, w is our own copy for this SR
	bitr=logop(bitr,bitrr,logopp[w]); // but what if we want different logical opps for each?
    }
    tmp=tmp>>1;
  }
    // default route we don't use now...
    
    shift_[w]+=bitr;
    
    //4-what is incoming pulsin bit if any? - incoming pulse will always be ORed in
    //we have done    //5-XOR of logic op of all bits and re-insertion
    
    //6-DAC result for any purposes - do we output in main loop?
    //    dac[w]=

    //7-pulses out if any

  }//start

  printf("%d :",w);  
  print32bits(shift_[w]);

    } //4x
    
  }//32
}
