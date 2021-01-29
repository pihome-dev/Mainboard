// Sensoren
#define SENSOR_ENABLED	1
#define SENSOR_DISABLED	0

#define FOTOSENSOR_DEFAULT_VALUE	500
#define FOTOSENSOR_TOLERANCE 8
#define FOTOSENSOR_DEFAULT_READINTERVAL 5

#define PIR_DEFAULT_VALUE 0
#define PIR_HARDWARE_RESET_TIME 4

#define DS1820_DEFAULT_READINTERVAL	5

#define BME280_DEFAULT_READINTERVAL 10

#define BME280_ADDRESS	0x76

// Fotosensoren
volatile int fotosensor_one_enabled;
volatile int fotosensor_two_enabled;

volatile int fotosensor_read_interval;

volatile int fotosensor_one_value;
volatile int fotosensor_two_value;
volatile int fotosensor_one_value_old;
volatile int fotosensor_two_value_old;

// PIR Sensroen
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

volatile int ds1820_read_interval;

// BME280
volatile int bme280_enabled;
volatile int bme280_exist;
volatile int bme280_readinterval;

volatile float bme280_temperature;
volatile float bme280_pressure;
volatile float bme280_humidity;
volatile float bme280_altitude;

volatile float bme280_temperature_old;
volatile float bme280_pressure_old;
volatile float bme280_humidity_old;
volatile float bme280_altitude_old;

void search_bme280(void);
void read_bme280(void);


void sensoren_init(void);
void read_fotosensor_one(void);
void read_fotosensor_two(void);

void read_pir_one(void);
void read_pir_two(void);

void read_ds1820_one(void);
void read_ds1820_two(void);