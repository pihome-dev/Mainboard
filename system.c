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

  // INIT UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
  
  // Initialisiere System LED (Status LED)
  stateled_init();
  
  // Initialisiere Boards
  boards_init();

  // Initialisiere the Timer
  timer_init();

  // Initialisiere I2C
  i2c_init();

  // Initialisiere Sensoren
  sensoren_init();

  // Search Connected BME280
  //search_bme280();

  // Search Connected Boards
  rgbwboards_search();

  //dreizweichpwmboards_search();

  //vierchampboards_search();

  // Start the Timer
  timer_start();
  sei();
  uart_puts("System is started and running\n\r\n\r");

  systemstate = STATE_RUN;
  
  // Test
  //output_enabled = 1;
  //fotosensor_one_enabled = SENSOR_ENABLED;
  //fotosensor_two_enabled = SENSOR_ENABLED;
  // Testend
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

	 //
	 // Read the BME280 if Sensor enabled and exist
	 //
	 if (bme280_enabled == SENSOR_ENABLED) {
	 	read_bme280();
	 } else {
	   bme280_temperature = 0;
	   bme280_pressure = 0;
	   bme280_humidity = 0;
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
		      break;
          }
      }
    }
    
    if (docommand == 1) {
    	
    	switch (maincmd[0]) {
	     
	     default:
	       break;
	   }
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
