//
// Test program
// - Use this for testing current output in different scenarios.

#define F_CPU 16000000
#define _PWM_DUTY_WEAK 20.f
#define _PWM_DUTY_STRONG 85.f
#define _PWM_FREQ 10000U

#include "drivers/pwm_light.h"
#include <util/delay.h>

const uint32_t delay = 1000;
int main() {
	initLight();

	// Run through all combinations of light output.
	while(1) {
		setFrontLightOn();
		_delay_ms(delay);

		setRearLightMode(LIGHT_WEAK);
		_delay_ms(delay);

		setRearLightMode(LIGHT_STRONG);
		_delay_ms(delay);

		setRearLightMode(LIGHT_OFF);
		_delay_ms(delay);

		setFrontLightOff();
		_delay_ms(delay);

		setRearLightMode(LIGHT_WEAK);
		_delay_ms(delay);

		setRearLightMode(LIGHT_STRONG);
		_delay_ms(delay);

		setRearLightMode(LIGHT_OFF);
		_delay_ms(delay);

	};
	return 0;
}
