#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(short x, short y) { 
COORD pos = {x, y}; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 

main()
{
 float QtrSale,Sales[6][4],TSales[6];
 int   Ridx,Cidx;

 system("cls");
 gotoxy(31,3);printf("SALES SUMMARY REPORT");
 gotoxy(33,6);printf("Q U A R T E R");
 gotoxy(20,8);printf("1st        2nd        3rd        4th        Total Sales");
 gotoxy(10,10);printf("1st");
 gotoxy(10,12);printf("2nd");
 gotoxy(10,14);printf("3rd");
 gotoxy(10,16);printf("4th");
 gotoxy(10,18);printf("5th");
 gotoxy(10,20);printf("6th");
 gotoxy(3,12);printf("Y");
 gotoxy(3,14);printf("E");
 gotoxy(3,16);printf("A");
 gotoxy(3,18);printf("R");
 for(Ridx=0;Ridx<=5;Ridx++)
   for(Cidx=0;Cidx<=3;Cidx++)
     {
       gotoxy((17-Cidx)+(Cidx*12),10+(Ridx*2));
       scanf("%f",&QtrSale);
       Sales[Ridx][Cidx] = QtrSale;
     }
 for(Ridx=0;Ridx<=5;Ridx++)
   {
     TSales[Ridx] = 0;
     for(Cidx=0;Cidx<=3;Cidx++)
	  TSales[Ridx] += Sales[Ridx][Cidx];
     gotoxy(65,10+(Ridx*2));
     printf("%9.2f",TSales[Ridx]);
   }
 getch();
}





