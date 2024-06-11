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

// TODO: fix at the end
#define MAXMODES 8
#define MAXBASE 15

uint32_t maxovermin[MAXMODES]={15,15,31,0, 0,0,0,0}; // to fill in as we go
uint32_t maxplaymin[MAXMODES]={31,15,31,0, 0,0,0,0};
uint32_t maxrecmin[MAXMODES]={1,1,1,0, 0,0,0,0};

void resett(void){
  
};

typedef struct layers_ {
  uint32_t rec_cnt;
  uint32_t rec_end;
  uint32_t play_cnt;
  uint32_t play_len;
  uint32_t (*speedsamp)(float speedy, uint32_t lengthy, uint32_t start, uint32_t dacc, uint32_t *samples);
  void (*reclayer)(uint32_t value, uint32_t dacccount); // to add these
} layers;

static layers lay[8][2];

    typedef struct listy_ { 
      uint32_t start[120];  
      uint32_t length[120];
      uint8_t layer;
    } playl;

    enum STATE {
      N,
      R,
      P,
      RP
    };

    typedef struct xx_ {
      enum STATE state; 
      uint32_t active;
      uint32_t masterL; // current layer
      uint32_t majormode;
      uint32_t minormode[2];
      uint32_t playspeed; // index into playreff
      uint32_t toggle, ttoggle;
      layers layer[2]; // rec layers count and functions for access
      playl playlist;// list of playbacks
      uint32_t playcnt; // 
      uint32_t playfull; // how many elements in the playlist
      uint32_t overlaid; /// how we enter RP
      uint32_t lastmode;
      uint32_t play,rec;
      uint32_t sensi;
      uint32_t entryp, entryr, entryrp; // for resets
    } hands;

static hands f[8];


#define TOPS 0b11111111111111110000000000000000

// timing is critical
// and maybe we need different BRK value for: mode, freezer, rec and play - 64 and 10 are close...
#define BRKF 8 // for freezer. 8 with 24 divider ////now 48 with divider of 8; was 8 when we have have divider in main as 32... too high causes issues for speed of freezes
#define BRK 8 // was 64 // was 128 - for other toggles...
#define DELB 42 // 40 now with 8 divider - was 20 reduced was 200 delay for pin changes in new trigger code - was 10000 but this slows down all playback so we have to reduce and rely on BRK -- is delay we hold the the freeze/toggle
   #define DELA 32 // for clear DAC // was 64
#define FULLRESET 1200
#define SOFTRESET 800 //  was - divide by 8 if we have test_toggle slowr // was 4000 time for full reset when hold the mode down - over 4 seconds
#define SHORTMODE 8 // was 20ms could be shorter...
#define LONGMODE 140 // 1sec was 280=2 secs
#define LONGTOG 300

