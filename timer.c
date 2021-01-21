#include "system.h"

void timer_init(void) {

	TCCR1B = (1<<CS10) | (1<<CS12);  // Timer mode with 1024 prescler
	TCNT1 = 49910;   // for 1 sec at 16 MHz
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	//sysTimer = 0;
	//sysTimerReloadValue = 10000;

}

void timer_stop(void) {

  TIMSK &= ~(1<<TOIE0);
  TCCR1B &= ~(1<<CS10);
  TCCR1B &= ~(1<<CS12);  
}

void timer_start(void) {

  TIMSK |= (1<<TOIE0);
  TCCR1B |= (1<<CS10);
  TCCR1B |= (1<<CS12);
  
}

ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	
  sysTimer++;	
	
  if (pir_one_reset == 1) {
    pir_one_reset_time++;
  }
  
  if (pir_two_reset == 1) {
    pir_two_reset_time++;
  }
}