#include<bits/stdc++.h>
#define MAIN 110
#define INF 1<<29
using namespace std;
int n,m,edge[MAIN][MAIN];
int lowcost[MAIN],nearvex[MAIN];
int Prim()
{
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        lowcost[i]=edge[i][1];
        nearvex[i]=1;
    }
    nearvex[1]=-1,lowcost[1]=0;
    for(int i=1; i<n; i++)
    {
        int minn=INF,point=-1;
        for(int j=1; j<=n; j++)
            if(nearvex[j]!=-1&&lowcost[j]<minn)
            {
                minn=lowcost[j];
                point=j;
            }
        for(int j=1; j<=n; j++)
            if(nearvex[j]!=-1&&edge[point][j]<INF&&minn==edge[point][j]&&nearvex[point]!=j)
                return -1;
        if(point!=-1)
        {
            sum+=minn;
            nearvex[point]=-1;
        }
        for(int i=1; i<=n; i++)
            if(nearvex[i]!=-1&&lowcost[i]>edge[i][point])
            {
                nearvex[i]=point;
                lowcost[i]=edge[i][point];
            }
    }
    return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(edge,0,sizeof(edge));
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(!w) edge[u][v]=edge[v][u]=INF;
        else edge[u][v]=edge[v][u]=w;
    }
    cout<<Prim()<<endl;
    return 0;
}

