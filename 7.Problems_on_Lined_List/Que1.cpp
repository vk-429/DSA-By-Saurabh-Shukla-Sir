#include"SLLADT.cpp"
struct node
{
    int coeff;
    int deg;
    node *next;
};
class Polynomial
{
    private:
        node* start;
    public:
        Polynomial();
        void insert(int ,int );
        Polynomial& operator=(const Polynomial &other);
        void printPolynomial();
        node* getStart();
};
void Polynomial::printPolynomial()
{
    node *t;
    t=start;
    while(t)
    {
        cout<<"Coefficiant = "<<t->coeff<<" Degree = "<<t->deg<<"\n";
        t=t->next;
    }
}
Polynomial add(Polynomial P1,Polynomial P2)
{
    Polynomial A;
    node *t1,*t2;
    t1=P1.getStart();
    t2=P2.getStart();
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->deg==t2->deg)
        {
            A.insert((t1->coeff+t2->coeff),t1->deg);
            t1=t1->next;
            t2=t2->next;
        }
        else
        {
            if(t1->deg>t2->deg)
            {
                A.insert(t1->coeff,t1->deg);
                t1=t1->next;
            }
            else
            {
                A.insert(t2->coeff,t2->deg);
                t2=t2->next;
            }
        }
    }
    while(t2!=NULL)
    {
        A.insert(t2->coeff,t2->deg);
        t2=t2->next;
    }
    while(t1!=NULL)
    {
        A.insert(t1->coeff,t1->deg);
        t1=t1->next;
    }
    return A;
}
node* Polynomial::getStart()
{
    return start;
}
Polynomial::Polynomial()
{
    start=NULL;
}
void Polynomial::insert(int c,int d)
{
    node *n=new node;
    node *t,*p;
    n->coeff=c;
    n->deg=d;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        t=start;
        if(t->deg<d)
        {
            n->next=t;
            start=n;
        }
        else
        {
            p=t;
            t=t->next;
            while(t!=NULL)
            {
                if(d>=t->deg)
                    break;
                p=t;
                t=t->next;
            }
            if(t!=NULL && d == t->deg)
                t->deg += d;
            else
            {
                n->next=t;
                p->next=n;
            }
        }
    }
}
Polynomial& Polynomial::operator=(const Polynomial &other)
{
    // Check for self-assignment
    if (this == &other)
        return *this;

    // Clear the current list
    while (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }

    // Copy elements from 'other' to 'this'
    node *otherCurrent = other.start;
    while (otherCurrent)
    {
        insert(otherCurrent->coeff, otherCurrent->deg);
        otherCurrent = otherCurrent->next;
    }

    return *this;
}


















int count(SLL &obj)
{
    Node* t;
    int ans=0;
    t=obj.begin();
    while(t)
    {
        t=t->next;
        ans++;
    }
    return ans;
}
void reverse(SLL &obj)
{
    Node *current = obj.begin();
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer

        // Move pointers to the next pair of nodes
        prev = current;
        current = next;
    }

    // Update the start pointer to the new head of the reversed list
    obj.setStart(prev);
}

int middle(SLL &obj)
{
    Node *r1,*r2;
    if(obj.begin())
    {
        r1=obj.begin();
        r2=r1;
        while(r2)
        {
            if(r2->next)
                r2=r2->next->next;
            else
                break;
            r1=r1->next;
        }
        return r1->item;
    }
    else
    {
        cout<<"List is Empty\n";
        return -1;
    }
}


// bool is_cycle(SLL &obj)
// {
//     Node *t1,*t2;
//     t1=t2=obj.begin();
//     do
//     {
//         if(t1==NULL)
//             return false;
//         if(t1->next)
//             t1=t1->next->next;
//         else
//             return false;
//         t2=t2->next;
//     } while (t1!=t2);
//     if(t1==t2)
//     return true;
// }
bool is_cycle(SLL &obj)
{
    Node *t1 = obj.begin();
    Node *t2 = obj.begin();
    while (t1 != NULL && t1->next != NULL)
    {
        t1 = t1->next->next;
        t2 = t2->next;
        if (t1 == t2)
            return true;
    }

    return false;
}

