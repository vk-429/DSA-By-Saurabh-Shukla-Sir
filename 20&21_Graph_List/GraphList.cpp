#include<iostream>
#include"QueueArray.cpp"
#include"StackArray.cpp"
#include"DynArray.cpp"
using namespace std;

struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        void createList(int);
        void addNode(int,int);
        void printList();
        void setVertex(int);
        node* begin();
        ~AdjList();
};
node* AdjList::begin()
{
    return start;
}
void AdjList::setVertex(int v)
{
    vertex=v;
}
AdjList::AdjList()
{
    start=NULL;
}
AdjList::~AdjList()
{
    node *t;
    while(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
void AdjList::printList()
{
    node* t;
    t=start;
    while(t)
    {
        cout<<"("<<t->vertex<<","<<t->item<<") ";
        t=t->next;
    }
    cout<<"\n";
}
void AdjList::addNode(int data,int v)
{
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
void AdjList::createList(int i)
{
    int data,v;
    int no_of_nodes;
    cout<<"Enter the no. of nodes connected with node "<<i<<" : ";
    cin>>no_of_nodes;
    for(int j=1;j<=no_of_nodes;j++)
    {
        node* n=new node;
        cout<<"Enter vertex number : ";
        cin>>v;
        cout<<"Enter data to store : ";
        cin>>data;
        addNode(data,v);
    }
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        void createGraph(int);
        void addEdge(int,int);
        void printGraph();
        void BFS(int);
        void DFS(int);
        int getnn();
        ~Graph();
        DynArray& adjacentNodes(int);
};
DynArray& Graph::adjacentNodes(int n)
{
    DynArray *p=new DynArray(1);
    if(n<v_count&&n>=0)
    {
        node *t=arr[n].begin();
        while(t)
        {
            p->Append(t->vertex);
            t=t->next;
        }
    }
    return *p;
}
int Graph::getnn()
{
    return v_count;
}
void Graph::DFS(int nn)
{
    bool status[nn]={false};
    Stack S(nn);
    S.push(0);
    status[0]=true;
    int n;
    while(!S.CheckEmpty())
    {
        n=S.peek();
        cout<<"V("<<S.peek()<<") ";
        S.pop();
        node* t;
        t=arr[n].begin();
        while(t)
        {
            if(status[t->vertex]==false)
            {
                S.push(t->vertex);
                status[t->vertex]=true;
            }
            t=t->next;
        }
    }
    cout<<"\n";
}
void Graph::BFS(int nn)
{
    bool status[nn]={false};
    Queue Q(nn);
    Q.insert(0);
    status[0]=true;
    int n;
    while(!Q.isEmpty())
    {
        n=Q.getFront();
        cout<<"V("<<Q.getFront()<<") ";
        Q.remove();
        node* t;
        t=arr[n].begin();
        while(t)
        {
            if(status[t->vertex]==false)
            {
                Q.insert(t->vertex);
                status[t->vertex]=true;
            }
            t=t->next;
        }
    }
    cout<<"\n";
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
        arr[i].printList();
}
Graph::~Graph()
{
    for(int i=0;i<v_count;i++)
        arr[i].~AdjList();
    delete[] arr;
}
void Graph::addEdge(int data,int vno)
{
    int node_no,no_of_edge;
    cout<<"Enter the no of edges connected with this node : ";
    cin>>no_of_edge;
    for(int i=0;i<no_of_edge;i++)
    {
        cout<<"Enter the node numbers which are connected with this node : ";
        cin>>node_no;
        arr[node_no].addNode(data,vno);
    }
}
void Graph::createGraph(int nn)
{
    v_count=nn;
    arr=new AdjList[nn];
    for(int i=0;i<nn;i++)
    {
        arr[i].setVertex(i);
        arr[i].createList(i);
    }
}
Graph::Graph()
{
    v_count=0;
    arr=NULL;
}

int main()
{
    int arr[]={1,2,3};
    int *ptr;
    ptr=arr;
    *ptr++ += *++ptr;
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
    return 0;
}
// int main()
// {
//     Graph G;
//     G.createGraph(6);
//     G.printGraph();
//     G.DFS(6);
//     return 0;
// }