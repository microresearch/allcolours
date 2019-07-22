#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

//skeeve: https://www.avrfreaks.net/forum/256-bit-shift-register-required?page=all

    unsigned char bits[32]; 
    unsigned char hi_mask=0x80, hi_index=31;
    // hi bit is bits[hi_index] & hi_mask
    // a shift will change one bit and
    // alter the labels of all of them

unsigned char shift(unsigned char lo_bit)
{
  unsigned char retval= hi_mask && (bits[hi_index] & hi_mask);
bits[hi_index]&= ~hi_mask;
if(lo_bit) bits[hi_index]|=hi_mask;
hi_mask>>=1;  // shift direction corrected
if(0==hi_mask) {
    hi_mask=0x80;
    hi_index--;
    hi_index &= 31;
}
// printf("mask: %d index: %d ", hi_mask, hi_index);
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

    // see https://www.maximintegrated.com/en/app-notes/index.mvp/id/1743 for taps!    
    // https://www.avrfreaks.net/forum/very-fastsmall-random-number-generator?page=all
    
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
      if (count<128) n=n^1;
      else n=0;
      bat=shift(n);
      count++;
      printf("%d: %d\n", count, bat);
    }
    
    return 0;
}
