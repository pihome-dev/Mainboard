// SYSTEM
#define F_CPU 16000000UL			// Systemfrequency

// I2C
#define SCL_CLOCK  100000L			// I2C Clock

// UART
#define UART_BAUD_RATE 115200	// UART Baudrate

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

#include "uart.h"
#include "uout.h"
#include "uin.h"
#include "pins.h"
#include "boards.h"
#include "timer.h"
#include "sensoren.h"
#include "adc.h"
#include "sysled.h"
#include "eeprom.h"
#include "light.h"

void avrrestart(void);

volatile uint16_t sysTimer;
volatile int output_enabled;
volatile int second_tick;

int uartcommand;
int uartcommandi;

char tmp[4];
int inttmp;

int uartc;
char uartbuffer[30];
char uartrxbuffer[50];

int maincmd[20];
int docommand;

char buf[40];
