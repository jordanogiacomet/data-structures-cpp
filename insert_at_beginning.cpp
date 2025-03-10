#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data; 
    struct Node* next;
};

void Insert(Node** head, int value);
void Print(Node* head);

int main(void)
{   
    Node* head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);

    Print(head);

    return 0;
}

void Insert(Node** head, int value)
{
    struct Node* temp = (Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(*head != NULL) temp->next = *head;
    *head = temp; 
}

void Print(Node* head)
{   
    printf("List is: ");
    while(head != NULL)
    {
        printf("%i ", head->data);
        head = head->next;
    }
    printf("\n");
}