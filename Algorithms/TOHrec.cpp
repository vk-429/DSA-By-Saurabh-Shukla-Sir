#include<iostream>
using namespace std;

void TOH(int n,char beg,char aux,char end)
{
    static int i;
    if(n>0)
    {
        TOH(n-1,beg,end,aux);
        cout<<++i<<") "<<beg<<" -> "<<end<<"\n";
        TOH(n-1,aux,beg,end);
    }
}
int main()
{
    int n;
    cout<<"Enter no. of plates : ";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}