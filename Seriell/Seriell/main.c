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
#include "uart.h"
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <stdlib.h>


int main(void)
{
	uart_init(9600);
	sei();
	
	
    /* Replace with your application code */
    while (1) 
    {
		uart_send_int(1000);
		uart_send_string_ln("");
		
		_delay_ms(100);
    }
}

ISR (USART_RX_vect) {
	char value = UDR0;
	UDR0 = value;
}