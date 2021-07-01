#include "../header/system.h"

void fourchamp_reboot(int boardnumber) {
	
  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(8);  // Mode Reboot
    i2c_write(1);  // Reboot Bit

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Reboot\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_factory_reset(int boardnumber) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(9);  // Mode Factory Reset
    i2c_write(1);  // Factory Reset Bit

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Factory Reset\n", boardnumber);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_mute(int boardnumber, uint8_t ampnumber, uint8_t mute) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  // Buffer Addr
    i2c_write(1);  // Mode Mute
    i2c_write(ampnumber);  // Amp Number
    i2c_write(mute);

    i2c_stop();
    if (mute == 1) {
      snprintf(buf, 50, "4CH Amp %d => Mute Amp %d Mute\n", boardnumber, ampnumber);
    } else {
    	snprintf(buf, 50, "4CH Amp %d => Mute Amp %d Unmute\n", boardnumber, ampnumber);
    }
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_input(int boardnumber, uint8_t ampnumber, uint8_t inputch) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(2);  			// Mode Input
    i2c_write(ampnumber);  // Amp Number
    i2c_write(inputch);		// Input CH (1-4)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Input CH Amp %d set to %d\n", boardnumber, ampnumber, inputch);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_gain(int boardnumber, uint8_t ampnumber, uint8_t gain) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(3);  			// Mode Gain
    i2c_write(ampnumber);  // Amp Number
    i2c_write(gain);			// Gain (0-14)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Gain Amp %d set to %d\n", boardnumber, ampnumber, gain);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_volume(int boardnumber, uint8_t ampnumber, uint8_t volume) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(4);  			// Mode Volume
    i2c_write(ampnumber);  // Amp Number
    i2c_write(volume);		// Volume (0-14)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Volume Amp %d set to %d\n", boardnumber, ampnumber, volume);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_treble(int boardnumber, uint8_t ampnumber, uint8_t treble) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(5);  			// Mode Treble
    i2c_write(ampnumber);  // Amp Number
    i2c_write(treble);		// Treble (0-14)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Treble Amp %d set to %d\n", boardnumber, ampnumber, treble);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_middle(int boardnumber, uint8_t ampnumber, uint8_t middle) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(6);  			// Mode Middle
    i2c_write(ampnumber);  // Amp Number
    i2c_write(middle);		// Middle (0-14)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Middle Amp %d set to %d\n", boardnumber, ampnumber, middle);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}

void fourchamp_bass(int boardnumber, uint8_t ampnumber, uint8_t bass) {

  unsigned char address;
  address = get_4champboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) { // 4CH Amp Board bereit zum schreiben?
  
    i2c_write(1);  			// Buffer Addr
    i2c_write(7);  			// Mode Bass
    i2c_write(ampnumber);  // Amp Number
    i2c_write(bass);		   // Bass (0-14)

    i2c_stop();
    snprintf(buf, 50, "4CH Amp %d => Bass Amp %d set to %d\n", boardnumber, ampnumber, bass);
    uart_puts(buf);
  } else {
    i2c_stop();
  }
}