#include<iostream>
using namespace std;
// ArrayADT : Array Abstract Data Type
template<typename X>
class Array
{
    private:
        int capacity;
        int lastindex;
        X *ptr;
    public:
        Array(Array &);
        int getCapacity();
        Array& operator=(const Array&);
        Array(int);
        bool CheckEmpty();
        void Append(X);
        void Insert(int,X);
        void Edit(int,X);
        void Delete(int);
        bool CheckFull();
        int Count();
        X get(int);
        ~Array();
        int FindElement(X);
        void PrintArray();
};
template<typename X>
Array<X>& Array<X>::operator=(const Array& arr)
{
    if (this != &arr) // Check for self-assignment
    {
        delete[] ptr; // Deallocate the current array

        capacity = arr.capacity;
        lastindex = arr.lastindex;
        ptr = new X[capacity];

        for (int i = 0; i <= lastindex; i++)
            ptr[i] = arr.ptr[i];
        return *this;
    }

    return *this; // Return a reference to the current object
}
template<typename X>
int Array<X>::getCapacity()
{
    return capacity;
}
template<typename X>
Array<X>::Array(Array &arr)
{
    capacity=arr.capacity;
    lastindex=arr.lastindex;
    ptr=new X[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=arr.ptr[i];
}
template<typename X>
Array<X>::Array(int size)
{
    ptr=new X[size];
    capacity=size;
    lastindex=-1;
    //cout<<"Array created successfully\n";
    //cout<<capacity;
}
template<typename X>
bool Array<X>::CheckEmpty()
{
    if(lastindex==-1)
        return true;
    else
        return false;
    //return (lastindex==-1);
}
template<typename X>
void Array<X>::Append(X num)
{
    if(lastindex==capacity-1)
    {
        cout<<"Can't Append ! Array is already full\n";
        return;
    }
    lastindex++;
    ptr[lastindex]=num;
}
template<typename X>
void Array<X>::Insert(int index,X num)
{
    if(lastindex==(capacity-1))
    {
        cout<<"Error : Array is already full";
        return;
    }
    else if(index>(lastindex+1)||index<0)
    {
        cout<<"Invalid Index";
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
template<typename X>
void Array<X>::Edit(int index,X num)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=num;
    else
    {
        cout<<"Invalid index !\n";
            return;
    }
}
template<typename X>
void Array<X>::Delete(int index)
{
    if(lastindex==-1)
    {
        cout<<"Array is empty\n";
        return;
    }
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
template<typename X>
bool Array<X>::CheckFull()
{
    if(lastindex==(capacity-1))
        return true;
    else 
        return false;
}
template<typename X>
int Array<X>::Count()
{
    return lastindex+1;
}
template<typename X>
X Array<X>::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"\nInvalid index !\n";
    return X();
}
template<typename X>
Array<X>::~Array()
{
    delete[] ptr;
}
template<typename X>
int Array<X>::FindElement(X num)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==num)
            return i;
    }
    return -1;
}
template<typename X>
void Array<X>::PrintArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<' ';
    cout<<endl;
}

int main()
{
    Array<int> obj(5);
    obj.Append(20);
    obj.Append(30);
    obj.Append(60);
    obj.PrintArray();

    Array<double> o1(5);
    o1.Append(4.5);
    o1.Append(10.3);
    o1.Insert(1,7.75);
    o1.PrintArray();
    return 0;
}