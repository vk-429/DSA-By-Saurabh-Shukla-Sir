#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int,5> arr = {1,2,3,4,5};
    array<int,5>::reverse_iterator it;
    it = arr.rbegin();
    for(;it!=arr.rend();it++)
        cout<<*it<<" ";
    cout<<"\n";
    return 0;
}