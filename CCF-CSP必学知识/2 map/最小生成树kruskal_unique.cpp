#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 101
#define MAXM 10000
using namespace std;
struct edge
{
    int u,v,w;
    int equal,used,del;
}edges[MAXM];
int parent[MAXN];
int n,m;
bool first;
int Find(int x)
{
    int s=x; while(parent[s]>=0) s=parent[s];
    while(s!=x)
    {
        int tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}
void Union(int R1,int R2)
{
    int r1=Find(R1),r2=Find(R2);
    int tmp=parent[r1]+parent[r2];
    if(parent[r1]>parent[r2]) { parent[r1]=r2; parent[r2]=tmp; }
    else { parent[r2]=r1; parent[r1]=tmp; }
}
int cmp(const void *a,const void *b)
{
    edge aa=*(const edge *)a; edge bb=*(const edge *)b;
    return aa.w-bb.w;
}
int kruskal()
{
    int sumweight=0,num=0;
    int u,v;
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<m;i++)
    {
        if(edges[i].del) continue;
        u=edges[i].u; v=edges[i].v;
        if(Find(u)!=Find(v))
        {
            sumweight+=edges[i].w; num++;
            Union(u,v);
            if(first) edges[i].used=1;
        }
        if(num>=n-1) break;
    }
    return sumweight;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
        edges[i].del=0; edges[i].equal=0; edges[i].used=0;
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            if(j==i) continue;
            if(edges[j].w==edges[i].w) edges[i].equal=1;
        }
    qsort(edges,m,sizeof(edges[0]),cmp); first=true;
    int weight1=kruskal(),weight2; first=false;
    bool judge=false;
    for(int i=0;i<m;i++)
        if(edges[i].used&&edges[i].equal)
        {
            edges[i].del=1;
            weight2=kruskal();
            if(weight1==weight2)
            {
                printf("Not Unique!\n");
                judge=true;
                break;
            }
            edges[i].del=0;
        }
    if(!judge) printf("%d\n",weight1);
    return 0;
}
