// Test program

#define F_CPU 16000000

#include "drivers/pwm_light.h"
#include <util/delay.h>

int main() {
	initLight();

	while(1) {
		setFrontLightOn();
		_delay_ms(500);

		setRearLightMode(LIGHT_WEAK);
		_delay_ms(500);

		setRearLightMode(LIGHT_STRONG);
		_delay_ms(500);

		setRearLightMode(LIGHT_OFF);
		_delay_ms(500);

		setFrontLightOff();
		_delay_ms(500);

		setRearLightMode(LIGHT_WEAK);
		_delay_ms(500);

		setRearLightMode(LIGHT_STRONG);
		_delay_ms(500);

		setRearLightMode(LIGHT_OFF);
		_delay_ms(500);

	};
	return 0;
}
