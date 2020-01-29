bool vis[maxn];
short graph[maxn][maxn]= {0};
ll dis[maxn];
unordered_set<int> points[maxn];
struct cmp {
	bool operator () (int a,int b) const {
		return dis[a]>dis[b];
	}
};
void calc(int k)
{
	fill(dis,dis+n+1,LLONG_MAX);
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,cmp> qu;
	dis[k]=0;
	qu.push(k);
	for (int y=1; y<=n; y++) {
		while (!qu.empty()&&vis[qu.top()]) qu.pop();
		if (qu.empty()) break;
		int u=qu.top();
		qu.pop();
		vis[u]=1;
		for (int p:points[u])
			if (vis[p]==0) {
				if (dis[u]+graph[u][p]<dis[p]) {
					dis[p]=dis[u]+graph[u][p];
					qu.push(p);
				}
			}
	}
}
