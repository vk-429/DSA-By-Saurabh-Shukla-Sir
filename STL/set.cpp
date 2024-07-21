#include<iostream>
#include<set>
using namespace std;

class Employee
{
    private:
        int empid;
        string name;
        double salary;
    public:
        Employee(int id,string n,double s):empid(id),name(n),salary(s){}
        void showEmployee()const
        {
            cout<<empid<<" "<<name<<" "<<salary<<"\n";
        }
        bool operator<(Employee &E)
        {
            return salary<E.salary;
        }
        double getSalary()const
        {
            return salary;
        }
        string getName()const
        {
            return name;
        }
        int getEmpID()const
        {
            return empid;
        }
};
class CompareBySalary
{
    public:
        bool operator()(Employee const &e1,Employee const &e2)const
        {
            return e1.getSalary()<e2.getSalary();
        }
};
int f1();
int main()
{
    f1();
    set<Employee,CompareBySalary> s1;
    Employee e1(1,"Rahul",20000);
    s1.insert(*(new Employee(1,"Rahul",20000.0)));
    s1.insert(*(new Employee(2,"Jay",10000.0)));
    s1.insert(*(new Employee(3,"Sunita",40000.0)));
    s1.insert(*(new Employee(4,"Arjun",30000.0)));
    for(auto &x:s1)
        x.showEmployee();
    cout<<"\n";
    set<Employee,CompareBySalary>:: iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        (*it).showEmployee();
    cout<<"\n";
    return 0;
}
int f1()
{
    set<int> s1{10,30,20,50,40,70};
    s1={2,3,4,5};
    for(auto&x:s1)
        cout<<x<<" ";
    cout<<"\n";
    cout<<s1.count(20)<<"\n";
    cout<<s1.size()<<"\n";
    //s1.insert(s1.begin(),78);//hai lekin insert to appropriate jgh pe hi krega
    s1.insert(25);
    s1.emplace(26);
    s1.insert({24,39,45});
    s1.erase(++(++(++s1.begin())));
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    return 0;
}