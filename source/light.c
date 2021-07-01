#include "../header/system.h"

void lightsystem_init(void) {

  light_on = LIGHT_OFF;
  motionlight_on = LIGHT_OFF;
  nightlight_on = LIGHT_OFF;
  
  light_mode_run = 0;
  motionlight_mode_run = 0;
  nightlight_mode_run = 0;
  nightlight_run = 0;
  
  motionlight_timer_time = 0;
  nightlight_timer_time = 0;
}

void lightsystem_sendlightmode(uint8_t modenr) {
  for (int zz = 0; zz<8; zz++) {
    rgbwboard_run_pwm_mode(zz +1, modenr);
    pwmboard_setmode(zz +1, modenr);
  }
}

void lightsystem(void) {

  if (light_on == LIGHT_ON && light_mode_run != light_mode) {
    light_on = LIGHT_ON;
    lightsystem_sendlightmode(light_mode);
    light_mode_run = light_mode;
    if (motionlight_on == LIGHT_ON) {
      motionlight_on = LIGHT_OFF;
      motionlight_timer_time = 0;
    }
  }
  
  if (light_on == LIGHT_OFF && light_mode_run != 0) {
    light_on = LIGHT_OFF;
    lightsystem_sendlightmode(0);
    light_mode_run = 0;
  }
  
  // Motionlight  
  
  if (motionlight_enabled == 1 && light_on == LIGHT_OFF && motionlight_on == LIGHT_OFF && nightlight_run == 0) {
  	 
  	 if (pir_one_value == 1 || pir_two_value == 1) {
  	 	if (light_brightness_on == 1) {
  	 	  if (roombrightness_value > light_brightness) {
  	 	    lightsystem_sendlightmode(motionlight_mode);
  	       motionlight_timer_time = 0;
          motionlight_on = LIGHT_ON;
  	 	  }
  	 	} else {
  	 	  lightsystem_sendlightmode(motionlight_mode);
  	     motionlight_timer_time = 0;
        motionlight_on = LIGHT_ON;
      }
    }
  }
  
  if (motionlight_enabled == 1 && light_on == LIGHT_OFF && motionlight_on == LIGHT_ON && nightlight_run == 0) {

    if (pir_one_value == 1 || pir_two_value == 1) {
      motionlight_timer_time = 0;
      //uart_puts("timer reset\n");
    } else {
    	if (motionlight_timer_time > motionlight_time) {
    	  motionlight_timer_time = 0;
    	  lightsystem_sendlightmode(0);
        motionlight_on = LIGHT_OFF;
      }
    }
  }
  
  // Nightlight
  
  if (nightlight_enabled == 1 && light_on == LIGHT_OFF && nightlight_on == LIGHT_OFF && nightlight_run == 1) {
  	 
  	 if (pir_one_value == 1 || pir_two_value == 1) {
  	 	lightsystem_sendlightmode(nightlight_mode);
  	   nightlight_timer_time = 0;
      nightlight_on = LIGHT_ON;
    }
  }
  
  if (nightlight_enabled == 1 && light_on == LIGHT_OFF && nightlight_on == LIGHT_ON && nightlight_run == 1) {

    if (pir_one_value == 1 || pir_two_value == 1) {
      nightlight_timer_time = 0;
    } else {
    	if (nightlight_timer_time > nightlight_time) {
    	  nightlight_timer_time = 0;
    	  lightsystem_sendlightmode(0);
        nightlight_on = LIGHT_OFF;
      }
    }
  }

  // Check Nightlighttime
  
  if (nightlight_enabled == 1 && nightlight_run == 0) {
    if (systemhour >= nightlight_time_hour_on && systemmin >= nightlight_time_minute_on) {
      nightlight_run = 1;
      if (nightlight_time_hour_on > nightlight_time_hour_off) {
        nightwait = 1;
      } else {
        nightwait = 0;
      }
    }
  }
  if (nightlight_enabled == 1 && nightlight_run == 1) {
  	 if (nightwait == 1) {
  	   if (systemhour <  nightlight_time_hour_off) {
  	     nightwait = 0;
  	   }
  	 } else {
	   if (systemhour >= nightlight_time_hour_off && systemmin >= nightlight_time_minute_off && systemhour <= nightlight_time_hour_on && systemmin <= nightlight_time_minute_on) {
        nightlight_run = 0;
        if (nightlight_on == LIGHT_ON) {
      	  lightsystem_sendlightmode(0);
        }
      }
    } 
  }
}

void lightsystem_timer(void) {

  if (motionlight_on == LIGHT_ON) {
    motionlight_timer_time++;
  }
  
  if (nightlight_on == LIGHT_ON) {
    nightlight_timer_time++;
  }

}