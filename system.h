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

#include "pins.h"
#include "timer.h"
#include "uart.h"
#include "sensoren.h"
#include "adc.h"
#include "boards.h"
#include "i2cmaster.h"
#include "sysled.h"

void avrrestart(void);

volatile int sysTimer;
volatile int output_enabled;

char buf[40];