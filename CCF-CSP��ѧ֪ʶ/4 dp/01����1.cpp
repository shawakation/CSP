#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAIN 110
using namespace std;
int n,v,c[MAIN],w[MAIN],dp[MAIN][MAIN];
int main()
{
    memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=v;j++)
            if(j<c[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
    printf("%d\n",dp[n][v]);
	return 0;
}
