#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
int nx,ny,m;
bool g[MAXN][MAXN];
int cx[MAXN],cy[MAXN];
int pred[MAXN];
int MaxMatch()
{
    int res=0,temp;
    queue <int> q;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    for(int i=1; i<=nx; i++)
    {
        if(cx[i]!=-1) continue;
        for(int j=1; j<=ny; j++) pred[j]=-2;
        while(!q.empty()) q.pop();
        for(int j=1; j<=ny; j++)
            if(g[i][j])
            {
                pred[j]=-1;
                q.push(j);
            }
        while(!q.empty())
        {
            temp=q.front();
            if(cy[temp]==-1) break;
            q.pop();
            for(int j=1; j<=ny; j++)
                if(pred[j]==-2&&g[cy[temp]][j])
                {
                    pred[j]=temp;
                    q.push(j);
                }
        }
        if(q.empty()) continue;
        while(pred[temp]>-1)
        {
            cx[cy[pred[temp]]]=temp;
            cy[temp]=cy[pred[temp]];
            temp=pred[temp];
        }
        cy[temp]=i;
        cx[i]=temp;
        res++;
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
