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
int x=0, y=0;

u8 testing[16]={160,800,128,255,128,250,770,180,290,299,313,230,444,222,110,450};

// Interrupt is called once a millisecond, 
SIGNAL(TIMER0_COMPA_vect) 
{
  y++;
  if (y==160) {
  y=0;
  x++;
  if (x>16) x=0;
  OCR1A=testing[x];
  }
  
}

void setup() {
  pinMode(0,OUTPUT); //  we always need this
  pinMode(9,OUTPUT); //  we always need this
  pinMode(11,OUTPUT); //  we always need this
    // for pin
    
  cli();//stop interrupts

  // we have 3 timers and 2 are used for PWm, one for interrupts which runs at 1Khz
  
  // OCR1A is the fast one - 16 bit CTC!
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  TCCR1B= (1<<WGM12) | (1<<CS10);// no pre-scale
  OCR1A=32; //0=8 MHz // start at 8 for around 1MHz=10K filter

// interrupt at 1KHz to change pwm = timer0

  OCR0A = 0xAF;
  TCCR0B= (1<<CS01) | (1<<CS00); // 64 divisor = 1 millisecond
  TIMSK0 |= _BV(OCIE0A); // enable timer0 overflow interrupt

  
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
  //   x--;
   //   if (x<8) x=256;
   //         OCR1A=x*4;
   //  OCR1A=x;
   //   delay(10);

  //  PORTD=0; // in main loop this gives us 4 MHz - ON
  //   _delay_us(100); // with 1 uS delay we get 440 KHz
  //  _delay_ms(1000);
  //  PORTD=255; // off
   //   _delay_us(1000000);
  //     _delay_ms(1000);

}