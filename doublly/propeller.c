#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // for Sleep() function

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int x = 40, y = 12;
    int i, j, k;
    char propeller[] = "|/-\\";

    // hide the cursor
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    // infinite loop for animation
    while (1) {
        // draw propeller
        for (i = 0; i < 4; i++) {
            gotoxy(x, y);
            printf("%c", propeller[i]);
            for (j = 1; j < 5; j++) {
                gotoxy(x, y+j);
                printf("%c", propeller[(i+j)%4]);
            }
            for (k = 3; k >= 0; k--) {
                gotoxy(x, y+8-k);
                printf("%c", propeller[(i+k)%4]);
            }
            Sleep(50); // pause for 50 milliseconds
        }
    }
    return 0;
}

