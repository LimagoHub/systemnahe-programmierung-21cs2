/*
 * EingabeMitPolling.c
 *
 * Created: 26.11.2022 11:23:33
 * Author : JoachimWagner
 */ 

#include <avr/io.h>

#define GET_BIT(port,bit) port&(1<<bit)

int main(void)
{
	
	// Port d als Eingang
	DDRD = 0;
	
	// Pullup auf D2 und D3
	PORTD = (1 << PORTD2) | (1 << PORTD3) ;
	
	
	// Bit5 in PORTB als Ausgang
	DDRB = (1 << DDB5);
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		if( ! GET_BIT(PIND, PIND2) ) {
			PORTB = (1 << PORTB5);
		}
			
		if (! GET_BIT(PIND, PIND3) ) {
			PORTB = 0;
		}
    }
}

