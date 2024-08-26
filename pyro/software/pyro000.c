/*
1- DONEcode to test: flash LEDs, read from inputs, trigger outs, read from encoder, encoder switch

inputs as pulses...

HEADER from top: reset, MOSI, MISO, SCK, GND

2- select modes using encoder: - different modes eg. single trigger sets off all, at interval x... next on x does x... enables/etc
 - LED patterns - flashing all signifies ARMed..., binary mode, and then which one is armed...

// where is encoder code? arduino encoder

*/

#define F_CPU 16000000UL 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

typedef int u16;
typedef unsigned char u8;

#define BV(bit) (1<<(bit)) // Byte Value => converts bit into a byte value. One at bit location.
#define cbi(reg, bit) reg &= ~(BV(bit)) // Clears the corresponding bit in register reg
#define sbi(reg, bit) reg |= (BV(bit))              // Sets the corresponding bit in register reg
#define HEX__(n) 0x##n##UL

void adc_init(void)
{
	cbi(ADMUX, REFS1);
	sbi(ADMUX, REFS0); // AVCC
	sbi(ADMUX, ADLAR); //8 bits
	sbi(ADCSRA, ADPS2);
	//	sbi(ADCSRA, ADPS1); // change speed here! now div by 64
	//	sbi(ADCSRA, ADPS0); // change speed here!

	sbi(ADCSRA, ADEN);
	//sbi(ADCSRA, ADIE); // not needed
	DDRC = 0x00;
	PORTC = 0x00;
}


static u8 aLastState=0;

