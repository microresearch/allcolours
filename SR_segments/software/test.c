
#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

//gcc test.c -otest -lm -std=gnu99 

#define ADCONLY(X, Y){						\
  if (w==0)							\
    {								\
      printf("0\n");						\
    }								\
  }

#define ADCX(X, Y){			\
  if (w==0)							\
    {								\
      printf("0\n");						\
    }								\
  else if (w==2)      {					\
    printf("2\n");					\
  }							\
  else {						\
}

typedef struct heavens_ { // fill out with trigger, routes, types, bits and other attributes,,,
  uint32_t trigger;  
  uint32_t adctype, adcpar;
  uint32_t dactype, dacpar;
  uint32_t Gshift_[9];
  uint32_t localGSR[9];
  uint32_t Gshare_;
  uint32_t shift_;
  uint32_t gshift_;
  uint32_t extrashift_;
  uint32_t lastdac; // speed stuff
  uint32_t dac;
  int32_t route;
  float time_now;
  uint32_t lastest;
  float alpha;
  long last_time;
 long int_time;
  uint32_t delay[512]; // 128x32 bits=4096 // 512=16384
  uint32_t delcnt;
  uint32_t paramx; // for param holds - could be more than one param...
  uint32_t changed;
  uint32_t reset[4];
  int32_t gsrcnt[4];
  uint32_t latch;
  uint32_t index;
  uint32_t strobed;
  uint32_t lastspeed;
  uint32_t countspeed;
/*
- how else we can express matrices which makes sense - to match up:

as array for each side:

eg. speed, length, bit FUNCS, adc, which dac // them CV indices

thus:
*/

  uint32_t (*func)[13];
//  uint32_t func[64][13];
   /// speed, length, adc, bit, dac, cv indices: speedcvin, speedcv(mod), lengthcv, daccv, adccv, addccvv(IN),  bitcv, bitcvv - and indexes for these


} heavens;



unsigned char bits[32], head;
uint32_t *shift_[32];
uint32_t *shift_register;
/*static uint8_t lfsr_taps[32][4] = {
        {30, 30, 30, 30},
        {29, 29, 29, 29},
        {28, 28, 28, 28},
        {31, 30, 27, 27},
        {31, 30, 29, 28},
        {31, 30, 28, 27},
        {31, 30, 29, 28},
        {31, 29, 28, 27},
        {31, 30, 28, 27},
        {31, 30, 28, 27},
        {31, 30, 29, 27},
        {31, 30, 27, 25},
        {31, 30, 28, 27},
        {31, 30, 28, 26},
        {31, 30, 29, 27},
        {31, 29, 28, 26},
        {31, 30, 29, 28},
        {31, 30, 29, 26},
        {31, 30, 29, 26},
        {31, 30, 27, 25},
        {31, 30, 29, 26},
        {31, 28, 27, 26},
        {31, 30, 28, 26},
        {31, 30, 28, 27},
        {31, 30, 29, 28},
        {31, 30, 29, 25},
        {31, 30, 29, 26},
        {31, 30, 27, 25},
        {31, 30, 29, 27},
        {31, 30, 27, 25},
        {31, 30, 29, 28},
        {31, 29, 25, 24},
	};*/

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
	//        {31, 29, 25, 24},
	{31, 6, 5, 1},
	
  };

int countbits(int xxx){
  int cont=0;
  while (xxx>0){
    if (xxx&1) cont++;
    xxx=xxx>>1;
  }
  return cont;
}



// // note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

/*static uint8_t lfsr_taps_mirrored[32][4] = { // TO TEST! seems to work so far!
        {30, 31, 31, 31},
        {29, 31, 31, 31},
        {28, 31, 31, 31},
        {31, 28, 31, 31},
        {31, 27, 28, 29},
        {31, 26, 28, 29},
        {31, 25, 26, 27},
        {31, 25, 26, 27},
        {31, 23, 25, 26},
        {31, 22, 24, 25},
        {31, 21, 22, 24},
        {31, 20, 23, 25},
        {31, 19, 21, 22},
        {31, 18, 20, 22},
        {31, 17, 18, 20},
        {31, 17, 18, 20},
        {31, 15, 16, 17},
        {31, 14, 15, 18},
        {31, 13, 14, 17},
        {31, 12, 15, 17},
        {31, 11, 12, 15},
        {31, 12, 13, 14},
        {31, 9, 11, 13},
        {31, 8, 10, 11},
        {31, 7, 8, 9},
        {31, 6, 7, 11},
        {31, 5, 6, 9},
        {31, 4, 7, 9},
        {31, 3, 4, 6},
        {31, 2, 5, 7},
        {31, 1, 2, 3},
        {31, 1, 5, 6},
	};*/

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



//   {32, 30, 26, 25},     //Tap position for 32-bit LFSR
// becomes 31x, 1, 5, 6

