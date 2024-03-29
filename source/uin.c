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
          
        case UARTIN_LIGHT_BRIGHTNESS_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   light_brightness_on = inttmp;
			   if (inttmp == 1) {
			     uart_puts_P("Brightnesslight enabled\n");
			   } else {
			     uart_puts_P("Brightnesslight disabled\n");
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
          
        case UARTIN_MOTIONLIGHT_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   motionlight_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts_P("Motionlight enabled\n");
			   } else {
			     uart_puts_P("Motionlight disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_NIGHTLIGHT_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   nightlight_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts_P("Nightlight enabled\n");
			   } else {
			     uart_puts_P("Nightlight disabled\n");
			   }
			   eeprom_autosave();
			 }
          break;
          
        case UARTIN_LIGHT_BRIGHTNESS:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
          tmp[2] = maincmd[5];
			 tmp[3] = '\0';
			 inttmp16 = atoi(tmp);
			 if (inttmp16 >= 0 && inttmp16 <= 999) {
			   light_brightness = inttmp16;
			   snprintf(buf, 50, "Lightbrightness set to %d \n", inttmp16);
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
          
          
          
        case UART_IN_NIGHTLIGHT_TIME_ON:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 temphour = atoi(tmp);
			 
			 tmp[0] = maincmd[5];
          tmp[1] = maincmd[6];
			 tmp[2] = '\0';
			 tempmin = atoi(tmp);
			 
			 if (temphour >= 0 && temphour <= 24 && tempmin >= 0 && tempmin <= 60) {
			   nightlight_time_hour_on = temphour;
			   nightlight_time_minute_on = tempmin;
			   eeprom_autosave();
			   snprintf(buf, 50, "Nightlight On set to %d:%d \n", temphour, tempmin);
    	  		uart_puts(buf);
			 } else {
			   uart_puts_P("Wrong Nightlight On Time data.\n");
			 }
          break;
          
          
        case UART_IN_NIGHTLIGHT_TIME_OFF:
          tmp[0] = maincmd[3];
          tmp[1] = maincmd[4];
			 tmp[2] = '\0';
			 temphour = atoi(tmp);
			 
			 tmp[0] = maincmd[5];
          tmp[1] = maincmd[6];
			 tmp[2] = '\0';
			 tempmin = atoi(tmp);
			 
			 if (temphour >= 0 && temphour <= 24 && tempmin >= 0 && tempmin <= 60) {
			   nightlight_time_hour_off = temphour;
			   nightlight_time_minute_off = tempmin;
			   eeprom_autosave();
			   snprintf(buf, 50, "Nightlight Off set to %d:%d \n", temphour, tempmin);
    	  		uart_puts(buf);
			 } else {
			   uart_puts_P("Wrong Nightlight Off Time data.\n");
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
			     } else {
			       uart_puts_P("Wrong Modenumber\n");
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
			     } else {
			       uart_puts_P("Wrong Boardnumber\n");
			     }
			   } else {
			     uart_puts_P("Wrong Boardnumber\n");
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
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_WS2812_OFF:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_ws2812_off(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_WS2812_RED:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t bright;
			     
			     tmp[0] = maincmd[4];
			     tmp[1] = maincmd[5];
			     tmp[2] = maincmd[6];
  			     tmp[3] = '\0';
  			     bright = atoi(tmp);
  			     
  			     if (bright >= 0 && bright <= 100) {
		          rgbwboard_set_all_ws2812_red(boardnr, bright);  
		        } else {
		          uart_puts_P("Wrong Bright. Brightness must between 0 and 100\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_WS2812_GREEN:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t bright;
			     
			     tmp[0] = maincmd[4];
			     tmp[1] = maincmd[5];
			     tmp[2] = maincmd[6];
  			     tmp[3] = '\0';
  			     bright = atoi(tmp);
  			     
  			     if (bright >= 0 && bright <= 100) {
		          rgbwboard_set_all_ws2812_green(boardnr, bright);
		          
		        } else {
		          uart_puts_P("Wrong Bright. Brightness must between 0 and 100\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_WS2812_BLUE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t bright;
			     
			     tmp[0] = maincmd[4];
			     tmp[1] = maincmd[5];
			     tmp[2] = maincmd[6];
  			     tmp[3] = '\0';
  			     bright = atoi(tmp);
  			     
  			     if (bright >= 0 && bright <= 100) {
		          rgbwboard_set_all_ws2812_blue(boardnr, bright);  
		        } else {
		          uart_puts_P("Wrong Bright. Brightness must between 0 and 100\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_READ_MODEDATA:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
		               uart_puts_P("Read Modedata\n");
		               rgbwboard_readmodevalues(boardnr, modenr);
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_READ_LIVEDATA:
		      tmp[0] = maincmd[3];
		      tmp[1] = '\0';
		      boardnr = atoi(tmp);

		      if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_readlivevalues(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_REBOOT:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_reboot(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_RGBWBOARD_FACTORY_RESET:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        rgbwboard_factory_reset(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    
		    // 4 CH Audio Amplifer		    
		    
		    case UART_IN_4CH_MUTE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t mutedata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = '\0';
  			     mutedata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_mute(boardnr, ampdata, mutedata);
		          
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_INPUT:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t inputch;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = '\0';
  			     inputch = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_input(boardnr, ampdata, inputch);
		          
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_GAIN:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t gaindata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = maincmd[6];
  			     tmp[2] = '\0';
  			     gaindata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_gain(boardnr, ampdata, gaindata);
		          
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_VOLUME:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t volumedata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = maincmd[6];
  			     tmp[2] = '\0';
  			     volumedata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_volume(boardnr, ampdata, volumedata);
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_TREBLE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t trebledata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = maincmd[6];
  			     tmp[2] = '\0';
  			     trebledata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_treble(boardnr, ampdata, trebledata);
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_MIDDLE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t middledata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = maincmd[6];
  			     tmp[2] = '\0';
  			     middledata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_middle(boardnr, ampdata, middledata);
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_BASS:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     uint8_t ampdata;
			     uint8_t bassdata;
			     
			     tmp[0] = maincmd[4];
  			     tmp[1] = '\0';
  			     ampdata = atoi(tmp);
  			     
  			     tmp[0] = maincmd[5];
  			     tmp[1] = maincmd[6];
  			     tmp[2] = '\0';
  			     bassdata = atoi(tmp);
  			     
  			     if (ampdata >= 1 && ampdata <= 2) {
		          fourchamp_bass(boardnr, ampdata, bassdata);
		        } else {
		          uart_puts_P("Wrong Amplifer Number\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		    
		    case UART_IN_4CH_REBOOT:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        fourchamp_reboot(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_4CH_FACTORY_RESET:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        fourchamp_factory_reset(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		      
		      
			 // 32 CH PWM Board		      
		      
		    case UART_IN_PWMBOARD_REBOOT:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        pwmboard_reboot(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_FACTORY_RESET:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
		        pwmboard_factory_reset(boardnr);
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_SET_RUNMODE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = '\0';
			   modenr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
		          pwmboard_setmode(boardnr, modenr);
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_READ_MODEDATA:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
		          pwmboard_readmodevalues(boardnr, modenr);
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_READ_MODESPEED:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
		          pwmboard_readmodespeed(boardnr, modenr);
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_READ_MODECHANGE:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
		          pwmboard_readmodechange(boardnr, modenr);
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_SET_MODEDATA:
		      tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
			   
			   tmp[0] = maincmd[6];
			   tmp[1] = maincmd[7];
			   tmp[2] = '\0';
			   tmpchannel = atoi(tmp);
			   
			   tmp[0] = maincmd[8];
			   tmp[1] = maincmd[9];
			   tmp[2] = maincmd[10];
			   tmp[3] = '\0';
			   tmpval = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
			       if (tmpchannel >= 1 && tmpchannel <= 32) {
			         if (tmpval >= 0 && tmpval <= 255) {
		              pwmboard_setmodevalue(boardnr, modenr, tmpchannel, tmpval);
		            } else {
		              uart_puts_P("Wrong Value Data\n");
		            }
		          } else {
		            uart_puts_P("Wrong Channel Data\n");
		          }
		        } else {
		          uart_puts_P("Wrong Modenumber\n");
		        }
		      } else {
		        uart_puts_P("Wrong Boardnumber\n");
		      }
		      break;
		      
		    case UART_IN_PWMBOARD_SET_MODECONFIG:
		           tmp[0] = maincmd[3];
			   tmp[1] = '\0';
			   boardnr = atoi(tmp);
			   
			   tmp[0] = maincmd[4];
			   tmp[1] = maincmd[5];
			   tmp[2] = '\0';
			   modenr = atoi(tmp);
			   
			   tmp[0] = maincmd[6];
			   tmp[1] = maincmd[7];
			   tmp[2] = '\0';
			   tmpchannel = atoi(tmp);
			   
			   tmp[0] = maincmd[8];
			   tmp[1] = '\0';
			   tmpspeed = atoi(tmp);
			   
			   tmp[0] = maincmd[9];
			   tmp[1] = '\0';
			   tmpchange = atoi(tmp);
						 
			   if (boardnr >= 1 && boardnr <= 8) {
			     if (modenr >= 0 && modenr <= 10) {
			       if (tmpspeed >= 1 && tmpspeed <= 5) {
			         if (tmpchange >= 0 && tmpchange <= 1) {
		              	   pwmboard_setmodeconfig(boardnr, modenr, tmpchannel, tmpspeed, tmpchange);
		                 } else {
		                   uart_puts_P("Wrong Change Data\n");
		                 }
		               } else {
		                 uart_puts_P("Wrong Speed Data\n");
		               }
		             } else {
		               uart_puts_P("Wrong Modenumber\n");
		             }
		           } else {
		             uart_puts_P("Wrong Boardnumber\n");
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
