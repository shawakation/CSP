#include <bits/stdc++.h>
#define maxn 510
using namespace std;
typedef long long ll;
int graph[maxn][maxn]= {0},n;
ll minpath=LLONG_MAX;
bool daxiaolu[maxn][maxn]= {0},vis[maxn]= {0};
vector<int> path;
void search(int p)
{
	path.push_back(p);
	vis[p]=1;
	if (p==n) {
		ll tired=0;
		for (int h=0; h<path.size()-1;) {
			if (daxiaolu[path[h]][path[h+1]]==0) {
				tired+=graph[path[h]][path[h+1]];
				h++;
			} else {
				int h1=h+1;
				ll sum=0;
				while (daxiaolu[path[h1]][path[h1+1]]&&h1<path.size()-1) h1++;
				for (; h<h1; h++) sum+=graph[path[h]][path[h+1]];
				tired+=sum*sum;
			}
		}
		minpath=min(minpath,tired);
		path.pop_back();
		vis[p]=0;
		return;
	}
	for (int h=1; h<=n; h++) if (graph[p][h]>0&&vis[h]==0) search(h);
	path.pop_back();
	vis[p]=0;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int t,a,b,c;
		scanf("%d%d%d%d",&t,&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
		daxiaolu[a][b]=daxiaolu[b][a]=t;    //0->dalu 1->xiaolu
	}
	search(1);
	printf("%lld",minpath);
	return 0;
}
