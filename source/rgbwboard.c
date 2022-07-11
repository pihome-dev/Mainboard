#include "../header/system.h"

void rgbwboard_run_pwm_mode(int boardnumber, uint8_t modenumber) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?

    i2c_write(1);  					// Buffer Addr
    i2c_write(2);  					// Board Select (Running Mode)
	 i2c_write(modenumber);  		// PWM Mode Number to run
	 
	 i2c_stop();
  } else {
	 i2c_stop();
  }
  
}

void rgbwboard_set_pwm_mode_data(int boardnumber, uint8_t modenumber, uint8_t rchannel, uint8_t gchannel, uint8_t bchannel, uint8_t wchannel) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);

  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  			 // Buffer Addr
    i2c_write(1);  			 // Board Select (PWM Data)
    i2c_write(modenumber);  // PWM Mode Number to write
    i2c_write(rchannel);    // R PWM Channel Value
    i2c_write(gchannel);    // G PWM Channel Value
    i2c_write(bchannel);    // B PWM Channel Value
    i2c_write(wchannel);    // W PWM Channel Value

    i2c_stop();
  } else {
    i2c_stop();
  }
}

void rgbwboard_set_pwm_mode_config(int boardnumber, uint8_t modenumber, uint8_t changemode, uint8_t changetimer, uint8_t changetimeg, uint8_t changetimeb, uint8_t changetimew) {
  
unsigned char address;
  address = get_rgbwboard_addr(boardnumber);

  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(3);  				// Board Select (PWM Config)
    i2c_write(modenumber);  	// PWM Mode Number
    i2c_write(changemode);    // PWM Changemode Value
    i2c_write(changetimer);   // R PWM Changetime Value
    i2c_write(changetimeg);   // G PWM Changetime Value
    i2c_write(changetimeb);   // B PWM Changetime Value
	 i2c_write(changetimew);   // W PWM Changetime Value

    i2c_stop();
  } else {
    i2c_stop();
  }
  
}




void rgbwboard_set_ws2812_mode_data(int boardnumber, uint8_t modenumber, uint8_t lednumber,  uint8_t rchannel, uint8_t gchannel, uint8_t bchannel) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?

    i2c_write(1);  				// Buffer Addr
    i2c_write(6);  				// Board Select (WS2812 Mode)
	 i2c_write(modenumber);    // WS2812 Mode Number to run
	 i2c_write(lednumber);  	// WS2812 Lednumber Number
	 i2c_write(rchannel);  	   // WS2812 Mode+Led RValue
	 i2c_write(gchannel);  		// WS2812 Mode+Led GValue
	 i2c_write(bchannel);  		// WS2812 Mode+Led BValue
	 
	 i2c_stop();
  } else {
	 i2c_stop();
  }

}

void rgbwboard_run_ws2812_mode(int boardnumber, uint8_t modenumber) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?

    i2c_write(1);  // Buffer Addr
    i2c_write(7);  // Board Select (Running Mode)
	 i2c_write(modenumber);  // PWM Mode Number to run
	 
	 i2c_stop();
  } else {
	 i2c_stop();
  }
  
}

void rgbwboard_set_num_ws2812(int boardnumber, uint8_t num_of_leds) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(8);  				// Set WS2812 Number of LED Mode
    i2c_write(num_of_leds);   // Number of LEDs

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => Number of WS2812 Set to %d\n", boardnumber, num_of_leds);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_set_all_ws2812_red(int boardnumber, uint8_t brightness) {
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(9);  				// Set all WS2812 Red
    i2c_write(brightness);    // Red Brightness

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => All WS2812 Set to Red (%d %)\n", boardnumber, brightness);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_set_all_ws2812_green(int boardnumber, uint8_t brightness) {
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(10);  				// Set all WS2812 Green
    i2c_write(brightness);    // Green Brightness

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => All WS2812 Set to Green (%d %)\n", boardnumber, brightness);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_set_all_ws2812_blue(int boardnumber, uint8_t brightness) {
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(11);  				// Set all WS2812 Blue
    i2c_write(brightness);    // Blue Brightness

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => All WS2812 Set to Blue (%d %)\n", boardnumber, brightness);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_ws2812_off(int boardnumber) {
  rgbwboard_run_ws2812_mode(boardnumber, 0);
}



void rgbwboard_reboot(int boardnumber) {
	
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(4);  // Board Select (PWM Data)
    i2c_write(1);  // PWM Mode Number to write

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => Reboot\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_factory_reset(int boardnumber){

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(5);  // Board Select (PWM Data)
    i2c_write(1);  // PWM Mode Number to write

    i2c_stop();
    snprintf(buf, 50, "RGBWBoard %d => Factory Reset\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void rgbwboard_readmodevalues(int boardnumber, uint8_t modenumber) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  snprintf(buf, 50, "I2C Start Write\n");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
    snprintf(buf, 50, "Ok\n");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(12);	      // Read Channelvalues from Modenumber
    i2c_write(modenumber);
    i2c_stop();
    
    snprintf(buf, 50, "I2C Stop OK\n");
    uart_puts(buf);    

    readdata[0] = 0;
    
    wdt_reset();
    _delay_ms(50);
    wdt_reset();
    
    snprintf(buf, 50, "I2C Start Read\n");
    uart_puts(buf);
    
    if (!(i2c_rep_start(address+I2C_READ))) {        // set device address and read mode
      snprintf(buf, 50, "Ok\n");
      uart_puts(buf);
      wdt_reset();
      
      readcount = i2c_readAck();
      readdata[0] = readcount;
      
      snprintf(buf, 50, "I2C Read 0: %d\n", readdata[0]);
      uart_puts(buf);
      
      for (int i=1;i<readdata[0];i++) {
        wdt_reset();
        if (i==readdata[0]-1) {
          readdata[i] = i2c_readNak();      // read last byte
        } else {
          readdata[i] = i2c_readAck();      // read bytes
        }
        snprintf(buf, 50, "I2C Read %d: %d\n", i, readdata[i]);
        uart_puts(buf);
        wdt_reset();
      }
      i2c_stop();
      snprintf(buf, 50, "I2C Stop OK\n");
      uart_puts(buf);
    }      
  }
}

void rgbwboard_readlivevalues(int boardnumber) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  snprintf(buf, 50, "I2C Start Write\n");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
    snprintf(buf, 50, "Ok\n");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(13);	      // Read Channelvalues from Modenumber
    i2c_stop();
    
    snprintf(buf, 50, "I2C Stop OK\n");
    uart_puts(buf);    

    readdata[0] = 0;
    
    wdt_reset();
    _delay_ms(50);
    wdt_reset();
    
    snprintf(buf, 50, "I2C Start Read\n");
    uart_puts(buf);
    
    if (!(i2c_rep_start(address+I2C_READ))) {        // set device address and read mode
      snprintf(buf, 50, "Ok\n");
      uart_puts(buf);
      wdt_reset();
      
      readcount = i2c_readAck();
      readdata[0] = readcount;
      
      snprintf(buf, 50, "I2C Read 0: %d\n", readdata[0]);
      uart_puts(buf);
      
      for (int i=1;i<readdata[0];i++) {
        wdt_reset();
        if (i==readdata[0]-1) {
          readdata[i] = i2c_readNak();      // read last byte
        } else {
          readdata[i] = i2c_readAck();      // read bytes
        }
        snprintf(buf, 50, "I2C Read %d: %d\n", i, readdata[i]);
        uart_puts(buf);
        wdt_reset();
      }
      i2c_stop();
      snprintf(buf, 50, "I2C Stop OK\n");
      uart_puts(buf);
    }      
  }
}
