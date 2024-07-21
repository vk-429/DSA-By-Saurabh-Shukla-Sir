#include"GraphList.cpp"

void bfs(Graph &G,int s)
{
    int n,u;
    bool status[G.getnn()]={false};
    Queue Q(G.getnn());
    Q.insert(s);
    status[s]=true;
    while(!Q.isEmpty())
    {
        n=Q.getFront();
        cout<<"V("<<n<<") ";
        Q.remove();
        DynArray adjacent=G.adjacentNodes(n);
        for(int i=0;i<adjacent.Count();i++)
        {
            u=adjacent.get(i);
            if(status[u]==false)
            {
                Q.insert(u);
                status[u]=true;
            }
        }
    }
    cout<<"\n";
}


void dfs(Graph &G,int s)
{
    int n,u;
    bool status[G.getnn()]={false};
    Stack S(G.getnn());
    S.push(s);
    status[s]=true;
    while(!S.CheckEmpty())
    {
        n=S.peek();
        cout<<"V("<<n<<") ";
        S.pop();
        DynArray adjacent=G.adjacentNodes(n);
        for(int i=0;i<adjacent.Count();i++)
        {
            u=adjacent.get(i);
            if(status[u]==false)
            {
                S.push(u);
                status[u]=true;
            }
        }
    }
    cout<<"\n";
}

int main()
{
    Graph G;
    G.createGraph(5);
    bfs(G,0);
    return 0;
}
