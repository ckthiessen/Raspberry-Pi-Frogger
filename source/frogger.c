// Authors: Cole Thiessen (30027689) & Isaac Lutzko (30026703)
// CPSC359 Winter 2021 Project (Part 2) Raspberry Pi Video Game
// Februar 2021
// Description:

// Link/Reference for Frogger Image: https://www.funstockretro.co.uk/news/arcade-hall-of-fame-frogger-konami/
//
// Link/Reference for Crazy Frog Image: https://www.thesun.co.uk/living/2974489/crazy-frog-just-turned-20-relive-his-hellish-magic-here/
//
// Link/Reference for Pepe Frog Image: https://line.17qq.com/articles/doddbhdz.html
//
// link/references for figuring how to display stat bar
//
//
// used for game.moves:


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

// #include "images/menus/main_menu_start.h"
// #include "images/menus/main_menu_quit.h"
#include "images/menus/main_menu_quit_game.h"
#include "images/menus/main_menu_start_game.h"

#include "images/menus/pause_menu_quit.h"
#include "images/menus/pause_menu_restart.h"
#include "images/menus/you_lose_prompt.h"
#include "images/menus/you_win_prompt.h"


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

struct fbs framebufferstruct;

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


void updateStage(int yOffset, int xOffset, short int *img_ptr)
{
	int i = 0;

	for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
	{
		for (int x = TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET); x < TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET + 1); x++)
		{
			int loc = ((y * GAME_WIDTH) + x) - (((VERTICAL_OFFSET * TILE_HEIGHT) * GAME_WIDTH) + NUM_RENDERED_TILES * TILE_WIDTH);
			if(loc > 0)
				game.map.stage[loc] = img_ptr[i];
			i++;
		}
	}
}

void mapBoardToStage(bool debug)
{
	for (int row = game.scrollOffset; row < NUM_RENDERED_TILES + game.scrollOffset; row++)
	{
		for (int col = HORIZONTAL_OFFSET; col < NUM_RENDERED_TILES + HORIZONTAL_OFFSET; col++)
		{
			char tile = game.map.board[row][col];
			short int *ptr;
			if (debug)
				printf("%c", tile);
			switch (tile)
			{
			// road
			case '-':
				ptr = blackRoadPtr;
				break;
			// front of bus/semi
			case 'b':
				ptr = busFrontPtr;
				break;
			// middle of bus/semi
			case 'm':
				ptr = busMidPtr;
				break;
			// back of bus/semi
			case 'e':
				ptr = busBackPtr;
				break;
			// front of car
			case 'c':
				ptr = carFrontPtr;
				break;
			// back of car
			case 'a':
				ptr = carBackPtr;
				break;
			// log
			case 'l':
				ptr = logPtr;
				break;
			// rock for lava
			case 'r':
				ptr = boulderPtr;
				break;
			// hole/pit for snakes and pits
			case 'h':
				ptr = pitPtr;
				break;
			// left head of snake
			case 's':
				ptr = snakeLeftPtr;
				break;
			// right head of snake
			case 't':
				ptr = snakeRightPtr;
				break;
			// desert background for snakes and pits
			case 'd':
				ptr = desertPtr;
				break;
			// lava
			case ';':
				ptr = lavaPtr;
				break;
			// water
			case ',':
				ptr = waterPtr;
				break;
			// safe zone
			case '.':
				ptr = safePtr;
				break;
			// castle wall
			case 'w':
				ptr = castleWallPtr;
				break;
			// castle door
			case 'o':
				ptr = castleDoorPtr;
				break;
			// castle top
			case 'p':
				ptr = castleTopPtr;
				break;
			// castle sky
			case '~':
				ptr = castleSkyPtr;
				break;
			default:
				ptr = blackRoadPtr;
				break;
			}
			updateStage(row, col, ptr);
		}
		if (debug)
			printf("\n");
	}
}

void checkCollision(void)
{
	char obstacle = game.map.board[game.frogLocation.row][game.frogLocation.col];
	if (
		obstacle == 'c' ||
		obstacle == ',' ||
		obstacle == 'h' ||
		obstacle == 's' ||
		obstacle == 'b')
	{
		resetFrogPosition();
		game.lives--;
	}
}

