/*
 * Erstes.c
 *
 * Created: 25.11.2022 16:13:43
 * Author : JoachimWagner
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

#include "util/delay.h"

#define SET_BIT(port,bit) port|=(1<<bit)
#define CLEAR_BIT(port,bit) port&=~(1<<bit)
#define TOOGLE_BIT(port,bit) port^=(1<<bit)


// gelb 500ms
// rot 1000ms
// rot gelb 500 ms
// gruen 1000 ms

void setup()
{
	// Datadirectionregister für Port B
	//DDRB = 0b00100000; // Gesetztes Bit = Ausgang
	
	DDRB = (1 << DDB5);
	
	//PORTB =0b00100000;
	//PORTB =0x20;
	//PORTB = 32;
	//PORTB = 040; // Octal !!!!
	
	PORTB = (1 << PORTB5)  ;
}


void loop()
{
	//PORTB &= ~(1 << PORTB5);
	CLEAR_BIT(PORTB,PORTB5);
	_delay_ms(1000);
	
	
	//PORTB = 0b00100000;
	SET_BIT(PORTB, PORTB5);
	_delay_ms(500);
}

int main(void)
{
	setup();
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		loop();
		
		
    }
	
	
}

