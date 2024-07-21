#include<iostream>
using namespace std;

void printOdd(int n)
{
    if(n>0)
    {
        cout<<(n*n)<<" ";
        printOdd(n-1);
    }
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    printOdd(n);
    return 0;
}