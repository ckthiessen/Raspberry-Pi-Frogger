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


// void generateStartingMap() {
// 	for(int row = 0; row < GAME_HEIGHT; row++) {
// 		for(int col = 0; col < GAME_WIDTH; col++) {
// 			map.stage[row][col] = 0xffff;
// 		}
// 	}

// 	// for(int row = GAME_HEIGHT/2; row < GAME_HEIGHT; row++) {
// 	// 	for(int col = 0; col < GAME_WIDTH; col++) {
// 	// 		map.stage[row][col] = 0x07e0;
// 	// 	}
// 	// }
// }

// void generateStartingMap()
// {
// 	for (int row = 0; row < NUM_TILES; row++)
// 	{
// 		for (int col = 0; col < NUM_TILES; col++)
// 		{
// 			map.board[row][col] = '-';
// 		}
// 	}
// 	map.board[15][19] = 'c';
// 	map.board[15][18] = 'c';
// 	map.board[18][9] = 'f';
// }

struct fbs framebufferstruct;

void updateStage(int yOffset, int xOffset, int color)
{
	for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset); y < TILE_HEIGHT * (yOffset - game.scrollOffset + 1); y++)
	{
		for (int x = TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET); x < TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET + 1); x++)
		{
			map.stage[(y * GAME_WIDTH) + x] = color;
		}
	}
}

// void render() {
// 	for(int row = 0; row < NUM_TILES; row++) {
// 		for(int col = 0; col < NUM_TILES; col++) {
// 			char tile = map.board[row][col];
// 			switch (tile)
// 			{
// 			case '-':
// 				drawTile(row+1, col+1, 0xFFFF);
// 				break;
// 			case 'c':
// 				drawTile(row+1, col+1, 0x6660);
// 			default:
// 				break;
// 			}
// 		}
// 	}
// }

void mapBoardToStage(bool debug)
{
	for (int row = game.scrollOffset; row < NUM_RENDERED_TILES + game.scrollOffset; row++)
	{
		for (int col = HORIZONTAL_OFFSET; col < NUM_RENDERED_TILES + HORIZONTAL_OFFSET; col++)
		{
			char tile = map.board[row][col];
			int color; 
			if(debug) printf("%c", tile);
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
			case 'g':
				color = 0x0420;
				break;
			default:
				color = 0xFFFF;
				break;
			}
			updateStage(row, col, color);
		}
	if (debug) printf("\n");
	}
}

unsigned long elapsed = 0;

void checkCollision() {
	if (
		map.board[game.frogLocation.row][game.frogLocation.col] == 'c' ||
		map.board[game.frogLocation.row][game.frogLocation.col] == 'b'
	) {
		resetFrogPosition();
		game.lives--;
		printf("Lives remaining: %d\n", game.lives);

	}
}

void update()
{
	char boardBuffer[NUM_MAP_TILES][NUM_MAP_TILES];
	memcpy(boardBuffer, map.board, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	for (int row = 0; row < NUM_MAP_TILES; row++)
	{
		for (int col = 0; col < NUM_MAP_TILES; col++)
		{
			if (map.board[row][col] == 'c' || map.board[row][col] == 'b')
			{
				char tile = map.board[row][col];
				boardBuffer[row][col] = '-';
				boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES] = tile;
			}
		}
	}
	memcpy(map.board, boardBuffer, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	checkCollision();
}

void pauseGame()
{ 
	game.action = NO_ACTION;
	bool paused = true;
	while(paused) {
		if(game.action == START) {
			paused = false;
			usleep(250*1000);
		}
	}

}

void moveFrog(int direction)
{
	map.board[game.frogLocation.row][game.frogLocation.col] = '-';
	switch (game.action)
	{
	case UP:
		map.board[game.frogLocation.row - 1][game.frogLocation.col] = 'f';
		game.frogLocation.row--;
		if(game.frogLocation.row < 40 && game.frogLocation.row >= 10) {
			game.scrollOffset--;
		}
		break;
	case DOWN:
		map.board[game.frogLocation.row + 1][game.frogLocation.col] = 'f';
		game.frogLocation.row++;
		if(game.frogLocation.row < 40 && game.frogLocation.row >= 10) {
			game.scrollOffset++;
		}
		break;
	case LEFT:
		map.board[game.frogLocation.row][game.frogLocation.col - 1] = 'f';
		game.frogLocation.col--;
		break;
	case RIGHT:
		map.board[game.frogLocation.row][game.frogLocation.col + 1] = 'f';
		game.frogLocation.col++;
		break;
	}
}

void doUserAction()
{
	if (game.action == START)
	{
		pauseGame();
	}
	else
	{
		moveFrog(game.action);
	}
}

void printBoard()
{
	printf("Top of board: %d\n", game.scrollOffset);
	for (int row = game.scrollOffset; row < NUM_RENDERED_TILES + game.scrollOffset; row++)
	{
		for (int col = 0; col < NUM_RENDERED_TILES; col++)
		{
			char tile = map.board[row][col];
			printf("%c", tile);
		}
		printf("\n");
	}
}

/* Draw a frame */
void drawStageToFrameBuffer()
{
	memcpy(framebufferstruct.fptr, map.stage, 1280 * 720 * 2);
}

void *getUserInput()
{
	while (true)
	{
		int buttonPress = sampleController();
		if (buttonPress == LEFT ||
			buttonPress == RIGHT ||
			buttonPress == DOWN ||
			buttonPress == UP ||
			buttonPress == START)
		{
			game.action = buttonPress;
		}
	}
}

void resetFrogPosition() {
	game.scrollOffset = 30;
	game.action = -1;
	game.frogLocation = FROG_START;
}

void initializeGame() {
	game.lives = 3;
}

/* main function */
int main()
{
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();

	pthread_t controllerThread;
	pthread_create(&controllerThread, NULL, getUserInput, NULL);
	initializeGame();
	resetFrogPosition();
	// generateStartingMap();
	game.elapsedTime = 0.0;
	while (true)
	{
		usleep((((float)SECONDS_PER_FRAME) * 1000) * 1000); // 30 Frames per second
		// usleep(500 * 1000); // 30 Frames per second
		game.elapsedTime += (float) SECONDS_PER_FRAME;
		// printf("%f\n", game.elapsedTime);
		if (game.action != -1)
		{
			doUserAction();
			game.action = -1;
		}
		update();
		mapBoardToStage(false);
		updateStage(game.frogLocation.row, game.frogLocation.col, 0x6660);
		drawStageToFrameBuffer();
		// printBoard();
		// break;
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);

	return 0;
}