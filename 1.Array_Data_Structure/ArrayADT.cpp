#include<iostream>
using namespace std;
// ArrayADT : Array Abstract Data Type
class Array
{
    private:

        int capacity;
        int lastindex;
        int *ptr;

    public:

        Array(int size):capacity(size),lastindex(-1){ptr=new int[capacity];}
        bool CheckEmpty(){return (lastindex == -1);}
        void Append(int);
        void Insert(int,int);
        void Edit(int,int);
        void Delete(int);
        bool CheckFull(){return (lastindex==(capacity-1));}
        int Count(){return (lastindex+1);}
        int get(int);
        ~Array(){delete[] ptr;}
        int FindElement(int);
        void PrintArray();
        Array(const Array&);
        Array& operator=(const Array&);
};

Array& Array::operator=(const Array& A)
{
    if(&A != this)
    {
        delete[] ptr;
        capacity = A.capacity;
        lastindex = A.lastindex;
        ptr = new int[capacity];
        for(int i=0;i<=lastindex;i++)
            ptr[i]=A.ptr[i];
    }
    return *this;
}

Array::Array(const Array& A)
{
    capacity = A.capacity;
    lastindex = A.lastindex;
    ptr = new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=A.ptr[i];
}
void Array::PrintArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
    cout<<"\n";
}

int Array::FindElement(int num)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==num)
            return i;
    }
    cout<<"Element Not Found!\n";
    return -1;
}

int Array::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"\nInvalid index !\n";
    return -1;
}

void Array::Delete(int index)
{
    if(lastindex==-1)
    {
        cout<<"Array is empty\n";
        return;
    }
    else if(index>=0 && index<=lastindex)
    {
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;    
    }
    else
        cout<<"Invalid index!\n";
}

void Array::Edit(int index,int num)
{
    if(index>=0 && index<=lastindex)
        ptr[index]=num;
    else
        cout<<"Invalid index!\n";
}

void Array::Insert(int index,int num)
{
    if(lastindex==(capacity-1))
    {
        cout<<"Error : Array is already full!\n";
        return;
    }
    else if(index>(lastindex+1)||index<0)
    {
        cout<<"Invalid Index!\n";
        return;
    }
    for(int i=lastindex;i>=index;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=num;
    lastindex++;
}

void Array::Append(int num)
{
    if(lastindex==capacity-1)
    {
        cout<<"Can't Append !\nArray is already full\n";
        return;
    }
    lastindex++;
    ptr[lastindex]=num;
}

// int main()
// {
//     Array A1(40);
//     A1.Append(12);
//     A1.PrintArray();
//     cout<<A1.CheckEmpty()<<endl;
//     cout<<A1.CheckFull()<<endl;
//     A1.Insert(1,20);
//     A1.Insert(2,34);
//     A1.PrintArray();
//     A1.Edit(2,45);
//     A1.PrintArray();
//     A1.Delete(1);
//     A1.PrintArray();
//     cout<<A1.Count()<<endl;
//     cout<<A1.FindElement(20);
//     cout<<endl<<A1.get(1)<<endl;
//     return 0;
// }