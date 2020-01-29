#include<bits/stdc++.h>
#define MAIN 110
#define MAXN 1010
#define INF 1<<29
using namespace std;
int n,m;
struct node
{
    int v,w;
    int next;
} edge[MAXN];
int first[MAIN],dist[MAIN],path[MAIN];
bool inq[MAIN];
void SPFA(int v0)
{
    queue <int> q;
    while(!q.empty()) q.pop();
    for(int i=1; i<=n; i++)
        dist[i]=INF,path[i]=v0,inq[i]=false;
    dist[v0]=0,path[v0]=-1,inq[v0]=true;
    q.push(v0);
    while(!q.empty())
    {
        int uu=q.front();
        q.pop(),inq[uu]=false;
        int temp=first[uu];
        while(temp!=-1)
        {
            if(dist[uu]+edge[temp].w<dist[edge[temp].v])
            {
                dist[edge[temp].v]=dist[uu]+edge[temp].w;
                path[edge[temp].v]=uu;
            }
            if(!inq[edge[temp].v])
            {
                q.push(edge[temp].v);
                inq[edge[temp].v]=true;
            }
            temp=edge[temp].next;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i==v0) continue;
        cout<<dist[i]<<":"<<endl;
        int shortest[MAIN],num=0,temp=i;
        shortest[++num]=i;
        while(temp!=v0)
        {
            temp=path[temp];
            shortest[++num]=temp;
        }
        for(int i=num; i>0; i--)
            if(i>1) cout<<shortest[i]<<"->";
            else cout<<shortest[i]<<endl;
    }
}
int main()
{
    cin>>n>>m;
    memset(first,-1,sizeof(first));
    for(int i=1; i<=m; i++)
    {
        int uu,vv,ww;
        cin>>uu>>vv>>ww;
        edge[i].v=vv,edge[i].w=ww;
        if(first[uu]<0) first[uu]=i,edge[i].next=-1;
        else edge[i].next=first[uu],first[uu]=i;
    }
    SPFA(1);
    return 0;
}
