#define LIGHT_ON	1
#define LIGHT_OFF	0

volatile int light_mode;
volatile int motionlight_mode;
volatile int nightlight_mode;

volatile int motionlight_enabled;
volatile int nightlight_enabled;

volatile int light_on;
volatile int motionlight_on;
volatile int nightlight_on;

volatile int light_mode_run;
volatile int motionlight_mode_run;
volatile int nightlight_mode_run;



volatile int nightlight_time_hour;
volatile int nightlight_time_min;

volatile int motionlight_time;
volatile int motionlight_timer_time;

volatile int nightlight_time;
volatile int nightlight_timer_time;





void lightsystem_init(void);
void lightsystem(void);
void lightsystem_timer(void);