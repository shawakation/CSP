#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int father[maxn];
void init(int n)
{
	for (int i=1;i<=n;i++) father[i]=i;
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
struct edge
{
	int u,v,w;
	edge(int _u,int _v,int _w) {
		u=_u;v=_v;w=_w;
	}
	friend bool operator < (const edge &a,const edge &b) {
		return a.w<b.w;
	}
};
vector<edge> arr;
int main()
{
	int n,m,root,maxw=-1,edgenum=0;
	scanf("%d%d%d",&n,&m,&root);
	init(n);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr.push_back(edge(a,b,c));
	}
	sort(arr.begin(),arr.end());
	for (int i=0;i<m;i++) {
		int fu=find(arr[i].u),fv=find(arr[i].v);
		if (fu!=fv) {
			edgenum++;
			father[fu]=fv;
			maxw=max(maxw,arr[i].w);
		}
		if (edgenum==n-1) break;
	}
	printf("%d",maxw);
	return 0;
}
