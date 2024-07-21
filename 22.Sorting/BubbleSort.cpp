#include<iostream>
using namespace std;

void bubblesort(int *p,int size)
{
    int i,j;
    for(i=1;i<size;i++)
    {
        for(j=0;j<size-i;j++)
        {
            if(p[j+1]<p[j])
            {
                p[j+1]=p[j+1]+p[j];
                p[j]=p[j+1]-p[j];
                p[j+1]=p[j+1]-p[j];
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
    cout<<"Enter the elements of the  array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubblesort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}