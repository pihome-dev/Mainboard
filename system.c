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

#define SLAVE_ADRESSE 0x50

void (*bootloader)( void ) = 0xF000;

void avrrestart(void) {
  bootloader();
}

int main (void) {

  // Initialisiere UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
  sei();
  uart_puts("\n\n");
  uart_puts("piHOME Mainboard Firmware\n\n");
  uart_puts("Revision: Rev 1.0\n");
  uart_puts("Softwarecode: 349FTH34\n");
  uart_puts("Copyright by piHOME\n");
  uart_puts("https://pihome.net\n\n");
  uart_puts("... Booting Firmware ...\n\n");
  uart_puts("UART Initialisiert\n");
  
  // Initialisiere I2C
  i2c_init(); 
  uart_puts("I2C Initialisiert\n");
  
  // Initialisiere System LED (Status LED)
  stateled_init();
  uart_puts("Status LED Initialisiert\n");

  // Initialisiere Boards
  boards_init();
  uart_puts("Boards Initialisiert\n");

  // Initialisiere Sensoren
  sensoren_init();
  uart_puts("Sensoren Initialisiert\n");

  // Initialisiere Lightsystem
  light_init();
  uart_puts("Lightsystem Initialisiert\n");

  // Initialisiere the Timer
  timer_init();
  uart_puts("Timer Initialisiert\n");
  
  // Start the Timer
  timer_start();
  uart_puts("Timer started\n");
  // INIT UART

  systemstate = STATE_RUN;
  
  // EEPROM
  if (getEEDefaultExist() != eeDefaultDataExist) {
    uart_puts("Write Default EEPROM Data\n");
  	 write_default_eeprom_data();
  } else {
    uart_puts("Default EEPROM Data exist\n");
  }
  
  output_on();

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
	 lightsystem();

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
			  int t = 0;
           switch (uartc) {
				 case '$':
				   uartcommandi = 0;
				   uartcommand = 1;
				   break;
				 case 'b':
				   uart_puts("\nSpringe zum Bootloader...\n");
				   _delay_ms(500);
				   uart_puts("3.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("2.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("1.");
				   _delay_ms(500);
				   uart_puts(".");
				   uart_puts("\n\n\n\n");
					timer_stop();
					cli();
		         bootloader();
		         break;
		       case '\n':
		         break;
		       case 'C':
		         uart_get_system_config();
		         break;
		       case 'D':
		         uart_get_data();
		         break;
		       case 'T':
		         if(!(i2c_start(SLAVE_ADRESSE+I2C_WRITE))) {
		           t = 0;
		           i2c_stop();
		         } else {
		           t = 1;
		           i2c_stop();
		         }
		         if (t == 1) {
		           uart_puts("not found\n");
		         } else {
		           uart_puts("found\n");
		         }
		         break;
				 default:
				   uart_puts("\nCommand not found\nPress \'?\' for more Information\n");
				   break;
           }
		  }
     }

	  if (docommand == 1) {
	    output_off();
	    system_command();
	    output_on();
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
	 
	 // EEPROM Autosave
	 if (second_tick == 1) {
	   second_tick = 0;
	   
	   // Check EEPROM Autosave
	   if (eeprom_autosave_enable == 1) {
	     if (eeprom_changed == 1) {
	       if (eeprom_changed_timer >= EEPROM_AUTOSAVE_TIME) {
	       	eeprom_changed = 0;
	       	eeprom_write_autosave();
	       	uart_puts("EEPROM written\n");
	       } else {
	         eeprom_changed_timer++;
	       }
	     }
	   }
	 }
	 

  }
}
