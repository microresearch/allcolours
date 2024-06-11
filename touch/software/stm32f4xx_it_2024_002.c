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
#include <sys/stat.h>
#include <sys/times.h>
#include "misc.h"
#include "resources.h"
#include "macros000.h"

#define TOPS 0b11111111111111110000000000000000
#define BOTS 0b00000000000000001111111111111111

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

#ifdef fouronethree
#define MAXREC 9000 // was 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#else
#define MAXREC 3800 // for older STM
#endif
// with F413 we have 9200 which is how long - around 20 seconds now on 24 divider

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


inline static uint32_t overlay(uint32_t value, uint32_t value2, uint32_t over){ // 4 bits - value is real, value2 is added // overlay on playback
  uint32_t tmpp;
  int32_t subs; float nn;
 	    if (over==0){ //usual - now swopped for >
	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==1){ 
	      tmpp=value2+value;
	      if (tmpp>BOTS) tmpp=BOTS; // as we store full value...
	    }
	    else if (over==2){ // mod
	      tmpp=value2+value;
	      tmpp=tmpp%4096;
	    }
	    else if (over==3){ // subtract live and do abs...
	      subs=value2-value;
	      tmpp=abs(subs);
	    }
	    else if (over==4){	    //add VCA/float thing /// but need more bits and more options
	    nn=value/4095.0;
	    nn*=(float)value2;
	    tmpp=(uint32_t)nn;
	    }
	    else if (over==5){	    //add VCA/float thing /// but need more bits and more options
	      value=4095-value;
	      nn=value/4095.0;
	      nn*=(float)value2;
	      tmpp=(uint32_t)nn;
	    }
	    return tmpp;
}

inline static uint32_t overlayx(uint32_t value, uint32_t value2, uint32_t over){ // 4 bits - value is new value // for reclodge
  uint32_t tmpp, subs;
 	    if (over==0){
	      tmpp=value;
	    }
	    else if (over==1){
   	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==2){ 
	      tmpp=value2+value;
	      if (tmpp>BOTS) tmpp=BOTS;
	    }
	    else if (over==3){ // mod
	      tmpp=value2+value;
	      tmpp=tmpp%4096;
	    }
	    return tmpp;
}

inline static uint32_t livevalue(uint32_t which, uint32_t opt){ // ???? or keep inversion...
  uint32_t tmpp, subs, overoverlay;
  // options for live value - eg. add global from top (and type of overlays), (sensitivity is already in macros)
  if (which!=6) tmpp=real[6]; // top voltage - value at the end
  // 6 syncs to 4 lowest
  else tmpp=real[4];
  
  overoverlay=(opt>>1)&3;
  if (overoverlay==0) tmpp=real[which];
  else if (overoverlay==2){ //usual - now swopped for >
    if (real[which]>tmpp) tmpp=real[which]; // only if is more than
  }
  else if (overoverlay==3){ 
    tmpp+=real[which];
    if (tmpp>4095) tmpp=4095; // ??
  }
  else if (overoverlay==1){ // invert 
    tmpp=4095-real[which];
    }
  return tmpp;
}

inline static void resetx(uint32_t which){
  for (uint32_t y=0;y<MAXREC;y++){ 
    recordings[which][y]=0;
  }
}

inline static void changemode(uint32_t dacc){
  f[dacc].majormode[f[dacc].state]++;
  if (f[dacc].majormode[f[dacc].state]>MAXMODE[f[dacc].state]) f[dacc].majormode[f[dacc].state]=0;
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].state=N; // NADA  
  // TODO: what else we need to reset here
}

