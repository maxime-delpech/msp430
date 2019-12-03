#include <msp430.h>

void main(void) {
	int i;

	WDTCTL = WDTPW | WDTHOLD;
	
	P1DIR = 0x01; //LED1 output
	P1DIR |= 0x40; // LED2 output
	P1OUT = 0x01; // set all outputs to false

	for(;;) {
		P1OUT ^= 0x41;

		for(i=0;i<0xFFFF;i++) {
		}
	}
}
