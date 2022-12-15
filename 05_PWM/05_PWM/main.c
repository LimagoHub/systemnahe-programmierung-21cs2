/*
 * 05_PWM.c
 *
 * Created: 10.02.2018 14:50:01
 * Author : Joachim
 */ 

// this code sets up counter0 for an 8kHz PWM wave @ 16Mhz Clock

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void pwm_loop(uint8_t direction) {
	for (uint8_t duty = 0; duty < 0xff; duty++)
	{
		OCR0A = direction ? duty: 0xff - duty;
		_delay_ms(10);
	}
}


int main(void)
{
	
	// Datadirection Pin D6 als Ausgang
	DDRD |= (1 << DDD6);

	OCR0A = 0xff;  // 256 * Duty / 100
	// set PWM for 75% duty cycle


	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= /*(1 << WGM02) | (1 << WGM01)  |*/ (1 << WGM00);
	// set fast PWM Modehttps://www.amazon.de/?tag=amz-mkt-chr-de-21&ascsubtag=1ba00-01000-org00-win10-other-nomod-de000-pcomp-feature-scomp-feature-scomp&ref=aa_scomp

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
	
	uint8_t direction = 0;
	
	while (1)
	{
		pwm_loop(direction = ! direction);
		
	}
}
