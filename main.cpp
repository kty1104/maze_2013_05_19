#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "structures.h"

extern map m;
extern hero h;
extern screen sc;
extern int stage;
extern time_t start;
map read_map(int stage);
void all_in_one_print(map m, hero h);


int tile_exist(int x, int y)
{
	if(m.map[y][x] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void move_hero(int offset_x, int offset_y)
{
	if(tile_exist(h.x+offset_x,h.y+offset_y)==true)
	{
		return;
	}
	else
	{
		h.x += offset_x;
		h.y += offset_y;
	}
}

void key_process()
{
	if(GetAsyncKeyState(VK_LEFT)!=0)
	{
		move_hero(-1,0);
	}
	if(GetAsyncKeyState(VK_RIGHT)!=0)
	{
		move_hero(1,0);
	}
	if(GetAsyncKeyState(VK_UP)!=0)
	{
		move_hero(0,-1);
		
	}
	if(GetAsyncKeyState(VK_DOWN)!=0)
	{
		move_hero(0,1);
	}
}

int check_escape(hero h,map m)
{
	int dest_x = m.width-2;
	int dest_y = m.height-2;

	for(int y = -1; y<=1; y++)
	{
		for(int x = -1; x<=1; x++)
		{
			if(h.x == dest_x+x && h.y == dest_y+y)
			{
				return true;
			}
		}
	}
	return false;
	
}



void init()
{
	h.x = 1;
	h.y = 1;
	memset(&sc,0,sizeof(screen));
	memset(&m,0,sizeof(map));
}

void load_next_stage()
{
	init();
	stage++;
	if(stage==5)
	{
		MessageBox(0,L"축하합니다 모두 클리어하셨군요",L"경 축",MB_OK);
		exit(0);
	}
	map map_from_file;
	map_from_file = read_map(stage);
	memset(&m,0,sizeof(map));
	memcpy(&m,&map_from_file,sizeof(map));
}
int main()
{
	start = time(0);
	init();
	load_next_stage();
	time(0);
	while(1)
	{
		Sleep(50);
		key_process();
		all_in_one_print(m,h);
		if(check_escape(h,m)==true)
		{
			load_next_stage();
		}
	}
}