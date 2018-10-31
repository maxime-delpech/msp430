#include <msp430g2231.h>
main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR |= 0XFF;
    int x = 0X01;
    long i=0;
    int j=1;
    int k=0;
    int l=0;
    /*
     * Mode variable controls the current show
     * 0: back and forth (default)
     * 1: one over two
     * 2: caterpillar
     * 3: caterpillar inverted
     * 4: blink all
     */
    for(;;)
    {

/////////////////////////////////
// back and forth
        for(k=1;k<=5;k++){
		x=0x01;
		for(j=1;j<=8;j++)
		{
			P1OUT = x;
			x*=2;	
			__delay_cycles(50000);
			//for(i=0;i<=10000;i++)
   			{
			}
		}
         	x=0x80;
          	for(j=1;j<=8;j++)
		{
           		P1OUT = x;
            		x/=2;
             		//for(i=0;i<=10000;i++)
			__delay_cycles(50000);
              		{
               		}
              	}

//////////////////////////////
// one over two
        for(k=1;k<=5;k++)
	{
        	P1OUT=0xAA;
        	for(l=0;l<=1;l++)
		{
        		//for(i=0;i<=64000;i++)
			__delay_cycles(50000);
        		{
			}
		}
       		P1OUT=0x55;
       		for(l=0;l<=1;l++)
		{
       			//for(i=0;i<=64000;i++)
			__delay_cycles(50000);
       			{
			}
		}
       	}
	
////////////////////////////////
// caterpilar
        for(k=1;k<=5;k++)
	{
               	P1OUT=0x18;
		__delay_cycles(50000);
               	P1OUT=0x24;
		__delay_cycles(50000);
               	P1OUT=0x42;
		__delay_cycles(50000);
               	P1OUT=0x81;
		__delay_cycles(50000);
        }

///////////////////////////////
// caterpillar inverted
        for(k=1;k<=5;k++)
	{
               	P1OUT=0x81;
		__delay_cycles(50000);
               	P1OUT=0x42;
		__delay_cycles(50000);
              	P1OUT=0x24;
		__delay_cycles(50000);
               	P1OUT=0x18;
		__delay_cycles(50000);
        }

////////////////////////////
// blink
        for(k=1;k<=5;k++)
	{
               	P1OUT=0xFF;
		__delay_cycles(50000);
               	P1OUT=0x00;
		__delay_cycles(50000);
	}
     } 
   }
}

