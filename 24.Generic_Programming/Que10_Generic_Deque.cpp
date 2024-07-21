#include<iostream>
using namespace std;

template<typename arg_type>
struct node
{
    int item;
    node<arg_type> *prev;
    node<arg_type> *next;
};

template<typename arg_type>
class Deque
{
    private:
        node<arg_type> *front;
        node<arg_type> *rear;
    public:
        Deque();
        void insertAtFront(arg_type);
        void insertAtBack(arg_type);
        bool isEmpty();
        void deleteFront();
        void deleteBack();
        arg_type getFront();
        arg_type getRear();
        node<arg_type>* Rear();
        node<arg_type>* Front();
        ~Deque();
        Deque(Deque<arg_type>&);
        Deque<arg_type>& operator=(const Deque<arg_type> &);
};

template<typename arg_type>
node<arg_type>* Deque<arg_type>::Front()
{
    return front;
}

template<typename arg_type>
node<arg_type>* Deque<arg_type>::Rear()
{
    return rear;
}

template<typename arg_type>
Deque<arg_type>& Deque<arg_type>::operator=(const Deque<arg_type> &D)
{
    if(&D==this)
        return *this;
    if(rear)
    {
        while(rear)
            deleteBack();
    }
    node<arg_type> *t;
    t=D.front;
    while(t)
    {
        insertAtBack(t->item);
        t=t->next;
    }
    return *this;
}

template<typename arg_type>
Deque<arg_type>::Deque(Deque<arg_type> &D)
{
    front=NULL;
    rear=NULL;
    node<arg_type> *t;
    t=D.front;
    while(t)
    {
        insertAtBack(t->item);
        t=t->next;
    }
}

template<typename arg_type>
Deque<arg_type>::~Deque()
{
    while(front)
        deleteFront();
}

template<typename arg_type>
arg_type Deque<arg_type>::getRear()
{
    if(isEmpty())
    {
        cout<<"Deque is Empty\n";
        return arg_type();
    }
    else
        return rear->item;
}

template<typename arg_type>
arg_type Deque<arg_type>::getFront()
{
    if(isEmpty())
    {
        cout<<"Deque is Empty\n";
        return arg_type();
    }
    else
        return front->item;
}

template<typename arg_type>
void Deque<arg_type>::deleteFront()
{
    if(isEmpty())
        cout<<"Deque Undeflow\n";
    else
    {
        node<arg_type> *t;
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

template<typename arg_type>
void Deque<arg_type>::deleteBack()
{
    if(isEmpty())
        cout<<"Deque Underflow\n";
    else
    {
        node<arg_type> *t;
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

template<typename arg_type>
bool Deque<arg_type>::isEmpty()
{
    return rear==NULL;
}

template<typename arg_type>
void Deque<arg_type>::insertAtFront(arg_type data)
{
    node<arg_type> *n=new node<arg_type>;
    n->item=data;
    n->prev=NULL;
    n->next=front;
    if(isEmpty())
        rear=n;
    else
        front->prev=n;
    front=n;
}

template<typename arg_type>
void Deque<arg_type>::insertAtBack(arg_type data)
{
    node<arg_type> *n=new node<arg_type>;
    n->item=data;
    n->next=NULL;
    n->prev=rear;
    if(isEmpty())
        front=n;
    else
        rear->next=n;
    rear=n;
}

template<typename arg_type>
Deque<arg_type>::Deque()
{
    front=NULL;
    rear=NULL;
}


int main()
{
    Deque<int> q;
    q.insertAtFront(2);
    q.insertAtBack(4);
    q.insertAtFront(9);
    q.insertAtBack(11);
    while(!q.isEmpty())
    {
        cout<<q.getFront()<<" ";
        q.deleteFront();
    }
    cout<<"\n";
    return 0;
}