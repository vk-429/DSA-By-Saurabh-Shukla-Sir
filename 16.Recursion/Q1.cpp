#include<iostream>
using namespace std;

void printN(int n)
{
    if(n>0)
    {
        printN(n-1);
        cout<<n<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    printN(n);
    return 0;
}