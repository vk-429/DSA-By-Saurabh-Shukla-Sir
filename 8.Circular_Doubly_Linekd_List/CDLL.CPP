#include<iostream>
using namespace std;

struct node
{
    node* prev;
    int item;
    node* next;
};
class CDLL
{
    private:
        node* start;
    public:
        CDLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node*);
        ~CDLL();
};
CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}
void CDLL::deleteSpecific(node* ptr)
{
    if(search(ptr->item)&&start)
    {
        if(start->next==start)
            start=NULL;
        else
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            if(ptr==start)
                start=ptr->next;
        }
        delete ptr;
    }
    else
        cout<<"Either the List is Empty or Provided Address is Invalid!\n";
}
void CDLL::deleteLast()
{
    if(start)
    {
        node* t;
        t=start->prev;
        if(start->next==start)
            start=NULL;
        else
        {
            start->prev=start->prev->prev;
            start->prev->prev->next=start;
        }
        delete t;
    }
    else
        cout<<"Underflow!\n";
}
void CDLL::deleteFirst()
{
    if(start)
    {
        node* t;
        t=start;
        if(start->prev==start && start->next==start)
            start=NULL;
        else
        {
            start->next->prev=start->prev;
            start->prev->next=start->next;
            start=start->next;
        }
        delete t;
    }
    else
        cout<<"Underflow!\n";
}
void CDLL::insertAfter(node* ptr,int data)
{
    if(search(ptr->item))
    {
        node* n=new node;
        n->item=data;
        n->prev=ptr;
        n->next=ptr->next;
        ptr->next->prev=n;
        ptr->next=n;
    }
    else
        cout<<"Invalid Address!\n";
}
node* CDLL::search(int data)
{
    if(start)
    {
        node* t;
        t=start;
        do
        {
            if(t->item==data)
                return t;
            t=t->next;
        } while (t!=start);
        return NULL;
    }
    cout<<"List is Empty!\n";
    return NULL;
}
void CDLL::insertAtLast(int data)
{
    node* n = new node;
    n->item = data;
    if(start)
    {
        n->prev = start->prev;
        n->next = start;
        n->prev->next = n;
        n->next->prev = n;
    }
    else
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
}
void CDLL::insertAtStart(int data)
{
    node* n = new node;
    n->item = data;
    if(start)
    {
        n->prev=start->prev;
        n->next=start;
        n->prev->next=n;
        n->next->prev=n;
    }
    else
    {
        n->prev=n;
        n->next=n;
    }
    start=n;
}
CDLL::CDLL()
{
    start=NULL;
}