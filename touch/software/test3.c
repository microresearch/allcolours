#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"
#define PLAYFULLY 119 // length of playlist in fingers.h
#include "fingers.h"

//gcc test3.c -otest -lm -std=gnu99

#define MAXREC 128


inline static float mod0(float value, float start, float ending, float length, uint32_t d, uint32_t layer) // new one with start and ending/loop point
{
  static uint32_t lengthed;
  lengthed=0;
  while (value > (ending-1)){ // wrapping
    value -= ending;
  }
  while (f[d].l[layer].cnt>(length-1)){ // get next in list
    f[d].l[layer].cnt-=length;
    f[d].playcnt+=1; 
    if (f[d].playcnt>=f[d].playfull) f[d].playcnt=0;
    length=f[d].playlist[f[d].playcnt].length;
    start=f[d].playlist[f[d].playcnt].start;
    lengthed=1;
  }
  if (lengthed==1) {
    value=f[d].l[layer].cnt+start;
  }
  return value;
}

inline static float mod00(float value, float start, float ending, float length, uint32_t d, uint32_t layer) // new one with start and ending/loop point
{
  static uint32_t lengthed;
  uint32_t tmpcnt;
  float tmpp;
  tmpcnt=f[d].playcnt;
  lengthed=0;
  while (value > (ending-1)){
    value -= ending;
  }

  tmpp=f[d].l[layer].cnt+1;
    if ((tmpp)>(length-1)){
    tmpp-=length;
    lengthed=1;
    tmpcnt+=1; 
    if (tmpcnt>=f[d].playfull) tmpcnt=0;
    length=f[d].playlist[tmpcnt].length;
    start=f[d].playlist[tmpcnt].start;
    }
  if (lengthed) {
    value=tmpp+start;
    }
  return value;
}

uint32_t speedsampleplay(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition, layer;
  float sample;
  lengthy=f[dacc].playlist[f[dacc].playcnt].length;
  end=f[dacc].playlist[f[dacc].playcnt].end;
  start=f[dacc].playlist[f[dacc].playcnt].start;
  layer=f[dacc].playlist[f[dacc].playcnt].l;

  f[dacc].l[layer].cnt+=speedy;
  
  f[dacc].l[layer].play_cnt=mod0(f[dacc].l[layer].play_cnt+speedy, start, end, lengthy, dacc, layer);
  lowerPosition = (int)f[dacc].l[layer].play_cnt;
  upperPosition = mod00(lowerPosition + 1, start, end, lengthy, dacc, layer);
  int32_t res=(f[dacc].l[layer].play_cnt - (float)lowerPosition);
  //  lowerPosition+=start;
  //  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  if (layer==0){  
    //   LOWER;
    printf("xx %d, ", (int)upperPosition);  }
  else {
    //    UPPER;
  }
  return (uint32_t)sample;
}

inline static void resett(uint32_t dacc){
  f[dacc].rpp=0;
  f[dacc].active=1;
  f[dacc].masterL=0;
  f[dacc].minormode[0]=0;
  f[dacc].minormode[1]=0;
  f[dacc].minormode[2]=0;
  f[dacc].minormode[3]=0;  
  f[dacc].majormode[0]=0;
  f[dacc].majormode[1]=0;
  f[dacc].majormode[2]=0;
  f[dacc].majormode[3]=0;  
  f[dacc].playspeed=0;
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].state=N; // NADA
  f[dacc].playcnt=0;
  f[dacc].playfull=0;
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].l[0].rec_cnt=0;  
  f[dacc].l[1].rec_cnt=0;
  f[dacc].l[0].rec_length=0;  
  f[dacc].l[1].rec_length=0;
  f[dacc].l[0].rec_start=0;  
  f[dacc].l[1].rec_start=0;
  f[dacc].l[0].play_cnt=0;
  f[dacc].l[1].play_cnt=0;
  f[dacc].l[0].rec_end=0;
  f[dacc].l[1].rec_end=0;
  f[dacc].l[0].cnt=0;
  f[dacc].l[1].cnt=0;
  f[dacc].lastmode=0;
  f[dacc].sensi=0;
  f[dacc].entryp=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
}



void main(void){
  uint32_t x, dacc=0, samples[1024];
  for (x=0;x<8;x++){
	resett(x);
  }

  // make first item in playlist
  f[dacc].playlist[0].length=13;
  f[dacc].playlist[0].end=12;
  f[dacc].playlist[0].start=8;
  f[dacc].playlist[0].l=0;
  f[dacc].playfull=1;
  f[dacc].l[0].play_cnt=f[dacc].playlist[0].start; // TODO
    
  for (x=0;x<64;x++){
    speedsampleplay(1.0f, 12, 0, 12, 0, samples);
    //    printf("x: %d x %d\n",x, (int)f[dacc].l[0].play_cnt);
  }
  
}
