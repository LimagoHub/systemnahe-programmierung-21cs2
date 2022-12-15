/*
 * Seriell.c
 *
 * Created: 15.12.2022 15:36:27
 * Author : JoachimWagner
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1


int main(void)
{
	// Baudrate 
	UBRR0H = MYUBRR >> 8;
	UBRR0L = MYUBRR;
	
	// RX Datenempfang aktivieren TX Datensenden aktivieren (DDR nicht notwendig)
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0); 
	 
	//Protokoll
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Set frame: 8data, 1 stp
	
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	
	sei();
	
	
    /* Replace with your application code */
    while (1) 
    {
		//while ( !(UCSR0A & (1 << UDRE0)) )
		//{
			//// OK
		//}
		//UDR0 = 'A';
		//_delay_ms(100);
    }
}

ISR (USART_RX_vect) {
	char value = UDR0;
	UDR0 = value;
}