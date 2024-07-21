#include<iostream>
using namespace std;

struct node
{
    int item;
    node* next;
};
class Queue
{
    private:
        node* front;
        node* rear;
    public:
        Queue();
        Queue(Queue &);
        Queue& operator=(const Queue&);
        void insert(int);
        bool isEmpty();
        int getRear();
        int getFront();
        node* Rear();
        node* Front();
        void remove();
        ~Queue();
        int size();
        void sortAscending(Queue &);
        void sortDescending(Queue &);
        void printQueue();
};
void Queue::printQueue()
{
    node *t1;
    t1=front;
    while(t1)
    {
        cout<<t1->item<<" ";
        t1=t1->next;
    }
    cout<<"\n";
}
node* Queue::Rear()
{
    return rear;
}
node* Queue::Front()
{
    return front;
}
Queue& Queue::operator=(const Queue&q)
{
    if(this==&q)
        return *this;
    if(front)
    {
        node *t;
        while(front)
        {
            t=front;
            front=front->next;
            delete t;
        }
        rear=NULL;
    }
    if(q.front)
    {
        node *t;
        t=q.front;
        node *n=new node;
        n->item=q.front->item;
        n->next=NULL;
        rear=n;
        front=n;
        while(t->next)
        { 
            t=t->next;
            node *n=new node;
            n->item=t->item;
            n->next=NULL;
            rear->next=n;
            rear=n;
        }
    }
    return *this;
}
Queue::Queue(Queue &q)
{
    rear=NULL;
    front=NULL;
    if(q.front)
    {
        node *t;
        t=q.front;
        node *n=new node;
        n->item=q.front->item;
        n->next=NULL;
        rear=n;
        front=n;
        while(t->next)
        { 
            t=t->next;
            node *n=new node;
            n->item=t->item;
            n->next=NULL;
            rear->next=n;
            rear=n;
        }
    }
}
int Queue::size()
{
    int count=0;
    node *t;
    t=front;
    while(t)
    {
        t=t->next;
        count++;
    }
    return count;
}
Queue::~Queue()
{
    while(!isEmpty())
        remove();
}
void Queue::remove()
{
    if(!isEmpty())
    {
        node*r;
        r=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete r;
    }
    else
        cout<<"Queue Underflow\n";
}
bool Queue::isEmpty()
{
    return rear==NULL;
}
int Queue::getFront()
{
    if(front)
        return front->item;
    else
        cout<<"Queue is Empty\n";
    return -1;
}
int Queue::getRear()
{
    if(rear)
        return rear->item;
    else
        cout<<"Queue is Empty\n";
    return -1;
}
void Queue::insert(int data)
{
    node* n=new node;
    n->item=data;
    n->next=NULL;
    if(isEmpty())
        front=rear=n;
    else
    {
        rear->next=n;
        rear=n;
    }
}
Queue::Queue()
{
    front=NULL;
    rear=NULL;
}
void sortAscending(Queue &q)
{
    Queue q1,q2;
    node *t1,*t2,*t3;
    if(q.Front())
    {
        t1=q.Front();
        q1.insert(t1->item);
        t1=t1->next;
        q.remove();
        while(!q.isEmpty())
        {
            t2=q1.Rear();
            if(t1->item>=t2->item)
            {
                q1.insert(t1->item);
                t1=t1->next;
                q.remove();
            }
            else
            {
                t3=q1.Front();
                while(!q1.isEmpty())
                {
                    q2.insert(t3->item);
                    t3=t3->next;
                    q1.remove();
                }
                t3=q2.Front();
                while(t3->item<t1->item)
                {
                    q1.insert(t3->item);
                    t3=t3->next;
                    q2.remove();
                }
                q1.insert(t1->item);
                while(!q2.isEmpty())
                {
                    q1.insert(t3->item);
                    t3=t3->next;
                    q2.remove();
                }
                t1=t1->next;
                q.remove();
            }
        }
        q=q1;
    }
    else
        cout<<"Queue is Empty\n";
}
void sortDescending(Queue &q)
{
    Queue q1,q2;
    node *t1,*t2,*t3;
    if(q.Front())
    {
        t1=q.Front();
        q1.insert(t1->item);
        t1=t1->next;
        q.remove();
        while(!q.isEmpty())
        {
            t2=q1.Rear();
            if(t1->item<=t2->item)
            {
                q1.insert(t1->item);
                t1=t1->next;
                q.remove();
            }
            else
            {
                t3=q1.Front();
                while(!q1.isEmpty())
                {
                    q2.insert(t3->item);
                    t3=t3->next;
                    q1.remove();
                }
                t3=q2.Front();
                while(t3->item>t1->item)
                {
                    q1.insert(t3->item);
                    t3=t3->next;
                    q2.remove();
                }
                q1.insert(t1->item);
                while(!q2.isEmpty())
                {
                    q1.insert(t3->item);
                    t3=t3->next;
                    q2.remove();
                }
                t1=t1->next;
                q.remove();
            }
        }
        q=q1;
    }
    else
        cout<<"Queue is Empty\n";
}
// void Queue::sortAscending(Queue &q)
// {
//     if(q.rear)
//     {
//         node *t1,*t2;
//         t1=q.rear;
//         while(t1->next)
//         {
//             t2=t1->next;
//             while(t2)
//             {
//                 if(t1->item>t2->item)
//                 {
//                     t1->item=t1->item+t2->item;
//                     t2->item=t1->item-t2->item;
//                     t1->item=t1->item-t2->item;
//                 }
//                 t2=t2->next;
//             }
//             t1=t1->next;
//         }
//     }
//     else
//         cout<<"Queue is Empty\n";
// }
// void Queue::sortDescending(Queue &q)
// {
//     if(q.rear)
//     {
//         node *t1,*t2;
//         t1=q.rear;
//         while(t1->next)
//         {
//             t2=t1->next;
//             while(t2)
//             {
//                 if(t1->item<t2->item)
//                 {
//                     t1->item=t1->item+t2->item;
//                     t2->item=t1->item-t2->item;
//                     t1->item=t1->item-t2->item;
//                 }
//                 t2=t2->next;
//             }
//             t1=t1->next;
//         }
//     }
//     else
//         cout<<"Queue is Empty\n";
// }


int main()
{
    Queue q1;
    q1.insert(10);
    q1.insert(70);
    q1.insert(30);
    q1.insert(20);
    q1.printQueue();
    sortAscending(q1);
    q1.printQueue();
    sortDescending(q1);
    q1.printQueue();
    return 0;
}