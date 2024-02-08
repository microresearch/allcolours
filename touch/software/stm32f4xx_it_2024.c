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
#define BRK 64 // was 128 - for other toggles...
#define DELB 42 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK -- is delay we hold the the freeze/toggle
#define DELA 32 // for clear DAC // was 64

#define HOLDRESET 800 // time for full reset when hold the mode down - over 4 seconds
#define SHORTMODE 8 // was 20ms could be shorter...
#define LONGMODE 140 // 1sec
#define LONGTOG 300 // 1-2 secs long press for TOGGLE->activate

#ifdef fouronethree
#define MAXREC 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#define DOUBLEMAXREC 19000
#else
#define MAXREC 3800 // for older STM
#define DOUBLEMAXREC 7600
#endif
// with F413 we have 9000 which is how long - 21 seconds now on 24 divider

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

inline static float mod0(float value, float length)
{
  while (value > (length-1))
        value -= length;
    return value;
}

float mod0X(float value, float length, uint32_t dacc)
{
  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    fingers[dacc].playcnt+=1;
    if (fingers[dacc].playcnt>fingers[dacc].playfull) fingers[dacc].playcnt=0;
    fingers[dacc].playcntr+=1;
    if (fingers[dacc].playcntr>118) fingers[dacc].playcntr=0;
    //    printf("//playcnt %d playcntr %d len %d //",playcnt, playcntr, playlist[playcntr].length);
    length=fingers[dacc].playlist[fingers[dacc].playcnt].length;
  }
    return value;
}

float mod0XX(float value, float length, uint32_t dacc)
{
  uint32_t tmp;
  tmp=fingers[dacc].playcnt;

  while (value > (length-1)){ // we are ahead
    value -= length; //0
    // get next in list
    tmp+=1;
    if (tmp>fingers[dacc].playfull) tmp=0;
    length=fingers[dacc].playlist[tmp].length;
  }
    return value;
}

// TODO: we need to resolve layers and also start...
inline static uint32_t speedsample_playlist(float speedy, uint32_t dacc, uint32_t *samples, uint32_t start, uint32_t layerr){ // for both lower and upper? TODO!
  uint32_t lowerPosition, upperPosition;
  float sample;
  uint32_t lengthy=fingers[dacc].playlist[fingers[dacc].playcnt].length;

  
  fingers[dacc].layer[layerr].play_cnt=mod0X(  fingers[dacc].layer[layerr].play_cnt+speedy, lengthy, dacc);
  lengthy=fingers[dacc].playlist[fingers[dacc].playcnt].length;

    //  Find surrounding integer table positions
  lowerPosition = (int)  fingers[dacc].layer[layerr].play_cnt;
  upperPosition = mod0XX(lowerPosition + 1, lengthy, dacc);

  // test addings
  fingers[dacc].playlist[fingers[dacc].playcntr+1].length=(int)fingers[dacc].layer[layerr].play_cnt+1;
  fingers[dacc].playlist[fingers[dacc].playcntr+1].start=start; // ????
  fingers[dacc].playlist[fingers[dacc].playcntr+1].layer=layerr;
  fingers[dacc].playfull=fingers[dacc].playcntr;

  start=fingers[dacc].playlist[fingers[dacc].playcnt].start;
  layerr=fingers[dacc].playlist[fingers[dacc].playcnt].layer;
  int32_t res=(fingers[dacc].layer[layerr].play_cnt - (float)lowerPosition);
  if (layerr==0) {
  sample= ((samples[lowerPosition+start]&4095) + 
		 (res *
		  ((samples[upperPosition+start]&4095) - (samples[lowerPosition+start]&4095))));
  }
  else
    {
  sample= ((samples[lowerPosition+start]>>16) + 
		 (res *
		  ((samples[upperPosition+start]>>16) - (samples[lowerPosition+start]>>16)))); 
    }
  return (uint32_t)sample;
}

