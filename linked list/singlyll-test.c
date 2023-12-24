#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int main(){
    node *Start, *NewNode, *Current;
    char Resp, Temp;
    int Ctr = 1;

    Start = NULL;
    NewNode = (node *)malloc(sizeof(node));
    Start = NewNode;

    printf("Creating Single Linked-list\n\n");

    do{
    printf("\nEnter Node #%d\n", Ctr);
    printf("\tEnter Data: ");
    scanf("%d", &NewNode->data);
    scanf("%c", &Temp);
    printf("Do you want to add another data? ");
    scanf("%c", &Resp);
    if(toupper(Resp) == 'Y'){
        Ctr++;
        NewNode->next = (node *)malloc(sizeof(node));
        NewNode = NewNode->next;}
    }while(toupper(Resp) == 'Y');
        NewNode->next = NULL;
        NewNode = NULL;
    

    printf("\nDisplaying the Linked-List!!");
    Ctr = 1;
    Current = Start;
    if(Current == NULL)
        printf("There's no data in here!!!!");
    else
    do{
        printf("\nNode #%d = %d", Ctr, Current->data);
        Current = Current->next;
        Ctr++;
    }
    while(Current!=NULL);
        free(Start);
        Current = Start = NULL;
        getch();
        return 0; 
}