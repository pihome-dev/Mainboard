#include "../header/system.h"

void boards_init(void) {
  
  rgbwboard_connected = 0;
  dreizweichboards_connected = 0;
  vierchampboards_connected = 0;
  
  for (int i = 0; i < 3; i++) {
    
    for (int u = 0; u < 8; u++) {
      boardsconfig[i][u] = 0;
    }
  }
}

//
//
// Boardfunctionen
//
//

unsigned char get_rgbwboard_addr(int boardnumber) {
  unsigned char adr;
  switch(boardnumber) {
    case 1:
      adr = RGBWBOARD_ONE_ADDRESS;
      break;
    case 2:
      adr = RGBWBOARD_TWO_ADDRESS;
      break;
    case 3:
      adr = RGBWBOARD_THREE_ADDRESS;
      break;
    case 4:
      adr = RGBWBOARD_FOUR_ADDRESS;
      break;
    case 5:
      adr = RGBWBOARD_FIVE_ADDRESS;
      break;
    case 6:
      adr = RGBWBOARD_SIX_ADDRESS;
      break;
    case 7:
      adr = RGBWBOARD_SEVEN_ADDRESS;
      break;
    case 8:
      adr = RGBWBOARD_EIGHT_ADDRESS;
      break;
    default:
      break;
  }
  
  return adr;
}

unsigned char get_32chboard_addr(int boardnumber) {
  unsigned char adr;
  switch(boardnumber) {
    case 1:
      adr = DREIZWEICHPWMBOARD_ONE_ADDRESS;
      break;
    case 2:
      adr = DREIZWEICHPWMBOARD_TWO_ADDRESS;
      break;
    case 3:
      adr = DREIZWEICHPWMBOARD_THREE_ADDRESS;
      break;
    case 4:
      adr = DREIZWEICHPWMBOARD_FOUR_ADDRESS;
      break;
    case 5:
      adr = DREIZWEICHPWMBOARD_FIVE_ADDRESS;
      break;
    case 6:
      adr = DREIZWEICHPWMBOARD_SIX_ADDRESS;
      break;
    case 7:
      adr = DREIZWEICHPWMBOARD_SEVEN_ADDRESS;
      break;
    case 8:
      adr = DREIZWEICHPWMBOARD_EIGHT_ADDRESS;
      break;
    default:
      break;
  }
  
  return adr;
}

unsigned char get_4champboard_addr(int boardnumber) {
  unsigned char adr;
  switch(boardnumber) {
    case 1:
      adr = VIERCHAMPBOARD_ONE_ADDRESS;
      break;
    case 2:
      adr = VIERCHAMPBOARD_TWO_ADDRESS;
      break;
    case 3:
      adr = VIERCHAMPBOARD_THREE_ADDRESS;
      break;
    case 4:
      adr = VIERCHAMPBOARD_FOUR_ADDRESS;
      break;
    case 5:
      adr = VIERCHAMPBOARD_FIVE_ADDRESS;
      break;
    case 6:
      adr = VIERCHAMPBOARD_SIX_ADDRESS;
      break;
    case 7:
      adr = VIERCHAMPBOARD_SEVEN_ADDRESS;
      break;
    case 8:
      adr = VIERCHAMPBOARD_EIGHT_ADDRESS;
      break;
    default:
      break;
  }
  
  return adr;
}

void rgbwboards_seach(void) {
  unsigned char addr;
  
  for (int b = 0; b < 8; b++) {
    addr = get_rgbwboard_addr(b);
    if(!(i2c_start(addr+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
	   i2c_stop();
	   boardsconfig[RGBWBOARDS][b] = 1;
	   rgbwboard_connected++;
    } else {
	   i2c_stop();
  	   boardsconfig[RGBWBOARDS][b] = 0;
    }
  }
}

void dreizweichboards_search(void) {
  unsigned char addr;
  
  for (int b = 0; b < 8; b++) {
    addr = get_32chboard_addr(b);
    if(!(i2c_start(addr+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
	   i2c_stop();
	   boardsconfig[DREIZWEICHPEMBOARDS][b] = 1;
	   dreizweichboards_connected++;
    } else {
	   i2c_stop();
  	   boardsconfig[DREIZWEICHPEMBOARDS][b] = 0;
    }
  }
}

void vierchampboards_search(void) {
  unsigned char addr;
  
  for (int b = 0; b < 8; b++) {
    addr = get_4champboard_addr(b);
    if(!(i2c_start(addr+I2C_WRITE))) { // RGBW Board bereit zum schreiben?
	   i2c_stop();
	   boardsconfig[VIERCHAMPBOARDS][b] = 1;
	   vierchampboards_connected++;
    } else {
	   i2c_stop();
  	   boardsconfig[VIERCHAMPBOARDS][b] = 0;
    }
  }
}



// RGBW Boards

void rgbwboard_run_pwm_mode(int boardnumber, int modenumber) {

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
	 i2c_stop();
  } else {
	 i2c_stop();
  }
}

void rgbwboard_set_pwm_change_mode(int boardnumber, int modenumber) {
  
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

void rgbwboard_set_pwm_softlimit(int boardnumber, int softlimit) {
  
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

void rgbwboard_set_pwm_defaultchangetime(int boardnumber, int changetime) {
  
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

void rgbwboard_set_pwm_defaultchangetimeR(int boardnumber, int changetime) {
  
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

void rgbwboard_set_pwm_defaultchangetimeG(int boardnumber, int changetime) {
  
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

void rgbwboard_set_pwm_defaultchangetimeB(int boardnumber, int changetime) {
  
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

void rgbwboard_set_pwm_defaultchangetimeW(int boardnumber, int changetime) {
  
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