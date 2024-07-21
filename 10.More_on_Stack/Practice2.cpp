#include<iostream>
#include<stack>
#include <string>
#include <cctype>
#include<climits>
using namespace std;
int value(int a,int b,char c)
{
    if(c=='+')return a+b;
    else if(c=='-')return a-b;
    else if(c=='*')return a*b;
    else 
    {
        if(b==0)
        {
            cout<<"Division by Zero Error!\n";
            exit(0);
        }    
        else return a/b;  
    }
}
int EvaluatePostfix(const string &postfix)
{
    stack<int> operands;
    for(char c : postfix)
    {
        if(isalnum(c))
            operands.push(c-48);
        else if(c=='+' || c=='-' || c=='*' || c=='/')
        {
            int b=operands.top();
            operands.pop();
            int a=operands.top();
            operands.pop();
            int r=value(a,b,c);
            operands.push(r);
        }
    }
    if(operands.size()!=1)
    {
        cout<<"Invalid Postfix Expression\n";
        return INT_MIN;
    }
    return operands.top();
}

int main()
{
    string s;
    cout<<"Enter a Postfix Expression :- ";
    cin>>s;
    cout<<"Ans = "<<EvaluatePostfix(s)<<"\n";
    return 0;
}