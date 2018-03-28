/*

- leaky or mutating shift register and/or control of 7400

- pulse out, primitive DAC out, clock out to 7400

- CV in incoming bit or set of bits to shift and/or value for clock out, CV pulse in to lock/unlock, slew for clock out/cv in, extra as speed of shifting?
- pulse in to shift... purpose of shifting ...
- larger speed shifts for filter are important so maybe look at dividers and changing these with CV
- knob mode for leak etc

start to list modes:

1-> various shift register implementations in pulse/bit and speed as
speed/skew CV/knob - OUT is pulse/bit and/or DAC out and OUT is 7400
clock/PWM OUT from shift reg taps ...

2-> various shift register implementations in as pulse/bit (from CV -
threshold) and speed as speed/skew CV/knob - OUT is pulse/bit and/or
DAC out and in CV controls 7400 clock/PWM OUT and is skewed by
speed/skew CV/knob

3-> various shift register implementations in pulse/bit and speed as
speed/skew CV/knob - OUT is pulse/bit and/or DAC out and in pulse
controls 7400 clock/PWM out

other modes?

we can xor and other ops CV and shift reg/pulse/DAC to 7400 CLOCK

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

void pwm_init(void){ // pwm TEST! - from original microbdinterp but there we change TCCR1B - what is output pin?
  // what range we can get?
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  TCCR1B= (1<<WGM12) | (1<<CS11);// divide by 8 which gives?
  OCR1A=128; // ??
}

void io_setup(void){
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
