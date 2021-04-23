#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include "framebuffer.h"
#include <wiringPi.h>	//delayMicroseconds(int)
#include <stdbool.h>	//true, false
#include <unistd.h>
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define GAME_CENTER 200
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_TILES 20
// #define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS
// #define SECONDS_PER_FRAME 1/10 // Time to render a frame such that we have 10 FPS (FOR TESTING)
#define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

/* Definitions */
typedef struct {
	int color;
	int x, y;
} Pixel;


struct Map {
	char board[NUM_TILES][NUM_TILES];
	unsigned short stage[GAME_WIDTH*GAME_HEIGHT];
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "--------------------"
	// "cc------------------"
	// "--------------------"
	// "--------------------"
} map;

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

void generateStartingMap() {
	for(int row = 0; row < NUM_TILES; row++) {
		for(int col = 0; col < NUM_TILES; col++) {
			map.board[row][col] = '-';
		}
	}
	map.board[15][19] = 'c';
	map.board[15][18] = 'c';
}

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

Pixel *pixel;

void updateStage(int yOffset, int xOffset, int color) {
	/* initialize a pixel */
	for (int y = TILE_HEIGHT*(yOffset-1); y < TILE_HEIGHT*yOffset; y++) {
		for (int x = TILE_WIDTH*(xOffset-1); x < TILE_WIDTH*xOffset; x++) {
			map.stage[(y*GAME_WIDTH) + x] = color;
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


void mapBoardToStage() {
	for(int row = 0; row < NUM_TILES; row++) { 
		for(int col = 0; col < NUM_TILES; col++) { 
			char tile = map.board[row][col];
			printf("%c", tile);
			switch (tile)
			{
			case '-':
				updateStage(row+1, col+1, 0xFFFF);
				break;
			case 'c':
				updateStage(row+1, col+1, 0xF000);
			default:
				break;
			}
		}
		printf("\n");
	}
}

unsigned long elapsed = 0;

// void update() {
// 	for(int row = 0; row < NUM_TILES; row++) { 
// 		int offset = (elapsed * 2) % 20;
// 		for(int col = 0; col < NUM_TILES; col++) { 
// 			char tile = map.board[row][(offset + col) % 20];
// 			drawTile(row+1, col+1, tile);
// 		}
// 		printf("\n");
// 	}
// }


void printBoard() {
	for(int row = 0; row < NUM_TILES; row++) { 
		for(int col = 0; col < NUM_TILES; col++) { 
			char tile = map.board[row][col];
			printf("%c", tile);
		}
		printf("\n");
	}
}

/* Draw a frame */
void drawFrame() {
	memcpy(framebufferstruct.fptr, map.stage, 1280*720*2);
}


/* main function */
int main(){
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	
	generateStartingMap();
	mapBoardToStage();
	drawFrame();
	
	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	
	return 0;
}



/* Draw a pixel */
void drawPixel(Pixel *pixel) {
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}