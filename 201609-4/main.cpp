#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
typedef long long ll;
bool vis[maxn]= {0};
int graph[maxn][maxn]= {0},n,pre[maxn],father[maxn];
vector<int> adj[maxn];
ll totalsum=0,dis[maxn];
void calc(int k)
{
	fill(dis,dis+maxn,LLONG_MAX);
	memset(pre,-1,sizeof(pre));
	dis[k]=0;
	for (int y=1; y<=n; y++) {
		int u=-1;
		ll minp=LLONG_MAX;
		for (int h=1; h<=n; h++) if (dis[h]<minp&&vis[h]==0) {
				u=h;
				minp=dis[h];
			}
		if (u==-1) return;
		vis[u]=1;
		for (auto &h:adj[u]) if (vis[h]==0) {
				if (dis[h]>dis[u]+graph[u][h]) {
					dis[h]=dis[u]+graph[u][h];
					pre[h]=u;
				} else if (dis[h]==dis[u]+graph[u][h]) {
					if (graph[u][h]<graph[pre[h]][h]) pre[h]=u;
				}
			}
	}
}
void init(int k)
{
	for (int i=1; i<=k; i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void search(int p)
{
	for (int k=p; k!=-1; k=pre[k]) {
		int k1=find(k),k2=find(pre[k]);
		if (k1!=k2) {
			father[k1]=k2;
			totalsum+=graph[k][pre[k]];
		}
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	calc(1);
	init(n);
	for (int i=2; i<=n; i++) search(i);
	printf("%lld",totalsum);
	return 0;
}
