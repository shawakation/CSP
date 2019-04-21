#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
struct edge {
	int u,v,w;
	edge(int _u,int _v,int _w) {
		u=_u;
		v=_v;
		w=_w;
	}
	friend bool operator < (const edge &a,const edge &b) {
		return a.w<b.w;
	}
};
vector<edge> arr;
int n,father[maxn];
void init()
{
	for (int i=1; i<=n; i++) father[i]=i;
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
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	init();
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr.push_back(edge(a,b,c));
	}
	sort(arr.begin(),arr.end());
	for (int i=0; i<m; i++) {
		unit(arr[i].u,arr[i].v);
		if (find(1)==find(n)) {
			printf("%d",arr[i].w);
			break;
		}
	}
	return 0;
}
