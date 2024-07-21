#include<iostream>
#include<deque>
using namespace std;

class Complex
{
    private:
        int a,b;
    public:
        Complex(int x,int y){a=x;b=y;}
        void setData(int x,int y){a=x;b=y;}
        void showData(){cout<<"("<<a<<","<<b<<")\n";}
};

int main()
{
    deque<int> d1;
    deque<int> d2={10,35,22,18,70};
    deque<int> d3;
    d3.assign(20,25);
    d3.assign({30,50,70});
    int i=0;
    d2.assign({1,2,3,4,5});
    while(i<d2.size())
    {
        cout<<d2.at(i)<<" ";
        i++;
    }
    cout<<"\n";
    //d2.erase(d2.begin()+2);
    d2.erase(d2.begin()+1,d2.end()-1);
    for(auto&x:d2)
        cout<<x<<" ";
    cout<<"\n";
    deque<int>::iterator it;
    for(it=d2.begin();it!=d2.end();it++)
        cout<<*it<<" ";
    cout<<"\n";

    deque<Complex> d={Complex(10,20),Complex(14,25),Complex(3,4)};
    deque<Complex>:: iterator it1;
    for(it1=d.begin();it1!=d.end();it1++)
        it1->showData();
    Complex *p=new Complex(5,6);
    it1=d.begin();
    //*it1=*p;//edit ho jayega begin wala element
    //d.emplace_front(*p);
    d.emplace_back(*p);
    d.emplace(d.begin()+2,*p);
    for(it1=d.begin();it1!=d.end();it1++)
        it1->showData();
    cout<<d2.front()<<"\n";
    cout<<d2.back()<<"\n";
    d2.push_front(20);
    d2.push_back(50);
    d2.swap(d3);
    d2.clear();
    for(auto&x:d2)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}