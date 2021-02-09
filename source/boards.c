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
    addr = get_rgbwboard_addr(b + 1);
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
    addr = get_32chboard_addr(b + 1);
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
    addr = get_4champboard_addr(b + 1);
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