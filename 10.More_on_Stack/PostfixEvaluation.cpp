#include<iostream>
#include<stack>
using namespace std;

int evaluate(int o1,int o2,char op)
{
    if(op == '/')
    {
        if(o2==0)
        {
            cout<<"Division by Zero Error!\n";
            exit(0);
        }    
        return o1/o2;
    }
    if(op == '*')
        return o1*o2;
    if(op == '+')
        return o1+o2;
    return o1-o2;
}

int evaluate_postfix(string& postfix)
{
    int ans = 0;
    stack<int> operands;
    for(char c:postfix)
    {
        if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            if(operands.size()<2)
            {
                cout<<"Invalid Postfix Expression\n";
                return INT_MIN;
            }
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = evaluate(operand1,operand2,c);
            operands.push(result);
        }
        else if(isalnum(c))
            operands.push(c-'0');
    }
    if(operands.size() == 1)
        ans = operands.top();
    return ans;
}

int main()
{
    string postfix;
    cout<<"Enter a postfix Expression : ";
    cin>>postfix;
    int ans = evaluate_postfix(postfix);
    cout<<"Ans = "<<ans<<"\n";
    return 0;
}