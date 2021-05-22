#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_RENDERED_TILES 20
#define NUM_MAP_TILES 50
#define ROW_OF_CASTLE 9
#define NUM_OBSTACLES 37
#define HORIZONTAL_OFFSET 0 // Offset horizontal rendering by 10 to eliminate obstacle pop-in
#define VERTICAL_OFFSET 3	// Offset vertical rendering by 3 to make room for game statistics
#define RENDER_EDGE (GAME_WIDTH + TILE_WIDTH)
#define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS
// Time to render a frame such that we have 10 FPS (FOR TESTING)
// #define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

// void updateStage(int yOffset, int xOffset, int color);
void drawGameInfo(int yOffset, int xOffset, short int *stat_ptr);
// void timePt(char timeDigit, short int **time);
// void movesPt(char movesDigit, short int **moveLeft);
void digitPtr(char passedDigit, short int **digits);

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
void updateScoreEnd(int yOffset, int xOffset, short int *score_ptr);

typedef struct
{
	unsigned short row, col;
} Coordinate;

Coordinate FROG_START = {49, 9};

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
	none = -1, // No powerup
	lifeUp,	   // Add a life
	timeUp,	   // Increase time
	movesUp,   // Increate num moves remaining
	slowDown   // Slow all moving obstacles
};

typedef struct
{
	Coordinate powerUpLocation;
	enum powerUpTypes type;
} PowerUp;


enum obstacleType
{
	car,
	bus,
	wood,
	rock,
	snake
};

typedef struct
{
	// int buff[TILE_HEIGHT * TILE_WIDTH];
	enum obstacleType type;
	short lane;
	int colPos;
	short ** imgs;
	int numImgs;
	int velocity;
} Obstacle;

struct Game
{
	short scrollOffset;		 // Offset used for vertical scrolling
	short action;			 // Current player action
	Coordinate frogLocation; // Frog current location
	double elapsedTime;		 // Current elapsed time
	double lastPowerUpTime;	 // Last time power up was generated
	PowerUp currentPowerUp;	 // Power up to display
	double secondsPerFrame;	 // Current frame rate
	int lives;				 // Remaining lives
	int moves;				 // Remaining moves
	double timeRemaining;	 // Remaining time
	Map map;				 // Game map
	bool win;				 // Won game
	bool lose;				 // Lost game
	bool quit;				 // Quit game
	//-----------
	// int statBarCounter;			// Used to diplay the correct time output
	int score;
	int movesMade;
	char scoreStr[4];
	Obstacle obstacles[NUM_OBSTACLES];
	short collisionBuffer[GAME_WIDTH * GAME_HEIGHT];
	int obstaclesInitialized;
} game;

// obst = {
// 	(short *) water_img.pixel_data,
// 	48,
// 	-1 * TILE_WIDTH
// };

Map INITIAL_MAP = {
	// Make holes have safe spots 2-3 wide
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
	 ".......hhhhdhhdhhhdstdddddhhhd...................",
	 ".......hhhdstdddddhdddhhddddhh...................",
	 ".......hhhddddstdddhhdddstddhh...................",
	 ".......hhhdhhdhhhhdstdddddddhh...................",
	 ".......hhhddstdhhhhhhdstddddhh...................",
	 ".......hhhhddddhhddstdddhhhdhh...................",
	 ".................................................",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
	 ".................................................",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
	 ".................................................",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
	 "-------------------------------------------------",
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
	12,
	6,
	0,
};

#endif
