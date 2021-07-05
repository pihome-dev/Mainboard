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
    
    snprintf(buf, 50, "4CH Amp %d => Gain Amp %d set to %d db (%d)\n", boardnumber, ampnumber, get_inputgain_value(gain), gain);
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
    snprintf(buf, 50, "4CH Amp %d => Volume Amp %d set to %d db (%d)\n", boardnumber, ampnumber, get_volume_value(volume) volume);
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

int get_inputgain_value(int data) {
  int //senddata, outval;
  switch (data) {
    case 1:
      //senddata = TDA7439_INPUT_GAIN_0DB;
      outval = 0;
      break;
    case 2:
      //senddata = TDA7439_INPUT_GAIN_2DB;
      outval = 2;
      break;
    case 3:
      //senddata = TDA7439_INPUT_GAIN_4DB;
      outval = 4;
      break;
    case 4:
      //senddata = TDA7439_INPUT_GAIN_6DB;
      outval = 6;
      break;
    case 5:
      //senddata = TDA7439_INPUT_GAIN_8DB;
		outval = 8;
      break;
    case 6:
      //senddata = TDA7439_INPUT_GAIN_10DB;
      outval = 10;
      break;
    case 7:
      //senddata = TDA7439_INPUT_GAIN_12DB;
      outval = 12;
      break;
    case 8:
      //senddata = TDA7439_INPUT_GAIN_14DB;
      outval = 14;
      break;
    case 9:
      //senddata = TDA7439_INPUT_GAIN_16DB;
      outval = 16;
      break;
    case 10:
      //senddata = TDA7439_INPUT_GAIN_18DB;
      outval = 18;
      break;
    case 11:
      //senddata = TDA7439_INPUT_GAIN_20DB;
      outval = 20;
      break;
    case 12:
      //senddata = TDA7439_INPUT_GAIN_22DB;
      outval = 22;
      break;
    case 13:
      //senddata = TDA7439_INPUT_GAIN_24DB;
      outval = 24;
      break;
    case 14:
      //senddata = TDA7439_INPUT_GAIN_26DB;
      outval = 26;
      break;
    case 15:
      //senddata = TDA7439_INPUT_GAIN_28DB;
      outval = 28;
      break;
    case 16:
      //senddata = TDA7439_INPUT_GAIN_30DB;
      outval = 30;
      break;
    default:
      break;
  }
  
  return outval;
}

int get_volume_value(int data) {
  int //senddata, outval;
  switch (data) {
    case 1:
      //senddata = TDA7439_VOLUME_0DB;
      outval = 0;
      break;
    case 2:
      //senddata = TDA7439_VOLUME_1DB;
      outval = -1;
      break;
    case 3:
      //senddata = TDA7439_VOLUME_2DB;
		outval = -2;
      break;
    case 4:
      //senddata = TDA7439_VOLUME_3DB;
      outval = -3;
      break;
    case 5:
      //senddata = TDA7439_VOLUME_4DB;
      outval = -4;
      break;
    case 6:
      //senddata = TDA7439_VOLUME_5DB;
      outval = -5;
      break;
    case 7:
      //senddata = TDA7439_VOLUME_6DB;
      outval = -6;
      break;
    case 8:
      //senddata = TDA7439_VOLUME_7DB;
      outval = -7;
      break;
    case 9:
      //senddata = TDA7439_VOLUME_8DB;
      outval = -8;
      break;
    case 10:
      //senddata = TDA7439_VOLUME_16DB;
      outval = -16;
      break;
    case 11:
      //senddata = TDA7439_VOLUME_24DB;
      outval = -24;
      break;
    case 12:
      //senddata = TDA7439_VOLUME_32DB;
      outval = -32;
      break;
    case 13:
      //senddata = TDA7439_VOLUME_40DB;
      outval = -40;
      break;
    default:
      //senddata = TDA7439_VOLUME_MUTE;
      outval = 0;
      break;
  }
  
  return outval;
}