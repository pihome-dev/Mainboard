#include "system.h"

void sensoren_init(void) {

  fotosensor_one_enabled = 0;
  fotosensor_two_enabled = 0;
  
  fotosensor_read_interval = (FOTOSENSOR_DEFAULT_READINTERVAL * 1000) / TIMERFREQ;
  
  fotosensor_one_value = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_two_value = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_one_value_old = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_two_value_old = FOTOSENSOR_DEFAULT_VALUE;
  
  // PIR PINs as Input
  
  PIRSENSOR1_DDR &= ~(1 << PIRSENSOR1_PIN);
  PIRSENSOR2_DDR &= ~(1 << PIRSENSOR2_PIN);
  
  pir_one_enabled = 0;
  pir_two_enabled = 0;
  
  pir_one_value = PIR_DEFAULT_VALUE;
  pir_two_value = PIR_DEFAULT_VALUE;
  pir_one_value_old = PIR_DEFAULT_VALUE;
  pir_two_value_old = PIR_DEFAULT_VALUE;
  
  ds1820_one_enabled = 0;
  ds1820_two_enabled = 0;
  
  ds1820_read_interval = (DS1820_DEFAULT_READINTERVAL * 1000) / TIMERFREQ;
  
  bme280_temperature = 0;
  bme280_pressure = 0;
  bme280_humidity = 0;
  
  bme280_readinterval = (BME280_DEFAULT_READINTERVAL * 1000) / TIMERFREQ;

}

void search_bme280(void) {
  // BME280 Sensor
  if(!(i2c_start(BME280_ADDRESS+I2C_WRITE))) {		// BME280 Sensor bereit zum schreiben?
	 i2c_stop();
	 bme280_exist = 1;			   						// BME280 Sensor exist
   
  } else {
	 i2c_stop();
  	 bme280_exist = 0;			   						// BME280 Sensor not exist
  }
}

void read_bme280(void) {

  if ( (sysTimer % bme280_readinterval) == 0) {

    bme280_temperature = bme280_readTemperature();
    bme280_pressure = bme280_readPressure();
    bme280_humidity = bme280_readHumidity();
    bme280_altitude = bme280_readAltitude(1013.25);
  
    if (output_enabled == 1) {
      if (bme280_temperature != bme280_temperature_old) {
  	     snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_BME280_TEMPERATURE, bme280_temperature);
        uart_puts(buf);
        bme280_temperature_old = bme280_temperature;
      }
    
      if (bme280_pressure != bme280_pressure_old) {
    	  snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_BME280_PRESSURE, bme280_pressure);
        uart_puts(buf);
        bme280_pressure_old = bme280_pressure;
      }
    
      if (bme280_humidity != bme280_humidity_old) {
  	     snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_BME280_HUMIDITY, bme280_humidity);
        uart_puts(buf);
        bme280_humidity_old = bme280_humidity;
      }
    
	   if (bme280_altitude != bme280_altitude_old) {
  	     snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_BME280_ALTITUDE, bme280_altitude);
        uart_puts(buf);
        bme280_altitude_old = bme280_altitude;
      }
    }
  }  
}

void read_fotosensor_one(void) {
	
  if (sysTimer % fotosensor_read_interval == 0) {
    fotosensor_one_value = readADC(FOTOSENSOR1_PIN);

    if (output_enabled == 1) {
      if ( (fotosensor_one_value - fotosensor_one_value_old) > FOTOSENSOR_TOLERANCE || (fotosensor_one_value_old - fotosensor_one_value) > FOTOSENSOR_TOLERANCE) {
        snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_FOTOSENSOR_ONE, fotosensor_one_value);
    	  uart_puts(buf);
	     fotosensor_one_value_old = fotosensor_one_value;
      }
    }    
    
  }
  
}

void read_fotosensor_two(void) {
	
  if (sysTimer % fotosensor_read_interval == 0) {
    fotosensor_two_value = readADC(FOTOSENSOR2_PIN);
    
    if (output_enabled == 1) {
      if ( (fotosensor_two_value - fotosensor_two_value_old) > FOTOSENSOR_TOLERANCE || (fotosensor_two_value_old - fotosensor_two_value) > FOTOSENSOR_TOLERANCE) {
        snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_FOTOSENSOR_TWO, fotosensor_two_value);
    	  uart_puts(buf);
	     fotosensor_two_value_old = fotosensor_two_value;
      }
    } 
  }
  
}

void read_pir_one(void) {
	
  if (pir_one_reset_time >= PIR_HARDWARE_RESET_TIME) {
    pir_one_reset = 0;
  }	
	
  if (pir_one_reset == 0) {
  	
    if ( !(PINC & (1<<PC1)) ) {
      pir_one_value = 0;
    } else {
      pir_one_reset_time = 0;
  	   pir_one_value = 1;
  	   pir_one_reset = 1;
    }
    
  } 
	
  if (output_enabled == 1) {
    if (pir_one_value != pir_one_value_old) {
      snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_PIR_ONE, pir_one_value);
    	uart_puts(buf);
    	pir_one_value_old = pir_one_value;
    }
  }
}

void read_pir_two(void) {
	
  if (pir_two_reset_time >= PIR_HARDWARE_RESET_TIME) {
    pir_two_reset = 0;
  }	
	
  if (pir_two_reset == 0) {
  	
    if ( !(PINC & (1<<PC1)) ) {
      pir_two_value = 0;
    } else {
      pir_two_reset_time = 0;
  	   pir_two_value = 1;
  	   pir_two_reset = 1;
    }
    
  }	
	
  if (output_enabled == 1) {
    if (pir_two_value != pir_two_value_old) {
      snprintf(buf, 50, "!%s%d=%d\n\r", UART_DATA, UART_PIR_TWO, pir_two_value);
    	uart_puts(buf);
    	pir_two_value_old = pir_two_value;
    }
  }
}

void read_ds1820_one(void) {

}

void read_ds1820_two(void) {

}