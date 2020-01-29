#include <bits/stdc++.h>
#define maxn 510
using namespace std;
bool vis[maxn]={0};
int graph[maxn][maxn]={0},n,startt,endt,dis[maxn];
vector<int> pre[maxn],path,ans;
void calc(int k)
{
	fill(dis,dis+maxn,INT_MAX);
	dis[k]=0;
	for (int y=1;y<=n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=1;h<=n;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=1;h<=n;h++) if (graph[u][h]>0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
int main()
{
	
	return 0;
}
