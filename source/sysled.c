#include "../header/system.h"

void stateled_init(void) {
	
  STATELED_DDR |= (1 << STATELED_PIN);

  // LED Off
  stateled_off();
  
  systemstate = STATE_IDLE;
  stateTimer = 0;
  
}

void stateled_on(void) {
  if (PININVERT == 1) {
    STATELED_PORT |= (1 << STATELED_PIN);
  } else {
    STATELED_PORT &= ~(1 << STATELED_PIN);
  }
}

void stateled_off(void) {
  if (PININVERT == 1) {
    STATELED_PORT &= ~(1 << STATELED_PIN);
  } else {
    STATELED_PORT |= (1 << STATELED_PIN);
  }
}

void stateled(void) {
  switch(systemstate) {
  	
  	 case STATE_IDLE:
  	   if (stateTimer < STATETIME_IDLE_ON ) {
        stateled_on();
      } else {
        stateled_off();
      }
      if (stateTimer > (STATETIME_IDLE_OFF + STATETIME_IDLE_WAIT) ) {
        stateTimer = 0;
      }
      break;
      
    case STATE_RUN:
      if (stateTimer < STATETIME_RUN_ON ) {
        stateled_on();
      } else {
        stateled_off();
      }
      if (stateTimer > (STATETIME_RUN_OFF + STATETIME_RUN_WAIT) ) {
        stateTimer = 0;
      }
      break;
      
    case STATE_ERROR:
      if (stateTimer < STATETIME_ERROR_ON ) {
        stateled_on();
      } else {
        stateled_off();
      }
      if (stateTimer > (STATETIME_ERROR_OFF + STATETIME_ERROR_WAIT) ) {
        stateTimer = 0;
      }
      break;
      
    case STATE_INIT:
      if (stateTimer < STATETIME_INIT_ON ) {
        stateled_on();
      } else {
        stateled_off();
      }
      if (stateTimer > (STATETIME_INIT_OFF + STATETIME_INIT_WAIT) ) {
        stateTimer = 0;
      }
      break;
      
    default:
      stateled_off();
      break;
  }
}