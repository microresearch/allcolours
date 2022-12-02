#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"

//gcc binary.c -obin -lm -std=gnu99 

uint64_t longer;

/* --- PRINTF_BYTE_TO_BINARY macro's --- */
#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i)    \
    (((i) & 0x80ll) ? '1' : '0'), \
    (((i) & 0x40ll) ? '1' : '0'), \
    (((i) & 0x20ll) ? '1' : '0'), \
    (((i) & 0x10ll) ? '1' : '0'), \
    (((i) & 0x08ll) ? '1' : '0'), \
    (((i) & 0x04ll) ? '1' : '0'), \
    (((i) & 0x02ll) ? '1' : '0'), \
    (((i) & 0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16 \
    PRINTF_BINARY_PATTERN_INT8              PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BYTE_TO_BINARY_INT16(i) \
    PRINTF_BYTE_TO_BINARY_INT8((i) >> 8),   PRINTF_BYTE_TO_BINARY_INT8(i)
#define PRINTF_BINARY_PATTERN_INT32 \
    PRINTF_BINARY_PATTERN_INT16             PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BYTE_TO_BINARY_INT32(i) \
    PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)
#define PRINTF_BINARY_PATTERN_INT64    \
    PRINTF_BINARY_PATTERN_INT32             PRINTF_BINARY_PATTERN_INT32
#define PRINTF_BYTE_TO_BINARY_INT64(i) \
    PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)
/* --- end macros --- */

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



#include <stdio.h>
int main() {
  uint32_t x, srlength=8, sh, shifter=4, tmpt, SRlengthn=8, sl=4, bitn=1, tmp;
  uint32_t shift_registern=0b11110000000000000000000011110000;
  uint32_t shift_register= 0b00000000000000000000000011110000;
  // copy shift reg into longer - top is always top of SR (bit 31)
  longer=shift_register;

  // try again loop/overlap SR
    for (x=0;x<32;x++){
    // top shifter bits at length srlength
      // shifter can not be longer than srlength and not less than 0
  tmp=(shift_registern&(othermasky[shifter]>>(31-srlength)))>>(srlength-(shifter-1));
  shift_registern=shift_registern<<shifter;
  shift_registern+=tmp;
  
    
        printf(""
    	   PRINTF_BINARY_PATTERN_INT32 ",\n",
    	   PRINTF_BYTE_TO_BINARY_INT32(shift_registern));
}
  
  
  /*  for (x=31;x>-1;x--){ // so this is wrapping reg but we want <<3 test wrap for 32 bits
    //  printf(""
    //	   PRINTF_BINARY_PATTERN_INT32 ",\n",
    //	   PRINTF_BYTE_TO_BINARY_INT32(shift_register));
    //		shift_register=shift_register<<1;
    //    longer=longer<<1;
    //    shift_register=(longer&0b11111111111111111111111111111111)+(longer>>32); // bottom x=32 bits; + bit at top
    //  }
  longer=longer<<shifter; // shifter must be below length
  sh=31-srlength;

  shift_register =(longer&masky[srlength])+((longer&((0b1111111111111111111111111111111100000000000000000000000000000000)+othermasky[31-srlength]))>>(srlength+1)); // this one works

  // bottom x bits
  
  //  shift_register =((longer&((0b1111111111111111111111111111111100000000000000000000000000000000)+othermasky[31-srlength]))>>(srlength+1)); 

  
  //  shift_register=  shift_register=(longer&othermasky[srlength])+((longer&((0b1111111111111111111111111111111100000000000000000000000000000000)+othermasky[31-srlength]))>>(srlength+1)); 

  printf(""
	   PRINTF_BINARY_PATTERN_INT32 ",\n",
	   PRINTF_BYTE_TO_BINARY_INT32(shift_register));
  
  // to test:
    tmpt=(SRlengthn-(sl-1)); // again what if sl is longer than lengthn - this is key figure
    //    if (tmpt<(sl-1)) tmpt=(sl-1); // double check this!
    shift_register=((shift_register<<1) & ~(masky[sl-1])); // checked
    //    number &= ~(1UL << n);

    // we want top sl-1 bits which are at length x
        shift_register+=( (shift_registern&((othermasky[sl-1]>>(32-SRlengthn))))>> tmpt);
    //    shift_register=(othermasky[sl-1])>>(32-(SRlengthn));
    //        shift_register+=(bitn<<(sl-1)); // but that bit needs to be empty - it is masked
  
	//  printf(""
	//	   PRINTF_BINARY_PATTERN_INT32 ",\n",
	//	   PRINTF_BYTE_TO_BINARY_INT32(shift_register));

  }
  */
    // but how this becomes part of coggs
    // we want overlap_length=x which is top x bits of shift_register shifted to bottom
	/*    
  for (x=0;x<32;x++){ // so this is wrapping reg but we want <<3 test wrap for 32 bits
    uint32_t pp= ~(masky[x]);
    //    printf(", %u", pp);
    printf("0b"
	   PRINTF_BINARY_PATTERN_INT32 ",\n",
    	   PRINTF_BYTE_TO_BINARY_INT32(pp));

  }
	*/
  return 0;
}
