#define LIGHT_ON	1
#define LIGHT_OFF	0

volatile uint8_t light_mode;
volatile uint8_t motionlight_mode;
volatile uint8_t nightlight_mode;

int nightwait;

volatile uint8_t motionlight_enabled;
volatile uint8_t nightlight_enabled;

volatile uint8_t light_on;
volatile uint8_t motionlight_on;
volatile uint8_t nightlight_on;
volatile uint8_t light_brightness_on;

volatile uint16_t light_brightness;

volatile uint8_t nightlight_run;

volatile uint8_t light_mode_run;
volatile uint8_t motionlight_mode_run;
volatile uint8_t nightlight_mode_run;

volatile uint8_t nightlight_time_hour_on;
volatile uint8_t nightlight_time_minute_on;
volatile uint8_t nightlight_time_hour_off;
volatile uint8_t nightlight_time_minute_off;

volatile uint8_t motionlight_time;
volatile uint8_t motionlight_timer_time;

volatile uint8_t nightlight_time;
volatile uint8_t nightlight_timer_time;



void lightsystem_init(void);
void lightsystem(void);
void lightsystem_timer(void);

void lightsystem_sendlightmode(uint8_t modenr);