#include<iostream>
using namespace std;
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define STAR_NUM 50
#define APPEAR_STAR 8
void textcolor(int foreground, int background);
void gotoxy(int x,int y);
int main()
{
	int fore, x[STAR_NUM+1], y[STAR_NUM+1],i=0,j=0;
    srand((unsigned int)time(0));
	while (i<=STAR_NUM&&j< STAR_NUM) {
		if (i < STAR_NUM) {
			fore = rand() % 16;
			textcolor(fore, BLACK);
			x[i] = rand() % 81;
			y[i] = rand() % 26;
			gotoxy(x[i], y[i]);
			putchar('*');
			Sleep(800);
			i++;
		}
		if (i >= APPEAR_STAR) {
			textcolor(BLACK, BLACK);
			gotoxy(x[j], y[j]);
			putchar('*');
			j++;
			Sleep(500);
		}
	}
	textcolor(WHITE, BLACK);
	return 0;
}
void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x,int y){
    COORD Pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

