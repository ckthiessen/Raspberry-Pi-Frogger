#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include "framebuffer.h"
#include "charscreen.h"
//#include <wiringPi.h>	//delayMicroseconds(int)
#include <stdbool.h>	//true, false
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define GAME_CENTER 200
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_TILES 20
#define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS

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
	for(int i = 0; i < NUM_TILES; i++) {
		for(int j = 0; j < NUM_TILES; j++) {
			map.board[i][j] = '-';
			if(i == 18) {
				map.board[i][j] = 'c';
			}
		}
	}
}

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

Pixel *pixel;

// void drawTile(int yOffset, int xOffset, int color, Pixel *pixel) {
void drawTile(int yOffset, int xOffset, int color) {
	/* initialize a pixel */
	
	// Pixel *pixel;
	// pixel = malloc(sizeof(Pixel));
	// printf("yst %d\n", GAME_CENTER*yOffset);
	// printf("yend %d\n", GAME_CENTER*(TILE_HEIGHT*yOffset));
	// printf("xst %d\n", GAME_CENTER*xOffset));
	// printf("xend %d\n", GAME_CENTER*(TILE_HEIGHT*xOffset));
	// for (int y = (GAME_CENTER*yOffset); y < GAME_CENTER+(TILE_HEIGHT*yOffset); y++) {
	for (int y = TILE_HEIGHT*(yOffset-1); y < TILE_HEIGHT*yOffset; y++) {
		// printf("%d\n", y);
		// for (int x = (GAME_CENTER*xOffset); x < GAME_CENTER+(TILE_WIDTH*xOffset); x++) {
		for (int x = TILE_WIDTH*(xOffset-1); x < TILE_WIDTH*xOffset; x++) {
			// printf("%d\n", x);
			pixel->color = color;
			pixel->x = x;
			pixel->y = y;
			drawPixel(pixel);
		}
	}
	/* free pixel's allocated memory */
	// free(pixel);
	// pixel = NULL;

}

void render() {
	for(int i = 0; i < NUM_TILES; i++) { 
		for(int j = 0; j < NUM_TILES; j++) { // Starts working when j is 4
			char tile = map.board[i][j];
			// printf("%c", tile);
			switch (tile)
			{
			case '-':
				// drawTile(i+1, j+1, 0xFFFF, pixel);
				drawTile(i+1, j+1, 0xFFFF);
				break;
			case 'c':
				// drawTile(i+1, j+1, 0xF800, pixel);
				drawTile(i+1, j+1, 0x6660);
			default:
				break;
			}
		}
		printf("\n");
	}
}


/* main function */
int main(){
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	pixel = malloc(sizeof(Pixel));

	
	generateStartingMap();
	while(true) {
		time_t start = time(NULL);
		// processInput();
		// update();
		render();
		sleep(start + SECONDS_PER_FRAME - time(NULL));
	}
	// Uncomment to render with pixels
	render();
	
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