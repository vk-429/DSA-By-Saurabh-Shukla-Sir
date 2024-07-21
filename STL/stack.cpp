#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#include<forward_list>
using namespace std;

int main()
{
    stack<int> s1;//based on deque
    stack<int,vector<int>> s2;//based on vector
    stack<int,queue<int>> s3;
    stack<int,list<int>> s4;
    stack<int,forward_list<int>> s5;
    stack<int,priority_queue<int>> s6;
    s6.push(30);
    s2.push(20);
    s2.push(100);
    s2.push(50);
    cout<<s2.size()<<"\n";
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<"\n";
    return 0;
}