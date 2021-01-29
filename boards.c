#include "system.h"

void boards_init(void) {
  
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