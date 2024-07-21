#include<iostream>
#include"DynArray.cpp"
#include<vector>
using namespace std;

class Employee
{
    private:
        int emp_id;
        string name;
        float salary;
    public:
        Employee& operator=(const Employee&);
        void inputempid()
        {
            int id;
            cout<<"Enter Employee id : ";
            cin>>id;
            emp_id=id;
        }
        void inputname()
        {
            string s;
            cout<<"Enter Name : ";
            cin>>s;
            name=s;
        }
        void inputsalary()
        {
            float sal;
            cout<<"Enter Salary : ";
            cin>>sal;
            salary=sal;
        }
        void setempid(int id)
        {
            emp_id=id;
        }
        void setname(string &s)
        {
            name=s;
        }
        void setsalary(float sal)
        {
            salary=sal;
        }
        float getsalary()
        {
            return salary;
        }
        string& getname()
        {
            return name;
        }
        int getid()
        {
            return emp_id;
        }
        void printempdata();
};
Employee& Employee::operator=(const Employee& E)
{
    emp_id=E.emp_id;
    name=E.name;
    salary=E.salary;
    return *this;
}
void Employee::printempdata()
{
    cout<<"Name : "<<name<<"\n";
    cout<<"Employee ID : "<<emp_id<<"\n";
    cout<<"Salary : "<<salary<<"\n\n";
}
void sortbysalary(Employee *p,int li,int ui)
{
    if(ui-li==0)
        return;
    int mid=(li+ui)/2;
    sortbysalary(p,li,mid);
    sortbysalary(p,mid+1,ui);
    int i,j;
    vector<Employee> E1,E2;
    for(i=li;i<=mid;i++)
        E1.push_back(p[i]);
    for(i=mid+1;i<=ui;i++)
        E2.push_back(p[i]);
    i=0;
    j=0;
    int k;
    for(k=li;k<=ui;k++)
    {
        if(i==E1.size() || j==E2.size())
            break;
        if(E1[i].getsalary()<E2[j].getsalary())
        {
            p[k]=E1[i];
            i++;
        }
        else
        {
            p[k]=E2[j];
            j++;
        }
        
    }
    while(i<E1.size())
    {
        p[k]=E1[i];
        i++;
        k++;
    }
    while(j<E2.size())
    {
        p[k]=E2[j];
        j++;
        k++;
    }
}
void sortbyname(Employee *p,int start,int end)
{
    if(start==end)
        return; 
    int left=start;
    int right=end;
    int loc=start;
    Employee temp;
    while(left!=right)
    {
        if(p[left].getname()>p[right].getname())
        {
            temp=p[left];
            p[left]=p[right];
            p[right]=temp;
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
        sortbyname(p,start,loc-1);  
    if(loc!=end)
        sortbyname(p,loc+1,end);
}
int main()
{
    int n;
    cout<<"Enter the no of Employees : ";
    cin>>n;
    Employee E[n];
    cout<<"Enter Details of Employees : \n";
    for(int i=0;i<n;i++)
    {
        E[i].inputempid();
        E[i].inputname();
        E[i].inputsalary();
    }
    for(int i=0;i<n;i++)
        E[i].printempdata();
    sortbysalary(E,0,n-1);
    for(int i=0;i<n;i++)
        E[i].printempdata();
    return 0;
}