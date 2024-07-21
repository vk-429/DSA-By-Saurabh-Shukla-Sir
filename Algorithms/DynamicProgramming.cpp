#include<iostream>
using namespace std;
int dp[20];
int fib(int n)
{
    if(dp[n]!=-1)
        return dp[n];
    if(n==0||n==1)
        dp[n]=n;
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}

int fib1(int n)
{
    int dp[n];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<20;i++)
        dp[i]=-1;
    cout<<fib1(n)<<"\n";
    return 0;
}