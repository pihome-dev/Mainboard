void pwmboard_reboot(int boardnumber);
void pwmboard_factory_reset(int boardnumber);
void pwmboard_setmode(int boardnumber, uint8_t modenumber);
void pwmboard_setmodevalue(int boardnumber, uint8_t modenumber, uint8_t channel, uint8_t modevalue);
void pwmboard_readmodevalues(int boardnumber, uint8_t modenumber);
void pwmboard_readmodechange(int boardnumber, uint8_t modenumber);
void pwmboard_readmodespeed(int boardnumber, uint8_t modenumber);
void pwmboard_setmodeconfig(int boardnumber, uint8_t modenumber, uint8_t channel, uint8_t speed, uint8_t changemode);
