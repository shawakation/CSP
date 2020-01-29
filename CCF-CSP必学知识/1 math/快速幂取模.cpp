typedef long long ll;
//calc  a^b%m  O(logb)
ll binarypow(ll a,ll b,ll m)
{
	ll ans=1;
	while (b>0) {
		if (b&1) ans=ans*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ans;
}
