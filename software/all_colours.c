/*

 *Leaky or mutating shift register and/or CV control of 7490*

- many pulse ins, logic ins and outs, clock in (interrupt INT), output pulses for each SR stage...

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

#define PinVal(Port, Bit, Val)    Port = Val ? Port | (1 << Bit) : Port & ~(1 << Bit);

uint16_t start_state = 0xACE1u;  /* Any nonzero start state will work. */
uint16_t lfsr = 0xACE1u;
uint16_t bit;                    /* Must be 16bit to allow bit<<15 later in the code */
unsigned char biit=0x05;

// interrupt for clock IN - rising edge on INT0 - pin PD2, pin 2 on Arduino UNO

ISR(INT0_vect) // basic 16 stage shift register - left shifts and its speed

{
  // shift it through and output
  bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
  lfsr =  (lfsr >> 1) | (bit << 15);
  // bit on pin PD3
  PinVal(PORTD, PD3, bit); // pin 3 on arduino / basic SR out with no IN...

  // update PWM with lfsr bits
  OCR1A=lfsr;
}

/* 

- how to stop finger interference on pulse in - test with comparator

also 10k to GND here on IN

- that this interrupt in some modes can perform CV update of clock OUT/PWM
- test speed of shift reg operations and speed of PWM out
- where do we do XOR etc... as is unclocked/clocked operation

- test and document range of speeds we have with OCR1A and dividers as is...

- start to define modes...

*/



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
  // 16 bit counter? - PB1 pin 1 on PORT B = pin 13 OC1A
  // what range we can get?
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  //  TCCR1B= (1<<WGM12) | (1<<CS11);// divide by 8 which gives 1MHz == 10KHz for filter so maybe keep it higher/no divide... or different modes
  TCCR1B= (1<<WGM12) | (1<<CS10); // no divider
  OCR1A=100; // ?? 16 bits?
}

void io_setup(void){
  DDRC = 0x00;
  PORTC = 0x00; // for ADC above

  // pwm out??, pulse in, pulse out 

  // for pulse in 

  //  DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
  DDRD = 0b00001010;
  EICRA |= ((1 << ISC01) | (1 << ISC00)); // Rising edge of INT0 will fire the ISR - this is for clock in
  EIMSK |= (1 << INT0); // Enable INT0 interrupt, will call INT0_vect ISR when INT0 fires
  sei();               // Enable global interrupts
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

void main(){
  io_setup();
  adc_init();
  pwm_init();

  while(1){
  }
}