ISR(TIMER2_COMPA_vect){//timer2 interrupt 200 Hz
  u8 tmp=0;
  static u8 armed=0, primed[4]={0,0,0,0};
  static uint32_t former=0;
  static int counter = 0; // can go -
  static uint32_t timer=0; 
  u8 aState, fom=0;
  uint32_t howlong=0;
  static uint32_t flashcount=0, presscnt;
  uint32_t pulslength;
  static u8 flasher=0, shortpress;
  static u8 mode, released, pressed;
  static u8 last[4]={0,0,0,0}, pin[4]={0,0,0,0}, state[4]={0,0,0,0};
  static uint32_t counterr[4]={0,0,0,0};
  static u8 armmed[4]={0,0,0,0};
  static u8 timeof[4]={0,0,0,0};
  const uint32_t remap[15]={8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    /* TODO:

       Timings for: press long, flashings, trigger-FUSE//100ms/2s

    - DONEwe just want 15 modes + timing of these (15 as no flash for 0) - length is length of push
    - DONEwe have different length of push... for length of trigger and priming
    - DONEflashing short or long when armed
    - modes to sketch and test

    - DONEport encoder: pins PD2, PD3 and switch is PB0 - A is ENC1, B is ENC0 // test switch also
    - DONEtriggers tested with LED
    - DONEtest triggering of igniter: 0-3 is PD0, PD1, PB1, PB2
    - DONEtest input trigger signals: PC0-PC3 - tested!
     */
    // set modes
  
  if (!armed){ // only change mode if we are not armed
    aState=(PIND&(1<<3))>>3;
     if ((aLastState == 1) && (aState == 0)) {       // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
       if (((PIND&(1<<2))>>2) != aState) { 
       counter ++;
     } else {
       counter --;
     }
       if (counter<0) counter=14;
       if (counter>14) counter=0;
     }
   aLastState = aState; 
    }
   
    // armed or not and length of...
    if (PINB&1 && former>10) {  // pressed so start to count...
      pressed=1;
      former=0;
   }
   if (pressed) presscnt++;
   if (pressed && former>10) { // released
     former=0;
     pressed=0;
     armed^=1;
     if (armed) {
       armmed[0]=1;
       armmed[1]=1;
       armmed[2]=1;
       armmed[3]=1;
       if (presscnt>300) shortpress=0; // long - say 1-2+ second press = 200x2=400
       else shortpress=1;
     }
     else { // not armed then reset all // TODO ????
       primed[0]=0;
       primed[1]=0;
       primed[2]=0;
       primed[3]=0;
       armmed[0]=0;
       armmed[1]=0;
       armmed[2]=0;
       armmed[3]=0;
       state[0]=0;
       state[1]=0;
       state[2]=0;
       state[3]=0;
       counterr[0]=0;
       counterr[1]=0;
       counterr[2]=0;
       counterr[3]=0;
       timer=0;
     }
     presscnt=0;
   } // press
   
   fom=PINB&1;
   if (fom==0) former++;
   
   shortpress=0; // TESTY!
   if (shortpress) {
     howlong=15; // length of flash = 1/5
     pulslength=20; // TODO: calibrate // length of pulse = 100ms=20
   }
   else {
     howlong=120; // longer --> was 120 /// 2000 is 10 seconds
     pulslength=400; // TODO: calibrate // 2 seconds
   }
   // display
   
   counter=0;// TESTY display!
   if (armed)  { // flash
     flashcount++;
     if (flashcount>howlong){ 
	 flasher^=1;
	 flashcount=0;
       }
     if (flasher) PORTD|=(((remap[counter])<<4)); // display - but do flashing on armed with length
     else PORTD&=0b00001111; // mask
   }
   else PORTD=(remap[counter])<<4; // display - but do flashing on armed with length
  
     //   else PORTD=0;
   
   //  DONE  - test triggering of igniter: 
   // pulses out: PD0, PD1, PB1, PB2
   // pulses in: PC0,PC1, PC2, PC3
   //   sbi(PORTB,1);
  // DO MODES here mode is counter... 0-14

   counter=14; // TESTY!
   if (armed){
   switch(counter){
   case 16: // testy ONLY
     for (u8 x=0;x<4;x++){
       if (x==0) cbi(PORTD,0);
       else if (x==1) cbi(PORTD,1);
       else if (x==2) cbi(PORTB,1);
       else cbi(PORTB,2);

       pin[x]=(PINC&(1<<x));
       if (x==0 && pin[x]) sbi(PORTD,0);
       else if (x==1 && pin[x]) sbi(PORTD,1);
       else if (x==2 && pin[x]) sbi(PORTB,1);
       else if (pin[x]) sbi(PORTB,2);
     }
     break;

     case 0: // 1- trigger sets off each one whenever and no re-trigger
     for (u8 x=0;x<4;x++){
       pin[x]=(PINC&(1<<x));
       if (armmed[x] && pin[x] && (last[x]==0) && state[x]==0) { 
	 state[x]=1; // fired
   }
       last[x]=pin[x];
     }
     break;

   case 1: // 2- trigger on first sets off all at once...
     pin[0]=(PINC&1);
       if (pin[0] && (last[0]==0) && state[0]==0) { 
	 state[0]=1; // fire all
	 state[1]=1; // fire
	 state[2]=1; // fire
	 state[3]=1; // fire
       }
       last[0]=pin[0];
     break;

   case 2://- trigger on first sets off first and then primes rest to set off on their own trigger 
     pin[0]=(PINC&1);
     if (pin[0] && (last[0]==0) && primed[0]==0 && state[0]==0) { 
       primed[0]=1;
       state[0]=1; // fired
     }
     
       // deal with the others:
       for (u8 x=1;x<4;x++){
       pin[x]=(PINC&(1<<x));

       if (primed[0] && armmed[x] && pin[x] && (last[x]==0) && state[x]==0) { 
	 state[x]=1; // fired
       }

       last[x]=pin[x];       
       }
       last[0]=pin[0];
	   break;

   case 3: // 3- pair arms or primes other - so one goes off after other .. pair is 0 and 1, 2 and 3
     pin[0]=(PINC&1);
     if (pin[0] && (last[0]==0) && primed[0]==0 && state[0]==0) { 
       primed[0]=1;
       state[0]=1; // fired
     }

     pin[2]=(PINC&4);
     if (pin[2] && (last[2]==0) && primed[2]==0 && state[2]==0) { 
       primed[2]=1;
       state[2]=1; // fired
     }

     pin[1]=(PINC&2);
     if (primed[0] && armmed[1] && pin[1] && (last[1]==0) && state[1]==0) { 
       state[1]=1; // fired
     }

     pin[3]=(PINC&8);
     if (primed[2] && armmed[3] && pin[3] && (last[3]==0) && state[3]==0) { 
       state[3]=1; // fired
     }
          
       last[0]=pin[0];
       last[1]=pin[1];
       last[2]=pin[2];
       last[3]=pin[3];       
     break;

   case 4:      //4- in sequence but on trigger - so one sets 2 ready, 2 sets 3 and 3 sets 4 (ie. only 3 has fired can 4 go on its trigger, ignore before that)
     pin[0]=(PINC&1);
     if (pin[0] && (last[0]==0) && primed[0]==0 && state[0]==0) { 
       primed[0]=1;
       state[0]=1; // fired
     }
     
     pin[1]=(PINC&2);
     if (primed[0] && armmed[1] && pin[1] && (last[1]==0) && state[1]==0) { 
       primed[1]=1;
       state[1]=1; // fired
     }

     pin[2]=(PINC&4);
     if (primed[1] && armmed[1] && pin[2] && (last[2]==0) && state[2]==0) { 
       primed[2]=1;
       state[2]=1; // fired
     }

     pin[3]=(PINC&8);
     if (primed[2] && armmed[3] && pin[3] && (last[3]==0) && state[3]==0) { 
       state[3]=1; // fired
     }
     
       last[0]=pin[0];
       last[1]=pin[1];
       last[2]=pin[2];
       last[3]=pin[3];       
     break;

     // TEST and do different window sizes (how to test?)
   case 5: // X- all trigger events within time window on all sets off all???  // different size of windows below 
     timer++;
     for (u8 x=0;x<4;x++){
       pin[x]=(PINC&(1<<x));
       
       if (pin[x] && (last[x]==0) && state[x]==0) { 
	 timeof[x]=timer;
	 primed[x]=1;
       }
       last[x]=pin[x];       
     }
     // if they are all in 1 second window  =200
     if (primed[0]==1 && primed[1]==1 && primed[2]==1 && primed[3]==1 ){
     if ( (abs(timeof[0]-timeof[1])<200) && (abs(timeof[0]-timeof[2])<200) && (abs(timeof[0]-timeof[3])<200) && (abs(timeof[1]-timeof[2])<200) && (abs(timeof[1]-timeof[3])<200) && (abs(timeof[2]-timeof[3])<200)){
	 state[0]=1; // fire all
	 state[1]=1; // fire
	 state[2]=1; // fire
	 state[3]=1; // fire
	 timeof[0]=0; 	 timeof[1]=0;	 timeof[2]=0;	 timeof[3]=0;
     }
     }
     break;

     // X- trigger on first sets off each in series at successive interval of X, Y, Z(how that is determined?) 1-2-3-4
   case 6:
     pin[0]=(PINC&1);
       if (pin[0] && (last[0]==0) && state[0]==0) { 
	 state[0]=1; // fire all and time next ones
	 timeof[0]=0;
	 primed[0]=1;
       }
       if (primed[0]==1) {
	 timeof[0]++;
	 if (timeof[0]>200) state[1]=1; // 1 second
	 if (timeof[0]>400) state[2]=1; 
	 if (timeof[0]>600) state[3]=1; 
       }
       last[0]=pin[0];
     break;

   case 7:      //X- prime on 1st, measure and fire 2nd and use time for next 2 after each other
     pin[0]=(PINC&1);
       if (pin[0] && (last[0]==0) && state[0]==0) { 
	 state[0]=1; // fire all and time next ones
	 timeof[0]=0;
	 primed[0]=1;
       }
       if (primed[0]==1) {
	 timeof[0]++;
	 pin[1]=(PINC&2);
	 if (armmed[1] && pin[1] && (last[1]==0) && state[1]==0) { 
	   state[1]=1; // fire
	   primed[1]=1;
	   timeof[1]=timeof[0];
	   timeof[0]=0;
	 }
	 if (primed[1]==1 && timeof[0]>timeof[1]) state[2]=1;
	 if (primed[1]==1 && timeof[0]>(timeof[1]*2)) state[3]=1; 
       }
       last[0]=pin[0];
       last[1]=pin[1];
     break;

     case 8:      //X- trigger each one after x second delay... 
     for (u8 x=0;x<4;x++){
       pin[x]=(PINC&(1<<x));
       if (armmed[x] && pin[x] && (last[x]==0) && state[x]==0) { 
	 timeof[x]=0;
	 primed[x]=1;
   }
       if (primed[x] && state[x]==0){
	 timeof[x]++;
	 if (timeof[x]>200) {//1 second delay
	   state[x]=1;
	 }
       }
       last[x]=pin[x];
     }
     break;
    

     
     //
     
     
     /////////////////////////     /////////////////////////     /////////////////////////     /////////////////////////     /////////////////////////
     
   case 14: // also -- for TEST/VIDEO we want to wait 10 seconds/ no trigger - just deal with [0]
       if (armmed[0] && state[0]!=1) { 
	 timer++;
	 if (timer>=2000){ // 2000 is 10 seconds
	   state[0]=1; // fire it
	   state[1]=1; // fire it
	   state[2]=1; // fire it
	   state[3]=1; // fire it
	   timer=0;
	 }
   }
       if (armmed[0]==0) armed=0;
       break;
   } // end switch
   } // end armed
   
   // 22/8/2024 - pulling out ignition from above 
       for (u8 x=0;x<4;x++){

	 if (state[x]==1){ // fired
	   counterr[x]=0;
	   if (x==0) sbi(PORTD,0);
	   else if (x==1) sbi(PORTD,1);
	   else if (x==2) sbi(PORTB,1);
	   else sbi(PORTB,2);
	   state[x]=2; // IGNITION
	 }

	 if (state[x]==2 && armmed[x]==1){ //IGNITION
	 counterr[x]++;
	 if (counterr[x]==pulslength) {
	   if (x==0) cbi(PORTD,0);
	   else if (x==1) cbi(PORTD,1);
	   else if (x==2) cbi(PORTB,1);
	   else cbi(PORTB,2);
	   armmed[x]=0;
	   state[x]=0;
	 }	   
	 }
       }
       if (armmed[0]==0 && armmed[1]==0 && armmed[2]==0 && armmed[3]==0) armed=0;
}

void main(void)
{
  // LEDs: PD4,5,6,7
  // encoder: PD2, PD3
  // encoder switch: PB0
  // pulses out: PD0, PD1, PB1, PB2
  // pulses in: PC0,PC1, PC2, PC3
  DDRB=0b00000110;
  PORTB=0b00000000;
  DDRC=0b00000000;
  PORTC=0b00000000;
  DDRD=0b11110011;  // PD4-7 // PD0,1 lsb at end
  PORTD=0b11110000;

  // setup 200Hz interrupt = 5mS
  cli();
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A=77; // now 77 // was 78 with 1024 divider = 200 HZ!?
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler- was 8 for 8KHz - now 64 for 1Khz=CS22
  TCCR2B |= (1 << CS20);// with cs20=1024   
  TCCR2B |= (1 << CS21);// with cs21=256   
  TCCR2B |= (1 << CS22);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  sei();
  aLastState=(PIND&(1<<3))>>3;

  while(1){
  }
  // flash LEDs test:
    /*
    tmp^=1;
     _delay_ms(100);
    if (tmp) PORTD=0b11110000;
    else PORTD=0;
    */
}    
