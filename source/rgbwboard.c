#include "../header/system.h"

void run_pwm_mode(int boardnumber, int modenumber) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(4);  // Board Select (Running Mode)
	 i2c_write(modenumber);  // PWM Mode Number to run
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_mode_data(int boardnumber, int modenumber, uint8_t rchannel, uint8_t gchannel, uint8_t bchannel, uint8_t wchannel) {

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
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_change_mode(int boardnumber, int modenumber) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(1);  // Change PWM Mode
    i2c_write(modenumber);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_softlimit(int boardnumber, int softlimit) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(2);  // Change PWM Mode
    i2c_write(softlimit);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_defaultchangetime(int boardnumber, int changetime) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(3);  // Change PWM Mode
    i2c_write(changetime);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_defaultchangetimeR(int boardnumber, int changetime) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(4);  // Change PWM Mode
    i2c_write(changetime);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_defaultchangetimeG(int boardnumber, int changetime) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(5);  // Change PWM Mode
    i2c_write(changetime);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_defaultchangetimeB(int boardnumber, int changetime) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(6);  // Change PWM Mode
    i2c_write(changetime);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void set_pwm_defaultchangetimeW(int boardnumber, int changetime) {
  
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {// RGBW Board bereit zum schreiben?
    i2c_write(1);  // Buffer Addr
    i2c_write(3);  // Board Select (Settings)
	 i2c_write(7);  // Change PWM Mode
    i2c_write(changetime);  // PWM Mode 0 / 1
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}