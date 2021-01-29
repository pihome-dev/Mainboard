/* Copyright (C) 2020-2021 DmanT (www.dmant.ovh) - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 * https://dmant.ovh/
 */

#include "system.h"

void (*bootloader)( void ) = 0xF000;

void avrrestart(void) {
  bootloader();
}

int main (void) {

  // Initialisiere UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
  sei();
  uart_puts("\n\r");
  uart_puts("\n\r");
  uart_puts("piHOME Mainboard Firmware\n\n");
  uart_puts("Revision: Rev 1.0\n");
  uart_puts("Softwarecode: 349FTH34\n");
  uart_puts("Copyright by piHOME\n");
  uart_puts("https://pihome.net\n\n");
  uart_puts("Booting Firmware...\n\n");
  uart_puts("UART Initialisiert\n");
  
  // Initialisiere System LED (Status LED)
  stateled_init();
  uart_puts("Status LED Initialisiert\n");

  // Initialisiere Boards
  boards_init();
  uart_puts("Boards Initialisiert\n");

  // Initialisiere Sensoren
  sensoren_init();
  uart_puts("Sensoren Initialisiert\n");

  // Initialisiere the Timer
  timer_init();
  uart_puts("Timer Initialisiert\n");
  // Start the Timer
  timer_start();
  uart_puts("Timer started\n");
  // INIT UART

  systemstate = STATE_RUN;

  while(1) {

  	 // Systemled
  	 stateled();
  	 // Systemled end

	 // Sensorcode
    // Read the Temperature if Sensor enabled and exist
    if (ds1820_one_enabled == SENSOR_ENABLED) {
	   read_ds1820_one();
	 }

	 if (ds1820_two_enabled == SENSOR_ENABLED) {
	   read_ds1820_two();
	 }

    //
    // Read the Fotowiderstand if Sensor enabled and exist
    //
    if (fotosensor_one_enabled == SENSOR_ENABLED) {
      read_fotosensor_one();
    } else {
      fotosensor_one_value = FOTOSENSOR_DEFAULT_VALUE;
    }

    if (fotosensor_two_enabled == SENSOR_ENABLED) {
      read_fotosensor_two();
    } else {
      fotosensor_two_value = FOTOSENSOR_DEFAULT_VALUE;
    }

    //
	 // Read the PIR if Sensor enabled and exist
	 //
	 if (pir_one_enabled == SENSOR_ENABLED) {
	   read_pir_one();
	 }

	 if (pir_two_enabled == SENSOR_ENABLED) {
	   read_pir_two();
	 }

	 // Sensorcode end

	 // Systemcode


	 // Systemcode end

	 // UART
	 
	 uartc = uart_getc();
    if ( uartc & UART_NO_DATA ){ /* No data */ } else
    { 
       	
	   if (uartcommand == 1) {
		  if (uartc == '#') {
		    docommand = 1;  
			 uartcommand = 0;
        } else {
		    maincmd[uartcommandi] = uartc;
		  }
		  uartcommandi++;
		} else {
			
           switch (uartc) {
				 case '$':
				   uartcommandi = 0;
				   uartcommand = 1;
				   break;
				 case 'b':
				   uart_puts("\n\rSpringe zum Bootloader...\n\r");
					timer_stop();
					cli();
		         bootloader();
		         break;
		       case '\n':
		         break;
				 default:
				   uart_puts("Command not found\n\n\rPress ? for more Information\n\r");
				   break;
           }
		  }
     }

	  if (docommand == 1) {
	    maincmd[0] = 0;
		 maincmd[1] = 0;
		 maincmd[2] = 0;
	    maincmd[3] = 0;
		 maincmd[4] = 0;
		 maincmd[5] = 0;
	    docommand = 0;
	  }
	 
	 // UART end

	 //
	 // Clear the Systemcounters
	 //
	 if (sysTimer > 20000) {
	   sysTimer = 0;
	 }

	 if (stateTimer > 2000) {
	   stateTimer = 0;
	 }

  }
}
