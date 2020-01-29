#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#define INF 0X3F3F3F3F
#define LL long long
#define SC(x) scanf("%d",&x)
#define SCC(x,y) scanf("%d%d",&x,&y)
#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define FF(i,a,b) for(int i=a; i<=b; i++)
#define RR(i,a,b) for(int i=a; i>=b; i--)
#define FC(i,a,b) for(int i=a; i<b; i++)
#define SS(x) scanf("%s",x)
#define PR(x) printf("%d\n",x)
#define PRR(x,y) printf("%d %d\n",x,y)
#define CL(a,x) memset(a,x,sizeof(a))
#define MID int mid=((l+r)>>1)
#define lson x<<1,l,mid
#define rson x<<1|1,mid+1,r
#define _X sum[x]
#define _L sum[x<<1]
#define _R sum[x<<1|1]
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define MAIN 30010
using namespace std;
struct node
{
    int h,l,r,s;
    node() {}
    node(int a,int b,int c,int d)
        :h(a),l(b),r(c),s(d) {}
    bool operator < (const node &tmp) const
    {
        if(h==tmp.h) return s>tmp.s;
        return h<tmp.h;
    }
} ss[MAIN];
int n,m,sum[MAIN<<2],cnt[MAIN<<2],num[MAIN<<2];
bool lx[MAIN<<2],rx[MAIN<<2];
void push_up(int x,int l,int r)
{
    if(cnt[x])
    {
        _X=r-l+1;
        lx[x]=true,rx[x]=true,num[x]=2;
    }
    else if(l==r) _X=lx[x]=rx[x]=num[x]=0;
    else
    {
        _X=_L+_R;
        lx[x]=lx[x<<1],rx[x]=rx[x<<1|1];
        num[x]=num[x<<1]+num[x<<1|1];
        if(rx[x<<1]&&lx[x<<1|1]) num[x]-=2;
    }
}
void update(int x,int l,int r,int a,int b,int c)
{
    if(a<=l&&r<=b)
    {
        cnt[x]+=c;
        push_up(x,l,r);
        return ;
    }
    MID;
    if(a<=mid) update(lson,a,b,c);
    if(mid<b) update(rson,a,b,c);
    push_up(x,l,r);
}
int main()
{
    int aa,bb,cc,dd;
    int minx=MAIN,miny=MAIN,maxy=-MAIN;
    SC(n),m=0;
    FC(i,0,n)
    {
        SCC(aa,bb),SCC(cc,dd);
        ss[m++]=node(aa,bb,dd,1);
        ss[m++]=node(cc,bb,dd,-1);
        minx=min(minx,aa),miny=min(miny,bb);
    }
    int tmpx=minx<0?-minx:0,tmpy=miny<0?-miny:0;
    sort(ss,ss+m);
    FC(i,0,m) ss[i].h+=tmpx,ss[i].l+=tmpy,ss[i].r+=tmpy,maxy=max(maxy,ss[i].r);
    CL(sum,0),CL(cnt,0),CL(num,0),CL(lx,false),CL(rx,false);
    int ans=0,past=0;
    FC(i,0,m)
    {
        update(1,0,maxy,ss[i].l+1,ss[i].r,ss[i].s);
        ans+=num[1]*(ss[i+1].h-ss[i].h);
        ans+=abs(sum[1]-past),past=sum[1];

    }
    cout<<ans<<endl;
    return 0;
}
