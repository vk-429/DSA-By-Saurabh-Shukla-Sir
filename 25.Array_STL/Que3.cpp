#include<iostream>
#include<array>
using namespace std;

void input(array<int,10>& arr)
{
    cout<<"Enter Elements :-\n";
    for(int i=0;i<10;i++)
        cin>>arr[i];
}

int find_greatest(array<int,10>& arr)
{
    int largest = INT_MIN;
    for(int i=0;i<10;i++)
    {
        if(arr[i]>largest)
            largest = arr[i];
    }
    return largest;
}

int main()
{
    array<int,10> arr ;
    input(arr);
    int greatest = find_greatest(arr);
    cout<<"Largest Element = "<<greatest<<"\n";
    return 0;
}