#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_tim.h"
#include <sys/unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/times.h>
#include "misc.h"
#include "resources.h"
#include "macros000.h"

#define TOPS 0b11111111111111110000000000000000
#define BOTS 0b00000000000000001111111111111111
#define TOP 4095

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRKF 8 // for freezer. 8 with 24 divider ////now 48 with divider of 8; was 8 when we have have divider in main as 32... too high causes issues for speed of freezes
#define BRK 8 // 8 is for when we have mode etc toggles outside main loop // was 128 // this is for mode and other toggles...
#define DELB 42 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK -- is delay we hold the the freeze/toggle
#define DELA 32 // for clear DAC // was 64

#define FULLRESET 1200 // say 6 seconds
#define SOFTRESET 800 // soft - over 4 seconds
#define SHORTMODE 8 // was 20ms could be shorter...
#define LONGMODE 280 // 2 sec
#define LONGTOG 300 // 1-2 secs long press for TOGGLE->activate
//#define PLAYFULLY 24 // length of playlist in fingers.h
#define LODGEFUL 27 // 0-27 = 28 lodges
#define THRESH 2048 // threshold for masking etc...

#ifdef fouronethree
#define MAXREC 8400 // was 9000/ prev 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#else
#define MAXREC 3800 // for older STM
#endif
// with F413 we have 9200 which is how long - around 20 seconds now on 24 divider

#define LOWVAL 40 // lowest value to trigger recordings

//#define MAXMODES 8

uint32_t MAXMODE[4]={8,8,8,8};

GPIO_InitTypeDef GPIO_InitStructure;
extern __IO uint32_t adc_buffer[8];

static uint32_t recordings[8][MAXREC+1]={0}; // 
static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
static int32_t control[4];
static uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10 NOW STATIC!
const uint32_t whichctrl[8]={0,1,2,3,0,1,2,3}; // ref for newADC speeds
const float *playreff[4]={logfast, logslow, logfast_stop, logslow_stop}; 
static uint32_t Theldon[8]={0,0,0,0, 0,0,0,0};

static uint32_t error=0;

#include "fingers.h"

void send_command(int command, void *message)
{
   asm("mov r0, %[cmd];"
       "mov r1, %[msg];"
       "bkpt #0xAB"
         :
         : [cmd] "r" (command), [msg] "r" (message)
         : "r0", "r1", "memory");
}

char buffx[10];

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

#define delay()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < DELB; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)

#define delay2()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < DELA; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)


#define delayy()						 do {	\
    register unsigned int ix;					\
    for (ix = 0; ix < 10000000; ++ix)				\
      __asm__ __volatile__ ("nop\n\t":::"memory");		\
  } while (0)



uint32_t nosilence(uint32_t value){
  if (value>LOWVAL) return 1;
  else return 0;
}

uint32_t always(uint32_t value){
  return 1;
}


inline static uint32_t overlaylive(uint32_t value, uint32_t value2, uint32_t over){  // 2 bits = 4 options
  uint32_t tmpp;
  int32_t subs;
 	    if (over==0){ //usual - now swopped for >
	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==1){ 
	      tmpp=value2+value;
	      if (tmpp>TOP) tmpp=TOP; 
	    }
	    else if (over==2){ // mod
	      tmpp=value2+value;
	      tmpp=tmpp%4096;
	    }
	    else { // subtract live and do abs...
	      subs=value2-value;
	      tmpp=abs(subs);
	    }
	    return tmpp;
}

inline static uint32_t overlayx(uint32_t value, uint32_t value2, uint32_t over){ // 3 bits = 8 options
  uint32_t tmpp; int32_t subs;
  float nn;
  over=0; // TESTY!
  if (over==0){ // solo
    tmpp=value;
  }
  else if (over==1){
    if (value>value2) tmpp=value; // only if is more than
    else tmpp=value2;
  }
  else if (over==2){ 
    tmpp=value2+value;
    if (tmpp>TOP) tmpp=TOP;
  }
  else if (over==3){ 
    tmpp=value2+value;
    tmpp=tmpp%4096;
  }
  else if (over==4){ // no silence on top
    if (value>LOWVAL) tmpp=value;
    else tmpp=value2;
    }
  else if (over==4){	    //add VCA/float thing /// but need more bits and more options
    nn=value/4095.0;
    nn*=(float)value2;
    tmpp=(uint32_t)nn;
  }
  else if (over==5){	    //add VCA/float thing /// but need more bits and more options -> 3 bits=8 options...  +2 - mask/threshold!?
    value=4095-value;
    nn=value/4095.0;
    nn*=(float)value2;
    tmpp=(uint32_t)nn;
  }
  else if (over==6){ // 	      //	      - mask/threshold
    if (value>THRESH) tmpp=value2;
    //    else tmpp=0;
  }
  return tmpp;
}

inline static void resetx(uint32_t which){
  for (uint32_t y=0;y<=MAXREC;y++){ 
    recordings[which][y]=0;
  }
}

