#include "C:/Users/VIVEK KUMAR/DSA/1.Array_Data_Structure/ArrayADT.cpp"
class ExtendedArray:public Array
{
    public:
        ExtendedArray(int);
        int greatest();
        void sort();
        int smallest();
        int search(int);
        int sum();
        float average();
        void rotateright();
        void removeDuplicate();
        int s_large();
        void swap(int,int);
};
ExtendedArray::ExtendedArray(int cap):Array(cap){}
void ExtendedArray::swap(int i1,int i2)
{
    if(i1<0||i2<0||i1>(Count()-1)||i2>(Count()-1))
    {
        cout<<"Either of the indices is invalid !";
        return;
    }
    else
    {
        int temp=get(i1);
        Edit(i1,get(i2));
        Edit(i2,temp);
    }
}
int ExtendedArray::s_large()
{
    int large=INT_MIN;
    int seclarge=0;
    if(Count()>=2)
    {
        for(int i=0;i<Count();i++)
        {
            if(large<get(i))
            {
                seclarge=large;
                large=get(i);
            }
            else if(get(i)>seclarge)
                seclarge=get(i);
        }
    }
    else
    {
        cout<<"You have less then 2 values in Array\n";
        return -1;
    }
    return seclarge;
}
//elements ko sort krke bhi removedupli kr skte hain
void ExtendedArray::removeDuplicate()
{
    for(int i=0;i<Count();i++)
    {
        for(int j=i+1;j<Count();j++)
        {
            if(get(i)==get(j))
            {
                Delete(j);
                j--;
            }

        }
    }
}
void ExtendedArray::rotateright()
{
    int temp=get(Count()-1);
    for(int i=Count()-1;i>0;i--)
        Edit(i,get(i-1));
    Edit(0,temp);
}
float ExtendedArray::average()
{
    float ans=(float)sum()/Count();
    return ans;
}
int ExtendedArray::sum()
{
    int sum=0;
    for(int i=0;i<Count();i++)
        sum+=get(i);
    return sum;
}
int ExtendedArray::search(int data)
{
    for(int i=0;i<Count();i++)
    {
        if(get(i)==data)
        {
            cout<<"Element found\n";
            return i;
        }
    }
    cout<<"Element Not Found !\n";
    return -1;
}
int ExtendedArray::smallest()
{
    int min;
    if(CheckEmpty())
    {
        cout<<"\nArray is empty";
        return -1;
    }
    min=get(0);
    for(int i=1;i<Count();i++)
        if(min>get(i))min=get(i);
    return min;
}
void ExtendedArray::sort()
{
    for(int i=0;i<Count()-1;i++)
        for(int j=i+1;j<Count();j++)
            if(get(i)>get(j)) swap(i,j);
}
int ExtendedArray::greatest()
{
    int max;
    if(CheckEmpty())
    {
        cout<<"\nArray is empty";
        return -1;
    }
    max=get(0);
    for(int i=1;i<Count();i++)
        if(max<get(i))max=get(i);
    return max;
}
