#include<iostream>
using namespace std;

void quicksortrec(int *p,int start,int end)
{
    if(start==end)
        return; 
    int left=start;
    int right=end;
    int loc=start;
    while(left!=right)
    {
        if(p[left]>p[right])
        {
            p[left]=p[left]+p[right];
            p[right]=p[left]-p[right];
            p[left]=p[left]-p[right];
            if(loc==left)
            {
                loc=right;
                left++;
            }
            else
            {
                loc=left;
                right--;
            }
        }
        else
        {
            if(loc==left)
                right--;
            else
                left++;
        }
    }
    if(loc!=start)
        quicksortrec(p,start,loc-1);  
    if(loc!=end)
        quicksortrec(p,loc+1,end);
}
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksortrec(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    delete[] arr;
    return 0;
}