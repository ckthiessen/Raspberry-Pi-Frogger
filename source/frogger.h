// Authors: Cole Thiessen (30027689) & Isaac Lutzko (30026703)
// CPSC359 Winter 2021 Project (Part 2) Raspberry Pi Video Game
// May 2021 (extended deadline due to deferral)
// Description: Header file for the main game file (frogger.c) which contains macros, explicit declarations of functions used in frogger.c, 
//				type definitions of structs, defined data types (enums), and the game map background characters (50 tiles high by 20 tiles wide).
//				The header file is used for putting global definitions in one place and import them as needed. This declutters the frogger.c file and makes it more readable.

#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280				// Width of the game screen in pixels (1280x720)
#define GAME_HEIGHT 720				// Height of the game screen in pixels (1280x720)
#define TILE_HEIGHT 36				// Height of each tile on the screen is 36 pixels high (20x20 tile game environment)
#define TILE_WIDTH 64				// Width of each tile on the screen is 64 pixels wide (20x20 tile game environment)
#define POWERUP_TIME_INTERVAL 30	// New powerup's are generated every 30 seconds, starting at the first 30 seconds of the game
#define NUM_VERTICAL_TILES 50		// Game board is 50 tiles high (only 20 tiles high displayed at a time)
#define NUM_HORIZONTAL_TILES 20		// Game board is 20 tiles wide (only 20 tiles wide displayed at a time)
#define ROW_OF_CASTLE 9				// 9 rows at top of game board is reserved for the castle at the end
#define NUM_OBSTACLES 77			// Number of obstacles on the full game board at a time - note that not all 80 displayed on screen at a time (20x20 game map)
#define VERTICAL_OFFSET 3			// Offset vertical rendering by 3 to make room for game statistics
#define TIME_STAT_BAR_TO_CHARS 50	// Number of chars for converting the time remaining of the game to an array of chars for displaying time on the status bar
#define MOVES_STAT_BAR_TO_CHARS 5	// Number of chars for converting the # of moves that a player has left of the game to an array of chars for displaying time on the status bar 
#define LIVES_STAT_BAR_TO_CHARS 3	// Number of chars for converting the # of lives that a player during the game to an array of chars for displaying lives on the status bar
#define TIME_MOVE_PREPEND_ZERO 4	// Used for prepending a zero to time left or # of moves left on the status bar if needed
#define SCORE_PREPEND_ZERO 3		// Used for prepending a zero to the score on the status bar if needed
#define TOP_ROW_STAT_BAR 17			// Top row on the status bar that shows time remaining, score, and lives left
#define BOTTOM_ROW_STAT_BAR 19		// Bottom row on the status bar that shows moves left and the value pack/powerup that is displayed on the screen

// Explicit declarations of functions before they are called that are in frogger.c - see proper documentation of each of these functions in frogger.c
void drawGameInfo(int yOffset, int xOffset, short int *stat_ptr);
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
void clearObstacleMemory(void);

// Struct defined for the coordinates of where a tile is on the game map
typedef struct
{
	short row;
	int col;
} Coordinate;

// Coordinate for where a frog starts at the beginning of the game or where a frog goes back to if they die and lose a life
Coordinate FROG_START = {49, 9 * TILE_WIDTH };

// Struct defined for the game map
// Map.board = game board by tiles (50 tiles high by 20 tiles wide) for drawing the game background - only 20x20 displayed at a time
// Map.stage = game screen resolution size (1280x720) - stage is drawn to the frame buffer for displaying the screen (see drawStageToFrameBuffer(void) function)
typedef struct
{
	char board[NUM_VERTICAL_TILES][NUM_HORIZONTAL_TILES];
	unsigned short stage[GAME_WIDTH * GAME_HEIGHT + 1];
} Map;

// options data type for what state the game is in for displaying the main menu or the pause menu
enum options
{
	resume,
	quit,
	restart,
	exitGame
};

// powerUpTypes data type for what powerup the frog currently has during the game
enum powerUpTypes
{
	none = -1, // No powerup
	lifeUp,	   // Add a life
	timeUp,	   // Increase time
	movesUp,   // Increate num moves remaining
	slowDown   // Slow all moving obstacles
};

// Struct defined for powerups
// Powerups have a coordinate as to where they are displayed on the screen and what power up type it has (i.e., what benefit does the powerup give to the player)
typedef struct
{
	Coordinate powerUpLocation;
	enum powerUpTypes type;
} PowerUp;

// ObstacleType data type for each obstacle - used to differentiate what different obstacles do (hitting a car would kill the frog, wood used for moving across water and would not kill frog)
enum ObstacleType
{
	car,
	bus,
	wood,
	rock,
	snake
};

// CollisionType data type for what each collision does to a frog:
// Colliding with a safe tile keeps frog alive, colliding with a death tile kills the frog, colliding with a powerUp tile gives frog the benefit of the powerUp
enum CollisionType 
{
	safe = 0,
	death = 1,
	powerUp = 2
};

// Struct defined for each obstacle and its' respective properties
typedef struct
{
	enum ObstacleType type;				// Each obstacle has a type (car, bus, wood, rock, or snake)
	short lane;							// What lane/row the obstacle is in
	int colPos;							// What column the obstacle is in at a specific time as it moves across the screen
	short ** imgs;						// Which images are needed to display specific obstacle (e.g., cars have one car front image and one car back image)
	int numImgs;						// How many images are needed for the obstacle (e.g., cars have 2 tile images, snakes have 3-5 tile images, etc)
	int velocity;						// Positive moves left to right (higher the positive int - quicker it moves), negative moves right to left (lower the negative int - quicker it moves)
	enum CollisionType collisionType;	// Will colliding with this obstacle kill the frog, keep the frog alive, or give the frog the powerup benefit
} Obstacle;

// Struct defined for the overall game and its' respective properties
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
	bool quit;				 // Quit to main menu
	bool exitGame;				 // Exit the program
	bool paused;			 // Pause game
	int score;				 // Player/Frog score
	int movesMade;			 // Moves made by player
	char scoreStr[4];		 // Score char array that is converted from int for displaying score on status bar and win or lose prompt
	Obstacle obstacles[NUM_OBSTACLES];	// Obstacles array that contains the obstacles that are in the game
	short collisionBuffer[GAME_WIDTH * GAME_HEIGHT];	// Collision buffer maps 1-to-1 with each pixel and determines the collision type of that pixel (death, safe or power up)
	int obstaclesInitialized;			// Number of obstacles that are initialized during the game
} game;

// Game map that contains characters that correspond to the background tiles
Map INITIAL_MAP = {
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
