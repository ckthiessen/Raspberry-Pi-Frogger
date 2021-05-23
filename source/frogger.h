#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define POWERUP_TIME_INTERVAL 30
#define NUM_VERTICAL_TILES 50
#define NUM_HORIZONTAL_TILES 20
#define ROW_OF_CASTLE 9
#define NUM_OBSTACLES 80
#define VERTICAL_OFFSET 3	// Offset vertical rendering by 3 to make room for game statistics

// void updateStage(int yOffset, int xOffset, int color);
void drawGameInfo(int yOffset, int xOffset, short int *stat_ptr);
// void timePt(char timeDigit, short int **time);
// void movesPt(char movesDigit, short int **moveLeft);
void digitPtr(char passedDigit, short int **digits);

void drawBackground(void);
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
int getRandomBetweenRange(int, int);
void applyPowerUp(void);
bool obstacleInView(int);

typedef struct
{
	short row;
	int col;
} Coordinate;

Coordinate FROG_START = {49, 9 * TILE_WIDTH };

typedef struct
{
	char board[NUM_VERTICAL_TILES][NUM_HORIZONTAL_TILES];
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


enum ObstacleType
{
	car,
	bus,
	wood,
	rock,
	snake
};

enum CollisionType 
{
	safe = 0,
	death = 1,
	powerUp = 2
};

typedef struct
{
	// int buff[TILE_HEIGHT * TILE_WIDTH];
	enum ObstacleType type;
	short lane;
	int colPos;
	short ** imgs;
	int numImgs;
	int velocity;
	enum CollisionType collisionType;
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


Map INITIAL_MAP = {
	// Make holes have safe spots 2-3 wide
	{"~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "~~~~~~~~~~~~~~~~~~~~",
	 "pppppppppppppppppppp",
	 "wwwwwwwwwwwwwwwwwwww",
	 "wwdwwdwwdwwdwwdwwdww",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 ";;;;;;;;;;;;;;;;;;;;",
	 "....................",
	 "||||||||||||||||||||",
	 "||||||||||||||||||||",
	 "|||o|||ooo|||o|||ooo",
	 "||||||||||||||||||||",
	 "|||oo|||ooo|||ooooo|",
	 "||||||||||||||||||||",
	 "||||||||||||||||||||",
	 "oo|||ooo|||ooo|||ooo",
	 "||||||||||||||||||||",
	 "....................",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 ",,,,,,,,,,,,,,,,,,,,",
	 "....................",
	 "--------------------",
	 "--------------------",
	 "--------------------",
	 "--------------------",
	 "....................",
	 "--------------------",
	 "--------------------",
	 "--------------------",
	 "--------------------",
	 "...................."},
	{0}};


#endif
