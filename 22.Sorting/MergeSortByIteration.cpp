#include<iostream>
#include"DynArray.cpp"
using namespace std;
void merge(int A[],int n1,int i1,int B[],int n2,int i2,int C[],int i3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1&&j<n2;k++)
    {
        if(A[i+i1]<B[j+i2])
        {
            C[k+i3]=A[i+i1];
            i++;
        }
        else
        {
            C[k+i3]=B[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        C[k+i3]=A[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        C[k+i3]=B[j+i2];
        j++;
        k++;
    }
}
void mergepass(int A[],int size,int l,int B[])
{
    int mergeCount,index,R,S;
    mergeCount=size/(2*l);
    int j;
    index=0;
    S=mergeCount*2*l;
    R=size-S;
    for(j=0;j<mergeCount;j++)
    {
        merge(A,l,index,A,l,index+l,B,index);
        index+=(2*l);
    }
    if(R<=l)
    {
        for(int i=0;i<R;i++)
            B[S+i]=A[S+i];
    }
    else
        merge(A,l,S,A,R-l,S+l,B,S);
}
void mergesort(int A[],int size)
{
    int l=1,B[size];
    while(l<size)
    {
        mergepass(A,size,l,B);
        mergepass(B,size,2*l,A);
        l=l*4;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the Array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergesort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;    
}