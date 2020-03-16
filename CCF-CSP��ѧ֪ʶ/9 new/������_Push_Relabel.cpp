#include<iostream>
#include<cstdio>
#include<cstring>
#define MAIN 1010
#define INF 1000000000
using namespace std;
struct node
{
    int f,c;
} edge[MAIN][MAIN];
int n,m;
int dist[MAIN],e[MAIN];
bool Relabel(int u)
{
    int minDist=INF;
    for(int i=1; i<=n; i++)
    {
        if(edge[u][i].f<edge[u][i].c)
            minDist=min(minDist,dist[i]);
    }
    if( minDist==INF) return false;
    dist[u]=minDist+1;
    for(int i=1; i<=n; i++)
    {
        if(!e[u]) break;
        if(dist[i]==minDist&&edge[u][i].f<edge[u][i].c)
        {
            int flow=min(e[u],edge[u][i].c-edge[u][i].f);
            edge[u][i].f+=flow;
            edge[i][u].f=-edge[u][i].f;
            e[u]-=flow;
            e[i]+=flow;
        }
    }
    return true;
}
void Push_Relabel()
{
    memset(dist,0,sizeof(dist)),dist[1]=n;
    memset(e,0,sizeof(e));
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(edge[1][i].c>0)
        {
            int flow=edge[1][i].c;
            edge[1][i].f+=flow;
            edge[i][1].f=-edge[1][i].f;
            e[1]-=flow;
            e[i]+=flow;
        }
    }
    while(1)
    {
        if(!flag) break;
        flag=false;
        for(int i=1; i<=n-1; i++)
            if(e[i]>0)
                flag=flag||Relabel(i);
    }
    printf("%d\n",e[n]);
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(edge,0,sizeof(edge));
        for(int i=1; i<=m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            edge[u][v].c+=c;
        }
        Push_Relabel();
    }
    return 0;
}
