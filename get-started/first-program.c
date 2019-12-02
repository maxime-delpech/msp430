#include <msp430.h>

void main(void) {
	int i;

	WDTCTL = WDTPW | WDTHOLD;
	
	P1DIR = 0x01; //LED1 output
	P1DIR |= 0x10; // LED2 output

	for(;;) {
		P1OUT ^= 0x11;

		for(i=0;i<10000;i++) {
		}
	}
}
