#include <msp430.h>
#include <stdlib.h>

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = BIT6;
	P1SEL = BIT6;
	//P1DIR = 0x01;
	TACCR0 = 0x0100;
	TACCR1 = 0;
	TACCTL1 = OUTMOD_7;
	TACTL   = TASSEL_2 + MC_1;
	P1REN = BIT3;
	P1OUT = BIT3;

	unsigned int pwm = 0;
	for (;;) {
		if ((P1IN & BIT3) != BIT3) {
			switch (TACCR0) {
				case 0x1000:
					TACCR0 = 0x0100;
					break;
				case 0x0100:
					TACCR0 = 0x0080;
					break;
				case 0x0080:
					TACCR0 = 0x0010;
					break;
				case 0x0010:
					TACCR0 = 0x1000;
			}
		}

		pwm = (rand() >> 3);
		TACCR1 = pwm;
		//if (pwm > 2048) {
		if (pwm > 256) {
			__delay_cycles(20000);
		} else {
			__delay_cycles(75000);
		}
	}
	return 0;
}