void resett(uint32_t dacc){
  f[dacc].rec=1;
  f[dacc].rl[0].ind=0;
  f[dacc].rl[1].ind=0;					
  f[dacc].ttoggle=0;
  f[dacc].state=NR;
  f[dacc].leaverr=0;
  f[dacc].leaverp=0;
  f[dacc].active=1;
  f[dacc].masterL[0]=0;
  f[dacc].masterL[1]=0;
  f[dacc].minormode[0][0]=0;
  f[dacc].minormode[0][1]=0;
  f[dacc].minormode[0][2]=0;
  f[dacc].minormode[0][3]=0;  
  f[dacc].minormode[1][0]=0;
  f[dacc].minormode[1][1]=0;
  f[dacc].minormode[1][2]=0;
  f[dacc].minormode[1][3]=0;  
  f[dacc].majormode[0]=0;
  f[dacc].majormode[1]=0;
  f[dacc].majormode[2]=0;
  f[dacc].majormode[3]=0;  
  f[dacc].playspeed[0]=0;
  f[dacc].playspeed[1]=0;
  f[dacc].ttoggle=0;
  f[dacc].rl[0].num_lodges=0;
  f[dacc].rl[1].num_lodges=0;
  //  f[dacc].lastmode=0;
  f[dacc].sensi=0;
  f[dacc].entryd[0]=0;
  f[dacc].entryd[1]=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
  //  f[dacc].playlistm=0;
  //  f[dacc].playlistp=0;
  for (uint32_t x=0;x<8;x++){ 
    resetx(x);
  }
  // zero all lodges
  for (uint32_t y=0;y<MAXLODGE;y++){
    f[dacc].rl[0].lodges[y].function=nosilence;
    f[dacc].rl[1].lodges[y].function=nosilence;	
    f[dacc].rl[0].lodges[y].sil=0;
    f[dacc].rl[1].lodges[y].sil=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].rl[1].lodges[y].realend=0;
    f[dacc].rl[0].lodges[y].end=MAXREC;
    f[dacc].rl[1].lodges[y].end=MAXREC;
    f[dacc].rl[0].lodges[y].linkage=0;
    f[dacc].rl[1].lodges[y].linkage=0;
    f[dacc].rl[0].lodges[y].start=0;
    f[dacc].rl[1].lodges[y].start=0;
    f[dacc].rl[0].lodges[y].delcnt=0;
    f[dacc].rl[1].lodges[y].delcnt=0;
    f[dacc].rl[0].lodges[y].delcntt=0.0;
    f[dacc].rl[1].lodges[y].delcntt=0.0;
    f[dacc].rl[0].lodges[y].delay=0;
    f[dacc].rl[1].lodges[y].delay=0;
    f[dacc].rl[0].lodges[y].flag=0;
    f[dacc].rl[1].lodges[y].flag=0;
    f[dacc].rl[0].lodges[y].added=0;
    f[dacc].rl[1].lodges[y].added=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].pl[1].lodges[y].realend=0;
    f[dacc].pl[0].lodges[y].end=MAXREC;
    f[dacc].pl[1].lodges[y].end=MAXREC;
    f[dacc].pl[0].lodges[y].linkage=0;
    f[dacc].pl[1].lodges[y].linkage=0;
    f[dacc].pl[0].lodges[y].start=0;
    f[dacc].pl[1].lodges[y].start=0;
    f[dacc].pl[0].lodges[y].delcnt=0.0;
    f[dacc].pl[1].lodges[y].delcnt=0.0;
    f[dacc].pl[0].lodges[y].delcntt=0.0;
    f[dacc].pl[1].lodges[y].delcntt=0.0;
    f[dacc].pl[0].lodges[y].delay=0;
    f[dacc].pl[1].lodges[y].delay=0;
  }
}

inline static void resets(uint32_t dacc){ // soft reset of both layers
  f[dacc].masterL[0]=0;
  f[dacc].masterL[1]=0;
  f[dacc].ttoggle=0;
  f[dacc].rec=1;
  f[dacc].state=NR; // NADA
  //  f[dacc].lastmode=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].pl[0].num_lodges=0;
  f[dacc].pl[1].num_lodges=0;
  f[dacc].rl[0].num_lodges=0;
  f[dacc].rl[1].num_lodges=0;
  
  for (uint32_t y=0;y<MAXLODGE;y++){   // zero all lodges TODO? is it necessary if we just set numlodges to 0?
    f[dacc].rl[0].lodges[y].function=nosilence;
    f[dacc].rl[1].lodges[y].function=nosilence;	
    f[dacc].rl[0].lodges[y].sil=0;
    f[dacc].rl[1].lodges[y].sil=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].rl[1].lodges[y].realend=0;
    f[dacc].rl[0].lodges[y].end=MAXREC;
    f[dacc].rl[1].lodges[y].end=MAXREC;
    f[dacc].rl[0].lodges[y].linkage=0;
    f[dacc].rl[1].lodges[y].linkage=0;
    f[dacc].rl[0].lodges[y].start=0;
    f[dacc].rl[1].lodges[y].start=0;
    f[dacc].rl[0].lodges[y].delcnt=0;
    f[dacc].rl[1].lodges[y].delcnt=0;
    f[dacc].rl[0].lodges[y].delcntt=0.0;
    f[dacc].rl[1].lodges[y].delcntt=0.0;
    f[dacc].rl[0].lodges[y].delay=0;
    f[dacc].rl[1].lodges[y].delay=0;
    f[dacc].rl[0].lodges[y].flag=0;
    f[dacc].rl[1].lodges[y].flag=0;
    f[dacc].rl[0].lodges[y].added=0;
    f[dacc].rl[1].lodges[y].added=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].pl[1].lodges[y].realend=0;
    f[dacc].pl[0].lodges[y].end=MAXREC;
    f[dacc].pl[1].lodges[y].end=MAXREC;
    f[dacc].pl[0].lodges[y].linkage=0;
    f[dacc].pl[1].lodges[y].linkage=0;
    f[dacc].pl[0].lodges[y].start=0;
    f[dacc].pl[1].lodges[y].start=0;
    f[dacc].pl[0].lodges[y].delcnt=0;
    f[dacc].pl[1].lodges[y].delcnt=0;
    f[dacc].pl[0].lodges[y].delay=0;
    f[dacc].pl[1].lodges[y].delay=0;
  }
}

