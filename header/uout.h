#define					UART_SENDDATA							"D"
#define					UART_GETDATA							"C"


// SEND

#define					UART_FOTOSENSOR_ONE_VALUE			9
#define					UART_FOTOSENSOR_TWO_VALUE			10

#define					UART_PIR_ONE_VALUE					11
#define					UART_PIR_TWO_VALUE					12

#define					UART_DS1820_ONE_VALUE				13
#define					UART_DS1820_TWO_VALUE				14

#define					UART_FOTOSENSOR_ONE_ENABLE			15
#define					UART_FOTOSENSOR_TWO_ENABLE			16

#define					UART_PIR_ONE_ENABLE					17
#define					UART_PIR_TWO_ENABLE					18

#define					UART_DS1820_ONE_ENABLE				19
#define					UART_DS1820_TWO_ENABLE				20

#define					UART_FOTOSENSOR_READ_INTERVAL		21
#define					UART_FOTOSENSOR_READ_TOLERANCE	22

#define					UART_RGBWBOARD_ONE_CONNECTED		23
#define					UART_RGBWBOARD_TWO_CONNECTED		24
#define					UART_RGBWBOARD_THREE_CONNECTED	25
#define					UART_RGBWBOARD_FOUR_CONNECTED		26
#define					UART_RGBWBOARD_FIVE_CONNECTED		27
#define					UART_RGBWBOARD_SIX_CONNECTED		28
#define					UART_RGBWBOARD_SEVEN_CONNECTED	29
#define					UART_RGBWBOARD_EIGHT_CONNECTED	30

#define					UART_DS1820_READ_INTERVAL			31
#define					UART_PIR_RESET_TIME					32
#define					UART_BME280_READ_INTERVAL			33
#define					UART_BME280_TEMPERATURE				34
#define					UART_BME280_HUMIDITY					35
#define					UART_BME280_PRESSURE					36

#define					UART_LIGHT_MODE						37
#define					UART_MOTIONLIGHT_MODE				38
#define					UART_NIGHTLIGHT_MODE					39
#define					UART_MOTIONLIGHT_ENABLE				40
#define					UART_NIGHTLIGHT_ENABLE				41



// GET
#define					UART_GET_SYSTEMTIME					1

void output_on(void);
void output_off(void);
void uart_send_system_config(void);
void uart_send_system_data(void);
void uart_send_system_info(void);
void uart_get_systemtime(void);
void uart_get_connected_rgbwboards(void);