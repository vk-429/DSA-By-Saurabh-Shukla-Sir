#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
void example1()// adjacent_find()
{
    vector<int> v1={10,4,5,13,7,7,21,15,11,11,11,21};
    int x=*adjacent_find(v1.begin(),v1.end());
    cout<<"Pair found with element value = "<<x<<"\n";
    vector<int> v2={10,3,5,11,34,21};
    vector<int>::iterator it;
    it=adjacent_find(v2.begin(),v2.end());
    if(it==v2.end())
        cout<<"No such pair exist\n";
}

void example2()//all_of()
{
    vector<int> v1={10,20,14,50,17,6,12};
    if(all_of(v1.begin(),v1.end(),[](int a)->bool{return a%2==0;}))
        cout<<"\nAll numbers are even";
    else
        cout<<"\nAtleast one number is not even";
}

void example3()//all_of()
{
    vector<int> v1={10,20,14,50,18,6,12};
    if(any_of(v1.begin(),v1.end(),[](int a)->bool{return a%2==1;}))
        cout<<"\nAtleast one element is odd";
    else
        cout<<"\nNon of the element is odd";
}

void example4()// binary_search()
{
    vector<int> v1={1,4,4,6,7,7,21,53,112,117,119,200};
    if(binary_search(v1.begin(),v1.end(),112))
        cout<<"Element found\n";
    else
        cout<<"Element not found\n";
}

void example5()//lower_bound() and upper_bound(), #imp
{
    vector<int> v1={1,4,4,6,7,7,21,53,112,117,119,200};
    vector<int>::iterator it;
    it=lower_bound(v1.begin(),v1.end(),7);
    cout<<"Element just greater than or equal to 7 is at index "<<it-v1.begin()<<"\n";
    // upper bound don't consider equal value it consideres only just greater value
    it=upper_bound(v1.begin(),v1.end(),7);
    cout<<"Element just greater than or equal to 7 is at index "<<it-v1.begin()<<"\n";
}

void example6()
{
    vector<int> v1={1,4,4,6,7,7,21,53,112,117,119,200};
    int max=*max_element(v1.begin(),v1.end()-4);
    int min=*min_element(v1.begin()+4,v1.end());
    cout<<"Minimum = "<<min<<" Maximum = "<<max<<"\n";
}

void example7()// for_each() #imp
{
    vector<int> v1={1,4,4,6,7,7,21,53,112,117,119,200};
    for_each(v1.begin(),v1.end(),[](int x)->void {cout<<x<<" - "<<x*x<<"\n";});
}

void example8() //generate
{
    vector<int> v1(100);
    generate(v1.begin(),v1.end(),[]()->int{static int i;i++;return i*i;});
    for(auto &x:v1)
        cout<<x<<" ";
    cout<<"\n";
}

void example9()// generate_n()
{
    vector<int> v1(10);
    generate_n(v1.begin(),5,[]()->int{static int i;++i;return i*i;});
    generate_n(v1.begin()+5,5,[]()->int {static int i;++i;return i*i*i;});
    for(auto &x:v1)
        cout<<x<<" ";
    cout<<"\n";
}

void example10() //count()
{
    vector<int> v1={21,4,4,6,7,7,121,53,110,11,19,20};
    cout<<count(v1.begin(),v1.end(),4)<<"\n";
    cout<<count_if(v1.begin(),v1.end(),[](int x)->bool {return x>15;})<<"\n";
}

void example11() //find()
{
    vector<int> v1={21,4,4,6,7,7,121,53,110,11,19,20};
    vector<int>:: iterator it;
    it=find(v1.begin(),v1.end(),110);
    if(it==v1.end())
        cout<<"Element not found\n";
    else
        cout<<"Element found at index "<<it-v1.begin()<<"\n";
}

void example12()// find_if()
{
    vector<int> v1={21,5,5,6,7,7,121,53,110,11,19,20};
    vector<int>::iterator it;
    it=find_if(v1.begin(),v1.end(),[](int x)->bool{
        int k;
        k=(int)sqrt(x);
        return k*k==x;
    });
    if(it==v1.end())
        cout<<"Element not found\n";
    else
        cout<<"Element "<<*it<<" found at index "<<it-v1.begin()<<"\n";
}

void example13()// equal()
{
    vector<int> v1={1,2,3,4,5,6};
    vector<int> v2={2,3,4};
    if(equal(v2.begin(),v2.end(),v1.begin()+1))
        cout<<"Equal\n";
    else
        cout<<"Not equal\n";
}

void example14() //fill()
{
    vector<int> v1={10,10,20,30,30,40,40,40,50,60,60,70,70,70,80};
    fill(v1.begin()+1,v1.begin()+5,100);
    for(auto &num:v1)
        cout<<num<<" ";
    cout<<"\n";
}

void example15() //remove
{
    vector<int> v1={11,2,5,11,18,25};
    vector<int>:: iterator it,newEnd;
    // newEnd=remove(v1.begin(),v1.end(),11);
    // for(auto &num:v1)
    //     cout<<num<<" ";
    // cout<<"\n";
    // for(it=v1.begin();it!=newEnd;it++)
    //     cout<<*it<<" ";
    // cout<<"\n";
    newEnd=remove_if(v1.begin(),v1.end(),[](int x)->bool{return (x%2)==0;});
    for(it=v1.begin();it!=newEnd;it++)
        cout<<*it<<" ";
    cout<<"\n";
}

void example16() //reverse()
{
    vector<int> v1={11,2,5,11,18,25};
    reverse(v1.begin(),v1.end());
    for(int num:v1)
        cout<<num<<" ";
    cout<<"\n";
}

void example17()
{
    vector<int> v1={10,3,4,4,4,5,5,77};
    replace(v1.begin(),v1.end(),4,63);
    for(auto& num:v1)
        cout<<num<<" ";
    cout<<"\n";
}

void example18()// search() #imp
{
    vector<int> v1={11,44,22,77,33,99,66,55,88};
    vector<int> v2={99,66,55};
    vector<int>::iterator it;
    it=search(v1.begin(),v1.end(),v2.begin(),v2.end());
    if(it!=v1.end())
        cout<<"Subsequence found at index "<<it-v1.begin()<<"\n";
    else
        cout<<"Subsequence not found\n";
}

void example19()// is_sorted()
{
    vector<int> v1={11,18,22,25,33,33,33,55,88};
    if(is_sorted(v1.begin(),v1.end()))
    {
        cout<<"Yes : Sorted\n";
    
    }
    else
        cout<<"NO : Not Sorted\n";
}

void example20() //is_sorted_until()
{
    vector<int> v1={110,14,22,77,33,33,44,55};
    vector<int>:: iterator it;
    it=is_sorted_until(v1.begin(),v1.end());
    cout<<*it<<"\n";
    cout<<"Number of Elements Sorted Untill the First Unsorted One is : "<<it-v1.begin()<<"\n";
}
int main()
{
    example1();
    example2();
    example3();
    example4();
    example5();
    example6();
    example7();
    example8();
    example9();
    example10();
    example11();
    example12();
    example13();
    example14();
    example15();
    example16();
    example17();
    example18();
    example19();
    example20();
    return 0;
}