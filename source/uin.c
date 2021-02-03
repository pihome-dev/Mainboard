#include "../header/system.h"

void system_command(void) {

int boardnr;
int modenr;
int rval;
int gval;
int bval;
int wval;

  switch (maincmd[0]) {
  	
    case UARTIN_SYSTEM:
      tmp[0] = maincmd[1];
	   tmp[1] = maincmd[2];
		tmp[2] = '\0';
      switch(atoi(tmp)) {
      	
        case UARTIN_FOTOSENSOR_ONE_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   fotosensor_one_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("Fotosensor One enabled\n");
			   } else {
			     uart_puts("Fotosensor One disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_FOTOSENSOR_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   fotosensor_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("Fotosensor Two enabled\n");
			   } else {
			     uart_puts("Fotosensor Two disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_PIR_ONE_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   pir_one_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("PIR One enabled\n");
			   } else {
			     uart_puts("PIR One disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_PIR_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   pir_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("PIR Two enabled\n");
			   } else {
			     uart_puts("PIR Two disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_DS1820_ONE_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   ds1820_one_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("DS1820 One enabled\n");
			   } else {
			     uart_puts("DS1820 One disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_DS1820_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   ds1820_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("DS1820 Two enabled\n");
			   } else {
			     uart_puts("DS1820 Two disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_FOTOSENSOR_READ_INTERVAL:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 99) {
			   fotosensor_read_interval = inttmp;
			   snprintf(buf, 50, "Fotosensor Readinterval set to %d seconds\n", inttmp);
    	  		uart_puts(buf);
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_FOTOSENSOR_READ_TOLERANCE:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
          tmp[2] = maincmd[5];
			 tmp[3] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 999) {
			   fotosensor_read_tolerance = inttmp;
			   snprintf(buf, 50, "Fotosensor Readtolerance set to %d\n", inttmp);
    	  		uart_puts(buf);
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_DS1820_READ_INTERVAL:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 99) {
			   ds1820_read_interval = inttmp;
			   snprintf(buf, 50, "DS1820 Readinterval set to %d seconds\n", inttmp);
    	  		uart_puts(buf);
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_SET_SYSTEMTIME:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 
			 tmp[0] = maincmd[5];
			 tmp[1] = maincmd[6];
			 tmp[2] = '\0';
			 inttmp2 = atoi(tmp);
			 
			 if (inttmp >= 0 && inttmp <= 23 && inttmp2 >= 0 && inttmp2 <= 59) {
				systemhour = inttmp;
				systemmin = inttmp2;
				systemtime_synctimer = 0;
			   uart_puts_P("Systemtime set\n");
			   systemclock_synced = 1;
			 }
          break;
          
        default:
          break;
      }
      
      break;
      
    case UARTIN_COMMAND:
      tmp[0] = maincmd[1];
	   tmp[1] = maincmd[2];
		tmp[2] = '\0';
      switch(atoi(tmp)) {
        
        case UART_IN_LIGHT_ON:
          light_on = LIGHT_ON;
          break;
        
        case UART_IN_LIGHT_OFF:
          light_on = LIGHT_ON;
          break;
          
        case UART_IN_MOTIONLIGHT_TIME:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 10 && inttmp <= 90) {
			   motionlight_time = inttmp;
			   eeprom_autosave();
			   snprintf(buf, 50, "Motionlighttime set to %d seconds\n", inttmp);
    	  		uart_puts(buf);
			 } else {
			   uart_puts_P("Wrong Motionlighttime. Time must between 10 and 90 seconds.\n");
			 }
          break;
        
        case UART_IN_NIGHTLIGHT_TIME:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 10 && inttmp <= 90) {
			   nightlight_time = inttmp;
			   eeprom_autosave();
			   snprintf(buf, 50, "Nightlighttime set to %d seconds\n", inttmp);
    	  		uart_puts(buf);
			 } else {
			   uart_puts_P("Wrong Nightlighttime. Time must between 10 and 90 seconds.\n");
			 }
          break;
          
        case UART_IN_SET_LIGHT_MODE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 6) {
			   light_mode = inttmp;
			   eeprom_autosave();
			   snprintf(buf, 50, "Lightmode set to Mode %d\n", inttmp);
    	  		uart_puts(buf);
			 } else {
			   uart_puts_P("Wrong Lightmode. Lightmode must between 0 and 6.\n");
			 }
          break;
          
        case UART_IN_SET_RGBWBOARD_DATA:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 boardnr = atoi(tmp);
						 
			 
			 int myerr = 0;
			 if (boardnr >= 1 && boardnr <= 8) { // Boardnumber
            tmp[0] = maincmd[4];
  			   tmp[1] = '\0';
  			   modenr = atoi(tmp);
			     if (modenr >= 1 && modenr <= 8) {

			       tmp[0] = maincmd[5];
			       tmp[1] = maincmd[6];
			       tmp[2] = maincmd[7];
  			       tmp[3] = '\0';
  			       rval = atoi(tmp);

			       tmp[0] = maincmd[8];
			       tmp[1] = maincmd[9];
			       tmp[2] = maincmd[10];
  			       tmp[3] = '\0';
  			       gval = atoi(tmp);

			       tmp[0] = maincmd[11];
			       tmp[1] = maincmd[12];
			       tmp[2] = maincmd[13];
  			       tmp[3] = '\0';
  			       bval = atoi(tmp);

			       tmp[0] = maincmd[14];
			       tmp[1] = maincmd[15];
			       tmp[2] = maincmd[16];
  			       tmp[3] = '\0';
  			       wval = atoi(tmp);
  			       
  			       if (rval >= 0 && rval <= 255 && gval >= 0 && gval <= 255 && bval >= 0 && bval <= 255 && wval >= 0 && wval <= 255) {
  			       	if (boardsconfig[RGBWBOARDS][boardnr - 1] == 1) {
  			       	  rgbwboard_set_pwm_mode_data(boardnr, modenr, rval, gval, bval, wval);
  			           snprintf(buf, 50, "RGBWBoard %d Mode %d set to R %d | G %d | B %d | w %d\n", boardnr, modenr, rval, gval, bval, wval);
     	  		        uart_puts(buf);
     	  		      } else {
     	  		        snprintf(buf, 50, "RGBWBoard %d not connected\n", boardnr);
     	  		        uart_puts(buf);
     	  		      }
  			       } else {
  			         myerr = 1;
  			       }  			       
              } else {
                myerr = 1;
              }
			 } else {
			   myerr = 1;
			 }
			 if (myerr == 1) {
			   uart_puts_P("Wrong Parameter. Syntax: Boardnumber Modenumber RVal GVal BVal WVal\n");
			 }
          break;
        
        default:
          break;
      }
      
      break;      
      
    default:
      break;
  }
}