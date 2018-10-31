#include <msp430g2553.h>

int round(int n) {
	return (int) n - n%1;
}

void decrement(int *adr_x, int *adr_mask, int seconds) {
	int i=0;
	for(i=0;i<seconds-1;i++)
	{
   		P1OUT = *adr_x & *adr_mask;
	    __delay_cycles(250000);
		P1OUT = *adr_x;
    	__delay_cycles(250000);
    	P1OUT = *adr_x & *adr_mask;
    	__delay_cycles(250000);
		P1OUT = *adr_x;
    	__delay_cycles(250000);
	}
	*adr_x = *adr_x >> 1;
    *adr_mask = *adr_mask >> 1;
}

void bip(final, number) {
	int i=0;				//counter
	if (final) { 			//final = long bip
		P2OUT = 0x02;
		__delay_cycles(1000000);
		P2OUT = ~0x02;
	} else {
		for(i=0;i<number;i++) {	
			P2OUT = 0x02;
			__delay_cycles(150000);
			P2OUT = ~0x02;
			__delay_cycles(150000);
		}
	}
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0xFF;			//all P1x are outputs
	P2DIR |= 0x02;			//P2.1 output
	int i=0;				//counter
    int x = 0xFF;			//hexa value to manage leds
	int *adr_x = &x;		//pointer to x
	int mask = 0x7F;		//mask to manage the blink
	int *adr_mask = &mask;	//pointer to mask
	int DURATION = 60;		//total duration of timer
	int duration_led = round(DURATION/8); //duration per led

	P1OUT = 0xFF;
	while(P2IN & 0x01) {
	}

    for(;;)
    {
	   	x = 0xFF;
		mask = 0x7F;
		bip(0,1);

	   	for(i=0;i<8;i++) {
			decrement(adr_x, adr_mask, duration_led);
			if (i==3) {
				bip(0,3);
			}
		}
		bip(1,0);
    }
	return 0;
}

