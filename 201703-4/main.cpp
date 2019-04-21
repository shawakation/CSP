#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int n,minday=INT_MAX;
struct node {
	int v,w;
	node(int _v,int _w) {
		v=_v;
		w=_w;
	}
};
vector<node> graph[maxn];
vector<int> path;
bool vis[maxn]= {0};
int maxday()
{
	int pos=0;
	int e=path[pos],f=path[++pos],maxt=-1;
	while (pos<path.size()) {
		for (node &p:graph[e]) if (p.v==f) {
				maxt=max(maxt,p.w);
				e=f;
				++pos;
				if (pos<path.size()) f=path[pos];
				break;
			}
	}
	return maxt;
}
void search(int p)
{
	path.push_back(p);
	vis[p]=1;
	if (p==n) {
		minday=min(minday,maxday());
		path.pop_back();
		vis[p]=0;
		return;
	}
	if (path.size()>n) {
		path.pop_back();
		vis[p]=0;
		return;
	}
	for (node &h:graph[p]) if (vis[h.v]==0) search(h.v);
	path.pop_back();
	vis[p]=0;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back(node(b,c));
		graph[b].push_back(node(a,c));
	}
	search(1);
	printf("%d",minday);
	return 0;
}