inline static uint32_t speedop(uint32_t dacc, uint32_t opt){
  uint32_t tmpp;
  tmpp=control[whichctrl[dacc]]>>2;
  if (opt&1){
    tmpp+=control[2]; // top
    if (tmpp>1023) tmpp=1023;
  }
  return tmpp;
}

inline static uint32_t overlay(uint32_t value, uint32_t value2, uint32_t over){ // 4 bits - value is real, value2 is added
  uint32_t tmpp, subs;
 	    if (over==0){ //usual - now swopped for >
	      if (value>value2) tmpp=value; // only if is more than
	      else tmpp=value2;
	    }
	    else if (over==1){ // mod
	      tmpp=value2+=value;
	      if (tmpp>4095) tmpp=4095;
	    }
	    else if (over==2){
	      tmpp=value2+=value;
	      tmpp=tmpp%4096;
	    }
	    else if (over==3){
	      subs=value2-value;
	      tmpp=abs(subs);
	    }
	    return tmpp;
}

inline static uint32_t livevalue(uint32_t which, uint32_t opt){
  uint32_t tmpp, subs, overoverlay;
  // options for live value - eg. add global from top (and type of overlays), (sensitivity is already in macros)
  if (which!=6) tmpp=values[6]; // top voltage - value at the end
  else { // no options on 6 or?
    tmpp=real[6];
    return tmpp;
  }
  /* options
  no overlay, 0,1,2,3 below = 5 options and we want ideally 4 or 7
  maybe lose 3
   */

  overoverlay=opt&3;
  if (overoverlay==0) tmpp=real[which];
  else if (overoverlay==1){ //usual - now swopped for >
    if (real[which]>tmpp) tmpp=real[which]; // only if is more than
  }
  else if (overoverlay==2){ // mod
    tmpp+=real[which];
    if (tmpp>4095) tmpp=4095;
  }
  else if (overoverlay==3){
    tmpp+=real[which];
    tmpp=tmpp%4096;
  }
  return tmpp;
}

inline static void resetx(uint32_t which){
  for (uint32_t y=0;y<MAXREC;y++){ 
    recordings[which][y]=0;
  }
}

void reclayerupper(uint32_t value, uint32_t daccount){
  recordings[daccount][fingers[daccount].layer[1].rec_cnt]=(recordings[daccount][fingers[daccount].layer[1].rec_cnt]&4095)+(value<<16);
}

void reclayerlower(uint32_t value, uint32_t daccount){
  recordings[daccount][fingers[daccount].layer[0].rec_cnt]=(recordings[daccount][fingers[daccount].layer[0].rec_cnt]&TOPS)+(value);
}

inline static void changemode(uint32_t dacc){
  fingers[dacc].majormode[fingers[dacc].state]++;
  fingers[dacc].toggle=0;					
  fingers[dacc].ttoggle=0;
  fingers[dacc].play=0;					
  fingers[dacc].rec=0;
  fingers[dacc].state=N; // NADA  
  // TODO: what else we need to reset here
}

inline static void resett(uint32_t dacc){
  fingers[dacc].active=1;
  fingers[dacc].masterL=0;
  fingers[dacc].majormode[0]=0;
  fingers[dacc].majormode[1]=0;
  fingers[dacc].majormode[2]=0;
  fingers[dacc].majormode[3]=0;  
  fingers[dacc].minormode[0]=0;
  fingers[dacc].minormode[1]=0;
  fingers[dacc].playspeed=0;
  fingers[dacc].toggle=0;					
  fingers[dacc].ttoggle=0;
  fingers[dacc].state=N; // NADA
  fingers[dacc].playcnt=0;					
  fingers[dacc].playfull=0;
  fingers[dacc].play=0;					
  fingers[dacc].rec=0;
  fingers[dacc].layer[0].rec_cnt=0;
  fingers[dacc].layer[1].rec_cnt=0;
  fingers[dacc].layer[0].play_cnt=0;
  fingers[dacc].layer[1].play_cnt=0;
  fingers[dacc].layer[0].rec_end=0;
  fingers[dacc].layer[1].rec_end=0;
  fingers[dacc].overlaid=0;
  fingers[dacc].lastmode=0;
  fingers[dacc].sensi=0;
  fingers[dacc].entryp=0;
  fingers[dacc].entryr=0;
  fingers[dacc].entryrp=0;
}

