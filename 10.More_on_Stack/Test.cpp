#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Default precedence for '('
}

string infixToPostfix(const string& infix) 
{
    string postfix = "";
    stack<char> operators;

    for (char c : infix) 
    {
        if (isalnum(c)) 
        { // Operand
            postfix += c;
        } 
        else if (c == '(') 
        {
            operators.push(c);
        } 
        else if (c == ')') 
        {
            while (!operators.empty() && operators.top() != '(') 
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop and discard the '('
        } 
        else 
        { // Operator
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) 
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) 
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() 
{
    string infix;
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << "\n";
    cout << "Postfix: " << postfix << "\n";
    return 0;
}
