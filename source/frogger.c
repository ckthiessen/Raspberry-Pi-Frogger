// Authors: Cole Thiessen (30027689) & Isaac Lutzko (30026703)
// CPSC359 Winter 2021 Project (Part 2) Raspberry Pi Video Game
// May 2021 (extended deadline due to deferral)
// Description:

// Link/Reference for Frogger Image: https://www.funstockretro.co.uk/news/arcade-hall-of-fame-frogger-konami/
// Link/Reference for Crazy Frog Image: https://www.thesun.co.uk/living/2974489/crazy-frog-just-turned-20-relive-his-hellish-magic-here/
// Link/Reference for Pepe Frog Image: https://line.17qq.com/articles/doddbhdz.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <wiringPi.h> //delayMicroseconds(int)
#include <stdbool.h>  //true, false
#include <unistd.h>
#include <pthread.h>
#include "frogger.h"
#include "framebuffer.h"
#include "controller.h"
#include "images/frog.h"

// import main menu image header files
#include "images/menus/main_menu_quit_game.h"
#include "images/menus/main_menu_start_game.h"
#include "images/menus/pause_menu_quit.h"
#include "images/menus/pause_menu_restart.h"
#include "images/menus/you_lose_prompt_w_score.h"
#include "images/menus/you_win_prompt_w_score.h"

// import images for life packs, the safe zone, obstacles, the status bar, and the castle
#include "images/safe_zone.h"
#include "images/life_packs/more_lives.h"
#include "images/life_packs/more_time.h"
#include "images/life_packs/more_steps.h"
#include "images/life_packs/slow_down_obstacles.h"
#include "images/obstacles/boulder.h"
#include "images/obstacles/bus_back.h"
#include "images/obstacles/bus_front.h"
#include "images/obstacles/bus_mid.h"
#include "images/obstacles/car_back.h"
#include "images/obstacles/car_front.h"
#include "images/obstacles/lava.h"
#include "images/obstacles/log.h"
#include "images/obstacles/pit.h"
#include "images/obstacles/snake_left_head.h"
#include "images/obstacles/snake_right_head.h"
#include "images/obstacles/snake_mid.h"
#include "images/obstacles/water.h"
#include "images/obstacles/desert.h"
#include "images/obstacles/black_road.h"
#include "images/status_bar/0_img.h"
#include "images/status_bar/1_img.h"
#include "images/status_bar/2_img.h"
#include "images/status_bar/3_img.h"
#include "images/status_bar/4_img.h"
#include "images/status_bar/5_img.h"
#include "images/status_bar/6_img.h"
#include "images/status_bar/7_img.h"
#include "images/status_bar/8_img.h"
#include "images/status_bar/9_img.h"
#include "images/status_bar/left_img.h"
#include "images/status_bar/lives_img.h"
#include "images/status_bar/moves_img.h"
#include "images/status_bar/NA_img.h"
#include "images/status_bar/pack_img.h"
#include "images/status_bar/score_img.h"
#include "images/status_bar/time_img.h"
#include "images/status_bar/value_img.h"
#include "images/castle/castle_wall.h"
#include "images/castle/castle_door.h"
#include "images/castle/castle_sky.h"
#include "images/castle/castle_top.h"

// instance of the frame buffer struct in framebuffer.h
struct fbs framebufferstruct;

// Pointers for graphics:
// Frog Pointer
short int *frogPtr = (short int *)frog_img.pixel_data;

// Safe Zone Pointer
short int *safePtr = (short int *)safe_zone_img.pixel_data;

// Menu Pointers
short int *mainMenuStartPtr = (short int *)main_menu_start_img.pixel_data;
short int *mainMenuQuitPtr = (short int *)main_menu_quit_img.pixel_data;
short int *pauseMenuQuitPtr = (short int *)pause_menu_quit_img.pixel_data;
short int *pauseMenuRestartPtr = (short int *)pause_menu_restart_img.pixel_data;
short int *winPromptPtr = (short int *)you_win_img.pixel_data;
short int *losePromptPtr = (short int *)you_lose_img.pixel_data;

// Life Pack Pointers
short int *moreLivesPtr = (short int *)most_lives_img.pixel_data;
short int *moreTimePtr = (short int *)more_time_img.pixel_data;
short int *moreStepsPtr = (short int *)more_steps_img.pixel_data;
short int *slowDownPtr = (short int *)slow_down_obstacles_img.pixel_data;

// Obstacle Pointers
short int *boulderPtr = (short int *)boulder_img.pixel_data;
short int *busBackPtr = (short int *)bus_back_img.pixel_data;
short int *busFrontPtr = (short int *)bus_front_img.pixel_data;
short int *busMidPtr = (short int *)bus_mid_img.pixel_data;
short int *carBackPtr = (short int *)car_back_img.pixel_data;
short int *carFrontPtr = (short int *)car_front_img.pixel_data;
short int *lavaPtr = (short int *)lava_img.pixel_data;
short int *logPtr = (short int *)log_image.pixel_data;
short int *pitPtr = (short int *)pit_img.pixel_data;
short int *snakeLeftPtr = (short int *)snake_left.pixel_data;
short int *snakeRightPtr = (short int *)snake_right.pixel_data;
short int *snakeMidPtr = (short int *)snake_mid_img.pixel_data;
short int *waterPtr = (short int *)water_img.pixel_data;
short int *desertPtr = (short int *)desert_img.pixel_data;
short int *blackRoadPtr = (short int *)black_road_img.pixel_data;

// Castle Pointers
short int *castleWallPtr = (short int *)castle_wall_img.pixel_data;
short int *castleDoorPtr = (short int *)castle_door_img.pixel_data;
short int *castleTopPtr = (short int *)castle_top_img.pixel_data;
short int *castleSkyPtr = (short int *)castle_sky_img.pixel_data;

