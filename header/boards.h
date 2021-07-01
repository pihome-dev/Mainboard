#define RGBWBOARDS										0
#define DREIZWEICHPEMBOARDS							1
#define VIERCHAMPBOARDS									2

volatile uint8_t boardsconfig[3][8];

volatile uint8_t rgbwboard_connected;
volatile uint8_t dreizweichboards_connected;
volatile uint8_t vierchampboards_connected;

void rgbwboards_seach(void);
void dreizweichboards_search(void);
void vierchampboards_search(void);

unsigned char get_rgbwboard_addr(int boardnumber);
unsigned char get_32chboard_addr(int boardnumber);
unsigned char get_4champboard_addr(int boardnumber);

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

#define VIERCHAMPBOARD_ONE_ADDRESS					0x14
#define VIERCHAMPBOARD_TWO_ADDRESS					0x16
#define VIERCHAMPBOARD_THREE_ADDRESS				0x18
#define VIERCHAMPBOARD_FOUR_ADDRESS					0x1A
#define VIERCHAMPBOARD_FIVE_ADDRESS					0x1C
#define VIERCHAMPBOARD_SIX_ADDRESS					0x1E
#define VIERCHAMPBOARD_SEVEN_ADDRESS				0x20
#define VIERCHAMPBOARD_EIGHT_ADDRESS				0x22