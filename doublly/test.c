#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void bangeler(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 

typedef struct{
	char Name[10];
	int BodyCount;
}Angelo;
