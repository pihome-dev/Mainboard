#include "../header/system.h"

uint16_t eeDefaultExist EEMEM 												= 10;

// Sensoren
uint16_t eeFOTOSENSOR_ONE_ENABLE EEMEM										= 11;
uint16_t eeFOTOSENSOR_TWO_ENABLE EEMEM										= 12;
uint16_t eeFOTOSENSOR_READ_TOLERANCE EEMEM								= 17;
uint16_t eeFOTOSENSOR_READ_INTERVAL EEMEM									= 18;

uint16_t eePIR_ONE_ENABLE EEMEM												= 13;
uint16_t eePIR_TWO_ENABLE EEMEM												= 14;

uint16_t eeDS1820_ONE_ENABLE EEMEM											= 15;
uint16_t eeDS1820_TWO_ENABLE EEMEM											= 16;
uint16_t eeDS1820_READ_INTERVAL EEMEM										= 19;
uint16_t eePIR_HARDWARE_RESETTIME EEMEM									= 19;
uint16_t eeBME280_READ_INTERVAL EEMEM										= 20;

uint16_t eeLIGHT_MODE EEMEM													= 21;

uint16_t eeMOTIONLIGHT_MODE EEMEM											= 22;
uint16_t eeNIGHTLIGHT_MODE EEMEM												= 23;

uint16_t eeMOTIONLIGHT_ENABLE EEMEM											= 24;
uint16_t eeNIGHTLIGHT_ENABLE EEMEM											= 25;

uint16_t eeMOTIONLIGHT_TIME EEMEM											= 26;
uint16_t eeNIGHTLIGHT_TIME EEMEM 											= 27;
uint16_t eeBME280_ENABLE EEMEM												= 28;
uint16_t eeNIGHTLIGHT_TIME_HOUR_ON EEMEM 									= 29;
uint16_t eeNIGHTLIGHT_TIME_MINUTE_ON EEMEM								= 30;
uint16_t eeNIGHTLIGHT_TIME_HOUR_OFF EEMEM 								= 31;
uint16_t eeNIGHTLIGHT_TIME_MINUTE_OFF EEMEM								= 32;
uint16_t eeLIGHT_BRIGHTNESS EEMEM											= 33;
uint16_t eeLIGHT_BRIGHTNESS_ON EEMEM										= 34;

uint8_t getEEDefaultExist(void) {
  uint8_t retByte;
  retByte = eeprom_read_byte (&eeDefaultExist);
  return retByte;
}

void write_default_eeprom_data(void) {
	
  eeprom_update_byte(&eeFOTOSENSOR_ONE_ENABLE, eeData_FOTOSENSOR_ONE_ENABLE);
  eeprom_update_byte(&eeFOTOSENSOR_TWO_ENABLE, eeData_FOTOSENSOR_TWO_ENABLE);
  
  eeprom_update_byte(&eeBME280_ENABLE, eeData_BME280_ENABLE);
  
  eeprom_update_byte(&eeFOTOSENSOR_READ_TOLERANCE, eeData_FOTOSENSOR_READ_TOLERANCE);
  eeprom_update_byte(&eeFOTOSENSOR_READ_INTERVAL, eeData_FOTOSENSOR_READ_INTERVAL);
  
  eeprom_update_byte(&eePIR_ONE_ENABLE, eeData_PIR_ONE_ENABLE);
  eeprom_update_byte(&eePIR_TWO_ENABLE, eeData_PIR_TWO_ENABLE);
  eeprom_update_byte(&eePIR_HARDWARE_RESETTIME, eeData_PIR_HARDWARE_RESETTIME);
  
  eeprom_update_byte(&eeDS1820_ONE_ENABLE, eeData_DS1820_ONE_ENABLE);
  eeprom_update_byte(&eeDS1820_TWO_ENABLE, eeData_DS1820_TWO_ENABLE);
  eeprom_update_byte(&eeDS1820_READ_INTERVAL, eeData_DS1820_READ_INTERVAL);
  
  eeprom_update_byte(&eeBME280_READ_INTERVAL, eeData_BME280_READ_INTERVAL);
  
  eeprom_update_byte(&eeLIGHT_MODE, eeData_LIGHT_MODE);
  eeprom_update_byte(&eeMOTIONLIGHT_MODE, eeData_MOTIONLIGHT_MODE);
  eeprom_update_byte(&eeNIGHTLIGHT_MODE, eeData_NIGHTLIGHT_MODE);
  eeprom_update_byte(&eeMOTIONLIGHT_ENABLE, eeData_MOTIONLIGHT_ENABLE);
  eeprom_update_byte(&eeNIGHTLIGHT_ENABLE, eeData_NIGHTLIGHT_ENABLE);
  
  eeprom_update_byte(&eeMOTIONLIGHT_TIME, eeData_MOTIONLIGHT_TIME);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME, eeData_NIGHTLIGHT_TIME);
  
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_HOUR_ON, 0);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_MINUTE_ON, 0);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_HOUR_OFF, 0);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_MINUTE_OFF, 0);
  
  eeprom_update_byte(&eeLIGHT_BRIGHTNESS, eeData_LIGHT_BRIGHTNESS);
  eeprom_update_byte(&eeLIGHT_BRIGHTNESS_ON, eeData_LIGHT_BRIGHTNESS_ON);
  
  eeprom_update_byte(&eeDefaultExist, eeDefaultDataExist);
  
}

