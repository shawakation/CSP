#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAIN 1010
using namespace std;
int v1,v2,n;
int c1[MAIN],c2[MAIN],w[MAIN],dp[MAIN][MAIN];
int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&v1,&v2,&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&c1[i],&c2[i],&w[i]);
    for(int i=1;i<=n;i++)
        for(int j=v1;j>=0;j--)
            for(int k=v2;k>=0;k--)
            {
                int t1=min(j+c1[i],v1),t2=min(k+c2[i],v2);
                dp[t1][t2]=max(dp[t1][t2],dp[j][k]+w[i]);
            }
    printf("%d",dp[v1][v2]);
    return 0;
}
