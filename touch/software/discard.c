	case 32:
	  // as mode 30?XX but we reset rec_cnt once...
	  // basic mode with NO freezers, record and play and overlay with freeze/unfreeze of all, no speed changes at all...
	  // alt logic - rec and play just reset counters as soon as hit
	  // overlay is peak
	  /*	  
		  freeze: record, tap again: playback
		  
		  play: global stop/start all playback (also sync)...
		  rec: global rec (nada if we are already in rec)...
	  */
	  FREEZERS;
	  REALADC;

	  if (frozen[daccount]) { // rec on freezer -doesn't reset counter
	    if (!lastrecy[daccount]){
	    rec_cnt[daccount]=1; // just once...
	    }
	    lastrecy[daccount]=0;
	    recd[daccount]=1;
	    playb[daccount]=0;
	  }
	  else if (rec_cnt[daccount]) { // play if we have...
	    lastrecy[daccount]=1;
	    recd[daccount]=0;
	    playb[daccount]=1;
	  }

	  // REC and PLAY just reset all respective counters but only once
	  if (togrec){ 
	    LASTREC;
	  }
	  else {
	    lastrec=0;
	      }

	  if (togplay){
	    LASTPLAY;
	  }
	  else {
	    lastplay=0;
	      }

	  // playback
	  if (playb[daccount] && rec_cnt[daccount]){// only play if we have something in rec // ALT LOGIC
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    values[daccount]=speedsample(1.0f, rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  
	  ///// recordings
	    if (recd[daccount]){ // we are recording TESTY: we don't reset counter...rec_cnt // could also be if not playing...
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    
	    ////// write to DAC
	  // if playback add
	    if (playb[daccount] && rec_cnt[daccount]) {
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

		//		itoa(rec_cnt[daccount], buffx, 10);
		//		uint32_t m[] = { 2/*stderr*/, (uint32_t)buffx, sizeof(buffx)/sizeof(char) - 1 };
		//		send_command(0x05/* some interrupt ID */, m);
		



	case 7: // TEST for local speeds on each voltage - so we don't add any values there 
	  // doesn't work so well as global as some have no contents
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    // speed depends on real how we treat it!
	    if (daccount>3) { // 4,5,6,7 voltages
	    speed=real[daccount]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    }
	    else {
	      speed=reall[daccount]; // 10 bits
	    }
	    values[daccount]=speedsample(logspeed[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	    }
	    ////// write to DAC
	    if (play==0)	    values[daccount]=(real[daccount]); 
	    
	  break; ///// 


case 5: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // with only speed upwards
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

case 5: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage from lower up
	  // with only speed upwards
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    values[daccount]=speedsample(logfast[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 

	  // NON!
	case 6: // speed with rec slow down
	  // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, no speed
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }

	  recsp[daccount]++;
	  //	  recspeed=real[6]>>6; // gets faster for higher values
	  recspeed=16; // TESTY fixed
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      if (recsp[daccount]>recspeed){
		recsp[daccount]=0;
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break; 


// NON!
	case 4: // basic mode with freezers, record and play and overlay with freeze/unfreeze of all, speed on top voltage gets slower
	  /// speed lowering as case 2
	  FREEZERS;
	  
	  if (frozen[daccount]==0) { // freeze always holds
	    REALADC;
	  }
	  // playback
	  if (play && rec_cnt[daccount]){// only play if we have something in rec
	    LASTPLAY;
	    if (overlap[daccount]) rec_cnt[daccount]=MAXREC;
	    speed=real[6]>>2; // 24/4 // 25/4 now 12 to 10 bits
	    //	    speed=1;
	    //	    values[daccount]=speedsample(logslow[speed], rec_cnt[daccount], daccount, recordings[daccount]);
	  } // if play
	  else {
	    lastplay=0;
	    play=0;
	  }
    
	  ///// recordings
	    if (rec){ // we are recording
	      LASTREC; // reset all
	      recordings[daccount][rec_cnt[daccount]]=real[daccount];
	      rec_cnt[daccount]++;
	      if (rec_cnt[daccount]>MAXREC) {
		rec_cnt[daccount]=0;
		overlap[daccount]=1;
	      }
	    } // if rec
	    else {
	      lastrec=0;
	      //	      overlap[daccount]=0;
	    }

	    ////// write to DAC
	  // if playback add
	    if (play==1) { //TEST: don't add for speed!
	    values[daccount]+=real[daccount];
	    if (values[daccount]>4095) values[daccount]=4095;
	  }
	  else {
	    values[daccount]=(real[daccount]); 
	  }
	  break;


//	    values[daccount]=speedsample(speed, rec_cnt[daccount], recordings[daccount]);
// no filtering and we can't slow down here
// unused
uint32_t upspeedsample(uint32_t speedy, uint32_t lengthy, uint32_t dacc, uint32_t *samples){
  uint32_t value;
  // test construction in most basic mode
  /*
  value=(samples[play_cnt[dacc]])&4095;  // ignore top bits
	      play_cnt[dacc]++;
	      if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0; // but what if we overlap then play full...
  */
  // speedy is 1-32 ---> 1 is basic speed.
  speedy+=1;
  play_cnt[dacc]+=(float)speedy;
  if (play_cnt[dacc]>lengthy) play_cnt[dacc]=0.0f;
  value=(samples[(int)(play_cnt[dacc])])&4095;  // ignore top bits
  return value;
}

// latest PCB now April 2021:

// 13/4/2021: toggling and freezing implemented, all hardware tested and working...

/*
TODO:

- basic recording mode, how we handle freezes and length

- different modes to list out and implement for record and playback

//NOTES 14/4:

STM32F446RETx: 128KB memory. so if we have 2bytes for each cell x8 = 16 per step at 1 KHz

say we use 8k for other variables =120,000 remaining

7500 steps for each max = 7.5 seconds at 1KHz (fastest)

75 seconds at 100Hz

- run at max speed and record at slower speed

//

10/2/2020 - start to set up TIM2 interrupt

26/1/2020 - new code base for testing on latest PCB -> note on pcb PROG HEADER we swop last 2 gnd and swdio 

// test fixed DAC outs to voltages out and to VCAs.

// test ADCs in from pads to voltages out an VCAs.

// test FR1-8 inputs, rec, play and push

- implement recording, playback and any logic/scalings

- internal DAC PA4 with multiplex with EN_LOW1 on PC11 and sel1/2/3 on PC13/14/15

- ADC0-3 on PA0/1/2/3
- ADC5-7 on PA5/6/7
- ADC4 on PC0

- rec on PB2, play on PB4, push on PB6
- FR1-7 on PB8-15, FR8 on PC4 (inverted ins from 40106 so low is on!)

On PCB panel (clockwise): 
- top one(3): ADC5 and ADC4, F6 and F5 (is adc5top or 4 the one for VCA?)
- 4: ADC7 and ADC6, F8, F7
- 1: ADC1, ADC0, F1, F2
- 2: AS+DC3, ADC2, F3, F4

/////////////////////////////////////////////////////////////

New note - now we will use onboard DAC as we only use 12x ADC

Testing on STM32F446 NUCLEO

For new touch module/own touch things: 

- read from say 12x ADC and output signals on DAC - which will be multiplexed
- so we need input ADC and eventually toggle input pins for rec/play with, output address and enable for 4051  

- first steps: ADC inputs, DAC output (should be on PA4 (DAC_OUT1) which is marked A2 on lower left of board!

but we can only have 15 ADC ins as one doubles up as DAC!

// PROGRESS: now DAC seems to work...

// ADCs, output pins, input pins...

refs:  https://stackoverflow.com/questions/45718493/stm32-f446re-simple-dac-output-what-am-i-missing

https://csserver.evansville.edu/~blandfor/Engr101/NucleoBoardUserManual.pdf

// TODO: testing for external DAC such as MPC492X (one or two DACs) - tested with 4922

- setup SPI on SPI2 or SPI3 (SPI1 would conflict with ADC ins)
- communicate with DAC1 and test - SPI seems to be working now with enable to +V and schematic as in: 

http://community.axoloti.com/t/gpio-i-o-example-dac-mcp4x22-spi/134

MOSI is on PB5, SCK is on PB3, CS is on PA15

 */

/*
void TIM2_IRQHandler(void) {
  // flash on update event
  if (TIM2->SR & TIM_SR_UIF) GPIOA->ODR ^= (1 << 5);
   
  TIM2->SR = 0x0; // reset the status register
  }*/


/*

- problems with speeds and aliasing so need to rewrite code without 32 steps-TODO: how to handle slow downs and speed ups?

14/12/21: TODO: we need to stop rec and play and all freezers if we change mode!

Q of linear or exponential scales... at the moment is all linear...

//problems with speeds and aliasing so need to rewrite code without 32 steps


24/4/2023

///////////////////older

20/12+ - see notes.org for changes

14/12: put in modechanging clearance into macro TOGGLE - still needs to be TESTED!

13/12: changes to freeze/toggle logic which seem to work well, new macrosDONE

6/12: try new freeze/toggle logics - working better so test for freezings, tested but try with other fingers before we put into TOGGLE MACRO TODO!

2/12: re-check freeze etc.logic as seems odd - was wrong way round so corrected but still not 100% as needs release

2/11: we have bleed on voltages - small but present and how can we fix this?

18/10: on mode change should we stop rec/playback as this will change reading of data (only in some cases).DONE in macro 14/12

14/10: filled in mode 0 to test all

13/10: TODO: code in freezers, mode switch and rec/play with simple case 0 and test!

11/10: TODO: simplify code sections and test all freezers, rec, mode, playback (basic mode)

- what are our modes and where are these defined? in it.c

Revisiting 30 Sept:

- 30/9 tests: 2 and 3 not closing: 3 was adc issue which fixed
   somehow, 2 still bleeds at 60mV, we adjusted TIM2 slower to get rid
   of bleed across VCAs (why now?), still to test new freeze
   functionality...also got rid of bitshift as was loud (to check on
   scope), maybe try different resistor values for closings, testing
   first freeze and seems to work


//////////////////////////

TODO: August 30+ 2021:

- new PCB - we have trig on PC6 which needs to go high only when we sense any of trigs (freezers, rec, play, mode)

- basic operations of VCA and voltage with new board (also now we have low pass in hardware)
- new freezer/trig code and test all

think it is in mode23 but we need to change the output pin here!

- figure out modes, timings, log etc.
*/