// Status Bar Pointers
short int *zeroPtr = (short int *)zero_img.pixel_data;
short int *onePtr = (short int *)one_img.pixel_data;
short int *twoPtr = (short int *)two_img.pixel_data;
short int *threePtr = (short int *)three_img.pixel_data;
short int *fourPtr = (short int *)four_img.pixel_data;
short int *fivePtr = (short int *)five_img.pixel_data;
short int *sixPtr = (short int *)six_img.pixel_data;
short int *sevenPtr = (short int *)seven_img.pixel_data;
short int *eightPtr = (short int *)eight_img.pixel_data;
short int *ninePtr = (short int *)nine_img.pixel_data;
short int *leftPtr = (short int *)left_img.pixel_data;
short int *livesPtr = (short int *)lives_img.pixel_data;
short int *movesPtr = (short int *)moves_img.pixel_data;
short int *naPtr = (short int *)NA_img.pixel_data;
short int *packPtr = (short int *)pack_img.pixel_data;
short int *scorePtr = (short int *)score_img.pixel_data;
short int *timePtr = (short int *)time_img.pixel_data;
short int *valuePtr = (short int *)value_img.pixel_data;

/*
@Params: yOffset: integer that is used for offsetting what row the image is being drawn to
@Params: xOffset: integer that is used for offsetting what column the image is being drawn to
@Params: *img_ptr: short int image pointer that is being drawn to a position in the stage
@Params: type: CollisionType that is defined in frogger.h that declares as to what kind collision the tile is - (safe, death, powerUp)
@Returns: This subroutine does not return anything
This subroutine takes in a yOffset and an xOffset that corresponds as to what tile the image (image as a pointer in *img_ptr) is being
drawn to.  The location of the pixel being drawn also has a type as per the CollisionType that is also being passed.
*/
void updateStage(int yOffset, int xOffset, short int *img_ptr, enum CollisionType type)
{
	// If the obstacle that is being drawn to the stage will be displayed on the screen then draw to stage, otherwise don't draw to stage
	if (obstacleInView(yOffset))
	{
		int i = 0;
		// Draw image from *img_ptr with 2 for loops similar to DrawImage zip file in tutorial content
		for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
		{
			for (int x = TILE_WIDTH * xOffset; x < TILE_WIDTH * (xOffset + 1); x++)
			{
				int loc = ((y * GAME_WIDTH) + x) - (((VERTICAL_OFFSET * TILE_HEIGHT) * GAME_WIDTH) + NUM_HORIZONTAL_TILES * TILE_WIDTH);
				if (loc > 0)
				{
					game.collisionBuffer[loc] = type; // Set pixel collisionType in collisionBuffer to the passed tile which is used for collision detection
					game.map.stage[loc] = img_ptr[i]; // Set pixel to color from *img_ptr
				}
				i++;
			}
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine is used for drawing the background as per the map that is defined in frogger.h.  Each character in the map corresponds to a specific
image for drawing the background (e.g., 'o' corresponds to a pit in challenge #3, ';' corresponds to the lava in challenge #4).  Iterating through
the characters in the map, using a switch statement we set each character to a specific image pointer and a collisionType for updateStage().  By
setting each tile to an image and a collisionType we can then call updateStage for that tile, and then the stage can be drawn to the frame
buffer to display the background screen.
*/
void drawBackground(void)
{
	for (int row = game.scrollOffset; row < NUM_HORIZONTAL_TILES + game.scrollOffset; row++)
	{
		for (int col = 0; col < NUM_HORIZONTAL_TILES; col++)
		{
			char tile = game.map.board[row][col]; // Tile that corresponds to specific tile in the game board as per the row and column
			short int *ptr;
			enum CollisionType type;
			switch (tile)
			{
			// road
			case '-':
				type = safe;
				ptr = blackRoadPtr;
				break;
			// hole/pit for snakes and pits
			case 'o':
				type = death;
				ptr = pitPtr;
				break;
			// desert background for snakes and pits
			case '|':
				type = safe;
				ptr = desertPtr;
				break;
			// lava
			case ';':
				type = death;
				ptr = lavaPtr;
				break;
			// water
			case ',':
				type = death;
				ptr = waterPtr;
				break;
			// safe zone
			case '.':
				type = safe;
				ptr = safePtr;
				break;
			// castle wall
			case 'w':
				type = safe;
				ptr = castleWallPtr;
				break;
			// castle door
			case 'd':
				type = safe;
				ptr = castleDoorPtr;
				break;
			// castle top
			case 'p':
				type = safe;
				ptr = castleTopPtr;
				break;
			// castle sky
			case '~':
				type = safe;
				ptr = castleSkyPtr;
				break;
			default:
				type = safe;
				ptr = blackRoadPtr;
				break;
			}
			updateStage(row, col, ptr, type); // Call updateStage for the tile by its row, its column, the short int image pointer and the collisionType
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine is used to check if the frog has collided with an object kills him or has collided with a powerUp.  
*/
void checkCollision(void)
{
	bool collision = false; // Collision default set to false here
	for (int y = (TILE_HEIGHT + 1) * (game.frogLocation.row - game.scrollOffset); y < (TILE_HEIGHT) * (game.frogLocation.row - game.scrollOffset + 1); y++)
	{
		for (int x = game.frogLocation.col; x < game.frogLocation.col + TILE_WIDTH; x++)
		{
			int loc = ((y * GAME_WIDTH) + x) - (((VERTICAL_OFFSET * TILE_HEIGHT) * GAME_WIDTH) + NUM_HORIZONTAL_TILES * TILE_WIDTH); // Get location of pixel
			if (game.collisionBuffer[loc] == death)																					 // Check if frog colliding with pixel kills the frog
			{
				collision = true;	 // Set collision to true since the frog collided with a pixel that kills it
				resetFrogPosition(); // Move frog back to the start
				game.lives--;		 // Decrement the number of lives the frog has
				break;
			}
			if (game.collisionBuffer[loc] == powerUp) // Check if frog collided with a pixel that corresponds to a powerUp
			{
				collision = true; // Set collision to true since the frog collided with a pixel that corresponds to a powerUp
				applyPowerUp();	  // Apply appropriate powerUp
				game.score += 50; // Increment score of player by 50
				game.currentPowerUp.type = none;
			}
		}
		if (collision) // If frog collided with a lethal pixel or a pixel that corresponds to a powerUp, break loop
		{
			break;
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine calculates a players' score when the game is over - whether the player loses or wins
*/
void calculateScore(void)
{
	if (game.lives > 0)	// If the game is won, add to the score for winning, otherwise do not add the below additions to the score if game lost
	{
		game.score += ((400 - game.movesMade) * 5);	// The fewer the moves made to win, the higher the score
		game.score += ((500 + game.timeRemaining) * 5); // The faster the game is won, the higher the score
		game.score += (200 * game.lives); // The most lives you finish with after the win, the higher the score
	}

	sprintf(game.scoreStr, "%d", game.score);	// Convert game score integer to string for displaying score correctly on screen

	if (game.score < 1000)	// If game score is less than 1000, prepend a zero for displaying score correctly on screen
	{
		memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
		game.scoreStr[0] = '0';
		if (game.score < 100)	// if game score is less than 100, prepend a zero for displaying score correctly on screen
		{
			memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
			game.scoreStr[0] = '0';
			if (game.score < 10)	// if game score is less than 10, prepend a zero for displaying score correctly on screen
			{
				memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
				game.scoreStr[0] = '0';
			}
		}
	}

	short int *calcScorePtr;	// Short int pointer used for getting correct image pointer for a digit on the status bar 

	digitPtr(game.scoreStr[0], &calcScorePtr);	// Get image pointer for thousandth digit 
	drawGameInfo(13, 10, calcScorePtr);			// Draw digit for thousandth digit

	digitPtr(game.scoreStr[1], &calcScorePtr);	// Get image pointer for hundredth digit
	drawGameInfo(13, 11, calcScorePtr);			// Draw digit for hundredth digit

	digitPtr(game.scoreStr[2], &calcScorePtr);	// Get image pointer for tens digit
	drawGameInfo(13, 12, calcScorePtr);			// Draw digit for tens digit

	digitPtr(game.scoreStr[3], &calcScorePtr);	// Get image pointer for ones digit
	drawGameInfo(13, 13, calcScorePtr);			// Draw digit for ones digit
}

/*
@Params: *menu: short image pointer that takes in a specific menu image pointer (e.g., pause menu when restart is selected)
@Params: heightOffset: integer that corresponds to the height of the menu that is passed (e.g., pause menu has different height than main menu)
@Params: widthOffset: integer that corresponds to the width of the menu that is passed (e.g., pause menu has different width than main menu)
@Returns: This subroutine does not return anything
This subroutine takes in the short image pointer that is being drawn and it's respective height and width by its' tiles and sets
each pixel in the stage to the appropriate color from the menu short image pointer that is passed.  If the game ends, the calculateScore()
function is called that sets the score digits in the win or lose prompt/menu.  After the stage has been set, the drawStageToFrameBuffer()
function is called to display the appropriate screen
*/
void displayMenu(short *menu, int heightOffset, int widthOffset)
{
	int i = 0;
	for (int y = heightOffset; y < GAME_HEIGHT - heightOffset; y++)
	{
		for (int x = widthOffset; x < GAME_WIDTH - widthOffset; x++)
		{
			game.map.stage[((y * GAME_WIDTH) + x) % (GAME_HEIGHT * GAME_WIDTH)] = menu[i];
			i++;
		}
	}

	if (game.win == true || game.lose == true)	// if game has ended, set tiles in stage for displaying score
		calculateScore();

	drawStageToFrameBuffer();
}

/*
@Params: isMainMenu: boolean that checks if menu is the main menu or not
@Returns: This subroutine does not return anything
This subroutine displays the correct menu - either the main menu or the pause menu, starting with the start game main menu 
or the restart game pause menu and changes depending on user action on the joypad on the SNES - and makes appropriate changes
to the game state.  First if at main menu, display the start game main menu and set game option to resume, otherwise display 
the restart game pause menu and set game option to restart.  From then, the menu that is displayed changes depending on user movement
on the joypad.  If user presses left or right on the joypad, the menu that is displayed changes to show that the player wants to 
select a different option (e.g., user sees restart game pause menu, then presses left to select quit game pause menu).  From there,
if the user selects the option that is shown to them - either resume game, quit game, or restart game - then the appropriate actions
are made to game state.
*/
void pauseGame(bool isMainMenu)
{
	enum options currentOption;
	short *menu;
	if (isMainMenu) // If menu is the main menu then display the default main menu and set default game option to resume for starting the game
	{
		menu = mainMenuStartPtr;
		currentOption = resume;
		displayMenu(menu, 0, 0);
	}
	else // Menu is pause menu so display default pause menu and set default game option to restarting game
	{
		currentOption = restart;
		menu = pauseMenuRestartPtr;
		displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
	}
	game.action = NO_ACTION;
	bool paused = true;
	while (paused) // Loop that acts depending on user input on SNES
	{
		if (game.action == LEFT || game.action == RIGHT)  // If user changes selection on menu
		{
			if (isMainMenu)	// If main menu then change selected option on menu
			{
				game.action = -1;
				menu = menu == mainMenuStartPtr ? mainMenuQuitPtr : mainMenuStartPtr;
				currentOption = menu == mainMenuStartPtr ? resume : exitGame;
				displayMenu(menu, 0, 0);
			}
			else	// Since pause menu then change selected option on menu
			{
				game.action = -1;
				menu = menu == pauseMenuQuitPtr ? pauseMenuRestartPtr : pauseMenuQuitPtr;
				currentOption = menu == pauseMenuQuitPtr ? quit : restart;
				displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
			}
			usleep(500 * 1000);
		}
		if (game.action == SELECT)	// If user has selected the current option then make appropriate action
		{
			switch (currentOption)
			{
			case resume:
				break;
			case quit:
				game.quit = true;
				break;
			case restart:
				clearObstacleMemory();
				initializeGame();
				break;
			case exitGame:
				game.exitGame = true;
				break;
			}
			game.paused = false;
		}
		if (game.action == START && !isMainMenu)	// If user wants to resume game after pausing it
		{
			game.paused = false;
			usleep(500 * 1000);
		}
	}
}

/*
@Params: *menu: short image pointer that takes in the win or lose prompt menu
@Returns: This subroutine does not return anything
This subroutine takes in the win or lose prompt depending on if the player won or lost and displays the appropriate menu
*/
void endGame(short *menu)
{
	game.action = NO_ACTION;
	game.paused = true;
	displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
	while (game.paused)
	{
		if (game.action != -1)
		{
			game.paused = false;
			usleep(500 * 1000);
		}
	}
}

/*
@Params: a: integer that is used for determining the max of the two passed integers
@Params: b: integer that is used for determining the max of the two passed integers
@Returns: int: returns the maximum of the two passed integers
This subroutine takes in two integers and returns the maximum of the two
*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/*
@Params: a: integer that is used for determining the minimum of the two passed integers
@Params: b: integer that is used for determining the minimum of the two passed integers
@Returns: int: returns the minimum of the two passed integers
This subroutine takes in two integers and returns the minimum of the two
*/
int min(int a, int b)
{
	return a < b ? a : b;
}

/*
@Params: direction: integer that takes in the 
@Returns: This subroutine does not return anything
This subroutine moves the location of the frog on the game map depending on a users input on the SNES from game.action.  
The screen also moves along with the frog to keep the frog in the center of the screen, done with the game.scrollOffset. 
When a player moves the frog, that also adds to the players score.
*/
void moveFrog(int direction)
{
	bool moved = false;
	switch (game.action)
	{
	// Player presses up on the SNES joypad
	case UP:
		if (game.frogLocation.row > 1)
		{
			game.frogLocation.row--;
			moved = true;
			if (game.frogLocation.row < 40 && game.frogLocation.row >= 10)
			{
				game.scrollOffset--;
			}
		}
		break;
	// Player presses down on the SNES joypad
	case DOWN:
		if (game.frogLocation.row < NUM_VERTICAL_TILES - 1)
		{
			game.frogLocation.row++;
			moved = true;
			if (game.frogLocation.row >= 10)
			{

				game.scrollOffset = min(game.scrollOffset + 1, 30);
			}
		}
		break;
	// Player presses left on the SNES joypad
	case LEFT:
		if (game.frogLocation.col > 0)
		{
			moved = true;
			game.frogLocation.col = max(game.frogLocation.col - TILE_WIDTH, 0);
		}
		break;
	// Player presses right on the SNES joypad
	case RIGHT:
		if (game.frogLocation.col < GAME_WIDTH)
		{
			moved = true;
			game.frogLocation.col = min(game.frogLocation.col + TILE_WIDTH, GAME_WIDTH);
		}
		break;
	}
	if (moved)	// If Player moves frog, decrement moves left to display correct status bar, increment moves made by player to increase score
	{
		game.moves--;
		game.movesMade++;
		if (game.movesMade <= 50)
		{
			game.score += 3;
		}
		else if (game.movesMade <= 100)
		{
			game.score += 2;
		}
		else if (game.movesMade <= 150)
		{
			game.score += 2;
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine presents the main menu if the user starts the program by calling pauseGame(false), otherwise makes appropriate
changes to game state when the player moves the frog
*/
void doUserAction(void)
{
	if (game.action == START)
	{
		pauseGame(false);
	}
	else
	{
		moveFrog(game.action);
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine draws the frame buffer from the set stage by calling memcpy
*/
void drawStageToFrameBuffer(void)
{
	memcpy(framebufferstruct.fptr, game.map.stage, 1280 * 720 * 2);
}

/*
@Params: *arg: NULL argument that is passed to the controller user input thread
@Returns: This subroutine does not return anything
This subroutine is the thread for user input on the SNES controller.  Checks whether the player has pressed a button
on the SNES controller and then makes the appropriate changes to game state.
*/
void *getUserInput(void *arg)
{
	while (true)
	{
		int buttonPress = sampleController();
		if (buttonPress == LEFT ||
			buttonPress == RIGHT ||
			buttonPress == DOWN ||
			buttonPress == UP ||
			buttonPress == START ||
			buttonPress == SELECT)
		{
			game.action = buttonPress;
			// If start pressed, sleep for half a second to not immediately unpause
			if (buttonPress == START)
			{
				usleep(250 * 1000);
			}
		}
	}
	return NULL;
}

/*
@Returns: This subroutine does not return anything
This subroutine resets the frog back to the start position and resets the scroll offset of the screen.  Called at the beginning of
the game and if the frog died.
*/
void resetFrogPosition(void)
{
	game.scrollOffset = 30;
	game.action = -1;
	game.frogLocation = FROG_START;
}

/*
@Params: *img: short image pointer to be drawn/set to the stage
@Params: yOffset: integer that is used for offsetting what row the image is being drawn to
@Params: xOffset: integer that is used for offsetting what column the image is being drawn to
@Returns: This subroutine does not return anything
This subroutine takes in an image pointer and coordinates of a tile and sets/draws the image to the game stage.
*/
void drawTile(short *img, int yOffset, int xOffset)
{
	int i = 0;
	for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
	{
		for (int x = xOffset; x < xOffset + TILE_WIDTH; x++)
		{
			int loc = ((y * GAME_WIDTH) + x) - (((VERTICAL_OFFSET * TILE_HEIGHT) * GAME_WIDTH) + NUM_HORIZONTAL_TILES * TILE_WIDTH);
			if (loc > 0)
			{
				game.map.stage[loc] = img[i];
			}
			i++;
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine draws the frog to the stage by calling drawTile with the frog short image pointer and it's current location as its parameter.
*/
void drawFrog(void)
{
	drawTile(frogPtr, game.frogLocation.row, game.frogLocation.col);
}

/*
@Returns: This subroutine does not return anything
This subroutine updates the location of the frog on the game map.  If frog moves to a log or a rock, the frog moves with the log or the rock moving.
*/
void updateFrogLocation(void)
{
	// Could improve efficiency by skipping to logs
	// instead of iterating over all obstacles but this is easier for development
	for (int obstNum = 0; obstNum < NUM_OBSTACLES; obstNum++)
	{
		Obstacle obst = game.obstacles[obstNum];
		// If we are on the same lane as a log or rock and the platform is safe, move us with the platform
		if ((obst.type == wood || obst.type == rock) && obst.lane == game.frogLocation.row)
		{
			game.frogLocation.col = ((game.frogLocation.col + obst.velocity) + GAME_WIDTH) % GAME_WIDTH;
			break;
		}
	}
	drawFrog();
}

/*
@Returns: PowerUp: struct defined in frogger.h where each powerUp has coordinates and a powerUp type.  
This subroutine generates a random powerup on a random tile on the game screen and returns that powerup.
*/
PowerUp generateRandomPowerUp(void)
{
	enum powerUpTypes type = getRandomBetweenRange(0, 4);

	Coordinate coord;
	coord.col = rand() % NUM_HORIZONTAL_TILES;

	// Always render powerup on screen
	coord.row = min(max(ROW_OF_CASTLE + 1, (rand() % NUM_HORIZONTAL_TILES) + game.scrollOffset + VERTICAL_OFFSET), NUM_VERTICAL_TILES - 1);

	return (PowerUp){
		.powerUpLocation = coord,
		.type = type};
}

/*
@Returns: This subroutine does not return anything
This subroutine displays a powerUp on the game screen by taking the currentPowerUp coordinates and its type, setting an image pointer to the
appropriate powerUp type, and then calling updateStage to add the powerUp to the stage.
*/
void displayPowerUp(void)
{
	int row = game.currentPowerUp.powerUpLocation.row;
	int col = game.currentPowerUp.powerUpLocation.col;

	short *img;
	switch (game.currentPowerUp.type)
	{
	case lifeUp:
		img = moreLivesPtr;	// Add a life - Heart Image
		break;
	case timeUp:
		img = moreTimePtr;	// Increase time - Clock Image
		break;
	case movesUp:
		img = moreStepsPtr;	// Increase the number of moves remaining - Shoe Image
		break;
	case slowDown:
		img = slowDownPtr;	// Slow all moving obstacles - Lightning Bolt Image
		break;
	default:
		break;
	}
	updateStage(row, col, img, powerUp);
}

/*
@Returns: This subroutine does not return anything
This subroutine slows the obstacles of the game.  This is called when the frog has hit the Lightning Bolt image powerUp.
*/
void slowAllObstacles(void)
{
	for (int obstNum = 0; obstNum < NUM_OBSTACLES; obstNum++)
	{
		if (game.obstacles[obstNum].velocity < -3 || game.obstacles[obstNum].velocity > 3)
		{
			game.obstacles[obstNum].velocity = game.obstacles[obstNum].velocity > 0
												   ? game.obstacles[obstNum].velocity - 2
												   : game.obstacles[obstNum].velocity + 2;
		}
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine is called to apply powerUps if the frog collides with a powerUp.  
*/
void applyPowerUp(void)
{
	switch (game.currentPowerUp.type)
	{
	case lifeUp:
		game.lives++; // Add another life
		break;
	case timeUp:
		game.timeRemaining += 60.0; // Add another minute of game time
		break;
	case movesUp:
		game.moves += 50; // Add 50 moves
		break;
	case slowDown:
		slowAllObstacles(); // Slow all obstacles velocity
		break;
	default:
		break;
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine checks for powerUps depending on the last time a powerUp has been generated.  If it is time to generate a new powerUp then the 
appropriate actions are made, and then the powerUp is then displayed by calling displayPowerUp().
*/
void checkPowerUps(void)
{
	// generate powerups every 30 seconds starting on the first 30 minutes
	if ((game.lastPowerUpTime + POWERUP_TIME_INTERVAL) - game.elapsedTime < 0)
	{
		game.lastPowerUpTime = game.elapsedTime;
		PowerUp newPowerup = generateRandomPowerUp();
		game.currentPowerUp.powerUpLocation = newPowerup.powerUpLocation;
		game.currentPowerUp.type = newPowerup.type;
	}

	if (game.currentPowerUp.type != none)
	{
		displayPowerUp();
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine checks if the game has ended or not.  If the frog has reached the castle then the game has ended and the player has won the game.
If the frog has run out of lives or moves or time left, the player has lost the game.
*/
void checkEndCondition(void)
{
	if (game.frogLocation.row == ROW_OF_CASTLE)
	{
		game.win = true;
	}
	else if (game.lives <= 0 || game.moves <= 0 || game.timeRemaining <= 0)
	{
		game.lose = true;
	}
}

/*
@Params: yOffset: integer that is used for offsetting what row the image is being drawn to
@Params: xOffset: integer that is used for offsetting what column the image is being drawn to
@Params: *stat_ptr: short int image pointer for the status bar that is to be drawn/set to the stage
@Returns: This subroutine does not return anything
This subroutine draws a tile on the status bar depending on the image pointer and the coordinates of a tile.  
*/
void drawGameInfo(int yOffset, int xOffset, short int *stat_ptr)
{
	int i = 0;

	for (int y = TILE_HEIGHT * yOffset; y < TILE_HEIGHT * (yOffset + 1); y++)
	{
		for (int x = TILE_WIDTH * xOffset; x < TILE_WIDTH * (xOffset + 1); x++)
		{
			game.map.stage[((y * GAME_WIDTH) + x)] = stat_ptr[i];
			i++;
		}
	}
}

/*
@Params: passedDigit: char that corresponds to a digit from the numbers that need to be displayed on the status bar
@Params: **digits: short int pointer that is passed in so that it can set another pointer from another function
@Returns: This subroutine does not return anything
This subroutine takes in the character that corresponds to a digit and the pointer from a different function and then sets
that pointer from a different function to the short int image pointer that correspond to the passedDigit character.  (e.g., char passedDigit = '1'
then set pointer from a different function to the '1' short int image pointer to display correct digit to game screen)
*/
void digitPtr(char passedDigit, short int **digits)
{
	switch (passedDigit)
	{
	case '0':
		*digits = zeroPtr;
		break;
	case '1':
		*digits = onePtr;
		break;
	case '2':
		*digits = twoPtr;
		break;
	case '3':
		*digits = threePtr;
		break;
	case '4':
		*digits = fourPtr;
		break;
	case '5':
		*digits = fivePtr;
		break;
	case '6':
		*digits = sixPtr;
		break;
	case '7':
		*digits = sevenPtr;
		break;
	case '8':
		*digits = eightPtr;
		break;
	case '9':
		*digits = ninePtr;
		break;
	default:
		*digits = zeroPtr;
		break;
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine updates the game info for the status bar at the bottom of the screen and then calls drawGameInfo() for each tile of the status 
bar to set the stage of the screen.  First, to display the correct digits for the score, time, moves left, and lives left, the timeRemaining 
double of the game is converted to a string and 0 prepended depending on how much time is left, the moves int of the game is coverted to a string
and 0 prepended depending on how many moves are left, the lives int converted to a string, and the score int converted to a string and 0 prepended
depending on what the score is.  Next, the tiles of the status bar are iterated over to set the short int pointer *ptr to the respective
short int image pointers for the status bar for calling drawGameInfo for the appropriate tile.
*/
void updateGameInfo(void)
{
	// game.timeRemaining double converted for string for displaying time
	char timeStr[TIME_STAT_BAR_TO_CHARS];
	sprintf(timeStr, "%f", game.timeRemaining);

	if (game.timeRemaining < 100) // If time remaining on timer less than 100 then prepend 0 to string
	{
		memmove(timeStr + 1, timeStr, TIME_MOVE_PREPEND_ZERO);
		timeStr[0] = '0';
		if (game.timeRemaining < 10) // If time remaining on timer less then 10 then prepend a second 0 to string
		{
			memmove(timeStr + 1, timeStr, TIME_MOVE_PREPEND_ZERO);
			timeStr[0] = '0';
		}
	}

	// game.moves int converted to string for displaying number of moves left
	char movesStr[MOVES_STAT_BAR_TO_CHARS];
	sprintf(movesStr, "%d", game.moves);

	if (game.moves < 100) // If player moves left less than 100 then prepend 0 to string
	{
		memmove(movesStr + 1, movesStr, TIME_MOVE_PREPEND_ZERO);
		movesStr[0] = '0';
		if (game.moves < 10) // if player moves left less than 10 then prepend a second 0 to string
		{
			memmove(movesStr + 1, movesStr, TIME_MOVE_PREPEND_ZERO);
			movesStr[0] = '0';
		}
	}

	// game.lives int converted to string for displaying number of lives left
	char livesStr[LIVES_STAT_BAR_TO_CHARS];
	sprintf(livesStr, "%d", game.lives);

	// game.score int converted to string for displaying score
	sprintf(game.scoreStr, "%d", game.score);

	if (game.score < 1000)	// If player score is less than 1000 then prepend a 0 to string
	{
		memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
		game.scoreStr[0] = '0';
		if (game.score < 100)	// If player score is less than 100 then prepend a second 0 to string
		{
			memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
			game.scoreStr[0] = '0';
			if (game.score < 10)	// If player score is less than 10 then prepend a third 0 to string
			{
				memmove(game.scoreStr + 1, game.scoreStr, SCORE_PREPEND_ZERO);
				game.scoreStr[0] = '0';
			}
		}
	}

	short int *ptr;
	for (int row = (NUM_HORIZONTAL_TILES - 3); row < NUM_HORIZONTAL_TILES; row++)
	{
		for (int col = 0; col < NUM_HORIZONTAL_TILES; col++)
		{
			if (row == TOP_ROW_STAT_BAR)
			{
				switch (col)
				{
				// score
				case 2:
					ptr = scorePtr; // score label
					break;
				case 3:
					digitPtr(game.scoreStr[0], &ptr); // score thousandths digit
					break;
				case 4:
					digitPtr(game.scoreStr[1], &ptr); // score hundredths digit
					break;
				case 5:
					digitPtr(game.scoreStr[2], &ptr); // score tens digit
					break;
				case 6:
					digitPtr(game.scoreStr[3], &ptr); // score ones digit
					break;

				// time
				case 9:
					ptr = timePtr; // time label
					break;
				case 10:
					digitPtr(timeStr[0], &ptr); // time hundreds digits
					break;
				case 11:
					digitPtr(timeStr[1], &ptr); // time tens digit
					break;
				case 12:
					digitPtr(timeStr[2], &ptr); // time ones digit
					break;

				// lives left
				case 15:
					ptr = livesPtr; // 'lives' label
					break;
				case 16:
					ptr = leftPtr; // 'left' label
					break;
				case 17:
					digitPtr(livesStr[0], &ptr); // number of lifes left digit
					break;

				default:
					ptr = blackRoadPtr;
					break;
				}
			}

			else if (row == BOTTOM_ROW_STAT_BAR)
			{
				switch (col)
				{
				// moves left
				case 4:
					ptr = movesPtr; // 'moves' label
					break;
				case 5:
					ptr = leftPtr; // 'left' label
					break;
				case 6:
					digitPtr(movesStr[0], &ptr); // moves left hundredths digit
					break;
				case 7:
					digitPtr(movesStr[1], &ptr); // moves left tens digit
					break;
				case 8:
					digitPtr(movesStr[2], &ptr); // moves left ones digit
					break;

				// value-pack
				case 13:
					ptr = valuePtr;	// 'value' label
					break;
				case 14:
					ptr = packPtr;	// 'pack' label
					break;
				case 15:
					switch (game.currentPowerUp.type)
					{
					// case none:
					case -1:
						ptr = naPtr;	// N/A ptr image
						break;
					// case lifeUp:
					case 0:
						ptr = moreLivesPtr; // Heart image powerUp
						break;
					// case timeUp:
					case 1:
						ptr = moreTimePtr;	// Clock image powerUp
						break;
					// case movesUp:
					case 2:
						ptr = moreStepsPtr;	// Shoe image powerUp
						break;
					// case slowDown:
					case 3:
						ptr = slowDownPtr;	// Lightning Bolt image powerUp
						break;
					default:
						ptr = naPtr;
					}
					break;

				default:
					ptr = blackRoadPtr;
					break;
				}
			}
			else
				ptr = blackRoadPtr;

			drawGameInfo(row, col, ptr);
		}
	}
}

/*
@Params:
@Params:
@Params:
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
Obstacle obstacleFactory(enum ObstacleType type, int lane, int colPos, int velocity)
{
	int numImgs;
	short **imgs;
	enum CollisionType collisionType;
	// Remember to free mem
	switch (type)
	{
	case car:
		numImgs = 2;
		imgs = malloc(numImgs * sizeof(short *));
		imgs[0] = carBackPtr;
		imgs[1] = carFrontPtr;
		collisionType = death;
		break;
	case bus:
		numImgs = 4;
		imgs = malloc(numImgs * sizeof(short *));
		imgs[0] = busFrontPtr;
		imgs[1] = busMidPtr;
		imgs[2] = busMidPtr;
		imgs[3] = busBackPtr;
		collisionType = death;
		break;
	case wood:
		numImgs = getRandomBetweenRange(2, 4); // Log is random number between 2 and 4 tiles long
		imgs = malloc(numImgs * sizeof(short *));
		for (int i = 0; i < numImgs; i++)
		{
			imgs[i] = logPtr;
		}
		collisionType = safe;
		break;
	case rock:
		numImgs = getRandomBetweenRange(2, 4); //  Random number of rocks between 2 and 4 tiles
		imgs = malloc(numImgs * sizeof(short *));
		for (int i = 0; i < numImgs; i++)
		{
			imgs[i] = boulderPtr;
		}
		collisionType = safe;
		break;
	case snake:
		numImgs = getRandomBetweenRange(3, 5); // Snake is random number between 3 and 5 tiles long
		imgs = malloc(numImgs * sizeof(short *));
		imgs[0] = snakeLeftPtr;
		for (int i = 1; i < numImgs - 1; i++)
		{
			imgs[i] = snakeMidPtr;
		}
		imgs[numImgs - 1] = snakeRightPtr;
		collisionType = death;
		break;
	}
	return (Obstacle){
		.type = type,
		.lane = lane,
		.colPos = colPos,
		.imgs = imgs,
		.numImgs = numImgs,
		.velocity = velocity,
		.collisionType = collisionType};
}

/*
@Params:
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
int getRandomBetweenRange(int low, int high)
{
	return (rand() % (high)) + low;
}

/*
@Params:
@Params:
@Params:
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
void initializeLane(enum ObstacleType type, int numObstacles, int lane, int velocity)
{
	int startPos = 0;
	int i = game.obstaclesInitialized;
	for (; i < game.obstaclesInitialized + numObstacles; i++)
	{
		Obstacle obst = obstacleFactory(type, lane, 0, velocity);
		if (obst.type == snake)
		{
			startPos = TILE_WIDTH * 1;
		}
		else
		{
			startPos += (TILE_WIDTH * obst.numImgs * getRandomBetweenRange(1, 3)) % GAME_WIDTH;
		}
		obst.colPos = startPos;
		game.obstacles[i] = obst;
	}
	game.obstaclesInitialized = i;
}

/*
@Params:
@Params:
@Params:
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
void initializeObstacles(void)
{
	// 20 Cars and Busses
	initializeLane(car, 3, 48, 4);
	initializeLane(bus, 2, 47, -4);
	initializeLane(car, 3, 46, 5);
	initializeLane(car, 3, 45, 6);
	initializeLane(bus, 2, 43, -4);
	initializeLane(car, 3, 42, 4);
	initializeLane(bus, 2, 41, -4);
	initializeLane(bus, 2, 40, -6);

	// 25 logs
	initializeLane(wood, 3, 38, 6);
	initializeLane(wood, 3, 37, 8);
	initializeLane(wood, 3, 36, -6);
	initializeLane(wood, 2, 35, 5);
	initializeLane(wood, 3, 34, -7);
	initializeLane(wood, 3, 33, 4);
	initializeLane(wood, 2, 32, -5);
	initializeLane(wood, 3, 31, -8);
	initializeLane(wood, 3, 30, 5);

	// 6 snakes
	initializeLane(snake, 1, 28, 10);
	initializeLane(snake, 1, 26, 8);
	initializeLane(snake, 1, 25, 6);
	initializeLane(snake, 1, 23, 8);
	initializeLane(snake, 1, 21, 9);
	initializeLane(snake, 1, 20, 11);

	// 26 rocks
	initializeLane(rock, 3, 18, -4);
	initializeLane(rock, 3, 17, 5);
	initializeLane(rock, 3, 16, 7);
	initializeLane(rock, 2, 15, -5);
	initializeLane(rock, 3, 14, -7);
	initializeLane(rock, 3, 13, 4);
	initializeLane(rock, 3, 12, -5);
	initializeLane(rock, 3, 11, -7);
	initializeLane(rock, 3, 10, 5);
}

/*
@Params:
@Returns: This subroutine does not return anything
This subroutine checks whether or not a lane with obstacles is in the screen or not
i.e., is an obstacle that is on the game board also on the currently displayed screen
*/
bool obstacleInView(int lane)
{
	if (lane > game.scrollOffset && lane < NUM_HORIZONTAL_TILES + game.scrollOffset)
	{
		return true;
	}
	return false;
}

/*
@Returns: This subroutine does not return anything
This subroutine ...
*/
void drawObstacles(void)
{
	for (int obstNum = 0; obstNum < NUM_OBSTACLES; obstNum++)
	{
		Obstacle obst = game.obstacles[obstNum];
		// check if obstacle is a snake
		if (obst.type == snake && ((obst.colPos + game.obstacles[obstNum].velocity + (TILE_WIDTH * obst.numImgs) > GAME_WIDTH) || obst.colPos + game.obstacles[obstNum].velocity < 0))
		{
			// Reverse direction of snake when it reaches end of screen
			game.obstacles[obstNum].velocity *= -1;
		}
		obst.colPos = (obst.colPos + game.obstacles[obstNum].velocity + GAME_WIDTH) % GAME_WIDTH;

		if (obstacleInView(obst.lane))
		{
			// Only render if obstacle is in view
			for (int imgNo = 0; imgNo < obst.numImgs; imgNo++)
			{
				int i = 0;
				for (int y = TILE_HEIGHT * (obst.lane - game.scrollOffset); y < TILE_HEIGHT * (obst.lane - game.scrollOffset + 1); y++)
				{
					int imgOffset = imgNo * TILE_WIDTH;
					for (int x = obst.colPos + imgOffset; x < (obst.colPos + TILE_WIDTH) + imgOffset; x++)
					{
						int loc = ((y * GAME_WIDTH) + x) - (((VERTICAL_OFFSET * TILE_HEIGHT) * GAME_WIDTH) + NUM_HORIZONTAL_TILES * TILE_WIDTH);
						if (loc > 0)
						{
							game.collisionBuffer[loc] = obst.collisionType;
							game.map.stage[loc] = obst.imgs[imgNo][i];
						}
						i++;
					}
				}
			}
		}
		game.obstacles[obstNum].colPos = obst.colPos;
	}
}

/*
@Returns: This subroutine does not return anything
This subroutine ...
*/
void initializeGame(void)
{
	resetFrogPosition();
	initializeObstacles();
	game.elapsedTime = 0.0;
	game.lastPowerUpTime = 0.0;
	game.currentPowerUp.type = none;
	game.secondsPerFrame = 0;
	game.timeRemaining = 60.0 * 5.0; // Player starts with 5 minutes
	game.lives = 4;
	game.moves = 250;
	game.map = INITIAL_MAP;
	game.obstaclesInitialized = 0;
	game.score = 0;
	game.movesMade = 0;
	game.win = false;
	game.lose = false;
	game.paused = false;
	game.quit = false;
}

/*
@Returns: This subroutine does not return anything
This subroutine ...
*/
void clearCollisionBuffer(void)
{
	memset(game.collisionBuffer, 0, (GAME_WIDTH * GAME_HEIGHT) * sizeof(short));
}

/*
@Returns: This subroutine does not return anything
This subroutine ...
*/
void clearObstacleMemory(void)
{
	for (int obstacleNum = 0; obstacleNum < NUM_OBSTACLES; obstacleNum++)
	{
		free(game.obstacles[obstacleNum].imgs);
	}
}

/*
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
void *gameTimer(void *arg)
{
	while (true)
	{
		while (!game.paused)
		{
			usleep(1000 * 1000);
			game.elapsedTime += 1;
			game.timeRemaining -= 1;
		}
	}
	return NULL;
}

/*
@Params:
@Params:
@Returns: This subroutine does not return anything
This subroutine ...
*/
/* main function */
int main(int argc, char *argv[])
{
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	srand(time(NULL));

	initController();

	pthread_t controllerThread;
	pthread_t timerThread;
	pthread_create(&controllerThread, NULL, getUserInput, NULL);
	pthread_create(&timerThread, NULL, gameTimer, NULL);
	while (!game.exitGame)
	{
		initializeGame();
		pauseGame(true);
		while (!game.lose && !game.win && !game.quit && !game.exitGame)
		{
			if (game.action != -1)
			{
				doUserAction();
				game.action = -1;
			}
			clearCollisionBuffer();
			drawBackground();
			updateGameInfo();
			drawObstacles();
			updateFrogLocation();
			checkPowerUps();
			checkCollision();
			drawStageToFrameBuffer();
			checkEndCondition();
		}

		if (game.win)
		{
			endGame(winPromptPtr);
		}
		else if (game.lose)
		{
			endGame(losePromptPtr);
		}
		clearObstacleMemory();
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	system("clear");

	return 0;
}
