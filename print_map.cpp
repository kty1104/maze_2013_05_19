#include "structures.h"
#include <stdio.h>
#include <Windows.h>
#include <time.h>
extern screen sc;
extern time_t start;
void goto_00()
{
	
    COORD XY = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

}
void change_color(char foreground)
{
	foreground = foreground%16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground);
}

void print_map_to_buf(map m)
{
	for(int y=0;y<m.height;y++)
	{
		for(int x = 0; x<m.width;x++)
		{
			if(m.map[y][x]==0)
			{
				sc.ch_buffer[y][x] = BLANK;
				sc.color_buffer[y][x] = COLOR_BLANK;
			}
			if(m.map[y][x]==1)
			{
				sc.ch_buffer[y][x] = TILE;
				sc.color_buffer[y][x] = COLOR_TILE;
			}
			if(m.map[y][x]==3)
			{
				sc.ch_buffer[y][x] = STAR;
				sc.color_buffer[y][x] = COLOR_STAR;
			}
		}
	}
}

void print_hero_to_buf(hero h)
{
	int x = h.x;
	int y = h.y;
	sc.ch_buffer[y][x] = HERO;
	sc.color_buffer[y][x] = COLOR_HERO;
}

void print_to_buf(map m, hero h)
{
	print_map_to_buf(m);
	print_hero_to_buf(h);
}

//이 함수를 호출해서 화면에 출력 위의 함수는 이 함수 안에서만 호출됨.
//초기화 후(맵 로드, 주인공 좌표 설정)에 출력해야 함.
void all_in_one_print(map m, hero h)
{
	goto_00();
	print_to_buf(m,h);
	double sec = difftime(time(0),start);
	change_color(15);
	printf("time passed: %g\n", sec);
	for(int y = h.y - HERO_SIGHT_HEIGHT; y<h.y + HERO_SIGHT_HEIGHT; y++)
	{
		for(int x = h.x - HERO_SIGHT_WIDTH; x<h.x + HERO_SIGHT_WIDTH; x++)
		{

			if(x<0 || y<0 || x>m.width-1 || y>m.height-1)
			{
				change_color(COLOR_BLANK);
				printf("  ");

			}
			else
			{
				if(sc.ch_buffer[y][x]==BLANK)
				{
					change_color(COLOR_BLANK);
					printf("  ");
				}
				else if(sc.ch_buffer[y][x]==HERO)
				{
					change_color(COLOR_HERO);
					printf("●");
				}
				else if(sc.ch_buffer[y][x]==TILE)
				{
					change_color(COLOR_TILE);
					printf("■");
				}
				else if(sc.ch_buffer[y][x]==STAR)
				{
					change_color(COLOR_STAR);
					printf("★");
				}
			}
			
		}
		printf("\n");
	}
}

