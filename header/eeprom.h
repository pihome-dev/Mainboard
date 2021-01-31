#define eeDefaultDataExist							23

// Sensoren
#define eeData_FOTOSENSOR_ONE_ENABLE 			1
#define eeData_FOTOSENSOR_TWO_ENABLE 			1
#define eeData_FOTOSENSOR_READ_TOLERANCE		20
#define eeData_FOTOSENSOR_READ_INTERVAL		5

#define eeData_PIR_ONE_ENABLE 					1
#define eeData_PIR_TWO_ENABLE 					1

#define eeData_DS1820_ONE_ENABLE 				1
#define eeData_DS1820_TWO_ENABLE 				1
#define eeData_DS1820_READ_INTERVAL				5

#define EEPROM_AUTOSAVE_TIME						10						

uint8_t getEEDefaultExist(void);
void write_default_eeprom_data(void);
void getEEPROMDefaultData(void);
void eeprom_autosave(void);

void eeprom_write_autosave(void);

volatile int eeprom_autosave_enable;
volatile int eeprom_changed;
volatile int eeprom_changed_timer;