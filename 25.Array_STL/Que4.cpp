#include<iostream>
#include<array>
using namespace std;

class Complex
{
    private:
        int real;
        int img;
    public:
        Complex():real(0),img(0){}
        Complex(int r,int i):real(r),img(i){}
        void display()
        {
            cout<<real<<" + "<<img<<"i"<<"\n";
        }
        int getReal()
        {
            return real;
        }
        int getImg()
        {
            return img;
        }
};

void input(array<Complex,5>& arr)
{
    for(int i=0;i<5;i++)
    {
        cout<<"Enter real and img of Complex Number "<<(i+1)<<" :-\n";
        int real,img;
        cin>>real>>img;
        arr[i] = (Complex(real,img));
    }
        
}

Complex find_sum(array<Complex,5>& arr)
{
    int sumreal = 0, sumimg = 0;
    for(int i = 0;i<5;i++)
    {
        sumreal += arr[i].getReal();
        sumimg += arr[i].getImg();
    }
    return (Complex(sumreal,sumimg));
}

int main()
{
    array<Complex,5> arr;
    input(arr);
    for(int i=0;i<5;i++)
        arr[i].display();
    Complex sum = find_sum(arr);
    cout<<"\nSum of all Complex Numbers = ";
    sum.display();
    return 0;
}

