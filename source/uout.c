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
  
  uart_puts_P("Synctime: ");
  snprintf(buf, 50, "%d min\n", SYSTEMTIME_SYNCTIME);
  uart_puts(buf);
  uart_puts_P("\n\n");
  
  output_on();
}

void uart_get_systemtime(void) {
  snprintf(buf, 50, "!%s%02d\n", UART_GETDATA, UART_GET_SYSTEMTIME);
  uart_puts(buf);
}

void uart_get_connected_rgbwboards(void) {
	 output_off();
	
	 snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_ONE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD1]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_TWO_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD2]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_THREE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD3]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_FOUR_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD4]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_FIVE_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD5]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_SIX_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD6]);
    uart_puts(buf);
    
    snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_SEVEN_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD7]);
    uart_puts(buf);
    
	 snprintf(buf, 50, "!%s%d=%d\n", UART_SENDDATA, UART_RGBWBOARD_EIGHT_CONNECTED, boardsconfig[RGBWBOARDS][RGBWBOARD8]);
    uart_puts(buf); 
    
    output_on();
}