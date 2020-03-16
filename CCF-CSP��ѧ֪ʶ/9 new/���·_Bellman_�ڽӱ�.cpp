#include<bits/stdc++.h>
#define MAIN 110
#define INF 1<<29
using namespace std;
int n,m;
struct node
{
    int u,v,w;
} edge[MAIN];
int dist[MAIN],path[MAIN];
void Bellman_Ford(int v0)
{
    for(int i=1;i<=n;i++)
        dist[i]=INF,path[i]=-1;
    dist[v0]=0;
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(edge[j].w+dist[edge[j].u]<dist[edge[j].v])
            {
                dist[edge[j].v]=edge[j].w+dist[edge[j].u];
                path[edge[j].v]=edge[j].u;
            }

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
    for(int i=1;i<=m;i++)
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    Bellman_Ford(1);
    return 0;
}
