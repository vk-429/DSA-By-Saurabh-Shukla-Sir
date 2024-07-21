#include<iostream>
#include<array>
using namespace std;


template<typename X>
void printArray(X p,int size)
{
    for(auto &x:p)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    array<int,5> A{3,4,6,9,12};
    array<char,5> B{'A','E','I','O','U'};
    array<double,5> C{2.2,4.5,3.6,7.9,8.2};
    printArray(A,5);
    printArray(B,5);
    printArray(C,5);
    return 0;
}