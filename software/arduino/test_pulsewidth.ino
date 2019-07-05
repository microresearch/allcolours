//#define F_CPU 16000000UL 

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
int x;

void setup() {
  pinMode(0,OUTPUT); //  we always need this
    pinMode(9,OUTPUT); //  we always need this
    pinMode(11,OUTPUT); //  we always need this
    // for pin
    
  cli();//stop interrupts
  // OCR1A is the fast one - 16 bit CTC!
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  TCCR1B= (1<<WGM12) | (1<<CS10);// no pre-scale
  OCR1A=2; //0=8 MHz 

    // 1024= 7 Khz= 7000/100=70Hz 1khz-10Hz in the filter

  // OCR2A is for pulsed envelopes - so fast PWM into low pass filter a la ERD/SIR 
    //    TCCR2A = _BV(COM2A1) | _BV(WGM21); // ctc?
    //    TCCR2B = _BV(CS20); // no prescale
  //    TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM21);
  //    TCCR2B=(1<<CS21) | (1<<CS20);  // divide by 64 for 250KHz
  //    OCR2A=1;
    
  sei();//allow interrupts
}

void loop() {
  // x++;
  //    if (x>255) x=1;
    //    OCR1A=200+x;
    //OCR2A=x;
    //    delay(1);

  PORTD=0; // in main loop this gives us 4 MHz - ON
  //   _delay_us(100); // with 1 uS delay we get 440 KHz
  _delay_ms(1000);
  PORTD=255; // off
   //   _delay_us(1000000);
     _delay_ms(1000);

}