static uint8_t lfsr_taps_older[32][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {4, 3, 0, 0},			//Tap position for 4-bit LFSR
  {5, 4, 3, 2},			//Tap position for 5-bit LFSR
  {6, 5, 3, 2},			//Tap position for 6-bit LFSR
  {7, 6, 5, 4},			//Tap position for 7-bit LFSR
  {8, 6, 5 ,4},		//Tap position for 8-bit LFSR
  {9, 8, 6, 5},			//Tap position for 9-bit LFSR
  {10, 9, 7, 6},		//Tap position for 10-bit LFSR
  {11, 10, 9, 7},		//Tap position for 11-bit LFSR
  {12, 11, 8, 6},		//Tap position for 12-bit LFSR *
  {13, 12, 10, 9},		//Tap position for 13-bit LFSR
  {14, 13, 11, 9},		//Tap position for 14-bit LFSR
  {15, 14, 13, 11},		//Tap position for 15-bit LFSR
  {16, 14, 13, 11},	//Tap position for 16-bit LFSR
  {17, 16, 15, 14},		//Tap position for 17-bit LFSR
  {18, 17, 16, 13},		//Tap position for 18-bit LFSR
  {19, 18, 17, 14},		//Tap position for 19-bit LFSR *
  {20, 19, 16, 14},		//Tap position for 20-bit LFSR 
  {21, 20, 19, 16},		//Tap position for 21-bit LFSR
  {22, 19, 18, 17},		//Tap position for 22-bit LFSR
  {23, 22, 20, 18},		//Tap position for 23-bit LFSR
  {24, 23, 21, 20},	//Tap position for 24-bit LFSR
  {25, 24, 23, 22},		//Tap position for 25-bit LFSR
  {26, 25, 24, 20},		//Tap position for 26-bit LFSR *
  {27, 26, 25, 22},		//Tap position for 27-bit LFSR *
  {28, 27, 24, 22},		//Tap position for 28-bit LFSR
  {29, 28, 27, 25},		//Tap position for 29-bit LFSR
  {30, 29, 26, 24},		//Tap position for 30-bit LFSR
  {31, 30, 29, 28},		//Tap position for 31-bit LFSR
  {32, 30, 26, 25},     //Tap position for 32-bit LFSR 32 is 31, 29, 25, 24
};

//In tables of m-sequence feedback sets, as presented below, neither the Fibonacci nor the Galois form is specified. This is because any given set will work with either implementation. If a given feedback set is used on both the Fibonacci and Galois forms, the sequence produced by one form will be the mirror image of the sequence produced by the other.



unsigned char sr_length;

void printbits(uint8_t *bitz){
  int x,y;
  unsigned char bitt,cc;
  for (x=0;x<4;x++){
    cc=1;
  for (y=0;y<8;y++){
    if ((bitz[x]&cc)!=0) bitt=1;
    else bitt=0;
    cc=cc<<1;
    printf("%d",bitt);
  }
}
printf("\n");
}

void print32bits(uint32_t *bitz){
  int x,y;
  unsigned char bitt;
  uint32_t cc=0b10000000000000000000000000000000; 

  for (y=0;y<32;y++){
    if ((*bitz&cc)!=0) bitt=1;
    else bitt=0;
    cc=cc>>1;
    printf("%d",bitt);
  }
  //printf("\n");
}



//skeeve: https://www.avrfreaks.net/forum/256-bit-shift-register-required?page=all
// https://electricdruid.net/practical-lfsr-random-number-generators/
// see https://www.maximintegrated.com/en/app-notes/index.mvp/id/1743 for taps!    
// https://www.avrfreaks.net/forum/very-fastsmall-random-number-generator?page=all

// we need arrays for taps index/XORs!

// eg. for 32 we need  bits 31, 29, 25, and 24


//uint32_t binmask32=0b10100011000000000000000000000000; // doesn;t work

unsigned char hi_mask=0x80, hi_index=7; //was 31 -7 gives us 64 bits
    // hi bit is bits[hi_index] & hi_mask
    // a shift will change one bit and
    // alter the labels of all of them

//uint8_t g_buf[4]={0xaa,0xaa,0xaa,0xaa};
uint8_t g_buf[4]={0xff,0xff,0xff,0xff}; 

uint8_t shift256bit_32(uint8_t carry_in)
{
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t carry_out;
  //shift into 32 bit shift register         
      if(*shift_register & (1uL<<31))
        carry_out=1;
      else
         carry_out=0;
      *shift_register*=2;
      *shift_register+=carry_in;         
   return carry_out;   //
}

uint8_t lfsr32()
{
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint32_t bit;
  uint8_t carry_out, carry_in;
  //shift into 32 bit shift register         
  if(*shift_register & (1uL<<31))
      carry_out=1;
  else
    carry_out=0;
  //  bit=((*shift_register)^binmask32)&0x01;
  //  bit= ((*shift_register >> 31) ^ (*shift_register >> 29) ^ (*shift_register >> 25) ^ (*shift_register >> 24)) & 1u; // 32 is 31, 29, 25, 24
  bit=0;
      //      printf("bit: %d ", bit);
      carry_in = bit;// | carry_out;
      *shift_register*=2; // we are shifting left << so bit 31 is out last one
      *shift_register+=carry_in;         
      print32bits(shift_register);
      //g      printf("%d\n",carry_out);
      return carry_out;   //
}