inline static float mod0(float value, uint32_t length)
{
  while ((int)value > (length-1)){
        value -= length;
	//	printf("val %f length %d\n", value, length);
  }
    return value;
}

// offset is delay to start playing, start is point to start in recording, realend is end, length is length, loop is MAXREC - but can also set
// delcntt is the delay cnt
// delcnt is the index... // now unused
uint32_t playlodge(float speed1, uint32_t d, uint32_t lay, uint32_t* P_options){ 
  uint32_t x, y, tmpx, tmpxx, ff;
  uint32_t sample=0;

    for (x=0;x<f[d].pl[lay].num_lodges;x++){
    f[d].pl[lay].lodges[x].delcntt=mod0(f[d].pl[lay].lodges[x].delcntt+speed1, (f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].length+f[d].pl[lay].lodges[x].delay));
  }

    for (x=0;x<f[d].pl[lay].num_lodges;x++){
      if (f[d].pl[lay].lodges[x].delcntt>=f[d].pl[lay].lodges[x].offset && (f[d].pl[lay].lodges[x].delcntt<=(f[d].pl[lay].lodges[x].offset+f[d].pl[lay].lodges[x].length))) {
	tmpx=fmod(((f[d].pl[lay].lodges[x].delcntt-f[d].pl[lay].lodges[x].offset)+f[d].pl[lay].lodges[x].start),MAXREC); // but if we overlap ???
	
	if (tmpx>=MAXREC) tmpx=MAXREC-1; // safety

	if (lay==0) {
	  sample=overlayx(recordings[d][tmpx]&TOP, sample, (P_options[0]>>5)&3); // deal with overlap of zones in one layer DONE
	  f[d].pl[lay].lodges[x].currentval=recordings[d][tmpx]&TOP; // currentval
	}
	else {
	  sample=overlayx(recordings[d][tmpx]>>16, sample, (P_options[0]>>5)&3); // top layer
	  f[d].pl[lay].lodges[x].currentval=recordings[d][tmpx]>>16; // currentval
	}
      }
        }
    return sample;
}

static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};

void reclayerupper(uint32_t value, uint32_t place, uint32_t d){
  if (place>=MAXREC) place=MAXREC-1;
  recordings[d][place]=(recordings[d][place]&TOP)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t place, uint32_t d){
  if (place>=MAXREC) place=MAXREC-1;
  recordings[d][place]=(recordings[d][place]&TOPS)+(value);
}

// from playlodge:
// offset is delay to start playing, start is point to start in recording, realend is end, length is length, loop is end (normally MAXREC)
// delcntt is the delay cnt
// delcnt is the recording index...
uint32_t reclodge(uint32_t lay, layersr *rec, uint32_t d, uint32_t value, uint32_t* R_options, uint32_t masterL, uint32_t swoptype){ // pass in all and the p/layers
  uint32_t x, y, tmpx, tmpxx;
  for (x=0;x<rec[lay].num_lodges;x++){
    if (rec[lay].lodges[x].flag==0 && rec[lay].lodges[x].function(value)) {
      rec[lay].lodges[x].delcntt++;

      if (rec[lay].lodges[x].delcntt>=(rec[lay].lodges[x].offset+rec[lay].lodges[x].lengthr+rec[lay].lodges[x].delay)) rec[lay].lodges[x].delcntt=0;

      if (rec[lay].lodges[x].delcntt>=rec[lay].lodges[x].offset && (rec[lay].lodges[x].delcntt<=(rec[lay].lodges[x].offset+rec[lay].lodges[x].lengthr))){
	if (rec[lay].lodges[x].over==0){
	if ((rec[lay].lodges[x].delcnt+rec[lay].lodges[x].start)>=rec[lay].lodges[0].end) {
	  rec[lay].lodges[x].delcnt=0;
	  rec[lay].lodges[x].over=1; 
	}
	} // over==1
	else {
	if ((rec[lay].lodges[x].delcnt)>=rec[lay].lodges[0].end) {
	  rec[lay].lodges[x].delcnt=0;
	  rec[lay].lodges[x].over=1; 
	}
	}
	if (rec[lay].lodges[x].over==0)	tmpx=rec[lay].lodges[x].delcnt+rec[lay].lodges[x].start;
	else tmpx=rec[lay].lodges[x].delcnt;

	rec[lay].lodges[x].realend=tmpx;
	rec[lay].lodges[x].length++;
	rec[lay].lodges[x].delcnt++;
	
	if (swoptype==1){ 
	if (masterL==0){
	  if (lay==0){
	    tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	    reclayerlower(tmpxx, tmpx, d);
	  }
	  else {
	    tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options[0])&3); // fixed
	    reclayerupper(tmpxx, tmpx, d); 
	  }	    
	} // masterL
	else {
	  if (lay==1){
	    tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	    reclayerlower(tmpxx, tmpx, d);
	  }
	  else { // 0
	    tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options[0])&3); // fixed
	    reclayerupper(tmpxx, tmpx, d); 
	  }	    
	}
      } // swoptype
      else { // swop is zero so layer depends on lay
	  if (lay==0){
	    tmpxx=overlayx(value, (recordings[d][tmpx]&TOP), (R_options[0])&3);
	    reclayerlower(tmpxx, tmpx, d);
	  }
	  else {
	    tmpxx=overlayx(value, (recordings[d][tmpx]>>16), (R_options[0])&3); // fixed
	    reclayerupper(tmpxx, tmpx, d); 
	  }
      } // swoptype
      }
    }
  }
  return tmpxx;
}

