#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        DynArray():capacity(1),lastindex(-1){ptr = new int[capacity];}
        DynArray(int);
        void DoubleArray();
        void HalfArray();
        int Cap();
        bool Empty();
        void Append(int);
        void Insert(int,int);
        void Edit(int,int);
        void Delete(int);
        bool Full();
        int get(int);
        int Count();
        ~DynArray();
        int FindElement(int);
        void PrintArray();
};
void DynArray::PrintArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
}
void DynArray::Delete(int index)
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
int DynArray::FindElement(int index)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(index==i)
            return index;
    }
    return -1;
}
DynArray::~DynArray()
{
    delete[] ptr;
}
int DynArray::Count()
{
    return (lastindex+1);
}
int DynArray::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"\nInvalid index !\n";
    return -1;
}
bool DynArray::Full()
{
    return (lastindex==capacity-1);
}
void DynArray::Edit(int index,int num)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=num;
    else
    {
        cout<<"Invalid index !\n";
            return;
    }
}
void DynArray::Insert(int index,int num)
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
void DynArray::Append(int num)
{
    if(lastindex==capacity-1)
        DoubleArray();
    lastindex++;
    ptr[lastindex]=num;
}
bool DynArray::Empty()
{
    return (lastindex==-1);
}
int DynArray::Cap()
{
    return capacity;
}
void DynArray::HalfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity/=2;
}
void DynArray::DoubleArray()
{
    int *temp;
    temp=new int [2*capacity];
    for(int i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete[] ptr;
    ptr=temp;
    capacity*=2;
}
DynArray::DynArray(int size)
{
    capacity=size;
    lastindex=-1;
    ptr=new int[size];
}
int main()
{
    DynArray DA(20);
    DA.Append(23);
    DA.PrintArray();
    
    return 0;
}