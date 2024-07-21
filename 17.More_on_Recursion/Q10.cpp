#include<iostream>
using namespace std;

double calcpowXY(double x,double y)
{
    if(y==0)
        return 1;
    if(y>0)
        return x*(calcpowXY(x,y-1));
    return (1/x)*(calcpowXY(x,y+1));
}
int main()
{
    double x,y;
    cout<<"Enter x and y : ";
    cin>>x>>y;
    cout<<calcpowXY(x,y)<<"\n";
    return 0;
}