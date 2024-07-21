#include<iostream>
using namespace std;
struct node
{
    int item;
    node* next;   
};
class CLL
{
    private:
        node* last;
    public:
        CLL();
        void insertAtFirst(int);
        void insertAtEnd(int);
        void insertSpecific(node*,int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node*);
        ~CLL();
};
CLL::~CLL()
{
    while(last)
        deleteFirst();
}
void CLL::deleteSpecific(node* ptr)
{
    if(search(ptr->item)&&last)
    {
        node *t;
        t=last->next;
        while(t->next!=ptr)
            t=t->next;
        t->next=ptr->next;
        if(t==ptr)
            last=NULL;
        else if(ptr==last)
            last=t;
        delete ptr;
    }
    else
        cout<<"Either the Provided Address is Invalid or List is Empty!\n";
    /*
    if(ptr&&last)
    {
        node *t;
        t=last;
        if(ptr==last)
        {
            if(ptr->next==last)
                last=NULL;
            else
            {
                while(t->next!=ptr)
                    t=t->next;
                t->next=last->next;
                last=t;
            }

        }
        else
        {
            if(last->next==ptr)
                t->next=last->next->next;
            else
            {
                while(t->next!=ptr)
                    t=t->next;
                t->next=ptr->next;
            }
        }
        delete ptr;
    }
    */
}
void CLL::deleteLast()
{
    if(last)
    {
        node *t;
        t=last;
        if(t->next==last)
        {
            last=NULL;
            delete t;
        }
        else
        {
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            last=t;
            delete (t->next);
        }
    }
    else
        cout<<"Underflow!\n";
}
void CLL::deleteFirst()
{
    if(last)
    {
        node *t;
        t=last->next;
        if(last->next==last)
            last=NULL;
        else
            last->next=t->next;
        delete t;
    }
    else
        cout<<"Underflow!\n";
}
node * CLL::search(int data)
{
    if(last)
    {
        node* t;
        t=last;
        do
        {
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=last);
        return NULL;
    }
    else
        cout<<"List is Empty!\n";
    /*
    if(last)
    {
        node* t;
        t=last; 
        while(t->next!=last)
        {
            if(t->item==data) 
                return t;
            t=t->next;
        }
        if(t->item==data)return t;
        return NULL;  
    }
    */
}
void CLL::insertSpecific(node* ptr,int data)
{
    if(search(ptr->item))
    {
        node* n=new node;
        n->item=data;
        n->next=ptr->next;
        ptr->next=n;
        if(ptr==last)
            last=n;
    }
    else
        cout<<"Invalid Address!\n";
}
void CLL::insertAtEnd(int data)
{
    node* n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
    }
    else
        n->next=n;
    last=n;
}
void CLL::insertAtFirst(int data)
{
    node* n=new node;
    n->item=data;
    if(last)
        n->next=last->next;
    else
        last=n;
    last->next=n;
}
CLL::CLL()
{
    last=NULL;
}