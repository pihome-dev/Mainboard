void fourchamp_reboot(int boardnumber);
void fourchamp_factory_reset(int boardnumber);
void fourchamp_mute(int boardnumber, uint8_t ampnumber, uint8_t mute);
void fourchamp_input(int boardnumber, uint8_t ampnumber, uint8_t inputch);
void fourchamp_gain(int boardnumber, uint8_t ampnumber, uint8_t gain);
void fourchamp_volume(int boardnumber, uint8_t ampnumber, uint8_t volume);
void fourchamp_treble(int boardnumber, uint8_t ampnumber, uint8_t treble);
void fourchamp_middle(int boardnumber, uint8_t ampnumber, uint8_t middle);
void fourchamp_bass(int boardnumber, uint8_t ampnumber, uint8_t bass);

int get_inputgain_value(int data);
int get_volume_value(int data);