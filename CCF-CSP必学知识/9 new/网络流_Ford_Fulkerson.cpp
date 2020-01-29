#include<bits/stdc++.h>
#define MAIN 1010
#define INF 1000000000
using namespace std;
struct nod
{
    int f,c;
} edge[MAIN][MAIN];
int n,m;
int flag[MAIN],prev[MAIN],alpha[MAIN];
queue <int> q;
void Ford_Fulkerson()
{
    while(1)
    {
        memset(flag,-1,sizeof(flag));
        memset(prev,-1,sizeof(prev));
        memset(alpha,-1,sizeof(alpha));
        while(!q.empty()) q.pop();
        flag[1]=0,prev[1]=0,alpha[1]=INF;
        q.push(1);
        while(!q.empty()&&flag[n]==-1)
        {
            int v=q.front();
            q.pop();
            for(int i=1; i<=n; i++)
            {
                if(flag[i]==-1)
                {
                    if(edge[v][i].c<INF&&edge[v][i].f<edge[v][i].c)
                    {
                        flag[i]=0,prev[i]=v;
                        alpha[i]=min(alpha[v],edge[v][i].c-edge[v][i].f);
                        q.push(i);
                    }
                    else if(edge[i][v].c<INF&&edge[i][v].f>0)
                    {
                        flag[i]=0,prev[i]=-v;
                        alpha[i]=min(alpha[v],edge[i][v].f);
                        q.push(i);
                    }
                }
            }
            flag[v]=1;
        }
        if(flag[n]==-1||!alpha[n]) break;
        int k1=n,k2=abs(prev[k1]),a=alpha[n];
        while(k2)
        {
            if(edge[k2][k1].c<INF) edge[k2][k1].f+=a;
            else edge[k1][k2].f-=a;
            k1=k2,k2=abs(prev[k1]);
        }
    }
    int maxFlow=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==1&&edge[i][j].f<INF) maxFlow+=edge[i][j].f;
            if(edge[i][j].f<INF) printf("%d->%d:%d\n",i,j,edge[i][j].f);
        }
    }
    printf("%d\n",maxFlow);
}
int main()
{
    int u,v,c,f;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            edge[i][j].f=edge[i][j].c=INF;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d%d",&u,&v,&c,&f);
        edge[u][v].c=c,edge[u][v].f=f;
    }
    Ford_Fulkerson();
    return 0;
}
