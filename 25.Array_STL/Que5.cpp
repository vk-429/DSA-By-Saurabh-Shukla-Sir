#include<iostream>
#include<array>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    array<int,10> arr = {10,3,7,19,24,13};
    //int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr.begin(),arr.end());
    for(auto& x:arr)
        cout<<x<<" ";
    cout<<"\n";
    cout<<INT_MIN<<"\n";
    return 0;
}