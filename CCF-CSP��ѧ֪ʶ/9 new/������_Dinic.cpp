#include<bits/stdc++.h>
#define MAIN 1010
#define INF 1000000000
using namespace std;
int n,m;
int edge[MAIN][MAIN];
int level[MAIN];
queue <int> q;
int BFS()
{
    while(!q.empty()) q.pop();
    q.push(1);
    memset(level,-1,sizeof(level));
    level[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=1; i<=n; i++)
            if(level[i]==-1&&edge[u][i]>0)
            {
                level[i]=level[u]+1;
                q.push(i);
            }
    }
    if(level[n]!=-1) return true;
    return false;
}
int DFS(int u,int minn)
{
    if(u==n) return minn;
    int val=0;
    for(int i=1; i<=n; i++)
        if(edge[u][i]>0&&level[i]==level[u]+1
           &&(val=DFS(i,min(minn,edge[u][i]))))
        {
            edge[u][i]-=val;
            edge[i][u]+=val;
            return val;
        }
    return 0;

}
void Dinic()
{
    int maxFlow=0,temp;
    while(BFS())
        while(temp=DFS(1,INF))
            maxFlow+=temp;
    printf("%d\n",maxFlow);
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
            edge[u][v]+=c;
        }
        Dinic();
    }
    return 0;
}
