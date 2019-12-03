#include <msp430.h>

void main(void) {
	WDTCTL = WDTPW + WDTHOLD;     // Stop WDT  

	P1DIR = BIT0;
	P1OUT = 0x01;
	
	CCTL0 = CCIE;
	TACTL = TASSEL_2 + MC_1 + ID_3;
	TACCR0 = 0xFFFF;
	TACCR1 = 0x00FF;

	int pwm=0,l=100;
	while(1)
	{
	pwm+=l; //Change the duty cycle
    if(pwm==10000) l=-100;//If duty cycle is at maximum, start decreasing it
    if(pwm==0) l=100; //If duty cycle is at minimum, start increasing it
    TACCR1=pwm; //Set the duty cycles in the Capture/compare module
	}
}

// Timer A0 interrupt service routine 
#pragma vector=TIMER0_A1_VECTOR 
__interrupt void Timer_A (void) 
{   
	P1OUT ^= BIT0;                          // Toggle P1.0 
} 
