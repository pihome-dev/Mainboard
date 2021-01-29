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
// Search
//
//

void rgbwboards_search(void) {

  // RGBW Board 1
  if(!(i2c_start(RGBWBOARD_ONE_ADDRESS+I2C_WRITE))) {    // RGBW Board 1 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD1] = 1;			   // RGBW Board 1 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD1] = 0;			   // RGBW Board 1 not exist
  }
  
  // RGBW Board 2
  if(!(i2c_start(RGBWBOARD_TWO_ADDRESS+I2C_WRITE))) {    // RGBW Board 2 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD2] = 1;			   // RGBW Board 2 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD2] = 0;			   // RGBW Board 2 not exist
  }

  // RGBW Board 3
  if(!(i2c_start(RGBWBOARD_THREE_ADDRESS+I2C_WRITE))) {  // RGBW Board 3 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD3] = 1;			   // RGBW Board 3 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD3] = 0;			   // RGBW Board 3 not exist
  }
 
  // RGBW Board 4
  if(!(i2c_start(RGBWBOARD_FOUR_ADDRESS+I2C_WRITE))) {   // RGBW Board 4 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD4] = 1;			   // RGBW Board 4 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD4] = 0;			   // RGBW Board 4 not exist
  }

  // RGBW Board 5
  if(!(i2c_start(RGBWBOARD_FIVE_ADDRESS+I2C_WRITE))) {   // RGBW Board 5 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD5] = 1;			   // RGBW Board 5 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD5] = 0;			   // RGBW Board 5 not exist
  }
  
  // RGBW Board 6
  if(!(i2c_start(RGBWBOARD_SIX_ADDRESS+I2C_WRITE))) {    // RGBW Board 6 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD6] = 1;			   // RGBW Board 6 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD6] = 0;			   // RGBW Board 6 not exist
  }

  // RGBW Board 7
  if(!(i2c_start(RGBWBOARD_SEVEN_ADDRESS+I2C_WRITE))) {  // RGBW Board 7 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD7] = 1;			   // RGBW Board 7 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD7] = 0;			   // RGBW Board 7 not exist
  }
  
  // RGBW Board 8
  if(!(i2c_start(RGBWBOARD_EIGHT_ADDRESS+I2C_WRITE))) {  // RGBW Board 8 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[RGBWBOARDS][RGBWBOARD8] = 1;			   // RGBW Board 8 exist
  } else {
	 i2c_stop();
  	 boardsconfig[RGBWBOARDS][RGBWBOARD8] = 0;			   // RGBW Board 8 not exist
  }

}


void dreizweichpwmboards_search(void) {

  // 32CH PWM Board 1
  if(!(i2c_start(DREIZWEICHPWMBOARD_ONE_ADDRESS+I2C_WRITE))) {    		// 32CH PWM Board 1 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD1] = 1;			   // 32CH PWM Board 1 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD1] = 0;			   // 32CH PWM Board 1 not exist
  }
  
  // 32CH PWM Board 2
  if(!(i2c_start(DREIZWEICHPWMBOARD_TWO_ADDRESS+I2C_WRITE))) {    		// 32CH PWM Board 2 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD2] = 1;			   // 32CH PWM Board 2 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD2] = 0;			   // 32CH PWM Board 2 not exist
  }
  
  // 32CH PWM Board 3
  if(!(i2c_start(DREIZWEICHPWMBOARD_THREE_ADDRESS+I2C_WRITE))) {  		// 32CH PWM Board 3 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD3] = 1;			   // 32CH PWM Board 3 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD3] = 0;			   // 32CH PWM Board 3 not exist
  }
  
  // 32CH PWM Board 4
  if(!(i2c_start(DREIZWEICHPWMBOARD_FOUR_ADDRESS+I2C_WRITE))) {   		// 32CH PWM Board 4 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD4] = 1;			   // 32CH PWM Board 4 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD4] = 0;			   // 32CH PWM Board 4 not exist
  }
  
  // 32CH PWM Board 5
  if(!(i2c_start(DREIZWEICHPWMBOARD_FIVE_ADDRESS+I2C_WRITE))) {   		// 32CH PWM Board 5 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD5] = 1;			   // 32CH PWM Board 5 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD5] = 0;			   // 32CH PWM Board 5 not exist
  }
  
  // 32CH PWM Board 6
  if(!(i2c_start(DREIZWEICHPWMBOARD_SIX_ADDRESS+I2C_WRITE))) {    		// 32CH PWM Board 6 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD6] = 1;			   // 32CH PWM Board 6 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD6] = 0;			   // 32CH PWM Board 6 not exist
  }
  
  // 32CH PWM Board 7
  if(!(i2c_start(DREIZWEICHPWMBOARD_SEVEN_ADDRESS+I2C_WRITE))) {  		// 32CH PWM Board 7 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD7] = 1;			   // 32CH PWM Board 7 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD7] = 0;			   // 32CH PWM Board 7 not exist
  }
  
  // 32CH PWM Board 8
  if(!(i2c_start(DREIZWEICHPWMBOARD_EIGHT_ADDRESS+I2C_WRITE))) {  		// 32CH PWM Board 8 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD8] = 1;			   // 32CH PWM Board 8 exist
  } else {
	 i2c_stop();
  	 boardsconfig[DREIZWEICHPEMBOARDS][DREIZWEICHBOARD8] = 0;			   // 32CH PWM Board 8 not exist
  }

}

