#include<iostream>
using namespace std;

template<typename arg_type>
struct Node
{
    arg_type item;
    Node<arg_type> *next;
};

template<typename arg_type>
class SLL
{
    private:
        Node<arg_type> *start;
    public:
        SLL();
        void insertAtStart(arg_type);
        void insertAtLast(arg_type);
        Node<arg_type>* search(arg_type);
        void insertAfter(Node<arg_type>*,arg_type);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(Node<arg_type>*);
        Node<arg_type>* getStart();
        void printList();
        Node<arg_type>* get();
        ~SLL();
};

template<typename arg_type>
Node<arg_type>* SLL<arg_type>::get()
{
    Node<arg_type> *t;
    t=start;
    while(t!=nullptr && t->item!=data)
        t=t->next;
    return t;
}

template<typename arg_type>
void SLL<arg_type>::printList()
{
    Node<arg_type> *t;
    t=start;
    while(t)
    {
        cout<<t->item<<" ";
        t=t->next;
    }
    cout<<"\n";
}

template<typename arg_type>
SLL<arg_type>::~SLL()
{
    while(start)
        deleteFirst();
}

template<typename arg_type>
Node<arg_type>* SLL<arg_type>::getStart()
{
    return start;
}

template<typename arg_type>
void SLL<arg_type>::deleteSpecific(Node<arg_type> *ptr)
{
    if(start&&ptr)
    {
        Node<arg_type> *t;
        if(ptr==start)
        {
            start=start->next;
            delete ptr;
        }
        else
        {
            t=start;
            while(t->next != nullptr && t->next != ptr)
                t=t->next;
            if(t->next == ptr)
            {
                t->next=ptr->next;
                delete ptr;
            }
        }
    }
    else
        cout<<"Underflow\n";
}

template<typename arg_type>
void SLL<arg_type>::deleteLast()
{
    if(start)
    {
        Node<arg_type> *t;
        t=start;
        if(t->next==nullptr)
        {
            start=nullptr;
            delete t;
        }
        else
        {
            while(t->next->next!=nullptr)
                t=t->next;
            delete t->next;
            t->next=nullptr;
        }
    }
    else
        cout<<"Underflow\n";
}

template<typename arg_type>
void SLL<arg_type>::deleteFirst()
{
    if(start)
    {
        Node<arg_type> *t;
        t=start;
        start=start->next;
        delete t;
    }
    else
        cout<<"Underflow\n";
}

template<typename arg_type>
void SLL<arg_type>::insertAfter(Node<arg_type> *ptr,arg_type data)
{
    if(ptr)
    {
        Node<arg_type> *n=new Node<arg_type>;
        n->item=data;
        n->next=ptr->next;
        ptr->next=n;
    }
    else
        cout<<"Invalid Address!\n";
}

template<typename arg_type>
Node<arg_type>* SLL<arg_type>::search(arg_type data)
{
    Node<arg_type> *t;
    t=start;
    while(t!=nullptr)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return nullptr;
}

template<typename arg_type>
void SLL<arg_type>::insertAtLast(arg_type data)
{
    Node<arg_type> *t;
    Node<arg_type> *n = new Node<arg_type>;
    n->item = data;
    n->next = nullptr;
    if (start == nullptr)
        start = n;
    else 
    {
        t = start;
        while (t->next != nullptr)
            t = t->next;
        t->next = n;
    }
}

template<typename arg_type>
void SLL<arg_type>::insertAtStart(arg_type data)
{
    Node<arg_type> *n=new Node<arg_type>;
    n->item=data; 
    n->next=start;
    start=n;
}

template<typename arg_type>
SLL<arg_type>::SLL()
{
    start=nullptr;//NULL = nullptr
}

int main()
{
    SLL<int> s1;
    s1.insertAtStart(4);
    s1.insertAtStart(2);
    s1.insertAtStart(5);
    s1.insertAtStart(9);
    s1.insertAtStart(41);
    s1.printList();
    s1.deleteFirst();
    s1.deleteLast();
    s1.printList();
    return 0;
}