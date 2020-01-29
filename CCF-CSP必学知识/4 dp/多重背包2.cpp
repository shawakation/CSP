#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAIN 110
using namespace std;
int n,v,c[MAIN],w[MAIN],s[MAIN],dp[MAIN];
int main()
{
    memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&c[i],&w[i],&s[i]);
    for(int i=1;i<=n;i++)
        if(c[i]*s[i]>=v)
        {
            for(int j=c[i];j<=v;j++)
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
        else {
            int k=1;
            while(k<s[i])
            {
                for(int j=v;j>=c[i]*k;j--)
                    dp[j]=max(dp[j],dp[j-c[i]*k]+w[i]*k);
                s[i]-=k;
                k*=2;
            }
            for(int j=v;j>=c[i]*s[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]*s[i]]+w[i]*s[i]);
        }
    printf("%d\n",dp[v]);
	return 0;
}
