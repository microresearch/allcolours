#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"
#define PLAYFULLY 119 // length of playlist in fingers.h
#include "fingers.h"

//gcc test4.c -otest -lm -std=gnu99

#define MAXREC 128

void reclodge(uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ 
  uint32_t x, y, tmpx, tmpxx;
  // tape 0 lower
  for (x=0;x<f[d].l[0].num_lodges;x++){
    f[d].l[0].lodges[x].delcnt++;
    if (f[d].l[0].lodges[x].delcnt>f[d].l[0].lodges[x].delay){      
      tmpx=f[d].l[0].lodges[x].cnt+f[d].l[0].lodges[x].start;
      if (f[d].l[0].lodges[x].over==0) f[d].l[0].lodges[x].realend=tmpx; // fixed
      
      if (tmpx>f[d].l[0].lodges[x].end) { // redo delay
	f[d].l[0].lodges[x].delcnt=0;
	f[d].l[0].lodges[x].realend=f[d].l[0].lodges[x].end;
	tmpx=f[d].l[0].lodges[x].start;
	f[d].l[0].lodges[x].cnt=0;
	f[d].l[0].lodges[x].over=1;
    }

      if (f[d].l[0].lodges[x].delcnt!=0 || f[d].l[0].lodges[x].delay==0){
	printf("write tmpx %d real %d\n",tmpx, f[d].l[0].lodges[x].realend);
	//      tmpxx=overlayx(value, (recordings[d][tmpx]&BOTS), (R_options>>2)&3); 
      //      reclayerlower(tmpxx, tmpx, d);
      f[d].l[0].lodges[x].cnt++;
      f[d].l[0].lodges[x].rcnt++;
      }
    }
    else     printf("del %d\n",f[d].l[0].lodges[x].delcnt);
  }
}

void main(void){
  uint32_t x, dacc=0, samples[1024];
  // setup list of lodges and test them
  // testing delay DONE
  f[0].l[0].num_lodges=1;
  f[0].l[0].lodges[0].delcnt=0;
  f[0].l[0].lodges[0].delay=0;
  f[0].l[0].lodges[0].delcnt=0;
  f[0].l[0].lodges[0].cnt=0;
  f[0].l[0].lodges[0].start=10;
  f[0].l[0].lodges[0].end=32;
  // test overlap and realend
  for (x=0;x<64;x++){
  reclodge(0,66,0,0);
  }
}
