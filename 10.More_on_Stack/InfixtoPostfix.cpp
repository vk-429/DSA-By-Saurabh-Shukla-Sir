#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    return 0;
}

string infix_to_postfix(string& infix)
{
    string postfix;
    stack<char> operators;
    for(char c: infix)
    {
        if(isalnum(c))
            postfix+=c;
        else if(c == '(')
            operators.push(c);
        else if(c == ')')
        {
            while(!operators.empty()  && operators.top() != '(')
            {
                postfix+=operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while(!operators.empty() && precedence(c) <= precedence(operators.top()))
            {
                postfix+=operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while(!operators.empty())
    {
        postfix+=operators.top();
        operators.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter an Infix Expression : ";
    cin>>infix;
    string postfix = infix_to_postfix(infix);
    cout<<"Postfix Expression : "<<postfix<<"\n";
    return 0;
}