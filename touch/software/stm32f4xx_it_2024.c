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
#include "macros.h"

#define TOPS 0b11111111111111110000000000000000

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
#define PLAYFULLY 119 // length of playlist in fingers.h

#ifdef fouronethree
#define MAXREC 9200 // was 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#else
#define MAXREC 3800 // for older STM
#endif
// with F413 we have 9200 which is how long - around 20 seconds now on 24 divider

#define MAXMODES 8

GPIO_InitTypeDef GPIO_InitStructure;
extern __IO uint32_t adc_buffer[8];

static uint32_t recordings[8][MAXREC+1]={0}; // 
static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
static int32_t control[4];
static uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10 NOW STATIC!
const uint32_t whichctrl[8]={0,1,2,3,0,1,2,3}; // ref for newADC speeds

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

inline static float mod0(float value, float length) // basic one
{
  while (value > (length-1))
        value -= length;
    return value;
}

inline static float mod0N(float value, float start, float ending, float length, uint32_t dacc) // new one with start and ending/loop point
{
  // in what case would we add to playlist - when we go over length?  // and now playlist needs end and length
  while (value > (ending-1)){
    value -= ending;
  }
    while (f[dacc].l[f[dacc].masterL].cnt>length){
    f[dacc].l[f[dacc].masterL].cnt-=length;
    value=start+f[dacc].l[f[dacc].masterL].cnt;
    f[dacc].l[f[dacc].masterL].cnt=0;
    // add to playlist: start, ending, length
    }
  return value;
}

inline static float mod0NN(float value, float start, float ending, float length, uint32_t dacc) // new one with start and ending/loop point
{ 
  uint32_t tmpp;
  while (value > (ending-1)){
    value -= ending;
    }
  tmpp=f[dacc].l[f[dacc].masterL].cnt;
  if ((f[dacc].l[f[dacc].masterL].cnt+1)>length){
    tmpp-=length;
    value=start+tmpp;
    }
  return value;
}


inline static float mod0XX(float value, float length, uint32_t d)
{
  while (value > (length-1)){
        value -= length;
    // get next in list
  f[d].playcnt+=1; 
  if (f[d].playcnt>=f[d].playfull) f[d].playcnt=0;
  length=f[d].playlist[f[d].playcnt].length;
  }
    return value;
}

inline static float mod00(float value, float length, uint32_t d)
{
  uint32_t tmp=f[d].playcnt;
  while (value > (length-1)) {
        value -= length;
	tmp+=1;
	if (tmp>f[d].playfull) tmp=0;
	length=f[d].playlist[tmp].length;
  }
  return value;
}

inline static float mod0X(float value, float length, uint32_t d) // adds to playlist 
{
  while (value > (length-1)){
    value -= length;
    ADDPLAYLISTRST;
    f[d].l[f[d].masterL].othercnt=0;
  }
  return value;
}


inline static uint32_t overlay(uint32_t value, uint32_t value2, uint32_t over){ // 4 bits - value is real, value2 is added
  uint32_t tmpp;
  int32_t subs;
  //  over=2; // TESTY
 	    if (over==0){ //usual - now swopped for >
	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==1){ 
	      tmpp=value2+value;
	      if (tmpp>4095) tmpp=4095;
	    }
	    else if (over==2){ // mod
	      tmpp=value2+value;
	      tmpp=tmpp%4096;
	    }
	    else if (over==3){ // subtract live and do abs...
	      subs=value2-value;
	      tmpp=abs(subs);
	    }
	    return tmpp;
}

inline static uint32_t overlayx(uint32_t value, uint32_t value2, uint32_t over){ // 4 bits - value is new value
  uint32_t tmpp, subs;
  //    over=2; // TESTY
 	    if (over==0){
	      tmpp=value;
	    }
	    else if (over==1){
   	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==2){ 
	      tmpp=value2+value;
	      if (tmpp>4095) tmpp=4095;
	    }
	    else if (over==3){ // mod
	      tmpp=value2+value;
	      tmpp=tmpp%4096;
	    }
	    return tmpp;
}

