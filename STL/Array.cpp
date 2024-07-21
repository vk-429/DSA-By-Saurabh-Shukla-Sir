#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int,3> a1={10,20,30};
    array<int,4> a2;
    array<int,3> a3=a1;//size of both the arrays should be same
    array<int,5> a4{11,22,33};//remaining values will remain zero
    array<int,5> a5{50,70,20,30,40};
    int i;
    try
    {
        for(int i=0;i<5;i++)
            cout<<a5.at(i)<<"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    a1[3]=50;//no error no bound checking
    cout<<a1[1]<<"\n";
    //Implicit iterator
    for(auto &x:a5)
        cout<<x<<" ";
    cout<<"\n";
    array<int,5>::iterator it1=a5.begin();
    *(it1+2)=500;
    for(it1=a5.begin();it1!=a5.end();it1++)
        cout<<*it1<<" ";
    array<int,5>::reverse_iterator it2=a5.rbegin();
    array<int,5>::const_iterator it3=a5.cbegin();
    //*it=100;//read only
    cout<<"\n";
    array<int,5>::const_reverse_iterator it4;//=a5.crbegin();
    for(it4=a5.crbegin();it4!=a5.crend();it4++)
        cout<<*it4<<" ";
    cout<<"\n";
    //similarly 4 type of reverse iterator
    cout<<a5.front()<<"\n";
    cout<<a5.back()<<"\n";
    cout<<a5.empty()<<"\n";
    int *p=a5.data();
    cout<<*p<<"\n";
    cout<<a5.size()<<"\n";
    array<int,5> a6={3,6,9,1,4};
    a5.swap(a6);
    for(auto &x:a5)
        cout<<x<<" ";
    cout<<"\n";
    for(auto &x:a6)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}