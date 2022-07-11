void rgbwboard_run_pwm_mode(int boardnumber, uint8_t modenumber);
void rgbwboard_set_pwm_mode_data(int boardnumber, uint8_t modenumber, uint8_t rchannel, uint8_t gchannel, uint8_t bchannel, uint8_t wchannel);
void rgbwboard_set_pwm_mode_config(int boardnumber, uint8_t modenumber, uint8_t changemode, uint8_t changetimer, uint8_t changetimeg, uint8_t changetimeb, uint8_t changetimew);

void rgbwboard_set_ws2812_mode_data(int boardnumber, uint8_t modenumber, uint8_t lednumber,  uint8_t rchannel, uint8_t gchannel, uint8_t bchannel);
void rgbwboard_run_ws2812_mode(int boardnumber, uint8_t modenumber);

void rgbwboard_reboot(int boardnumber);
void rgbwboard_factory_reset(int boardnumber);
void rgbwboard_set_num_ws2812(int boardnumber, uint8_t num_of_leds);

void rgbwboard_set_all_ws2812_red(int boardnumber, uint8_t brightness);
void rgbwboard_set_all_ws2812_green(int boardnumber, uint8_t brightness);
void rgbwboard_set_all_ws2812_blue(int boardnumber, uint8_t brightness);
void rgbwboard_ws2812_off(int boardnumber);

void rgbwboard_readmodevalues(int boardnumber, uint8_t modenumber);
void rgbwboard_readlivevalues(int boardnumber);

volatile uint8_t readcount;
volatile uint8_t readdata[50];