// draft new speedsample for list:


inline static uint32_t speedsamplelower(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  fingers[dacc].layer[0].play_cnt=mod0(fingers[dacc].layer[0].play_cnt+speedy, lengthy);
  lowerPosition = (int)fingers[dacc].layer[0].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy); // wrap... or entry into next in list?
  
  int32_t res=(fingers[dacc].layer[0].play_cnt - (float)lowerPosition);
  float sample= ((samples[lowerPosition+start]&4095) + 
		 (res *
		  ((samples[upperPosition+start]&4095) - (samples[lowerPosition+start]&4095))));

  return (uint32_t)sample;
}

inline static uint32_t speedsampleupper(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples){
  uint32_t lowerPosition, upperPosition;
  
  fingers[dacc].layer[1].play_cnt=mod0(fingers[dacc].layer[1].play_cnt+speedy, lengthy);
  lowerPosition = (int)fingers[dacc].layer[1].play_cnt;
  upperPosition = mod0(lowerPosition + 1, lengthy);
  
  int32_t res=(fingers[dacc].layer[1].play_cnt - (float)lowerPosition);
  float sample= ((samples[lowerPosition+start]>>16) + 
		 (res *
		  ((samples[upperPosition+start]>>16) - (samples[lowerPosition+start]>>16)))); 

      return (uint32_t)sample;
}

