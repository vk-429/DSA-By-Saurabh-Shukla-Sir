#include<iostream>
using namespace std;
// ArrayADT : Array Abstract Data Type

template<typename arg_type, size_t size>
class Array
{
    private:
        int capacity;
        int lastindex;
        arg_type *ptr;
    public:
        Array()
        {
            ptr=new arg_type[size];
            capacity=size;
            lastindex=-1;
        }

        Array(Array &);
        bool CheckEmpty() {return (lastindex==-1);}
        bool CheckFull() {return lastindex==(capacity-1);}
        int Count() {return lastindex+1;}

        void Append(arg_type num);
        void Insert(int index,arg_type num);
        void Edit(int index,arg_type num);
        void Delete(int index);
        arg_type get(int index);
        int FindElement(arg_type num);
        void PrintArray();
        Array<arg_type,size>& operator=(const Array<arg_type,size>&);
        ~Array() {delete[] ptr;}  
};

template<typename arg_type,size_t size>
Array<arg_type,size>::Array(Array<arg_type,size> &A)
{
    capacity=A.capacity;
    lastindex=A.lastindex;
    ptr=new arg_type[capacity];
    for(int i=0;i<capacity;i++)
        ptr[i]=A.ptr[i];
}

template<typename arg_type,size_t size>
Array<arg_type,size>& Array<arg_type,size>::operator=(const Array<arg_type,size>& arr)
{
    if (this != &arr) // Check for self-assignment
    {
        delete[] ptr; // Deallocate the current array

        capacity = arr.capacity;
        lastindex = arr.lastindex;
        ptr = new arg_type[capacity];

        for (int i = 0; i <= lastindex; i++)
            ptr[i] = arr.ptr[i];
        return *this;
    }

    return *this; // Return a reference to the current object
}

template<typename arg_type, size_t size>
void Array<arg_type,size>::PrintArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}

template<typename arg_type, size_t size>
int Array<arg_type,size>::FindElement(arg_type num)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==num)
            return i;
    }
    return -1;
}

template<typename arg_type, size_t size>
arg_type Array<arg_type,size>::get(int index)
{
    if(index>=0&&index<=lastindex)
        return ptr[index];
    cout<<"\nInvalid index !\n";
    return arg_type();
}

template<typename arg_type, size_t size>
void Array<arg_type,size>::Delete(int index)
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

template<typename arg_type, size_t size>
void Array<arg_type,size>::Edit(int index,arg_type num)
{
    if(index>=0&&index<=lastindex)
        ptr[index]=num;
    else
    {
        cout<<"Invalid index !\n";
            return;
    }
}

template<typename arg_type, size_t size>
void Array<arg_type,size>::Insert(int index,arg_type num)
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

template<typename arg_type, size_t size>
void Array<arg_type,size>::Append(arg_type num)
{
    if(lastindex==capacity-1)
    {
        cout<<"Can't Append ! Array is already full\n";
        return;
    }
    lastindex++;
    ptr[lastindex]=num;
}


// int main()
// {
//     Array<int, 5> intArray;
//     intArray.Append(1);
//     intArray.Append(2);
//     intArray.Append(3);
//     intArray.Insert(1, 4);
//     cout << "Int Array:" << endl;
//     intArray.PrintArray();

//     Array<char, 5> charArray;
//     charArray.Append('A');
//     charArray.Append('B');
//     charArray.Append('C');
//     charArray.Insert(1, 'D');
//     cout << "Char Array:" << endl;
//     charArray.PrintArray();

//     Array<double, 5> doubleArray;
//     doubleArray.Append(1.1);
//     doubleArray.Append(2.2);
//     doubleArray.Append(3.3);
//     doubleArray.Insert(1, 4.4);
//     cout << "Double Array:" << endl;
//     doubleArray.PrintArray();

//     Array<string,5> str;
    
//     str.Append("one");
//     str.Append("four");
//     str.Append("ten");
//     str.Append("fourteen");
//     str.Append("forty-two");
//     str.PrintArray();
//     str.Delete(2);
//     str.PrintArray();

//     return 0;
// }