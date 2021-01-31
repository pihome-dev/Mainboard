#include "../header/system.h"

void output_on(void) {
  output_enabled = SENSOR_ENABLED;
}

void output_off(void) {
  output_enabled = SENSOR_DISABLED;
}

void uart_send_system_config(void) {
  output_off();
  
  // Fotosensor One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_ONE_ENABLE, fotosensor_one_enabled);
  uart_puts(buf);
  
  // Fotosensor Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_TWO_ENABLE, fotosensor_two_enabled);
  uart_puts(buf);
  
  // PIR One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_ONE_ENABLE, pir_one_enabled);
  uart_puts(buf);
  
  // PIR Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_TWO_ENABLE, pir_two_enabled);
  uart_puts(buf);
  
  // DS1820 One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_ONE_ENABLE, ds1820_one_enabled);
  uart_puts(buf);
  
  // DS1820 Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_TWO_ENABLE, ds1820_two_enabled);
  uart_puts(buf);
  
  // Fotosensor Read Interval
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_READ_INTERVAL, fotosensor_read_interval);
  uart_puts(buf);
  
  // Fotosensor Read Tolerance
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_READ_TOLERANCE, fotosensor_read_tolerance);
  uart_puts(buf);
  
  output_on();
}

void uart_send_system_data(void) {
  output_off();
  
  // Fotosensor One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_ONE_VALUE, fotosensor_one_value);
  uart_puts(buf);
  
  // Fotosensor Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_FOTOSENSOR_TWO_VALUE, fotosensor_two_value);
  uart_puts(buf);
  
  // PIR One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_ONE_VALUE, pir_one_value);
  uart_puts(buf);
  
  // PIR Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_PIR_TWO_VALUE, pir_two_value);
  uart_puts(buf);
  
  // DS1820 One enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_ONE_VALUE, ds1820_one_value);
  uart_puts(buf);
  
  // DS1820 Two enabled
  snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_DS1820_TWO_VALUE, ds1820_two_value);
  uart_puts(buf);
  
  output_on();
}

void uart_send_system_info(void) {
  output_off();
  
  uart_puts_P("\npiHOME Mainboard Information\n\n");
  uart_puts_P("Systemtime: ");
  snprintf(buf, 50, "%02d:%02d:%02d\n", systemhour, systemmin, systemsec);
  uart_puts(buf);
  
  uart_puts_P("Systemtime Synctime: ");
  snprintf(buf, 50, "%d min\n", SYSTEMTIME_SYNCTIME);
  uart_puts(buf);
  uart_puts_P("\n\n");
  
  output_on();
}

void uart_get_systemtime(void) {
  snprintf(buf, 50, "!%s%d\n", UART_GETDATA, UART_GET_SYSTEMTIME);
  uart_puts(buf);
}