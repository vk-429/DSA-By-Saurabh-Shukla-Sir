#include "Que4_Generic_Array.cpp"
using namespace std;

template<typename arg_type,size_t size>
class Stack:private Array<arg_type,size>
{
    public:
        Stack();
        Stack(Stack &);
        void push(arg_type);
        arg_type peek();
        void pop();
        virtual bool CheckFull();
        virtual bool CheckEmpty();
        int getStackSize();
        Stack<arg_type,size>& operator=(const Stack<arg_type,size> &);
        ~Stack();
};

template<typename arg_type,size_t size>
Stack<arg_type,size>::~Stack(){}

template<typename arg_type,size_t size>
Stack<arg_type,size>& Stack<arg_type,size>::operator=(const Stack<arg_type,size> &S)
{
    if (this != &S) 
        Array<arg_type, size>::operator=(S);
    return *this;
}

template<typename arg_type,size_t size>
int Stack<arg_type,size>::getStackSize()
{
    return this->Count();
}

template<typename arg_type,size_t size>
bool Stack<arg_type,size>::CheckEmpty()
{
    return Array<arg_type, size>::CheckEmpty();
}

template<typename arg_type,size_t size>
bool Stack<arg_type,size>::CheckFull()
{
    return Array<arg_type, size>::CheckFull();
}

template<typename arg_type,size_t size>
void Stack<arg_type,size>::pop()
{
    if (!CheckEmpty())
        this->Delete(this->Count() - 1);
    else
        cout << "Stack Underflow\n";
}

template<typename arg_type,size_t size>
arg_type Stack<arg_type,size>::peek()
{
    if (!CheckEmpty())
        return this->get(this->Count() - 1);
    else
        cout << "Stack is Empty\n";
    return arg_type();
}

template<typename arg_type,size_t size>
void Stack<arg_type,size>::push(arg_type data)
{
    if (CheckFull())
        cout << "Stack Overflow\n";
    else
        this->Append(data);
}

template<typename arg_type,size_t size>
Stack<arg_type,size>::Stack(Stack<arg_type,size> &S):Array<arg_type,size>(S)
{}

template<typename arg_type,size_t size>
Stack<arg_type,size>::Stack():Array<arg_type,size>(){}


// template<typename arg_type,size_t size>
// void pushInStack(Stack<arg_type,size> &s, Stack<arg_type,size> &minStack, int data)
// {
//     s.push(data);
//     if (minStack.CheckEmpty())
//         minStack.push(data);
//     else
//     {
//         if (data > minStack.peek())
//             minStack.push(minStack.peek());
//         else
//             minStack.push(data);
//     }
// }

// template<typename arg_type,size_t size>
// void popFromStack(Stack<arg_type,size> &s, Stack<arg_type,size> &minStack)
// {
//     s.pop();
//     minStack.pop();
// }


// template<typename arg_type,size_t size>
// void reverseStack(Stack<arg_type,size> &s1)
// {
//     Stack s2(s1.getStackSize());
//     while(!s1.CheckEmpty())
//     {
//         s2.push(s1.peek());
//         s1.pop();
//     }
//     s1=s2;
// }

int main()
{
    Stack<int,5> s;
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(2);
    s.push(10);
    while(!s.CheckEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<"\n";

    Stack<string,5> s2;
    s2.push("One");
    s2.push("four");
    s2.push("Hello");
    s2.push("bye");
    cout<<s2.CheckEmpty()<<"\n";
    cout<<s2.CheckFull()<<"\n";
    cout<<s2.getStackSize()<<"\n";
    Stack<string,5> s3;
    s3=s2;
    Stack<string,5> s4=s3;
    while(!s2.CheckEmpty())
    {
        cout<<s2.peek()<<" ";
        s2.pop();
    }
    cout<<"\n";
    while(!s3.CheckEmpty())
    {
        cout<<s3.peek()<<" ";
        s3.pop();
    }
    cout<<"\n";
    while(!s4.CheckEmpty())
    {
        cout<<s4.peek()<<" ";
        s4.pop();
    }
    cout<<"\n";
    return 0;
}