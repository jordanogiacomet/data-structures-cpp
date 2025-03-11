#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    struct Node* next;
};

Node *head; // Global

void Insert(int value); // Insert an integer at end of list
void Print(); // Print all elements in the list
void Reverse();

int main(void)
{
    head = NULL; // Empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5

    Print();
    Reverse();
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

void Reverse()
{   
    if(head == NULL)
    {
        return;
    }
    stack<Node*> S;
    Node* temp = head;
    while(temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top(); head = temp;
    S.pop();
    while(!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

