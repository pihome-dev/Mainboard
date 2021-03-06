#define eeDefaultDataExist							8
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
#define eeData_BME280_ENABLE		 				1
#define eeData_PIR_HARDWARE_RESETTIME			PIR_HARDWARE_RESET_TIME


//////////
#define eeData_LIGHT_MODE			 				1
#define eeData_MOTIONLIGHT_MODE			 		7
#define eeData_NIGHTLIGHT_MODE			 		8

#define eeData_LIGHT_BRIGHTNESS					LIGHT_BRIGHTNESS_DEFAULT_VALUE
#define eeData_LIGHT_BRIGHTNESS_ON				LIGHT_BRIGHTNESS_DEFAULT_ON

#define eeData_MOTIONLIGHT_ENABLE				1
#define eeData_NIGHTLIGHT_ENABLE			 		0

#define eeData_MOTIONLIGHT_TIME					30
#define eeData_NIGHTLIGHT_TIME			 		30

#define eeData_NIGHTLIGHT_HOUR					22
#define eeData_NIGHTLIGHT_MINUTE					00


uint8_t getEEDefaultExist(void);
void write_default_eeprom_data(void);
void getEEPROMDefaultData(void);
void eeprom_autosave(void);

void eeprom_reset(void);

void eeprom_write_autosave(void);

volatile int eeprom_autosave_enable;
volatile int eeprom_changed;
volatile int eeprom_changed_timer;