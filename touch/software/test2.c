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

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}

static uint32_t modded=0;

float mod0X(float value, float length, uint32_t start)
{
  uint32_t tmp, tmplen, tmpval;
  modded=0;
  while (value > (length-1)){ // we are ahead - get next in list
  value -= length; //0

    if (othercnt[0]>0) {
    playlist[playcntr].length=othercnt[0]-playlist[playcntr].start;
    //    printf("pp: %d xx:%d\n",playcntr, playlist[playcntr].length );
    playcntr++; // ignore zero length
    playfull++;
    playlist[playcntr].start=0;
    //    playlist[playcntr].length=REC_END-othercnt[0];
  }

  
    // get next in list
    playcnt+=1; 
    if (playcnt>=playfull) playcnt=0;
      length=playlist[playcnt].length;
    // add to list
  //  if (othercnt[0]>0) {
    //    playcntr++; 
    //    playfull++;
    //    if (playfull>=120) playfull=119;
    //    if (playcntr>=120) playcntr=119;
    //    playlist[playcntr].length=othercnt[0];
    //    playlist[playcntr].start=start; 
  //  }
  othercnt[0]=0;
   //   printf("playcnt: %d\n", playcnt);
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
    //    tmp+=1;
    //    if (tmp>playfull) tmp=0;
    //    length=playlist[tmp].length;
  }
    return value;
}


#define REC_END 20

void speedsample(float speedy, uint32_t layer){
  uint32_t lowerPosition, upperPosition;
  uint32_t lengthy=playlist[playcnt].length;
  uint32_t start=playlist[playcnt].start;
  //printf("p:%d",playcnt);
  //  printf(" %d ,", start+(int)play_cnt_[layer]);
  othercnt[layer]++;
  //  if (othercnt[layer]>REC_END) othercnt[layer]=0;
  play_cnt_[layer]=mod0X(play_cnt_[layer]+speedy, lengthy, start);
  lengthy=playlist[playcnt].length;//???
  
    //  Find surrounding integer table positions
  lowerPosition = (int)play_cnt_[layer];
  upperPosition = mod0XX(lowerPosition + 1, lengthy);

  //  return (int)play_cnt;// + playlist[playcnt].start;
  return;
}

int main(void)
{
  uint32_t x=0,y=0,z=0;
  float speedr=1.0f;
  static uint32_t playing, playexit;
  playfull=0;
  playcnt=0; 

  playlist[0].start=0;
  playlist[0].length=20;
  playcntr=1;
  // we enter playlist 1
  while (x<6){
    x++;
    speedsample(speedr, 0);
  }

  if (othercnt[0]>0) {
    playlist[playcntr].length=othercnt[0]-playlist[playcntr].start;
    //    printf("pp: %d xx:%d\n",playcntr, playlist[playcntr].length );
    playcntr++; // ignore zero length
    playfull++;
    playlist[playcntr].start=othercnt[0];
    //    playlist[playcntr].length=REC_END-othercnt[0];
  }
  // we enter playlist 2
  //  othercnt[0]=0;
  //  play_cnt_[0]=0;
  x=0;
  //  printf("xx**\n");
  while (x<48){
    x++;
    speedsample(speedr, 0);
  }
  //  printf("playcntr %d other %d", playcntr, othercnt[0]);
  if (othercnt[0]>0) {
    playlist[playcntr].length=othercnt[0]-playlist[playcntr].start;
    //    printf("pp: %d xx:%d\n",playcntr, playlist[playcntr].length );
    playcntr++; // ignore zero length
    playfull++;
    playlist[playcntr].start=othercnt[0];
    //    playlist[playcntr].length=REC_END-othercnt[0];
  }
  // we enter playlist 3
  //  othercnt[0]=0;
  //  play_cnt_[0]=0;
  x=0;
  //  printf("xx**\n");
  while (x<2){
    x++;
    speedsample(speedr, 0);
  }

  //  printf("playcntr %d other %d", playcntr, othercnt[0]);
  if (othercnt[0]>0) {
    playlist[playcntr].length=othercnt[0]-playlist[playcntr].start;
    //    printf("pp: %d xx:%d\n",playcntr, playlist[playcntr].length );
    playcntr++; // ignore zero length
    playfull++;
    playlist[playcntr].start=othercnt[0];
    //    playlist[playcntr].length=REC_END-othercnt[0];
  }
  // we enter playlist 4
  //  othercnt[0]=0;
  //  play_cnt_[0]=0;
  x=0;
  //  printf("xx**\n");
  while (x<2){
    x++;
    speedsample(speedr, 0);
  }

  
  printf("\n");
  for (x=0;x<24;x++){
        printf("x: %d start %d len: %d\n", x, playlist[x].start, playlist[x].length);
  }

  const float *playreff[4]={logfast, logslow, logfast_stop, logspeed_stop}; 
  printf("HERE: %f RP: %d\n", playreff[0][0], RP);
}
