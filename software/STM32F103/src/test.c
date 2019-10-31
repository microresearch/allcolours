/// testing

//gcc test.c -otest -lm -std=gnu99 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void main(void){
  uint64_t x,y,z,min=0,max=255,mmm=1, zz, yy;
  x=0; y=!x;
  printf("NOT %d\n", y);

  x=0b10000000000000000000000000000000;
  y=0b11110000000000000000000000000000; 
  printf ("AND %d\n", x & y);
  printf ("OR %d\n", x | y);

  printf("&& %d\n", x && y);

    printf("nmaxi %u\n", x);
  
  for (z=31;z>0;z--){
    //    zz=(pow(2,32-z)-1)-((pow(2,z)));
    zz=0;
    for (yy=31;yy>z;yy--){
    zz+=pow(2,yy);
    }
    
    printf ("%u, ", zz);
  }
  

  uint64_t looker[32]={1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647, 4294967295};

  if ((x | y) == looker[27]) printf("YES\n");
  else   printf ("xORy %u \n", x | y);

  
}
