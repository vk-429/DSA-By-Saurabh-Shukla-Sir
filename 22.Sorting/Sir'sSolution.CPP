#include<iostream>
//#include "StackArray.cpp"
using namespace std;
void bubbleSort(int A[],int size)
{
    int r,i,t;
    for(r=1;r<=size-1;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
    }
}
void modifiedBubbleSort(int A[],int size)
{
    int r,i,t;
    bool flag;
    for(r=1;r<=size-1;r++)
    {
        flag=false;
        for(i=0;i<=size-1-r;i++)
        {
            if(A[i]>A[i+1])
            {
                flag=true;
                t=A[i];
                A[i]=A[i+1];
                A[i+1]=t;
            }
        }
        if(flag==false)
            break;
    }
}
void insertionSort(int A[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp<A[j])
            {
                A[j+1]=A[j];
            }
            else
                break;
        }
        A[j+1]=temp;
    }
}
int minValueIndex(int A[],int size,int j)
{
    int i,min,minIndex;
    min=A[j];
    minIndex=j;
    for(i=j+1;i<=size-1;i++)
    {
        if(min>A[i])
        {
            min=A[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void selectionSort(int A[],int size)
{
    int t,i,minIndex;
    for(i=0;i<=size-2;i++)
    {
        minIndex=minValueIndex(A,size,i);
        t=A[i];
        A[i]=A[minIndex];
        A[minIndex]=t;
    }
}
int quick(int A[],int left,int right)
{
    int loc=left,t;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        t=A[loc];
        A[loc]=A[right];
        A[right]=t;
        loc=right;
        while(left<right && A[left]<=A[loc])
            left++;
        if(left==right)
            break;
        t=A[left];
        A[left]=A[loc];
        A[loc]=t;
        loc=left;
    }
    return loc;
}
void quickSort(int A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(loc>l+1)
        quickSort(A,l,loc-1);
    if(loc<u-1)
        quickSort(A,loc+1,u);
}
// void quickSortLoop(int A[],int l,int u)
// {
//     int loc,i,j;
//     Stack lower(10),upper(10);
//     lower.push(l);
//     upper.push(u);
//     while(!lower.isEmpty())
//     {
//         i=lower.peek();
//         j=upper.peek();
//         loc=quick(A,i,j);
//         lower.pop();
//         upper.pop();
//         if(loc>i+1)
//         {
//             lower.push(i);
//             upper.push(loc-1);
//         }
//         if(loc<j-1)
//         {
//             lower.push(loc+1);
//             upper.push(j);
//         }
//     }
// }
// int main()
// {
//     int a[]={80,30,50,90,100,10,20,40,70,60};
//     int i;
//     quickSortLoop(a,0,9);
//     for(i=0;i<=9;i++)
//         cout<<" "<<a[i];
//     cout<<endl;
//     return 0;
// }