void update(void)
{
	char boardBuffer[NUM_MAP_TILES][NUM_MAP_TILES];
	memcpy(boardBuffer, game.map.board, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	for (int row = 0; row < NUM_MAP_TILES; row++)
	{
		for (int col = 0; col < NUM_MAP_TILES; col++)
		{
			char prev = '\0';
			char obstacle = game.map.board[row][col];
			char background = '\0';
			char newPos;
			switch (obstacle)
			{
			case 'c':
			case 'a':
			case 'm':
			case 'e':
			case 'b':
				background = '-';
				break;
			case 's':
				background = 'd';
				newPos = boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES];
				if (newPos == 'h')
				{ // Reverse snake direction when they hit a hole or rock
					laneVelocities[row] = -laneVelocities[row];
				}
				break;
			case 'l':
				background = ',';
				break;
			case 'r':
				background = ';';
				break;
			default:
				break;
			}
			if (background != '\0')
			{
				boardBuffer[row][col] = background;
				boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES] = obstacle;
			}
		}
	}
	memcpy(game.map.board, boardBuffer, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	// checkCollision();
}

void displayMenu(short * menu, int heightOffset, int widthOffset) {
	int i = 0;
	for (int y = heightOffset; y < GAME_HEIGHT - heightOffset; y++)
	{
		for (int x = widthOffset; x < GAME_WIDTH - widthOffset; x++)
		{
			game.map.stage[((y * GAME_WIDTH) + x) % (GAME_HEIGHT * GAME_WIDTH)] = menu[i];
			i++;
		}
	}
	drawStageToFrameBuffer();
}


void pauseGame(bool isMainMenu)
{
	enum options currentOption;
	short * menu;
	if (isMainMenu) {
		menu = mainMenuStartPtr;
		currentOption = resume;
		displayMenu(menu, 0, 0);
	} else {
		currentOption = restart;
		menu = pauseMenuRestartPtr;
		displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
	}
	game.action = NO_ACTION;
	bool paused = true;
	while (paused)
	{
		if (game.action == LEFT || game.action == RIGHT) {
			if (isMainMenu) {
				game.action = -1;
				menu = menu == mainMenuStartPtr ? mainMenuQuitPtr : mainMenuStartPtr;
				currentOption = menu == mainMenuStartPtr ? resume : quit;
				displayMenu(menu, 0, 0);
			} else {
				game.action = -1;
				menu = menu == pauseMenuQuitPtr ? pauseMenuRestartPtr : pauseMenuQuitPtr;
				currentOption = menu == pauseMenuQuitPtr ?  quit : restart;
				displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
			}
			usleep(500 * 1000);
		}
		if (game.action == SELECT) {
			switch (currentOption) {
				case resume:
					break;
				case quit:
					game.quit = true;
					break;
				case restart:
					initializeGame();
					break;
			}
			paused = false;
		}
		if (game.action == START && !isMainMenu)
		{
			paused = false;
			usleep(500 * 1000);
		}
	}
}

void endGame(short * menu) {
	game.action = NO_ACTION;
	bool paused = true;
	displayMenu(menu, TILE_HEIGHT * 5, TILE_WIDTH * 5);
	while (paused)
	{
		if (game.action == START)
		{
			paused = false;
			usleep(500 * 1000);
		}
	}
}

void moveFrog(int direction)
{
	bool moved = false;
	switch (game.action)
	{
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
	case DOWN:
		if (game.frogLocation.row < NUM_MAP_TILES - 1)
		{
			game.frogLocation.row++;
			moved = true;
			if (game.frogLocation.row < 40 && game.frogLocation.row >= 10)
			{
				
				game.scrollOffset++;
			}
		}
		break;
	case LEFT:
		if (game.frogLocation.col > HORIZONTAL_OFFSET)
		{
			moved = true;
			game.frogLocation.col--;
		}
		break;
	case RIGHT:
		if (game.frogLocation.col < NUM_RENDERED_TILES + HORIZONTAL_OFFSET - 1)
		{
			moved = true;
			game.frogLocation.col++;
		}
		break;
	}
	if (moved) { 
		game.moves--; 
		game.movesMade++;
		if (game.movesMade <= 50) {
			game.score += 3;
		}
		else if (game.movesMade <= 100) {
			game.score += 2;
		}
		else if (game.movesMade <= 150) {
			game.score += 2;
		}
	}
}

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

/* Draw a frame */
void drawStageToFrameBuffer(void)
{
	memcpy(framebufferstruct.fptr, game.map.stage, 1280 * 720 * 2);
}

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
		}
	}
	return NULL;
}

void resetFrogPosition(void)
{
	game.scrollOffset = 30;
	game.action = -1;
	game.frogLocation = FROG_START;
}

