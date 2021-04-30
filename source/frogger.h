#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_RENDERED_TILES 20
#define NUM_MAP_TILES 50
#define HORIZONTAL_OFFSET 9 // Offset horizontal rendering by 10 to eliminate obstacle pop-in
// #define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS
#define SECONDS_PER_FRAME 1/4 // Time to render a frame such that we have 10 FPS (FOR TESTING)
// #define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

void updateStage(int yOffset, int xOffset, int color);
void mapBoardToStage(bool debug);
void checkCollision();
void update();
void pauseGame();
void moveFrog(int direction);
void doUserAction();
void drawStageToFrameBuffer();
void *getUserInput();
void resetFrogPosition();
void initializeGame();

typedef struct
{
	unsigned short row, col;
} Coordinate;

Coordinate FROG_START = { 49, 19 };

struct Game
{
	short scrollOffset; // Offset used for scrolling
	short action;
	Coordinate frogLocation;
	float elapsedTime;
	int lives;
} game;

struct Map
{
	char board[NUM_MAP_TILES][NUM_MAP_TILES];
	unsigned short stage[GAME_WIDTH * GAME_HEIGHT];
} map = {
	{"--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "ggggggggggggggggggggggggggggggggggggggggggggggggg", //fw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "gggggggggfggggggggggggggggggggggggggggggggggggggg"},
	{}};

short laneVelocities[NUM_MAP_TILES] = {
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	-1,
	1,
	1,
	-2,
	-1,
	-1,
	2,
	1,
	-1,
	2,
	1,
	0,
};

#endif


