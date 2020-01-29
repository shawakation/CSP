int father[maxn];
void init(int n)
{
	for (int i=1;i<=n;i++) father[i]=i;
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
