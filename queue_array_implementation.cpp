#include <stdio.h>
#include <stdlib.h>
#include <iterator> 
#include <iostream>
using namespace std;

int A[10];
int front = -1;
int rear = -1;

void Enqueue(int value);
int Dequeue();
bool IsEmpty();
bool IsFull();
int Front();

int main(void)
{
    Enqueue(2);
    Enqueue(3);

    cout << Front() << '\n';

    cout << Dequeue() << '\n';

    Enqueue(5);

    cout << Dequeue() << '\n';

    cout << Front() << '\n';
}

bool IsEmpty()
{
    if(rear == -1 && front == -1)
    {
        return true;
    }
    return false;
}

bool IsFull()
{
    if((rear + 1) % size(A) == front)
    {
        return true;
    }
    return false;
}

void Enqueue(int value)
{
    if(IsFull())
    {
        cout << "Queue is full.\n";
        return;
    }
    if(IsEmpty())
    {
        rear = 0;
        front = 0;
        A[front] = value;
        return;
    }
    else
    {
        rear = (rear + 1) % size(A);
    }
    A[rear] = value;
}

int Dequeue()
{   
    int res;
    if(IsEmpty())
    {
        cout << "Queue is empty.\n";
        EXIT_FAILURE;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        EXIT_FAILURE;
    }
    else
    {   
        res = A[front];
        front = (front + 1) % size(A);
    }
    return res;
}

int Front()
{
    if(IsEmpty())
    {
        cout << "Queue is empty.\n";
        EXIT_FAILURE;
    }
    return A[front];
}


