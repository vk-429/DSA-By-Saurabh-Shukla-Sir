#include<iostream>
#include"QueueArray.cpp"
#include"StackArray.cpp"
#include"DynArray.cpp"
using namespace std;

class Graph
{
    private:
        int v_count;
        int e_count;
        int **adj;
    public:
        Graph();
        void createGraph(int,int);
        void printGraph();
        void printAdjacent(int);
        bool checkIsolated(int);
        void BFS(int,int);
        void DFS(int,int);
        int getnn();
        DynArray& adjacentNodes(int);
        ~Graph();
};
DynArray& Graph::adjacentNodes(int n)
{
    DynArray *p=new DynArray(1);
    if(n<v_count&&n>=0)
    {
        for(int i=0;i<v_count;i++)
            if(adj[n][i]==1)
                p->Append(i);
    }
    return *p;
}
int Graph::getnn()
{
    return v_count;
}
void Graph::DFS(int nn,int s)
{
    bool status[nn]={false};
    Stack S(nn);
    S.push(s);
    status[s]=true;
    int n;
    while(!S.CheckEmpty())
    {
        n=S.peek();
        cout<<"V("<<S.peek()<<") ";
        S.pop();
        for(int i=0;i<nn;i++)
        {
            if(adj[n][i]==1)
            {
                if(status[i]==false)
                {
                    S.push(i);
                    status[i]=true;
                }
            }
        }
    }
    cout<<"\n";
}
void Graph::BFS(int nn,int s)
{
    bool status[nn]={false};
    Queue Q(nn);
    Q.insert(s);
    status[s]=true;
    int n;
    while(!Q.isEmpty())
    {
        n=Q.getFront();
        cout<<"V("<<Q.getFront()<<") ";
        Q.remove();
        for(int i=0;i<nn;i++)
        {
            if(adj[n][i]==1)
            {
                if(status[i]==false)
                {
                    Q.insert(i);
                    status[i]=true;
                }
            }
        }
    }
    cout<<"\n";
}
Graph::~Graph()
{
    for(int i=0;i<v_count;i++)
        delete[] adj[i];
    delete[] adj;
}
bool Graph::checkIsolated(int n)
{
    for(int i=0;i<v_count;i++)
        if(adj[n][i]==1)
            return false;
    return true;
}
void Graph::printAdjacent(int n)
{
    for(int i=0;i<v_count;i++)
        if(adj[n][i]==1)
            cout<<"V("<<i<<") ";
    cout<<"\n";
}
void Graph::printGraph()
{
    int i,j;
    for(i=0;i<v_count;i++)
    {
        for(j=0;j<v_count;j++)
            cout<<adj[i][j]<<" ";
        cout<<"\n";
    }
}
void Graph::createGraph(int nn,int ne)
{
    v_count=nn;
    e_count=ne;
    adj=new int*[nn];
    for(int i=0;i<nn;i++)
        adj[i]=new int[nn];
    int u,v,i,j;
    for(i=0;i<nn;i++)
        for(j=0;j<nn;j++)
            adj[i][j]=0;
    for(int k=0;k<ne;k++)
    {
        cout<<"\nEnter node numbers connecting edge "<<k<<" : ";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    // for(i=0;i<(nn-1);i++)
    // {
    //     adj[i][i]=0;
    //     for(j=i+1;j<nn;j++)
    //     {
    //         if(ne>0)
    //         {
    //             adj[j-i-1][j]=1;
    //             adj[j][j-i-1]=1;
    //             ne--;
    //         }
    //         else
    //         {
    //             adj[j-i-1][j]=1;
    //             adj[j][j-i-1]=1;
    //         }
    //     }
    // }
    // adj[i][i]=0;
}
Graph::Graph()
{
    v_count=0;
    e_count=0;
    adj=NULL;
}

// int main()
// {
//     Graph G;
//     G.createGraph(6,9);
//     G.printGraph();
//     G.BFS(6,0);
//     //G.DFS(6);
//     return 0;
// }