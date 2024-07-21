#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l1;
    list<int> l2={50,10,40,20,30};
    l1.assign({10,20,30});
    //l1.assign(2,5);
    cout<<l2.back()<<"\n";
    cout<<l2.front()<<"\n";
    //l2.clear();
    cout<<l2.size()<<"\n";
    // l2.emplace_back(80);
    // l2.emplace_front(15);
    for(auto& x:l1)
        cout<<x<<" ";
    cout<<"\n";
    for(auto& x:l2)
        cout<<x<<" ";
    cout<<"\n";

    list<int>::iterator it=l2.begin();
    while(*it!=40)
        it++;
    it++;
    l2.insert(it,{100,200});
    it=l2.begin();
    list<int>::iterator it1,it2;
    it1=++it;
    ++it;
    ++it;
    it2=++it;
    for(it=l2.begin();it!=l2.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    l2.erase(it1,it2);
    for(it=l2.begin();it!=l2.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    l2.merge(l1);
    for(it=l2.begin();it!=l2.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    return 0;
}