int length_of_cycle(SLL &obj)
{
    int count=1;
    Node *t1,*t2;
    if(is_cycle(obj))
    {
        t2=t1=obj.begin();
        do
        {
            t1=t1->next->next;
            t2=t2->next;
        }while(t1!=t2);
        while(t1->next!=t2)
        {
            count++;
            t1=t1->next;
        }
        return count;
    }
    return 0;
}
void sort(SLL &obj)
{
    Node *t1,*t2;
    t1=t2=obj.begin();
    if(t1)
    {
        while(t1->next)
        {
            t2=t1->next;
            while(t2)
            {
                if(t1->item > t2->item)
                {
                    t1->item = t1->item+t2->item;
                    t2->item = t1->item-t2->item;
                    t1->item = t1->item-t2->item;
                }
                t2=t2->next;
            }
            t1=t1->next;
        }
    }
    else
        cout<<"List is Empty\n";
}
SLL merge(SLL &L1,SLL &L2)
{
    SLL ML;
    int i;
    Node *t1,*t2;
    t1=L1.begin();
    t2=L2.begin();
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->item>t2->item)
        {
            ML.insertAtStart(t2->item);
            t2=t2->next;
        }
        else
        {
            ML.insertAtStart(t1->item);
            t1=t1->next;
        }
    }
    while(t2!=NULL)
    {
        ML.insertAtStart(t2->item);
        t2=t2->next;
    }
    while(t1!=NULL)
    {
        ML.insertAtStart(t1->item);
        t1=t1->next;   
    }
    reverse(ML);
    return ML;
}
SLL sumList(SLL &L1,SLL &L2)
{
    SLL A;
    Node* t1,*t2;
    t1=L1.begin();
    t2=L2.begin();
    int sum=0,carry=0;
    while (t1!=NULL && t2!=NULL)
    {
        sum=t1->item+t2->item+carry;
        A.insertAtStart(sum%10);
        carry=sum/10;
        t1=t1->next;
        t2=t2->next;
    }
    if(t1==NULL && t2==NULL)
    {
        if(carry!=0)
            A.insertAtStart(carry);
    }
    else if(t1==NULL)
    {
        while (t2!=NULL)
        {
            sum=t2->item+carry;
            A.insertAtStart(sum%10);
            carry=sum/10;
            t2=t2->next;
        } 
        if(carry!=0)
            A.insertAtStart(carry);
    }
    else
    {
        while (t1!=NULL)
        {
            sum=t1->item+carry;
            A.insertAtStart(sum%10);
            carry=sum/10;
            t1=t1->next;
        }
        if(carry!=0)
            A.insertAtStart(carry);
    }
    return A;
}

int main()
{
    SLL S1,S2,S3;
    S1.insertAtLast(9);
    S1.insertAtLast(5);
    S1.insertAtLast(7);
    S1.insertAtLast(1);
    S1.insertAtLast(3);
    
    S1.printList();
    // sort(S1);
    // S1.printList();
    S2.insertAtLast(1);
    S2.insertAtLast(8);
    S2.insertAtLast(9);
    S2.insertAtLast(4);
    S2.printList();
    // sort(S2);
    // S2.printList();
    // S3=merge(S1,S2);
    // S3.printList();
    SLL S4;
    S4 = sumList(S1,S2);
    S4.printList();
    // cout<<count(S1)<<"\n";
    // cout<<count(S2)<<"\n";
    cout<<middle(S1)<<"\n";
    cout<<middle(S2)<<"\n";
    cout<<is_cycle(S1)<<"\n";
    cout<<length_of_cycle(S1)<<"\n";
    cout<<is_cycle(S2)<<"\n";
    cout<<length_of_cycle(S2)<<"\n";
    Polynomial P1,P2,P3;
    P1.insert(5,3); 
    P1.insert(-4,2);
    P1.insert(5,1); 
    P1.insert(10,0);
    P2.insert(7,2);
    P2.insert(5,1);
    P2.insert(4,0);
    
    cout<<"Polynomial P1 :-\n";
    P1.printPolynomial();
    cout<<"Polynomial P2 :-\n";
    P2.printPolynomial();
    cout<<"Sum of P1 and P2 :-\n";
    P3=add(P1,P2);
    P3.printPolynomial();
    return 0;
}