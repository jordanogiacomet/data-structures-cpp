#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool CheckBalancedParentheses(char *exp);

int main(void)
{   
    const int MAX = 100;
    char expression[MAX];
    cout << "Enter a expression: ";
    cin.getline(expression, MAX);

    if(CheckBalancedParentheses(expression))
    {
        cout << "The expression " << expression << " is balanced.\n";
    }
    else
    {
        cout << "The expression " << expression << " is not balanced.\n";
    }
}

bool CheckBalancedParentheses(char *exp)
{
    int length = strlen(exp);
    stack<char> S; 
    for(int i = 0; i < length; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            S.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(S.empty())
            {
                return false;
            }
            char top = S.top();
            S.pop();

            if((exp[i] == ')' && top!= '(') ||
               (exp[i] == ']' && top!= '[') ||
               (exp[i] == '}' && top!= '{'))
            {
                return false;
            }
        }
    }
    return S.empty();
}


