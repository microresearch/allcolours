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

#define BV(bit) (1<<(bit)) // Byte Value => converts bit into a byte value. One at bit location.
#define cbi(reg, bit) reg &= ~(BV(bit)) // Clears the corresponding bit in register reg
#define sbi(reg, bit) reg |= (BV(bit))              // Sets the corresponding bit in register reg


// set up adc, inputs, outputs and PWM out

void adc_init(void)
{
	cbi(ADMUX, REFS1);
	sbi(ADMUX, REFS0); // AVCC
	sbi(ADMUX, ADLAR); //8 bits
	sbi(ADCSRA, ADPS2);
	//	sbi(ADCSRA, ADPS1); // change speed here! now div by 64
	//	sbi(ADCSRA, ADPS0); // change speed here!

	sbi(ADCSRA, ADEN);
	sbi(ADCSRA, ADIE);
}

void pwm_init(void){ // pwm TEST! - from original microbdinterp but there we change TCCR0A - what is output pin?
  // 16 bit counter? - PB1 pin 1 on PORT B = pin 13 = pin 9 on arduino uno
  // what range we can get - at 8MHz no prescale ocr11=10 gives 700 KHz which is 7k cutoff - we will run at 16MHz
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  //  TCCR1B= (1<<WGM12) | (1<<CS11);// divide by 8 which gives 1MHz on 8MHz chip
    TCCR1B= (1<<WGM12) | (1<<CS10);// cs11-divide by 8 which gi // cs10 = no prescalar
  OCR1A=100; // divide by 8 = 1MHz this gives us 100 KHz so corner of 1 KHz
}

void io_setup(void){
  DDRB=0xff;
  DDRC = 0x00;
  PORTC = 0x00; // for ADC above

  // pwm out??, pulse in, pulse out and DAC out
  
}

unsigned char adcread(unsigned char channel){
  unsigned char result, high;
  ADMUX &= 0xF8; // clear existing channel selection                
  ADMUX |=(channel & 0x07); // set channel/pin
  ADCSRA |= (1 << ADSC);  // Start A2D Conversions 
  loop_until_bit_is_set(ADCSRA, ADIF); /* Wait for ADIF, will happen soon */
  result=ADCH;
  return result;
}


// set shift conditions

// run according to mode

void setup(){
  x=10;
  io_setup();
  adc_init();
  pwm_init();
}

void loop()
{
    x++;
    if (x>1024) x=10;
    OCR1A=x;
    delay(1);
}