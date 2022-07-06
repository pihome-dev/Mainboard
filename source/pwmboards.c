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
    i2c_write(1);  				// Mode Change Runmode
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

void pwmboard_readmodevalues(int boardnumber, uint8_t modenumber) {
  
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  snprintf(buf, 50, "I2C Start Write");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // 32CH PWM Board bereit zum schreiben?
    snprintf(buf, 50, "Ok");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(5);					// Read Channelvalues form Modenumber
    i2c_write(modenumber);
    i2c_stop();
    
	 snprintf(buf, 50, "I2C Stop OK");
    uart_puts(buf);    
    
    snprintf(buf, 50, "I2C Start Read");
    uart_puts(buf);

    uint8_t retcount;
    uint8_t retdata[50];
    retdata[0] = 0;
    
    if (!(i2c_start(address+I2C_READ))) {        // set device address and read mode
      snprintf(buf, 50, "Ok");
      uart_puts(buf);
    
      retcount = i2c_readAck();      // read first byte
      snprintf(buf, 50, "I2C Read %d", retcount);
      uart_puts(buf);
    
      if (retcount > 0) {
    	
    	  retdata[0] = retcount;
        for (int readi = 1; readi < retcount; readi++) {
          if (readi == retcount) {
            retdata[readi] = i2c_readNak();
          } else {
            retdata[readi] = i2c_readAck();
          }
        }
      }
    
      i2c_stop();
      snprintf(buf, 50, "I2C Stop OK");
      uart_puts(buf);
    }
    
    if (retdata[0] > 0) {
    	for (int i=1; i<retdata[0];i++) {
        snprintf(buf, 50, "PWM Mode %d CH%d => %d\n", modenumber, i, retdata[i]);
        uart_puts(buf);
      }
    }
  }
}