#ifdef fouronethree
#define MAXREC 9500 // F413===depends on RAM! // for uint32_t we have this for 128Kb -> 320k around 10k samples which is how long??? // was 7000 like 30 seconds at 32 divider...
#define DOUBLEMAXREC 19000
#else
#define MAXREC 3800 // for older STM
#define DOUBLEMAXREC 7600
#endif
// with F413 we have 9000 which is how long - 21 seconds now on 24 divider

   GPIO_InitTypeDef GPIO_InitStructure;

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


   extern __IO uint32_t adc_buffer[8];
   static uint32_t recordings[8][MAXREC+1]={0}; // 
   static uint32_t rec_cnt[8]={0,0,0,0, 0,0,0,0};
   static uint32_t spd_cnt[8]={0,0,0,0, 0,0,0,0};
   static uint32_t over_cnt[8]={0,0,0,0, 0,0,0,0};
   static uint32_t play_spd_cnt[8]={0,0,0,0, 0,0,0,0};
   static float play_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
   static float play_cnt_lop[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
   static float ownplay_cnt[8]={0.0f,0.0f,0.0f,0.0f, 0.0f,0.0f,0.0f,0.0f,};
   //static uint32_t tgr_cnt[10]={0};
   static uint32_t rec=0, play=0;

   static uint32_t SENSESHIFT=0, SENSEOFFSET=0;//1800; // offset is minus!
   //static uint32_t SENSESHIFT=1, SENSEOFFSET=560; // lower sensitivity

    const uint32_t SENSESHIFTS[3]={0,1,2}; // just use first 2 for now
    const uint32_t SENSEOFFSETS[3]={64,560,1800};


   //static uint32_t shifter[8]={2,2,2,2,2,2,2,2}; // shifter seperates vca from cv - VCA comes first
   //static uint32_t shifter[8]={1,1,1,1,1,1,1,1}; // shifter seperates vca from cv - no shift here
   uint32_t previousone[8]={3,0,1,2, 7,4,5,6}; // lowest voltage=4?, then VCAs from bottom order=0,1,2,3, 4,5,6,7



   // STARTY
   void TIM2_IRQHandler(void) // running with period=1024, prescale=32 at 2KHz
     {
       static uint32_t again=0, ssilence=0, started=0;
       static uint32_t silence=0;

       static uint32_t global_time=0; // also in resett
       static uint32_t d=0, entryp=0, entryn=0, entryr=0, entryo=0;
       static uint32_t speed=0, overlap[8]={0};
       static float speedy, alpha[8]={0,0,0,0, 0,0,0,0};
       static uint32_t starty[8]={0,0,0,0, 0,0,0,0}, target[8]={0,0,0,0, 0,0,0,0};
       static int32_t result[8]={0,0,0,0, 0,0,0,0};
       volatile uint32_t k;
       uint32_t j,x,y;//
       static uint32_t val;
       // array to map freeze but exception is FR8 on PC4! 
       uint32_t freezer[8]={1<<8, 1<<4, 1<<13, 1<< 15,  1<<9, 1<<12, 1<<14, 1<<4}; // 1st 4 are vca, last 4 are volts  
       uint32_t prev[8]={1,2,3,4,5,6,7,0};
       uint32_t bits, lengg, where;
       uint32_t values[8]={0,0,0,0, 0,0,0,0}; // changed 2/10
       static int32_t real[8], reall[8];//, realfr[8]={0,0,0,0, 0,0,0,0}; // not static????
       static int32_t control[4];
       static uint32_t lastvalue[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastvaluer[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastplayer[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastplayerr[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastspeed=0, lastspeedd=0;
       static uint32_t frozen[8]={0,0,0,0, 0,0,0,0};
       static uint32_t first_round[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastplayspot[8]={0,0,0,0, 0,0,0,0};
       static uint32_t playb[8]={0,0,0,0, 0,0,0,0};
       static uint32_t recd[8]={0,0,0,0, 0,0,0,0};
       static uint32_t lastrec=0, secondrec=0, lastplay=0, added[8]={0}, modetoggle=0, newmode=0, counting=0, overlaid=0, lastmode=0;
       static uint32_t count=0, triggered[11]={0}, mode=0, starter[8]={0,0,0,0,0,0,0,0}, freezetoggle[8]={0,0,0,0,0,0,0,0}, ender[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, enderr[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, enderspd[8]={MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC, MAXREC}, recsp[8]={0}, baseminor=0,recminor=0,playminor=0,overminor=0,nadaminor=0;
       static uint32_t lasttriggered[11]={0}, mbreaker=0, lastlastrec=0, llrec=0,lastlastplay, lastlast;
       static int32_t endpoint, togrec=0, togplay=0, helder=0, heldon=0, helldone=0, modeheld=0, modechanged=1, first=0, firsty[8]={0}, breaker[11]={0};
       static uint32_t testingl=0, testingt=0;

    static uint32_t Thelldone[8]={0,0,0,0, 0,0,0,0};     // helldone=0; heldon=0; modeheld=helder; helder=0;}  but for toggle
    static uint32_t Theldon[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Theld[8]={0,0,0,0, 0,0,0,0};
    static uint32_t Thelder[8]={0,0,0,0, 0,0,0,0};      
    static uint32_t Newtog[8]={0,0,0,0, 0,0,0,0};      
       
       uint32_t tmp, trigd;
       int32_t midder, subs;

       uint32_t speeddiv[4]={1, 4, 16, 32};
       float speeddivisor[4]={1.0, 0.25, 0.0625, 0.03125}; /// ???

       uint32_t playoverlay, playspeed, playspeedmod, playfreeze, playrun, playlast;
       uint32_t recspeed;
       uint32_t overoverlay, overfreeze, overrun, overlast, overrec, overspeedmod;

       //    itoa(prev[0], buffx, 10);
       //  uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
       //  send_command(0x05/* some interrupt ID */, m);

       if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // this was missing ???
       {
	   TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	   
	   mode=111; 	   /// 0:ADC all, 666: newADC, 667: toggle/freeze, 777: modetoggle, 778:longer mode, 779:longer freeze/toggle
	   
	   // SHIFTS
	   // SENSESHIFT=2, SENSEOFFSET=1800; 
	   //SENSESHIFT=1, SENSEOFFSET=560;
	   //	   SENSESHIFT=0, SENSEOFFSET=64;

	   f[4].sensi=2;
	   f[0].sensi=0;
	   switch(mode){

	   case 0: // test realadc and dacs... // test zero level...
	     REALADC;
	     //  TEST_TOGGLES;
	     //	     values[d]=(real[d]);
	     if (real[d]>40) values[d]=4095;//real[d]; // this value does not seem to depend on sensi...???
	     else values[d]=0;
	     //	     values[d]=40;
	     break; 

	   case 111: // test noise/glitch
	     values[d]=4095;
	     break;

	   case 112: // test if we have 0 for silence modes
	     REALADC;
	     if (real[d]==0) values[d]=0;
	     else values[d]=4095;
	     break;

	   case 666: // test new ADCs:
	     CTRL;
	     values[4]=control[0];
	     break;

	   case 667:
	     FREEZERS;
	     if (f[4].ttoggle) {
	       testingl^=1;
	       f[4].ttoggle=0;
	     }
	     
	     if (testingl) { 
	       values[4]=4095;
	  }
	     else values[4]=0;
	     break;
	     
	   case 777: // tests of all toggles! rec, play, mode and freeze
	     //	     	  FREEZERS;
	     ///TEST_TOGGLES;
	     
	  if (modetoggle) {  // frozen[d]  // play // rec // modetoggle
	    values[4]=4095;
	  }
	  else values[4]=0;
	  
	  /*
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	  \
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	  \
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(GPIOC, &GPIO_InitStructure); \
	GPIOC->BSRRL=(1)<<6; \
	//	delay();     \

	for (x=0;x<100;x++){
	if (!(GPIOB->IDR & (1<<6))) { // ! is on!
	    values[4]=4095;
	  }
	  else values[4]=0;
	}
	GPIOC->BSRRH=(1)<<6;			  \
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; \
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; \
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; \
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; \
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; \
	GPIO_Init(GPIOC, &GPIO_InitStructure); \
	  */
	  
	  break; /////

	case 778: // for hold timing tests below:
	  if (testingl) { 
	    values[4]=4095;
	  }
	  else values[4]=0;
	  break; /////	    

       case 779: // for toggle longer as in attach/detach

	  if (testingt) { 
	    values[4]=4095;
	  }
	  else values[4]=0;
	   break;
	   } // switch
	   
	// see if works best there?
	   FREEZERS;
	   if (Newtog[4]){
	     Newtog[4]=0;
	     if (Theld[4]>LONGTOG) {
	       Theld[4]=0;
	     testingt^=1; // testy
	     }
	   }
	   
	WRITEDAC2;
	d++;
	if (d==8) {
	   TEST_TOGGLES;      // only place where toggles - pulled out of ==8 section
	  global_time++;
	  d=0;
	  count++;
	  //	  TEST_TOGGLES;      // only place where toggles TESTY!
	// start to test for long or short mode hits
	  if (newmode){
	    newmode=0;
	    breaker[10]=0;
	    /* if (modeheld>10) { // 1000 is around 4 seconds and works // 10 is short */
	    /* modeheld=0; */
	    /* testting^=1; // testy */
	    /* } */

	    if (modeheld>FULLRESET) { //reset all
	  modeheld=0;
	  RESETT;
	  //	  	  testingl^=1; // testy
	}
	    else if (modeheld>SOFTRESET && modeheld<FULLRESET){
	      //	      testingl^=1; // testy
	    }
	else if (modeheld>LONGMODE && modeheld<SOFTRESET) { // increment major mode
	  modeheld=0;
	  //	  MODECHANGED;
	  mode++;
	  if (mode>MAXMODES) mode=0;
	  //	  	  testingl^=1; // testy
	  //	  testting^=1; // testy
	}	
	else if (modeheld<LONGMODE){ //inc minor mode matrix
	  modeheld=0; // ??? was commented just for testing
	  //	  testting^=1; // testy triggers
	  //	  	  testingl^=1; // testy
	  baseminor++;
	  if (baseminor>MAXBASE) baseminor=0;
	  //  if (rec==0 && play==0) baseminor++; // we dont use so far
	  if (rec && play) {
	    overminor++;
	    if (overminor>maxovermin[mode]) overminor=0; // maxplaymin[mode]=xxx;
	  }
	  else if (rec) {
	    recminor++;
	    if (recminor>maxrecmin[mode]) recminor=0;
	  }
	  else if (play) {
	    playminor++;
	    if (playminor>maxplaymin[mode]) playminor=0;
	  }
	  }
	  } // newmode
    }
    }
  }
