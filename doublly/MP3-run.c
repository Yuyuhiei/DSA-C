#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//struct
struct Node{
	int empNum;
	char empName[30];
	struct Node* next;
};

//creation of node
struct Node* createNode(int empNum, const char* empName){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->empNum = empNum;
	strcpy(newNode->empName, empName);
	newNode->next = NULL;
	return newNode;
}
	
//insertion of node at the beginning
void insertNode(struct Node** head, int empNum, const char* empName){
	struct Node* newNode = createNode(empNum, empName);
	newNode->next = *head;
	*head = newNode;
	printf("Noded added successfully!\n");
}

//deletion of node at the beginning
void deleteNode(struct Node** head){
	if (*head == NULL){
		printf("The list is empty!\n");
		return;
	}
	
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
	printf("Node deleted successfully!\n");
}

//traversal of nodes in the list
void traverse(struct Node* head){
	if (head == NULL){
		printf("The list is empty!\n");
		return;
	}
	
	printf("\nEmployee List:\n");
	while (head != NULL){
		printf("Employee Number: %d, Employee Name: %s\n", head->empNum, head->empName);
		head = head->next;
	}
}


	
	int main(){
		struct Node* head = NULL;
		int choice;
		int empNum;
		char empName[30];
		
		while(1){
			printf("\nLinked List Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getch();
		
		switch(choice){
			case 1: 
				printf("Employee Number: ");
				scanf("%d", &empNum);
				printf("Employee Name: ");
				scanf("%s", empName);
				insertNode(&head, empNum, empName);
				traverse(head);
				break;
			case 2:
				deleteNode(&head);
				traverse(head);
				break;
			case 3:
				traverse(head);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("invalid input!");
			}
	printf("Press any key to continue...");
	getchar();
	getchar();
}
return 0;
}
	





	
