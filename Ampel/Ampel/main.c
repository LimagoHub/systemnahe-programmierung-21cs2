/*
 * Ampel.c
 *
 * Created: 26.11.2022 10:17:42
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



#define RED 0b00000100
#define RED_YELLOW 0b00000110
#define YELLOW 0b00000010
#define GREEN 0b00000001


inline void set_trafficlight_color_to(uint8_t color) {
	PORTB = color;
} 


void setup()
{
	// Datadirectionregister für Port B
	//DDRB = 0b00100000; // Gesetztes Bit = Ausgang
	
	DDRB = (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
	
	set_trafficlight_color_to(YELLOW);
}


void loop()
{
	set_trafficlight_color_to(YELLOW);
	_delay_ms(500);
	
	set_trafficlight_color_to(RED);
	_delay_ms(2000);
	
	set_trafficlight_color_to(RED_YELLOW);
	_delay_ms(500);
		
	set_trafficlight_color_to(GREEN);
	_delay_ms(2000);
	

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