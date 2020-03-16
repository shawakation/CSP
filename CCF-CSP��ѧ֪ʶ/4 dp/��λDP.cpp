#include<cstdio>
#include<cstring>
long long dp[13][13][3],dig[13];
long long dfs(int len,long long mod,int k,int flag)
{
    if (len<=0) return (!mod&&k==2);
    if (!flag&&dp[len][mod][k]!=-1) return dp[len][mod][k];
    int num=flag?dig[len]:9;
    long long ans=0;
    for( int i=0; i<=num; i++)
    {
        long long modt=(mod*10+i)%13;
        int kt;
        if(k==2||k==1&&i==3) kt=2;
        else if(i==1) kt=1;
        else kt=0;
        ans+=dfs(len-1,modt,kt,flag&&num==i);
    }
    if(!flag) dp[len][mod][k]=ans;
    return ans;
}
long long solve(long long x)
{
    int len=0;
    while (x) dig[++len]=x%10,x/=10;
    return dfs(len,0,0,1);
}
int main()
{
    long long n;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%lld",&n))
        printf("%lld\n",solve(n));
    return 0;
}
