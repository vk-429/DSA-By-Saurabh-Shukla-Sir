#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        Stack(const Stack &);
        Stack& operator=(const Stack &);
        void push(int);
        bool isEmpty();
        int peek();
        void pop();
        ~Stack();
        void reverse();
};

Stack::Stack(const Stack &s) : top(NULL) {
    if (s.top) {
        top = new node;
        top->item = s.top->item;
        node *source = s.top->next;
        node *dest = top;
        while (source) {
            dest->next = new node;
            dest = dest->next;
            dest->item = source->item;
            source = source->next;
        }
        dest->next = NULL;
    }
}

Stack& Stack::operator=(const Stack &s) {
    if (this == &s)
        return *this;  // handle self-assignment
    
    // Free existing resources
    while (!isEmpty())
        pop();
    
    // Copy from source
    if (s.top) 
    {
        top = new node;
        top->item = s.top->item;
        node *source = s.top->next;
        node *dest = top;
        while (source) 
        {
            dest->next = new node;
            dest = dest->next;
            dest->item = source->item;
            source = source->next;
        }
        dest->next = NULL;
    }
    else 
        top = NULL;

    return *this;
}
void Stack::reverse()
{
    node *t1,*t2;
    if(top && top->next)
    {
        t2=NULL;
        do
        {
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        } while (top->next!=NULL);
        top->next=t1;
    }
}
Stack::~Stack()
{
    while(top)
        pop();
}
void Stack::pop()
{
    if(isEmpty())
        cout<<"Stack Underflow\n";
    else
    {   
        node *r;
        r=top;
        top=top->next;
        delete r;
    }
}
int Stack::peek()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
    else
        return top->item;
}
bool Stack::isEmpty()
{
    return top==NULL;
}
void Stack::push(int data)
{
    node *n=new node;
    n->item=data;
    n->next=top;
    top=n;
}
Stack::Stack()
{
    top=NULL;
}
bool isPolindrome(int x)
{
    Stack s;
    int x_copy = x;
    while(x_copy)
    {
        s.push(x_copy%10);
        x_copy/=10;
    }
    int reverse=0;
    while(!s.isEmpty())
    {
        int curr = s.peek();
        s.pop();
        reverse*=10;
        reverse+=curr;
    }
    return (x==reverse); 
}
void reverse(Stack &s1)
{
    Stack s2;
    while(!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1 = s2;
}

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.peek()<<"\n";
    reverse(s);
    cout<<s.peek()<<"\n";
    s.pop();
    cout<<s.peek()<<"\n";
    s.pop();
    cout<<s.peek()<<"\n";
    s.pop();
    cout<<s.peek()<<"\n";
    s.pop();
    cout<<s.peek()<<"\n";
    cout<<isPolindrome(313)<<"\n";
    return 0;
}