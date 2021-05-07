#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_RENDERED_TILES 20
#define NUM_MAP_TILES 50
#define ROW_OF_CASTLE 9
#define HORIZONTAL_OFFSET 9 // Offset horizontal rendering by 10 to eliminate obstacle pop-in
#define VERTICAL_OFFSET 3 // Offset vertical rendering by 3 to make room for game statistics
// #define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS
 // Time to render a frame such that we have 10 FPS (FOR TESTING)
// #define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

// void updateStage(int yOffset, int xOffset, int color);
// void drawGameInfo(void);
void mapBoardToStage(bool debug);
void checkCollision(void);
void update(void);
void pauseGame(bool isMainMenu);
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
	unsigned short stage[GAME_WIDTH * GAME_HEIGHT + 1];
} Map;

enum options
{
	resume,
	quit,
	restart
};

enum powerUpTypes
{
	none = -1,	// No powerup
	lifeUp,		// Add a life
	timeUp,		// Increase time
	movesUp,	// Increate num moves remaining
	slowDown	// Slow all moving obstacles
};

typedef struct
{
	Coordinate powerUpLocation;
	enum powerUpTypes type; 
} PowerUp;

struct Game
{
	short scrollOffset;			// Offset used for vertical scrolling
	short action;				// Current player action
	Coordinate frogLocation;	// Frog current location
	double elapsedTime;			// Current elapsed time
	double lastPowerUpTime;		// Last time power up was generated
	PowerUp currentPowerUp;		// Power up to display
	double secondsPerFrame; 	// Current frame rate
	int lives;					// Remaining lives
	int moves;					// Remaining moves
	double timeRemaining;		// Remaining time
	Map map;					// Game map
	bool win;					// Won game
	bool lose;					// Lost game
	bool quit;					// Quit game
	//-----------
	int statBarCounter;			// Used to diplay the correct time output
} game;

Map INITIAL_MAP = {
	{"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
	 "ppppppppppppppppppppppppppppppppppppppppppppppppp",
	 "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
	 "wwowwowwowwowwowwowwowwowwowwowwowwowwowwowwowwow",
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
	 ".......hhhhdhdhdhhdhhhdhhhhhhh...................",
	 ".......hhhdstdddhhddstdddhhhhh...................",
	 ".......hhhhddhddhhhdddddhhhhhh...................",
	 ".......hhhhdhhdhhhdstdddddhhhd..................",
	 ".......hhhdstdddddhdddhhddddhh...................",
	 ".......hhhddddstdddhhdddstddhh...................",
	 ".......hhhdhhdhhhhdstdddddddhh...................",
	 ".......hhhddstdhhhhhhdstddddhh...................",
	 ".......hhhhddddhhddstdddhhhdhh...................",
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
	 "--ac------ac------ac--------ac--------ac------ac-",
	 "-----ac--------ac--------ac-----ac-------ac------",
	 "----ac-----ac--------ac-------ac----ac--------ac-",
	 "--bmme------------bmme---------bmme------bmme----",
	 "-----ac----------ac--------ac----ac----cc------ac",
	 "------bmme--------------bmme---bmme----bmme--bmme",
	 "--ac------ac------ac--------ac----ac----------ac-",
	 "-----ac--------ac--------ac--------ac----ac------",
	 "-----------ac--------ac-------ac------ac------ac-",
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