inline static void copyin(uint32_t d, uint32_t l, uint32_t reset){
  uint32_t x;
  // copy in rec zones to play zones
  //  reset=1;
    f[d].pl[l].num_lodges=f[d].rl[l].num_lodges;
    for (x=0;x<f[d].rl[l].num_lodges;x++){
      //      f[d].pl[l].lodges[x].delcntt=f[d].rl[0].lodges[x].delcntt; 
      f[d].pl[l].lodges[x].offset=f[d].rl[l].lodges[x].offset;
      f[d].pl[l].lodges[x].delay=f[d].rl[l].lodges[x].delay;
      f[d].pl[l].lodges[x].start=f[d].rl[l].lodges[x].start;
      f[d].pl[l].lodges[x].realend=f[d].rl[l].lodges[x].realend;
      f[d].pl[l].lodges[x].length=f[d].rl[l].lodges[x].length;
      reset=1; // TESTY!
      if (reset){ // reset play to beginning
      f[d].pl[l].lodges[x].delcntt=0.0;
      f[d].pl[l].lodges[x].delcnt=0.0;
      }
      else if (f[d].rl[l].lodges[x].added) { // if we added zone beyond 0
	f[d].pl[l].lodges[x].delcnt=f[d].rl[l].lodges[x].delcnt;
	if (x!=0) f[d].pl[l].lodges[x].delcntt=f[d].pl[l].lodges[x-1].delcntt; // prev delcntt
	else f[d].pl[l].lodges[0].delcntt=0.0;
	f[d].rl[l].lodges[x].added=0;
      }
    }
}

////////////////////////////////////////////////////////////////////////////////

inline static void extendlodge(uint32_t d, uint32_t lay, uint32_t (*func)(uint32_t val)){
  uint32_t tt;
  if (f[d].rl[lay].num_lodges==0){
  f[d].rl[lay].num_lodges=1;
  f[d].rl[lay].lodges[0].function=func;
  f[d].rl[lay].lodges[0].flag=0; 
  f[d].rl[lay].lodges[0].start=0;
  f[d].rl[lay].lodges[0].length=0; // length=0, lengthr=MAXREC, end=MAXREC = extendible
  f[d].rl[lay].lodges[0].offset=0;
  f[d].rl[lay].lodges[0].delcnt=0;
  f[d].rl[lay].lodges[0].delcntt=0; 
  f[d].rl[lay].lodges[0].delay=0; 
  f[d].rl[lay].lodges[0].lengthr=MAXREC; // but could be longer???
  f[d].rl[lay].lodges[0].end=MAXREC;
  }
  else {
    tt=f[d].rl[lay].num_lodges-1;
    if (tt!=0) f[d].rl[lay].lodges[tt].delcnt=f[d].rl[lay].lodges[tt-1].realend; // previous end ?? TESTY!
    f[d].rl[lay].lodges[tt].lengthr=MAXREC; 
    f[d].rl[lay].lodges[tt].flag=0;
  }
}

inline static void addlodge(uint32_t d, uint32_t lay, uint32_t sil, uint32_t (*func)(uint32_t val)){
  uint32_t tmpx;
    f[d].rl[lay].num_lodges+=1;
    if (f[d].rl[lay].num_lodges>MAXLODGE) f[d].rl[lay].num_lodges=1;
    if (f[d].rl[lay].num_lodges==1){ // first lodge
      f[d].rl[lay].lodges[0].function=func;
      f[d].rl[lay].lodges[0].length=0;
      f[d].rl[lay].lodges[0].delcnt=0;
      f[d].rl[lay].lodges[0].delcntt=0.0;
      f[d].rl[lay].lodges[0].start=0;
      f[d].rl[lay].lodges[0].offset=0;
      f[d].rl[lay].lodges[0].sil=sil;
      f[d].rl[lay].rcnt=0;
      f[d].rl[lay].lodges[0].delay=0; // looping???
      f[d].rl[lay].lodges[0].lengthr=MAXREC; // but could be longer???
      f[d].rl[lay].lodges[0].end=MAXREC;
      f[d].rl[lay].lodges[0].flag=0;
      f[d].rl[lay].lodges[0].over=0; 
    } // first lodge
    else { // lodge>1
      tmpx=f[d].rl[lay].num_lodges-1;
      f[d].rl[lay].lodges[tmpx].over=0; 
      f[d].rl[lay].lodges[tmpx].added=1;
      f[d].rl[lay].lodges[tmpx].function=func;
      f[d].rl[lay].lodges[tmpx].length=0;
      f[d].rl[lay].lodges[tmpx].flag=0;
      f[d].rl[lay].lodges[tmpx].delcnt=0;
      f[d].rl[lay].lodges[tmpx].delcntt=f[d].rl[lay].lodges[tmpx-1].delcntt;
      f[d].rl[lay].lodges[tmpx].start=f[d].rl[lay].lodges[tmpx-1].realend+1; 
      f[d].rl[lay].lodges[tmpx].offset=(f[d].rl[lay].lodges[tmpx-1].realend)+1; // start right away
      f[d].rl[lay].lodges[tmpx].sil=sil;
      f[d].rl[lay].rcnt=0;
      f[d].rl[lay].lodges[tmpx].delay=0; // to come later
      f[d].rl[lay].lodges[tmpx].end=MAXREC; 
      f[d].rl[lay].lodges[tmpx].lengthr=MAXREC; // but could be longer???
      f[d].rl[lay].lodges[tmpx-1].flag=1; // stop the last one TODO: remember to reset
    }
}

