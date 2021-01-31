TARGET=system
MCU=atmega128
SOURCES=source/system.c source/uart.c source/i2cmaster.c source/timer.c source/sensoren.c source/adc.c source/boards.c source/sysled.c source/uout.c source/uin.c source/eeprom.c source/light.c source/bme280.c source/systemclock.c

PROGRAMMER=usbasp

LFUSE=0xF7
HFUSE=0xC1
EFUSE=0xFC
#auskommentieren für automatische Wahl
#PORT=-P/dev/ttyS0
#BAUD=-B115200

#Ab hier nichts verändern
OBJECTS=$(SOURCES:.c=.o)
CFLAGS=-c -Os -DF_CPU=16000000UL
LDFLAGS=

all: hex eeprom

hex: $(TARGET).hex

eeprom: $(TARGET)_eeprom.hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $(TARGET).elf $(TARGET).hex

$(TARGET)_eeprom.hex: $(TARGET).elf
	avr-objcopy -O ihex -j .eeprom --change-section-lma .eeprom=1 $(TARGET).elf $(TARGET)_eeprom.hex

$(TARGET).elf: $(OBJECTS)
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) $(OBJECTS) -o $(TARGET).elf

.c.o:
	avr-gcc $(CFLAGS) -mmcu=$(MCU) $< -o $@

size:
	avr-size --mcu=$(MCU) -C $(TARGET).elf

program:
	avrdude -p $(MCU) -c $(PROGRAMMER) -B 5 -Uflash:w:$(TARGET).hex:a

clean_tmp:
	rm -rf *.o
	rm -rf *.elf

clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.hex
	
	rm -rf source/*.o
	rm -rf source/*.elf
