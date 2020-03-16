#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1<<29
#define MAXN 100
struct edge
{
    int u,v,w;
}edges[MAXN];
int n,m,dist[MAXN],path[MAXN];
void bellman(int v0)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=INF; path[i]=-1;
    }
    dist[v0]=0;
    for(int k=1;k<n;k++)
    {
        for(int i=0;i<m;i++)
        {
            if(dist[edges[i].u]!=INF&&edges[i].w+dist[edges[i].u]<dist[edges[i].v])
            {
                dist[edges[i].v]=edges[i].w+dist[edges[i].u];
                path[edges[i].v]=edges[i].u;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    bellman(0);
    int shortest[MAXN];
    for(int i=1;i<n;i++)
    {
        printf("%d\t",dist[i]);
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]])
        {
            k++; shortest[k]=path[shortest[k-1]];
        }
        k++; shortest[k]=0;
        for(int j=k;j>0;j--) printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    return 0;
}
