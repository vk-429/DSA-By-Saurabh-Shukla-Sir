#include<iostream>
using namespace std;


class Time
{
    private:
        int hr;
        int min;
        int sec;
    public:
        void setTime(int h,int m,int s)
        {
            hr=h;
            min=m;
            sec=s;
        }
        void showTime()
        {
            cout<<hr<<" : "<<min<<" : "<<sec<<"\n";
        }
        bool operator>(Time &T)
        {
            if(hr>T.hr)
                return true;
            if(hr==T.hr)
            {
                if(min>T.min)
                    return true;
                if(min==T.min)
                {
                    if(sec>T.sec)
                        return true;
                    return false;
                }
                return false;
            }
            return false;
        }
};

template<typename X>
X bigger(X a,X b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    Time T1,T2,T3;
    T1.setTime(5,45,20);
    T2.setTime(6,37,23);
    T3=bigger(T1,T2);
    T3.showTime();
    cout<<bigger(234,543)<<"\n";
    cout<<bigger(5.5,3.7)<<"\n";
    return 0;
}