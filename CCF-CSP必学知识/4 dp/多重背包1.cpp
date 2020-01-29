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
        for(int j=v;j>=0;j--)
            for(int k=0;k<=s[i];k++)
            {
                if(j-k*c[i]<0) break;
                dp[j]=max(dp[j],dp[j-c[i]*k]+w[i]*k);
            }
    printf("%d\n",dp[v]);
	return 0;
}
