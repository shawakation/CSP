#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
vector<int> graph[maxn];
bool vis[maxn]= {0};
unordered_set<int> countt[maxn];
int n,cur=1;
void search(int p)
{
	vis[p]=1;
	for (int h=0; h<graph[p].size(); h++)
		if (vis[graph[p][h]]==0) {
			countt[graph[p][h]].insert(cur);
			countt[cur].insert(graph[p][h]);
			search(graph[p][h]);
		}
}
int main()
{
	int m,sum=0;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
	}
	for (int i=1; i<=n; i++) {
		memset(vis,0,sizeof(vis));
		cur=i;
		countt[cur].insert(i);
		search(i);
	}
	for (int i=1; i<=n; i++) if (countt[i].size()==n) sum++;
	printf("%d",sum);
	return 0;
}
