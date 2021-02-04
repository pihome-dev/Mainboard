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


// Commanddata
#define UART_IN_LIGHT_ON												 1
#define UART_IN_LIGHT_OFF												 2
#define UART_IN_MOTIONLIGHT_TIME										 3
#define UART_IN_NIGHTLIGHT_TIME										 4
#define UART_IN_SET_LIGHT_MODE										 5
#define UART_IN_SET_RGBWBOARD_DATA									 6

int boardnr;
int modenr;

uint8_t rval;
uint8_t gval;
uint8_t bval;
uint8_t wval;

void system_command(void);