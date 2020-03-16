#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MAXN 200
using namespace std;
stack <int> s;
int edge[MAXN][MAXN];
int n,m;
void dfs(int x)
{
    s.push(x);
    for(int i=0; i<n; i++)
        if(edge[i][x]>0)
        {
            edge[i][x]=0;
            edge[x][i]=0;
            dfs(i);
            break;
        }
}
void Fleury(int x)
{
    s.push(x);
    while(!s.empty())
    {
        bool temp=false;
        for(int i=0; i<n; i++)
            if(edge[s.top()][i]>0)
            {
                temp=true;
                break;
            }
        if(!temp)
        {
            printf("%d ",s.top()+1);
            s.pop();
        }
        else
        {
            int s_top=s.top();
            s.pop();
            dfs(s_top);
        }
    }
    printf("\n");
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(edge,0,sizeof(edge));
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u-1][v-1]=1;
        edge[v-1][u-1]=1;
    }
    int num=0,start=0;
    for(int i=0; i<n; i++)
    {
        int degree=0;
        for(int j=0; j<n; j++)
            degree+=edge[i][j];
        if(degree%2)
        {
            start=i;
            num++;
        }
    }
    if(!num||num==2) Fleury(start);
    else printf("No Euler path\n");
    return 0;
}
/*
9 14
1 2
1 8
2 3
2 8
2 9
3 4
4 5
4 6
4 9
5 6
6 7
6 9
7 8
8 9
*/
