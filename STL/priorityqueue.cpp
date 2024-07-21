#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Employee
{
    private:
        int empid;
        string name;
        float salary;
    public:
        Employee(int i,string n,float s):empid(i),name(n),salary(s){}
        void showEmployee()
        {
            cout<<"ID : "<<empid<<", Name : "<<name<<", Salary : "<<salary<<"\n";
        }
        // bool operator<(const Employee &E)const
        // {
        //     return salary<E.salary;
        // }
        float getSalary()const
        {return salary;}
};
class CompareBySalary
{
    public:
        bool operator()(Employee const &e1,Employee const &e2)
        {
            return e1.getSalary()<e2.getSalary();
        }
};
int main()
{
    priority_queue<int,vector<int>> pq1;
    pq1.push(10);
    pq1.push(20);
    pq1.push(15);
    pq1.push(30);
    pq1.push(12);
    cout<<pq1.top()<<"\n";
    pq1.pop();
    priority_queue<Employee,vector<Employee>,CompareBySalary> pq2;
    pq2.push(*(new Employee(1,"Arun",20000)));
    pq2.push(*(new Employee(1,"Sushma",30000)));
    pq2.push(*(new Employee(1,"Ajay",40000)));
    pq2.push(*(new Employee(1,"Alok",50000)));
    pq2.push(*(new Employee(1,"Nitin",35000)));
    Employee e1=pq2.top();
    e1.showEmployee();
    return 0;
}