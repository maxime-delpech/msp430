#include <msp430g2231.h>

void decrement(int *adr_x, int *adr_mask, int seconds) {
	int i=0;
	for (i=0;i<seconds;i++) {
		P1OUT = *adr_x;
        __delay_cycles(250000);
        P1OUT = *adr_x & *adr_mask;
        __delay_cycles(250000);
        P1OUT = *adr_x;
        __delay_cycles(250000);
        P1OUT = *adr_x & *adr_mask;
        __delay_cycles(250000);
	    *adr_x = *adr_x >> 1;
        *adr_mask = *adr_mask >> 1;
	}
}

main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0xFF;
    int x = 0xFF;
	int *adr_x = &x;
	int mask = 0x7F;
	int *adr_mask = &mask;
    /*
    */
    for(;;)
    {
		if (~P2IN & 0x01)
		{
			x = 0xFF;
			mask = 0x7F;
			P1OUT = x;
		} else {				
	    	x = 0xFF;
			mask = 0x7F;
	    	while (x != 0x00) {
				decrement(adr_x, adr_mask, 1);
				if (~P2IN & 0x01) {
					break;
				}
	    	}
		}
    }
}

