#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<int,string> m1={{1,"Bhopal"},{2,"Indore"},{3,"Pune"}};
    map<int,string> m2;
    m2.emplace(1,"Patna");
    m2.emplace(2,"Varanasi");
    m2.insert({{4,"Bhopal"},{5,"Indore"},{3,"Pune"}});
    cout<<m2.at(2)<<"\n";
    m2.erase(1);
    m2.erase(++m2.begin());
    //m2.clear();
    for(auto &x:m2)
        cout<<x.first<<" "<<x.second<<"\n";
    
    cout<<m1[1]<<"\n";
    cout<<m1[3]<<"\n";
    cout<<m1.at(2)<<"\n";
    //cout<<m1.at(5)<<"\n";
    map<int,string>::iterator it;
    for(it=m1.begin();it!=m1.end();it++)
        cout<<it->first<<" "<<it->second<<"\n";
    //map<map<int,string>,string> details{{{1,"Shiva"},"Varanasi"},{{2,"Vivek"},"Agartala"}};
    
    return 0;
}