#define					UART_DATA								"D"

#define					UART_BME280_TEMPERATURE_VALUE		5
#define					UART_BME280_PRESSURE	_VALUE		6
#define					UART_BME280_HUMIDITY	_VALUE		7
#define					UART_BME280_ALTITUDE_VALUE			8

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

void output_on(void);
void output_off(void);
void uart_get_system_config(void);
void uart_get_data(void);