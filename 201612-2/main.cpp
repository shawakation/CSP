#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calcT(ll m)
{
	ll a=m-3500;
	if (a<=1500) return (ll)(a*0.03);
	else if (a>1500&&a<=4500) return (ll)(45+(a-1500)*0.1);
	else if (a>4500&&a<=9000) return (ll)(345+(a-4500)*0.2);
	else if (a>9000&&a<=35000) return (ll)(1245+(a-9000)*0.25);
	else if (a>35000&&a<=55000) return (ll)(7745+(a-35000)*0.3);
	else if (a>55000&&a<=80000) return (ll)(13745+(a-55000)*0.35);
	else return (ll)(22495+(a-80000)*0.45);
}
int main()
{
	ll t;
	scanf("%lld",&t);
	if (t<=3500) printf("%lld",t);
	else {
		ll s=(t/100+1)*100;
		while (calcT(s)!=s-t) s+=100;
		printf("%lld",s);
	}
	return 0;
}
