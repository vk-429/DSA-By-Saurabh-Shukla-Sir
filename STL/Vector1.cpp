#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //declaration and initialization
    vector<int> v1;
    vector<int> v2={10,50,20,40,30};
    v1.assign({2,4,8,6});
    v1.assign(4,20);

    //subscript operator
    cout<<v2[3]<<"\n";
    cout<<v2[5]<<"\n";//subscript operator don't have bound checking

    //at function
    cout<<v2.at(3)<<"\n";
    try
    {
        cout<<v2.at(5);//at() function have bound checking
    }
    catch(const exception& e)
    {
        cout<<"Index out of Bound Exception !"<<'\n';
    }

    //implicit iterator
    for(auto &x:v2)
        cout<<x<<" ";
    cout<<"\n";

    //Explicit iterator
    //vector<int>::iterator it;
    //it=v2.begin();
    vector<int>::reverse_iterator it;
    it=v2.rbegin();
    *(it+2)=100;
    // for(it=v2.begin();it!=v2.end();it++)
    //     cout<<*it<<" ";
    for(it=v2.rbegin();it!=v2.rend();it++)
        cout<<*it<<" ";
    cout<<"\n";
    v2.pop_back();
    v2.erase(v2.end()-1);//end last element ke bhi ak aage ko point krta hai
    v2.push_back(70);
    v2.insert(v2.begin(),{60,62,64});
    v2.erase(v2.begin(),v2.begin()+2);
    for(auto &x:v2)
        cout<<x<<" ";
    cout<<"\n";

    //methods
    cout<<"Capacity = "<<v2.capacity()<<"\n";
    v2.push_back(90);
    cout<<"Capacity = "<<v2.capacity()<<"\n";
    cout<<"Size = "<<v2.size()<<"\n";
    
    return 0;
}