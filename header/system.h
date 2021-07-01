#include "../config.h"
#include <avr/io.h>
#include <inttypes.h>
#include <compat/twi.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <avr/eeprom.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/crc16.h>
#include <avr/wdt.h>

#include <util/delay.h>

#include "i2cmaster.h"
#include "uart.h"
#include "uout.h"
#include "uin.h"
#include "../pins.h"
#include "boards.h"
#include "timer.h"
#include "sensoren.h"
#include "adc.h"
#include "sysled.h"
#include "eeprom.h"
#include "light.h"
#include "bme280.h"
#include "systemclock.h"
#include "rgbwboard.h"
#include "audioboards.h"
#include "font.h"
#include "oled.h"
#include "pwmboards.h"

void avrrestart(void);

volatile uint16_t sysTimer;
volatile int output_enabled;
volatile int second_tick;

volatile int systemhour;
volatile int systemmin;
volatile int systemsec;

volatile int systemtime_synctimer;

int uartcommand;
int uartcommandi;

char tmp[5];
uint8_t inttmp;
uint8_t inttmp2;

uint16_t inttmp16;

int uartc;
char uartbuffer[30];
char uartrxbuffer[50];

int maincmd[20];
int docommand;

char buf[80];
