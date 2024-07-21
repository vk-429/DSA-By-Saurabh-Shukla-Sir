#include<iostream>
using namespace std;

class Time
{
    private:
        int hr,min,sec;
    public:
        void setTime(int hr,int min,int sec)
        {
            this->hr=hr;
            this->min=min;
            this->sec=sec;
        }
        void showtime()
        {
            cout<<"\n"<<hr<<" : "<<min<<" : "<<sec;
        }
        bool operator>(Time T)
        {
            if(hr>T.hr)
                return true;
            else if(hr<T.hr)
                return false;
            else if(min>T.min)
                return true;
            else if(min<T.min)
                return false;
            else if(sec>T.sec)
                return true;
            else
                return false;
        }
};
template<typename X>
X bigger(X a,X b)
{
    if(a>b)
        return a;
    else 
        return b;
}

// double bigger(double a,double b)
// {
//     if(a>b)
//         return a;
//     else 
//         return b;
// }
// Time bigger(Time a,Time b)
// {
//     if(a>b)
//         return a;
//     else 
//         return b;
// }

int main()
{
    Time t1,t2,t3;
    t1.setTime(3,45,20);
    t2.setTime(3,40,50);
    t3=bigger(t1,t2);
    t3.showtime();
    cout<<"\n"<<bigger(10,20);
    cout<<"\n"<<bigger(4.5F,3.2F);
    return 0;
}