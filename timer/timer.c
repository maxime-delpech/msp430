#include <msp430g2231.h>
#include <math.h>

main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0XFF;
    int x = 0X01;
    /*
    */
    for(;;)
    {
	    x = 0xFF;
	    while (x != 0x00) {
	    	P1OUT = x;
	    	__delay_cycles(1000000);
	    	x = x >> 1;
	    }
    }
}