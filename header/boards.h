#define RGBWBOARDS										0
#define DREIZWEICHPEMBOARDS							1
#define VIERCHAMPBOARDS									2

volatile int boardsconfig[3][8];

volatile int rgbwboard_connected;
volatile int dreizweichboards_connected;
volatile int vierchampboards_connected;

void rgbwboards_seach(void);
void dreizweichboards_search(void);
void vierchampboards_search(void);

unsigned char get_rgbwboard_addr(int boardnumber);
unsigned char get_32chboard_addr(int boardnumber);
unsigned char get_4champboard_addr(int boardnumber);

void rgbwboard_run_pwm_mode(int boardnumber, int modenumber);
void rgbwboard_set_pwm_mode_data(int boardnumber, int modenumber, uint8_t rchannel, uint8_t gchannel, uint8_t bchannel, uint8_t wchannel);
void rgbwboard_set_pwm_defaultchangetime(int boardnumber, int changetime);
void rgbwboard_set_pwm_defaultchangetimeR(int boardnumber, int changetime);
void rgbwboard_set_pwm_defaultchangetimeG(int boardnumber, int changetime);
void rgbwboard_set_pwm_defaultchangetimeB(int boardnumber, int changetime);
void rgbwboard_set_pwm_defaultchangetimeW(int boardnumber, int changetime);

void boards_init(void);

// RGBW Boards

#define RGBWBOARD1										0
#define RGBWBOARD2										1
#define RGBWBOARD3										2
#define RGBWBOARD4										3
#define RGBWBOARD5										4
#define RGBWBOARD6										5
#define RGBWBOARD7										6
#define RGBWBOARD8										7

#define RGBWBOARD_ONE_ADDRESS							0x32
#define RGBWBOARD_TWO_ADDRESS							0x34
#define RGBWBOARD_THREE_ADDRESS						0x36
#define RGBWBOARD_FOUR_ADDRESS						0x38
#define RGBWBOARD_FIVE_ADDRESS						0x3A
#define RGBWBOARD_SIX_ADDRESS							0x3C
#define RGBWBOARD_SEVEN_ADDRESS						0x3E
#define RGBWBOARD_EIGHT_ADDRESS						0x40

// 32CH PWM Boards

#define DREIZWEICHBOARD1								0
#define DREIZWEICHBOARD2								1
#define DREIZWEICHBOARD3								2
#define DREIZWEICHBOARD4								3
#define DREIZWEICHBOARD5								4
#define DREIZWEICHBOARD6								5
#define DREIZWEICHBOARD7								6
#define DREIZWEICHBOARD8								7

#define DREIZWEICHPWMBOARD_ONE_ADDRESS				0x42
#define DREIZWEICHPWMBOARD_TWO_ADDRESS				0x44
#define DREIZWEICHPWMBOARD_THREE_ADDRESS			0x46
#define DREIZWEICHPWMBOARD_FOUR_ADDRESS			0x48
#define DREIZWEICHPWMBOARD_FIVE_ADDRESS			0x4A
#define DREIZWEICHPWMBOARD_SIX_ADDRESS				0x4C
#define DREIZWEICHPWMBOARD_SEVEN_ADDRESS			0x4E
#define DREIZWEICHPWMBOARD_EIGHT_ADDRESS			0x50

// 4CH Amplifer Boards

#define VIERCHBOARD1										0
#define VIERCHBOARD2										1
#define VIERCHBOARD3										2
#define VIERCHBOARD4										3
#define VIERCHBOARD5										4
#define VIERCHBOARD6										5
#define VIERCHBOARD7										6
#define VIERCHBOARD8										7

#define VIERCHAMPBOARD_ONE_ADDRESS					0x52
#define VIERCHAMPBOARD_TWO_ADDRESS					0x54
#define VIERCHAMPBOARD_THREE_ADDRESS				0x56
#define VIERCHAMPBOARD_FOUR_ADDRESS					0x58
#define VIERCHAMPBOARD_FIVE_ADDRESS					0x5A
#define VIERCHAMPBOARD_SIX_ADDRESS					0x5C
#define VIERCHAMPBOARD_SEVEN_ADDRESS				0x5E
#define VIERCHAMPBOARD_EIGHT_ADDRESS				0x60