void initializeGame(void)
{
	resetFrogPosition();
	game.elapsedTime = 0.0;
	game.lastPowerUpTime = 0.0;
	game.currentPowerUp.type = none;
	game.secondsPerFrame = 1.0 / 5.0;
	game.timeRemaining = 60.0 * 5.0;	// Player starts with 5 minutes
	game.lives = 3;
	game.moves = 250;
	game.map = INITIAL_MAP;
	//-----------------------
	game.score = 0;
	game.movesMade = 0;
}

void updateFrogLocation(void)
{
	char obstacle = game.map.board[game.frogLocation.row][game.frogLocation.col];
	if (obstacle == 'l' || obstacle == 'r')
	{
		game.frogLocation.col += laneVelocities[game.frogLocation.row];
	}
	updateStage(game.frogLocation.row, game.frogLocation.col, frogPtr);
}

PowerUp generateRandomPowerUp(void)
{
	srand(time(NULL));
	enum powerUpTypes type = rand() % 4;

	Coordinate coord;
	coord.col = (rand() % NUM_RENDERED_TILES) + HORIZONTAL_OFFSET;
	coord.row = (rand() % NUM_RENDERED_TILES) + game.scrollOffset;

	return (PowerUp){
		.powerUpLocation = coord,
		.type = type};
}

void displayPowerUp(void)
{
	int row = game.currentPowerUp.powerUpLocation.row;
	int col = game.currentPowerUp.powerUpLocation.col;
	// updateStage(row, col, frogPtr);

	switch (game.currentPowerUp.type)
	{
		case lifeUp:
			updateStage(row, col, moreLivesPtr);
			break;
		case timeUp:
			updateStage(row, col, moreTimePtr);
			break;
		case movesUp:
			updateStage(row, col, moreStepsPtr);
			break;
		case slowDown:
			updateStage(row, col, slowDownPtr);
			break;
		default:
			updateStage(row, col, moreLivesPtr);
			break;
	}
}

int ones;
int tens;
void applyPowerUp(void)
{
	switch (game.currentPowerUp.type)
	{
	case lifeUp:
		printf("Hit Powerup: %d\n", game.currentPowerUp.type);
		game.lives++;	// Add another life
		break;
	case timeUp:
		game.timeRemaining += 60.0; // Add another minute of game time
		printf("Hit Powerup: %d\n", game.currentPowerUp.type);
		break;
	case movesUp:
		game.moves += 50; // Add 50 moves
		printf("Hit Powerup: %d\n", game.currentPowerUp.type);
		break;
	case slowDown:
		game.secondsPerFrame *= 1.20; // Slow down time 20%
		printf("Hit Powerup: %d\n", game.currentPowerUp.type);
		break;
	default:
		break;
	}
}

void checkPowerUps(void)
{
	if ((game.lastPowerUpTime + 30.0) - game.elapsedTime < 0)
	{
		game.lastPowerUpTime = game.elapsedTime;
		PowerUp newPowerup = generateRandomPowerUp();
		game.currentPowerUp.powerUpLocation = newPowerup.powerUpLocation;
		game.currentPowerUp.type = newPowerup.type;
	}
	if (game.frogLocation.col == game.currentPowerUp.powerUpLocation.col &&
		game.frogLocation.row == game.currentPowerUp.powerUpLocation.row)
	{
		applyPowerUp();
		game.score += 50;
		game.currentPowerUp.type = none;
	}
	if (game.currentPowerUp.type != none)
	{
		displayPowerUp();
	}
}

void checkEndCondition(void) {
	if (game.frogLocation.row == ROW_OF_CASTLE) {
		game.win = true;
		game.quit = true;
	}
	else if (game.lives <= 0 || game.moves <= 0 || game.timeRemaining <= 0) {
		game.lose = true;
		game.quit = true;
	}
}

