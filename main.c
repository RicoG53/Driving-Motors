/*
 * DrivingMotors.c
 *
 * Created: 11/17/2022 6:37:44 PM
 * Author : Rico
 
 * motor runs at 100% speed for ten sec, then 50% for ten, then 75% for ten, and then 25% for ten seconds
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    // pwm setup wgm 001, COM0A 10, prescalar cs 101
	TCCR0A |= (1<<COM0A1 | 1<<WGM00);
	TCCR0B |= (1<<CS02 | 1<<CS00);
	TIMSK0 |= (1<<OCIE0A);
	
	
	
    while (1) 
    {
		// 100%, 50%, 75%, 25%
		OCR0A = 0; // sets pwm dc at 100% 
		_delay_ms(10000);
		OCR0A = 127.5; // sets pwm dc at 50%
		_delay_ms(10000);
		OCR0A = 63.75; // sets pwm dc at 75%
		_delay_ms(10000);
		OCR0A = 191.25; // sets pwm dc at 25%
		_delay_ms(10000);
    }
}

