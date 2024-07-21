#include<iostream>
using namespace std;

template<typename arg_type, size_t size>
class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        arg_type *ptr;
    public:
        Queue();
        Queue(Queue<arg_type,size> &);
        Queue<arg_type,size>& operator=(const Queue<arg_type,size>&);
        void insert(arg_type);
        bool isEmpty()const;
        arg_type getRear();
        arg_type getFront();
        void remove();
        ~Queue();
        bool isFull();
        int Size()const;
};

template<typename arg_type, size_t size>
Queue<arg_type,size>& Queue<arg_type,size>::operator=(const Queue<arg_type,size> &q)
{
    if(this==&q)
        return *this;
    capacity=q.capacity;
    rear=q.rear;
    front=q.front;
    if(ptr)
        delete []ptr;
    ptr=new arg_type[capacity];
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

template<typename arg_type, size_t size>
Queue<arg_type,size>::Queue(Queue<arg_type,size> &q)
{
    capacity=q.capacity;
    rear=q.rear;
    front=q.front;
    ptr=new arg_type[capacity];
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

template<typename arg_type, size_t size>
void Queue<arg_type,size>::remove()
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

template<typename arg_type, size_t size>
int Queue<arg_type,size>::Size()const
{
    if(isEmpty())
        return 0;
    else if(front>rear)
        return ((capacity-front)+(rear+1));
    else 
        return (rear-front+1);
}

template<typename arg_type, size_t size>
bool Queue<arg_type,size>::isFull()
{
    if(front==rear+1 || (front==0&&rear==capacity-1))
        return true;
    else
        return false;
}

template<typename arg_type, size_t size>
Queue<arg_type,size>::~Queue()
{
    delete[] ptr;
}

template<typename arg_type, size_t size>
arg_type Queue<arg_type,size>::getFront()
{
    if(rear==-1)
    {
        cout<<"Queue is Empty\n";
        return arg_type();
    }
    return ptr[front];
}

template<typename arg_type, size_t size>
arg_type Queue<arg_type,size>::getRear()
{
    if(rear==-1)
    {
        cout<<"Queue is Empty\n";
        return arg_type();
    }
    return ptr[rear];
}

template<typename arg_type, size_t size>
bool Queue<arg_type,size>::isEmpty()const
{
    if(rear==-1)
        return true;
    else
        return false;
}

template<typename arg_type, size_t size>
void Queue<arg_type,size>::insert(arg_type data)
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

template<typename arg_type, size_t size>
Queue<arg_type,size>::Queue()
{
    ptr=new arg_type[size];
    capacity=size;
    front=-1;
    rear=-1;
}

int main()
{
    Queue<int,5> q;
    q.insert(1);
    q.insert(2);
    q.insert(1);
    q.insert(2);
    q.insert(2);
    cout<<q.getRear()<<"\n";
    cout<<q.getFront()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cout<<q.Size()<<"\n";
    q.remove();
    q.remove();
    cout<<q.getRear()<<"\n";
    cout<<q.getFront()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cout<<q.Size()<<"\n";
    q.insert(5);
    cout<<q.getRear()<<"\n";
    cout<<q.getFront()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cout<<q.Size()<<"\n";
    q.insert(26);
    cout<<q.getRear()<<"\n";
    cout<<q.getFront()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cout<<q.Size()<<"\n";
    q.remove();
    q.remove();
    q.remove();
    q.remove();
    q.remove();
    cout<<q.getRear()<<"\n";
    cout<<q.getFront()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cout<<q.Size()<<"\n";
    return 0;
}
