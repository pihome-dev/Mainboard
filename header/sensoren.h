// Sensoren
#define SENSOR_ENABLED	1
#define SENSOR_DISABLED	0


// Fotosensoren
volatile int fotosensor_one_enabled;
volatile int fotosensor_two_enabled;

volatile int fotosensor_read_interval;
volatile int fotosensor_read_tolerance;

volatile int fotosensor_one_value;
volatile int fotosensor_two_value;
volatile int fotosensor_one_value_old;
volatile int fotosensor_two_value_old;

// PIR Sensoren
volatile int pir_hardware_reset_time;
volatile int pir_one_enabled;
volatile int pir_two_enabled;

volatile int pir_one_value;
volatile int pir_two_value;
volatile int pir_one_value_old;
volatile int pir_two_value_old;

volatile int pir_one_reset;
volatile int pir_one_reset_time;
volatile int pir_two_reset;
volatile int pir_two_reset_time;


// Temperatursensoren
volatile int ds1820_one_enabled;
volatile int ds1820_two_enabled;

volatile int ds1820_one_value;
volatile int ds1820_two_value;

volatile int ds1820_read_interval;

volatile int bme280_enabled;
volatile int bme280_read_interval;

void search_bme280(void);
void read_bme280(void);


void sensoren_init(void);
void read_fotosensor_one(void);
void read_fotosensor_two(void);

void read_pir_one(void);
void read_pir_two(void);

void read_ds1820_one(void);
void read_ds1820_two(void);