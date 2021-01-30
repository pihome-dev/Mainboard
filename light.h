#define LIGHTMODE_OFF							0
#define LIGHTMODE_ON								1
#define LIGHT_OFF									0
#define LIGHT_ON									1

volatile int manual_light;
volatile int motion_light;
volatile int night_light;

volatile int manlight_on;
volatile int motlight_on;
volatile int niglight_on;

void light_init(void);
void lightsystem(void);