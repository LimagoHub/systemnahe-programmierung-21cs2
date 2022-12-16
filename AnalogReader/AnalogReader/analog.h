/*
 * analog.h
 *
 * Created: 16.12.2022 14:22:25
 *  Author: JoachimWagner
 */ 


#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void analog_init();
uint16_t analog_read(uint8_t channel) ;