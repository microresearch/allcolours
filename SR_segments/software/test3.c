#include "stdio.h"
#include <stdint.h>
#include "math.h"
#include "stdlib.h"
#include "time.h"

typedef struct moods_ { // 
  uint8_t spdfr;
  uint8_t probfr;
  uint8_t incfr;
  uint8_t incor;
  uint8_t last;
  uint32_t *par1, *par2, *par3, *par4;
  uint8_t (*logic)(uint8_t bit1, uint8_t bit2);
} moods;


uint8_t XOR_(uint8_t bit1, uint8_t bit2){
  uint8_t res;
  res=bit1^bit2;
  return res;
}

static uint32_t CV[4]={21,0,0,0};
static uint32_t CVL[4]={0,0,0,0};

//static heavens gate[9]; // for paralell SR doubled + tail

static moods moodsw[64]={
			   {0,0,0,0,0,CV,CV,CV,CV, XOR_}, // test - frs are refs to array, but problem is pars - as refs to CV[w] or gate[w].dac --
}; // how to do refs to dacs  
  // would be easier to pass in modes structure... but...
  //  SRitselftryagain(0, moodsw[0].spdfr, moodsw[0].probfr, moodsw[0].incfr, moodsw[0].incor, moodsw[0].last, moodsw[0].par1,  moodsw[0].par2,  moodsw[0].par3,  moodsw[0].par4, moodsw[0].logic);  // seems to be accepted

void SRitselftryagain(uint8_t w, uint8_t spdfr, uint8_t probfr, uint8_t incfr, uint8_t incor, uint8_t last, uint32_t *par1, uint32_t *par2, uint32_t *par3, uint32_t *par4, uint8_t (*logic)(uint8_t bit1, uint8_t bit2) ){
uint8_t prob;
 prob=logic(1,0);
 printf("%d\n",prob); 
}

void SRitselftry2(uint8_t w, moods *mode){
  uint8_t prob;
  //  prob=mode->logic(0,1); // working
  prob=mode->par1[0];
  printf("%d\n",prob); 
}

static uint32_t sharedindexes[4]={0,0,0,0};
static uint32_t buffer[1024];
static uint32_t head;
static uint32_t resett=1;

static inline uint32_t shared(uint32_t depth, uint8_t wh){
  uint32_t bt=0, bits, x, max=0, top=0;
  static int32_t bc=31, done=0;
  static uint32_t k;

  sharedindexes[wh]++; 

  if (resett==1){
    head++;
    if (head>1023) head=0;
    bits=rand()%2;
    buffer[head]=bits;
    printf("reset new bit=%d into head %d ",bits, head);
    resett=0;
  }

  if (sharedindexes[wh]>1023) sharedindexes[wh]=0;
      printf("called by: %d ownindex is: %d mybit is: %d\n", wh, sharedindexes[wh], buffer[sharedindexes[wh]]); 
}

int main(void)  
{
  int y=0;
  //SRitselftryagain(0, moodsw[0].spdfr, moodsw[0].probfr, moodsw[0].incfr, moodsw[0].incor, moodsw[0].last, moodsw[0].par1,  moodsw[0].par2,  moodsw[0].par3,  moodsw[0].par4, moodsw[0].logic);
  //  SRitselftry2(0, &moodsw[0]);
  //  uint32_t xxx=0b1111;
  //  printf("\n%d\n",xxx); 
  
  for (uint32_t x=0;x<64000;x++){
    //       y=3;
    // how do we simulate speeds...
        if (y==2)       shared(0,y);
            else {
        if ((rand()%3)==1) shared(0,y);
    	          }
    //shared(0,y);
    y++;
    if (y>3) {
      y=0;
      resett=1;
      printf("\nresetz");
    }
  }
}
