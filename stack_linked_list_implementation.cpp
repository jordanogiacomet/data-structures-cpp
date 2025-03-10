#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *link;
};

Node *top = NULL;

void Push(int value);
void Pop();
Node *Top();
bool IsEmpty();
Node *GetNewNode(int value);

int main(void)
{
    Push(1);
    Push(2);
    Push(3);
    Pop();

    Node* temp = Top();

    printf("Top: ");
    printf("%d\n", temp->value);
}

Node *GetNewNode(int value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->link = NULL;

    return newNode;
}

bool IsEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

void Push(int value)
{
    Node *newNode = GetNewNode(value);
    if (IsEmpty())
    {
        top = newNode;
        return;
    }
    newNode->link = top;
    top = newNode;
}

void Pop()
{
    if (IsEmpty())
    {
        printf("Error: stack is empty\n");
        return;
    }
    Node *temp = top;
    top = temp->link;
    free(temp);
}

Node *Top()
{
    if (IsEmpty())
    {
        printf("Error: stack is empty\n");
        return NULL;
    }
    return top;
}
