#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

//GROUP 1 - BSCS 1-1

using namespace std;

// Function to move cursor to the specified position on the console window
void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct node {
    node *prev;
    int data;
    node *next;
};

// Function to traverse double linked list (HEAD TO TAIL)
void Traverse(node *head) {
    node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Function to intraverse double linked list (TAIL TO HEAD)
void Intraverse(node *tail) {
    while (tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
}

// Function to add nodes to created double linked list
node *AddToEmpty(node *head, int data) {
    node *temp = new node;

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

// Function to add nodes at the end of created double linked list
void AddAtTail(node** head, int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to create whole double linked list
node* CreateList() {
    int numNode, data, i;

    cout << "\nEnter the number of nodes: ";
    cin >> numNode;

    // Only applies to first prompt of choice 1
    if (numNode == 0) {
        cout << "No double linked list created.\n";
        return NULL;
    }

    cout << "Enter data for node 1: ";
    cin >> data;

    node* head = new node;
    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    for (i = 1; i < numNode; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        AddAtTail(&head, data);
    }

    return head;
}

int main() {
    node *head = NULL, *tail = NULL;
    node *ptr;
    int choice, data;
    char choice2;

    do {
        system("cls"); // To clear the console window

        // Display main menu and prompt the user to input their choice
        gotoxy(60,1);
        cout << "=== MAIN MENU ===" << endl;
        gotoxy(35,4);
        cout << "1: Creation Double Linked List" << endl;
        gotoxy(35,6);
        cout << "2: Traverse from top to bottom" << endl;
        gotoxy(35,8);
        cout << "3: Traverse from bottom to top" << endl;
        gotoxy(35,10);
        cout << "4: Exit" << endl << endl;
        gotoxy(35,12);
        cout << "Enter your option: ";
        cin >> choice; 

switch (choice) {
    case 1: //Create the double linked list
        if (head != NULL) {
            //If the list is already created, ask if the user wants to add more nodes
            cout << "\nDouble linked list already created. Do you want to add more nodes? (Y/N): ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                //If the user chooses to add more nodes, ask to input data and call AddAtTail function
                cout << "Enter data for new node: ";
                cin >> data;
                AddAtTail(&head, data);
                ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
            } else {
                break;
            }
        } else {
            //If there is no list created yet, CreateList function is called
            head = CreateList();
            ptr = head;
        }
        break;

    case 2: //Traverse the double linked list (From HEAD to TAIL)
        ptr = head;
        if (ptr == NULL) {
            cout << "\nThere is no double linked list to traverse! Please create one first.";
            break;
        }
        cout << "\nTraversed linked list: ";
        Traverse(head);
        break;

    case 3: //Intraverse the double linked list (From TAIL to HEAD)
        if (head == NULL) {
            cout << "\nThere is no double linked list to intraverse! Please create one first.";
            break;
        }
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        tail = ptr;
        cout << "\nIntraversed linked list: ";
        Intraverse(tail);
        break;

    case 4: //Exit the program
        exit(0);

    default:
        // Display an error message if an invalid choice is entered
        cout << "\nInvalid choice! Please try again.";
        break;
}

cout << "\n\n";
system("pause"); //Holds the console window and displays "Press any key to continue..."

} while (choice != 4);

return 0;
}
