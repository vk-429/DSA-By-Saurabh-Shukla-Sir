#include<iostream>
#include<math.h>
using namespace std;
void TOH(int n,char a,char b,char c)
{
    if(n==0)
        return;
    else if(n==1)
        cout<<a<<" -> "<<c<<"\n";
    else if(n==2)
    {
        cout<<a<<" -> "<<b<<"\n";
        cout<<a<<" -> "<<c<<"\n";
        cout<<b<<" -> "<<c<<"\n";
    }
    else
    {
        if(n%2==0)
        {
            b=b+c;
            c=b-c;
            b=b-c;
        }
        int num=pow(2,n-3);
        int n1=num+1;
        for(int i=num;i>=1;i--)
        {        
            cout<<a<<" -> "<<c<<"\n";
            cout<<a<<" -> "<<b<<"\n";
            cout<<c<<" -> "<<b<<"\n";
            cout<<a<<" -> "<<c<<"\n";
            cout<<b<<" -> "<<a<<"\n";
            cout<<b<<" -> "<<c<<"\n";
            cout<<a<<" -> "<<c<<"\n";
            if(i>1)
            {
                if(i%2==0)
                    cout<<a<<" -> "<<b<<"\n";
                else
                {
                    if(n1>4&&n1%4==1)
                        cout<<a<<" -> "<<b<<"\n";
                    else
                        cout<<b<<" -> "<<a<<"\n";
                }
                a=a+c;
                c=a-c;
                a=a-c;
                b=b+c;
                c=b-c;
                b=b-c;
            }
            cout<<"\n\n\n\n";
            n1=(n1+2)/2;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of plates : ";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}