void shifterfromstm() // tested working
{
  uint8_t bith;
  uint32_t *shift_register = (uint8_t *)g_buf;
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  print32bits(shift_register);
}

void varshifter() // tested working
{
  uint32_t bith;
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t SRlengthh=4;
 
  bith = *shift_register>>31; // bit which would be shifted out - always 31 as at the end
  //  printf ("bith: %d\n",bith);

  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  
  *shift_register+= (bith <<(31-SRlengthh)); // PB7 and PB10
  
  /* 
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  */
  //  print32bits(shift_register);
}

void varshifterb() // tested working - > so for shift reg on bottom
{
  uint32_t bith;
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t SRlengthh=31;
 
  bith = (*shift_register>>SRlengthh) & 0x01; // bit which would be shifted out 
  //  printf ("bith: %d\n",bith);

  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  
  *shift_register+= bith; // PB7 and PB10
  
  /* 
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  */
  //  print32bits(shift_register);
}


uint32_t looker[32]={2147483648U, 3221225472U, 3758096384U, 4026531840U, 4160749568U, 4227858432U, 4261412864U, 4278190080U, 4286578688U, 4290772992U, 4292870144U, 4293918720U, 4294443008U, 4294705152U, 4294836224U, 4294901760U, 4294934528U, 4294950912U, 4294959104U, 4294963200U, 4294965248U, 4294966272U, 4294966784U, 4294967040U, 4294967168U, 4294967232U, 4294967264U, 4294967280U, 4294967288U, 4294967292U, 4294967294U, 4294967295U}; // we look up length in this from 0-31


void varshifter_electronotes() // tested working
{
  uint32_t bith;
  //uint32_t probh=0b11111111000000000000000000000000;
  uint32_t probh=0b11111110000000000000000000000000;
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t SRlengthh=8;
  //  printf("%u\n", probh);
  //->>>>>>>>>>>>>> 7- electronotes: bits of the first SR determine (via NAND) if we recycle 2nd SR, or add new bit from the first SR - no input needed
  // so to test we need to run first SR - we ignore its length for now
  // but we need x bits of probability switches and x bits
  // test on LAP! somehow...
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one

  if (((probh | (rand()%256)<<24) & looker[7] ) == looker[7]) *shift_register+=(rand()%2) <<(31-SRlengthh);  // this seems to work
    //	shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter - testing simple swopover
    // do we need to mask lower bits?
    else *shift_register += bith <<(31-SRlengthh);

  
  /*
    if (hcount>8) hcount=0;
    if( !(GPIOB->IDR & 0x0080)) probh^=(1<<(31-hcount));
    hcount++;
    if (((probh | shift_registerl) & looker[7] ) == looker[7]) shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter
    //	shift_registerh+=((shift_registerl>>31)<<shifterh); // new bits enter - testing simple swopover
    // do we need to mask lower bits?
    else shift_registerh += bith<<shifterh;
  */
  
  //  print32bits(shift_register);

      if (bith==1)	printf("x");
    else printf("0");


}

//uint32_t shift_registerh[32]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}; // 32 bit SR but we can change length just using output bit

uint32_t shift_registerh[1024];


#define PARRR 128

