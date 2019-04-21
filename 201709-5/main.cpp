#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll c[maxn]= {0},arr[maxn]= {0};
int n;
int lowbit(int x)
{
	return x&(-x);
}
ll getsum(int x)
{
	ll sum=0;
	for (int i=x; i>=1; i-=lowbit(i)) sum+=c[i];
	return sum;
}
void update(int x,ll v)
{
	for (int i=x; i<=n; i+=lowbit(i)) c[i]+=v;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		ll t;
		scanf("%lld",&t);
		update(i,t);
		arr[i]=t;
	}
	for (int i=0; i<m; i++) {
		int opt;
		scanf("%d",&opt);
		if (opt==1) {
			int l,r;
			ll v;
			scanf("%d%d%lld",&l,&r,&v);
			if (v==1) continue;
			for (int h=l; h<=r; h++) {
				if (arr[h]%v==0) {
					ll temp=arr[h];
					arr[h]/=v;
					temp-=arr[h];
					update(h,-temp);
				}
			}
		} else if (opt==2) {
			int l,r;
			scanf("%d%d",&l,&r);
			if (l==1) printf("%lld\n",getsum(r));
			else if (l==r) printf("%lld\n",arr[l]);
			else if (l>1) printf("%lld\n",getsum(r)-getsum(l-1));
		}
	}
	return 0;
}
