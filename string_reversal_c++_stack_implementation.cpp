#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

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
   stack<char> S;
   for(int i = 0; i < length - 1; i++)
   {
        S.push(c[i]);
   }
   for(int i = 0; i < length - 1; i++)
   {
        c[i] = S.top();
        S.pop();
   }
}

