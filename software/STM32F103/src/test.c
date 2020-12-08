/// testing

//gcc test.c -otest -lm -std=gnu99 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void main(void){
  uint64_t x,y,z,min=0,max=255,mmm=1, zz, yy, flipped[2];
  x=0; y=!x;
  //  printf("NOT %d\n", y);

  x=0b10000000000000000000000000000000;
  y=0b11110000000000000000000000000000; 
  //  printf ("AND %d\n", x & y);
  //  printf ("OR %d\n", x | y);

  //  printf("&& %d\n", x && y);

  //    printf("nmaxi %u\n", x);

  //shift_registerh= (shift_registerh<<1) + (bith | !(GPIOB->IDR & 0x0400)); // PB10

  x=0;
  y=0x0444;
  
  printf("(bith | !(GPIOB->IDR & 0x0400)) %d\n", (x | !(y & 0x0400)));
  
    // print basic looker

  for (z=1;z<32;z++){
    //    zz=(pow(2,32-z)-1)-((pow(2,z)));
    zz=0;
    for (yy=0;yy<z;yy++){
      //    zz+=pow(2,yy);
    }
    
    printf ("%u, ", zz);
  }

  /*
  for (z=31;z>0;z--){
    //    zz=(pow(2,32-z)-1)-((pow(2,z)));
    zz=0;
    for (yy=31;yy>z;yy--){
    zz+=pow(2,yy);
    }
    
    printf ("%u, ", zz);
  }
  */

  //  uint64_t looker[32]={1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647, 4294967295};

uint32_t looker[32]={2147483648U, 3221225472U, 3758096384U, 4026531840U, 4160749568U, 4227858432U, 4261412864U, 4278190080U, 4286578688U, 4290772992U, 4292870144U, 4293918720U, 4294443008U, 4294705152U, 4294836224U, 4294901760U, 4294934528U, 4294950912U, 4294959104U, 4294963200U, 4294965248U, 4294966272U, 4294966784U, 4294967040U, 4294967168U, 4294967232U, 4294967264U, 4294967280U, 4294967288U, 4294967292U, 4294967294U, 4294967295U}; // we look up length in this from 0-31

 uint32_t targeth, whereh=(0x1fff)<<16, interh=1, speedhh=256, shift_registerh=0x1fff, tmp;
 uint8_t goinguph=0;
 
// test up and down

 for (z=1;z<(speedhh+10)*2;z++){

   if ((z%4)==0)   shift_registerh=rand()%0x1fff;
 
 targeth=(8503-(shift_registerh&0x1FFF))<<16;
 //	targeth=(4407-(shift_registerh&0x0FFF))<<16;
 if (whereh>=targeth) {
   goinguph=0; // decrease
   interh=(whereh-targeth)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
 }	  
 else {
   goinguph=1; // increase
   interh=(targeth-whereh)/(speedhh+1); // and if goes down to 0 which will do as speedh maxes at 16383 - so
 }

 //    printf("START SR %zu target %zu where %zu inter %zu >>16 %zu\n", shift_registerh, targeth, whereh, interh, tmp);

 

   if (goinguph==1){ // 
    // increase whereh
    whereh+=interh;
    tmp=(whereh>>16);
    if (tmp>=(targeth>>16)) {
       goinguph=2;
       //       break;
     }
    printf("SR %zu target %zu where %zu inter %zu targeth >> 16 %zu tmp >>16 %zu\n", shift_registerh, targeth, whereh, interh, targeth>>16, tmp);

  }

  if (goinguph==0){
    // decrease whereh
    whereh-=interh;
    tmp=(whereh>>16);
    if (tmp<=(targeth>>16)) {
      goinguph=2;
      //      break;
    }
    printf("SR %zu target %zu where %zu inter %zu targeth >> 16 %zu tmp >>16 %zu\n", shift_registerh, targeth, whereh, interh, targeth>>16, tmp);
  }
 }
 
  
//  if ((x | y) == looker[3]) printf("YES\n");
//  else   printf ("xORy %u \n", x | y);

  y=255;

  //  y^=1;

  printf("<<24 %zu\n", y<<24);

}
