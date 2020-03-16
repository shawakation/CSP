#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000
#define MAXN 21
using namespace std;
int n,m;
int edge[MAXN][MAXN];
int lowcost[MAXN],nearvex[MAXN];
void prim(int u0)
{
    int sumweight=0;
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=edge[u0][i];
        nearvex[i]=u0;
    }
    nearvex[u0]=-1;
    for(int i=1;i<n;i++)
    {
        int min=INF;
        int v=-1;
        for(int j=1;j<=n;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]<min)
            {
                v=j;
                min=lowcost[j];
            }
        }
        if(v!=-1)
        {
            printf("%d %d %d\n",nearvex[v],v,lowcost[v]);
            nearvex[v]=-1;
            sumweight+=lowcost[v];
        }
        for(int j=1;j<=n;j++)
        {
            if(nearvex[j]!=-1&&edge[v][j]<lowcost[j])
            {
                lowcost[j]=edge[v][j];
                nearvex[j]=v;
            }
        }
    }
    printf("weight of MST is %d\n",sumweight);
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(edge,0,sizeof(edge));
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge[u][v]=edge[v][u]=w;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) edge[i][j]=0;
            else if(!edge[i][j]) edge[i][j]=INF;
        }
    prim(1);
    return 0;
}
