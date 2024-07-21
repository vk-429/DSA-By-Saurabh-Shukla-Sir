#include<iostream>
using namespace std;

struct node
{
    int item;
    int priority;
    node *next;
};
class PriorityQueue
{
    private:
        node *start;
    public:
        PriorityQueue();
        void insert(int,int);
        void deleteFront();
        int getFront();
        node* Front();
        int getHighP();
        ~PriorityQueue();
        bool isEmpty();
};
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        deleteFront();
}
int PriorityQueue::getHighP()
{
    if(start)
        return start->priority;
    cout<<"Queue is Empty\n";
    return -1;
}
node* PriorityQueue::Front()
{
    if(start)
        return start;
    cout<<"Queue is Empty\n";
    return NULL;
}
int PriorityQueue::getFront()
{
    if(start)
        return start->item;
    cout<<"Queue is Empty\n";
    return -1;
}
void PriorityQueue::deleteFront()
{
    if(start)
    {
        node* t;
        t=start;
        start=start->next;
        delete t;
    }
    else
        cout<<"Queue Underflow\n";
}
void PriorityQueue::insert(int data, int p)
{
    node *n=new node;
    n->item=data;
    n->priority=p;
    if(start==NULL)
    {
        n->next=start;
        start=n;
    }
    else
    {
        node*t,*p=NULL;
        t=start;
        while(t!=nullptr && (t->priority>=n->priority))
        {
            p=t;
            t=t->next;
        }
        if(p)
        {
            n->next=p->next;
            p->next=n; 
        }
        else
        {
            n->next=start;
            start=n;
        }
        /*
        if(start->priority<n->priority)
        {
            n->next=start;
            start=n;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
            {   
                if(t->next->priority>=n->priority)
                    t=t->next;
                else
                    break;
            }
            n-next=t->next;
            t->next=n;
        }
        */  
    }
}
PriorityQueue::PriorityQueue()
{
    start=NULL;
}