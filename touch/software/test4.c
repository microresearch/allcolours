#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"
#define PLAYFULLY 119 // length of playlist in fingers.h
#include "fingers.h"

//gcc test4.c -otest -lm -std=gnu99

#define MAXREC 128

//  lodgep=f[0].l[0].lodges; // can be passed in - but need to pass both layers
//  printf("testl: %d \n", lodgep[0].delcnt); 
// TODO: trial function passing in lodges (but lodges is after layers...)
// f[d].l[0].lodges[x].delcnt - pass in both

//TODO: attachment, does each lodge/zone have a function attached?
void reclodgex(zonel *lodge1, zonel *lodge2, uint32_t d, uint32_t value, uint32_t layer, uint32_t R_options){ // for any d... pass it in...
  uint32_t x, y, tmpx, tmpxx;
  // tape 0 lower
  for (x=0;x<f[d].l[layer].num_lodges;x++){
    lodge1[x].delcnt++;
    if (lodge1[x].delcnt>=lodge1[x].offset && (lodge1[x].delcnt<=(lodge1[x].offset+lodge1[x].end-lodge1[x].start))) {     
      tmpx=lodge1[x].cnt+lodge1[x].start;
      if (lodge1[x].over==0) lodge1[x].realend=tmpx; // fixed
      if (tmpx>lodge1[x].end) { // now we want final delay before we start again
	lodge1[x].realend=lodge1[x].end;
	tmpx=lodge1[x].start;
	lodge1[x].cnt=0;
	lodge1[x].over=1;
    }

	printf("write tmpx %d real %d\n",tmpx, lodge1[x].realend);
	lodge1[x].cnt++;
	lodge1[x].rcnt++;
    }
    else     {
      printf("del %d\n",lodge1[x].delcnt);
    }
    if (lodge1[x].delcnt>=(lodge1[x].offset+lodge1[x].end+lodge1[x].delay-lodge1[x].start)) lodge1[x].delcnt=0;
  }
}


// question of end is length or end point? as now it includes the start
void reclodge(uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ 
  uint32_t x, y, tmpx, tmpxx;
  // tape 0 lower
  for (x=0;x<f[d].l[0].num_lodges;x++){
    f[d].l[0].lodges[x].delcnt++;
    if (f[d].l[0].lodges[x].delcnt>=f[d].l[0].lodges[x].offset && (f[d].l[0].lodges[x].delcnt<=(f[d].l[0].lodges[x].offset+f[d].l[0].lodges[x].end-f[d].l[0].lodges[x].start))) {     
      tmpx=f[d].l[0].lodges[x].cnt+f[d].l[0].lodges[x].start;
      if (f[d].l[0].lodges[x].over==0) f[d].l[0].lodges[x].realend=tmpx; // fixed
      
      if (tmpx>f[d].l[0].lodges[x].end) { // now we want final delay before we start again
	//f[d].l[0].lodges[x].delcnt=0;
	f[d].l[0].lodges[x].realend=f[d].l[0].lodges[x].end;
	tmpx=f[d].l[0].lodges[x].start;
	f[d].l[0].lodges[x].cnt=0;
	f[d].l[0].lodges[x].over=1;
    }

      //    if (f[d].l[0].lodges[x].delcnt!=0 || f[d].l[0].lodges[x].offset==0){
	printf("write tmpx %d real %d\n",tmpx, f[d].l[0].lodges[x].realend);
	//      tmpxx=overlayx(value, (recordings[d][tmpx]&BOTS), (R_options>>2)&3); 
      //      reclayerlower(tmpxx, tmpx, d);
      f[d].l[0].lodges[x].cnt++;
      f[d].l[0].lodges[x].rcnt++;
      //                 }
    }
    else     {
      printf("del %d\n",f[d].l[0].lodges[x].delcnt);
    }
    if (f[d].l[0].lodges[x].delcnt>=(f[d].l[0].lodges[x].offset+f[d].l[0].lodges[x].end+f[d].l[0].lodges[x].delay-f[d].l[0].lodges[x].start)) f[d].l[0].lodges[x].delcnt=0;
  }
}

void main(void){
  uint32_t x, dacc=0, samples[1024];
  // setup list of lodges and test them
  // testing delay DONE
  f[0].l[0].num_lodges=1;
  f[0].l[0].lodges[0].delcnt=0;
  f[0].l[0].lodges[0].delay=3;
  f[0].l[0].lodges[0].offset=0;
  f[0].l[0].lodges[0].delcnt=0;
  f[0].l[0].lodges[0].cnt=0;
  f[0].l[0].lodges[0].start=10;
  f[0].l[0].lodges[0].end=32;
  // test overlap and realend
  for (x=0;x<70;x++){
    //  reclodge(0,66,0,0);
    reclodgex(f[0].l[0].lodges, f[0].l[1].lodges, 0, 66, 0, 0);
  }

  // test pointer to lodges

  zonel *lodgep;
  //  lodgep=f[0].l[0].lodges; // can be passed in - but need to pass both layers
  //  printf("testl: %d \n", lodgep[0].delcnt); 
// TODO: trial function passing in lodges (but lodges is after layers...)
// f[d].l[0].lodges[x].delcnt - pass in both

  
  // TODO: test adding to playlist - or new playlist scheme of zones///

  
}
