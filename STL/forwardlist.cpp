#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> l1={30,50,10,70,60};
    forward_list<int> l2;
    l2.assign(4,100);
    l2.assign({25,50,75,100});
    for(auto &x:l1)
        cout<<x<<" ";
    cout<<"\n";
    forward_list<int>:: iterator it;
    it=l1.begin();
    it++;
    l1.emplace_after(it,40);
    it=l1.before_begin();
    l1.insert_after(it,{20,30,45});
    l1.push_front(100);
    //l1.sort();
    //l1.clear();
    l1.pop_front();
    l1.emplace_front(90);
    forward_list<int>:: iterator it1=l1.begin();
    it1++;
    it1++;
    l1.erase_after(it,it1);
    l1.emplace_after(it,23);
    for(it=l1.begin();it!=l1.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    return 0;
}