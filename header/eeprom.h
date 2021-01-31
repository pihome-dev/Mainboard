#define eeDefaultDataExist							23
#define eeDefaultDataExistReset					1

// Sensoren
#define eeData_FOTOSENSOR_ONE_ENABLE 			1
#define eeData_FOTOSENSOR_TWO_ENABLE 			1
#define eeData_FOTOSENSOR_READ_TOLERANCE		FOTOSENSOR_DEFAULT_READTOLERANCE
#define eeData_FOTOSENSOR_READ_INTERVAL		FOTOSENSOR_DEFAULT_READINTERVAL

#define eeData_PIR_ONE_ENABLE 					1
#define eeData_PIR_TWO_ENABLE 					1

#define eeData_DS1820_ONE_ENABLE 				1
#define eeData_DS1820_TWO_ENABLE 				1
#define eeData_DS1820_READ_INTERVAL				DS1820_DEFAULT_READINTERVAL
#define eeData_BME280_READ_INTERVAL				BME280_DEFAULT_READINTERVAL
#define eeData_PIR_HARDWARE_RESETTIME			PIR_HARDWARE_RESET_TIME					

uint8_t getEEDefaultExist(void);
void write_default_eeprom_data(void);
void getEEPROMDefaultData(void);
void eeprom_autosave(void);

void eeprom_reset(void);

void eeprom_write_autosave(void);

volatile int eeprom_autosave_enable;
volatile int eeprom_changed;
volatile int eeprom_changed_timer;