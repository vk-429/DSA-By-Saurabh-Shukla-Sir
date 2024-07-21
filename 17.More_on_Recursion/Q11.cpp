#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll gcd(ll p,ll q)
{
    ll temp;
    while((p%q)!=0)
    {
        temp=p;
        p=q;
        q=temp%q;
    }
    return q;
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll x,y,k;
	    cin>>x>>y>>k;
	    ll a,ans;
        for(int i=0;i<k;i++)
        {
            if(x>y)
            x=gcd(x,y);
            else
            y=gcd(y,x);
            if(x>y)
            x=(x*y)/gcd(x,y);
            else
            y=(x*y)/gcd(y,x);
            cout<<x<<" "<<y<<"\n";
        }
	    cout<<(x+y)<<"\n";
	}
	return 0;
}