void resett(uint32_t dacc){
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].state=N;
  f[dacc].active=1;
  f[dacc].masterLR=0;
  f[dacc].masterLP=0;
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
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].rl[0].num_lodges=0;
  f[dacc].rl[1].num_lodges=0;
  f[dacc].lastmode=0;
  f[dacc].sensi=0;
  f[dacc].entryp=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
  //  f[dacc].playlistm=0;
  //  f[dacc].playlistp=0;
  for (uint32_t x=0;x<8;x++){ 
    //  f[dacc].l[0].cnt[x]=0;
    //  f[dacc].l[1].cnt[x]=0;
  //  f[dacc].l[0].play_cnt[x]=0;
  //  f[dacc].l[1].play_cnt[x]=0;
  }
  // zero all lodges
  for (uint32_t y=0;y<MAXLODGE;y++){ 
    f[dacc].rl[0].lodges[y].over=0;
    f[dacc].rl[1].lodges[y].over=0;
    f[dacc].rl[0].lodges[y].cnt=0;
    f[dacc].rl[1].lodges[y].cnt=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].rl[1].lodges[y].realend=0;
    f[dacc].rl[0].lodges[y].end=0;
    f[dacc].rl[1].lodges[y].end=0;
    f[dacc].rl[0].lodges[y].linkage=0;
    f[dacc].rl[1].lodges[y].linkage=0;
    f[dacc].rl[0].lodges[y].start=0;
    f[dacc].rl[1].lodges[y].start=0;
    f[dacc].rl[0].lodges[y].delcnt=0;
    f[dacc].rl[1].lodges[y].delcnt=0;
    f[dacc].rl[0].lodges[y].delay=0;
    f[dacc].rl[1].lodges[y].delay=0;

    f[dacc].pl[0].lodges[y].over=0;
    f[dacc].pl[1].lodges[y].over=0;
    f[dacc].pl[0].lodges[y].cnt=0;
    f[dacc].pl[1].lodges[y].cnt=0;
    f[dacc].rl[0].lodges[y].realend=0;
    f[dacc].pl[1].lodges[y].realend=0;
    f[dacc].pl[0].lodges[y].end=0;
    f[dacc].pl[1].lodges[y].end=0;
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

inline static void resets(uint32_t dacc){ // soft reset of both layers
  f[dacc].masterLP=0;
  f[dacc].masterLR=0;
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].state=N; // NADA
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].lastmode=0;
  f[dacc].entryp=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
  for (uint32_t x=0;x<8;x++){ 
    //  f[dacc].l[0].cnt[x]=0;
    //  f[dacc].l[1].cnt[x]=0;
  //  f[dacc].l[0].play_cnt[x]=0;
  //  f[dacc].l[1].play_cnt[x]=0;
  }
  // zero all lodges TODO: etc
}

inline static float mod0(float value, float start, float ending, float length, uint32_t d, uint32_t which, uint32_t layer, uint32_t full) 
{
  static uint32_t lengthed;
  lengthed=0;
  while (value > (ending-1)){ // wrapping
    value -= ending;
  }
  return value;
}

// now for zones and we use realend as the end always...
// TODO: add fractional increment... will need floats
uint32_t playlodge(layers *play, layers *tousel, float speedy, uint32_t d, uint32_t P_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  uint32_t sample;
  // tape 0 lower
  for (x=0;x<tousel[f[d].masterLP].num_lodges;x++){
    play[f[d].masterLP].lodges[x].delcnt++;
    if (play[f[d].masterLP].lodges[x].delcnt>=tousel[f[d].masterLP].lodges[x].offset && (play[f[d].masterLP].lodges[x].delcnt<=(tousel[f[d].masterLP].lodges[x].offset+tousel[f[d].masterLP].lodges[x].realend-tousel[f[d].masterLP].lodges[x].start))) {     
      tmpx=play[f[d].masterLP].lodges[x].cnt+tousel[f[d].masterLP].lodges[x].start;

      if (tmpx>tousel[f[d].masterLP].lodges[x].realend) { // now we want final delay before we start again
	tmpx=tousel[f[d].masterLP].lodges[x].start;
	play[f[d].masterLP].lodges[x].cnt=0;
    }
      if (tmpx>MAXREC) tmpx=MAXREC-1;
      sample=recordings[d][tmpx]&BOTS;
      play[f[d].masterLP].lodges[x].cnt++;
    }
    if (play[f[d].masterLP].lodges[x].delcnt>=(tousel[f[d].masterLP].lodges[x].offset+tousel[f[d].masterLP].lodges[x].realend+tousel[f[d].masterLP].lodges[x].delay-tousel[f[d].masterLP].lodges[x].start)) play[f[d].masterLP].lodges[x].delcnt=0;
  }
  return sample;  
}


