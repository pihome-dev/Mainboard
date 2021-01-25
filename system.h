// SYSTEM
#define F_CPU 12000000UL			// Systemfrequency

// I2C
#define SCL_CLOCK  100000L			// I2C Clock

// UART
#define UART_BAUD_RATE 57600		// UART Baudrate
//#define UART_BAUD_RATE 115200	// UART Baudrate

// Timer
#define TIMERFREQ		10				// Timerfrequenz in ms
#define TIMERPRE		256			// Timer Prescaler

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdint.h>
#include <avr/eeprom.h>
#include <stdio.h>
#include <string.h>

#include <compat/twi.h>

#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/crc16.h>

#include <util/delay.h>

#include "uout.h"
#include "pins.h"
#include "timer.h"
#include "uart.h"
#include "sensoren.h"
#include "adc.h"
#include "boards.h"
#include "i2cmaster.h"
#include "sysled.h"
#include "bme280.h"

void avrrestart(void);

volatile uint16_t sysTimer;
volatile int output_enabled;

char buf[40];