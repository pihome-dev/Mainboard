#include "../header/system.h"

void output_on(void) {
  output_enabled = SENSOR_ENABLED;
}

void output_off(void) {
  output_enabled = SENSOR_DISABLED;
}

void uart_send_system_config(void) {
  output_off();
  
  uart_puts_P("\n-------- piHOME System Config --------\n\n");
  
  // Fotosensor One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_ONE_ENABLE, fotosensor_one_enabled);
  uart_puts(buf);
  
  // Fotosensor Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_TWO_ENABLE, fotosensor_two_enabled);
  uart_puts(buf);
  
  // Fotosensor Read Interval
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_READ_INTERVAL, fotosensor_read_interval);
  uart_puts(buf);
  
  // Fotosensor Read Tolerance
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_READ_TOLERANCE, fotosensor_read_tolerance);
  uart_puts(buf);
  
  // PIR One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_ONE_ENABLE, pir_one_enabled);
  uart_puts(buf);
  
  // PIR Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_TWO_ENABLE, pir_two_enabled);
  uart_puts(buf);
  
  // PIR Resettime
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_RESET_TIME, pir_hardware_reset_time);
  uart_puts(buf);
  
  // DS1820 One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_ONE_ENABLE, ds1820_one_enabled);
  uart_puts(buf);
  
  // DS1820 Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_TWO_ENABLE, ds1820_two_enabled);
  uart_puts(buf);
  
  // DS1820 Read Interval
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_READ_INTERVAL, ds1820_read_interval);
  uart_puts(buf);
  
  // BME280 Read Interval
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_BME280_READ_INTERVAL, bme280_read_interval);
  uart_puts(buf);
  
  // Lightmode
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_LIGHT_MODE, light_mode);
  uart_puts(buf);
  
  // Motionlightmode
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_MOTIONLIGHT_MODE, motionlight_mode);
  uart_puts(buf);
  
// Lightbrightness
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_LIGHT_BRIGHTNESS, light_brightness);
  uart_puts(buf);
  
  // Nightlightmode
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_MODE, nightlight_mode);
  uart_puts(buf);
  
  // Motionlight enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_MOTIONLIGHT_ENABLE, motionlight_enabled);
  uart_puts(buf);
  
  // Nightlight enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_ENABLE, nightlight_enabled);
  uart_puts(buf); 
  
  // Motionlight time
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_MOTIONLIGHT_TIME, motionlight_time);
  uart_puts(buf);
  
  // Nightlight time
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_TIME, nightlight_time);
  uart_puts(buf);
  
  uart_puts_P("\n-------- Config Ende --------\n\n");
  
  output_on();
}

void uart_send_system_data(void) {
  output_off();
  
  uart_puts_P("\n-------- piHOME System Data --------\n\n");
  
  // Fotosensor One value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_ONE_VALUE, fotosensor_one_value);
  uart_puts(buf);
  
  // Fotosensor Two value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_TWO_VALUE, fotosensor_two_value);
  uart_puts(buf);
  
  // PIR One value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_ONE_VALUE, pir_one_value);
  uart_puts(buf);
  
  // PIR Two value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_TWO_VALUE, pir_two_value);
  uart_puts(buf);
  
  // Roommotion
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_ROOMMOTION, roommotion_value);
  uart_puts(buf);
  
  // Roombrightness
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_ROOMBRIGHTNESS, roombrightness_value);
  uart_puts(buf);
  
  // DS1820 One value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_ONE_VALUE, ds1820_one_value);
  uart_puts(buf);
  
  // DS1820 Two value
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_TWO_VALUE, ds1820_two_value);
  uart_puts(buf);
  
  // BME280 Temperature
  snprintf(buf, 50, "!%s%d=%+3li.%02u\n", UART_SENDDATA, UART_BME280_TEMPERATURE, bme280_temperature/100, (uint8_t)(bme280_temperature%100));
  uart_puts(buf);

  // BME280 Pressure
  snprintf(buf, 50, "!%s%d=%4li.%02u\n", UART_SENDDATA, UART_BME280_PRESSURE, bme280_pressure/100 , (uint8_t)(bme280_pressure%100));
  uart_puts(buf);

  // BME280 Humidity
  snprintf(buf, 50, "!%s%d=%2li.%02u\n", UART_SENDDATA, UART_BME280_HUMIDITY, bme280_humidity>>10, (uint16_t)((bme280_humidity&0x3FF)*1000)/1024);
  uart_puts(buf);
  
  // Nightlight Hour On
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_HOUR_ON, nightlight_time_hour_on);
  uart_puts(buf);
  
  // Nightlight Minute On
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_MINUTE_ON, nightlight_time_minute_on);
  uart_puts(buf);
  
  // Nightlight Hour Off
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_HOUR_OFF, nightlight_time_hour_off);
  uart_puts(buf);
  
  // Nightlight Minute Off
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_NIGHTLIGHT_MINUTE_OFF, nightlight_time_minute_off);
  uart_puts(buf);
  
  uart_puts_P("\n-------- Data Ende --------\n\n");
  
  output_on();
}

void uart_send_system_info(void) {
  output_off();
  
  uart_puts_P("\n-------- piHOME System Mainboard Information --------\n\n");
  
  uart_puts_P("Systemtime: ");
  snprintf(buf, 50, "%02d:%02d:%02d\n", systemhour, systemmin, systemsec);
  uart_puts(buf);
  
  uart_puts_P("Systemtime in minutes: ");
  snprintf(buf, 50, "%d\n", (systemhour * 60) + systemmin);
  uart_puts(buf);
  
  uart_puts_P("Nightlight On in minutes: ");
  snprintf(buf, 50, "%d\n", (nightlight_time_hour_on * 60) + nightlight_time_minute_on);
  uart_puts(buf);
  
  uart_puts_P("Nightlight Off in minutes: ");
  snprintf(buf, 50, "%d\n", (nightlight_time_hour_off * 60) + nightlight_time_minute_off);
  uart_puts(buf);
  
  uart_puts_P("Synctime: ");
  snprintf(buf, 50, "%d min\n", SYSTEMTIME_SYNCTIME);
  uart_puts(buf);
  
  uart_puts_P("\n-------- Mainboard Information Ende --------\n\n");
  
  output_on();
}

void uart_get_systemtime(void) {
  snprintf(buf, 50, "!%s%02d\n", UART_GETDATA, UART_GET_SYSTEMTIME);
  uart_puts(buf);
}

void uart_get_connected_rgbwboards(void) {
	 output_off();
	
	 uart_puts_P("\n-------- piHOME System Connected RGBW Boards --------\n\n");
	
	 snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_ONE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD1]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_TWO_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD2]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_THREE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD3]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_FOUR_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD4]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_FIVE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD5]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_SIX_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD6]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_SEVEN_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD7]);
    uart_puts(buf);
    
	 snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_EIGHT_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD8]);
    uart_puts(buf);
    
	 uart_puts_P("\n-------- RGBW Boards Ende --------\n\n");
    
    output_on();
}