#include "system.h"

void output_on(void) {
  output_enabled = SENSOR_ENABLED;
}

void output_off(void) {
  output_enabled = SENSOR_DISABLED;
}

void uart_get_system_config(void) {
  output_off();
  
  // Fotosensor One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_ONE_ENABLE, fotosensor_one_enabled);
  uart_puts(buf);
  
  // Fotosensor Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_TWO_ENABLE, fotosensor_two_enabled);
  uart_puts(buf);
  
  // PIR One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_PIR_ONE_ENABLE, pir_one_enabled);
  uart_puts(buf);
  
  // PIR Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_PIR_TWO_ENABLE, pir_two_enabled);
  uart_puts(buf);
  
  // DS1820 One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_DS1820_ONE_ENABLE, ds1820_one_enabled);
  uart_puts(buf);
  
  // DS1820 Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_DS1820_TWO_ENABLE, ds1820_two_enabled);
  uart_puts(buf);
  
  // Fotosensor Read Interval
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_READ_INTERVAL, fotosensor_read_interval);
  uart_puts(buf);
  
  // Fotosensor Read Tolerance
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_READ_TOLERANCE, fotosensor_read_tolerance);
  uart_puts(buf);
  
  output_on();
}

void uart_get_data(void) {
  output_off();
  // Fotosensor One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_ONE_VALUE, fotosensor_one_value);
  uart_puts(buf);
  
  // Fotosensor Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_FOTOSENSOR_TWO_VALUE, fotosensor_two_value);
  uart_puts(buf);
  
  // PIR One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_PIR_ONE_VALUE, pir_one_value);
  uart_puts(buf);
  
  // PIR Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_PIR_TWO_VALUE, pir_two_value);
  uart_puts(buf);
  
  // DS1820 One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_DS1820_ONE_VALUE, ds1820_one_value);
  uart_puts(buf);
  
  // DS1820 Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_DATA, UART_DS1820_TWO_VALUE, ds1820_two_value);
  uart_puts(buf);
  output_on();
}