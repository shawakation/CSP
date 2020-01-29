#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
typedef long long ll;
int n,k;
bool vis[maxn];
short graph[maxn][maxn]= {0};
ll dis[maxn];
unordered_set<int> points[maxn],reds;
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
int father[maxn];
void init(int n)
{
	for (int i=1; i<=n; i++) father[i]=i;
}
int find(int p)
{
	int a=p;
	while (father[p]!=p) p=father[p];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=p;
		a=z;
	}
	return p;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
int main()
{
	int m;
	scanf("%d%d%d",&n,&m,&k);
	init(n);
	for (int i=1; i<=n; i++) {
		int t;
		scanf("%d",&t);
		if (t==1) reds.insert(i);
	}
	for (int i=0; i<m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u!=v) {
			graph[u][v]=graph[v][u]=w;
			points[u].insert(v);
			points[v].insert(u);
			unit(u,v);
		}
	}
	for (int i=1; i<=n; i++) {
		calc(i);
		vector<ll> ds;
		for (int p:reds) if (find(i)==find(p)) ds.push_back(dis[p]);
		sort(ds.begin(),ds.end());
		ll sum=0;
		for (int j=0; j<ds.size()&&j<k; j++) sum+=ds[j];
		printf("%lld\n",sum);
	}
	return 0;
}
