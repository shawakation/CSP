#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
int nx,ny,m;
bool g[MAXN][MAXN];
int cx[MAXN],cy[MAXN];
bool use[MAXN];
int path(int u)
{
    for(int v=1; v<=ny; v++)
    {
        if(g[u][v]&&!use[v])
        {
            use[v]=true;
            if(cy[v]==-1||path(cy[v]))
            {
                cx[u]=v;
                cy[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    for(int i=1; i<=nx; i++)
    {
        if(cx[i]==-1)
        {
            memset(use,false,sizeof(use));
            res+=path(i);
        }
    }
    return res;
}
int main()
{
    memset(g,false,sizeof(g));
    cin>>nx>>ny>>m;
    for(int i=1; i<=m; i++)
    {
        int xx,yy;
        cin>>xx>>yy;
        g[xx][yy]=true;
    }
    cout<<MaxMatch()<<endl;
    return 0;
}
/*
3 4 6
1 2
1 3
2 2
3 1
3 3
3 4
2 2 3
1 1
1 2
2 1
*/
