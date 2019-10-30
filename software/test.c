#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

unsigned char bits[32], head; 


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
  uint8_t SRlengthh=8;
 
  bith = *shift_register>>31; // bit which would be shifted out - always 31 as at the end
  //  printf ("bith: %d\n",bith);

  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  
  *shift_register+= (bith <<(31-SRlengthh)); // PB7 and PB10

  /* 
  bith = *shift_register>>31; // bit which would be shifted out
  *shift_register=*shift_register<<1; // we are shifting left << so bit 31 is out last one
  *shift_register+=bith;
  */
  print32bits(shift_register);
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
    uint16_t bit,count=0;                    /* Must be 16bit to allow bit<<15 later in the code */
    unsigned period = 0;
    unsigned char bat;
    unsigned char biit=0x05;

  
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
    unsigned char n=0;
    while(1){
      //      if (count<32) n=n^1;
      //      else n=0;
      //bat=shift256bit_32(bat^binmask32);
      //      for (n=0;n<32;n++){
      //      bat=lfsr32();
      varshifter();
      
      //      if (bat==0) printf("1");
      //      else printf("0");
      //      }
      //      printf("\n");
      //      uint8_t shift256bit_32(uint8_t carry_in)
      //      printf("%d: %d\n", count, bat);
      //      printbits();
      count++;
      //      printbits(&g_buf[0]);
    }
    
    return 0;
}
