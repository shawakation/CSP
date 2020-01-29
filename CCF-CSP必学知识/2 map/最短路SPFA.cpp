#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 10000000
#define MAXN 10
using namespace std;
struct Arcnode
{
    int to;
    int weight;
    Arcnode *next;
};
queue <int> Q;
int n;
Arcnode *List[MAXN];
int inq[MAXN];
int dist[MAXN],path[MAXN];
void SPFA(int src)
{
    int u;
    Arcnode *temp;
    for(int i=0; i<n; i++)
    {
        dist[i]=INF;
        path[i]=src;
        inq[i]=0;
    }
    dist[src]=0;
    path[src]=src;
    inq[src]++;
    Q.push(src);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        inq[u]--;
        temp=List[u];
        while(temp!=NULL)
        {
            int v=temp->to;
            if(dist[v]>dist[u]+temp->weight)
            {
                dist[v]=dist[u]+temp->weight;
                path[v]=u;
                if(!inq[v])
                {
                    Q.push(v);
                    inq[v]++;
                }
            }
            temp=temp->next;
        }
    }
}
int main()
{
    int u,v,w;
    scanf("%d",&n);
    memset(List,0,sizeof(List));
    Arcnode* temp;
    while(1)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(u==-1&&v==-1&&w==-1) break;
        temp=new Arcnode;
        temp->to=v;
        temp->weight=w;
        temp->next=NULL;
        if(List[u]==NULL) List[u]=temp;
        else
        {
            temp->next=List[u];
            List[u]=temp;
        }
    }
    SPFA(0);
    for(int j=0; j<n; j++)
    {
        temp=List[j];
        while(temp!=NULL)
        {
            List[j]=temp->next;
            delete temp;
            temp=List[j];
        }
    }
    int shortest[MAXN];
    for(int i=1; i<n; i++)
    {
        printf("%d\t",dist[i]);
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]])
            shortest[++k]=path[shortest[k-1]];
        shortest[++k]=0;
        for(int j=k; j>0; j--)
            printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    return 0;
}
