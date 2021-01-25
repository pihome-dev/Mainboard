/* Copyright (C) 2020-2021 DmanT (www.dmant.ovh) - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */
 
#include "system.h"

void (*bootloader)( void ) = 0xF000;

void avrrestart(void) {
  bootloader();
}

void toggle(int doo) {
  for (int i = 0; i < doo; i++) {
    PORTA |= (1<<PA0);
    PORTA |= (1<<PA1);
    _delay_ms(200);
    PORTA &= ~(1<<PA0);
    PORTA &= ~(1<<PA1);
    _delay_ms(200);
  }
  _delay_ms(800);
}

int main (void) {
	
  DDRA |= (1<<PA0);
  DDRA |= (1<<PA1);

  // Initialisiere System LED (Status LED)g
  stateled_init();
  toggle(1);
  
  output_enabled = 0;

  // INIT UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );it
  sei();
  
  uart_puts("Welcome to piHOME Mainboard Firmware\n\r");
  uart_puts("\n\r");
  uart_puts("System is starting now\n\r\n\r");
  uart_puts("Please wait...\n\r");
  
  // Initialisiere the Timer
  timer_init();
  uart_puts(".");

  // Initialisiere I2C
  i2c_init();
  uart_puts(".");
  
  // Initialisiere Sensoren
  sensoren_init();
  uart_puts(".");
  
  // Search Connected BME280
  search_bme280();
  uart_puts(".");
  
  // Initialisiere Boards
  boards_init();
  uart_puts(".");
  
  // Search Connected Boards
  rgbwboards_search();
  uart_puts(".");
  
  dreizweichpwmboards_search();
  uart_puts(".");
  
  vierchampboards_search();
  uart_puts(".");
  
  // Start the Timer
  timer_start(); 
  uart_puts(".\n\r");
  
  uart_puts("System is started and running\n\r\n\r");
  
  toggle(2);
  _delay_ms(1000);
  toggle(2);
  _delay_ms(1000);
   
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
