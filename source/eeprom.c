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

uint8_t getEEDefaultExist(void) {
  uint8_t retByte;
  retByte = eeprom_read_byte (&eeDefaultExist);
  return retByte;
}

void write_default_eeprom_data(void) {
	
  eeprom_update_byte(&eeFOTOSENSOR_ONE_ENABLE, eeData_FOTOSENSOR_ONE_ENABLE);
  eeprom_update_byte(&eeFOTOSENSOR_TWO_ENABLE, eeData_FOTOSENSOR_TWO_ENABLE);
  
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
  
  light_mode = eeprom_read_byte (&eeLIGHT_MODE);
  motionlight_mode = eeprom_read_byte (&eeMOTIONLIGHT_MODE);
  nightlight_mode = eeprom_read_byte (&eeNIGHTLIGHT_MODE);
  motionlight_enabled = eeprom_read_byte (&eeMOTIONLIGHT_ENABLE);
  nightlight_enabled = eeprom_read_byte (&eeNIGHTLIGHT_ENABLE);
  
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
  
  eeprom_update_byte(&eeBME280_READ_INTERVAL, bme280_read_interval);
    
}

void eeprom_autosave(void) {
  eeprom_changed = 1;
  eeprom_changed_timer = 0;
}

void eeprom_reset(void) {
  eeprom_update_byte(&eeDefaultExist, eeDefaultDataExistReset);
}