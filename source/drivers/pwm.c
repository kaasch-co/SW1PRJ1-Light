#ifndef F_CPU
#define F_CPU 16000000U
#endif

#define TOP(pre, hz) (uint16_t)(F_CPU / (pre * hz)) - 1
#define COMP(top, dc) (uint16_t)(top * (dc / 100.0f))

#include "pwm.h"
#include <avr/io.h>
#include <stdint.h>

// Timer prescaler - 8 suits a frequency range of 31Hz - 65535Hz.
// CS11 of TCCR1B needs to be set accordingly if changed
static const uint8_t PRESCALER = 8;

float pwm_duty_cycle;
uint32_t pwm_frequency;
uint16_t pwm_top;
uint16_t pwm_comp;

void initPWM(float duty_cycle, uint32_t freq) {
	pwm_duty_cycle = duty_cycle;
	pwm_frequency = freq;

	// Calculate TOP and COMP based on inputs and prescale factor
	pwm_top = TOP(PRESCALER, freq);
	pwm_comp = COMP(pwm_top, duty_cycle);

	// Setup Timer1 and Pin
	DDRB |= (1 << PB5);	// Set port b pin 5 as output (OC1A on ATMega2560)

	TCCR1A = (1 << COM1A1) | 	// Compare Output Mode Channel A = Clear OC1A on compare match
			 (1 << WGM11);		// Timer Mode = Fast PWM, TOP = ICR1
	
	TCCR1B = (1 << WGM13) |		// ^
			 (1 << WGM12) | 	// ^
			 (1 << CS11); 		// Prescaler = 8
	
	ICR1 = pwm_top;	// Set Timer1 TOP to calculated TOP value
	OCR1A = pwm_comp; // Set Timer1 COMP to calculated COMP value
	return;
}

void setDutyCycle(float duty_cycle) {

	// safe guards
	if (duty_cycle > 100.0f) {
		duty_cycle = 100.0f;
	}

	if (duty_cycle < 0.0f) {
		duty_cycle = 0.0f;
	}

	// set globals
	pwm_duty_cycle = duty_cycle;
	pwm_comp = COMP(pwm_top, duty_cycle);

	// set new compare value
	OCR1A =	pwm_comp;
	return;
}

void setFrequency(uint32_t freq) {
	
	// safe guards
	if (freq < 31) {
		freq = 31;
	}

	// set globals
	pwm_frequency = freq;
	pwm_top = TOP(PRESCALER, freq);
	pwm_comp = COMP(pwm_top, pwm_duty_cycle);

	// set new top and comp - this will affect the signal until next
	// timer cycle.
	ICR1 = pwm_top;
	OCR1A = pwm_comp;
	return;
}