void vierchampboards_search(void) {

  // 4CH PWM Board 1
  if(!(i2c_start(VIERCHAMPBOARD_ONE_ADDRESS+I2C_WRITE))) {    		// 4CH Amplifier Board 1 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD1] = 1;			   	// 4CH Amplifier Board 1 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD1] = 0;			   	// 4CH Amplifier Board 1 not exist
  }
  
  // 4CH PWM Board 2
  if(!(i2c_start(VIERCHAMPBOARD_TWO_ADDRESS+I2C_WRITE))) {    		// 4CH Amplifier Board 2 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD2] = 1;			   	// 4CH Amplifier Board 2 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD2] = 0;			   	// 4CH Amplifier Board 2 not exist
  }
  
  // 4CH PWM Board 3
  if(!(i2c_start(VIERCHAMPBOARD_THREE_ADDRESS+I2C_WRITE))) {  		// 4CH Amplifier Board 3 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD3] = 1;			   	// 4CH Amplifier Board 3 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD3] = 0;			   	// 4CH Amplifier Board 3 not exist
  }
  
  // 4CH PWM Board 4
  if(!(i2c_start(VIERCHAMPBOARD_FOUR_ADDRESS+I2C_WRITE))) {   		// 4CH Amplifier Board 4 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD4] = 1;			   	// 4CH Amplifier Board 4 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD4] = 0;			   	// 4CH Amplifier Board 4 not exist
  }
  
  // 4CH PWM Board 5
  if(!(i2c_start(VIERCHAMPBOARD_FIVE_ADDRESS+I2C_WRITE))) {   		// 4CH Amplifier Board 5 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD5] = 1;			   	// 4CH Amplifier Board 5 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD5] = 0;			   	// 4CH Amplifier Board 5 not exist
  }
  
  // 4CH PWM Board 6
  if(!(i2c_start(VIERCHAMPBOARD_SIX_ADDRESS+I2C_WRITE))) {    		// 4CH Amplifier Board 6 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD6] = 1;			   	// 4CH Amplifier Board 6 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD6] = 0;			  	   // 4CH Amplifier Board 6 not exist
  }
  
  // 4CH PWM Board 7
  if(!(i2c_start(VIERCHAMPBOARD_SEVEN_ADDRESS+I2C_WRITE))) {  		// 4CH Amplifier Board 7 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD7] = 1;			 	   // 4CH Amplifier Board 7 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD7] = 0;			   	// 4CH Amplifier Board 7 not exist
  }
  
  // 4CH PWM Board 8
  if(!(i2c_start(VIERCHAMPBOARD_EIGHT_ADDRESS+I2C_WRITE))) {  		// 4CH Amplifier Board 8 bereit zum schreiben?
	 i2c_stop();
	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD8] = 1;			   	// 4CH Amplifier Board 8 exist
  } else {
	 i2c_stop();
  	 boardsconfig[VIERCHAMPBOARDS][VIERCHBOARD8] = 0;			   	// 4CH Amplifier Board 8 not exist
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


void send_single_pwm_value_to_rgbwboard(int boardnumber, int pwmchannel, int pwmvalue) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);

  if (pwmvalue >= 0 || pwmvalue <= 255) {
    if(!(i2c_start(address+I2C_WRITE))) {				// RGBW Board bereit zum schreiben?
      i2c_write(1);  										// Buffer Addr
      i2c_write(5);  										// Board Select (Running Mode)
      i2c_write(pwmchannel);
	   i2c_write(pwmvalue);  								// PWM Mode Number to run
	   i2c_stop();
    } else {
	   i2c_stop();
    }
  }
}

void send_multi_pwm_value_to_rgbwboard(int boardnumber, int redvalue, int greenvalue, int bluevalue, int whitevalue) {

  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if (redvalue >= 0 && redvalue <= 255 && greenvalue >= 0 && greenvalue <= 255 && bluevalue >= 0 && bluevalue <= 255 && whitevalue >= 0 && whitevalue <= 255) {
    if(!(i2c_start(address+I2C_WRITE))) {				// RGBW Board bereit zum schreiben?
      i2c_write(1);  										// Buffer Addr
      i2c_write(6);  										// Board Select (Running Mode)
      i2c_write(redvalue);
	   i2c_write(greenvalue);
	   i2c_write(bluevalue);
		i2c_write(whitevalue);
	   i2c_stop();
    } else {
	   i2c_stop();
    }
  }
}

void send_mode_to_rgbwboard(int boardnumber, int modenumber) {
	
  unsigned char address;
  address = get_rgbwboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {				// RGBW Board bereit zum schreiben?
    i2c_write(1);  											// Buffer Addr
    i2c_write(4);  											// Board Select (Running Mode)
	 i2c_write(modenumber);  								// PWM Mode Number to run
	 i2c_stop();
  } else {
	 i2c_stop();
  }
  
}

void send_pwmtime_to_rgbwboard(int boardnumber, int uptime, int downtime) {

}

void send_config_to_rgbwboard(int boardnumber, int defaultuptime, int defaultdowntime, int pwmlimit, int autosave) {

}




void send_mode_to_32chboard(int boardnumber, int modenumber) {
	
  unsigned char address;
  address = get_32chboard_addr(boardnumber);
  
  if(!(i2c_start(address+I2C_WRITE))) {				// RGBW Board bereit zum schreiben?
    i2c_write(1);  											// Buffer Addr
    i2c_write(4);  											// Board Select (Running Mode)
	 i2c_write(modenumber);  								// PWM Mode Number to run
	 i2c_stop();
  } else {
	 i2c_stop();
  }
  
}