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

void mapBoardToStage(bool debug)
{
	for (int row = game.scrollOffset; row < NUM_RENDERED_TILES + game.scrollOffset; row++)
	{
		for (int col = HORIZONTAL_OFFSET; col < NUM_RENDERED_TILES + HORIZONTAL_OFFSET; col++)
		{
			char tile = map.board[row][col];
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
			case 'g':
				color = 0x0420;
				break;
			case 'l':
				color = 0x8B00;
				break;
			case ',':
				color = 0x34DE;
				break;
			case '.':
				color = 0x0000;
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
	if (
		map.board[game.frogLocation.row][game.frogLocation.col] == 'c' ||
		map.board[game.frogLocation.row][game.frogLocation.col] == ',' ||
		map.board[game.frogLocation.row][game.frogLocation.col] == 'b')
	{
		resetFrogPosition();
		game.lives--;
		printf("Lives remaining: %d\n", game.lives);
	}

}

void update(void)
{
	char boardBuffer[NUM_MAP_TILES][NUM_MAP_TILES];
	memcpy(boardBuffer, map.board, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	for (int row = 0; row < NUM_MAP_TILES; row++)
	{
		for (int col = 0; col < NUM_MAP_TILES; col++)
		{
			char obstacle = map.board[row][col];
			char background = '\0';
			switch (obstacle)
			{
			case 'c':
			case 'b':
				background = '-';
				break;
			case 'l':
				background = ',';
				break;
			default:
				break;
			}
			if (background != '\0') {
				boardBuffer[row][col] = background;
				boardBuffer[row][(col + laneVelocities[row] + NUM_MAP_TILES) % NUM_MAP_TILES] = obstacle;
			}
		}
	}
	memcpy(map.board, boardBuffer, NUM_MAP_TILES * NUM_MAP_TILES * sizeof(char));
	// checkCollision();
}

void pauseGame(void)
{
	game.action = NO_ACTION;
	bool paused = true;
	while (paused)
	{
		if (game.action == START)
		{
			paused = false;
			usleep(250 * 1000);
		}
	}
}

void moveFrog(int direction)
{
	switch (game.action)
	{
	case UP:
		game.frogLocation.row--;
		if (game.frogLocation.row < 40 && game.frogLocation.row >= 10)
		{
			game.scrollOffset--;
		}
		break;
	case DOWN:
		game.frogLocation.row++;
		if (game.frogLocation.row < 40 && game.frogLocation.row >= 10)
		{
			game.scrollOffset++;
		}
		break;
	case LEFT:
		game.frogLocation.col--;
		break;
	case RIGHT:
		game.frogLocation.col++;
		break;
	}
}

void doUserAction(void)
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

/* Draw a frame */
void drawStageToFrameBuffer(void)
{
	memcpy(framebufferstruct.fptr, map.stage, 1280 * 720 * 2);
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
			buttonPress == START)
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
	game.lives = 3;
}

void updateFrogLocation(void)
{
	if(map.board[game.frogLocation.row][game.frogLocation.col] == 'l') {
		game.frogLocation.col += laneVelocities[game.frogLocation.row];
	}
	updateStage(game.frogLocation.row, game.frogLocation.col, 0x6660);
}

/* main function */
int main(int argc, char* argv[])
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
		game.elapsedTime += (float)SECONDS_PER_FRAME;
		// printf("%f\n", game.elapsedTime);
		if (game.action != -1)
		{
			doUserAction();
			game.action = -1;
		}
		update();
		mapBoardToStage(false);
		updateFrogLocation();
		drawStageToFrameBuffer();
		// printBoard();
		// break;
	}

	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);

	return 0;
}