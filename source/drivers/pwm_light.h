#pragma once

enum LightPowerMode {
	LIGHT_OFF,
	LIGHT_WEAK,
	LIGHT_STRONG
};

void initLight(void);
void setFrontLightOn(void);
void setFrontLightOff(void);
void setRearLightMode(enum LightPowerMode);
