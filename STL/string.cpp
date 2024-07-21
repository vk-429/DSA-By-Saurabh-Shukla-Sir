#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string s1="mysirg education services";
    //s1.insert(2,"Hello");
    //s1.erase(s1.begin()+7,s1.begin()+17);
    s1.replace(0,6,"MySirG");
    s1.replace(s1.begin(),s1.begin()+6,"MySirG");
    cout<<s1.find("m")<<"\n";//gives the index of 1st occurence
    cout<<s1.find('e')<<"\n";
    string s2=s1.substr(0,7);
    cout<<s2<<"\n";
    cout<<s1.compare("mysirg education services")<<"\n";
    cout<<s1.compare("a")<<"\n";
    cout<<s1.compare("z")<<"\n";
    s1+=" private";
    s1.pop_back();
    // s1.push_back('Z');
    // cout<<s1<<"n";
    //s1.append(s2);
    //s1.swap(s2);
    char str[100];
    
    // //convert string into NULL terminated string
    //strcpy(str,s1.c_str());
    //s1.append(str);
    // s1.assign(str);
    // cout<<s1<<"\n";
    //str=s1.c_str();//wrong
    // cout<<str<<"\n";
    // string s2;
    // s2.assign(s1);
    // cout<<s2<<"\n";
    // cout<<s1<<"\n";
    cout<<s1.back()<<"\n";
    cout<<s1.front()<<"\n";
    // cout<<s1.size()<<"\n";
    // cout<<s1.capacity()<<"\n";
    // cout<<s1.length()<<"\n";
    // s1.append(" private limited");
    // cout<<s1.size()<<"\n";
    // cout<<s1.capacity()<<"\n";
    // cout<<s1.length()<<"\n";
    string::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it;
    cout<<"\n";
    it=s1.begin()+2;
    //*it='A';
    cout<<s1<<"\n";
    for(auto&x: s1)
        cout<<x;
    cout<<"\n";
    try
    {
        for(int i=0;true;i++)
            cout<<s1.at(i);
    }
    catch(const std::exception& e)
    {
        cout<<"\nException : Out of Range\n";
    }
    for(int i=0;i<s1.length();i++)
        cout<<s1[i];
    cout<<"\n";
    return 0;
}