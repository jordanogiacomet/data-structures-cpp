#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

Node *GetNewNode(int value);
bool IsEmpty();
void Enqueue(int value);
void Dequeue();
int Front();

int main(void)
{
    Enqueue(2);
    Enqueue(3);
    cout << Front() << '\n';
    Dequeue();
    cout << Front() << '\n';
    Dequeue();
    Enqueue(4);
    cout << Front() << '\n';
    Dequeue();
    Dequeue();
}

Node *GetNewNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

bool IsEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    return false;
}

void Enqueue(int value)
{
    Node *temp = GetNewNode(value);
    if (IsEmpty())
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    Node *temp = front;
    if (IsEmpty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

int Front()
{
    if (IsEmpty())
    {
        cout << "Queue is empty.\n";
    }
    return front->data;
}