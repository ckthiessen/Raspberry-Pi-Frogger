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
#define SECONDS_PER_FRAME 1 / 5
 // Time to render a frame such that we have 10 FPS (FOR TESTING)
// #define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

void updateStage(int yOffset, int xOffset, int color);
void mapBoardToStage(bool debug);
void checkCollision(void);
void update(void);
void pauseGame(void);
void moveFrog(int direction);
void doUserAction(void);
void drawStageToFrameBuffer(void);
void *getUserInput(void *);
void resetFrogPosition(void);
void updateFrogLocation(void);
void initializeGame(void);

typedef struct
{
	unsigned short row, col;
} Coordinate;

Coordinate FROG_START = {49, 19};

typedef struct
{
	char board[NUM_MAP_TILES][NUM_MAP_TILES];
	unsigned short stage[GAME_WIDTH * GAME_HEIGHT];
} Map;

struct Game
{
	short scrollOffset; // Offset used for scrolling
	short action;
	Coordinate frogLocation;
	double elapsedTime;
	int lives;
	Map map;
} game;

Map INITIAL_MAP = {
	{".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ".................................................",
	 ";;;;;rr;;;;;;;;;;rrrr;;;;;rrr;;;;rr;;;;rr;;;rrrrr",
	 ";;;;;;rrrr;;;;;;;;;;;;;;rrrr;;;rrrr;;;;rrrr;;rrrr",
	 ";;rrrr;;;;rrr;;;;rrr;;;;;;;;rrr;;rrrr;rr;;;rrrrr;",
	 ";;;;;rrrr;;;;;;rrrr;;;;;;rrr;;;;rrrr;;;;rrr;;rrr;",
	 ";;;;;rr;;;;;;;;;;rrrr;;;;;rrr;;;;rr;;;;rr;;;rrrrr",
	 ";;;;;;rrrr;;;;;;;;;;;;;;rrrr;;;rrrr;;;;rrrr;;rrrr",
	 ";;rrrr;;;;rrr;;;;rrr;;;;;;;;rrr;;rrrr;rr;;;rrrrr;",
	 ";;;;;rrrr;;;;;;rrrr;;;;;;rrr;;;;rrrr;;;;rrr;;rrr;",
	 ";;rrrr;;;;rrr;;;;rrr;;;;;;;;rrr;;rrrr;rr;;;rrrrr;",
	 ".................................................",
	 ".......hhhh.h.h.hh.hhh.hhhhhhh...................",
	 ".......hhh.ss...hh..ss...hhhhh...................",
	 ".......hhhh..h..hhh.....hhhhhh...................",
	 ".......hhhh..hh.hhh.ss.....hhh...................",
	 ".......hhh.ss.....h...hh....hh...................",
	 ".......hhh....ss...hh...ss..hh...................",
	 ".......hhh.hh.hhhh.ss.......hh...................",
	 ".......hhh..ss.hhhhhh.ss....hh...................",
	 ".......hhhh....hh..ss...hhh.hh...................",
	 ".................................................",
	 ",,,,,ll,,,,,,,,,,llll,,,,,lll,,,,ll,,,,ll,,,lllll",
	 ",,,,,,llll,,,,,,,,,,,,,,llll,,,llll,,,,llll,,llll",
	 ",,llll,,,,lll,,,,lll,,,,,,,,lll,,llll,ll,,,lllll,",
	 ",,,,,llll,,,,,,llll,,,,,,lll,,,,llll,,,,lll,,lll,",
	 ",,,,,ll,,,,,,,,,,llll,,,,,lll,,,,ll,,,,ll,,,lllll",
	 ",,,,,,llll,,,,,,,,,,,,,,llll,,,llll,,,,llll,,llll",
	 ",,llll,,,,lll,,,,lll,,,,,,,,lll,,llll,ll,,,lllll,",
	 ",,,,,llll,,,,,,llll,,,,,,lll,,,,llll,,,,lll,,lll,",
	 ",,llll,,,,lll,,,,lll,,,,,,,,lll,,llll,ll,,,lllll,",
	 ".................................................",
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-",
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--",
	 "----cc-----cc--------cc-------cc----cc--------cc-",
	 "--bbbb------------bbbb---------bbbb------bbbb----",
	 "-----cc----------cc--------cc----cc----cc---cc-cc",
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb",
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-",
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--",
	 "----cc-----cc--------cc-------cc----cc--------cc-",
	 "................................................."},
	{0}};

short laneVelocities[NUM_MAP_TILES] = {
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	-1,
	1,
	1,
	1,
	1,
	1,
	-1,
	1,
	-1,
	1,
	1,
	-1,
	0,
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
