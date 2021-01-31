#include "../header/system.h"

void systemclock(void) {
  systemsec++;
	   
  // Systemtime
  if (systemsec >= 60) {
    systemsec = 0;
	 systemmin++;
	 systemclock_sync();
  }
	   
  if (systemmin >= 60) {
    systemmin = 0;
	 systemhour++;
	 systemtime_synctimer++;
  }
	   
  if (systemhour >= 24) {
    systemhour = 0;
  }
}

void systemclock_sync(void) {
  if (systemtime_synctimer >= SYSTEMTIME_SYNCTIME) {
    uart_get_systemtime();
  }
}