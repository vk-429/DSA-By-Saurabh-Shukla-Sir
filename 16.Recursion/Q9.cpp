#include<iostream>
using namespace std;

void printOdd(int n)
{
    if(n>0)
    {
        printOdd(n-1);
        cout<<(n*n*n)<<" ";
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