////

// if there are no lodges we just have one, otherwise we extend the last lodge
uint32_t R_basic(uint32_t d, uint32_t V_options, uint32_t* R_options){
  uint32_t tmp, tmpp, swoptype;  
  //  LAYERSWOPR;

  if (f[d].entryr==0){ // includes reset now - only on entry set these
    // what to reset?    
    lastvalue[d]=0;
    f[d].entryr=1;
    f[d].leaverr=1;
    extendlodge(d,0, always);
    extendlodge(d,1, always);
  }
    tmp=real[d];
    tmpp=control[whichctrl[d]];
    SWOP;
    return tmp;
  }

/* eg. addlodgex
entry 
swop
addlodges: abstract that out for each layer as function
reclodges
*/

uint32_t Mnosilence(uint32_t d, uint32_t lay, uint32_t val){
  uint32_t tmpx;
  if (val>LOWVAL) { // start recording layer 0
    f[d].rl[0].ind=1;
    if (f[d].entryd[0]==0){
      addlodge(d,0,0,nosilence);
      f[d].entryd[0]=1;
    } // on entry we add lodge and also on each new silence...
  } // above val
  else { 
      // low value but did we leave recording
      if (f[d].rl[0].ind==1){ // we were recording so set end point of last one and add all delays
	tmpx=f[d].rl[0].num_lodges-1; // lodge we just left
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[0].lodges[x].delay+=f[d].rl[0].lodges[tmpx].length+1;
	}
	f[d].rl[0].ind=0; f[d].entryd[0]=0;
      }
  }  
}

uint32_t (*Mfunc[4])(uint32_t d, uint32_t lay, uint32_t val)={Mnosilence};

uint32_t NR_addlodgex(uint32_t d, uint32_t V_options, uint32_t* R_options){ // generic one and now manilodges is the function pointer
  uint32_t tmp, tmpp, other, tmpx, swoptype;
  // 1//ENTRY
  if (f[d].entryr==0){ 
    f[d].entryr=1;
    f[d].leaverr=1;
    f[d].entryd[0]=0;
    f[d].entryd[1]=0;
    f[d].rl[0].ind=0;
    f[d].rl[1].ind=0;
  }

  // 2//SWOPPAGE
  //  LAYERSWOPR;
  //  swoptype=(R_options[0]|R_options[1])&1;
  //  if (swoptype==0){  // swop values
  //    if (f[d].masterL[0]==0){
  tmp=real[d];
  tmpp=control[whichctrl[d]]; 
  //    }
  //    else {
  //  tmpp=real[d];
  //  tmp=control[whichctrl[d]]; 
  //    } // swop values only
  //  }

  // 3. manipulation of lodges:
  //call pointer for function depending on mode
  //  	  values[d]=(*NRfunc[f[d].majormode[NR]])(d, V_options, R_options); // TESTY!
  (*Mfunc[f[d].majormode[NR]])(d, 0, tmp);
  (*Mfunc[f[d].majormode[NR]])(d, 1, tmpp);

  // 4. RECLODGE
  reclodge(0, f[d].rl, d, tmp, R_options, f[d].masterL[0], swoptype); // so we just extend the last lodge // only rec on >LOWVAL but how to pull out
  reclodge(1, f[d].rl, d, tmpp, R_options, f[d].masterL[0], swoptype); // so we just extend the last lodge
  return tmp;
}

uint32_t R_addlodges(uint32_t d, uint32_t V_options, uint32_t* R_options){ // each succesive rec mode adds one zone
  uint32_t tmp, tmpp, other, tmpx, swoptype;
  uint32_t res[2];
  if (f[d].entryr==0){ // includes reset now
    f[d].entryr=1;
    f[d].leaverr=1;
    f[d].entryd[0]=0;
    f[d].entryd[1]=0;
    addlodge(d, 0, 0, always);
    addlodge(d, 1, 0, always);
    } // entry

  //  LAYERSWOPR;
  tmp=real[d];
  tmpp=control[whichctrl[d]]; 

  f[d].rl[0].ind=1;
  f[d].rl[1].ind=1; 
  SWOP;
  return tmp;
}

void R_addlodges_leave(uint32_t d){
  uint32_t tmpx;  // if we were recording then close it...
  if (f[d].rl[0].ind==1){ 
    tmpx=f[d].rl[0].num_lodges-1; // lodge we just left
    for (uint32_t x=0;x<tmpx;x++){ // previous lodges
      f[d].rl[0].lodges[x].delay+=(f[d].rl[0].lodges[tmpx].length);
    }
    f[d].rl[0].ind=0;
  }
  // layer2
    if (f[d].rl[1].ind==1){ 
    tmpx=f[d].rl[1].num_lodges-1; // lodge we just left
    for (uint32_t x=0;x<tmpx;x++){ // previous lodges
      f[d].rl[1].lodges[x].delay+=(f[d].rl[1].lodges[tmpx].length);
    }
    f[d].rl[1].ind=0;
  }

  f[d].leaverr=0;
}

