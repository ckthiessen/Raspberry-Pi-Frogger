#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "framebuffer.h"
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define GAME_CENTER 200
#define TILE_HEIGHT 72
#define TILE_WIDTH 128


/* Definitions */
typedef struct {
	int color;
	int x, y;
} Pixel;

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

// How should I decide the size of my tiles? Talk about aspect ration.
//	 Thinking of 128X72 cause that would give 10 rows. is that enough?  
// How can I clear my screen remotely?
// Any tips for getting started? Or what to work on first? 
// How should I start? Should I do a console version first and then just paint
	// Make sure have system for painting

void drawObject(int color, int x, int y, int row) {

	{
		for (int x = GAME_CENTER; x < GAME_WIDTH+GAME_CENTER; x++) 
		{	
				pixel->color = 0xFFFF; // White pixel
				pixel->x = x;
				pixel->y = y;
	
				drawPixel(pixel);
		}
	}
}

void drawBoard() {
	/* initialize a pixel */
	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

	for (int y = GAME_CENTER; y < GAME_HEIGHT+GAME_CENTER; y++)
	{
		for (int x = GAME_CENTER; x < GAME_WIDTH+GAME_CENTER; x++) 
		{	
				pixel->color = 0xFFFF; // White pixel
				pixel->x = x;
				pixel->y = y;
	
				drawPixel(pixel);
		}
	}

	/* free pixel's allocated memory */
	free(pixel);
	pixel = NULL;

}

void render() {
	drawBoard();
}

/* main function */
int main(){

	/* initialize + get FBS */
	framebufferstruct = initFbInfo();

	render();
	
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
	

	return 0;
}



/* Draw a pixel */
// What is this doing? Why is it /8? 
void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}