void drawGameInfo(int yOffset, int xOffset, short int *stat_ptr) {
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

void digitPtr(char passedDigit, short int **digits) {
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

void updateGameInfo(void) {
	// printf("test test\n");

	// game.timeRemaining double converted for string for displaying time
	char timeStr[50];
	sprintf(timeStr, "%f", game.timeRemaining);

	// game.moves int converted to string for displaying number of moves left
	char movesStr[5];
	sprintf(movesStr, "%d", game.moves);

	if(game.moves < 100) {
		memmove(movesStr+1, movesStr, 4);
		movesStr[0] = '0';
		if(game.moves < 10) {
			memmove(movesStr+1, movesStr, 4);
			movesStr[0] = '0';
		}
	}

	// game.lives int converted to string for displaying number of lives left
	char livesStr[3];
	sprintf(livesStr, "%d", game.lives);

	// game.score int converted to string for displaying score
	char scoreStr[4];
	sprintf(scoreStr, "%d", game.score);

	if(game.score < 1000) {
		memmove(scoreStr+1, scoreStr, 3);
		scoreStr[0] = '0';
		if(game.score < 100) {
			memmove(scoreStr+1, scoreStr, 3);
			scoreStr[0] = '0';
			if(game.score < 10) {
				memmove(scoreStr+1, scoreStr, 3);
				scoreStr[0] = '0';
			}
		}
	}


	short int *ptr;
	for (int row = (NUM_RENDERED_TILES - 3); row < NUM_RENDERED_TILES; row++)
	{
		for (int col = 0; col < NUM_RENDERED_TILES; col++)
		{
			// printf("col: %d\n", col);

			if(row == 17)
			{
				switch(col)
				{
					// score
					case 2:
						ptr = scorePtr;
						break;
					case 3:
						digitPtr(scoreStr[0], &ptr);
						// ptr = zeroPtr;
						break;
					case 4:
						// ptr = zeroPtr;
						digitPtr(scoreStr[1], &ptr);
						break;
					case 5:
						// ptr = zeroPtr;
						digitPtr(scoreStr[2], &ptr);
						break;
					case 6:
						// ptr = zeroPtr;
						digitPtr(scoreStr[3], &ptr);
						break;

					// time
					case 9:
						ptr = timePtr;
						break;
					// hundreds digits
					case 10:
						digitPtr(timeStr[0], &ptr);
						break;
					// tens digit
					case 11:
						digitPtr(timeStr[1], &ptr);
						break;
					// ones digit
					case 12:
						digitPtr(timeStr[2], &ptr);
						break;

					// lives left
					case 15:
						ptr = livesPtr;
						break;
					case 16:
						ptr = leftPtr;
						break;
					case 17:
						digitPtr(livesStr[0], &ptr);
						break;
	
					default:
						ptr = blackRoadPtr;
						break;
				}
			}

			else if(row == 19)
			{
				switch (col)
				{
					// moves left
					case 4:
						ptr = movesPtr;
						break;
					case 5:
						ptr = leftPtr;
						break;
					// hundreds
					case 6:
						digitPtr(movesStr[0], &ptr);
						break;
					// tens
					case 7:
						digitPtr(movesStr[1], &ptr);
						break;
					// ones
					case 8:
						digitPtr(movesStr[2], &ptr);
						break;

					// value-pack
					case 13:
						ptr = valuePtr;
						break;
					case 14:
						ptr = packPtr;
						break;
					case 15:
						switch (game.currentPowerUp.type)
						{
							// case none:
							case -1:
								ptr = naPtr;
								break;
							// case lifeUp:
							case 0:
								ptr = moreLivesPtr;
								break;
							// case timeUp:
							case 1:
								ptr = moreTimePtr;
								break;
							// case movesUp:
							case 2:
								ptr = moreStepsPtr;
								break;
							// case slowDown:
							case 3:
								ptr = slowDownPtr;
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
			else ptr = blackRoadPtr;

			// if (row == 17 && col == 12 && ((game.statBarCounter % 5) == 0)) {
			// 	// drawGameInfo(row, col, timeOnesPtr);
			// 	printf("ones: %d\n", ones);
			// }
			// else if (row == 17 && col == 11 && ((game.statBarCounter % 50) == 0)) {
			// 	// drawGameInfo(row, col, timeTensPtr);
			// 	printf("tens: %d\n", tens);
			// }
			// else {
			// 	// drawGameInfo(row, col, ptr);
			// }
			// // printf("what is counter: %d\n", game.statBarCounter);

			drawGameInfo(row, col, ptr);

		}
	}
}

void calculateScore(void) {
	game.score += ((400 - game.movesMade) * 5);
	game.score += ((500 + game.timeRemaining) * 5);
	game.score += (200 * game.lives);
}


/* main function */
int main(int argc, char *argv[])
{
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();

	pthread_t controllerThread;
	pthread_create(&controllerThread, NULL, getUserInput, NULL);
	initializeGame();
	pauseGame(true);
	while (!game.quit)
	{
		usleep(((game.secondsPerFrame) * 1000) * 1000); // 30 Frames per second
		game.elapsedTime += game.secondsPerFrame;
		game.timeRemaining -= game.secondsPerFrame;

		if (game.action != -1)
		{
			doUserAction();
			game.action = -1;
		}

		update();
		mapBoardToStage(false);
		updateGameInfo();
		updateFrogLocation();
		checkPowerUps();
		drawStageToFrameBuffer();
		checkEndCondition();
	}

	if(game.win) {
		endGame(winPromptPtr);
	}
	else if(game.lose) {
		endGame(losePromptPtr);
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	system("clear");

	return 0;
}