#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "resources.h"

//gcc test2.c -otest -lm -std=gnu99

typedef struct listy_ { 
  uint32_t start;  
  uint32_t length;
  uint32_t layer;
} playl;

playl playlist[120];// list of playbacks
uint32_t playcnt; // for play of playlist
uint32_t playcntr; // for rec of playlist
uint32_t playfull; // how many elements in the playlist

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}

float mod0X(float value, float length)
{
  uint32_t tmp, tmplen, tmpval;
  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    playcnt+=1;
    if (playcnt>playfull) playcnt=0;
    playcntr+=1;
    if (playcntr>118) playcntr=0;
    //    printf("//playcnt %d playcntr %d len %d //",playcnt, playcntr, playlist[playcntr].length);
    length=playlist[playcnt].length;
  }
    return value;
}

float mod0XX(float value, float length)
{
  uint32_t tmp, tmplen, tmpval;
  tmp=playcnt;

  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    tmp+=1;
    if (tmp>playfull) tmp=0;
    length=playlist[tmp].length;
  }
    return value;
}

void speedsample(float speedy){
  uint32_t lowerPosition, upperPosition;
  float play_cnt; // position
  uint32_t lengthy=playlist[playcnt].length;

  play_cnt=mod0X(play_cnt+speedy, lengthy);
  lengthy=playlist[playcnt].length;

    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt;
  upperPosition = mod0XX(lowerPosition + 1, lengthy);

  // test addings
    playlist[playcntr+1].length=(int)play_cnt+1;
    playlist[playcntr+1].start=0;
    playfull=playcntr;
  
  //  printf("lower%d upper %d  %d ",lowerPosition, upperPosition);

  //  int res=(play_cnt - (float)lowerPosition);
    //  Return interpolated table value

  printf("%d ,", (int)play_cnt);
  //  return (int)play_cnt;// + playlist[playcnt].start;
  return;
}

int main(void)
{
  uint32_t x,y,z;
  float speedr=1.0f;
  playlist[0].start=0;
  playlist[0].length=10;
  //  playlist[1].start=0;
  //  playlist[1].length=16;
  playfull=0;
  playcnt=0; 
  playcntr=0; // for rec of playlist
  
  for (x=0;x<256;x++){
    speedsample(speedr);
    //    printf(" %d ,", y);
  
  }
}
