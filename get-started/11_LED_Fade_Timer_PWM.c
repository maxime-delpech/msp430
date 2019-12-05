#include <msp430.h> 

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
	//Configure P1.6 to be controlled by Capture/Compare module
	P1DIR|=BIT6;
	P1OUT&=~(BIT6);
	P1SEL|=BIT6;
	TACCR0=10000; //Setting up the PWM Frequency
	TACCR1=0; //Initialising the Duty cycle to 0
	TACCTL1|=OUTMOD_7; //Using Reset/Set mode to generate PWM wave
	TACTL|=TASSEL_2+MC_1; //Configuring the timer to use SMCLK and count in UP mode

	int pwm=0,l=100; //Initializing required variables
	while(1)
	{   
		__delay_cycles(5000); //Wait before changing the duty cycles, for smooth variation
		pwm+=l; //Change the duty cycle
		if(pwm==10000) l=-100;//If duty cycle is at maximum, start decreasing it
		if(pwm==0) l=100; //If duty cycle is at minimum, start increasing it
		TACCR1=pwm; //Set the duty cycles in the Capture/compare module
	}
	return 0;
}

/*
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TMR0()
{
	if(TAIV==TA0IV_TAIFG)
	{ 
		count++;
		if(count==10)
		{
			count =0;
			pwm+=v;
		if(pwm==10000) v=-1000;
		if(pwm==0) v=1000;
		TACCR1=pwm;
		}
	}
}
*/
