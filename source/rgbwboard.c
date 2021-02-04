#include "../header/system.h"

void rgbwboard_run_pwm_mode(int boardnumber, int modenumber) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(2);  // Board Select (Running Mode)
	 i2c_write(modenumber);  // PWM Mode Number to run
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void rgbwboard_set_pwm_mode_data(int boardnumber, int modenumber, uint8_t rchannel, uint8_t gchannel, uint8_t bchannel, uint8_t wchannel) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);

  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(1);  // Board Select (PWM Data)
    i2c_write(1);  // Set PWM Mode Data
    i2c_write(modenumber);  // PWM Mode Number to write
    i2c_write(rchannel);    // R PWM Channel Value
    i2c_write(gchannel);    // G PWM Channel Value
    i2c_write(bchannel);    // B PWM Channel Value
    i2c_write(wchannel);    // W PWM Channel Value

    i2c_write(10);    // R Channel Changetime
    i2c_write(10);    // G Channel Changetime
    i2c_write(10);    // B Channel Changetime
    i2c_write(10);    // W Channel Changetime

    i2c_write(1);    // Changemode

    i2c_stop();
  } else {
    i2c_stop();
  }
}