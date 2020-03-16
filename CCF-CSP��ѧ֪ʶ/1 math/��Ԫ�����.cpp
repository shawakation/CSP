#include<iostream>
#include<cstring>
#include<cstdio>
#define MAIN 200010
using namespace std;
const long long p=1000000007;
long long fact[MAIN]= {1},inv[MAIN]= {1};
long long Lucas(long long a,long long m)
{
    long long ans=fact[a];
    ans=(ans*inv[a-m]%p)*inv[m]%p;
    return ans;
}
long long power(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if (b&1) ans=(ans*a)%p;
        b=b>>1;
        a=(a*a)%p;
    }
    return ans;
}
int main()
{
    long long h,w,a,b;
    scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
    for (int i=1; i<=200000; i++)
    {
        fact[i]=(fact[i-1]*i)%p;
        inv[i]=power(fact[i],p-2);
    }
    long long ans=0;
    for (long long i=1; i<=w-b; i++)
        ans=(ans+Lucas(a+i-2,i-1)*Lucas(h-a+w-i-1,w-i))%p;
    printf("%lld\n",ans);
    return 0;
}