void varshifter_par_lfsr(uint8_t length)
{
  // test printing of 32 parallel registers
  uint32_t bith[PARRR];
  uint8_t SRlengthh=length; // always real length minus one
  uint16_t xx;
  for (xx=0;xx<PARRR;xx++){

    bith[xx]= ((shift_registerh[xx] >> (lfsr_taps[SRlengthh][0])) ^ (shift_registerh[xx] >> (lfsr_taps[SRlengthh][1])) ^ (shift_registerh[xx] >> (lfsr_taps[SRlengthh][2])) ^ (shift_registerh[xx] >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

    shift_registerh[xx]=shift_registerh[xx]<<1; // we are shifting left << so bit 31 is out last one
  
  //  *shift_registerh+= (bith <<shifter); // PB7 and PB10

  shift_registerh[xx]+= bith[xx];

  /* 
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  */
  //      print32bits(shift_register);
  //    printf("BITH %d", bith);
  //    printf("\n");
  if (bith[xx]==1)	printf("1");
  else printf("0");
  }
  printf("\n");
  
}


void varshifter_lfsr(uint8_t length) // tested working NOW!
{
  uint32_t bith;
    uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t SRlengthh=length; // always real length minus one

  //  uint8_t shifter=3SRlengthh; // always real length minus one
 
  //  bith = *shift_register>>31; // bit which would be shifted out - always 31 as at the end
  
  //bith= ((*shift_register >> (lfsr_taps[SRlengthh][0]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][1]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][2]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][3]-1+shifter))) & 1u; // 32 is 31, 29, 25, 24
      bith= ((*shift_register >> (lfsr_taps[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

  //      bith= ((*shift_register >> (lfsr_taps_mirrored[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

  //          bith= ((*shift_register >> (lfsr_taps_mirrored[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24
      // printf ("bith: %d\n",bith);
      
  // // note that we can have 2 mirrored with [n, A, B, C] -> [n, n-C, n-B, n-A] - maybe for LF to hF!

  //mirrored=(length+1-(those+1))-1
  
  //  printf("        {%d, %d, %d, %d},\n", lfsr_taps[SRlengthh][0], (SRlengthh-lfsr_taps[SRlengthh][3])-1, (SRlengthh-lfsr_taps[SRlengthh][2])-1, (SRlengthh-lfsr_taps[SRlengthh][1])-1);

  //printf("        {%d, %d, %d, %d},\n", lfsr_taps_older[SRlengthh][0]-1, lfsr_taps_older[SRlengthh][1]-1, lfsr_taps_older[SRlengthh][2]-1, lfsr_taps_older[SRlengthh][3]-1);

  
    //  printf("        {%d, %d, %d, %d},\n", lfsr_taps_older[SRlengthh][0]-1+shifter, lfsr_taps_older[SRlengthh][1]-1+shifter, lfsr_taps_older[SRlengthh][2]-1+shifter, lfsr_taps_older[SRlengthh][3]-1+shifter);
  
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  
  //  *shift_register+= (bith <<shifter); // PB7 and PB10

  *shift_register+= bith;

  /* 
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  */
  //      print32bits(shift_register);
  //    printf("BITH %d", bith);
  //    printf("\n");
          if (bith==1)	printf("x");
             else printf("0");
  
}



unsigned char shift(unsigned char lo_bit) ///this is JUST a circular buffer!!!!
{
  unsigned char retval= hi_mask && (bits[hi_index] & hi_mask);
  printf("index: %d mask: %d result %d \n", hi_index, hi_mask, retval);
  //  printbits();
  bits[hi_index]&= ~hi_mask;
  if(lo_bit) bits[hi_index]|=hi_mask;
  hi_mask>>=1;  // shift direction corrected
  if(0==hi_mask) {
    hi_mask=0x80;
    hi_index--;
    hi_index &= 7;
}

return retval;
}


// 16 bit 65k repeat

int main(void)
{
    uint16_t start_state = 0xACE1u;  /* Any nonzero start state will work. */
    uint16_t lfsr = start_state;
    uint16_t bit,x,y,count=0;                    /* Must be 16bit to allow bit<<15 later in the code */
    unsigned period = 0;
    unsigned char bat;
    unsigned char biit=0x05;
    //    x=0b1111111111101111;
    uint32_t bits=0b11111111000000000000000010000000, bitzz, adc, res, mask[32], cc;
    uint32_t emptybits=0b10000000000000000000000000000000;
    shift_register = (uint8_t *)g_buf;

    //    x &= ~0xff;
    y=0;

    for (cc=0;cc<1024;cc++){
      //      shift_registerh[cc]=rand()%4294967295;
            shift_registerh[cc]=cc;
    }
    

    // TO: how to get CV in (8 bits say) as we use bottom bits/or spacings for CV out/PWM 
    // mask and shift for 8 bits
    // shift_registerh &= MASK[SRlengthh]; // store mask as the INVERTED one eg. ~(Oxff) for bottom 8 bits - bottom/lower is where SR is for lower lengths
    // shift_registerh +=(ADCBuffer[2]>>(8+SHIFTED[SRlengthh]))<<SHIFT[SRlengthh];
    // just 8 bits always so:
    // shift_registerh +=(ADCBuffer[2]>>8)<<SHIFT[SRlengthh]; // starts at 0 for first 8 then goes up to 24 I think
    uint32_t SHIFT[32]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; 
    
    // and for top 8 bits of 32? - depending on length we would have different masks and different bit options
    //
    // what do we do with input bit? - OR it in!
    // for 8 bits or less is a bit odd as we just output our bits... maybe also increase SHIFTED to reflect this - so 3 arrays: masks, where, howmany bits
    // *maybe ADC/PWM out should be upper bits as we shift in at the lowest - so then we would shift in DAC on lowest bits*
    // also question of how often we shift in 8 bits or they will cover themselves - shift in every 8 cycles?

    // SO: shift in bits on lowest, shift out on upper.
    // shift in on upper, shift out on lower (as is now) - try this one first.

    // top 8 bits masked of 32: as length decreases we shift that mask right until we get to 8 bits
    // we can also space those out for higher orders... but then we need to access individual bits of ADC

    // test the logic of:
    //    if (((probh | shift_registerl) & 0xff )
    //    uint32_t probh=0b000000000000000000000011111110;
    //    uint32_t shift_registerl=0b00000000000000000000000000000000;
    //    if (((probh | shift_registerl) & 0xff) == 0xff) printf("TEST: if (((probh | shift_registerl) & 0xff )\n");

    /*
      8 bits from different positions towards lower end...
      for lengths <9 we don't do this calculation

      DACOUT= ((shift_registerh & 0x01) + ((shift_registerh>>pos[SRlengthh][1])&0x02) + ((shift_registerh>>pos[SRlengthh][2])&0x04) // etc 

      pos[32][8]={
      {1,2,3,4,5,6,7,8}, // ignore first 9 lengths then start to space out
      etc///
      }
      just need to calculate 8 bit arrays for positions based on length - basic positions table <<1 each time...

      eg. from electronotes p.246 low to high 6 bits out of 24 >> a,c,f,g,h,i = 25=1, 27=3, 30=6, 34=10, 39=15, 45=21 (spacing=2, 3, 4, 5, 6)

      so for our 8 bits for full 32 bits we could have bits 0, 1, 3, 6, 10, 15, 21, 28 -> this translates as:
      subtract: 
      0, 1, 2, 3, 4, 5, 6, 7

in reverse tho for 9->31

      


      pos[32][8]={
      {1,2,3,4,5,6,7,8}, // ignore first 8 lengths then start to space out
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {1,2,3,4,5,6,7,8},
      {0, 0, 0, 0, 0, 0, 0, 1},//10 bits = length 9
      {0, 0, 0, 0, 0, 1, 1, 2},//11
      {0, 0, 0, 0, 1, 1, 2, 3},//12
      {0, 0, 0, 0, 1, 1, 2, 4},//13
      {0, 0, 0, 1, 1, 2, 3, 5},//14
      {0, 0, 0, 1, 1, 2, 4, 6},//15
      {0, 0, 0, 1, 2, 3, 5, 7},//16
      {0, 0, 1, 2, 3, 4, 6, 8},//17
      {0, 0, 1, 2, 3, 5, 7, 9},//18
      {0, 0, 1, 2, 3, 5, 7, 10},//19
      {0, 0, 1, 2, 3, 5, 8, 11},//20
      {0, 0, 1, 2, 3, 6, 9, 12},//21
      {0, 0, 1, 2, 4, 7, 10, 13},//22
      {0, 0, 1, 2, 4, 7, 10, 14},//23
      {0, 0, 1, 2, 5, 8, 11, 15},//24
      {0, 0, 1, 3, 6, 9, 12, 16},//25
      {0, 0, 1, 3, 6, 9, 13, 17},//26
      {0, 0, 1, 3, 6, 10, 14, 18},//27
      {0, 0, 1, 3, 6, 10, 14, 19},//28
      {0, 0, 1, 3, 6, 10, 15, 20},// 29
      {0, 0, 1, 3, 6, 10, 15, 21},// 30
      {0, 0, 1, 3, 6, 10, 15, 21},// 31
      {0, 0, 1, 3, 6, 10, 15, 21} // for 32 bits = length=31
      }


      // down to 9

    */

    
    /*
    for (x=32;x>7;x--){
      // this seems to test and work out
      bitzz=~(bits>>y);
      //adc=255<<SHIFT[x-1];
      //      printf("x: %d bits: %u\n",x, bitzz);
      //      printf("%u, ", bitzz);
      mask[x-1]=bitzz;
      //      emptybits=0;
      //      emptybits&=bitzz;
      //      emptybits+=adc;
      //      res=adc+bitzz;
      //      print32bits(&emptybits);
      //      print32bits(&res);
      y++;
    }

    for (x=7;x<32;x++){
      printf("%u, ", mask[x]);
      }*/
    
    // shift_registerh & (1<<(SRlengthh/2)
    //    if (x & (1<<4))    printf("%d\n", y);
    
    //    if (!(biit & 0x20)) printf("BIT\n");
    
    /*       do
    {
        // taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 
	// [1,2,4,15] from maxim app-notes???
        bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    	// slipped bit based on what kind of random???
    	if (bit==1)	printf("x");
    	else printf("0");
    	lfsr =  (lfsr >> 1) | (bit << 15);
        ++period;
    } while (1);
    */

    // how to simulate 2 shift registers  meeting and crossing

    // run sr left, run sr right
    // merge or logic
    // print

    unsigned char n=31;
    //    print32bits(shift_register);
    //    while(1){
    //        for (y=0;y<512;y++){
    //      varshifter_par_lfsr(31);
      //void varshifter_lfsr(uint8_t length) // tested working NOW!
      //      print32bits(shift_register);
      //      lfsr32();
    //    }
    
    //(bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6
    uint32_t bitl=1, bitss;
    //    bitss=0x0030;
    //    bitl = (bitl | !(bitss & 0x0040)); // PB5 and PB6
    //    bitl=!(bitss & 0x0040);
    //    printf("BITL %d\n", bitl);

    // try to re-learn pointer arrays

    
    
    //    (bitl | !(GPIOB->IDR & 0x0040)); // PB5 and PB6    
    //                   while(1){
      //      if (count<32) n=n^1;
      //      else n=0;
      //bat=shift256bit_32(bat^binmask32);
    /*    		  for (n=4;n<32;n++){
      //      bat=lfsr32();
		    //		  varshifter_lfsr(n);
	      //	      varshifter_electronotes();
            for (y=0;y<6400;y++){ 
		    //        for (x=0;x<5000;x++){ 
        varshifter_lfsr(n);
	    }
	//  }
      //      if (bat==0) printf("1");
      //      else printf("0");
      //      }
      //      printf("\n");
      //      uint8_t shift256bit_32(uint8_t carry_in)
      //      printf("%d: %d\n", count, bat);
      //      printbits();
      count++;
      //      printbits(&g_buf[0]);
      }*/
		  //		   }
    /*    for (int x=0;x<65536;x++){ // 16 bits 
      printf("%d, ", countbits(x));
        }
    */
   for (int x=1;x<13;x++){ 
     //     printf("%d, ", 4096/x);
   }
  //     printf("%d, ", 4096/x);
   //   *g_buf=bits>>21;
   //   bits=(emptybits>>24)&0x80;
   //   print32bits(&bits);

   // we want bits 0,2,5,9,11,14,18,20 of 24 bits - what are necessary shifts
   // gap is 0,2,3,4,2,3,4,2 start from 0
   // shift is 0,1,etc...
   int cd=0;
   int gap[32][8]={
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //<8 bits
     {0,1,1,1,1,1,1,1}, //8 bits
     {0,2,1,1,1,1,1,1}, //9bits
     {0,2,2,1,1,1,1,1}, //10bits
     {0,2,1,2,1,2,1,1}, //11bits
     {0,2,2,2,1,2,1,1}, //12bits     
     {0,2,2,2,1,2,1,1}, //13bits
     {0,2,2,2,1,2,1,1}, //14bits
     
     {0,2,2,2,2,2,1,1}, //15bits
     {0,2,2,2,2,2,2,1}, //16bits
     {0,2,2,2,2,2,2,2}, //17bits
     {0,2,3,2,2,2,2,2}, //18bits
     {0,2,3,3,2,2,2,2}, //19bits
     {0,2,3,3,2,3,2,2}, //20bits
     {0,2,3,3,2,3,3,2}, //21bits
     {0,2,3,4,2,3,3,2}, //22bits
     {0,2,3,4,2,3,4,2}, //23bits  
     {0,3,3,4,2,3,4,2}, //24 bits - from electronotes but bit different

     {0,3,3,4,2,3,4,3}, //25bits
     {0,3,3,4,3,3,4,3}, //26bits
     {0,3,4,4,3,3,4,3}, //27bits
     {0,3,4,4,3,4,4,3}, //28bits
     {0,4,4,4,3,4,4,3}, //29bits
     {0,4,4,4,4,4,4,3}, //30bits
     {0,4,4,4,4,4,4,4}, //31bits
     {0,5,4,4,4,4,4,4}, //32bits
   };
     

uint8_t lfsr_taps[32][4] = {
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

uint32_t spac[32]={0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7};

 uint32_t spacc[32][3]={
{0, 0, 0 },
{0, 0, 0 },
{0, 0, 0 },
{0, 0, 0 },
{1, 2, 3 },
{1, 2, 3 },
{1, 2, 3 },
{1, 2, 3 },
{2, 4, 6 },
{2, 4, 6 },
{2, 4, 6 },
{2, 4, 6 },
{3, 6, 9 },
{3, 6, 9 },
{3, 6, 9 },
{3, 6, 9 },
{4, 8, 12 },
{4, 8, 12 },
{4, 8, 12 },
{4, 8, 12 },
{5, 10, 15 },
{5, 10, 15 },
{5, 10, 15 },
{5, 10, 15 },
{6, 12, 18 },
{6, 12, 18 },
{6, 12, 18 },
{6, 12, 18 },
{7, 14, 21 },
{7, 14, 21 },
{7, 14, 21 },
{7, 14, 21 }
 };

uint32_t spacmask[32]={
0b11111111111111111111111111111011,
0b11111111111111111111111111111011,
0b11111111111111111111111111111011,
0b11111111111111111111111111111011,
0b11111111111111111111111111110000,
0b11111111111111111111111111110000,
0b11111111111111111111111111110000,
0b11111111111111111111111111110000,
0b11111111111111111111111110101010,
0b11111111111111111111111110101010,
0b11111111111111111111111110101010,
0b11111111111111111111111110101010,
0b11111111111111111111110110110110,
0b11111111111111111111110110110110,
0b11111111111111111111110110110110,
0b11111111111111111111110110110110,
0b11111111111111111110111011101110,
0b11111111111111111110111011101110,
0b11111111111111111110111011101110,
0b11111111111111111110111011101110,
0b11111111111111110111101111011110,
0b11111111111111110111101111011110,
0b11111111111111110111101111011110,
0b11111111111111110111101111011110,
0b11111111111110111110111110111110,
0b11111111111110111110111110111110,
0b11111111111110111110111110111110,
0b11111111111110111110111110111110,
0b11111111110111111011111101111110,
0b11111111110111111011111101111110,
0b11111111110111111011111101111110,
  0b11111111110111111011111101111110};

uint32_t lastspac[32][4]={
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{0, 1, 2, 3 },
{1, 3, 5, 7 },
{1, 3, 5, 7 },
{1, 3, 5, 7 },
{1, 3, 5, 7 },
{2, 5, 8, 11 },
{2, 5, 8, 11 },
{2, 5, 8, 11 },
{2, 5, 8, 11 },
{3, 7, 11, 15 },
{3, 7, 11, 15 },
{3, 7, 11, 15 },
{3, 7, 11, 15 },
{4, 9, 14, 19 },
{4, 9, 14, 19 },
{4, 9, 14, 19 },
{4, 9, 14, 19 },
{5, 11, 17, 23 },
{5, 11, 17, 23 },
{5, 11, 17, 23 },
{5, 11, 17, 23 },
{6, 13, 20, 27 },
{6, 13, 20, 27 },
{6, 13, 20, 27 },
{6, 13, 20, 27 }
};

uint32_t lastspacbac[32][4]={
{0, 0, 0, 0 },
{0, 0, 0, 0 },
{0, 0, 0, 0 },
{0, 0, 0, 0 },
{0, 0, 0, 0 },
{0, 0, 0, 0 },
{0, 0, 0, 0 },

{1, 2, 2, 4 },
{1, 2, 2, 4 },
{1, 2, 2, 4 },
{1, 2, 2, 4 },

{2, 4, 6, 8 },
{2, 4, 6, 8 },
{2, 4, 6, 8 },
{2, 4, 6, 8 },

{3, 6, 8, 12 },
{3, 6, 8, 12 },
{3, 6, 8, 12 },
{3, 6, 8, 12 },

{4, 8, 12, 16 },
{4, 8, 12, 16 },
{4, 8, 12, 16 },
{4, 8, 12, 16 },

{5, 10, 15, 20 },
{5, 10, 15, 20 },
{5, 10, 15, 20 },
{5, 10, 15, 20 },

{6, 12, 18, 24 },
{6, 12, 18, 24 },
{6, 12, 18, 24 },
{6, 12, 18, 24 }

};

 
 uint32_t bitter;
// we want bits as zero.
/*
 for (x=0;x<32;x++){
   bitter=0b11111111111111111111111111111111;
   int spacing=(x/4);
   //   bitter^=((1<<(lfsr_taps[x][0]))+(1<<(lfsr_taps[x][1]))+(1<<(lfsr_taps[x][2]))+(1<<(lfsr_taps[x][3])));
   bitter^=1+(1<<spacing)+(1<<(spacing*2))+(1<<(spacing*3));
   
      printf("{%d, %d, %d },\n",spacing, (spacing*2), (spacing*3));
   //  printf("{%d, %d, %d, %d },\n", (spacing*2)-1, (spacing*3)-2, (spacing*4)-3); // tops
   //  printf("%d, ",spacing);
   //   printf("0b");
   //   print32bits(&bitter);
   //      printf(",\n");
	    }
*/

// we need 2 SRs
uint32_t xp= 0b11111111111111111111111111111101;
uint32_t yp= 0b11111111111111111111111111111111;

uint32_t xlength=7;
uint32_t ylength=31, bitn;

 for (x=0;x<64;x++){
	bitn=xp&0x01; // lowest bit
	xp=xp>>1;
	//	PULSIN_OR;
	xp &= ~(1UL << xlength);
	xp +=(bitn << xlength);
	//	dac[w]=DAC_(w, SRlength[w], dactype[w],par,trigger[w]);	
	print32bits(&xp);
	printf(",\n");
 }

 for (x=0;x<32;x++){

	yp&=spacmask[ylength]; //cleared

	// y is the present one into which x comes
	
	if (xlength>=ylength){ // need to >> 
	  //	  tmp=(xlength>>2)-(ylength>>2); // /4
	  // 0b11111111111111111111111110101010 mask
	  // {1, 3, 5, 7 } lastspac[11]
	  // {1, 2, 3 } spac11
	  yp+=(((xp&(1<<lastspac[xlength][0])) >>(lastspac[xlength][0])) + \
	  ((xp&(1<<lastspac[xlength][1]))  >> ((lastspac[xlength][1]) - spacc[ylength][0]))  + \
	    ((xp&(1<<lastspac[xlength][2]))  >>((lastspac[xlength][2]) - spacc[ylength][1]))  + \
	       ((xp&(1<<lastspac[xlength][3]))  >>((lastspac[xlength][3]) - spacc[ylength][2]))); 
	}
	  else // shift up <<
	    {
	      yp+=(((xp&(1<<lastspac[xlength][0]))>>(lastspac[xlength][0]))+ \
		   ((xp&(1<<lastspac[xlength][1]))<< ((spacc[ylength][0]) - lastspac[xlength][1]))  + \
		    ((xp&(1<<lastspac[xlength][2]))<< ((spacc[ylength][1]) - lastspac[xlength][2]))  + \
		     ((xp&(1<<lastspac[xlength][3]))<< ((spacc[ylength][2]) - lastspac[xlength][3])));
	    }

	//	print32bits(&yp);
	//	printf(",\n");
	//	xp=xp<<1;
	yp=yp<<1;
 }

 
   
   //   }
   //output shifts to 8 bits:   {0, 1, 3, 2, 6, 9, 12, 13}
   /*
   int bitsP[8]={0,2,5,9,11,14,18,20};
   for (y=0;y<32;y++){
     cd=0;
   printf("{");
     for (x=0;x<8;x++){
       cd+=gap[y][x];
       if (x<7)     printf("%d,", (cd-x));
       else printf("%d},\n", (cd-x));
}
}*/

   //     for (x=3;x<12;x++){
   //       printf("%d, ",4096/(x));
   //     }
   int length=31, otherpar=2,nn=0;
   n=0;
   /*     for (x=0;x<64000;x++){
  
     if (n>length) { // 0s
       printf("0");
       if (nn>otherpar) {
	 n=0;
       }
       nn++;
     }
     else {
       printf("1");
       n++;
       nn=0;
     }         
     } */   

uint32_t xcc=1<<11;
printf("%d, ",xcc);

uint32_t ee[32]={3, 3, 3, 3, 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

for (x=31;x>0;x--){
  //  printf("%d, ",ee[x]);
 }

//xcc=0b11111001; // test bits for this SR ; // test bits for this SR
//xcc &= ~(1 << 2); // eg. remove loopback = clear bit w

//printf("\n%d, ",xcc);

uint32_t    tmpp=0b11111111; // test bits for this SR 

uint32_t      tmp=tmpp&15; // bottom 4 bits 

/*
for (x=0;x<4;x++){ //unroll?
      if (tmp&0x01){  
	printf("\n%d\n ",x);
      }
    tmp=tmp>>1;
      }	
*/
printf("\n\n ",x);


uint32_t binroute[8][4]={ // add more routes, also what seq change of routes makes sense
  {8,1,2,1}, // 3/0/1/0
  {9,3,6,9}, // as 3/0/1/0 but add loop itself - subtract above to get only looping
  {1,2,4,8}, // only loop - this is what is added to get loop too for prob
  {8,1,2,2}, // as defroutee 3/0/1/1
  {8,1,1,2}, // as altroute 3/0/0/1
  {8,9,1,2}, // bounce L and R back and forth
  {8,1,2,5}, // others
  {2,4,8,1}, // reverse round route
};

for (x=0;x<8;x++){
  tmpp=((binroute[x][0])<<0)+((binroute[x][1])<<4)+((binroute[x][2])<<8)+((binroute[x][3])<<12);
  //  tmp=(tmpp>>4)&15;
  //  printf("%d, ",tmpp);
 }


int w=0;
/*
ADCONLY(0,0)
 else if (w==2){
   printf("2\n");
 }
*/

ADCX(2,2);
printf("3");
}

float pp, mult=0.1f;
int k=4095, kk, CV=4095;

mult=1.0f/((float)(CV)+1.0f); // changed 24/2
pp=(float)k *  mult;// + ((float)(gate[3].dac)*mult); // mix with param

kk=(int)pp;
printf("gggggg:%d\n",kk);

//x= ( ((xp& (1<<lastspac[length][0]))>>lastspacbac[length][0]));// + ((xp& (1<<lastspac[length][1]))>>lastspacbac[length][1]) + ((xp& (1<<lastspac[length][2]))>>lastspacbac[length][2]) + ((xp& (1<<lastspac[length][3]))>>lastspacbac[length][3]) ); 

/*
for (cd=1024;cd>0;cd--){
  pp=cd/1024.0f;
  printf("%f, ",pp);
 }
*/

enum refs {vspeed, vlength, vadc};

//printf("length: %d", vlength);

/*
- how else we can express matrices which makes sense - to match up:

as array for each side:

eg. speed, length, bit FUNCS, adc, which dac // them CV indices

thus:
*/


uint32_t funcN[64][13]={
  {1,1,1,19,0, 5,0,6,0,6,7,1,0},
};

uint32_t funcL[64][13]={
  {1,1,0,19,0, 5,0,6,0,6,0,1,0},
};

uint32_t funcC[64][13]={
  {1,1,0,19,0, 5,0,6,0,6,0,4,0},
};

uint32_t funcR[64][13]={
  {1,0,0,19,0, 5,0,6,0, 6,0,6,0},
};

static heavens gate[9]; // for paralell SR doubled + tail


  gate[0].func=funcN; // pointers...
  gate[1].func=funcL;
  gate[2].func=funcC;
  gate[3].func=funcR;



printf("funcy %d\n",gate[3].func[0][11]);

uint32_t monk=9;
x=y=monk;

printf("x %d y %d\n",y, x);

return 0;
}
