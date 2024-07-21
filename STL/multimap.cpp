#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    multimap<int,string> m1={{1,"Ravi"},{2,"Nitin"},{1,"Rajesh"}};
    // m1.erase(1);
    for(auto &x:m1)
        cout<<x.first<<" "<<x.second<<"\n";
    cout<<m1.count(1)<<"\n";
    
    return 0;
}