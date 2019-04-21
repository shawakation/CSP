#include <bits/stdc++.h>
#define maxn 510
using namespace std;
typedef long long ll;
bool vis[maxn]= {0};
int graph[maxn][maxn]= {0},n;
ll dis[maxn];
void calc(int k)
{
	fill(dis,dis+maxn,LLONG_MAX);
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
		for (int h=1; h<=n; h++) if (graph[u][h]>0&&vis[h]==0) {
				if (dis[h]>dis[u]+graph[u][h]) dis[h]=dis[u]+graph[u][h];
			}
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int t,a,b,c;
		scanf("%d%d%d%d",&t,&a,&b,&c);
		if (t==0) graph[a][b]=graph[b][a]=c;
		else graph[a][b]=graph[b][a]=c*c;
	}
	calc(1);
	printf("%lld",dis[n]);
	return 0;
}
