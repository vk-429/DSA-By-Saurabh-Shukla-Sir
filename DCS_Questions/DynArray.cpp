#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        DynArray(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void Delete(int);
        bool isFull();
        int get(int);
        int Count();
        ~DynArray();
        int find(int);
        void doubleArray();
        void halfArray();
        int size();
};
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
    }
    if((lastindex+1)==(capacity/2))
        halfArray();
}
void DynArray::append(int data)
{
    if(lastindex==(capacity-1))
        doubleArray();
    lastindex++;
    ptr[lastindex]=data;
}
void DynArray::insert(int index,int data)
{
    if(index<0||index>lastindex+1)
    {
        cout<<"Invalid index\n";
        return;
    }
    else if(isFull())
        doubleArray();
    else
    {
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
    }
}
int DynArray::size()
{
    return capacity;
}
void DynArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity/=2;
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int [2*capacity];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity*=2;
}
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}
bool DynArray::isEmpty()
{
    return lastindex==-1;
}
void DynArray::edit(int index,int data)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=data;
    else
    {
        cout<<"Invalid index !\n";
        return;
    }
}
bool DynArray::isFull()
{
    return lastindex==(capacity-1);
}
int DynArray::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"Invalid index or invalid index\n";
    return -1;
}
int DynArray::Count()
{
    return lastindex+1;
}
DynArray::~DynArray()
{
    delete[]ptr;
}
int DynArray::find(int num)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(num==ptr[i])
            return i;
    }
    return -1;
}