inline static uint32_t livevalue(uint32_t which, uint32_t opt){
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
    if (tmpp>4095) tmpp=4095;
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

uint32_t accessplaylayerupper(uint32_t d){
  uint32_t value=(recordings[d][(int)f[d].l[1].play_cnt])>>16; 
  return value;
}

uint32_t accessplaylayerlower(uint32_t d){
  uint32_t value=(recordings[d][(int)f[d].l[0].play_cnt])&4095; 
  return value;
}

uint32_t accessreclayerupper(uint32_t d){
  uint32_t value=(recordings[d][f[d].l[1].rec_cnt])>>16; 
  return value;
}

uint32_t accessreclayerlower(uint32_t d){
  uint32_t value=(recordings[d][f[d].l[0].rec_cnt])&4095; 
  return value;
}

//(recordings[d][f[d].layer[1].rec_cnt]&4095); // lower
//

void reclayerupper(uint32_t value, uint32_t d){
  recordings[d][f[d].l[1].rec_cnt]=(recordings[d][f[d].l[1].rec_cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t d){
  recordings[d][f[d].l[0].rec_cnt]=(recordings[d][f[d].l[0].rec_cnt]&TOPS)+(value);
}

inline static void changemode(uint32_t dacc){
  f[dacc].majormode++;
  if (f[dacc].majormode>MAXMODES) f[dacc].majormode=0;
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].state=N; // NADA  
  // TODO: what else we need to reset here
}

inline static void resett(uint32_t dacc){
  f[dacc].rpp=0;
  f[dacc].active=1;
  f[dacc].masterL=0;
  f[dacc].majormode=0;
  f[dacc].minormode[0]=0;
  f[dacc].minormode[1]=0;
  f[dacc].minormode[2]=0;
  f[dacc].minormode[3]=0;  
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
  f[dacc].l[0].overend=0;  
  f[dacc].l[1].overend=0;
  f[dacc].l[0].rec_length=0;  
  f[dacc].l[1].rec_length=0;
  f[dacc].l[0].rec_start=0;  
  f[dacc].l[1].rec_start=0;
  f[dacc].l[0].overendd=0;  
  f[dacc].l[1].overendd=0;
  f[dacc].l[0].play_cnt=0;
  f[dacc].l[1].play_cnt=0;
  f[dacc].l[0].rec_end=0;
  f[dacc].l[1].rec_end=0;
  f[dacc].l[0].othercnt=0;
  f[dacc].l[1].othercnt=0;
  f[dacc].overlaid=0;
  f[dacc].lastmode=0;
  f[dacc].sensi=0;
  f[dacc].entryp=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
}

inline static void resets(uint32_t dacc){ // soft reset of both layers
  f[dacc].masterL=0;
  f[dacc].toggle=0;					
  f[dacc].ttoggle=0;
  f[dacc].state=N; // NADA
  f[dacc].playcnt=0;
  f[dacc].playfull=0;
  f[dacc].play=0;					
  f[dacc].rec=0;
  f[dacc].l[0].rec_cnt=0;
  f[dacc].l[1].rec_cnt=0;
  f[dacc].l[0].play_cnt=0;
  f[dacc].l[1].play_cnt=0;
  f[dacc].l[0].rec_end=0;
  f[dacc].l[1].rec_end=0;
  f[dacc].l[0].othercnt=0;
  f[dacc].l[1].othercnt=0;
  f[dacc].overlaid=0;
  f[dacc].lastmode=0;
  f[dacc].entryp=0;
  f[dacc].entryr=0;
  f[dacc].entryrp=0;
  f[dacc].leavep=0;
}

// new one for warp - no playlist yet
// inline static float mod0n(float value, float start, float ending, float length, uint32_t dacc) // new one with start and ending/loop point


// wrapping version - end is topmost(rec_end), length is how long, start is start - so can wrap round end...
inline static uint32_t speedsamplelowerW(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
    uint32_t lowerPosition, upperPosition;
    float sample;
    f[dacc].l[0].play_cnt=mod0N(f[dacc].l[0].play_cnt+speedy, start, end, lengthy, dacc);
    lowerPosition = (int)f[dacc].l[0].play_cnt;
    upperPosition = mod0NN(lowerPosition + 1, start, end, lengthy, dacc);
    f[dacc].l[f[dacc].masterL].cnt+=speedy;
    int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
    if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
    if (upperPosition>=MAXREC) upperPosition=0;
    LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupperW(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
    uint32_t lowerPosition, upperPosition;
    float sample;
    f[dacc].l[0].play_cnt=mod0N(f[dacc].l[0].play_cnt+speedy, start, end, lengthy, dacc);
    lowerPosition = (int)f[dacc].l[0].play_cnt;
    upperPosition = mod0NN(lowerPosition + 1, start, end, lengthy, dacc);
    f[dacc].l[f[dacc].masterL].cnt+=speedy;
    int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
    if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
    if (upperPosition>=MAXREC) upperPosition=0;
    UPPER;
    return (uint32_t)sample;
}

// 3 sets of speedsamplelower/upper: add to playlist, read from playlist, no add/no read from
// here is add to playlist
inline static uint32_t speedsamplelower(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[0].othercnt+=speedy; // fixed - to test!
  f[dacc].l[0].play_cnt=mod0X(f[dacc].l[0].play_cnt+speedy, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupper(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[1].othercnt+=speedy;
  f[dacc].l[1].play_cnt=mod0X(f[dacc].l[1].play_cnt+speedy, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  int32_t res=(f[dacc].l[1].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  UPPER;
  return (uint32_t)sample;
}

// no add but do read from playlist - no layers as layer is in the list
inline static uint32_t speedsampleplayl(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition, layer=0;
  float sample;
  if (f[dacc].playfull>0){ // if we have anything in the list
  lengthy=f[dacc].playlist[f[dacc].playcnt].length;
  start=f[dacc].playlist[f[dacc].playcnt].start;
  layer=f[dacc].playlist[f[dacc].playcnt].l;
  }
  f[dacc].l[layer].othercnt+=speedy;
  f[dacc].l[layer].play_cnt=mod0XX(f[dacc].l[layer].play_cnt+speedy, lengthy, dacc);
  lowerPosition = (int)f[dacc].l[layer].play_cnt;
  upperPosition = mod00(lowerPosition + 1, lengthy, dacc); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[layer].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  if (layer==0){  
    LOWER;
  }
  else {
    UPPER;
  }
  return (uint32_t)sample;
}

// nada to do with playlist
inline static uint32_t speedsamplelowerN(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[0].othercnt+=speedy;
  f[dacc].l[0].play_cnt=mod0(f[dacc].l[0].play_cnt+speedy, lengthy);
  lowerPosition = (int)f[dacc].l[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy); // wrap... or entry into next in list?
  int32_t res=(f[dacc].l[0].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  LOWER;
  return (uint32_t)sample;
}

inline static uint32_t speedsampleupperN(float speedy, uint32_t lengthy, uint32_t start, uint32_t end, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  float sample;
  f[dacc].l[1].othercnt+=speedy;
  f[dacc].l[1].play_cnt=mod0(f[dacc].l[1].play_cnt+speedy, lengthy);
  lowerPosition = (int)f[dacc].l[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  int32_t res=(f[dacc].l[1].play_cnt - (float)lowerPosition);
  lowerPosition+=start;
  upperPosition+=start;
  if (lowerPosition>=MAXREC) lowerPosition=0; // just in case
  if (upperPosition>=MAXREC) upperPosition=0;
  UPPER;
  return (uint32_t)sample;
}

// STARTY
void TIM2_IRQHandler(void) 
  {
    uint32_t speed=0;
    float spd=0.0; // for new accel tests
    static uint32_t d=0;
    uint32_t j,x,y, tmp, tmpp, tmpy, autre;
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    static uint32_t modetoggle=0, newmode=0, count=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0};
    static int32_t togrec=0, togplay=0, helder=0, heldon=0, modeheld=0, modechanged=1, first=0;
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Theldon[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Theld[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelder[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Newtog[8]={0,0,0,0, 0,0,0,0};      
    static uint32_t oncey=0;
    uint32_t V_options, R_options, P_options, RP_options;
    const float *playreff[4]={logfast, logslow, logfast_stop, logslow_stop}; 
    const uint32_t SENSESHIFTS[3]={0,1,2}; // just use first 2 for now
    const uint32_t SENSEOFFSETS[3]={82,560,1800}; // TODO - adjust maybe
    //    const uint32_t remode[4]={0,1,2,2}; // 2 arrays N, R and P/RP
	  
    if (oncey==0){// can we put this init elsewhere?
      oncey=1;
      for (x=0;x<8;x++){
	resett(x);
	f[x].l[0].speedsamp[0]=speedsamplelower; // where to init these...
	f[x].l[1].speedsamp[0]=speedsampleupper;
	f[x].l[0].speedsamp[1]=speedsamplelowerN; 
	f[x].l[1].speedsamp[1]=speedsampleupperN;
	f[x].l[0].speedsamp[2]=speedsamplelowerW; 
	f[x].l[1].speedsamp[2]=speedsampleupperW;
	f[x].l[0].reclayer=reclayerlower;
	f[x].l[1].reclayer=reclayerupper;
	f[x].l[0].accessreclayer=accessreclayerlower;
	f[x].l[1].accessreclayer=accessreclayerupper;
	f[x].l[0].accessplaylayer=accessplaylayerlower;
	f[x].l[1].accessplaylayer=accessplaylayerupper;

      }
    }
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	// micromode logic outside mode switches - but what if these depend on mode!?
	V_options=f[d].minormode[0]&7; // V: sens, sync/global-overlay= 3 bits - top [6] syncs to [4] to test
	R_options=f[d].minormode[1]&3; //  2 bits for 2nd tape overlay options//other options?
	P_options=f[d].minormode[2]&31; // P,RP: 11 speedarray, LOSE1sync, 11 live overlay, // 6 bits total + sync/no syncTODODONE
	RP_options=(f[d].minormode[3]&7); // RP: 1bit recend + say 2 bits overlay = 3 bits now

	// TESTY
	//	RP_options=3<<6; 
	
	f[d].sensi=V_options&1; // first bit - sensitivity is in macros
	f[d].playspeed=P_options&3; // speedarray = 2 bits
	// functions outside switch
	FREEZERS;
	REALADC;
	CTRL;

	// TODO - to test: is the finger active = long freeze
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
	    if (f[d].l[f[d].masterL].rec_end){
	    f[d].state=RP;
	  }
	    else {
	      f[d].state=R; // nothing to play
	    }
	  }
	  else if (f[d].rec)	f[d].state=R;
	  else if (f[d].play && (f[d].l[f[d].masterL].rec_end)) f[d].state=P;
	  else f[d].state=N;
	}
	f[d].lastmode=0;
	} // end of active
	
	  // do main mode/state work with switches within this
	////// TESTY

	f[d].majormode=2;
	///////////////////////////////////////////////////////	
	// NADA: TODO: geomantic mode thing - could be only for all modes which are active
	if (f[d].state==N){ 
	  RESETFRN;
	  switch(f[d].majormode){
	  case 0:
	  case 1:
	    tmp=livevalue(d, V_options);
	    DOFREEZE;
	    values[d]=tmp;
	    break;
	  case 2: // N: always recording in a loop (to both layers?)
	  tmp=livevalue(d, V_options);
	  LAYERSWOP;
	  autre=f[d].masterL;
	  RECLAYER; // autre is our layer for the macro  
	  autre=f[d].masterL^1;
	  RECLAYER;
	  values[d]=tmp;
	  break;
	  } // end switch	    
	} // end NADA
	else f[d].entryn=0;

	// PLAY: ADC->speed // toggle is swop
	if (f[d].state==P){ 
	  RESETFRP; // DONEdeal with playfull if is 0
	  f[d].leavep=1;
	  speed=control[whichctrl[d]]>>2; // TESTY - new spd accel
	  
	  switch(f[d].majormode){
	  case 0:
	  PSWOP; // includes add to playlist PSWOPP is without that adding
	  //length, start, end
	  if (f[d].l[f[d].masterL].rec_end) values[d]=  f[d].l[f[d].masterL].speedsamp[0](playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]); 
	  tmp=livevalue(d, V_options); 
	  values[d]=overlay(tmp, values[d], (P_options>>2)&3); // testy: types of live overlay
	  break;
	  case 1: // mode 1 playback of playlist
	    PSWOPP; // no adding to playlist
	    if (f[d].l[f[d].masterL].rec_end) values[d]=  speedsampleplayl(playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, d, recordings[d]);  // start is always 0 TESTY??? RECEND is our length
	  tmp=livevalue(d, V_options); 
	  values[d]=overlay(tmp, values[d], (P_options>>2)&3); // testy: types of live overlay
	    break;
	    } // end SWITCH
	} // end PLAY
	else {
	  if (f[d].leavep && f[d].majormode==0){ // we left P so add to our playlist - TODO: if any others add to playlist
	    f[d].leavep=0;
	    ADDPLAYLIST;
	  }
	  f[d].entryp=0;
	}

	// REC: ADC->overlay to other tape
	// freeze as swop main tape... // further REC adds sections to main tape...// we hear is voltage+newADCoverlay - ADD to rec means just don't reset end counter // we don't
	if (f[d].state==R){ 
	  RESETFRR; 
	  switch(f[d].majormode){
	  case 0:
	  case 1:
	    tmp=livevalue(d, V_options);
	    LAYERSWOP;
	    autre=f[d].masterL;
	    RECLAYER; // autre is our layer for the macro  
	    autre=f[d].masterL^1;
	    tmp=overlay(control[whichctrl[d]], tmp, R_options&3); // overlay of CTRL
	    values[d]=tmp;
	    RECLAYER;
	    break;
	  case 2: //ADC: zooms through start and end (at each press start, next press start) zoom/stop and playback is bounced to other layer... trigger swops layers
	    tmp=livevalue(d, V_options);
	    LAYERSWOP;//RP; 
	    if (control[whichctrl[d]]>32){ 
	      speed=control[whichctrl[d]]>>2;
	      if (f[d].rpp==0) f[d].rpp=1; // set start
	      if (f[d].rpp==2) f[d].rpp=3;
	      values[d]=f[d].l[f[d].masterL].speedsamp[2](playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
	      if (f[d].rpp==1) { // set the start
		f[d].l[f[d].masterL].rec_start=f[d].l[f[d].masterL].play_cnt;
	      }
	      else { 
		if (f[d].l[f[d].masterL].play_cnt>f[d].l[f[d].masterL].rec_start) f[d].l[f[d].masterL].rec_fraglength=f[d].l[f[d].masterL].play_cnt-f[d].l[f[d].masterL].rec_start;
		else f[d].l[f[d].masterL].rec_fraglength=(f[d].l[f[d].masterL].rec_end-f[d].l[f[d].masterL].play_cnt)+f[d].l[f[d].masterL].rec_start;
	      }
	      values[d]=overlay(tmp, values[d], (P_options>>2)&3); 
	    }
	    else { // released...
		values[d]=f[d].l[f[d].masterL].speedsamp[2](1.0f, f[d].l[f[d].masterL].rec_fraglength, f[d].l[f[d].masterL].rec_start, f[d].l[f[d].masterL].rec_end, d, recordings[d]);
		values[d]=overlay(tmp, values[d], (P_options>>2)&3); // and write this to other l
		tmp=values[d];
		autre=f[d].masterL^1;
		RECLAYER;
		//	      }
	      if (f[d].rpp==3) f[d].rpp=0;
     	      else if (f[d].rpp==1) f[d].rpp=2; // set end // when do we set to 0
	    }
	    break;
	  } // end switch
	} // end REC
	else f[d].entryr=0;

	// REC+PLAY: ADC->speed/bounce/rec to other // freeze is swop // what does voltage do (overlay same tape minormodes here)
	if (f[d].state==RP){ 
	  //	  RESETFRRP; 
	  f[d].lastmode=1; // in this case!
	  LAYERSWOPRP;
	  tmp=livevalue(d, V_options); 
	  speed=control[whichctrl[d]]>>2;
	  autre=f[d].masterL^1; // opposite...
	  values[d]=f[d].l[f[d].masterL].speedsamp[0](playreff[f[d].playspeed][speed], f[d].l[f[d].masterL].rec_end, 0, f[d].l[f[d].masterL].rec_end, d, recordings[d]); // as per play above for mode 0** would be playlist in playlist modes
	  values[d]=overlay(tmp, values[d], (P_options>>2)&3); // types of live overlay - is also recorded
	  tmp=overlayx(values[d], f[d].l[autre].accessreclayer(d), (RP_options>>1)&3);
	  RECLAYERP; // now with RP_options bit 1 as toggling rec_end - test live toggling
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
	  TEST_TOGGLES;      // only place where toggles - TESTY - newer toggles
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

