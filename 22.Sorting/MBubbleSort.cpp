#include<iostream>
using namespace std;

void mbubblesort(int *p,int size)
{
    int i,j,count=0;
    for(i=1;i<size;i++)
    {
        count=0;
        for(j=0;j<size-i;j++)
        {
            if(p[j+1]<p[j])
            {
                count++;
                p[j+1]=p[j+1]+p[j];
                p[j]=p[j+1]-p[j];
                p[j+1]=p[j+1]-p[j];
            }
        }
        if(count==0)
            break;
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
    mbubblesort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}