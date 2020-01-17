
#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

unsigned char bits[32], head; 

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
        {31, 29, 25, 24},
  };





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
printf("\n");
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

uint8_t g_buf[4]={0xaa,0xaa,0xaa,0xaa};
//uint8_t g_buf[4]={0xff,0xff,0xff,0xff}; 

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
      printf("%d\n",carry_out);
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
  uint8_t SRlengthh=4;
 
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


void varshifter_lfsr(uint8_t length) // tested working NOW!
{
  uint32_t bith;
  uint32_t *shift_register = (uint8_t *)g_buf;
  uint8_t SRlengthh=length; // always real length minus one

  //  uint8_t shifter=3SRlengthh; // always real length minus one
 
  //  bith = *shift_register>>31; // bit which would be shifted out - always 31 as at the end
  //  printf ("bith: %d\n",bith);
  //  bith= ((*shift_register >> (lfsr_taps[SRlengthh][0]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][1]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][2]-1+shifter)) ^ (*shift_register >> (lfsr_taps[SRlengthh][3]-1+shifter))) & 1u; // 32 is 31, 29, 25, 24
  //    bith= ((*shift_register >> (lfsr_taps[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

  //      bith= ((*shift_register >> (lfsr_taps_mirrored[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

          bith= ((*shift_register >> (lfsr_taps_mirrored[SRlengthh][0])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][1])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][2])) ^ (*shift_register >> (lfsr_taps_mirrored[SRlengthh][3]))) & 1u; // 32 is 31, 29, 25, 24

      
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
  //    print32bits(shift_register);
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
    x=0b1111111111111111;
    
    x &= ~0xff;
    printf("%d\n", x);
    
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
    unsigned char n=31;
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
    return 0;
}
