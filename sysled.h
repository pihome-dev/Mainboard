#define STATE_IDLE							0
#define STATE_RUN								1
#define STATE_ERROR							2

#define STATETIME_IDLE_ON					500
#define STATETIME_IDLE_OFF					500
#define STATETIME_IDLE_WAIT				0

#define STATETIME_RUN_ON					100
#define STATETIME_RUN_OFF					900
#define STATETIME_RUN_WAIT					0

#define STATETIME_ERROR_ON					700
#define STATETIME_ERROR_OFF				300
#define STATETIME_ERROR_WAIT				0

#define PININVERT								0

volatile int statestate;
volatile int systemstate;
volatile int stateTimer;

void stateled_init(void);
void stateled_off(void);
void stateled_on(void);
void stateled(void);