void getEEPROMDefaultData(void) {
  
  fotosensor_one_enabled = eeprom_read_byte (&eeFOTOSENSOR_ONE_ENABLE);
  fotosensor_two_enabled = eeprom_read_byte (&eeFOTOSENSOR_TWO_ENABLE);
  
  fotosensor_read_tolerance = eeprom_read_byte (&eeFOTOSENSOR_READ_TOLERANCE);
  fotosensor_read_interval = eeprom_read_byte (&eeFOTOSENSOR_READ_INTERVAL);
  
  pir_one_enabled = eeprom_read_byte (&eePIR_ONE_ENABLE);
  pir_two_enabled = eeprom_read_byte (&eePIR_TWO_ENABLE);
  pir_hardware_reset_time = eeprom_read_byte (&eePIR_HARDWARE_RESETTIME);
  
  ds1820_one_enabled = eeprom_read_byte (&eeDS1820_ONE_ENABLE);
  ds1820_two_enabled = eeprom_read_byte (&eeDS1820_TWO_ENABLE);
  
  ds1820_read_interval = eeprom_read_byte (&eeDS1820_READ_INTERVAL);
  
  bme280_read_interval = eeprom_read_byte (&eeBME280_READ_INTERVAL);
  bme280_enabled = eeprom_read_byte (&eeBME280_ENABLE);
  
  light_mode = eeprom_read_byte (&eeLIGHT_MODE);
  motionlight_mode = eeprom_read_byte (&eeMOTIONLIGHT_MODE);
  nightlight_mode = eeprom_read_byte (&eeNIGHTLIGHT_MODE);
  motionlight_enabled = eeprom_read_byte (&eeMOTIONLIGHT_ENABLE);
  nightlight_enabled = eeprom_read_byte (&eeNIGHTLIGHT_ENABLE);
  
  light_brightness = eeprom_read_byte (&eeLIGHT_BRIGHTNESS);
  
  motionlight_time = eeprom_read_byte (&eeMOTIONLIGHT_TIME);
  nightlight_time = eeprom_read_byte (&eeNIGHTLIGHT_TIME);
  
  nightlight_time_hour_on = eeprom_read_byte(&eeNIGHTLIGHT_TIME_HOUR_ON);
  nightlight_time_minute_on = eeprom_read_byte(&eeNIGHTLIGHT_TIME_MINUTE_ON);
  
  nightlight_time_hour_off = eeprom_read_byte(&eeNIGHTLIGHT_TIME_HOUR_OFF);
  nightlight_time_minute_off = eeprom_read_byte(&eeNIGHTLIGHT_TIME_MINUTE_OFF);
  
  light_brightness_on = eeprom_read_byte(&eeLIGHT_BRIGHTNESS_ON);
  
  eeprom_autosave_enable = 1;
  eeprom_changed = 0;
}

void eeprom_write_autosave(void) {
	
  eeprom_update_byte(&eeFOTOSENSOR_ONE_ENABLE, fotosensor_one_enabled);
  eeprom_update_byte(&eeFOTOSENSOR_TWO_ENABLE, fotosensor_two_enabled);
  
  eeprom_update_byte(&eeFOTOSENSOR_READ_TOLERANCE, fotosensor_read_tolerance);
  eeprom_update_byte(&eeFOTOSENSOR_READ_INTERVAL, fotosensor_read_interval);
  
  eeprom_update_byte(&eePIR_ONE_ENABLE, pir_one_enabled);
  eeprom_update_byte(&eePIR_TWO_ENABLE, pir_two_enabled);
  eeprom_update_byte(&eePIR_HARDWARE_RESETTIME, pir_hardware_reset_time);
  
  eeprom_update_byte(&eeDS1820_ONE_ENABLE, ds1820_one_enabled);
  eeprom_update_byte(&eeDS1820_TWO_ENABLE, ds1820_two_enabled);
  eeprom_update_byte(&eeDS1820_READ_INTERVAL, ds1820_read_interval);
  
  eeprom_update_byte(&eeBME280_ENABLE, bme280_enabled);
  eeprom_update_byte(&eeBME280_READ_INTERVAL, bme280_read_interval);
  
  eeprom_update_byte(&eeLIGHT_MODE, light_mode);
  eeprom_update_byte(&eeMOTIONLIGHT_MODE, motionlight_mode);
  eeprom_update_byte(&eeNIGHTLIGHT_MODE, nightlight_mode);
  eeprom_update_byte(&eeMOTIONLIGHT_ENABLE, motionlight_enabled);
  eeprom_update_byte(&eeNIGHTLIGHT_ENABLE, nightlight_enabled);
  
  eeprom_update_byte(&eeMOTIONLIGHT_TIME, motionlight_time);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME, nightlight_time);
  
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_HOUR_ON, nightlight_time_hour_on);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_MINUTE_ON, nightlight_time_minute_on);
  
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_HOUR_OFF, nightlight_time_hour_off);
  eeprom_update_byte(&eeNIGHTLIGHT_TIME_MINUTE_OFF, nightlight_time_minute_off);
  
  eeprom_update_byte(&eeLIGHT_BRIGHTNESS, light_brightness);
  
  eeprom_update_byte(&eeLIGHT_BRIGHTNESS_ON, light_brightness_on);
    
}

void eeprom_autosave(void) {
  eeprom_changed = 1;
  eeprom_changed_timer = 0;
}

void eeprom_reset(void) {
  eeprom_update_byte(&eeDefaultExist, eeDefaultDataExistReset);
}