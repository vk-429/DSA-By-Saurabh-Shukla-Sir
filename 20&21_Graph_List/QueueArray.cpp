#include<iostream>
using namespace std;
class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        Queue(int);
        Queue(Queue &);
        Queue& operator=(const Queue&);
        void insert(int);
        bool isEmpty()const;
        int getRear();
        int getFront();
        void remove();
        ~Queue();
        bool isFull();
        int size()const;
};
Queue& Queue::operator=(const Queue &q)
{
    if(this==&q)
        return *this;
    capacity=q.capacity;
    rear=q.rear;
    front=q.front;
    if(ptr)
        delete []ptr;
    ptr=new int[capacity];
    int n=q.size();
    int i=q.front;
    while(n)
    {
        ptr[i]=q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
    return *this;
}
Queue::Queue(Queue &q)
{
    capacity=q.capacity;
    rear=q.rear;
    front=q.front;
    ptr=new int[capacity];
    int n=q.size();
    int i=q.front;
    while(n)
    {
        ptr[i]=q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
void Queue::remove()
{
    if(isEmpty())
        cout<<"Queue Underflow\n";
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
int Queue::size()const
{
    if(isEmpty())
        return 0;
    else if(front>rear)
        return ((capacity-front)+(rear+1));
    else 
        return (rear-front+1);
}
bool Queue::isFull()
{
    if(front==rear+1 || (front==0&&rear==capacity-1))
        return true;
    else
        return false;
}
Queue::~Queue()
{
    delete[] ptr;
}
int Queue::getFront()
{
    if(rear==-1)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    return ptr[front];
}
int Queue::getRear()
{
    if(rear==-1)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    return ptr[rear];
}
bool Queue::isEmpty()const
{
    if(rear==-1)
        return true;
    else
        return false;
}
void Queue::insert(int data)
{
    if(isFull())
        cout<<"Queue Overflow\n";
    else if(isEmpty())
    {
        front=0;
        rear=0;
        ptr[rear]=data;
    }
    else if(rear == capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
/*
void Queue::insert(int data)
{
    if(isFull())//(front==rear+1 || (front==0&&rear==capacity-1))
    {
        cout<<"Queue Overflow\n";
    }
    else if(isEmpty())
    {
        rear=0;
        front=0;
        ptr[rear]=data;
    }
    else if(front==0)
    {
        rear++;
        ptr[rear]=data;
    }
    else if(rear==capacity-1 && front>0)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}p
*/
Queue::Queue(int cap)
{
    ptr=new int[cap];
    capacity=cap;
    front=-1;
    rear=-1;
}

// int main()
// {
//     Queue q(5);
//     q.insert(1);
//     q.insert(2);
//     q.insert(1);
//     q.insert(2);
//     q.insert(2);
//     cout<<q.getRear()<<"\n";
//     cout<<q.getFront()<<"\n";
//     cout<<q.isEmpty()<<"\n";
//     cout<<q.isFull()<<"\n";
//     cout<<q.size()<<"\n";
//     q.remove();
//     q.remove();
//     cout<<q.getRear()<<"\n";
//     cout<<q.getFront()<<"\n";
//     cout<<q.isEmpty()<<"\n";
//     cout<<q.isFull()<<"\n";
//     cout<<q.size()<<"\n";
//     q.insert(5);
//     cout<<q.getRear()<<"\n";
//     cout<<q.getFront()<<"\n";
//     cout<<q.isEmpty()<<"\n";
//     cout<<q.isFull()<<"\n";
//     cout<<q.size()<<"\n";
//     q.insert(26);
//     cout<<q.getRear()<<"\n";
//     cout<<q.getFront()<<"\n";
//     cout<<q.isEmpty()<<"\n";
//     cout<<q.isFull()<<"\n";
//     cout<<q.size()<<"\n";
//     q.remove();
//     q.remove();
//     q.remove();
//     q.remove();
//     q.remove();
//     cout<<q.getRear()<<"\n";
//     cout<<q.getFront()<<"\n";
//     cout<<q.isEmpty()<<"\n";
//     cout<<q.isFull()<<"\n";
//     cout<<q.size()<<"\n";
//     return 0;
// }
