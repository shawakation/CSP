#include<bits/stdc++.h>
#define MAIN 110
#define INF 1<<29
using namespace std;
int n,m,edge[MAIN][MAIN];
int dist[MAIN],path[MAIN];
void Bellman(int v0)
{
    for(int i=1; i<=n; i++)
    {
        dist[i]=edge[v0][i];
        if(edge[v0][i]<INF) path[i]=v0;
        else path[i]=-1;
    }
    for(int i=2; i<n; i++)
    {
        for(int j=1; j<=n; j++)
            if(j!=v0)
            {
                for(int k=1; k<=n; k++)
                    if(dist[k]+edge[k][j]<dist[j])
                    {
                        dist[j]=dist[k]+edge[k][j];
                        path[j]=k;
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
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j) edge[i][j]=INF;
            else edge[i][j]=0;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u][v]=w;
    }
    Bellman(1);
    return 0;
}
