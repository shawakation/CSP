#define maxn 1000
int c[maxn];
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int n)
{
	int sum=0;
	while(n>0) {
		sum+=c[n];
		n-=lowbit(n);
	}
	return sum;
}
void update(int pos,int num)
{
	while(pos<maxn) {
		c[pos]+=num;
		pos+=lowbit(pos);
	}
}
