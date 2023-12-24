#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//GROUP 1 - BSCS 1-1

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

//Function to traverse double linked list (HEAD TO TAIL)
void Traverse(struct node *head) {
    struct node *current = head;
	
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

//Function to intraverse double linked list (TAIL TO HEAD)
void Intraverse(struct node *tail) {
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
}

//Function to add nodes to created double linked list
struct node *AddToEmpty(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

//Function to add nodes at the end of created double linked list
void AddAtTail(struct node** head, int data) {
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

//Function to create whole double linked list
struct node* CreateList() {
    int numNode, data, i;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &numNode);

	//Only applies to first prompt of choice 1
    if (numNode == 0) {
        printf("No double linked list created.\n");
        return NULL;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    struct node* head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    for (i = 1; i < numNode; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        AddAtTail(&head, data);
    }

    return head;
}

int main(int argc, char *argv[]) {
	struct node *head = NULL, *tail = NULL;
	struct node *ptr;
	int choice, data;
	char choice2;
	
	do {
		system("cls"); // To clear the console window
	    //Display main menu and prompt the user to input their choice
		gotoxy(60,1);
		printf("=== MAIN MENU ===");
	    gotoxy(35,4);
	    printf("1: Creation Double Linked List\n");
	    gotoxy(35,6);
	    printf("2: Traverse from top to bottom\n");
	    gotoxy(35,8);
	    printf("3: Traverse from bottom to top\n");
	    gotoxy(35,10);
		printf("4: Exit\n\n");
		gotoxy(35,12);
	    printf("\nEnter your option: ");
	    scanf("%d", &choice);
	    
	    switch (choice) {
	    	case 1: //Create the double linked list
	        if (head != NULL) {
		        //If the list is already created, ask if the user wants to add more nodes
		        printf("\nDouble linked list already created. Do you want to add more nodes? (Y/N): ");
		        scanf(" %c", &choice2);
		        if (choice2 == 'Y' || choice2 == 'y') {
		            //If the user chooses to add more nodes, ask to input data and call AddAtTail function
		            printf("Enter data for new node: ");
		            scanf("%d", &data);
		            AddAtTail(&head, data);
		            ptr = head;
		            while (ptr->next != NULL) {
		                ptr = ptr->next;
		            }
		        } 
				else {
		            break;
		        }
		    } 
				else {
			        //If there is no list created yet, CreateList function is called
			        head = CreateList();
			        ptr = head;
		    }
		    break;
		    
		    case 2: //Traverse the double linked list (From HEAD to TAIL)
		        ptr = head;
		        if (ptr == NULL) {
		            printf("\nThere is no double linked list to traverse! Please create one first.");
		            break;
		        }
		        printf("\nTraversed linked list: ");
		        Traverse(head);
		        break;
		        
		    case 3: //Intraverse the double linked list (From TAIL to HEAD)
		        if (head == NULL) {
		            printf("\nThere is no double linked list to intraverse! Please create one first.");
		            break;
		        }
		        ptr = head;
		        while (ptr->next != NULL) {
		            ptr = ptr->next;
		        }
		        tail = ptr;
		        printf("\nIntraversed linked list: ");
		        Intraverse(tail);
		        break;
		        
		    case 4: //Exit the program
		        exit(0);
		        
		    default:
		        // Display an error message if an invalid choice is entered
		        printf("\nInvalid choice! Please try again.");
		        break;
		}
		printf("\n\n");
    	system("pause"); //Holds the console window and displays "Press any key to continue..."
	} while (choice !=4);
	return 0;
}