#include<iostream>
#include<set>
using namespace std;

int main()
{
    multiset<int> s1={10,20,10,40,30,20,40,10,20,10};
    for(auto &x:s1)
        cout<<x<<" ";
    cout<<"\n";
    cout<<s1.count(10)<<"\n";
    return 0;
}