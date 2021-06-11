#define UARTIN_SYSTEM													'S'
#define UARTIN_COMMAND													'C'

// Systemdata
#define UARTIN_FOTOSENSOR_ONE_ENABLE								 1
#define UARTIN_FOTOSENSOR_TWO_ENABLE								 2
#define UARTIN_PIR_ONE_ENABLE											 3
#define UARTIN_PIR_TWO_ENABLE											 4
#define UARTIN_DS1820_ONE_ENABLE										 5
#define UARTIN_DS1820_TWO_ENABLE										 6
#define UARTIN_FOTOSENSOR_READ_INTERVAL							 7
#define UARTIN_FOTOSENSOR_READ_TOLERANCE							 8
#define UARTIN_DS1820_READ_INTERVAL									 9
#define UARTIN_SET_SYSTEMTIME											 10

#define UARTIN_BME280_READ_INTERVAL									 11
#define UARTIN_BME280_ENABLE											 12

#define UARTIN_MOTIONLIGHT_ENABLE									 13
#define UARTIN_NIGHTLIGHT_ENABLE										 14
#define UARTIN_LIGHT_BRIGHTNESS										 15
#define UARTIN_LIGHT_BRIGHTNESS_ENABLE								 16


// Commanddata
#define UART_IN_LIGHT_ON												 1
#define UART_IN_LIGHT_OFF												 2
#define UART_IN_MOTIONLIGHT_TIME										 3
#define UART_IN_NIGHTLIGHT_TIME										 4
#define UART_IN_SET_LIGHT_MODE										 5
#define UART_IN_SET_RGBWBOARD_DATA									 6
#define UART_IN_SET_RGBWBOARD_CONFIG								 7
#define UART_IN_SET_WS2812_MODE										 8
#define UART_IN_SET_WS2812_CONFIG									 9
#define UART_IN_RGBWBOARD_REBOOT										 10
#define UART_IN_RGBWBOARD_FACTORY_RESET							 11
#define UART_IN_RGBWBOARD_WS2812_OFF								 12
#define UART_IN_RGBWBOARD_WS2812_RED								 13
#define UART_IN_RGBWBOARD_WS2812_GREEN								 14
#define UART_IN_RGBWBOARD_WS2812_BLUE								 15
#define UART_IN_NIGHTLIGHT_TIME_ON									 16
#define UART_IN_NIGHTLIGHT_TIME_OFF									 17


int myerr;

int boardnr;
int modenr;

int rval;
int gval;
int bval;
int wval;
int temphour;
int tempmin;

int i2cchangemode;
int i2crchangetime;
int i2cgchangetime;
int i2cbchangetime;
int i2cwchangetime;

void system_command(void);