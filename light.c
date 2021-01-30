#include "system.h"

void light_init(void) {
  manual_light = LIGHTMODE_OFF;
  motion_light = LIGHTMODE_OFF;
  night_light = LIGHTMODE_OFF;
  
  manlight_on = LIGHT_OFF;
  motlight_on = LIGHT_OFF;
  niglight_on = LIGHT_OFF;
}

void lightsystem(void) {

  if (manual_light == LIGHTMODE_ON) {
    if (manlight_on == LIGHT_OFF) {
      // set manual light on
      
      manlight_on = LIGHT_ON;
    }
  } else {
    if (manlight_on == LIGHT_ON) {
      // set manual light off
      
      manlight_on = LIGHT_OFF;
    }
  }
  
  
  // Motionlight when Manuallight is OFF
  if (manual_light == LIGHTMODE_OFF && motion_light == LIGHTMODE_ON) {
  
    if (pir_one_value == 1 && motlight_on == LIGHT_OFF || pir_two_value == 1 && motlight_on == LIGHT_OFF) {
      // set motion light on
    }
    
    if (pir_one_value == 1 && motlight_on == LIGHT_ON || pir_two_value == 1 && motlight_on == LIGHT_ON) {
      // reset the motion light timer
    }
    
    if (pir_one_value == 0 && pir_two_value == 0 && motlight_on == LIGHT_ON) {
      // set motion light off
    }
  
  }

}