#include "system.h"

void stateled_init(void) {
  STATELED_DDR |= (1 << STATELED_PIN);

  // LED Off
  stateled_off();
}

void stateled_on(void) {
  STATELED_PORT &= ~(1 << STATELED_PIN);
}

void stateled_off(void) {
  STATELED_PORT |= (1 << STATELED_PIN);
}