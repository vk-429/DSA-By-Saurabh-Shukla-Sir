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
            //return (lastindex==-1);
        }
        void Append(int num)
        {
            lastindex++;
            ptr[lastindex]=num;
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
        bool CheckFull()
        {
            if(lastindex==(capacity-1))
                return true;
            else 
                return false;
        }
        int Count()
        {
            return lastindex+1;
        }
        int get(int index)
        {
            if(index>=0&&index<=lastindex)
                return ptr[index];
            cout<<"Invalid index !\n";
            return -1;
        }
        ~Array()
        {
            delete[] ptr;
        }
        int FindElement(int num)
        {
            for(int i=0;i<=lastindex;i++)
            {
                if(ptr[i]==num)
                    return i;
            }
            return -1;
        }
        void PrintArray()
        {
            for(int i=0;i<=lastindex;i++)
                cout<<ptr[i]<<endl;
        }
        void sort();
        int greatest();
        int smallest();
        int search(int);
        int sum();
        float average();
        void rotateright();
        void removedupli();
        int s_large();
        void swap(int,int);
        int getindex(int);
};
int Array::getindex(int num)
{
    int i=0;
    while(i<=lastindex)
    {
        if(ptr[i]==num)
            return i;
        i++;
    }
    return -1;
}
void Array::swap(int i1,int i2)
{
    if(i1<0||i2<0||i1>(lastindex)||i2>(lastindex))
    {
        cout<<"Either of the indices is invalid !";
        return;
    }
    else
    {
        ptr[i1]=ptr[i1]+ptr[i2];
        ptr[i2]=ptr[i1]-ptr[i2];
        ptr[i1]=ptr[i1]-ptr[i2];
    }
}
int Array::s_large()
{
    int large=INT_MIN;
    int seclarge=0;
    for(int i=0;i<=lastindex;i++)
    {
        if(large<ptr[i])
        {
            seclarge=large;
            large=ptr[i];
        }
        else if(ptr[i]>seclarge)
            seclarge=ptr[i];
    }
    return seclarge;
}
void Array::removedupli()
{  
    sort();
    for(int i=0;i<lastindex;i++)
    {
        if(ptr[i]==ptr[i+1])
        {
            Delete(i);
            i--;
        }
    }
}
void Array::rotateright()
{
    int temp=ptr[lastindex];
    for(int i=lastindex;i>0;i--)
        ptr[i]=ptr[i-1];
    ptr[0]=temp;
}
float Array::average()
{
    return (sum()/(lastindex+1));
}
int Array::sum()
{
    int sum=0;
    for(int i=0;i<=lastindex;i++)
        sum+=ptr[i];
    return sum;
}
int Array::search(int index)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(index==i)
        {
            cout<<"Element found\n";
            return ptr[index];
        }
    }
    return -1;
}
int Array::smallest()
{
    int min=INT_MAX;
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]<min)
            min=ptr[i];
    }
    return min;
}
int Array::greatest()
{
    int max=INT_MIN;
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]>max)
            max=ptr[i];
    }
    return max;
}
void Array::sort()
{
    for(int i=0;i<lastindex;i++)
    {
        for(int j=i+1;j<=lastindex;j++)
        {
            if(ptr[i]>ptr[j])
            {
                ptr[i]=ptr[i]+ptr[j];
                ptr[j]=ptr[i]-ptr[j];
                ptr[i]=ptr[i]-ptr[j];
            }
        }
    }
}
int main()
{
    Array A1(40);
    /*A1.Append(12);
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
    cout<<A1.FindElement(2);*/
    A1.Append(12);
    A1.Append(40);
    A1.Insert(2,35);
    A1.Insert(3,23);
    A1.Insert(2,45);
    A1.PrintArray();
    cout<<"\n\n";
    A1.sort();
    A1.PrintArray();
    cout<<"\nGreatest value in A1 = "<<A1.greatest()<<"\n";
    cout<<"\nSmallest value in A1 = "<<A1.smallest()<<"\n";
    cout<<A1.search(6)<<endl;
    cout<<"Sum of element in A1 = "<<A1.sum()<<endl;
    cout<<"Average of elements in A1 = "<<A1.average()<<endl;
    A1.Insert(2,13);
    cout<<"Average of elements in A1 = "<<A1.average()<<endl;
    A1.rotateright();
    A1.PrintArray();
    cout<<"\n\n";
    A1.Insert(2,12);
    A1.Insert(4,40);
    A1.PrintArray();
    A1.removedupli();
    cout<<"\n\n";
    A1.PrintArray();
    cout<<"\nSecond largest value in A1 = "<<A1.s_large()<<"\n";
    A1.swap(2,3);
    cout<<"\n\n";
    A1.PrintArray();
    return 0;
}