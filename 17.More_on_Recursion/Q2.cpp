#include<iostream>
using namespace std;

int sumN(int n)
{
    if(n==0)
        return 0;
    return (2*n-1)+sumN(n-1);
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Sum = "<<sumN(n)<<"\n";
    return 0;
}