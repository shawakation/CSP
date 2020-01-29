#define maxn 10000
int father[maxn];
void init(int n)
{
	for (int i=1;i<=n;i++) father[i]=i;
}
int Find(int x)
{
    if (x==father[x]) return x;
    father[x]=Find(father[x]);
    return father[x];
}
void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if (fx!=fy) father[fx]=fy;
}
