#include "../header/system.h"

void sensoren_init(void) {
  
  fotosensor_one_value = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_two_value = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_one_value_old = FOTOSENSOR_DEFAULT_VALUE;
  fotosensor_two_value_old = FOTOSENSOR_DEFAULT_VALUE;
  
  // PIR PINs as Input
  
  PIRSENSOR1_DDR &= ~(1 << PIRSENSOR1_PIN);
  PIRSENSOR2_DDR &= ~(1 << PIRSENSOR2_PIN);
  
  pir_one_value = PIR_DEFAULT_VALUE;
  pir_two_value = PIR_DEFAULT_VALUE;
  pir_one_value_old = PIR_DEFAULT_VALUE;
  pir_two_value_old = PIR_DEFAULT_VALUE;
  
  pir_one_reset = 0;
  pir_one_reset_time = 0;
  pir_two_reset = 0;
  pir_two_reset_time = 0;
  
}

void read_fotosensor_one(void) {
	
  if ( sysTimer % (fotosensor_read_interval * 100) == 0) {
    fotosensor_one_value = readADC(5);

    if (output_enabled == 1) {
      if ( (fotosensor_one_value - fotosensor_one_value_old) > fotosensor_read_tolerance || (fotosensor_one_value_old - fotosensor_one_value) > fotosensor_read_tolerance) {
        snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_ONE_VALUE, fotosensor_one_value);
    	  uart_puts(buf);
	     fotosensor_one_value_old = fotosensor_one_value;
      }
    }    
    
  }
  
}

void read_fotosensor_two(void) {
	
  if ( sysTimer % (fotosensor_read_interval * 100) == 0) {
    fotosensor_two_value = readADC(7);
    
    if (output_enabled == 1) {
      if ( (fotosensor_two_value - fotosensor_two_value_old) > fotosensor_read_tolerance || (fotosensor_two_value_old - fotosensor_two_value) > fotosensor_read_tolerance) {
        snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_TWO_VALUE, fotosensor_two_value);
    	  uart_puts(buf);
	     fotosensor_two_value_old = fotosensor_two_value;
      }
    } 
  }
  
}

void read_pir_one(void) {
	
  if (pir_one_reset_time >= (pir_hardware_reset_time * 100) ) {
    pir_one_reset = 0;
  }	
	
  if (pir_one_reset == 0) {
  	
    if ( !(PIRSENSOR1_PIND & (1<<PIRSENSOR1_PIN)) ) {
      pir_one_value = 0;
    } else {
      pir_one_reset_time = 0;
  	   pir_one_value = 1;
  	   pir_one_reset = 1;
    }
    
  } 
	
  if (output_enabled == 1) {
    if (pir_one_value != pir_one_value_old) {
      snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_ONE_VALUE, pir_one_value);
    	uart_puts(buf);
    	pir_one_value_old = pir_one_value;
    }
  }
}

void read_pir_two(void) {
	
  if (pir_two_reset_time >= (pir_hardware_reset_time * 100) ) {
    pir_two_reset = 0;
  }	
	
  if (pir_two_reset == 0) {
  	
    if ( !(PIRSENSOR2_PIND & (1<<PIRSENSOR2_PIN)) ) {
      pir_two_value = 0;
    } else {
      pir_two_reset_time = 0;
  	   pir_two_value = 1;
  	   pir_two_reset = 1;
    }
    
  }	
	
  if (output_enabled == 1) {
    if (pir_two_value != pir_two_value_old) {
      snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_TWO_VALUE, pir_two_value);
    	uart_puts(buf);
    	pir_two_value_old = pir_two_value;
    }
  }
}

void read_ds1820_one(void) {

}

void read_ds1820_two(void) {

}

void read_bme280(void) {
  if ( sysTimer % (bme280_read_interval * 100) == 0) {
  	
    BME280_MESSURE();
    
    if (output_enabled == 1) {
      if ( bme280_temperature != bme280_temperature_old ) {
        snprintf(buf, 50, "!%s%d=%+3li.%02u\n", UART_SENDDATA, UART_BME280_TEMPERATURE, bme280_temperature/100, (uint8_t)(bme280_temperature%100));
    	  uart_puts(buf);
	     bme280_temperature_old = bme280_temperature;
      }
      
      if ( bme280_pressure != bme280_pressure_old ) {
        snprintf(buf, 50, "!%s%d=%4li.%02u\n", UART_SENDDATA, UART_BME280_PRESSURE, bme280_pressure/100 , (uint8_t)(bme280_pressure%100));
    	  uart_puts(buf);
	     bme280_pressure_old = bme280_pressure;
      }
      
      if ( bme280_humidity != bme280_humidity_old ) {
        snprintf(buf, 50, "!%s%d=%2li.%02u\n", UART_SENDDATA, UART_BME280_HUMIDITY, bme280_humidity>>10, (uint16_t)((bme280_humidity&0x3FF)*1000)/1024);
    	  uart_puts(buf);
	     bme280_humidity_old = bme280_humidity;
      }
    } 
  }
}