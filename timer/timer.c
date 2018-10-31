#include <msp430g2231.h>

main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0xFF;
    int x = 0xFF;
	int mask = 0x7F;
    /*
    */
    for(;;)
    {
		if (~P2IN & 0x01)
		{
			x = 0xFF;
			int mask = 0x7F;
			P1OUT = x;
		} else {				
	    	x = 0xFF;
			int mask = 0x7F;
	    	while (x != 0x00) {
	    		P1OUT = x;
		    	__delay_cycles(250000);
				P1OUT = x & mask;
				__delay_cycles(250000);
				P1OUT = x;
		    	__delay_cycles(250000);
				P1OUT = x & mask;
				__delay_cycles(250000);
				P1OUT = x;
		    	x = x >> 1;
				mask = mask >> 1;
				if (~P2IN & 0x01) {
					break;
				}
	    	}
		}
    }
}

//travailler sur les pointeurs
decrement(x, mask, seconds) {
	int i=0;
	for (i=0;i<seconds;i++) {
		P1OUT = x;
        __delay_cycles(250000);
        P1OUT = x & mask;
        __delay_cycles(250000);
        P1OUT = x;
        __delay_cycles(250000);
        P1OUT = x & mask;
        __delay_cycles(250000);
        P1OUT = x;
	    x = x >> 1;
        mask = mask >> 1;
	}
}