// STARTY
void TIM2_IRQHandler(void) 
  {
    uint32_t speed=0;
    static uint32_t daccount=0;
    uint32_t j,x,y, tmp, tmpy, autre;
    uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
    static uint32_t modetoggle=0, newmode=0, count=0;
    static uint32_t lasttriggered[11]={0}, mbreaker=0, breaker[11]={0};
    static int32_t togrec=0, togplay=0, helder=0, heldon=0, helldone=0, modeheld=0, modechanged=1, first=0;
    static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelldone[8]={0,0,0,0, 0,0,0,0};     // helldone=0; heldon=0; modeheld=helder; helder=0;}  but for toggle
    static uint32_t Theldon[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Theld[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelder[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Newtog[8]={0,0,0,0, 0,0,0,0};      
    static uint32_t oncey=0;
    uint32_t V_options, R_options, P_options, RP_options;
    const float *playreff[4]={logfast, logspeed, logfast_stop, logspeed_stop}; 
    const uint32_t SENSESHIFTS[3]={0,1,2}; // just use first 2 for now
    const uint32_t SENSEOFFSETS[3]={64,560,1800};
    const uint32_t remode[4]={0,1,2,2}; // 2 arrays N, R and P/RP
	  
    if (oncey==0){// can we put this init elsewhere?
      oncey=1;
      for (x=0;x<8;x++){
	resett(x);
	fingers[x].layer[0].speedsamp=speedsamplelower; // where to init these...
	fingers[x].layer[1].speedsamp=speedsampleupper;
	fingers[x].layer[0].reclayer=reclayerlower;
	fingers[x].layer[1].reclayer=reclayerupper;

    }
    }
    
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

	// micromode logic outside mode switches - but what if these depend on mode!?
	if (daccount==6) V_options=fingers[daccount].minormode[0]&1; // V: sens only as we can't sync to itself
	else V_options=fingers[daccount].minormode[0]&7; // V: sens, sync/global-overlay= 2 bits = 3 bits - except top [6] has no sync opts
	R_options=fingers[daccount].minormode[1]&3; //  2 bits for 2nd tape overlay options//other options
	P_options=fingers[daccount].minormode[2]&31; // P,RP: 11 speedarray, 1sync, 11 live overlay, // 5 bits
	RP_options=(fingers[daccount].minormode[2]&127); // RP: 11 recorded overlay if any // +2 bits

	fingers[daccount].sensi=V_options&1; // first bit - sensitivity is in macros
	fingers[daccount].playspeed=P_options&2; // speedarray

	// functions outside switch
	FREEZERS;
	REALADC;
	CTRL;

	// TODO - to test: is the finger active = long freeze
	   if (Newtog[daccount]){
	     Newtog[daccount]=0;
	     if (Theld[daccount]>LONGTOG) {
	       Theld[daccount]=0;
	       fingers[daccount].active^=1; // t0ggle
	     }
	   }
	
	// togplay and togrec
	if (fingers[daccount].active){
	if (togplay) fingers[daccount].play^=1;
	if (togrec) fingers[daccount].rec^=1;

	// logic of states now
	  if (fingers[daccount].rec && fingers[daccount].play){
	    if (fingers[daccount].layer[fingers[daccount].masterL].rec_end){
	    fingers[daccount].state=RP;
	  }
	    else {
	      fingers[daccount].state=R; // nothing to play
	    }
	  }
	  else if (fingers[daccount].lastmode==1 && fingers[daccount].play==0) { // if we leave overlaid via. exit from play
	    fingers[daccount].state=N;
	  }
	  else if (fingers[daccount].rec)	fingers[daccount].state=R;
	  else if (fingers[daccount].play && (fingers[daccount].layer[fingers[daccount].masterL].rec_end)) fingers[daccount].state=P;
	  else fingers[daccount].state=N;
	} // end of active
	
	  // do main mode/state work with switches within this
	
	// NADA: TODO: geomantic mode thing - could be only for all modes which are active
	if (fingers[daccount].state==N){ 
	  RESETFRN; 
	  fingers[daccount].lastmode=0;
	  tmp=livevalue(daccount, V_options);
	  DOFREEZE;
	  values[daccount]=tmp;
	} // end NADA
	else fingers[daccount].entryn=0;

	// PLAY: ADC->speed // toggle is swop
	if (fingers[daccount].state==P){ 
	  RESETFRP; // DONEdeal with playfull if is 0
	  fingers[daccount].lastmode=0;
	  fingers[daccount].masterL=fingers[daccount].toggle; // add to playlist if we change
	  speed=speedop(daccount, (P_options>>2)&1); // TEST: added speed sync/top
	  if (fingers[daccount].layer[fingers[daccount].masterL].rec_end) values[daccount]=  fingers[daccount].layer[fingers[daccount].masterL].speedsamp(playreff[fingers[daccount].playspeed][speed], fingers[daccount].layer[fingers[daccount].masterL].rec_end, 0, daccount, recordings[daccount]);  // start is always 0 TESTY??? RECEND is our length
	  
	  //  tmp=livevalue(daccount, V_options); 
	  values[daccount]=overlay(tmp, values[daccount], (P_options>>3)&3); // testy: types of live overlay
	} // end PLAY
	else fingers[daccount].entryp=0;

	// REC: ADC->overlay to other tape
	// freeze as swop main tape... // further REC adds sections to main tape...// we hear is voltage+newADCoverlay - ADD to rec means just don't reset end counter // we don't
	if (fingers[daccount].state==R){ 
	  RESETFRR; 
	  fingers[daccount].lastmode=0;
	  fingers[daccount].masterL=fingers[daccount].toggle;
	  tmp=livevalue(daccount, V_options); 
	  autre=fingers[daccount].masterL;
	  RECLAYER; // autre is our layer for the macro  
	  autre=fingers[daccount].masterL^1;
	  tmp=overlay(tmp, control[whichctrl[daccount]], R_options&3); // overlay of CTRL
	  values[daccount]=tmp;
	  RECLAYER;
	} // end REC
	else fingers[daccount].entryr=0;

	// REC+PLAY: ADC->speed/bounce/rec to other // freeze is swop // what does voltage do (overlay same tape minormodes here)
	if (fingers[daccount].state==RP){ 
	  RESETFRRP; 
	  fingers[daccount].lastmode=1; // in this case!
	  fingers[daccount].masterL=fingers[daccount].toggle;
	  tmp=livevalue(daccount, V_options); 
	  speed=speedop(daccount, (P_options>>2)&1); // TEST: added speed sync/top
	  autre=fingers[daccount].masterL^1; // opposite...
	  
	  values[daccount]=  fingers[daccount].layer[fingers[daccount].masterL].speedsamp(playreff[fingers[daccount].playspeed][speed], fingers[daccount].layer[fingers[daccount].masterL].rec_end, 0, daccount, recordings[daccount]); // as per play above ** would be playlist in playlist modes

	  values[daccount]=overlay(tmp, values[daccount], (P_options>>3)&3); // testy: types of live overlay - is also recorded
	  // overlay_end=till own rec_end (1), other rec_end(2) - if exists, extend until limit (3)
	  // types of overlay: 
	  
	  tmp=values[daccount]; // replace with reclayer options... eg. if we add to what is there??? if we extend past the end...
	  RECLAYER; // TODO: this does extend past the end... 
	  fingers[daccount].layer[autre].rec_end=fingers[daccount].layer[autre].rec_cnt; // this was outside RP below before...
	} //end RP
	else fingers[daccount].entryrp=0;

	// end of modes 
	
	WRITEDAC2;
	daccount++;
	if (daccount==8) {
	  daccount=0;
	  count++;
	  togplay=0; togrec=0; // here as then we set them for one round
	  TEST_TOGGLES;      // only place where toggles - TESTY - newer toggles
	  // handle micromodes, resett, and  
	  // how - depends on active positions // states we deal with later - go up to 10 bits

	  if (newmode){
	    newmode=0;
	    breaker[10]=0;

	    if (modeheld>HOLDRESET) { //reset all
	      modeheld=0;
	      if (fingers[0].active) resett(0); 	      //	      if active reset that one;
	    }
	else if (modeheld>LONGMODE && modeheld<HOLDRESET) { // increment major mode if active
	  modeheld=0;
	  if (fingers[0].active) changemode(0);
	  if (fingers[1].active) changemode(1);
	  if (fingers[2].active) changemode(2);
	  if (fingers[3].active) changemode(3);
	  if (fingers[4].active) changemode(4);
	  if (fingers[5].active) changemode(5);
	  if (fingers[6].active) changemode(6);
	  if (fingers[7].active) changemode(7);
	  
	}	
	else if (modeheld<LONGMODE){ //inc minor mode 
	  modeheld=0; 
	  if (fingers[0].active) {
	    fingers[0].minormode[remode[fingers[0].state]]++;
	  }
	  if (fingers[1].active) {
	    fingers[1].minormode[remode[fingers[1].state]]++;
	  }
	  if (fingers[2].active) {
	    fingers[2].minormode[remode[fingers[2].state]]++;
	  }
	  if (fingers[3].active) {
	    fingers[3].minormode[remode[fingers[3].state]]++;
	  }
	  if (fingers[4].active) {
	    fingers[4].minormode[remode[fingers[4].state]]++;
	  }
	  if (fingers[5].active) {
	    fingers[5].minormode[remode[fingers[5].state]]++;
	  }
	  if (fingers[6].active) {
	    fingers[6].minormode[remode[fingers[6].state]]++;
	  }
	  if (fingers[7].active) {
	    fingers[7].minormode[remode[fingers[7].state]]++;
	  }
	}
	} // newmode
	}
    }
  }

