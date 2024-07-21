#include<iostream>
using namespace std;
struct node
{
    node* prev;
    int item;
    node* next;
};
class DLL
{
    private:
        node* start;
    public:
        DLL();
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node*);
        ~DLL();
};
DLL::~DLL()
{
    while(start)
        deleteFirst();
}
void DLL::deleteSpecific(node* ptr)
{
    if(start&&ptr)
    {
        if(ptr->prev)
            ptr->prev->next=ptr->next;
        else
            start=start->next;
        if(ptr->next)
            ptr->next->prev=ptr->prev;
        delete ptr;
    }
    else
        cout<<"Underflow\n";
    
}
/*
void DLL::deleteSpecific(node* temp)
{
    if(temp->prev)
        temp->prev->next=temp->next;
    else
        start=temp->next;
    if(temp->next)
        temp->next->prev=temp->prev;
    delete temp;
}
*/
void DLL::deleteLast()
{
    if(start)
    {
        node* t;
        t=start;
        if(start->next==NULL)
            start=NULL;
        else
        {
            while(t->next!=NULL)
                t=t->next;
            t->prev->next=NULL;
        }
        delete t;
    }
    else
        cout<<"Underflow\n";
}
void DLL::deleteFirst()
{
    node* t;
    if(start)
    {
        t=start;
        if(start->next)
            start->next->prev=NULL;
        start=start->next;
        delete t;
    }
    else
        cout<<"Underflow\n";
}
node* DLL::search(int data)
{
    node* t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void DLL::insertAfter(node*t,int data)
{
    if(search(t->item))
    {
        node* n=new node;
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
void DLL::insertAtLast(int data)
{
    node* n=new node;
    n->item=data;
    n->next=NULL;
    node *t;
    t=start;
    if(!start)
    {
        n->prev=NULL;
        start=n;
    }   
    else
    {
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
}
void DLL::insertAtStart(int data)
{
    node* n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}
DLL::DLL()
{
    start=NULL;
}
