#include<iostream>
using namespace std;
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
void selectionsort(int*p,int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(p[j]<p[i])
            {
                p[i]=p[i]+p[j];
                p[j]=p[i]-p[j];
                p[i]=p[i]-p[j];
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    selectionsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}