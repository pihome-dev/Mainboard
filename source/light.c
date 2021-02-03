#include "../header/system.h"

void lightsystem_init(void) {

  light_on = LIGHT_OFF;
  motionlight_on = LIGHT_OFF;
  nightlight_on = LIGHT_OFF;
  
  light_mode_run = 0;
  motionlight_mode_run = 0;
  nightlight_mode_run = 0;
  
  motionlight_timer_time = 0;
  nightlight_timer_time = 0;
}

void lightsystem(void) {

  if (light_on == LIGHT_ON && light_mode_run != light_mode) {
    uart_puts("\n\nManuallight do on\n\n");
    light_on = LIGHT_ON;
    light_mode_run = light_mode;
    if (motionlight_on == LIGHT_ON) {
      motionlight_on = LIGHT_OFF;
      motionlight_timer_time = 0;
    }
  }
  
  if (light_on == LIGHT_OFF && light_mode_run != 0) {
    uart_puts("\n\nManuallight do off\n\n");
    light_on = LIGHT_OFF;
    light_mode_run = 0;
  }
  
  if (motionlight_enabled == 1 && light_on == LIGHT_OFF && motionlight_on == LIGHT_OFF) {
  	 
  	 if (pir_one_value == 1 || pir_two_value == 1) {
  	   uart_puts("\n\nMotionlight do on\n\n");
  	   motionlight_timer_time = 0;
      motionlight_on = LIGHT_ON;
    }
  }
  
  if (motionlight_enabled == 1 && light_on == LIGHT_OFF && motionlight_on == LIGHT_ON) {

    if (pir_one_value == 1 || pir_two_value == 1) {
      motionlight_timer_time = 0;
      //uart_puts("timer reset\n");
    } else {
    	if (motionlight_timer_time > motionlight_time) {
    	  uart_puts("\n\nMotionlight do off\n\n");
    	  motionlight_timer_time = 0;
        motionlight_on = LIGHT_OFF;
      }
    }
  }

}

void lightsystem_timer(void) {

  if (motionlight_on == LIGHT_ON) {
    motionlight_timer_time++;
    snprintf(buf, 50, "Motiontimer=%d\n", motionlight_timer_time);
    uart_puts(buf);
  }
  
  if (nightlight_on == LIGHT_ON) {
    nightlight_timer_time++;
  }

}