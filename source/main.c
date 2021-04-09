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

void generateStartingMap() {
	for(int row = 0; row < NUM_TILES; row++) {
		for(int col = 0; col < NUM_TILES; col++) {
			map.board[row][col] = '-';
		}
	}
	// map.board[18][18] = 'c';
	// map.board[18][17] = 'c';
	map.board[18][2] = 'c';
	map.board[18][3] = 'c';
}

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

Pixel *pixel;

// void drawTile(int yOffset, int xOffset, int color, Pixel *pixel) {
// void drawTile(int yOffset, int xOffset, int color) {
// 	/* initialize a pixel */
	
// 	// Pixel *pixel;
// 	// pixel = malloc(sizeof(Pixel));
// 	// printf("yst %d\n", GAME_CENTER*yOffset);
// 	// printf("yend %d\n", GAME_CENTER*(TILE_HEIGHT*yOffset));
// 	// printf("xst %d\n", GAME_CENTER*xOffset));
// 	// printf("xend %d\n", GAME_CENTER*(TILE_HEIGHT*xOffset));
// 	// for (int y = (GAME_CENTER*yOffset); y < GAME_CENTER+(TILE_HEIGHT*yOffset); y++) {
// 	for (int y = TILE_HEIGHT*(yOffset-1); y < TILE_HEIGHT*yOffset; y++) {
// 		// printf("%d\n", y);
// 		// for (int x = (GAME_CENTER*xOffset); x < GAME_CENTER+(TILE_WIDTH*xOffset); x++) {
// 		for (int x = TILE_WIDTH*(xOffset-1); x < TILE_WIDTH*xOffset; x++) {
// 			// printf("%d\n", x);
// 			pixel->color = color;
// 			pixel->x = x;
// 			pixel->y = y;
// 			drawPixel(pixel);
// 		}
// 	}
// 	/* free pixel's allocated memory */
// 	// free(pixel);
// 	// pixel = NULL;

// }

void drawTile(int yOffset, int xOffset, char tile) {
	/* initialize a pixel */

	for (int y = TILE_HEIGHT*(yOffset-1); y < TILE_HEIGHT*yOffset; y++) {
		for (int x = TILE_WIDTH*(xOffset-1); x < TILE_WIDTH*xOffset; x++) {
			int color;
			switch (tile)
			{
			case '-':
				color = 0xFFFF;
				break;
			case 'c':
				color = 0x6660;
			default:
				break;
			}
			pixel->color = color;
			pixel->x = x;
			pixel->y = y;
			drawPixel(pixel);
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

unsigned long elapsed = 0;

void update() {
	for(int row = 0; row < NUM_TILES; row++) { 
		int offset = (elapsed * 2) % 20;
		for(int col = 0; col < NUM_TILES; col++) { 
			char tile = map.board[row][(offset + col) % 20];
			drawTile(row+1, col+1, tile);
		}
		printf("\n");
	}
}


void printBoard() {
	for(int row = 0; row < NUM_TILES; row++) { 
		for(int col = 0; col < NUM_TILES; col++) { 
			char tile = map.board[row][col];
			printf("%c", tile);
		}
		printf("\n");
	}
}


/* main function */
int main(){
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	pixel = malloc(sizeof(Pixel));
	unsigned int wait = 0;
	double diff = 0;

	
	generateStartingMap();
	while(true) {
		time_t start = time(NULL);
		// processInput();
		update();
		// render();

		diff = start + 1 - time(NULL);
		// wait = diff > 0 ? diff : 0;
		usleep(1000 * 1000); // Sleep 1 second
		elapsed++;
		printf("%ld\n", elapsed);
	}
	// Uncomment to render with pixels
	// render();
	
	free(pixel);
	pixel = NULL;
	
	// mummap = "memory unmap"; frees the following mapping from memory
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	
	return 0;
}



/* Draw a pixel */
void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}