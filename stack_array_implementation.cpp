#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int value);
void Pop();
bool IsEmpty();
int Top();


int main(void)
{
    Push(1);
    Push(2);

    printf("Top: %d\n", Top());
    Pop();
    printf("Top: %d\n", Top());
}

void Push(int value)
{  
    if(top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = value;
}

void Pop()
{
    if(IsEmpty())
    {
        printf("Error: stack is empty\n");
        return;
    }
    top--;
}

bool IsEmpty()
{
    if(top == -1)
    {
        return true;
    }
    return false;
}

int Top()
{   
    return A[top];
}
