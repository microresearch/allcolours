#define F_CPU 16000000UL 

/*

//////

- speed question as fastest we can do is say 1 MHz pulse without any processing in interrupt and in asm

/////

1 pulse ins, 1 clock pulse in on each side LF, HF (these 2 are two interrupts PD2, PD3, INT0, INT1) -> all inverted

- modeh CV, model cv, speedl cv, speedh cv - check we have spare ADC!

- always pulses out, DAC out and PWM out.

Shift registers -> pulses out, DAC out, PWM out/DAC style (for each low and high side):

?mode low/mode high? - *thus we need seperate mode knobs*!

- length of SR (16 bits, 32 bits, x bits), shrink and extend, howdo we get to length? -> pulses count length, speed cv is length with pulses as speed
- leaky on/off (leaks on clock pulse so use with CV speed)
- speed/clocking of SR is from CV, or speed follows pulse in/clock
- toggle lock loop on clock/pulse in (speed CV only modes) - or always include it with AND or XOR?
- entry into SR from pulse ins, or as LFSR (random)
- entry into SR from speed CV (as threshold or as ADC?) - means we must use clock as speed cv
- xors back in, no xors back in - and which xors? select by clock pulse?
- sr as pulses or as bits is ONLY a choice on HF side
- which bits form the usual DAC out and the PWM DAC out? wide spaced or close spaced (4 bits for DAC and 8 bits for PWM)
- wild card of SR speed from DAC style SR output?

// HF SR: 32 stages max, LF: 16 or 24 max

recursions: 

SR is clocked by its own HIGH output or logic XOR/AND with clock in, SR usual feedback, SR speed from own DAC out

----> each SR has 1 pulse in, 1 clock pulse in, 2 pulse out and 4 bit DAC out:

pulse ins can leak, switch bits, input bits, select xor bits, select lengths, xor pulse in/not clock with last bit f sr -> input for sr

pulse outs all at different taps (to ins also)

////PWM update in main loop speed???

PWMs low and high so more combinations:

each follows: CV, update DAC(speed by CV or speed from clock), clock

or can mix/combine/logical op one against the other

- pwms follow each speed cv
- pwml follows cv, other is DAC style from SR - and can combine each also say mix DAC and cv
- pwmh follows cv, other is DAC style from SR
- both pwmh and pwml follow DAC style
- speed for DAC style updates is from speed cv for each or speed for DAC updates is from pulse in for each -> speed is same speed as DAC/shiftreg speed!
- pwms follow each clock pulse in for each...

values in array of pointers to avoid any switch routines

*/

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

u16 testing[16]={160,800,128,255,128,250,770,180,290,299,313,230,444,222,110,450};

#define PinVal(Port, Bit, Val)    Port = Val ? Port | (1 << Bit) : Port & ~(1 << Bit);

#define sbi(port,bit) (port)|=(1<<(bit))
#define cbi(port,bit) (port)&=~(1<<(bit))

#define sbi1(ioreg, bitnum) \
             asm(" sbi %0, %1" :: "I"(_SF_IO_ADDR(ioreg)), "I"(bitnum))

uint16_t start_state = 0xACE1u;  /* Any nonzero start state will work. */
uint16_t lfsr = 0xACE1u;
uint16_t bit;                    /* Must be 16bit to allow bit<<15 later in the code */

//uint8_t g_buf[4]={0xff,0xff,0xfa,0xfa}; 

inline uint8_t lfsr32()
{
  static uint32_t shift_register=0xff;;// = (uint8_t *)g_buf;
  uint32_t bit;
  uint8_t carry_out, carry_in;

  
  //shift into 32 bit shift register         
  //  if(shift_register & (1uL<<31))
  //      carry_out=1;
  //  else
  //    carry_out=0;
  //  bit=((shift_register)^binmask32)&0x01;
  bit= ((shift_register >> 31) ^ (shift_register >> 29) ^ (shift_register >> 25) ^ (shift_register >> 24)) & 1u; // 32 is 31, 29, 25, 24
  // try these as bitmasks
      //      printf("bit: %d ", bit);
  //  carry_in = bit;// | carry_out;
  shift_register=shift_register<<1; // we are shifting left << so bit 31 is out last one
  shift_register+=bit;         
  return bit;   //
}

uint8_t shift8bits[4]={0xfa,0xfb,0xaa,0xab};

uint8_t lfsr8() //   // test with 4x 8 bits: - this is faster say 78KHz with -O3
{
  //  uint8_t x;
  //  bit= ((shift_register >> 31) ^ (shift_register >> 29) ^ (shift_register >> 25) ^ (shift_register >> 24)) & 1u; // 32 is 31, 29, 25, 24
  //  bit= ((shift8bits[0]>>7) ^ (shift8bits[0]>>5) ^ (shift8bits[0]>>1) ^ (shift8bits[0]>>0)) & 0x01;
  bit=bit^1;
  
  shift8bits[0]=shift8bits[0]<<1;
  shift8bits[0]|=shift8bits[1]>>7;

  shift8bits[1]=shift8bits[1]<<1;
  shift8bits[1]|=shift8bits[2]>>7;

  shift8bits[2]=shift8bits[2]<<1;
  shift8bits[2]|=shift8bits[3]>>7;

  shift8bits[3]=shift8bits[3]<<1;  
  shift8bits[3]|=bit;

  // try to translate into assembly inline
  
  return bit; //
}

