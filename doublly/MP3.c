#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//strcuture for a node
struct Node{
	int empNum;
	char empName[100];
	struct Node* next;
};

//Function to create a new node 
struct Node* createNode(int empNum, const char* empName){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->empNum = empNum;
	strcpy(newNode->empName, empName);
	newNode->next = NULL;
	return newNode;
}

//Function to insert a node at the berginning of the linnked list
void insertNode(struct Node** head, int empNum, const char* empName){
	struct Node* newNode = createNode(empNum, empName);
	newNode->next = *head;
	*head = newNode;
	printf("Node inserted successfully.\n"); 
}

//Function to delete the first node of the linked list
void deleteNode(struct Node** head){
	if(*head == NULL){
		printf("List is already empty.\n");
		return;
	}
	
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
	printf("node deleted successfully.\n");
}

//Function to traverse and display the linked list
void displayList(struct Node* head){
	if (head == NULL){
		printf("list is empty.\n");
		return;
	}
	
	printf("employee List:\n");
	while (head != NULL){
		printf("Employee Number: %d, Name: %s\n", head->empNum, head->empName);
		head = head->next;
	}
}

int main(){
	
	struct Node* head = NULL;
	int empNum;
	char empName[100];
	
	int choice;
	while (1){
		printf("\nLinked List Operations:\n");
		printf("1. Insert Node\n");
		printf("2. Delete Node\n");
		printf("3. Display List\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getch();
		
		switch (choice){
			case 1:
				printf("Enter employee number: ");
				scanf("%d", &empNum);
				printf("Enter the employee name: ");
				scanf("%s", empName);
				insertNode(&head, empNum, empName);
				displayList(head);
				break;
			case 2:
				deleteNode(&head);
				displayList(head);
				break;
			case 3:
				displayList(head);
				break;
			case 4:
				printf("Exiting...\n");
				exit(0);
			default:
				printf("Invalid choice. Please try again.\n");
		}
		printf("\nPress enter to continue...");
		getchar(); //newline
		getchar(); //enter press
	}
	
	return 0;
}
