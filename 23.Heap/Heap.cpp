#include<iostream>
#define EMPTY_HEAP -2
using namespace std;

class HEAP
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        HEAP(int);
        void insert(int);
        bool isEmpty()const;
        void HalfArray();
        void DoubleArray();
        int greatest();
        void del();
        int get(int);
        ~HEAP();
        HEAP(const HEAP&);
        HEAP& operator=(const HEAP&);
        int sirkadel();
};
int HEAP::sirkadel()
{
    int i,item,temp,index,leftIndex,rightIndex;
    if(isEmpty())
        throw EMPTY_HEAP;
    else
    {
        item=ptr[0];
        temp=ptr[lastindex];
        lastindex--;
        index=0;
        leftIndex=1;
        rightIndex=2;
        while(leftIndex<lastindex)
        {
            
            if(ptr[leftIndex]>ptr[rightIndex])
            {
                if(temp<ptr[leftIndex])
                {
                    ptr[index]=ptr[leftIndex];
                    index=leftIndex;
                }
                else    
                    break;
            }
            else
            {
                if(temp<ptr[rightIndex])
                {
                    ptr[index]=ptr[rightIndex];
                    index=rightIndex;
                }
                else
                    break;
            }
            leftIndex=2*index+1;
            rightIndex=2*index+2;
        }
        if(leftIndex==lastindex && temp<ptr[leftIndex])
        {
            ptr[index]=ptr[leftIndex];
            index=leftIndex;
        }

        ptr[index]=temp;
        
        if(capacity/2>=lastindex+1 && capacity>1)
            HalfArray();
        return item;
    }
}
int HEAP::get(int i)
{
    return ptr[i];
}
HEAP& HEAP::operator=(const HEAP&H)
{
    if (this == &H) 
        return *this;
    if(ptr!=NULL)
        delete[] ptr;
    capacity=H.capacity;
    lastindex=H.lastindex;
    ptr=new int[H.capacity];
    for(int i=0;i<=H.lastindex;i++)
        ptr[i]=H.ptr[i];
    return *this;
}
HEAP::HEAP(const HEAP& H)
{
    capacity=H.capacity;
    lastindex=H.lastindex;
    ptr=new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=H.ptr[i];
}
HEAP::~HEAP()
{
    delete[] ptr;
}
void HEAP::del()
{
    if(lastindex==-1)
    {
        cout<<"Uderflow\n";
        return;
    }
    if(lastindex==0)
        lastindex=-1;
    else if(lastindex==1)
    {
        ptr[0]=ptr[1];
        lastindex--;
    }
    else
    {
        int parent=0;
        int child1=1,child2=2;
        int temp=ptr[lastindex];
        while(child1<=lastindex && child2<=lastindex)
        {
            if(ptr[child1]>ptr[child2])
            {
                ptr[parent]=ptr[child1];
                parent=child1;
            }
            else
            {
                ptr[parent]=ptr[child2];
                parent=child2;
            }
            child1=2*parent+1;
            child2=2*parent+2;
        }
        ptr[parent]=temp;
        lastindex--;
    }
    if(lastindex+1<=(capacity/2)&&capacity>1)
            HalfArray();
}
int HEAP::greatest()
{
    if(!isEmpty())
        return ptr[0];
    cout<<"HEAP is Empty !\n";
    return -1;
}
void HEAP::HalfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity/=2;
}
void HEAP::DoubleArray()
{
    int *temp;
    temp=new int [2*capacity];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete[] ptr;
    ptr=temp;
    capacity*=2;
}
bool HEAP::isEmpty()const
{
    return lastindex==-1;
}
void HEAP::insert(int data)
{
    if(lastindex==capacity-1)
        DoubleArray();
    if(isEmpty())
    {
        lastindex++;
        ptr[lastindex]=data;
    }
    else
    {
        // lastindex++;
        // ptr[lastindex]=data;
        // int index=lastindex,temp;
        // while(index>0&&ptr[index]>ptr[(index-1)/2])
        // {
        //     temp=ptr[index];
        //     ptr[index]=ptr[(index-1)/2];
        //     ptr[(index-1)/2]=temp;
        //     index=(index-1)/2;
        // }
        int index=lastindex+1,temp;
        while(index>0&&data>ptr[(index-1)/2])
        {
            ptr[index]=ptr[(index-1)/2];
            index=(index-1)/2;
        }
        ptr[index]=data;
        lastindex++;
    }
}
HEAP::HEAP(int cap)
{
    capacity=cap;
    lastindex=-1;
    ptr=new int[cap];
}

void heapsort(int*p,int size)
{
    HEAP H(size);
    for(int i=0;i<size;i++)
        H.insert(p[i]);
    int i=size-1;
    while(!H.isEmpty())
    {
        p[i]=H.greatest();
        H.del();
        i--;
    }
}
int main()
{
    int arr[10]={1023,2,24,3009,19,1081,34,3,12,2084};
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    heapsort(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
