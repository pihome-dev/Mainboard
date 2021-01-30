#include "system.h"

void timer_init(void) {

   //TCCR1B = (1<<CS12); // 256 Prescaler
   //TCNT1 = 62;

    TCCR1B |= (1 << WGM12)|(1 << CS12);
  
    // initialize counter
    TCNT1 = 0;
    // initialize compare value
    //OCR1A = 24999;
    OCR1A = ( (F_CPU / TIMERPRE) / 1000) * TIMERFREQ;

}

void timer_stop(void) {

  //TIMSK &= ~(1<<TOIE0);
  TIMSK &= ~(1 << OCIE1A);
  
}

void timer_start(void) {

  //TIMSK |= (1<<TOIE0);
  TIMSK |= (1 << OCIE1A);
  
}

ISR (TIMER1_COMPA_vect)    // Timer1 ISR
{
	
  sysTimer++;
  
  if ( (sysTimer % 100) == 0 ) {
    second_tick = 1;
  }
  
  // Statustimer
  stateTimer+= 10;

  // PIR Reset
  if (pir_one_reset == 1) {
    pir_one_reset_time++;
  }
  
  if (pir_two_reset == 1) {
    pir_two_reset_time++;
  }
}