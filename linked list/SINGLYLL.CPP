#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>
typedef struct node{
      int data;
      node *next;
      };

int main(){
  node *START, *NewNode, *Current;
  char Resp,Temp;
  int Ctr=1;


  START=NULL;
  NewNode = (node*)malloc(sizeof(node));
  START=NewNode;


  printf("Creating Single/Singly Linked List!!!\n\n");
  do{
      printf("Node No. %d\n",Ctr);
      printf("Enter Data => ");
      scanf("%d",&NewNode->data);
      scanf("%c", &Temp);
      printf("\nAdd another NODE [Y/N]? ");
      scanf("%c",&Resp);
          if (toupper(Resp) == 'Y')
          {
	        Ctr++;
	        NewNode->next=(node*)malloc(sizeof(node));
	        NewNode=NewNode->next;
          }
   }while(toupper(Resp)=='Y');
   NewNode->next=NULL;
   NewNode=NULL;

   printf("Displaying the Contents of the Single/Singly Linked List!!!\n\n");
   
   Ctr=1;
   Current=START;
   if (Current==NULL)
	printf("The Single/Singly Linked List is EMPTY!!!");
   else
     do{
	 printf("Node %d Content:\n",Ctr);
	 printf("\tData => %d\n",Current->data);
	 Current=Current->next;
	 Ctr++;
     }while (Current!=NULL);
 free(START);
 Current=START=NULL;
 getch();
 return(0);
	   }





