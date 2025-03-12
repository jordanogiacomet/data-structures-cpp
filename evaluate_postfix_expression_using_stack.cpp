#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int EvaluatePostfix(char *exp);
int Perform(char exp, int op1, int op2);

int main(void)
{
    const int MAX = 100;
    char expression[MAX];
    cout << "Enter a expression: ";
    cin.getline(expression, MAX);

    int res = EvaluatePostfix(expression);

    cout << "The result is: " << res << "\n";
}

int Perform(char exp, int op1, int op2)
{
    switch (exp)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0)
        {
            fprintf(stderr, "Erro: Divisão por zero.\n");
            exit(EXIT_FAILURE);
        }
        return op1 / op2;
    default:
        fprintf(stderr, "Erro: Operador '%c' inválido.\n", exp);
        exit(EXIT_FAILURE);
    }
}

int EvaluatePostfix(char *exp)
{   
    int res;
    stack<int> S;
    int length = strlen(exp);
    for (int i = 0; i < length; i++)
    {   
        if(exp[i] == ' ')
        {
            continue;
        }
        if(isdigit(exp[i]))
        {
            S.push(exp[i] - '0');
        }
        else
        {
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            res = Perform(exp[i], op1, op2);
            S.push(res);
        }
    }
    return S.top();
}
