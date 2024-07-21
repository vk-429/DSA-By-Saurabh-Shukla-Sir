#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

int precedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    return 0;
}

string infixtopostfix(const string &infix)
{
    string postfix = "";
    stack<char> operators;
    int i;
    for(char c : infix)
    {
        if(isalnum(c))
            postfix+=c;
        else if(c=='(')
            operators.push(c);
        else if(c==')')
        {
            while(!operators.empty() && operators.top() != '(')
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
    string s;
    cout<<"Enter a Infix Expression :- ";
    cin>>s;
    cout<<"Postfix Expression is Given as : "<<infixtopostfix(s)<<endl;
    return 0;
}