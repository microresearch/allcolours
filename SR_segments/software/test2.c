#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "time.h"

//gcc test.c -otest -lm -std=gnu99 

// TODO:

//- in test2.c compare generic shiftings with coggs version (and also if we still need to do <<1 if routes to itself? yes we do)

//- ghostSR in ghostSR in test2.c to trial//also various crossings of delayed ghosts with "real" SRs


//we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)
// but these will all be arrays, why do we need pointers?

uint32_t shift_[4], Gshift_[4][4], GGshift_[4], cogg[4][4], route[4]; // gshift is 4 even though we don't use one
// GG is ghost in ghost

// and cycling/circling array of ghosts which can come back or go forwards/backwards - when these ghosts are copied over (on event)
// with 256 cycles/copies - or we can have variable length of this shifting array

uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0};

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
  uint32_t bitn, bitr, tmp;
  uint32_t b, g, x, y;
  shift_[0]=0b1010101010101010101010101010101;
  shift_[1]=0b0110111011111011101110111110000;
  shift_[2]=0b0110111011111011101110111110000;
  shift_[3]=0b0110111011111011101110111110000;
  
  // seed rand
  srand (time(NULL));
  
  //say 0 is n, 1 is l, 2 is c, 3 is r
  // and same business for the lengths
  uint32_t SRlength[4]={31,31,31,31};
  //  print32bits(*shift_[0]);

  // trying to rewrite generic shifter for pointer arrays:
  // also counters can be arrays too...
  // whole of SR should be configurable as stream of bits so we can read a description from another SR
  // also mode and pulses can modify bits

  b=0; //this is us

  // trial routing table
  route[b]=1; // lowest 4 bits of routing NLCR 1000 so C would be 0010 = 2  - or we use binary weighted

  for (y=0;y<32;y++){
  
  //  g=2; // n=0,l=1,c=2,r=3 // so feedback here is from c 
  bitn = ((shift_[b] >> (lfsr_taps[SRlength[b]][0])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][1])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][2])) ^ (shift_[b] >> (lfsr_taps[SRlength[b]][3]))) & 1u; // 32 is 31, 29, 25, 24
  
  // copy now to ghost
  //we need multiple ghosts for each possible shifter: eg. Gshift_rl, Gshift_rn, Gshift_rc (right ones for left, for n and for c)
  Gshift_[b][0]=shift_[b]; 
  Gshift_[b][1]=shift_[b]; 
  Gshift_[b][2]=shift_[b];
  Gshift_[b][3]=shift_[b]; // ghosts for l,c,r only but let's keep one spare

  // what would ghosts in ghost look like... only for itself
  // and again ghost shift can occur on pulses in so is delayed rev...
  // which is the only way it makes sense
  // events for copy in, for shift and/or for bit extraction

  // if event {
  GGshift_[b]=Gshift_[b][b];
  // if event {
  bitr= (GGshift_[b]>>SRlength[b]) & 0x01;
  GGshift_[b]=(GGshift_[b]<<1)+bitr;
  // } wrap

  // alternative for array of revenants:
  //uint32_t Gshift_rev[4][256], Gshift_revcnt[4]={0,0,0,0};
  // if event {
  Gshift_rev[b][Gshift_revcnt[b]]=Gshift_[b][b];
  // if event {
  bitr= (Gshift_rev[b][Gshift_revcnt[b]]>>SRlength[b]) & 0x01;
  Gshift_rev[b][Gshift_revcnt[b]]=(Gshift_rev[b][Gshift_revcnt[b]]<<1)+bitr;
  Gshift_revcnt[b]++; // events for increment
  if (Gshift_revcnt[b]>255) Gshift_revcnt[b]=0;
  // } wrap

  


  
    // need to catch it
  if (shift_[b]==0)     shift_[b]=0xff;
  
  // what else it needs to know - for each queued SR we need one cogg=0 for reset as we reset each on reading
  // if we are using coggs to move on registers
  // this just signals that we have a reset for SR down the line
  cogg[b][0]=0;
  cogg[b][1]=0;
  cogg[b][2]=0;
  cogg[b][3]=0;

  shift_[b]=shift_[b]<<1;
  
  // decoding routing table into bits - max of 4 bits...
  // own routing means we have the shifted out bit already
  // we could also lag the ghost so is like a delayed revenant
  // so example it only shifts itself if there is a pulse bit

  bitr=0;   // leave off for above ghost in ghostings where we have a bitr 
  tmp=route[b]; // route can also be another SR!
  // if route to ourself then is cycling bit but we still need to cycle <<1 above!
  for (x=0;x<4;x++){
    if (tmp&0x01){  
      bitr |= (Gshift_[b][x]>>SRlength[x]) & 0x01; // or other logical opp for multiple bits/accum
      // could even shift them in one after the other
      // ghosts can also have ghosts and LFSR within themselves
      Gshift_[b][x]=(Gshift_[b][x]<<1)+bitr;
    }
    tmp=tmp>>1;
  }

  shift_[b]+= bitr;// & bitr;// ^ (!(GPIOC->IDR & 0x0010)); // or goes to 1s, xor is risky, AND works... and clockbit PC4
  //  printf("%d\n",bitr);
  print32bits(shift_[0]);
  //  print32bits(Gshift_[0][0]);
  printf("\n");
  }

  // how can we compare routing with ghosts to routing with coggs at different speeds
  
  // test small SR and changes in length
  /*  SRlengthl=31;
    for (y=0;y<100000;y++){
      //      SRlengthl-=2;
            SRlengthl=((rand()%31)+1);
      //      SRlengthl=((rand()%14)*2)+2; // even
      //      SRlengthl=((rand()%15)*2)+1; // odd
      //      printf("%d\n", SRlengthl);
      //      if (SRlengthl==1) SRlengthl=31;
  for (x=0;x<32;x++){
    bitn=(shift_registerl>>SRlengthl) & 0x01; // try overlap with/without this shift
    if ((rand()%1024)==0) bitn^=1; // flips
    shift_registerl=(shift_registerl<<1)+bitn;
  }
    }
    print32bits(shift_registerl);
  */
    
  //testing masks and overlaps - working
    /*
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