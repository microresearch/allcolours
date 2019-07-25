#include <avr/io.h>

.global TIMER0_COMPA_vect
TIMER0_COMPA_vect:
	out _SFR_IO_ADDR(PORTB),0 // this is  1MHz rather than sbi..
	out _SFR_IO_ADDR(PORTB),1
	reti
