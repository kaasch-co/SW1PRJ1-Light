# Driver and Module for PWM Light control with ATMega2560
For the SW1PRJ1 course at Aarhus University.

## Requirements:
* Microchip AVR Headers (located in `/usr/avr/include/` on some distros)
* avrdude
* avr-gcc

### Windows specific:
If you use Microchip Studio, you already have the AVR headers and avr-gcc.
You will only need to acquire and setup avrdude.

### Linux specific:
Scripts for building and flashing through USB are provided. 
May need to be tweaked for different systems.

## Usage:
The PWM signal uses Timer1 and PB5 pin as output.
The headlight switch uses PB6 pin as output.
Build `light_test.c` and the drivers for a simple light and current test.
Include the drivers in your own source code.