uint32_t R_addlodges_silence(uint32_t d, uint32_t V_options, uint32_t* R_options){ // add zones on press and offset is silence
  uint32_t tmpp, other, tmpx, tmp, swoptype;
  uint32_t res[2];
  if (f[d].entryr==0){ // includes reset now
    // what to reset?    
    lastvalue[d]=0;
    f[d].entryr=1;
    f[d].leaverr=1;
    f[d].entryd[0]=0;
    f[d].entryd[1]=0;
    f[d].rl[0].ind=0;
    f[d].rl[1].ind=0;
    f[d].rl[0].rcnt=0;
    f[d].rl[1].rcnt=0;
  }
  
  //  LAYERSWOPR;
  swoptype=(R_options[0]|R_options[1])&1;
  //  if (swoptype==0){  
  //    if (f[d].masterL[0]==0){
      tmp=real[d];
      tmpp=control[whichctrl[d]]; 
      //    }
      //    else {
      //  tmpp=real[d];
      //  tmp=control[whichctrl[d]]; 
      //    } 
      //  }
  
  f[d].rl[0].rcnt++;
  if (tmp>LOWVAL) { // start recording
    f[d].rl[0].ind=1;
    if (f[d].entryd[0]==0){
    addlodge(d, 0, f[d].rl[0].rcnt, nosilence);
    f[d].entryd[0]=1;
    } // entry
  } // above val
  else { 
    if (f[d].rl[0].ind==1){ 
      tmpx=f[d].rl[0].num_lodges-1; // lodge we just left
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[0].lodges[x].delay+=f[d].rl[0].lodges[tmpx].length+1+f[d].rl[0].lodges[tmpx].sil;
	}
	if (tmpx!=0) f[d].rl[0].lodges[tmpx].offset=f[d].rl[0].lodges[tmpx-1].length+f[d].rl[0].lodges[tmpx].sil+f[d].rl[0].lodges[tmpx-1].offset; // add in previous offset???
	else f[d].rl[0].lodges[0].offset=f[d].rl[0].lodges[0].sil;
	  f[d].rl[0].ind=0;
	  f[d].entryd[0]=0;
	  f[d].rl[0].rcnt=0;
    } // ind
  } ////////////////////////lower
  // layer2
    f[d].rl[1].rcnt++;
  if (tmpp>LOWVAL) { // start recording
    f[d].rl[1].ind=1;
    if (f[d].entryd[1]==0){
    addlodge(d,1,f[d].rl[1].rcnt, nosilence);
    f[d].entryd[1]=1;
    } // entry
  } // above val
  else { 
    if (f[d].rl[1].ind==1){ 
      tmpx=f[d].rl[1].num_lodges-1; // lodge we just left
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[1].lodges[x].delay+=f[d].rl[1].lodges[tmpx].length+1+f[d].rl[0].lodges[tmpx].sil;
	}
	if (tmpx!=0) f[d].rl[1].lodges[tmpx].offset=f[d].rl[1].lodges[tmpx-1].length+f[d].rl[1].lodges[tmpx].sil+f[d].rl[1].lodges[tmpx-1].offset; // add in previous offset???
	else f[d].rl[1].lodges[0].offset=f[d].rl[1].lodges[0].sil;
	  f[d].rl[1].ind=0;
	  f[d].entryd[1]=0;
	  f[d].rl[1].rcnt=0;
    } // ind
  }
  reclodge(0, f[d].rl, d, tmp, R_options, f[d].masterL[0], swoptype); 
  reclodge(1, f[d].rl, d, tmp, R_options, f[d].masterL[0], swoptype);
  return real[d];
}

void R_addlodges_leave_silence(uint32_t d){ // no add of apres-silence
  uint32_t tmpx;  // if we were recording then close it...
      if (f[d].rl[0].ind==1){ 
      tmpx=f[d].rl[0].num_lodges-1; // lodge we just left
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[0].lodges[x].delay+=f[d].rl[0].lodges[tmpx].length+f[d].rl[0].lodges[tmpx].sil;
	}
	if (tmpx!=0) f[d].rl[0].lodges[tmpx].offset=(f[d].rl[0].lodges[tmpx-1].length)+f[d].rl[0].lodges[tmpx].sil+f[d].rl[0].lodges[tmpx-1].offset; // add in previous offset???
	  else f[d].rl[0].lodges[0].offset=f[d].rl[0].lodges[0].sil;
	  f[d].rl[0].ind=0;
	  f[d].rl[0].rcnt=0;
      }

      if (f[d].rl[1].ind==1){ 
      tmpx=f[d].rl[1].num_lodges-1; // lodge we just left
	for (uint32_t x=0;x<tmpx;x++){ // previous lodges
	  f[d].rl[1].lodges[x].delay+=(f[d].rl[1].lodges[tmpx].length+1)+f[d].rl[1].lodges[tmpx].sil;
	}
	if (tmpx!=0) f[d].rl[1].lodges[tmpx].offset=(f[d].rl[1].lodges[tmpx-1].length)+f[d].rl[1].lodges[tmpx].sil+f[d].rl[1].lodges[tmpx-1].offset; // add in previous offset???
	  else f[d].rl[1].lodges[0].offset=f[d].rl[1].lodges[0].sil;
	  f[d].rl[1].ind=0;
	  f[d].rl[1].rcnt=0;
      }
      f[d].leaverr=0;
}


