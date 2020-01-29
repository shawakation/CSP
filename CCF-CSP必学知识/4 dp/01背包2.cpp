#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define MAIN 110
using namespace std;
int n,v,c[MAIN],w[MAIN],dp[MAIN];
int main()
{
    memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=v;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
    printf("%d\n",dp[v]);
	return 0;
}
