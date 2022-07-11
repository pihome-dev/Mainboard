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

void pwmboard_setmodeconfig(int boardnumber, uint8_t modenumber, uint8_t channel, uint8_t speed, uint8_t changemode) {
	
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  				// Buffer Addr
    i2c_write(3);  				// Mode Change Runmode
    i2c_write(modenumber);  	// Mode to Write
    i2c_write(channel);
    i2c_write(speed);  		// Channel to Write
    i2c_write(changemode);  	// Value to Write

    i2c_stop();
    snprintf(buf, 50, "PWM Board %d => Set Config Mode %d | Speed %d | Change %d\n", boardnumber, modenumber, speed, changemode);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void pwmboard_readmodevalues(int boardnumber, uint8_t modenumber) {
  
  unsigned char address;
  address = get_32chboard_addr(boardnumber);

  snprintf(buf, 50, "I2C Start Write\n");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
    snprintf(buf, 50, "Ok\n");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(5);	      // Read Channelvalues from Modenumber
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

void pwmboard_readmodespeed(int boardnumber, uint8_t modenumber) {
  
  unsigned char address;
  address = get_32chboard_addr(boardnumber);

  snprintf(buf, 50, "I2C Start Write\n");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
    snprintf(buf, 50, "Ok\n");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(6);	      // Read Channelvalues from Modenumber
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

void pwmboard_readmodechange(int boardnumber, uint8_t modenumber) {
  
  unsigned char address;
  address = get_32chboard_addr(boardnumber);

  snprintf(buf, 50, "I2C Start Write\n");
  uart_puts(buf);
  if(!(i2c_start(address+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
    snprintf(buf, 50, "Ok\n");
    uart_puts(buf);
    i2c_write(1);             // Buffer Addr
    i2c_write(7);	      // Read Channelvalues from Modenumber
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
