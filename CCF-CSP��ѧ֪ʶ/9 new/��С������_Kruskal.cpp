#include<bits/stdc++.h>
#define MAIN 110
#define MAXN 1010
using namespace std;
int n,m,parent[MAIN];
bool first=true;
struct edges
{
    int v,u,w;
    bool have,used,del;
} edge[MAXN];
bool cmp(const edges &a,const edges &b)
{
    return a.w<b.w;
}
int Find(int x)
{
    return x==parent[x]?x:parent[x]=Find(parent[x]);
}
int Union(int R1,int R2)
{
    R1=Find(R1);
    R2=Find(R2);
    if(R1!=R2) parent[R1]=R2;
}
int Kruskal()
{
    int val=0,sum=0;
    for(int i=1; i<=n; i++)
        parent[i]=i;
    for(int i=0; i<m; i++)
    {
        if(edge[i].del) continue;
        if(Find(edge[i].v)!=Find(edge[i].u))
        {
            if(first) edge[i].used=true;
            Union(edge[i].v,edge[i].u);
            sum+=edge[i].w;
            val++;
        }
        if(val+1==n) break;
    }
    return sum;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>edge[i].v>>edge[i].u>>edge[i].w;
        edge[i].del=false;
        edge[i].have=false;
        edge[i].used=false;
    }
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
        {
            if(j==i) continue;
            if(edge[j].w==edge[i].w) edge[i].have=true;
        }
    sort(edge,edge+m,cmp);
    int weight1=Kruskal(),weight2;
    first=false;
    for(int i=0; i<m; i++)
    {
        if(edge[i].used&&edge[i].have)
        {
            edge[i].del=true;
            weight2=Kruskal();
            cout<<weight2<<endl;
            if(weight1==weight2)
            {
                printf("-1\n");
                return 0;
            }
            edge[i].del=false;
        }
    }
    cout<<weight1<<endl;
    return 0;
}
