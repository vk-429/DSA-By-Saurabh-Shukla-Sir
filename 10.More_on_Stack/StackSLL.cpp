#include"SLLADT.cpp"

class Stack:private SLL
{
    public:
        Stack();
        void push(int);
        int peek();
        void pop();
        Node* start();
        Stack& operator=(const Stack&);
        bool operator==(Stack&);
        ~Stack();
};
Stack::~Stack(){}
Stack::Stack():SLL(){}
bool Stack::operator==(Stack& s)
{
    Node* current1 = begin();
    Node* current2 = s.begin();

    // Compare elements one by one
    while (current1 && current2)
    {
        if (current1->item != current2->item)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }

    // If one stack is longer than the other, they are not equal
    if (current1 || current2)
        return false;

    return true; // Stacks are equal
}

Stack& Stack::operator=(const Stack& s)
{
    SLL::operator=(s);
    return *this;
}
Node* Stack::start()
{
    return begin();
}
void Stack::pop()
{
    if(begin())
        deleteFirst();
    else
        cout<<"Stack Underflow\n";
}
int Stack::peek()
{
    if(begin())
        return begin()->item;
    else
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
}
void Stack::push(int data)
{
    insertAtStart(data);
}
void reverseStack(Stack &s1)
{
    Stack s2;
    while(s1.start())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
bool checkPolyndrome(Stack &s)
{
    Stack s1;
    reverseStack(s);
    s1=s;
    return s==s1;
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
    reverseStack(s);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<"\n";
    return 0;
}