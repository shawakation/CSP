#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAIN 110
using namespace std;
int n,v,t,w[MAIN],c[MAIN],z[MAIN][MAIN],dp[MAIN];
int main()
{
    scanf("%d%d%d",&n,&v,&t);
    for(int i=1;i<=n;i++)
    {
        int p; scanf("%d%d%d",&w[i],&c[i],&p);
        z[p][++z[p][0]]=i;
    }
    for(int i=1;i<=t;i++)
        for(int j=v;j>=0;j--)
            for(int k=1;k<=z[i][0];k++)
                if(j>=w[z[i][k]])
                    dp[k]=max(dp[k],dp[j-w[z[i][k]]]+c[z[i][k]]);
    printf("%d\n",dp[v]);
    return 0;
}
