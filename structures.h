#ifndef STRUCTURE_H
#define STRUCTURE_H

#define SCR_WIDTH 40
#define SCR_HEIGHT 20
#define MAX_MAP_W 100
#define MAX_MAP_H 100
#define BLANK 0
#define TILE 1
#define HERO 2
#define STAR 3

#define COLOR_TILE 13
#define COLOR_BLANK 0
#define COLOR_HERO 15
#define COLOR_STAR 14

#define HERO_SIGHT_WIDTH 6
#define HERO_SIGHT_HEIGHT 4


typedef struct _hero
{
	int x;
	int y;
}hero;

typedef struct _map
{
	int stage;
	int width;
	int height;
	int map[MAX_MAP_H][MAX_MAP_W];
}map;
typedef struct _screen
{
	int ch_buffer[SCR_HEIGHT][SCR_WIDTH];
	int color_buffer[SCR_HEIGHT][SCR_WIDTH];
}screen;
#endif