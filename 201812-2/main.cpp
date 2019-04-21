#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long ll;
ll r,y,g;
struct deng {
	ll kind,timet;
	deng() {
		kind=timet=-1;
	}
	void update(ll k,ll t) {
		kind=k;
		timet=t;
	}
	void nextstate() {
		switch (kind) {
			case 1: {
					kind=3;
					break;
				}
			case 2: {
					kind=1;
					break;
				}
			case 3: {
					kind=2;
					break;
				}
		}
	}
	void passtime(ll t) {
		while (t>=timet) {
			nextstate();
			t-=timet;
			switch (kind) {
				case 1: {
						timet=r;
						break;
					}
				case 2: {
						timet=y;
						break;
					}
				case 3: {
						timet=g;
						break;
					}
			}
		}
		timet-=t;
	}
} dengs[maxn];
bool isdeng[maxn]= {0};
queue<ll> allway;
int main()
{
	int n;
	ll totaltime=0;
	scanf("%lld%lld%lld%d",&r,&y,&g,&n);
	for (int i=1; i<=n; i++) {
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if (a==0) allway.push(b);
		else {
			dengs[i].update(a,b);
			isdeng[i]=1;
		}
	}
	for (int i=1; i<=n; i++) {
		if (isdeng[i]==0) {
			ll tt=allway.front();
			allway.pop();
			totaltime+=tt;
		} else {
			dengs[i].passtime(totaltime);
			ll t1=dengs[i].kind,t2=dengs[i].timet;
			switch (t1) {
				case 1: {
						totaltime+=t2;
						break;
					}
				case 2: {
						totaltime+=t2+r;
						break;
					}
				case 3:
					break;
			}
		}
	}
	printf("%lld",totaltime);
	return 0;
}
