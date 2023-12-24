#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>
#include <malloc.h>

//declaration of structure of node
struct node {
    int value;
    struct node* next;
};
typedef struct node node_t;


//prints the list of nodes
void printlist(node_t *head){
    node_t *temporary = head;

    while (temporary !=NULL){
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

//creation of new node function 
node_t *create_new_node(int value){
    node_t *result = (node_t *)malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

int main() {
    node_t *head;
    node_t *tmp;

    tmp = create_new_node(32);
    head = tmp;
    tmp = create_new_node(8);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(34);
    tmp->next = head;
    head = tmp;

    printlist(head);
    return 0;
}
