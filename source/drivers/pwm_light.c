#include "pwm_light.h"
#include "pwm.h"
#include <avr/io.h>

#define _PWM_DUTY_WEAK 15.0f
#define _PWM_DUTY_STRONG 67.0f
#define _PWM_FREQ 10000U


void initLight() {
	DDRB |= (1 << PB6); // Set Port B Pin 6 (OC1B) as output to control headlights
	
	// Init PWM for rear lights - Timer1 is used by the driver
	initPWM(_PWM_DUTY_WEAK, _PWM_FREQ);
	return;
}

void setFrontLightOn() {
	// Set Pin6 on PORTB high, maintain other pin states
	PORTB = (1 << PB6) | PORTB;
	return;
}

void setFrontLightOff() {
	// Set Pin6 on PORTB low, maintain other pin states
	PORTB = (0 << PB6) & PORTB;
	return;
}

void setRearLightMode(enum LightPowerMode powerMode) {
	switch (powerMode) {
		case LIGHT_OFF:
		setDutyCycle(0);
		break;

		case LIGHT_WEAK:
		setDutyCycle(_PWM_DUTY_WEAK);
		break;

		case LIGHT_STRONG:
		setDutyCycle(_PWM_DUTY_STRONG);
		break;
	}
	return;
}