static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};

void reclayerupper(uint32_t value, uint32_t place, uint32_t d){
  if (place>=MAXREC) place=MAXREC-1;
  recordings[d][place]=(recordings[d][place]&BOTS)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t place, uint32_t d){
  if (place>=MAXREC) place=MAXREC-1;
  recordings[d][place]=(recordings[d][place]&TOPS)+(value);
}

//TODO: linkage and attachment, does each lodge/zone have a function attached?
void reclodge(layers *rec, uint32_t d, uint32_t value, uint32_t layerval, uint32_t R_options){ // pass in the p/layers
  uint32_t x, y, tmpx, tmpxx, lay;
  // tape 0 lower
  for (x=0;x<rec[f[d].masterLR].num_lodges;x++){
    rec[f[d].masterLR].lodges[x].delcnt++;
    if (rec[f[d].masterLR].lodges[x].delcnt>=rec[f[d].masterLR].lodges[x].offset && (rec[f[d].masterLR].lodges[x].delcnt<=(rec[f[d].masterLR].lodges[x].offset+rec[f[d].masterLR].lodges[x].end-rec[f[d].masterLR].lodges[x].start))) {     
      tmpx=rec[f[d].masterLR].lodges[x].cnt+rec[f[d].masterLR].lodges[x].start;
      if (rec[f[d].masterLR].lodges[x].over==0) rec[f[d].masterLR].lodges[x].realend=tmpx; 
      if (tmpx>rec[f[d].masterLR].lodges[x].end) { // now we want final delay before we start again
	rec[f[d].masterLR].lodges[x].realend=rec[f[d].masterLR].lodges[x].end;
	tmpx=rec[f[d].masterLR].lodges[x].start;
	rec[f[d].masterLR].lodges[x].cnt=0;
	rec[f[d].masterLR].lodges[x].over=1;
    }
      tmpxx=overlayx(value, (recordings[d][tmpx]&BOTS), (R_options>>2)&3); 
      reclayerlower(tmpxx, tmpx, d);
      rec[f[d].masterLR].lodges[x].cnt++;
    }
    if (rec[f[d].masterLR].lodges[x].delcnt>=(rec[f[d].masterLR].lodges[x].offset+rec[f[d].masterLR].lodges[x].end+rec[f[d].masterLR].lodges[x].delay-rec[f[d].masterLR].lodges[x].start)) rec[f[d].masterLR].lodges[x].delcnt=0;
  }
  lay=f[d].masterLR^1; // opposite layer...
  for (x=0;x<f[d].rl[lay].num_lodges;x++){
    rec[lay].lodges[x].delcnt++;
    if (rec[lay].lodges[x].delcnt>=rec[lay].lodges[x].offset && (rec[lay].lodges[x].delcnt<=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end-rec[lay].lodges[x].start))) {     
      tmpx=rec[lay].lodges[x].cnt+rec[lay].lodges[x].start;
      if (rec[lay].lodges[x].over==0) rec[lay].lodges[x].realend=tmpx; // fixed
      if (tmpx>rec[lay].lodges[x].end) { // now we want final delay before we start again
	rec[lay].lodges[x].realend=rec[lay].lodges[x].end;
	tmpx=rec[lay].lodges[x].start;
	rec[lay].lodges[x].cnt=0;
	rec[lay].lodges[x].over=1;
    }
      tmpxx=overlayx(layerval, (recordings[d][tmpx]&BOTS), (R_options>>2)&3); 
      reclayerlower(tmpxx, tmpx, d);
      rec[lay].lodges[x].cnt++;
    }
    if (rec[lay].lodges[x].delcnt>=(rec[lay].lodges[x].offset+rec[lay].lodges[x].end+rec[lay].lodges[x].delay-rec[lay].lodges[x].start)) rec[lay].lodges[x].delcnt=0;
  }
}
  
