#include<iostream>
#include<cstdio>
#define lowbit(i) (i&(-i))
#define MAIN 100010
using namespace std;
long long n,q,A[MAIN],sum[MAIN];
long long c1[MAIN],c2[MAIN];
long long query(long long *data,int x)
{
    long long temp=0;
    for(int i=x; i; i-=lowbit(i))
        temp+=data[i];
    return temp;
}
void update(long long *data,int x,long long v)
{
    for(int i=x; i<=n; i+=lowbit(i))
        data[i]+=v;
}
int main()
{
    int s,t,d;
    char temp;
    scanf("%lld%lld",&n,&q);
    for(int i=1; i<=n; i++)
        scanf("%lld",&A[i]);
    for(int i=1; i<=n; i++)
        sum[i]=sum[i-1]+A[i];
    for(int i=1; i<=q; i++)
    {
        getchar();
        scanf("%c%d%d",&temp,&s,&t);
        if (temp=='Q')
        {
            long long ans;
            ans=sum[t]-sum[s-1];
            ans+=(t+1)*query(c1,t)-query(c2,t);
            ans-=(s*query(c1,s-1)-query(c2,s-1));
            printf("%lld\n",ans);
        }
        else
        {
            scanf("%d",&d);
            update(c1,s,d);
            update(c1,t+1,-d);
            update(c2,s,d*s);
            update(c2,t+1,-d*(t+1));
        }
    }
    return 0;
}

