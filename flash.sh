avrdude --part atmega2560 -cstk500v2 -b115200 -P /dev/ttyACM0 -Uflash:w:"$1":i -v -D
