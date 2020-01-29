#include <bits/stdc++.h>
#define maxn 100010
#define Q 1000000007
using namespace std;
typedef long long ll;
int n,L,R;
vector<vector<int> > paths;
vector<int> apath;
struct node {
	ll w;
	int pre;
	vector<int> childs;
	node() {
		w=pre=-1;
	}
} nodes[maxn];
bool judgesize(int s)
{
	if (s>=L&&s<=R) return 1;
	else return 0;
}
void search(int p)
{
	apath.push_back(p);
	if (apath.size()>R) {
		apath.pop_back();
		return;
	}
	if (judgesize(apath.size())) paths.push_back(apath);
	if (nodes[p].childs.size()==0) {
		apath.pop_back();
		return;
	}
	for (int h=0; h<nodes[p].childs.size(); h++) search(nodes[p].childs[h]);
	apath.pop_back();
}
void reset()
{
	paths.clear();
	for (int i=1; i<=n; i++) {
		nodes[i].w=nodes[i].pre=-1;
		nodes[i].childs.clear();
	}
}
int main()
{
	int T,m;
	scanf("%d",&T);
	for (int y=0; y<T; y++) {
		scanf("%d%d%d%d",&n,&m,&L,&R);
		for (int i=1; i<=n; i++) scanf("%lld",&nodes[i].w);
		for (int i=1; i<n; i++) {
			int t;
			scanf("%d",&t);
			nodes[t].childs.push_back(i+1);
			nodes[i+1].pre=t;
		}
		for (int i=0; i<m; i++) {
			int u,v;
			ll d,sum=0;
			scanf("%d%d%lld",&u,&v,&d);
			if (u>v) swap(u,v);
			for (int endt=v; endt!=u; endt=nodes[endt].pre) nodes[endt].w=(nodes[endt].w+d)%Q;
			nodes[u].w=(nodes[u].w+d)%Q;
			for (int e=1; e<=n; e++) search(e);
			for (int e=0; e<paths.size(); e++) {
				ll sumt=0;
				for (int d=0; d<paths[e].size(); d++) sumt=(sumt+nodes[paths[e][d]].w)%Q;
				sum=(sum+sumt)%Q;
			}
			printf("%lld\n",sum);
		}
		if (y<T-1) reset();
	}
	return 0;
}
