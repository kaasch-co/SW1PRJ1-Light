mkdir -p build/temp
avr-gcc -B=/usr/avr/include -O3 -Wall -mmcu=atmega2560 -o build/temp/compiled.obj "$@"
avr-objcopy -O ihex build/temp/compiled.obj build/output.hex
