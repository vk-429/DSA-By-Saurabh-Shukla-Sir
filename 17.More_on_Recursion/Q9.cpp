#include<iostream>
using namespace std;

int calcHCF(int x,int y)
{
    if(x%y==0)
        return y;
    return calcHCF(y,x%y);
}
int main()
{
    int x,y;
    cout<<"Enter Two Numbers : ";
    cin>>x>>y;
    if(x<y)
    {
        x=x+y;
        y=x-y;
        x=x-y;
    }
    cout<<"HCF = "<<calcHCF(x,y);
    return 0;
}