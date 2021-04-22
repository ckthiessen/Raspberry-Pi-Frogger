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


// possible struct for game screen;
typedef struct {
	int x, y;
	int color;
	// int 
} screen_frame;


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

struct gameMap {
	char screen[1280][720];
} game_screen;


// just 7 as row just to start, will have more for logs and what not
char objectArr[7][50] = 
{
	// cars/buses
"--bbbb------------bbbb---------bbbb------bbbb-----", //bw
"cc-------cc----------cc------cc-------cc-----cc---",	//fw
"-----cc----------cc--------cc----cc----cc---cc--cc",	//bw
"------bbbb--------------bbbb---bbbb----bbbb--bbbb-", //fw
"--cc------cc------cc--------cc----cc--cc---cc-cc--", //bw
"-----cc--------cc--------cc-----cc-cc----cc--cc---", //fw
"----cc-----cc--------cc-------cc----cc--------cc--" //bw

// logs
// 
// 
// 
// 
// 
// 
// 
};




// int mapCounter = 0;
// void generateStartingMap() {
// 	for(int row = 0; row < NUM_TILES; row++) {
// 		for(int col = 0; col < NUM_TILES; col++) {
// 			if(row == 11){
// 				map.board[row][col] = objectArr[0][mapCounter];
// 			}
// 			// else if(row == 12){
// 			// 	map.board[row][col] = objectArr[1][mapCounter];
// 			// }
// 			// else if(row == 13){
// 			// 	map.board[row][col] = objectArr[2][mapCounter];
// 			// }
// 			// else if(row == 14){
// 			// 	map.board[row][col] = objectArr[3][mapCounter];
// 			// }
// 			// else if(row == 15){
// 			// 	map.board[row][col] = objectArr[4][mapCounter];
// 			// }
// 			// else if(row == 16){
// 			// 	map.board[row][col] = objectArr[5][mapCounter];
// 			// }
// 			// else if(row == 17){
// 			// 	map.board[row][col] = objectArr[6][mapCounter];
// 			// }
// 			else{
// 				map.board[row][col] = '-';
// 			}


// 			if (mapCounter < 50){
// 				mapCounter++;
// 			}
// 			else {
// 				mapCounter = 0;
// 			}
			
// 		}
		
// 	}

// 	// map.board[18][18] = 'c';
// 	// map.board[18][17] = 'c';

// 	//cars/buses

// 	//score card rows

// 	// half way safe rows

// 	//logs/channel row

// 	//end of 1st screen


// }

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

Pixel *pixel;

screen_frame *screen;
void drawScreen(screen_frame *screen);

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

			// else if(row == 12){
			// 	map.board[row][col] = objectArr[1][mapCounter];
			// }
			// else if(row == 13){
			// 	map.board[row][col] = objectArr[2][mapCounter];
			// }
			// else if(row == 14){
			// 	map.board[row][col] = objectArr[3][mapCounter];
			// }
			// else if(row == 15){
			// 	map.board[row][col] = objectArr[4][mapCounter];
			// }
			// else if(row == 16){
			// 	map.board[row][col] = objectArr[5][mapCounter];
			// }
			// else if(row == 17){
			// 	map.board[row][col] = objectArr[6][mapCounter];
			// }
int mapCounter = 0;
void game_state(){
	for(int row = 0; row < 1280; row++) {
		int offset = (elapsed) % 720;
		for(int col = 0; col < 720; col++) {
			if(row == 11){
				game_screen.screen[row][col] = objectArr[0][mapCounter];
			}

			else{
				game_screen.screen[row][col] = '-';
			}


			if (mapCounter < 1280){
				mapCounter++;
			}
			else {
				mapCounter = 0;
			}
			
		}
		
	}
}









// int counter_draw = 0;

// void drawTile(int yOffset, int xOffset, char tile) {
// 	/* initialize a pixel */
	
// 	// yOffset = yOffset ;
// 	// xOffset = xOffset ;

// 	for (int y = TILE_HEIGHT*(yOffset-1); y < TILE_HEIGHT*yOffset; y++) {
// 		// for (int x = (TILE_WIDTH*(xOffset-1)); x < (TILE_WIDTH*xOffset); x++) {
// 		for (int x = (TILE_WIDTH*(xOffset-1)); x < (TILE_WIDTH*xOffset); x++) {
// 		// for (int x = ((TILE_WIDTH*(xOffset-1))+counter_draw); x < ((TILE_WIDTH*xOffset)+counter_draw); x++) {
// 			int color;
// 			switch (tile)
// 			{
// 			case '-':
// 				color = 0xFFFF;
// 				break;
// 			case 'b':
// 				color = 0x2200;
// 				break;
// 			case 'c':
// 				color = 0x6660;
// 			default:
// 				break;
// 			}
// 			pixel->color = color;
// 			pixel->x = x;
// 			pixel->y = y;
// 			drawPixel(pixel);

// 		}
// 	}
// 	// if(counter_draw == 32) counter_draw = 0;
// 	// counter_draw ++;
// }

// int counter_draw = 0;

unsigned long elapsed = 0;
void update() {
	for(int row = 0; row < NUM_TILES; row++) { 
		// int offset = (elapsed * 2) % 20;
		int offset = (elapsed) % 20;
		// int offset = (int)((float)TILE_WIDTH * elapsed * 2.0f) % 20;

		for(int col = 0; col < NUM_TILES; col++) { 
		// for(int col = 0; col < 1280; col++) { 
			// char tile = map.board[row][(offset + col) % 20];

			// for(int it = 0; it < )

			char tile = map.board[row][(offset + col) % 20]; //*********************

			// drawTile(row+1, col+1, tile);
			drawTile(row+1, col+1, tile);
		}
		printf("\n");
	}
}

// void update() {
// 	for (int row = 0; row < 1280; row++) {
// 		int offset = (elapsed * 2) % 20;

// 		for(int col = 0; col < NUM_TILES; col++) { 
// 			char tile = map.board[row][(offset + col) % 20];
// 			// pass row + 1 offset differently to smooth
			
// 			// pass col + 1 offset differently to smooth

// 			// drawTile(row+1, col+1, tile);
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


/* main function */
int main(){
	/* initialize + get FBS */
	framebufferstruct = initFbInfo();
	pixel = malloc(sizeof(Pixel));
	unsigned int wait = 0;
	double diff = 0;

	int counter = 0;
	
	// generateStartingMap();
	game_state(screen); 

	while(true) {

		//------------------------
		// generateStartingMap();
		//------------------------

		game_state(screen); // generate state of game

		time_t start = time(NULL);
		// processInput();
		// update();
		// render();

		//drawScreen call (similar to update)
		// drawScreen();	// draw the screen 


		diff = start + 1 - time(NULL);
		// wait = diff > 0 ? diff : 0;
		usleep(1000 * 1000); // Sleep 1 second
		// usleep(182.5 * 182.5);

		// counter++;

		// if(counter == 32){
		// 	elapsed++;
		// 	counter = 0;
		// }
		elapsed++;
		// counter++;
		printf("%ld\n", elapsed);

		// generateStartingMap();

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

// void drawPixel(Map *map){
// 	memcpy(map->framebuffer->fptr, map-> , 1280*720*2);
// }

void drawScreen(screen_frame *screen) {
	memcpy(screen->framebufferstruct->fptr, screen->game_state, 1280*720);
}