#define F_CPU 16000000UL
#include "system.h"

#define UART_BAUD_RATE 115200

void (*bootloader)( void ) = 0xF000;  // Achtung Falle: Hier Word-Adresse

void avrrestart(void) {
  bootloader();
}

int main (void) {

  // Initialisiere System LED (Status LED)
  stateled_init();
  
  output_enabled = 0;

  // INIT UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
  
  uart_puts("Welcome to piHOME\n\r");
  uart_puts("Starting System ...\n\r");
  
  // Initialisiere the Timer
  timer_init();
  
  // Initialisiere I2C
  i2c_init();
  
  // Initialisiere Sensoren
  sensoren_init();
  
  search_bme280();
  
  // Initialisiere Boards
  boards_init();
  
  // Search Connected Boards
  rgbwboards_search();
  dreizweichpwmboards_search();
  vierchampboards_search();
  
  // Start the Timer
  timer_start();
  
  uart_puts("System is started and running\n\r");
  while(1) {
  
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
	 // Clear the Systemcounter
	 //
	 if (sysTimer > 1000) {
	   sysTimer = 0;
	 }
  
  }
}