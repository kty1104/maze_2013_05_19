#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

map read_map(int stage)
{
	map m;
	char map_name[100];
	FILE * fp;
	m.stage = stage;
	sprintf(map_name, "maze%03d.txt", stage);
	fp = fopen(map_name,"rt");
	int y,x;
	x = 0;
	y = 0;
	int wid;
	int height;
	while(1)
	{
		int ch = fgetc(fp);
		
		if(ch=='\n')
		{
			y++;
			wid = x;
			height = y;
			x = 0;
		}
		else if(ch==EOF)
		{
			m.height = y;
			m.width = wid;
			m.map[m.height-2][m.width-2] = STAR;
			break;
		}
		if(ch == '0')
		{
			m.map[y][x]=BLANK;
			x++;
		
		}
		if(ch == '1')
		{
			m.map[y][x]=TILE;
			x++;
		
		}
		
	}

	return m;
}