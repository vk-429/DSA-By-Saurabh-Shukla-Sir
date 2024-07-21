#include<iostream>
#include"StackArray.cpp"
using namespace std;

int quick(int *p,int start,int end)
{
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
    return loc;
}
void quicksort(int *p,int start,int end)
{ 
    int loc,i,j;
    Stack lower(10),upper(10);
    lower.push(start);
    upper.push(end);
    while(!lower.CheckEmpty())
    {
        i=lower.peek();
        j=upper.peek();
        loc=quick(p,i,j);
        lower.pop();
        upper.pop();
        if(loc>i+1)
        {
            lower.push(i);
            upper.push(loc-1);
        }
        if(loc<j-1)
        {
            lower.push(loc+1);
            upper.push(j);
        }
    }
    
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
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    delete[] arr;
    return 0;
}