void R_nothing_leave(uint32_t d){
  f[d].leaverr=0;
}

void P_nothing_leave(uint32_t d){
  f[d].leavep=0;
}

void RP_nothing_leave(uint32_t d){
  f[d].leaverp=0;
}



// basic RP mode: just write new values to existing lodges, playback existing lodges 
// we play playback plus real/overlay and record different options...
uint32_t RP_basic(uint32_t d, uint32_t V_options, uint32_t* P_options, uint32_t* R_options, uint32_t *RP_options){
  uint32_t pp, other, tmpp, tmp, tmpx, x, pbopt, res, ress, swoptype;
  pbopt=((RP_options[0]>>1)&1) | ((R_options[1]>>1)&1);
  if (f[d].entryrp==0){
    f[d].leaverp=1;
    f[d].entryrp=1;
    f[d].leaverp=1;
    tmpx=f[d].rl[0].num_lodges-1; // lodge we just left - close this one... // R is masterL[0], P is masterL[1]
    //    f[d].rl[0].lodges[tmpx].end=f[d].rl[0].lodges[tmpx].realend;
    tmpx=f[d].rl[1].num_lodges-1; // lodge we just left - close this one... // R is masterL[0], P is masterL[1]
    //    f[d].rl[1].lodges[tmpx].end=f[d].rl[1].lodges[tmpx].realend;
    copyin(d, 0, P_options[1]&1);
    copyin(d, 1, P_options[1]&1);
  } // entryrp
  // play
  //  LAYERSWOPRP; // swop both layers TODO: as option just to swop one = 3 bits

  swoptype=(R_options[0]|R_options[1])&1;
  if (swoptype==0){  // swop values
    if (f[d].masterL[0]==0){
  tmp=real[d];
  tmpp=control[whichctrl[d]]; // we use CTRL as speed
    }
    else {
  tmpp=real[d];
  tmp=control[whichctrl[d]]; // we use CTRL as speed
    } // swop values only
  }

  float speedy=playreff[f[d].playspeed[f[d].masterL[1]]][(control[whichctrl[d]]>>2)]; // speed from CTRL or from layer
  ress=playlodge(speedy, d, 0, P_options);
  playlodge(speedy, d, 1, P_options);
  // record overlay on zones on both layers - question of swops!

  res=reclodge(0, f[d].rl, d, tmp, R_options, f[d].masterL[0], swoptype);
  reclodge(1, f[d].rl, d, tmpp, R_options, f[d].masterL[0], swoptype); 

  if (pbopt==0){
    tmp=overlaylive(real[d], ress, (P_options[f[d].masterL[1]]>>3)&3);
  }
  else
    {
      tmp=res;//overlaylive(real[d], res, (P_options[f[d].masterL[1]]>>3)&3);
    }

  return tmp;
}
//uint32_t (*RPfunc[2])(uint32_t d, uint32_t V_options, uint32_t* R_options, uint32_t* RP_options)={P_basic};
uint32_t P_basic(uint32_t d, uint32_t V_options, uint32_t* R_options, uint32_t* RP_options){  // CTRL live is speed
  uint32_t pp, x, otherl;
  uint32_t res;
  if (f[d].entryrp==0){
    //    lastvalue[d]=0;
    f[d].entryrp=1;
    f[d].leavep=1;
    copyin(d, 0, (RP_options[1]&1));
    copyin(d, 1, (RP_options[1]&1));
  }
  //  LAYERSWOP;
  float speedy=playreff[f[d].playspeed[f[d].masterL[1]]][(control[whichctrl[d]]>>2)]; // speed from CTRL
  uint32_t tmp=real[d];
  res=playlodge(speedy, d, 0, RP_options); //TODO: swoppy
  playlodge(speedy, d, 1, RP_options); // we ignore that value???

  tmp=overlaylive(tmp, res, (RP_options[f[d].masterL[1]]>>3)&3); // overlay of live value! - 
  return tmp;
}

uint32_t N_basic(uint32_t d, uint32_t V_options){
  uint32_t tmp=real[d];
  DOFREEZE;
  return tmp;
}

//uint32_t (*Nfunc[2])(uint32_t d, uint32_t V_options)={N_basic};
uint32_t (*NRfunc[4])(uint32_t d, uint32_t V_options, uint32_t* R_options)={R_basic, R_addlodges, R_addlodges_silence};
uint32_t (*RPfunc[2])(uint32_t d, uint32_t V_options, uint32_t* R_options, uint32_t* RP_options)={P_basic};

void (*NRfunc_leave[4])(uint32_t d)={R_nothing_leave, R_addlodges_leave, R_addlodges_leave, R_addlodges_leave_silence};
void (*RPfunc_leave[2])(uint32_t d)={RP_nothing_leave};


