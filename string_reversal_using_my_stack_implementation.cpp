#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
private: 
    char A[101];
    int top = -1; 
public: 
    void Push(int value);
    void Pop();
    char Top();
    bool IsEmpty();
};

void Reverse(char c[], int length);

int main()
{
    char C[51];
    printf("Enter a string: ");
    fgets(C, 51, stdin);

    Reverse(C, strlen(C));
    cout << "Output = " << C;
}

void Reverse(char c[], int length)
{
    Stack* stack = new Stack();
    for(int i = 0; i < length - 1; i++)
    {
        stack->Push(c[i]);
    }
    for(int i = 0; i < length - 1; i++)
    {
        c[i] = stack->Top();
        stack->Pop();
    }
}

void Stack::Push(int value)
{
    top++;
    this->A[top] = value;
}

void Stack::Pop()
{
    if(IsEmpty())
    {
        cout << "Error: stack is empty\n";
        return;
    }
    top--;
}

char Stack::Top()
{   
    return A[top];
}

bool Stack::IsEmpty()
{   
    if(top == -1)
    {
        return true;
    }
    return false;
}
