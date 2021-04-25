#ifndef FROGGER
#define FROGGER

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define TILE_HEIGHT 36
#define TILE_WIDTH 64
#define NUM_RENDERED_TILES 20
#define NUM_MAP_TILES 50
#define HORIZONTAL_OFFSET 9 // Offset horizontal rendering by 10 to eliminate obstacle pop-in
// #define SECONDS_PER_FRAME 1/30 // Time to render a frame such that we have 30 FPS
// #define SECONDS_PER_FRAME 1/10 // Time to render a frame such that we have 10 FPS (FOR TESTING)
#define SECONDS_PER_FRAME 1 // Time to render a frame such that we have 1 FPS (FOR TESTING)

typedef struct
{
	unsigned short row, col;
} Coordinate;

/* Definitions */
typedef struct
{
	short velocity;
} Lane;

struct Game
{
	short scrollOffset; // Offset used for scrolling
	short action;
	Coordinate frogLocation;
} game = {
	30,		// Sroll offset initialized to 30 to display bottom 20 rows
	-1,		// Player action initialized to -1 (no action)
	{49, 19} // Starting coordinate for the frog
};

struct Map
{
	char board[NUM_MAP_TILES][NUM_MAP_TILES];
	unsigned short stage[GAME_WIDTH * GAME_HEIGHT];
} map = {
	{"--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "cc-------cc----------cc------cc-------cc-----cc--", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "--bbbb------------bbbb---------bbbb------bbbb----", //bw
	 "ggggggggggggggggggggggggggggggggggggggggggggggggg", //fw
	 "-----cc----------cc--------cc----cc----cc---cc-cc", //bw
	 "------bbbb--------------bbbb---bbbb----bbbb--bbbb", //fw
	 "--cc------cc------cc--------cc----cc--cc---cc-cc-", //bw
	 "-----cc--------cc--------cc-----cc-cc----cc--cc--", //fw
	 "----cc-----cc--------cc-------cc----cc--------cc-", //bw
	 "gggggggggggggggggggfggggggggggggggggggggggggggggg"},
	{}};

#endif


