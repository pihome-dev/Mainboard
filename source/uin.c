#include "../header/system.h"

void system_command(void) {

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
			     uart_puts_P("Fotosensor One enabled\n");
			   } else {
			     uart_puts_P("Fotosensor One disabled\n");
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
			     uart_puts_P("Fotosensor Two enabled\n");
			   } else {
			     uart_puts_P("Fotosensor Two disabled\n");
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
			     uart_puts_P("PIR One enabled\n");
			   } else {
			     uart_puts_P("PIR One disabled\n");
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
			     uart_puts_P("PIR Two enabled\n");
			   } else {
			     uart_puts_P("PIR Two disabled\n");
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
			     uart_puts_P("DS1820 One enabled\n");
			   } else {
			     uart_puts_P("DS1820 One disabled\n");
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
			     uart_puts_P("DS1820 Two enabled\n");
			   } else {
			     uart_puts_P("DS1820 Two disabled\n");
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
          
        case UARTIN_BME280_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   bme280_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts_P("BME280 enabled\n");
			   } else {
			     uart_puts_P("BME280 disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_BME280_READ_INTERVAL:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 99) {
			   bme280_read_interval = inttmp;
			   snprintf(buf, 50, "BME280 Readinterval set to %d seconds\n", inttmp);
    	  		uart_puts(buf);
			   eeprom_autosave();
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
          light_on = LIGHT_OFF;
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
			   uart_puts_P("Wrong Lightmode. Lightmode must between 1 and 6.\n");
			 }
          break;
          
        case UART_IN_SET_RGBWBOARD_DATA:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 boardnr = atoi(tmp);
						 
			 
			 myerr = 0;
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
  			       	  
  			           snprintf(buf, 50, "RGBWBoard %d Mode %d set R%d | G%d | B%d | W%d\n", boardnr, modenr, rval, gval, bval, wval);
     	  		        uart_puts(buf);
     	  		        rgbwboard_set_pwm_mode_data(boardnr, modenr, rval, gval, bval, wval);
     	  		        
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
          
        case UART_IN_SET_RGBWBOARD_CONFIG:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 boardnr = atoi(tmp);
						 
			 
			 myerr = 0;
			 
			 if (boardnr >= 1 && boardnr <= 8) { // Boardnumber
            tmp[0] = maincmd[4];
  			   tmp[1] = '\0';
  			   modenr = atoi(tmp);
			     if (modenr >= 1 && modenr <= 8) {
			     	
			     	 tmp[0] = maincmd[5];
	  	 		    tmp[1] = '\0';
  		 		    i2cchangemode = atoi(tmp);
			       
			       tmp[0] = maincmd[6];
			       tmp[1] = maincmd[7];
			       tmp[2] = maincmd[8];
  			       tmp[3] = '\0';
  			       i2crchangetime = atoi(tmp);
  			       
  			       tmp[0] = maincmd[9];
			       tmp[1] = maincmd[10];
			       tmp[2] = maincmd[11];
  			       tmp[3] = '\0';
  			       i2cgchangetime = atoi(tmp);
  			       
  			       tmp[0] = maincmd[12];
			       tmp[1] = maincmd[13];
			       tmp[2] = maincmd[14];
  			       tmp[3] = '\0';
  			       i2cbchangetime = atoi(tmp);
  			       
  			       tmp[0] = maincmd[15];
			       tmp[1] = maincmd[16];
			       tmp[2] = maincmd[17];
  			       tmp[3] = '\0';
  			       i2cwchangetime = atoi(tmp);  			       
			 
			 	    rgbwboard_set_pwm_mode_config(boardnr, modenr, i2cchangemode, i2crchangetime, i2cgchangetime, i2cbchangetime, i2cwchangetime);
			 	    uart_puts_P("OK\n");
			     }
			 } else {
			   myerr = 1;
			 }
			 if (myerr == 1) {
			   uart_puts_P("Wrong Parameter. Syntax: Boardnumber Modenumber Changemode RChangetime GChangetime BChangetime WChangetime\n");
			 }
			 break;
			 
		    case UART_IN_SET_WS2812_MODE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);

			   if (boardnr >= 1 && boardnr <= 8) { // Boardnumber
              tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     modenr = atoi(tmp);
			     if (modenr >= 1 && modenr <= 8) {
			       rgbwboard_run_ws2812_mode(boardnr, modenr);
					 uart_puts_P("OK\n");
			     }
			   }
            break;
		      
		    case UART_IN_SET_WS2812_CONFIG:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			
			   if (boardnr >= 1 && boardnr <= 8) { // Boardnumber
              tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     modenr = atoi(tmp);
			     if (modenr >= 1 && modenr <= 8) {
			     	 int lednumber;

			       tmp[0] = maincmd[5];
			       tmp[1] = maincmd[6];
  			       tmp[3] = '\0';
  			       lednumber = atoi(tmp);

			       tmp[0] = maincmd[7];
			       tmp[1] = maincmd[8];
			       tmp[2] = maincmd[9];
  			       tmp[3] = '\0';
  			       rval = atoi(tmp);

			       tmp[0] = maincmd[10];
			       tmp[1] = maincmd[11];
			       tmp[2] = maincmd[12];
  			       tmp[3] = '\0';
  			       gval = atoi(tmp);
  			       
  			       tmp[0] = maincmd[13];
			       tmp[1] = maincmd[14];
			       tmp[2] = maincmd[15];
  			       tmp[3] = '\0';
  			       bval = atoi(tmp);
  			       
		          rgbwboard_set_ws2812_mode_data(boardnr, modenr, lednumber,  rval, gval, bval);
                uart_puts_P("OK\n");
		        }
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_REBOOT:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_reboot(boardnr);
		        uart_puts_P("OK\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_FACTORY_RESET:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_factory_reset(boardnr);
		        uart_puts_P("OK\n");
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
