#include<iostream>
using namespace std;

void insertionsort(int *p,int size)
{
    int temp;
    int i,j;
    for(i=1;i<size;i++)
    {
        j=i-1;
        temp=p[i];
        while(j>=0 && temp<p[j])
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertionsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}