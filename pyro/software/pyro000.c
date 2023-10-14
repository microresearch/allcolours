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

void main(void)
{
  unsigned char tmp=0, armed=0, former=0;
  //  adc_init();

  static int counter = 0; 
  int aState;
  static int aLastState=0;
  static u8 mode;
  static u8 last[4]={0,0,0,0}, pin[4]={0,0,0,0};
  // LEDs: PD4,5,6,7
  // encoder: PD2, PD3
  // encoder switch: PB0
  // pulses out: PD0, PD1, PB1, PB2
  // pulses in: PC0,PC1, PC2, PC3
  DDRB=0b00000110;
  PORTB=0b00000000;
  DDRC=0b00000000;
  DDRD=0b11110011;  // PD4-7 // PD0,1 lsb at end
  aLastState=(PIND&(1<<3))>>3;
  PORTD=0b11110000;
  
  while(1){
  // flash LEDs test:
    /*
    tmp^=1;
     _delay_ms(100);
    if (tmp) PORTD=0b11110000;
    else PORTD=0;
    */
    
    /* TODO:
    - DONEport encoder: pins PD2, PD3 and switch is PB0 - A is ENC1, B is ENC0 // test switch also
    - DONEtriggers tested with LED
    - test triggering of igniter: 0-3 is PD0, PD1, PB1, PB2
    - DONEtest input trigger signals: PC0-PC3 - tested!
    - modes to sketch and test
     */

    aState=(PIND&(1<<3))>>3;
     if ((aLastState == 1) && (aState == 0)) {       // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
       if (((PIND&(1<<2))>>2) != aState) { 
       counter ++;
     } else {
       counter --;
     }
       if (counter<0) counter=15;
       if (counter>15) counter=0;
     }
   aLastState = aState; 
   // show bottom bits on LEDs
   if (PINB&1 && former==0) {
     armed^=1;
   }
   former=PINB&1;
   _delay_ms(1);
   
   if (armed)  {
     PORTD=counter<<4; // test switch
   }
   else PORTD=0;

   
   //  DONE  - test triggering of igniter: 0-3 is PD0, PD1, PB1, PB2
   pin[0]=(PINC&1);
   if (armed && pin[0] && (last[0]==0)) { // we just want leading edge...
     sbi(PORTB,1);
     _delay_ms(100);
     cbi(PORTB,1);
   }
   last[0]=pin[0];
  } // while
}    
