/* Copyright (C) 2020-2021 DmanT (www.dmant.ovh) - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 * https://dmant.ovh/
 */

#include "../header/system.h"

void (*bootloader)( void ) = (void*)((unsigned long)0xF000);

void avrrestart(void) {
  bootloader();
}

int main (void) {
  systemstate = STATE_INIT;
  systemhour = 0;
  systemmin = 0;
  systemsec = 0;
  
  stateled();
  // Initialisiere UART
  uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
  sei();
  uart_puts_P("\n\n");
  uart_puts_P("piHOME Mainboard Firmware\n\n");
  uart_puts_P("Revision: Rev 1.0\n");
  uart_puts_P("Softwarecode: 349FTH34\n");
  uart_puts_P("Copyright by piHOME\n");
  uart_puts_P("https://pihome.net\n\n");
  uart_puts_P("... Booting Firmware ...\n\n");
  uart_puts_P("UART Initialisiert\n");
  
  // Initialisiere I2C
  i2c_init(); 
  uart_puts_P("I2C Initialisiert\n");
  
  // Initialisiere System LED (Status LED)
  stateled_init();
  uart_puts_P("Status LED Initialisiert\n");
  
  // Initialisiere oLED
  oled_init();
  if (oled_connected == 1) {
    oled_gotoxy(0,0);
	 oled_write("****************");
	 oled_gotoxy(0,1);
	 oled_write("* Ulrich Radig *");
	 oled_gotoxy(0,2);
	 oled_write("****************");
	 oled_font_size(1);
	 oled_gotoxy(0,4);
	 oled_write("%8i",tmp);	
	 oled_font_size(0);
  }
  uart_puts_P("oLED Initialisiert\n");
  
  // Initialisiere Systemtime
  systemclock_init();
  uart_puts_P("Systemtime Initialisiert\n");
  
  // Initialisiere Lightsystem
  lightsystem_init();
  uart_puts_P("Lightsystem Initialisiert\n");

  // Initialisiere Boards
  boards_init();
  uart_puts_P("Boards Initialisiert\n");

  // Initialisiere Sensoren
  sensoren_init();
  uart_puts_P("Sensoren Initialisiert\n");
  
  // Initialisiere RGBW Boards
  rgbwboards_seach();
  uart_puts_P("RGBW Boards Initialisiert\n");
  snprintf(buf, 50, "=> %d <= RGBW Boards connected\n", rgbwboard_connected);
  uart_puts(buf);
  
  // Initialisiere 32CH PWM Boards
  dreizweichboards_search();
  uart_puts_P("32CH PWM Boards Initialisiert\n");
  snprintf(buf, 50, "=> %d <= 32CH PWM Boards connected\n", dreizweichboards_connected);
  uart_puts(buf);
  
  // Initialisiere 4CH Amplifier PWM Boards
  vierchampboards_search();
  uart_puts_P("4CH Amplifier Boards Initialisiert\n");
  snprintf(buf, 50, "=> %d <= 4CH Amplifier Boards connected\n", dreizweichboards_connected);
  uart_puts(buf);
  
  // Search and initialisiere BME280 when exist
  BME280_search();
  if (bme280_connected == 1) {
  	 BME280_init();
    uart_puts_P("BME280 found and initalisiert\n");
  } else {
    uart_puts_P("No BME280 found. Skipping initialisierung");
  }

  // Initialisiere the Timer
  timer_init();
  uart_puts_P("Timer Initialisiert\n");
  
  // Start the Timer
  timer_start();
  uart_puts_P("Timer started\n");
  // INIT UART
  
  // EEPROM
  if (getEEDefaultExist() != eeDefaultDataExist) {
    uart_puts_P("Write Default Systemdata\n");
  	 write_default_eeprom_data();
  	 getEEPROMDefaultData();
  	 uart_puts_P("Systemdata written and loaded\n");
  } else {
  	 getEEPROMDefaultData();
    uart_puts_P("Systemdata loaded\n");
  }
  
  uart_puts_P("\n\n=> Firmware was started and running <=\n\n");
  
  output_on();
  systemstate = STATE_RUN;
  
  while(1) {
  
  	 // Systemled
  	 stateled();
  	 // Systemled end

	 // Sensorcode
    // Read the Temperature if Sensor enabled and exist
    if (ds1820_one_enabled == SENSOR_ENABLED) {
	   read_ds1820_one();
	 }

	 if (ds1820_two_enabled == SENSOR_ENABLED) {
	   read_ds1820_two();
	 }

    //
    // Read the Fotowiderstand if Sensor enabled and exist
    //
    if (fotosensor_one_enabled == SENSOR_ENABLED) {
      read_fotosensor_one();
    } else {
      fotosensor_one_value = FOTOSENSOR_DEFAULT_VALUE;
    }

    if (fotosensor_two_enabled == SENSOR_ENABLED) {
      read_fotosensor_two();
    } else {
      fotosensor_two_value = FOTOSENSOR_DEFAULT_VALUE;
    }

    //
	 // Read the PIR if Sensor enabled and exist
	 //
	 if (pir_one_enabled == SENSOR_ENABLED) {
	   read_pir_one();
	 }

	 if (pir_two_enabled == SENSOR_ENABLED) {
	   read_pir_two();
	 }
	 
	 //
	 // BME280 Sensor
	 //
	 if (bme280_connected == 1) {
	 	read_bme280();
	 }

	 // Sensorcode end

	 // Systemcode
	 lightsystem();

	 // Systemcode end

	 // UART
	 
	 uartc = uart_getc();
    if ( uartc & UART_NO_DATA ){ /* No data */ } else
    { 
       	
	   if (uartcommand == 1) {
		  if (uartc == '#') {
		    docommand = 1;  
			 uartcommand = 0;
        } else {
		    maincmd[uartcommandi] = uartc;
		  }
		  uartcommandi++;
		} else {
			  int t = 0;
           switch (uartc) {
				 case '$':
				   uartcommandi = 0;
				   uartcommand = 1;
				   break;
				 case 'b':
				   uart_puts_P("\nSpringe zum Bootloader...\n");
				   _delay_ms(500);
				   uart_puts("3.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("2.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("1.");
				   _delay_ms(500);
				   uart_puts(".");
				   uart_puts_P("\n\n\n\n");
					timer_stop();
					cli();
		         bootloader();
		         break;
		       case '\n':
		         break;
		       case 'A':
		         uart_get_connected_rgbwboards();
		         break;
		       case 'B':
		         rgbwboard_set_pwm_mode_data(1, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(2, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(3, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(4, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(5, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(6, 1, 50, 50, 50, 50);
		         rgbwboard_set_pwm_mode_data(7, 1, 50, 50, 50, 50);
					rgbwboard_set_pwm_mode_data(8, 1, 50, 50, 50, 50);
		         break;
		       case 'E':
		         rgbwboard_run_pwm_mode(1, 0);
		         rgbwboard_run_pwm_mode(2, 0);
		         rgbwboard_run_pwm_mode(3, 0);
		         rgbwboard_run_pwm_mode(4, 0);
		         rgbwboard_run_pwm_mode(5, 0);
		         rgbwboard_run_pwm_mode(6, 0);
		         rgbwboard_run_pwm_mode(7, 0);
		         rgbwboard_run_pwm_mode(8, 0);
		         break;
		       case 'F':
		         rgbwboard_run_pwm_mode(1, 1);
		         rgbwboard_run_pwm_mode(2, 1);
		         rgbwboard_run_pwm_mode(3, 1);
		         rgbwboard_run_pwm_mode(4, 1);
		         rgbwboard_run_pwm_mode(5, 1);
		         rgbwboard_run_pwm_mode(6, 1);
		         rgbwboard_run_pwm_mode(7, 1);
		         rgbwboard_run_pwm_mode(8, 1);
		         break;
		       case 'C':
		         uart_send_system_config();
		         break;
		       case 'I':
		         uart_send_system_info();
		         break;
		       case 'D':
		         uart_send_system_data();
		         break;
		       case 'R':
		         output_off();
		         uart_puts_P("Factory Reset...\n");
		         _delay_ms(500);
				   uart_puts("3.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("2.");
				   _delay_ms(500);
				   uart_puts(".");
				   _delay_ms(500);
				   uart_puts("1.");
				   _delay_ms(500);
				   uart_puts(".");
				   uart_puts_P("\n\n\n\n");
				   _delay_ms(500);
		         timer_stop();
					cli();
		         _delay_ms(500);
		         eeprom_reset();
		         _delay_ms(500);
		         avrrestart();
		         break;
				 default:
				   uart_puts_P("\nCommand not found\nPress \'?\' for more Information\n");
				   break;
           }
		  }
     }

	  if (docommand == 1) {
	    output_off();
	    system_command();
	    output_on();
	    maincmd[0] = 0;
		 maincmd[1] = 0;
		 maincmd[2] = 0;
	    maincmd[3] = 0;
		 maincmd[4] = 0;
		 maincmd[5] = 0;
	    docommand = 0;
	  }
	 
	 // UART end

	 //
	 // Clear the Systemcounters
	 //
	 if (sysTimer > 20000) {
	   sysTimer = 0;
	 }

	 if (stateTimer > 2000) {
	   stateTimer = 0;
	 }	 
	 
	 
	 if (second_tick == 1) {	 	
	   second_tick = 0;
	   
	   // Lightsystem Timer
	   lightsystem_timer();
	   // Lightsystemtimer end
	   
	   // Systemtime
	   systemclock();
	   // Systemtime end
	   
	   // EEPROM Autosave
	   // Check EEPROM Autosave
	   if (eeprom_autosave_enable == 1) {
	     if (eeprom_changed == 1) {
	       if (eeprom_changed_timer >= EEPROM_AUTOSAVE_TIME) {
	       	eeprom_changed = 0;
	       	eeprom_write_autosave();
	       	uart_puts_P("EEPROM written\n");
	       } else {
	         eeprom_changed_timer++;
	       }
	     }
	   }
	 }
	 

  }
}
