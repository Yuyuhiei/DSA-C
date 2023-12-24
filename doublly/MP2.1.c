#include <stdio.h>
#include <windows.h>

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct record {
    int itemNum;
    char itemName[15];
    float unitPrice;
    int qty;
} record;

int main() {
    record item[5];
    int i;
    float total[5];
    gotoxy(0, 0);
    printf("Item No.");

    gotoxy(20, 0);
    printf("Item Name");

    gotoxy(40, 0);
    printf("Unit Price");

    gotoxy(60, 0);
    printf("Quantity");

    gotoxy(80, 0);
    printf("Total Price");

    for (i = 0; i < 5; i++) {
        printf("\n");
        gotoxy(0, i + 2);
        scanf("%d", &item[i].itemNum);

        gotoxy(20, i + 2);
        scanf("%s", item[i].itemName);

        gotoxy(40, i + 2);
        scanf("%f", &item[i].unitPrice);

        gotoxy(60, i + 2);
        scanf("%d", &item[i].qty);

        total[i] = item[i].unitPrice * item[i].qty;

        gotoxy(80, i + 2);
        printf("%0.2f", total[i]);
    }

    printf("\n\nFinal Table:\n");
    printf("----------------------------------------------\n");
    printf("Item No.\tItem Name\tUnit Price\tQuantity\tTotal Price\n");
    printf("----------------------------------------------\n");
    
    for (i = 0; i < 5; i++) {
        printf("%d\t\t%s\t\t%0.2f\t\t%d\t\t%0.2f\n", item[i].itemNum, item[i].itemName, item[i].unitPrice, item[i].qty, total[i]);
    }
    
    return 0;
}

