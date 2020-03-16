#include<bits/stdc++.h>
#define MAIN 110
#define INF 1<<29
using namespace std;
int n,m,edge[MAIN][MAIN];
int A[MAIN][MAIN],path[MAIN][MAIN];
void Floyd()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            A[i][j]=edge[i][j];
            if(i!=j&&edge[i][j]<INF) path[i][j]=i;
            else path[i][j]=-1;
        }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(k==i||k==j) continue;
                if(A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=path[k][j];
                }
            }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            cout<<i<<"-"<<j<<":"<<endl;
            int shortest[MAIN],num=0,temp=j;
            shortest[++num]=j;
            while(temp!=i)
            {
                temp=path[i][temp];
                shortest[++num]=temp;
            }
            for(int i=num; i>0; i--)
                if(i>1) cout<<shortest[i]<<"->";
                else cout<<shortest[i]<<endl;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) edge[i][j]=0;
            else edge[i][j]=INF;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u][v]=w;
    }
    Floyd();
    return 0;
}
