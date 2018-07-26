#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

// 16 bit 65k repeat

int main(void)
{
    uint16_t start_state = 0xACE1u;  /* Any nonzero start state will work. */
    uint16_t lfsr = start_state;
    uint16_t bit;                    /* Must be 16bit to allow bit<<15 later in the code */
    unsigned period = 0;
    unsigned char bat;
    unsigned char biit=0x05;

    //    if (!(biit & 0x20)) printf("BIT\n");
    
       do
    {
        /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
        bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    	// slipped bit based on what kind of random???
    	if (bit==1)	printf("x");
    	else printf("0");
    	lfsr =  (lfsr >> 1) | (bit << 15);
        ++period;
    } while (1);

    return 0;
}
