#include "../header/system.h"

uint16_t readADC(uint8_t channel) {
	uint8_t i;
	uint16_t result = 0;
	
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
	ADMUX = channel | (1<<REFS1) | (1<<REFS0);
	
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	
	for(i=0; i<3; i++) {
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		
		result += ADCW;
	}
	ADCSRA &= ~(1<<ADEN);
	result /= 3;
	
	return result;
}