#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000
#define MAXN 8
using namespace std;
int n;
int edge[MAXN][MAXN];
int a[MAXN][MAXN],path[MAXN][MAXN];
void Floyd()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            a[i][j]=edge[i][j];
            if(i!=j&&a[i][j]<INF) path[i][j]=i;
            else path[i][j]=-1;
        }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(k==i||k==j) continue;
                if(a[i][k]+a[k][j]<a[i][j])
                {
                    a[i][j]=a[i][k]+a[k][j];
                    path[i][j]=path[k][j];
                }
            }
}
int main()
{
    int u,v,w;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            edge[i][j]=INF;
    for(int i=0;i<n;i++) edge[i][i]=0;
    while(1)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(u==-1&&v==-1&&w==-1) break;
        edge[u][v]=w;
    }
    Floyd();
    int shortest[MAXN];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            printf("%d=>%d\t%d\t",i,j,a[i][j]);
            memset(shortest,0,sizeof(shortest));
            int k=0;
            shortest[k]=j;
            while(path[i][shortest[k]]!=i)
            {
                k++;
                shortest[k]=path[i][shortest[k-1]];
            }
            k++; shortest[k]=i;
            for(int t=k;t>0;t--)
                printf("%d->",shortest[t]);
            printf("%d\n",shortest[0]);
        }
}
