#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

string InfixToPostfix(string exp);
int getPrecedence(char op);
bool HasHigherPrec(char op1, char op2);

int main(void)
{

    string expression;
    cout << "Enter a expression in infix notation: ";
    getline(cin, expression);

    string res = InfixToPostfix(expression);

    cout << "Expression converted to postfix notation: " << res << '\n';
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

bool HasHigherPrec(char op1, char op2)
{
    return getPrecedence(op1) >= getPrecedence(op2);
}

string InfixToPostfix(string exp)
{
    stack<char> S;
    string res;
    int length = exp.size();
    for (size_t i = 0; i < length; i++)
    {
        if (exp.at(i) == ' ')
        {
            continue;
        }
        if (isalpha(exp.at(i)))
        {
            res = res + ' ' + exp.at(i);
        }
        else
        {
            while (!S.empty() && HasHigherPrec(S.top(), exp.at(i)))
            {
                res = res + ' ' +  S.top();
                S.pop();
            }
            S.push(exp.at(i));
        }
    }
    while (!S.empty())
    {
        res = res + ' ' + S.top();
        S.pop();
    }
    return res;
}
