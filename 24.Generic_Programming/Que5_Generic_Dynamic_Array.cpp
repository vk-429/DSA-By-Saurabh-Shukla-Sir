#include<iostream>
using namespace std;

template<typename arg_type>
class DynArray
{
    private:
        int capacity;
        int lastindex;
        arg_type *ptr;
    public:
        DynArray();
        DynArray(int);
        void DoubleArray();
        void HalfArray();
        int Cap();
        bool Empty();
        void Append(arg_type);
        void Insert(int,arg_type);
        void Edit(int,arg_type);
        void Delete(int);
        bool Full();
        arg_type get(int);
        int Count();
        ~DynArray();
        int FindElement(int);
        void PrintArray();
};

template<typename arg_type>
void DynArray<arg_type>::PrintArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
    cout<<"\n";
}

template<typename arg_type>
void DynArray<arg_type>::Delete(int index)
{
    if(lastindex==-1)
    {
        cout<<"Array is empty\n";
        return;
    }
    else if(index<0||index>lastindex)
    {
        cout<<"Invalid Index !\n";
        return;
    }
    else
    {
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
        if(lastindex+1<=(capacity/2)&&capacity>1)
            HalfArray();
    } 
}

template<typename arg_type>
int DynArray<arg_type>::FindElement(int index)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(index==i)
            return index;
    }
    return -1;
}

template<typename arg_type>
DynArray<arg_type>::~DynArray()
{
    delete[] ptr;
}

template<typename arg_type>
int DynArray<arg_type>::Count()
{
    return (lastindex+1);
}

template<typename arg_type>
arg_type DynArray<arg_type>::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"\nInvalid index !\n";
    return arg_type();
}

template<typename arg_type>
bool DynArray<arg_type>::Full()
{
    return (lastindex==capacity-1);
}

template<typename arg_type>
void DynArray<arg_type>::Edit(int index,arg_type num)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=num;
    else
    {
        cout<<"Invalid index !\n";
            return;
    }
}

template<typename arg_type>
void DynArray<arg_type>::Insert(int index,arg_type num)
{
    if(lastindex==capacity-1)
        DoubleArray();
    else if(index<0||(index>(lastindex+1)))
    {
        cout<<"Invalid Index !\n";
        return;
    }
    else
    {
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=num;
        lastindex++;
    }
}

template<typename arg_type>
void DynArray<arg_type>::Append(arg_type num)
{
    if(lastindex==capacity-1)
        DoubleArray();
    lastindex++;
    ptr[lastindex]=num;
}

template<typename arg_type>
bool DynArray<arg_type>::Empty()
{
    return (lastindex==-1);
}

template<typename arg_type>
int DynArray<arg_type>::Cap()
{
    return capacity;
}

template<typename arg_type>
void DynArray<arg_type>::HalfArray()
{
    arg_type *temp;
    temp=new arg_type[capacity/2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity/=2;
}

template<typename arg_type>
void DynArray<arg_type>::DoubleArray()
{
    arg_type *temp;
    temp=new arg_type [2*capacity];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete[] ptr;
    ptr=temp;
    capacity*=2;
}

template<typename arg_type>
DynArray<arg_type>::DynArray(int size)
{
    capacity=size;
    lastindex=-1;
    ptr=new arg_type[size];
}

template<typename arg_type>
DynArray<arg_type>::DynArray()
{
    capacity=1;
    lastindex=-1;
    ptr=new arg_type[capacity];
}

int main()
{
    DynArray<int> D1;
    D1.Append(1);
    D1.Append(4);
    D1.Append(10);
    D1.Append(14);
    D1.Append(42);
    D1.PrintArray();
    D1.Delete(2);
    D1.PrintArray();

    cout<<"\n\n";
    DynArray<float> D2;
    D2.Append(1.1);
    D2.Append(4.4);
    D2.Append(10.10);
    D2.Append(14.14);
    D2.Append(42.42);
    D2.PrintArray();
    D2.Delete(2);
    D2.PrintArray();

    cout<<"\n\n";
    DynArray<string> D3;
    D3.Append("one");
    D3.Append("four");
    D3.Append("ten");
    D3.Append("fourteen");
    D3.Append("forty-two");
    D3.PrintArray();
    D3.Delete(2);
    D3.PrintArray();
    return 0;
}