#include <stdio.h>
#include <windows.h>

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct {
	int No;
	char Name[15];
	float Price;
	int Qty;
} RECORDS;

int main() {
	RECORDS item[5];
	int y = 0, i;
	float total[5];

	system("cls");

	gotoxy(10, 0);
	printf("Item No.");

	gotoxy(30, 0);
	printf("Item Name");

	gotoxy(50, 0);
	printf("Unit Price");

	gotoxy(70, 0);
	printf("Quantity");

	gotoxy(90, 0);
	printf("Total Price");

	for (i = 1; i <= 5; i++) {
		gotoxy(5, y + i);
		printf("%d.", i);
	}

	for (i = 0; i < 5; i++) {
		gotoxy(11, y + i + 1);
		scanf("%d", item[i].No);
		
		gotoxy(30, y + i + 1);
		scanf("%s", item[i].Name);
		
		gotoxy(51, y + i + 1);
		scanf("%f", &item[i].Price);
		
		gotoxy(71, y + i + 1);
		scanf("%d", &item[i].Qty);
		
		total[i] = item[i].Price * item[i].Qty;
		gotoxy(91, y + i + 1);
		printf("%0.2f", total[i]);
	}

	gotoxy(80, 24);

	return 0;
}
