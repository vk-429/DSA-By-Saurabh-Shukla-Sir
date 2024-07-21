#include<iostream>
using namespace std;

struct node
{
    int item;
    node *prev;
    node *next;
};
class Deque
{
    private:
        node *front;
        node *rear;
    public:
        Deque();
        void insertAtFront(int);
        void insertAtBack(int);
        bool isEmpty();
        void deleteFront();
        void deleteBack();
        int getFront();
        int getRear();
        node* Rear();
        node* Front();
        ~Deque();
        Deque(Deque&);
        Deque& operator=(const Deque &);
};
node* Deque::Front()
{
    return front;
}
node* Deque::Rear()
{
    return rear;
}
Deque& Deque::operator=(const Deque &D)
{
    if(&D==this)
        return *this;
    if(rear)
    {
        while(rear)
            deleteBack();
    }
    node *t;
    t=D.front;
    while(t)
    {
        insertAtBack(t->item);
        t=t->next;
    }
    return *this;
}
Deque::Deque(Deque &D)
{
    front=NULL;
    rear=NULL;
    node *t;
    t=D.front;
    while(t)
    {
        insertAtBack(t->item);
        t=t->next;
    }
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
int Deque::getRear()
{
    if(isEmpty())
    {
        cout<<"Deque is Empty\n";
        return -1;
    }
    else
        return rear->item;
}
int Deque::getFront()
{
    if(isEmpty())
    {
        cout<<"Deque is Empty\n";
        return -1;
    }
    else
        return front->item;
}
void Deque::deleteFront()
{
    if(isEmpty())
        cout<<"Deque Undeflow\n";
    else
    {
        node *t;
        t=front;
        if(front->next)
        {
            front=front->next;
            front->prev=NULL;
        }
        else
        {
            front=NULL;
            rear=NULL;
        }
        delete t;
    }
}
void Deque::deleteBack()
{
    if(isEmpty())
        cout<<"Deque Underflow\n";
    else
    {
        node *t;
        t=rear;
        if(rear->prev)
        {
            rear=rear->prev;
            rear->next=NULL;
        }
        else
        {
            rear=NULL;
            front=NULL;
        }
        delete t;
    }
}
bool Deque::isEmpty()
{
    return rear==NULL;
}
void Deque::insertAtFront(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=front;
    if(isEmpty())
        rear=n;
    else
        front->prev=n;
    front=n;
}
void Deque::insertAtBack(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    n->prev=rear;
    if(isEmpty())
        front=n;
    else
        rear->next=n;
    rear=n;
}
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}