#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1<<29
#define MAXN 100
int n,edge[MAXN][MAXN];
int dist[MAXN],path[MAXN];
void bellman(int v0)
{
    for(int i=0; i<n; i++)
    {
        dist[i]=edge[v0][i];
        if(i!=v0&&dist[i]<INF) path[i]=v0;
        else path[i]=-1;
    }
    for(int k=2; k<n; k++)
        for(int u=0; u<n; u++)
            if(u!=v0)
                for(int j=0; j<n; j++)
                    if(edge[j][u]<INF&&dist[j]+edge[j][u]<dist[u])
                    {
                        dist[u]=dist[j]+edge[j][u];
                        path[u]=j;
                    }
}
int main()
{
    int u,v,w;
    scanf("%d",&n);
    while(1)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(u==-1&&v==-1&&w==-1) break;
        edge[u][v]=w;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) edge[i][j]=0;
            else if(!edge[i][j]) edge[i][j]=INF;
        }
    }
    bellman(0);
    int shortest[MAXN];
    for(int i=1; i<n; i++)
    {
        printf("%d\t",dist[i]);
        memset(shortest,0,sizeof(shortest));
        int k=0;
        shortest[k]=i;
        while(path[shortest[k]])
        {
            k++;
            shortest[k]=path[shortest[k-1]];
        }
        k++;
        shortest[k]=0;
        for(int j=k; j>0; j--) printf("%d->",shortest[j]);
        printf("%d\n",shortest[0]);
    }
    return 0;
}
