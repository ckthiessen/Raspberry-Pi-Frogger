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

void updateStage(int yOffset, int xOffset, int color, int tileOffset)
{
	for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset - 1); y < TILE_HEIGHT * (yOffset - game.scrollOffset); y++)
	{
		for (int x = TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET - 1) - tileOffset; x < TILE_WIDTH * (xOffset - HORIZONTAL_OFFSET) - tileOffset; x++)
		{
			map.stage[(y * GAME_WIDTH) + x] = color;
		}
	}
}

// void updateStage(int yOffset, int xOffset, int color)
// {
// 	for (int y = TILE_HEIGHT * (yOffset - game.scrollOffset - 1); y < TILE_HEIGHT * (yOffset - game.scrollOffset); y++)
// 	{
// 		for (int x = TILE_WIDTH * (xOffset - 1) - tileOffset; x < TILE_WIDTH * xOffset - tileOffset; x++)
// 		{
// 			if(map.stage[(y * GAME_WIDTH) + x] == 0x6660) { continue; }
// 			map.stage[(y * GAME_WIDTH) + x] = color;
// 		}
// 	}
// }

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

void mapBoardToStage()
{
	int x = -1, y = 0;
	for (int row = game.scrollOffset; row < NUM_RENDERED_TILES + game.scrollOffset; row++)
	{
		int position = (int)(game.elapsedTime * laneVelocities[row]) % NUM_MAP_TILES;
		int tileOffset = (int)((float) TILE_WIDTH * game.elapsedTime * laneVelocities[row]) % TILE_WIDTH;
		// printf("%d\n", tileOffset);
		for (int col = HORIZONTAL_OFFSET; col < NUM_RENDERED_TILES + HORIZONTAL_OFFSET; col++)
		{
			char tile = map.board[row][(position + col) % NUM_MAP_TILES];
			// printf("%c\n", tile);
			// char tile = map.board[row][col];
			switch (tile)
			{
			case '-':
				updateStage(row + 1, col + 1, 0x8410, tileOffset);
				break;
			case 'b':
				updateStage(row + 1, col + 1, 0x001F, tileOffset);
				break;
			case 'c':
				updateStage(row + 1, col + 1, 0xF800, tileOffset);
				break;
			default:
				break;
			}
		}
		updateStage(row + 1, 1 + HORIZONTAL_OFFSET, 0x0000, 0);
		updateStage(row + 1, 20 + HORIZONTAL_OFFSET, 0x0000, 0);
		// 	if(row == 49) {
		// printf("\n");
		// 	}
	}
}

unsigned long elapsed = 0;

void update()
{
	char boardBuffer[NUM_MAP_TILES][NUM_MAP_TILES];
	memcpy(boardBuffer, map.board, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	for (int row = 0; row < NUM_MAP_TILES; row++)
	{
		// int tileOffset = (int)(game.elapsedTime * (float)laneVelocities[row] * (float)NUM_MAP_TILES) % NUM_MAP_TILES;
		for (int col = 0; col < NUM_MAP_TILES; col++)
		{
			// if (map.board[row][col] == 'c' || map.board[row][col] == 'b')
			// {
			// 	char tile = map.board[row][col];
			// 	boardBuffer[row][col] = '-';
			// 	boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES] = tile;
			// }
		}
	}
	memcpy(map.board, boardBuffer, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
}

void pauseGame()
{ 
	game.action = NO_ACTION;
	while(true) {
		if(game.action == START) {
			break;
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
		if(game.frogLocation.row < 40 && !(game.frogLocation.row < 10)) {
			game.scrollOffset--;
		}
		break;
	case DOWN:
		map.board[game.frogLocation.row + 1][game.frogLocation.col] = 'f';
		game.frogLocation.row++;
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
		usleep(1000*1000);
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

void resetGame() {
	game.scrollOffset = 30;
	game.action = -1;
	game.frogLocation = FROG_START;
}

/* main function */
int main()
{
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	// time_t timer = time(NULL);
	// long start = clock();

	pthread_t controllerThread;
	pthread_create(&controllerThread, NULL, getUserInput, NULL);
	resetGame();
	// generateStartingMap();
	game.elapsedTime = 0.0;
	while (true)
	{
		usleep(((float) SECONDS_PER_FRAME * 1000) * 1000); // Sleep 1 second
		game.elapsedTime += (float) SECONDS_PER_FRAME;
		// printf("%f\n", game.elapsedTime);
		if (game.action != -1)
		{
			doUserAction();
			game.action = -1;
		}
		// update();
		mapBoardToStage();
		updateStage(game.frogLocation.row + 1, game.frogLocation.col + 1, 0x6660, 0);
		drawStageToFrameBuffer();
		// printBoard();
		// break;
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);

	return 0;
}