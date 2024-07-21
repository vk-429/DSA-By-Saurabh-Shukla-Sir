#include<iostream>
using namespace std;

class Functor
{
    public:
        bool operator()(int a,int b){ return a>b;}
};
int main()
{
    Functor F;
    cout<<F(3,4)<<"\n";
    return 0;
}