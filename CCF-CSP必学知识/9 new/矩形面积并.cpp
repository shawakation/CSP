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
#define PRR(x,y) printf("%d%d\n",x,y)
#define CL(a,x) memset(a,x,sizeof(a))
#define MID int mid=((l+r)>>1)
#define lson x<<1,l,mid
#define rson x<<1|1,mid+1,r
#define _X sum[x]
#define _L sum[x<<1]
#define _R sum[x<<1|1]
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define MAIN 3010
using namespace std;
double X[MAIN];
double sum[MAIN<<2];
int cnt[MAIN<<2],k;
struct node
{
    double h,l,r;
    int s;
    node() {};
    node(double a,double b,double c,int d)
        :l(a),r(b),h(c),s(d) {};
    bool operator < (const node &cmp) const
    {
        return h<cmp.h;
    }
} ss[MAIN];
void push_up(int x,int l,int r)
{
    if(cnt[x]) sum[x]=X[r+1]-X[l];
    else if(l==r) sum[x]=0;
    else sum[x]=sum[x<<1]+sum[x<<1|1];
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
int FI(double kk,int k)
{
    int l=0,r=k-1;
    while(l<=r)
    {
        MID;
        if(X[mid]==kk) return mid;
        else if(X[mid]<kk) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
void asdf(int x,int l,int r)
{
    cout<<"x:"<<x<<" sum[x]:"<<sum[x]<<" cnt[x]:"<<cnt[x]<<" l:"<<l<<" r:"<<r<<endl;
    if(l==r) return ;
    MID;
    asdf(lson);
    asdf(rson);
}
int main()
{
    IN;
    int n,tt=1;
    while(~SC(n)&&n)
    {
        int m=0;
        FF(i,1,n)
        {
            double a,b,c,d;
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            X[m]=a,ss[m++]=node(a,c,b,1);
            X[m]=c,ss[m++]=node(a,c,d,-1);
        }
        sort(X,X+m),sort(ss,ss+m);
        int k=1;
        FC(i,1,m)
        if(X[i]!=X[i-1])
            X[k++]=X[i];
        CL(cnt,0),CL(sum,0);
        double ret=0;
        FF(i,0,k-1) cout<<X[i]<<" ";
        cout<<endl;
        FC(i,0,m-1)
        {
            int l=FI(ss[i].l,k);
            int r=FI(ss[i].r,k)-1;
            if(l<=r) update(1,0,k-1,l,r,ss[i].s);
            cout<<l<<" "<<r<<endl;
            cout<<sum[1]<<endl<<endl;
            asdf(1,0,k-1);
            ret+=sum[1]*(ss[i+1].h-ss[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",tt++,ret);
    }
    return 0;
}