// genericise? 
uint32_t R_basic(uint32_t d, uint32_t V_options, uint32_t R_options){
  uint32_t tmp, tmpp, other;  
  if (f[d].entryr==0){ // includes reset now
    // what to reset?    
    lastvalue[d]=0;
    f[d].entryr=1;
  }

 f[d].rl[f[d].masterLR].num_lodges=1;
  f[d].rl[f[d].masterLR].lodges[0].start=0;
  f[d].rl[f[d].masterLR].lodges[0].offset=0;
  f[d].rl[f[d].masterLR].lodges[0].delay=0; // looping???
  f[d].rl[f[d].masterLR].lodges[0].end=MAXREC; 
  tmp=livevalue(d, V_options);
  other=f[d].masterLR^1;
  f[d].rl[other].num_lodges=1;
  f[d].rl[other].lodges[0].start=0;
  f[d].rl[other].lodges[0].offset=0;
  f[d].rl[other].lodges[0].delay=0; 
  f[d].rl[other].lodges[0].end=MAXREC; 
  tmpp=overlay(control[whichctrl[d]], tmp, R_options&3); // overlay of CTRL - could be just CTRL signal
  //  tmpp=control[whichctrl[d]]
  reclodge(f[d].rl, d, tmp, tmpp, R_options);
  return tmpp;
}

// TO REDO!
uint32_t RP_basic(uint32_t d, uint32_t V_options, uint32_t P_options, uint32_t R_options, uint32_t RP_options){
  uint32_t pp, other, tmpp, tmp;
  // REC+PLAY: ADC->speed/bounce/rec to other // freeze is swop // what
// does voltage do (overlay same tape minormodes here) - see options for
// end of other layer...// and for stoppingx
  if (f[d].entryrp==0){
      f[d].entryrp=1;
    }
  // handle play
  float speedy=playreff[f[d].playspeed][(control[whichctrl[d]]>>2)]; 
  tmp=livevalue(d, V_options);
  //  pp=speedsampleplay(speedy, d, 0, d, recordings[d]); // last two d can be access to others...
  tmp=overlay(tmp, pp, (P_options>>2)&3); // live overlay on playback 
  other=f[d].masterLP^1; // swoppage

  f[d].rl[other].num_lodges=1;
  f[d].rl[f[d].masterLP].num_lodges=1;
  if (f[d].rl[other].lodges[0].realend && (RP_options&2)) f[d].rl[other].lodges[0].end=f[d].rl[other].lodges[0].realend;
  else f[d].rl[other].lodges[0].end=MAXREC; // option of rec_end

  if (RP_options&1){ // option to stop rec on not playing...
    //  reclodgex(d, tmp, other, R_options);
  }
  //  else 	if (speedy!=0.0f) reclodgex(d, tmp, other, R_options); // default is to stop
  return tmp;  
}
  
// deal with empty playlist at beginning and any reset
uint32_t P_basic(uint32_t d, uint32_t V_options, uint32_t P_options){ // swop is not handled
  uint32_t pp;
  if (f[d].entryp==0){
    lastvalue[d]=0;
    f[d].entryp=1;
    f[d].leavep=1;
  }
  
  float speedy=playreff[f[d].playspeed][(control[whichctrl[d]]>>2)]; 
  uint32_t tmp=livevalue(d, V_options);
  //pp=speedsampleplaynoI(speedy, d, 0, d, recordings[d]);
  pp=playlodge(f[d].pl, f[d].rl, 1.0f, d, 0);
  //  tmp=overlay(tmp, pp, (P_options>>2)&3);
  tmp=overlay(tmp, pp, 5); // TESTY
  
  return tmp;
}

