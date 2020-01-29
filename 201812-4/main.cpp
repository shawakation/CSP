#include <bits/stdc++.h>
#define maxn 50005
using namespace std;
int father[maxn];
void initf(int n)
{
	for (int i=1; i<=n; i++) father[i]=i;
}
int find(int x)
{
	if (x==father[x]) return x;
	father[x]=find(father[x]);
	return father[x];
}
struct edge {
	int u,v,w;
	edge(int _u,int _v,int _w):u(_u),v(_v),w(_w) {}
	friend bool operator < (const edge &a,const edge &b) {
		return a.w<b.w;
	}
};
deque<edge> arr;
int main()
{
	int n,m,root,ans=-1,countt=0;
	scanf("%d%d%d",&n,&m,&root);
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr.push_back(edge(a,b,c));
	}
	sort(arr.begin(),arr.end());
	initf(n);
	while (!arr.empty()) {
		edge t=arr.front();
		arr.pop_front();
		int fx=find(t.u),fy=find(t.v);
		if (fx!=fy) {
			father[fx]=fy;
			ans=max(ans,t.w);
			countt++;
		}
		if (countt==n-1) break;
	}
	printf("%d\n",ans);
	return 0;
}
