#ifndef CONTROLLER
#define CONTROLLER

// Button name and corresponding code
#define START 4
#define UP 5
#define DOWN 6
#define LEFT 7
#define RIGHT 8
#define NO_ACTION -1 // Set no action taken to -1 
#define SELECT 9

void initController(void);
int sampleController(void);
int Read_SNES(void);
void init_GPIO(void);

#endif


