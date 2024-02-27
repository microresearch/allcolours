#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"

//gcc test2.c -otest -lm -std=gnu99

    enum STATE {
      N,
      R,
      P,
      RP
    };


typedef struct listy_ { 
  uint32_t start;  
  uint32_t length;
  uint32_t layer;
} playl;

playl playlist[120];// list of playbacks
uint32_t playcnt; // for play of playlist
uint32_t playcntr; // for rec of playlist
uint32_t playfull; // how many elements in the playlist

float play_cnt_[2]={0.0, 0.0}; // for 2 layers
uint32_t othercnt[2]={0,0};

#define FULL 26

static uint32_t modded=0;
static float cnt=0;

inline static float mod0(float value, float length, float start)
{
  while (value > (FULL-1)){
    value -= FULL;
  }
  
  if (cnt>length){
    cnt=0;
    value=start;
  }
  return value;
}

#define REC_END 20

void speedsample(float speedy, uint32_t layer, uint32_t start){
  uint32_t lowerPosition, upperPosition;
  uint32_t lengthy=playlist[playcnt].length;
  play_cnt_[layer]=mod0(play_cnt_[layer]+speedy, lengthy, start);
  cnt=cnt+speedy;
  lowerPosition = (int)play_cnt_[layer];
  printf("cnt %d %d\n", cnt, lowerPosition);
  //  upperPosition = mod0XX(lowerPosition + 1, lengthy);

  //  return (int)play_cnt;// + playlist[playcnt].start;
  return;
}


int main(void)
{
  uint32_t x=0,y=0,z=0;
  float speedr=0.5f;
  static uint32_t playing, playexit;
  playfull=0;
  playcnt=0; 

  playlist[0].length=4;
  play_cnt_[0]=1; // start-1
  playcntr=1;
  while (x<64){
    x++;
    speedsample(speedr, 0, 2);
  }
}
