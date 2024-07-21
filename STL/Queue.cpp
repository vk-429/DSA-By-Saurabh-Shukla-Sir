#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<deque>
using namespace std;

int main()
{
    // queue <int,vector<int>> q1;
    // queue <int,list<int>> q1;
    queue <int,deque<int>> q1;
    q1.push(20);
    q1.push(40);
    q1.push(70);
    q1.push(50);
    cout<<q1.front()<<" "<<q1.back()<<"\n";
    // while(!q1.empty())
    // {
    //     cout<<q1.front()<<" ";
    //     q1.pop();// Error : class std::queue<int, std::vector<int> >' 
    //has no member named 'pop_front'; did you mean 'front'?
    // }
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<"\n";
    return 0;
}