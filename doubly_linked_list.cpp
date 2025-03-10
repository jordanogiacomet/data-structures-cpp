#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
};

Node* head;

Node* getNewNode(int value);
void InsertAtHead(int value);
void InsertAtTail(int value);
void Print();
void ReversePrint();
void Delete(int position);

int main(void)
{
    head = NULL;

    InsertAtTail(4);
    InsertAtTail(5);
    InsertAtTail(6);

    Print();
    ReversePrint();

    Delete(1);
    Delete(2);

    Print();
}

Node* GetNewNode(int value)
{
    struct Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void InsertAtHead(int value)
{
    struct Node* node = GetNewNode(value);

    if(head == NULL)
    {
        head = node;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;
}

void InsertAtTail(int value)
{
    Node* node = GetNewNode(value);

    if(head == NULL)
    {
        head = node;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
}

void Print()
{   
    Node* temp = head;
    printf("List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    // Going to last node
    printf("Reverse List: ");
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backwards using prev pointer 
    while(temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void Delete(int position)
{   
    Node* temp = head;
    if(position == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for(int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}