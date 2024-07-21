#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    array<float,5> arr = {1.1,2.2,3.3,4.4,5.5};
    float sum = 0.0, avg = 0.0;
    sum = accumulate(arr.begin(),arr.end(), 0.0);
    avg = sum/5.0;
    cout<<"Average = "<<avg<<"\n";
    return 0;
}