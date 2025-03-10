#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

Node *head; // Global

void Insert(int value); // Insert an integer at end of list
void Print(struct Node* head); // Print all elements in the list
void ReversePrint(struct Node* head);

int main(void)
{
    head = NULL; // Empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5

    Print(head);
    printf("\n");

    ReversePrint(head);
    printf("\n");

    return 0;
}

void Insert(int value)
{
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->value = value;
    temp1->next = NULL;

    if(head == NULL)
    {
        head = temp1;
        return;
    }

    Node* temp2 = head;

    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void Print(struct Node* head)
{   
    if(head == NULL) return; // Exit condition
    printf("%d ", head->value); // Print the node
    Print(head->next); // Recursive call
}

void ReversePrint(struct Node* head)
{
    if(head == NULL) return;
    ReversePrint(head->next);
    printf("%d ", head->value);
}


