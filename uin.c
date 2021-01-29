#include "system.h"

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
			     uart_puts("Fotosensor One enabled\n");
			   } else {
			     uart_puts("Fotosensor One disabled\n");
			   }
			 }
          break;
          
        case UARTIN_FOTOSENSOR_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   fotosensor_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("Fotosensor Two enabled\n");
			   } else {
			     uart_puts("Fotosensor Two disabled\n");
			   };
			 }
          break;
          
        case UARTIN_PIR_ONE_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   pir_one_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("PIR One enabled\n");
			   } else {
			     uart_puts("PIR One disabled\n");
			   }
			 }
          break;
          
        case UARTIN_PIR_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   pir_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("PIR Two enabled\n");
			   } else {
			     uart_puts("PIR Two disabled\n");
			   };
			 }
          break;
          
        case UARTIN_DS1820_ONE_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   ds1820_one_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("DS1820 One enabled\n");
			   } else {
			     uart_puts("DS1820 One disabled\n");
			   }
			 }
          break;
          
        case UARTIN_DS1820_TWO_ENABLE:
          tmp[0] = maincmd[3];
			 tmp[1] = '\0';
			 inttmp = atoi(tmp);
			 if (inttmp >= 0 && inttmp <= 1) {
			   ds1820_two_enabled = inttmp;
			   if (inttmp == 1) {
			     uart_puts("DS1820 Two enabled\n");
			   } else {
			     uart_puts("DS1820 Two disabled\n");
			   };
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