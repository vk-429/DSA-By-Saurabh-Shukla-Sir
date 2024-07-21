#include<iostream>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
using namespace std;

int main()
{
    tuple<int,double,string> t1{1,5.6,"abc"};
    tuple <int,string,string> t2;
    t2=make_tuple(10,"Bhopal","Concert");//make tuple is also not a member function
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<"\n";

    pair<int,string> p1{10,"abc"};
    pair<int,int> p2(20,30);
    pair<string,string> p3;
    p3=make_pair("rahul","gupta");//make pair is not a member function
    pair<int,string> p4(p1);
    cout<<p3.first<<" "<<p3.second<<"\n";
    vector<pair<int,int>> v1;
    v1.push_back(make_pair(2,4));
    cout<<v1[0].first<<" "<<v1[0].second<<"\n";
    return 0;
}

