#include<iostream>
using namespace std;

template<typename arg_type>
struct node
{
    node<arg_type>* prev;
    arg_type item;
    node<arg_type>* next;
};

template<typename arg_type>
class DLL
{
    private:
        node<arg_type>* start;
    public:
        DLL();
        void insertAtStart(arg_type);
        void insertAtLast(arg_type);
        void insertAfter(node<arg_type>*,arg_type);
        node<arg_type>* search(arg_type);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node<arg_type>*);
        node<arg_type>* get(arg_type);
        void printList();
        ~DLL();
};

template<typename arg_type>
void DLL<arg_type>::printList()
{
    node<arg_type> *t;
    t=start;
    while(t)
    {
        cout<<t->item<<" ";
        t=t->next;
    }
    cout<<"\n";
}

template<typename arg_type>
node<arg_type>* DLL<arg_type>::get(arg_type data)
{
    node<arg_type>* t;
    t=start;
    while(t!=nullptr && t->item!=data)
        t= t->next;
    return t;
}

template<typename arg_type>
DLL<arg_type>::~DLL()
{
    while(start)
        deleteFirst();
}

template<typename arg_type>
void DLL<arg_type>::deleteSpecific(node<arg_type>* ptr)
{
    if(start&&ptr)
    {
        node<arg_type>* temp;
        temp=start;
        if(temp->prev)
            temp->prev->next=temp->next;
        else
            start=temp->next;
        if(temp->next)
            temp->next->prev=temp->prev;
        delete temp;
    }
    else
        cout<<"Underflow\n";
    
}

template<typename arg_type>
void DLL<arg_type>::deleteLast()
{
    if(start)
    {
        node<arg_type>* t;
        t=start;
        if(start->next==nullptr)
            start=nullptr;
        else
        {
            while(t->next!=nullptr)
                t=t->next;
            t->prev->next=nullptr;
        }
        delete t;
    }
    else
        cout<<"Underflow\n";
}

template<typename arg_type>
void DLL<arg_type>::deleteFirst()
{
    node<arg_type>* t;
    if(start)
    {
        t=start;
        if(start->next)
            start->next->prev=nullptr;
        start=start->next;
        delete t;
    }
    else
        cout<<"Underflow\n";
}

template<typename arg_type>
node<arg_type>* DLL<arg_type>::search(arg_type data)
{
    node<arg_type>* t;
    t=start;
    while(t!=nullptr)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return nullptr;
}

template<typename arg_type>
void DLL<arg_type>::insertAfter(node<arg_type>*t,arg_type data)
{
    if(t)
    {
        node<arg_type>* n=new node<arg_type>;
        n->item=data;
        n->next=t->next;
        n->prev=t;
        if(t->next)
            t->next->prev=n;
        t->next=n;
    }
    else
        cout<<"Invalid Address!\n";
}

template<typename arg_type>
void DLL<arg_type>::insertAtLast(arg_type data)
{
    node<arg_type>* n=new node<arg_type>;
    n->item=data;
    n->next=nullptr;
    node<arg_type> *t;
    t=start;
    if(!start)
    {
        n->prev=nullptr;
        start=n;
    }   
    else
    {
        while(t->next!=nullptr)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
}

template<typename arg_type>
void DLL<arg_type>::insertAtStart(arg_type data)
{
    node<arg_type>* n=new node<arg_type>;
    n->item=data;
    n->prev=nullptr;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}

template<typename arg_type>
DLL<arg_type>::DLL()
{
    start=nullptr;
}

int main()
{
    DLL<string> s1;
    s1.insertAtLast("Vivek");
    s1.insertAtStart("Rohit");
    node<string>* n1=s1.get("Rohit"); 
    s1.insertAfter(n1,"Shiva");
    s1.printList();
    s1.deleteSpecific(s1.get("Rohit")); 
    s1.printList();
    return 0;

}
