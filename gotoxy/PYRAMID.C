#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Defines gotoxy() for ANSI C compilers. 
void gotoxy(short x, short y) { 
COORD pos = {x, y}; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 

int main()
{
 int i,j,PS,Y,X; 

 do{
     system("CLS");
     printf("Enter Size of PYRAMID [2 to 20]=> ");
     scanf("%d",&PS);
 }while (!(PS>=2)&&(PS<=20));
 Y=12-(PS/2);
 for(i=1;i<=PS;i++)
  {
   X=41-i;
   for(j=1;j<=i;j++)
     {
       gotoxy(X+(j*2),Y+i);
       printf("*");
     }
  }
 getch();
 return(0);

}