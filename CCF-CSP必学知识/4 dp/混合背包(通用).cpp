#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define CASH 100010
using namespace std;
int x,v,dp[CASH];
void pack(int c,int w,int n)
{
    if(!n||!v) return;
    if(n==1)
    {
        for(int i=v;i>=c;i--)
            dp[i]=max(dp[i],dp[i-c]+w);
        return;
    }
    if(n*c>=v-c+1)
    {
        for(int i=c;i<=v;i++)
            dp[i]=max(dp[i],dp[i-c]+w);
        return;
    }
    int va[CASH],vb[CASH];
    for(int j=0;j<c;j++)
    {
        int *pb=va,*pe=va-1; int *qb=vb,*qe=vb-1;
        for(int k=j,i=0;k<=v;k+=c,i++)
        {
            if(pe==pb+n)
            {
                if (*pb==*qb) ++qb;
                ++pb;
            }
            int tt=dp[k]-i*w; *++pe=tt;
            while(qe>=qb&&*qe<tt) --qe;
            *++qe=tt; dp[k]=*qb+i*w;
        }
    }
}
int main()
{
    int c1,w1,n1;
    memset(dp,0,sizeof(dp));
	scanf("%d%d",&x,&v);
	for(int i=1;i<=x;i++)
    {
        scanf("%d%d%d",&c1,&w1,&n1);
        pack(c1,w1,n1);
    }
    printf("%d\n",dp[v]);
	return 0;
}
