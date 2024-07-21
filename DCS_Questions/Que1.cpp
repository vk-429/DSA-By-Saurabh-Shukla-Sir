#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        Array(int size)
        {
            ptr=new int[size];
            capacity=size;
            lastindex=-1;
            //cout<<"Array created successfully\n";
            //cout<<capacity;
        }
        bool CheckEmpty()
        {
            if(lastindex==-1)
                return true;
            else
                return false;
        }
        void Append(int num)
        {
            if(lastindex==(capacity-1))
            {
                cout<<"Error : Array is already full";
                return;
            }
            else
            {
                lastindex++;
                ptr[lastindex]=num;
            }
        }
        void Insert(int index,int num)
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
        void Edit(int index,int num)
        {
            if(index>=0&&index<=lastindex)
                ptr[index]=num;
            else
            {
                cout<<"Invalid index !\n";
                    return;
            }
        }
        void Delete(int index)
        {
            if(lastindex==-1)
                cout<<"Array is empty\n";
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
        bool CheckFull()
        {
            if(lastindex==(capacity-1))
                return true;
            else 
                return false;
        }
        int get(int index)
        {
            if(index>=0&&index<=lastindex)
                return ptr[index];
            cout<<"Invalid index or invalid index\n";
            return -1;
        }
        int Count()
        {
            return lastindex+1;
        }
        ~Array()
        {
            delete[]ptr;
        }
        int FindElement(int index)
        {
            int flag=0;
            for(int i=0;i<=lastindex;i++)
            {
                if(index==i)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                return index;
            else
                return -1;
        }
        void PrintArray()
        {
            for(int i=0;i<=lastindex;i++)
                cout<<ptr[i]<<endl;
        }
};
int main()
{
    Array A1(40);
    A1.Append(12);
    A1.PrintArray();
    cout<<A1.CheckEmpty()<<endl;
    cout<<A1.CheckFull()<<endl;
    A1.Insert(1,20);
    A1.Insert(2,34);
    A1.PrintArray();
    A1.Edit(2,45);
    A1.PrintArray();
    A1.Delete(1);
    A1.PrintArray();
    cout<<A1.Count()<<endl;
    cout<<A1.FindElement(5);
    return 0;
}