#include"ArrayADT.cpp"
using namespace std;

class Stack:private Array
{
    public:
        Stack(int);
        Stack(Stack &);
        void push(int);
        int peek();
        void pop();
        ~Stack();
        virtual bool CheckFull();
        virtual bool CheckEmpty();
        int getStackSize();
        Stack& operator=(const Stack &);
};
Stack& Stack::operator=(const Stack &S)
{
    Array::operator=(S);
    return *this;
}
int Stack::getStackSize()
{
    return getCapacity();
}
Stack::Stack(Stack &S):Array(S)
{}
bool Stack::CheckEmpty()
{
    return Array::CheckEmpty();
}
bool Stack::CheckFull()
{
    return Array::CheckFull();
}
Stack::~Stack(){}
void Stack::pop()
{
    if(!CheckEmpty())
        Delete(Count()-1);
    else
        cout<<"Stack Underflow\n";
}
int Stack::peek()
{
    if(!CheckEmpty())
        return get(Count()-1);
    else
        cout<<"Stack is Empty\n";
    return 0;
}
Stack::Stack(int cap):Array(cap){}
void Stack::push(int data)
{
    if(CheckFull())
        cout<<"Stack Overflow\n";
    else
        Append(data);
}
void reverseStack(Stack &s1)
{
    Stack s2(s1.getStackSize());
    while(!s1.CheckEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
void pushInStack(Stack &s, Stack &minStack, int data)
{
    s.push(data);
    if (minStack.CheckEmpty())
        minStack.push(data);
    else
        minStack.push(min(minStack.peek(),data));
}
void popFromStack(Stack &s, Stack &minStack)
{
    s.pop();
    minStack.pop();
}
int main()
{
    Stack s(5);
    Stack minStack(5);
    pushInStack(s,minStack,50);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    pushInStack(s,minStack,40);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    pushInStack(s,minStack,60);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    pushInStack(s,minStack,70);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    pushInStack(s,minStack,30);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    cout<<"Poping Start\n";
    popFromStack(s,minStack);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    popFromStack(s,minStack);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    popFromStack(s,minStack);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    popFromStack(s,minStack);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    popFromStack(s,minStack);
    cout<<"Current min value is "<<minStack.peek()<<"\n";
    // s.push(10); 
    // // if(minStack.CheckEmpty())
    // //     minStack(10);
    // // else

    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // cout<<s.peek()<<"\n";
    // //s.pop();
    // //cout<<s.peek()<<"\n";
    // reverseStack(s);
    // cout<<s.peek()<<"\n";
    // cout<<endl;
    return 0;
}