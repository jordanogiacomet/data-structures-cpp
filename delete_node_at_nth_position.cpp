#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

Node *head; // Global

void Insert(int value); // Insert an integer at end of list
void Print(); // Print all elements in the list
void Delete(int position); // Delete node at position n
void DeleteValue(int value);


int main(void)
{
    head = NULL; // Empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5

    Print();

    int position;
    printf("Enter a value: ");
    scanf("%d", &position);
    DeleteValue(position);

    Print();

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

void Print()
{   
    printf("List: ");
    for(Node* temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->value);
    }
    printf("\n");
}

void Delete(int position)
{
    Node* temp1 = head;
    if(position == 1)
    {
        head = temp1->next; // head now points to second node
        free(temp1); // free the memory for n node
        return;
    }
    for(int i = 0; i < position - 2; i++)
    {
        temp1 = temp1->next;  // temp1 points to n-1 node
    }
    Node* temp2 = temp1->next; // node itself
    temp1->next = temp2->next; // n+1 node
    free(temp2); // Free the memory for temp2

    // Esse cenário funciona para casos que temos um nodo antes
    // E casos que temos ou não um nodo depois.
}

void DeleteValue(int value)
{
    Node* temp1 = head;
    if(head->value == value)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    while(temp1->next != NULL && temp1->next->value != value)
    {
        temp1 = temp1->next;
    }
    if(temp1->next == NULL)
    {
        return;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}