#include<iostream>
using namespace std;
struct Node
{
    int item;
    Node *next;
};
class SLL
{
    private:
        Node *start;
    public:
        SLL();
        void insertAtStart(int);
        void insertAtLast(int);
        Node* search(int);
        void insertAfter(Node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(Node*);
        Node* begin();
        void setStart(Node *);
        void printList();
        SLL& operator=(const SLL &);
        ~SLL();
};
SLL::~SLL()
{
    while(start)
        deleteFirst();
}
SLL& SLL::operator=(const SLL &L)
{
    // Check for self-assignment
    if (this == &L)
        return *this;

    // Clear the current list
    while (start)
        deleteFirst();

    // Copy elements from 'other' to 'this'
    Node *t = L.start;
    while (t)
    {
        insertAtLast(t->item);
        t = t->next;
    }

    return *this;
}
void SLL::printList()
{
    Node* t;
    t=start;
    while(t!=NULL)
    {
        cout<<(t->item)<<" ";
        t=t->next;
    }
    cout<<"\n";
}
void SLL::setStart(Node *newStart)
{
    start = newStart;
}
Node* SLL::begin()
{
    return start;
}
void SLL::deleteSpecific(Node *ptr)
{
    if(start&&ptr)
    {
        Node *t;
        if(ptr==start)
        {
            start=start->next;
            delete ptr;
        }
        else
        {
            t=start;
            while(t->next!=ptr)
                t=t->next;
            t->next=ptr->next;
            delete ptr;
        }
    }
    else
        cout<<"Underflow\n";
}
void SLL::deleteLast()
{
    if(start)
    {
        Node *t;
        t=start;
        if(t->next==NULL)
        {
            start=NULL;
            delete t;
        }
        else
        {
            while(t->next->next!=NULL)
                t=t->next;
            delete t->next;
            t->next=NULL;
        }
    }
    else
        cout<<"Underflow\n";
}
void SLL::deleteFirst()
{
    if(start)
    {
        Node *t;
        t=start;
        start=start->next;
        delete t;
    }
    else
        cout<<"Underflow\n";
}
void SLL::insertAfter(Node *ptr,int data)
{
    if(search(ptr->item))
    {
        Node *n=new Node;
        n->item=data;
        n->next=ptr->next;
        ptr->next=n;
    }
    else
        cout<<"Invalid Address!\n";
}
Node* SLL::search(int data)
{
    Node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void SLL::insertAtLast(int data)
{
    Node *t;
    Node *n = new Node;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
        start = n;
    else 
    {
        t = start;
        while (t->next != NULL) 
            t = t->next;
        t->next = n;
    }
}
void SLL::insertAtStart(int data)
{
    Node *n=new Node;
    n->item=data; 
    n->next=start;
    start=n;
}
SLL::SLL()
{
    start=NULL;//NULL = nullptr
}