#include<iostream>
using namespace std;

void printNR(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        printNR(n-1);
    }
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    printNR(n);
    return 0;
}