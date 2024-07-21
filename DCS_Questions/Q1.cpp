#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        Array(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void Delete(int);
        bool isFull();
        int get(int);
        int Count();
        ~Array();
        int find(int);
};
int Array::find(int data)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
            return i;
    }
    return -1;
}
Array::~Array()
{
    delete[]ptr;
}
int Array::Count()
{
    return lastindex+1;
}
int Array::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"Invalid index or invalid index\n";
    return -1;
}
bool Array::isFull()
{
    return lastindex==(capacity-1);
}
void Array::Delete(int index)
{
    if(lastindex==-1)
        cout<<"Array is emplty";
    else if(index>=0&&index<=lastindex)
    {
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;    
    }
    else
    {
        cout<<"Invalid index !\n";
            return;
    }
}
void Array::edit(int index,int data)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=data;
    else
    {
        cout<<"Invalid index !\n";
        return;
    }
}
void Array::insert(int index,int data)
{
    if(lastindex==(capacity-1))
    {
        cout<<"Error : Array is already full\n";
        return;
    }
    else if(index>(lastindex+1)||index<0)
    {
        cout<<"Invalid Index\n";
        return;
    }
    else
    {
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
    }
}
Array::Array(int cap)
{
    capacity=cap;
    lastindex=-1;
    ptr=new int[capacity];
}
bool Array::isEmpty()
{
    return lastindex==-1;
}
void Array::append(int data)
{
    if(lastindex==(capacity-1))
    {
        cout<<"Error : Array is already full\n";
        return;
    }
    else
    {
        lastindex++;
        ptr[lastindex]=data;
    }
}
int main()
{
    Array obj(5);
    if(obj.isEmpty())
        cout<<"Empty Array";
    obj.append(20);
    obj.append(40);
    obj.append(60);
    obj.insert(1,30);
    for(int i=0;i<obj.Count();i++)
        cout<<obj.get(i)<<" ";
    cout<<endl;
    obj.Delete(2);
    for(int i=0;i<obj.Count();i++)
        cout<<obj.get(i)<<" ";
    return 0;
}