ISR(INT0_vect) // doesn't run faster than 444 KHz - pin2 PD2
{
  //    PORTB=1; //pin 8 PB0
  //    PORTB=0;
  //  PinVal(PORTB, 0, 1);
  //  PinVal(PORTB, 0, 0);  
}

ISR(INT1_vect) // doesn't run faster than 444 KHz - pin3 PD3
{
  //  PORTB=1; //pin 8 PB0
  //  PORTB=0;
  //  PinVal(PORTD, 0, 1); // pin PD0 = 0
  //  PinVal(PORTD, 0, 0);  
}

/*ISR (__vector_14)
{
  PINB |= 1;
  }*/

 /*
SIGNAL(TIMER0_COMPA_vect) // again around 444 KHz speed 
{

  // test toggle pin 8 PB0
  //    PORTB=1; // in main loop this gives us 4 MHz
  //    PORTB=0;
  //  OCR0A = 0x0F; // 0xOF should be 1 MHz - but fastest we go is 444 Khz = 4K filter  

  //    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
  //    lfsr =  (lfsr >> 1) | (bit << 15);
  //    PinVal(PORTB, 0, bit); // pin 8 on arduino / basic SR out with no IN...
  // or bit as very short pulse is nicer but only for HF!
  //  PORTB=lfsr32(); // noise is not fast enough
  //  PORTB=lfsr8(); // noise is not fast enough

  
  //  bit=lfsr8(); //
  //    PORTB=1; // 442KHz // 471KHz witjout OCR0A above
  //    PORTB=0;
  //    PORTB |= _BV(0);   // 515/520 KHz    -> 757 K with sei
  //    PORTB &= ~(_BV(0));
  //  PINB=1;
  //  PINB=0;
  //  sbi(PINB,0);
  //  cbi(PINB,0);
  
  //  PORTB=0;
  PINB |= 1; // fastest square wave 420 KHz
  //  sbi1(PORTB,0);
    sei(); // with this rises to 729 KHz
}
 */

void setup() {
  /*  pinMode(0,OUTPUT); //  we always need these
  pinMode(7,OUTPUT); 
  pinMode(8,OUTPUT); 
  pinMode(9,OUTPUT); 
  pinMode(11,OUTPUT);
  */

  // for c/no arduino
  DDRD=0x80; // PD7 pin 7
  DDRB=0x0b;

  cli();//stop interrupts

  // we have 3 timers and 2 are used for PWm, one for interrupts which runs at 1Khz
  
  // OCR1A is the fast one - 16 bit CTC!
  TCCR1A= (1<<COM1A0);// | (1<<WGM11) | (1<<WGM10); // KEEP AS CTC for filter
  TCCR1B= (1<<WGM12) | (1<<CS10);// no pre-scale
  OCR1A=64; // 0=8 MHz // start at 8 for around 1MHz=10K filter

  // OCR2A is for pulsed envelopes - so fast PWM into low pass filter a la ERD/SIR 
    //    TCCR2A = _BV(COM2A1) | _BV(WGM21); // ctc?
    //    TCCR2B = _BV(CS20); // no prescale
  //    TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM21);
  //    OCR2A=1;

  
  //interrupt at full speed to change pwm = timer0
    TCNT0=0;
    TCCR0A= (1<<WGM01); // CTC mode clear on compared match
    TCCR0B= (1<<CS00); // no divider
    //TCCR0B=((1<<CS01) | (1<<CS00));  // divide by 64 - tested for SR but run fast and divide for LF
    TIMSK0 |= _BV(OCIE0A); // enable timer0 overflow interrupt
    OCR0A = 0x0f; // 0xOF should be 1 MHz - but fastest we go is 444 Khz = 4K filter  - fastest in assembly is 1 MHz more or less
  
    // 1024= 7 Khz= 7000/100=70Hz 1khz-10Hz in the filter

  // set up interrupt INT0 on pin PD2 which is arduino pin 2

    // but as inverted we want falling edge and also INT1 - test this
     
    EICRA |= ((1 << ISC01) | (1 << ISC11)); // for clocks in - falling edge triggers INT0 and INT1
    EIMSK |= ((1 << INT0) | (1 << ISC01)); // Enable INT0 and INT1 interrupt, will call INT0_vect ISR when INT0 fires... etc
  
          sei();//allow interrupts
}

void main() {

  setup();

  while(1){
  //  PORTB |= _BV(0);   // 515/520 KHz    
  //  PORTB &= ~(_BV(0));
  }
  
  // mode and speed ADC readings

  // slow/LF SR and all PWM updates...

  //  PORTB=lfsr32(); // noise is not fast enough // test in main
  
  //   x--;
   //   if (x<8) x=256;
   //         OCR1A=x*4;
   //  OCR1A=x;
   //   delay(10);

  // read modes and adjust accordingly
  
  // PORTD=255; // in main loop this gives us 4 MHz - ON
  // with fast timer interrupt this drops to 119 KHz
  //  _delay_ms(1000);
  //  PORTD=0; // off
  //  _delay_us(1); // with 1 uS delay we get 440 KHz
   //   _delay_us(1000000);
  //     _delay_ms(1000);

}