uint32_t N_basic(uint32_t d, uint32_t V_options){
  uint32_t tmp=livevalue(d, V_options);
  DOFREEZE;
  return tmp;
}

uint32_t N_alwaysrec(uint32_t d, uint32_t V_options){
  uint32_t tmp=livevalue(d, V_options);
  DOFREEZE;
  //  uint32_t autre=f[d].masterL; // old way!
  //  RECLAYER; // autre is our layer for the macro, tmp is value there
  //  autre=f[d].masterL^1;
  //  RECLAYER;
  return tmp;
}

uint32_t (*Nfunc[2])(uint32_t d, uint32_t V_options)={N_basic, N_alwaysrec};
uint32_t (*Rfunc[2])(uint32_t d, uint32_t V_options, uint32_t R_options)={R_basic};
uint32_t (*RPfunc[2])(uint32_t d, uint32_t V_options, uint32_t P_options, uint32_t R_options, uint32_t RP_options)={RP_basic};
uint32_t (*Pfunc[2])(uint32_t d, uint32_t V_options, uint32_t P_options)={P_basic};

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
    static uint32_t Theldon[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Theld[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelder[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Newtog[8]={0,0,0,0, 0,0,0,0};      
    uint32_t V_options, R_options, P_options, RP_options;
    const uint32_t SENSESHIFTS[3]={0,1,2}; // just use first 2 for now
    const uint32_t SENSEOFFSETS[3]={82,560,1800}; // TODO - adjust maybe
    //    const uint32_t remode[4]={0,1,2,2}; // 2 arrays N, R and P/RP
	      
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	// micromode logic outside mode switches - but what if these depend on mode!?
	V_options=f[d].minormode[0]&7; // V: sens, sync/global-overlay= 3 bits - top [6] syncs to [4] to test
	R_options=f[d].minormode[1]&63; // 6 bits  2bits overlay ctrl + 2 bits x2 for 2nd tape overlay options
	P_options=f[d].minormode[2]&15; // P,RP: 11 speedarray, 11 live overlay // 4 bits
	RP_options=(f[d].minormode[3]&3); // RP: 1bit recend + recstop option = 2 bits now

	//	RP_options=3<<6; 
	
	f[d].sensi=V_options&1; // first bit - sensitivity is in macros
	f[d].playspeed=P_options&3; // speedarray = 2 bits
	// functions outside switch
	FREEZERS;
	REALADC;
	CTRL;

	// is the finger active = long freeze
	   if (Newtog[d]){
	     Newtog[d]=0;
	     if (Theld[d]>LONGTOG) {
	       Theld[d]=0;
	       f[d].active^=1; // t0ggle
	       f[d].ttoggle=0;
	     }
	   }
	   
	// togplay and togrec	   
	if (f[d].active){
	  if (togplay) f[d].play^=1;
	  if (togrec) f[d].rec^=1;

	  if (f[d].lastmode==1 && f[d].play==0) { // if we leave overlaid via. exit from play
	    f[d].state=N;
	    f[d].rec=0; // added
	}
	else {
	// logic of states now
	  if (f[d].rec && f[d].play){
	    if (f[d].rl[f[d].masterLR].num_lodges>0){ // if we have a zone recorded
	    f[d].state=RP;
	  }
	    else {
	      f[d].state=R; // nothing to play
	    }
	  }
	  else if (f[d].rec)	f[d].state=R;
	  else if (f[d].play && (f[d].rl[f[d].masterLR].num_lodges>0)) f[d].state=P;
	  else f[d].state=N;
	}
	f[d].lastmode=0;
	} // end of active
	
	  // do main mode/state work with switches within this
	////// TESTY

	f[d].majormode[N]=0;
	f[d].majormode[P]=0;
	f[d].majormode[R]=0;
	f[d].majormode[RP]=0;
	///////////////////////////////////////////////////////	
	// NADA: TODO: geomantic mode thing - could be only for all modes which are active
	if (f[d].state==N){ 
	  RESETFRN;
	  values[d]=(*Nfunc[f[d].majormode[N]])(d, V_options);
	} // end NADA
	else f[d].entryn=0;

	// PLAY: 
	if (f[d].state==P){
	  LAYERSWOP; 
	  values[d]=(*Pfunc[f[d].majormode[P]])(d, V_options, P_options);
	} // end PLAY
	else {
	  if (f[d].leavep && f[d].majormode[P]==0){ // we left P so add to our playlist - TODO: if any other majormodes add to playlist we need to add these in 
	    f[d].leavep=0;
	  }
	  f[d].entryp=0;
	}

	// REC: 
	if (f[d].state==R){
	  LAYERSWOPR;
	  values[d]=(*Rfunc[f[d].majormode[R]])(d, V_options, R_options);
	} // end REC
	else f[d].entryr=0;

	// REC+PLAY: ADC->speed/bounce/rec to other // freeze is swop // what does voltage do (overlay same tape minormodes here)
	if (f[d].state==RP){ 
	  //	  RESETFRRP;  /// ????
	  f[d].lastmode=1; // in this case!
	  values[d]=(*RPfunc[f[d].majormode[RP]])(d, V_options, P_options, R_options, RP_options);
	} //end RP
	else f[d].entryrp=0;
	///////////////////////////////////////////////////////	
	// end of modes 
	
	WRITEDAC2;
	d++;
	if (d==8) {
	  d=0;
	  count++;
	  togplay=0; togrec=0; // here as then we set them for one round
	  TEST_TOGGLES;      // only place where toggles
	  // handle micromodes, resett, and  
	  // how - depends on active positions // states we deal with later - go up to 10 bits

	  if (newmode){
	    newmode=0;
	    breaker[10]=0;

	    if (modeheld>FULLRESET) { //reset all
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
	    else if (modeheld>SOFTRESET && modeheld<FULLRESET){
	      if (f[0].active) resets(0);
	      if (f[1].active) resets(1);
	      if (f[2].active) resets(2);
	      if (f[3].active) resets(3);
	      if (f[4].active) resets(4);
	      if (f[5].active) resets(5);
	      if (f[6].active) resets(6);
	      if (f[7].active) resets(7);
	    }
	else if (modeheld>LONGMODE && modeheld<SOFTRESET) { // increment major mode if active
	  modeheld=0;
	  if (f[0].active) changemode(0);
	  if (f[1].active) changemode(1);
	  if (f[2].active) changemode(2);
	  if (f[3].active) changemode(3);
	  if (f[4].active) changemode(4);
	  if (f[5].active) changemode(5);
	  if (f[6].active) changemode(6);
	  if (f[7].active) changemode(7);
	  
	}	
	else if (modeheld<LONGMODE){ //inc minor mode 
	  modeheld=0; 
	  if (f[0].active) {
	    f[0].minormode[f[0].state]++;
	  }
	  if (f[1].active) {
	    f[1].minormode[f[1].state]++;
	  }
	  if (f[2].active) {
	    f[2].minormode[f[2].state]++;
	  }
	  if (f[3].active) {
	    f[3].minormode[f[3].state]++;
	  }
	  if (f[4].active) {
	    f[4].minormode[f[4].state]++;
	  }
	  if (f[5].active) {
	    f[5].minormode[f[5].state]++;
	  }
	  if (f[6].active) {
	    f[6].minormode[f[6].state]++;
	  }
	  if (f[7].active) {
	    f[7].minormode[f[7].state]++;
	  }
	}
	} // newmode
	}
    }
  }

