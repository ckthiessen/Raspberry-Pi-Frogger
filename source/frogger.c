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
#include "images/menus/main_menu_start.h"
#include "images/menus/main_menu_quit.h"
#include "images/menus/pause_menu_quit.h"
#include "images/menus/pause_menu_restart.h"
#include "images/menus/you_lose_prompt.h"
#include "images/menus/you_win_prompt.h"

struct fbs framebufferstruct;

short int *frogPtr = (short int *)frog_img.pixel_data;
short int *mainMenuStartPtr = (short int *)main_menu_start.pixel_data;
short int *mainMenuQuitPtr = (short int *)main_menu_quit.pixel_data;
short int *pauseMenuQuitPtr = (short int *)pause_menu_quit.pixel_data;
short int *pauseMenuRestartPtr = (short int *)pause_menu_restart.pixel_data;

void updateStage(int yOffset, int xOffset, int color)
{
	int i = 0;

	switch (color)
	{

	case 0x6660:
		for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
		{
			for (int x = TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET); x < TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET + 1); x++)
			{
				game.map.stage[(y * GAME_WIDTH) + x] = frogPtr[i];
				i++;
			}
		}
		break;

	default:
		for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
		{
			for (int x = TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET); x < TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET + 1); x++)
			{
				game.map.stage[(y * GAME_WIDTH) + x] = color;
			}
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
			int color;
			if (debug)
				printf("%c", tile);
			switch (tile)
			{
			case '-':
				color = 0x8410;
				break;
			case 'b':
				color = 0x001F;
				break;
			case 'c':
				color = 0xF800;
				break;
			case 'l':
				color = 0x8B00;
				break;
			case 'r':
				color = 0x9CF3;
				break;
			case 'h':
				color = 0x0000;
				break;
			case 's':
				color = 0x7FA9;
				break;
			case ';':
				color = 0xFA00;
				break;
			case ',':
				color = 0x34DE;
				break;
			case '.':
				color = 0x0420;
				break;
			default:
				color = 0xFFFF;
				break;
			}
			updateStage(row, col, color);
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
		printf("Lives remaining: %d\n", game.lives);
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
			char obstacle = game.map.board[row][col];
			char background = '\0';
			char newPos;
			switch (obstacle)
			{
			case 'c':
			case 'b':
				background = '-';
				break;
			case 's':
				background = '.';
				newPos = boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES];
				if (newPos == 'r' || newPos == 'h')
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
	if (moved) { game.moves--; }
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
}

void updateFrogLocation(void)
{
	char obstacle = game.map.board[game.frogLocation.row][game.frogLocation.col];
	if (obstacle == 'l' || obstacle == 'r')
	{
		game.frogLocation.col += laneVelocities[game.frogLocation.row];
	}
	updateStage(game.frogLocation.row, game.frogLocation.col, 0x6660);
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
	updateStage(row, col, 0xF81D);
}

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
		game.currentPowerUp.type = none;
	}
	if (game.currentPowerUp.type != none)
	{
		displayPowerUp();
	}
}

void checkEndCondition(void) {
	// if (game.frogLocation.row == ROW_OF_CASTLE) {
	// 	game.win = true;
	// }
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
		updateFrogLocation();
		checkPowerUps();
		drawStageToFrameBuffer();
		// checkEndCondition();
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	system("clear");

	return 0;
}