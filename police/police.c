#include <msp430.h>

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR |= 0x01;
	P1DIR |= 0x40;

	for (;;) {
		P1OUT |= 0x40;
		__delay_cycles(300000);
		P1OUT &= ~0x40;
		__delay_cycles(10000);
		P1OUT |= 0x01;
		__delay_cycles(300000);
		P1OUT &= ~0x01;
		__delay_cycles(10000);
	}
}
