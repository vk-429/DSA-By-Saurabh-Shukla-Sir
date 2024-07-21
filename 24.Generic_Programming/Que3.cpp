#include<iostream>
#include<array>
using namespace std;

template<typename arg_type, size_t size>
void sort(array<arg_type, size>& arr)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
    }
}

template<typename X>
void printArray(X p,int size)
{
    for(auto &x:p)
        cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    array<int,5> A{13,4,6,10,12};
    array<char,5> B{'E','I','U','A','O'};
    array<double,5> C{2.2,1.5,3.6,4.9,0.2};
    cout<<"Before Sorting\n";
    printArray(A,5);
    printArray(B,5);
    printArray(C,5);
    cout<<"\nAfter Sorting\n";
    sort(A);
    sort(B);
    sort(C);
    printArray(A,5);
    printArray(B,5);
    printArray(C,5);
    return 0;
}