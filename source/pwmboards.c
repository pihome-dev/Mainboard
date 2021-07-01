#include "../header/system.h"

void pwmboard_reboot(int boardnumber) {
	
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(8);  // Mode Reboot
    i2c_write(1);  // Reboot Bit

    i2c_stop();
    snprintf(buf, 50, "PWM Board %d => Reboot\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void pwmboard_factory_reset(int boardnumber) {

  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(9);  // Mode Factory Reset
    i2c_write(1);  // Factory Reset Bit

    i2c_stop();
    snprintf(buf, 50, "PWM Board %d => Factory Reset\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void pwmboard_setmode(int boardnumber, uint8_t modenumber) {
	
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(2);  				// Mode Chnage Runmode
    i2c_write(modenumber);  	// Mode to Run

    i2c_stop();
    snprintf(buf, 50, "PWM Board %d => Set Runmode to %d\n", boardnumber, modenumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void pwmboard_setmodevalue(int boardnumber, uint8_t modenumber, uint8_t channel, uint8_t modevalue) {
	
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(1);  				// Mode Chnage Runmode
    i2c_write(modenumber);  	// Mode to Write
    i2c_write(channel);  		// Channel to Write
    i2c_write(modevalue);  	// Value to Write

    i2c_stop();
    snprintf(buf, 50, "PWM Board %d => Set Mode %d | CH %d | Val %d\n", boardnumber, modenumber, channel, modevalue);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}