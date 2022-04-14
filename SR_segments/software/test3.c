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


int main(void)  
{
  //SRitselftryagain(0, moodsw[0].spdfr, moodsw[0].probfr, moodsw[0].incfr, moodsw[0].incor, moodsw[0].last, moodsw[0].par1,  moodsw[0].par2,  moodsw[0].par3,  moodsw[0].par4, moodsw[0].logic);
  SRitselftry2(0, &moodsw[0]);
  uint32_t xxx=0b1111;
  printf("\n%d\n",xxx); 
  

  
}
