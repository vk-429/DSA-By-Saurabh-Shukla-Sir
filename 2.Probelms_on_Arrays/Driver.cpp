#include "Que1a.cpp"
#include<iostream>
using namespace std;
int main()
{
    ExtendedArray obj(10);
    obj.Append(20);
    obj.Append(70);
    obj.Append(30);
    obj.Append(10);
    cout<<"\nGreatest element is "<<obj.greatest()<<endl;
    obj.sort();
    obj.PrintArray();
    cout<<"\nSmallest element is "<<obj.smallest()<<endl;
    cout<<obj.search(2)<<"\n";
    cout<<"Sum of elements = "<<obj.sum()<<endl;
    cout<<"Average = "<<obj.average()<<endl;
    obj.rotateright();
    obj.PrintArray();
    obj.Append(20);
    obj.Append(70);
    cout<<"\n";
    obj.PrintArray();
    obj.removeDuplicate();
    cout<<"\n";
    obj.PrintArray();
    obj.swap(2,3);
    cout<<"\n";
    obj.PrintArray();
    return 0;
}