// STARTY
void TIM2_IRQHandler(void) 
  {
    uint32_t speed=0;
    float spd=0.0; // for new accel tests
    static uint32_t d=0;
    uint32_t j,x,y, tmp, tmpp, tmpy, autre;
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    static uint32_t modetoggle=0, newmode=0, count=0;
    static uint32_t lasttriggered[11]={0,0,0,0, 0,0,0,0, 0,0,0}, mbreaker=0, breaker[11]={0,0,0,0, 0,0,0,0, 0,0,0};
    static int32_t togrec=0, togplay=0, helder=0, heldon=0, modeheld=0, modechanged=1, first=0;
    static uint32_t Theld[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelder[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Newtog[8]={0,0,0,0, 0,0,0,0};      
    uint32_t V_options, R_options[2], P_options[2], RP_options[2];
    const uint32_t SENSESHIFTS[3]={0,1,2}; // just use first 2 for now
    const uint32_t SENSEOFFSETS[3]={120,560,1800}; // TODO - adjust maybe for RP
    //    const uint32_t remode[4]={0,1,2,2}; // 2 arrays N, R and P/RP
	      
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	// micromodes outside mode switches - these will change with new scheme
	/*
	V_options=f[d].minormode[0][0]&1; // V: sens, sync/global-overlay= 3 bits - top [6] syncs to [4] to test
	R_options[0]=f[d].minormode[0][1]&3; // was??6 bits  2bits overlay ctrl + 2 bits x2 for 2nd tape overlay options
	R_options[1]=f[d].minormode[1][1]&3; // 
	
	P_options[0]=f[d].minormode[0][2]&127; // P,RP: 11 speedarray, 11 live overlay + now zone overlay // 6 bits + reset option=7 bits
	P_options[1]=f[d].minormode[1][2]&127; // 
	
	RP_options[0]=(f[d].minormode[0][3]&31); // RP: type of swop, type of playback, overlay of live onto rec layer
	RP_options[1]=(f[d].minormode[1][3]&31); 
	
	f[d].sensi=V_options&1; // first bit - sensitivity is in macros
	f[d].playspeed[0]=(P_options[0]>>1)&3; // speedarray = 2 bits
	f[d].playspeed[1]=(P_options[1]>>1)&3; // speedarray = 2 bits
	*/
	// functions outside switch
	FREEZERS;
	REALADC;
	CTRL;

	/* // new scheme
	  toggle only: swop/reset that section
	  toggle+modifier: state(N/RP), mode, micromode [mode/micromode->advance]
	  toggle+CTRL: params on zones -> P or R zones
	  CTRL+modifier: ???  CTRL is local to 2 sections - can also be micromode/mode advance or params on zones...
	*/
	
	// toggle only: swop/reset that section // swop we have in macros but doesn't exclude mods
		if (Newtog[d]){ // newtog means there has been a release
		  Newtog[d]=0;
		  if (Theld[d]>LONGTOG) { 
		    Theld[d]=0;
		    // reset this one
		    resets(d);
		  }
		  f[d].ttoggle=0; // this is more for logic below...
		}

	if (f[d].ttoggle){
	  if (togrec) {
	    Thelder[d]=0; // reset the reset toggle for the above: to test
	    f[d].rec^=1; // is now just state	    
	  }
	}

	// logic is: we are in NR or RP only
	if (f[d].rec) f[d].state=NR;
	else if (f[d].rl[f[d].masterL[0]].num_lodges>0) f[d].state=RP; // and only if we have a lodge!
	else f[d].state=NR;
	
	////// TESTY - SET MODES for testing!
	f[d].majormode[NR]=2;
	f[d].majormode[RP]=0;
	///////////////////////////////////////////////////////
	
	// NR: TODO: geomantic mode thing - could be only for all modes which are active
	if (f[d].state==NR){ 
	  //RESETFRR; // ????
	  values[d]=NR_addlodgex(d, V_options, R_options); //uint32_t NR_addlodgex(uint32_t d, uint32_t V_options, uint32_t* R_options){ // generic one and now manilodges is the function pointer
	} // end NADA
	else {
	  if (f[d].leaverr){ 
	    (*NRfunc_leave[f[d].majormode[NR]])(d);
	  }
	    f[d].entryr=0;
	}
	// REC+PLAY: ADC->speed/bounce/rec to other // freeze is swop // what does voltage do (overlay same tape minormodes here)
	if (f[d].state==RP){ 
	  //	  RESETFRRP;  /// ????
	  values[d]=(*RPfunc[f[d].majormode[RP]])(d, V_options, R_options, RP_options);
	} //end RP
	else {
	  if (f[d].leaverp){ 
	    (*RPfunc_leave[f[d].majormode[RP]])(d);
	  }
	  f[d].entryrp=0;
    }
	
	///////////////////////////////////////////////////////	

	WRITEDAC2;
	d++;
	if (d==8) {
	  d=0;
	  count++;
	  togplay=0; togrec=0; // here as then we set them for one round
	  TEST_TOGGLES;      // only place where toggles
	  /*
	    toggle only: swop/reset that section
	    toggle+modifier: state(N/RP), mode, micromode [mode/micromode->advance] // and what of full reset of that one
	    toggle+CTRL: params on zones -> P or R zones
	    CTRL+modifier: ???  CTRL is local to 2 sections - can also be micromode/mode advance or params on zones...
	  */
	  
	  if (newmode){ // newmode is the release of mode
	    newmode=0;
	    breaker[10]=0;

	    if (modeheld>FULLRESET) { //reset all // keep this - only if there is no toggle
	      modeheld=0;
	      resett(0);
	      resett(1);
	      resett(2);
	      resett(3);
	      resett(4);
	      resett(5);
	      resett(6);
	      resett(7);
	    }
	}
    }
    }
  }
