// SYSTEM
#define F_CPU 											16000000UL		// Systemfrequency

// I2C
#define SCL_CLOCK  									400000L			// I2C Clock

// UART
#define UART_BAUD_RATE 								115200			// UART Baudrate

// Timer
#define TIMERFREQ										10					// Timerfrequenz in ms
#define TIMERPRE										256				// Timer Prescaler

#define SYSTEMTIME_SYNCTIME						180				// Synctime in Minutes

// Sensoren

#define FOTOSENSOR_DEFAULT_VALUE					500				// Fotosensor Default Value
#define FOTOSENSOR_DEFAULT_READINTERVAL		5					// Fotosensor Readintervall in seconds
#define FOTOSENSOR_DEFAULT_READTOLERANCE		20					// Fotosensor Readtolerance

#define PIR_DEFAULT_VALUE 							0					// PIR Sensor Default Value
#define PIR_HARDWARE_RESET_TIME 					2					// PIR Reset Time in seconds

#define DS1820_DEFAULT_READINTERVAL				5					// DS1820 Readintervall in seconds
#define BME280_DEFAULT_READINTERVAL				30					// BME280 Readintervall in seconds

#define EEPROM_AUTOSAVE_TIME						10					// EEPROM Autosave after time in seconds