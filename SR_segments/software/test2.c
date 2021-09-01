#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

//gcc test.c -otest -lm -std=gnu99 

//we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)

uint32_t Gshift_nr, Gshift_nl, Gshift_nn, Gshift_nc;
uint32_t Gshift_rr, Gshift_rl, Gshift_rn, Gshift_rc;
uint32_t Gshift_cr, Gshift_cl, Gshift_cn, Gshift_cc;
uint32_t Gshift_lr, Gshift_ll, Gshift_ln, Gshift_lc; 

uint32_t *shift_[32], *Gshift_[32][4], coggs[4][4]; // gshift is 4 even though we don't use one

static uint32_t invmasky[32]={//0,0,0, // skip all zeroes or all ones ???

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
0b00000000000000000000000000000000,			  
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

int main(void)   // try to re-learn pointer arrays
{
  uint32_t bitn, bitr;
  uint8_t b, g, x, y;
  uint32_t Gshiftg_nr, Gshift_nl, Gshift_nn, Gshift_nc;
  uint32_t Gshift_rr, Gshift_rl, Gshift_rn, Gshift_rc;
  uint32_t Gshift_cr, Gshift_cl, Gshift_cn, Gshift_cc;
  uint32_t Gshift_lr, Gshift_ll, Gshift_ln, Gshift_lc; 

  uint32_t shift_registern=0xffff, SRlengthl=31;
  uint32_t Gshift_registern=0x0f0f;
  uint32_t shift_registerl=0b0110101010111011101110101010000;

  shift_[0]=&shift_registern;

  Gshift_[0][0]=&Gshift_nr; // etc

  //say 0 is n, 1 is l, 2 is c, 3 is r
  // and same business for the lengths
  uint32_t SRlength[4]={32,32,32,32};
  //  print32bits(*shift_[0]);

  // trying to rewrite generic shifter for pointer arrays:
  // also counters can be arrays too...
  /*
  b=0; g=2; // n=0,l=1,c=2,r=3 // so feedback here is from c 
  bitn = ((*shift_[b] >> (lfsr_taps[SRlength[b]][0])) ^ (*shift_[b] >> (lfsr_taps[SRlength[b]][1])) ^ (*shift_[b] >> (lfsr_taps[SRlength[b]][2])) ^ (*shift_[b] >> (lfsr_taps[SRlength[b]][3]))) & 1u; // 32 is 31, 29, 25, 24
    // need to catch it
  if (*shift_[b]==0)     *shift_[b]=0xff;
  // copy now to ghost
  //we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)
  *Gshift_[b][0]=*shift_[b]; 
  *Gshift_[b][1]=*shift_[b]; 
  *Gshift_[b][2]=*shift_[b];
  *Gshift_[b][3]=*shift_[b]; // ghosts for l,c,r only but let's keep one spare
  // what else it needs to know - for each queued SR we need one cogg=0 for reset as we reset each on reading
  cogg[b][0]=0;
  cogg[b][1]=0;
  cogg[b][2]=0;
  cogg[b][3]=0;
  
  *shift_[b]=*shift_[b]<<1; // we are shifting left << so bit 31 is out last one

  bitr=(*Gshift_[g][b]>>SRlength[b]) & 0x01;
  *Gshift_[g][b]=(*Gshift_[g][b]<<1)+bitr; 

  *shift_[b]+= bitn;// & bitr;// ^ (!(GPIOC->IDR & 0x0010)); // or goes to 1s, xor is risky, AND works... and clockbit PC4
  */

  // test small sr
  SRlengthl=31;
    for (y=0;y<13200;y++){
      //      SRlengthl-=2;
      SRlengthl=((rand()%15)*2)+1;
      printf("%d\n", SRlengthl);
      //      if (SRlengthl==1) SRlengthl=31;
  for (x=0;x<32;x++){
    print32bits(shift_registerl);
    bitn=(shift_registerl>>SRlengthl) & 0x01; // try overlap with/without this shift
    shift_registerl=(shift_registerl<<1)+bitn;
  }
    }
  /* 
  //testing masks and overlaps - working
  uint32_t tmpp, tmp, sl=4;

  print32bits(shift_registerl);
  print32bits(Gshift_registern);

  shift_registerl=(shift_registerl<<1);
    // overlap bottom x bits of l with top x bits of Gn
  tmpp=shift_registerl&masky[sl]; // this is just lower bits
  //  print32bits(tmpp);
  shift_registerl&=invmasky[sl]; // clear lower - masks don't match but we did one shift - see if it makes sense? - try in test2.c
  //  print32bits(shift_registerl);
  tmp=Gshift_registern>>(32-sl); // top x bits
  //  print32bits(tmp);
  tmpp^=tmp;
  shift_registerl+=tmpp;
  
  print32bits(shift_registerl);
  */
}
