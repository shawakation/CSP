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
void init(int k)
{
	for (int i=1; i<=k; i++) father[i]=i;
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
int calc(int n,int m)
{
	int w=0;
	for (int h=0;h<m;h++) {
		int fa=find(arr[h].u),fb=find(arr[h].v);
		if (fa!=fb) {
			father[fa]=fb;
			edgenum++;
			w+=arr[h].w;
		}
		if (edgenum==n-1) break;
	}
	return w;
}