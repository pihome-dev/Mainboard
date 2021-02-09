#include "../header/system.h"

void rgbwboard_run_pwm_mode(int boardnumber, uint16_t modenumber) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?

    i2c_write(1);  // Buffer Addr
    i2c_write(2);  // Board Select (Running Mode)
	 i2c_write(modenumber);  // PWM Mode Number to run
	 
	 i2c_stop();
  } else {
	 i2c_stop();
  }
  
}

void rgbwboard_set_pwm_mode_data(int boardnumber, uint16_t modenumber, uint16_t rchannel, uint16_t gchannel, uint16_t bchannel, uint16_t wchannel) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);

  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(1);  // Board Select (PWM Data)
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

void rgbwboard_set_pwm_mode_config(int boardnumber, uint16_t modenumber, uint16_t changemode, uint16_t changetimer, uint16_t changetimeg, uint16_t changetimeb, uint16_t changetimew) {
  
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





void rgbwboard_set_ws2812_mode_data(int boardnumber, uint16_t modenumber, uint16_t lednumber,  uint16_t rchannel, uint16_t gchannel, uint16_t bchannel) {

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

void rgbwboard_run_ws2812_mode(int boardnumber, uint16_t modenumber) {

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







void rgbwboard_reboot(int boardnumber) {
	
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(4);  // Board Select (PWM Data)
    i2c_write(1);  // PWM Mode Number to write

    i2c_stop();
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
  } else {
    i2c_stop();
  }
}