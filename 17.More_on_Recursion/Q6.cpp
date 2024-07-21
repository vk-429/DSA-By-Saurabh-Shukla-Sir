#include<iostream>
using namespace std;

int sumDigit(int n)
{
    if(n==0)
        return 0;
    return (n%10)+sumDigit(n/10);
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Sum of digits = "<<sumDigit(n)<<"\n";
    return 0;
}