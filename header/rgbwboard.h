void rgbwboard_run_pwm_mode(int boardnumber, uint16_t modenumber);
void rgbwboard_set_pwm_mode_data(int boardnumber, uint16_t modenumber, uint16_t rchannel, uint16_t gchannel, uint16_t bchannel, uint16_t wchannel);
void rgbwboard_set_pwm_mode_config(int boardnumber, uint16_t modenumber, uint16_t changemode, uint16_t changetimer, uint16_t changetimeg, uint16_t changetimeb, uint16_t changetimew);

void rgbwboard_set_ws2812_mode_data(int boardnumber, uint16_t modenumber, uint16_t lednumber,  uint16_t rchannel, uint16_t gchannel, uint16_t bchannel);
void rgbwboard_run_ws2812_mode(int boardnumber, uint16_t modenumber);

void rgbwboard_reboot(int boardnumber);
void rgbwboard_factory_reset(int boardnumber);