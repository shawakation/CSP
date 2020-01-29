int n,a[MAIN],m[MAIN];
int extend_gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1; y=0;
        return a;
    }
    else
    {
        int r=extend_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
int CRT()
{
    int M=1;
    for(int i=0;i<n;i++) M*=m[i];
    int ret=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        int tm=M/m[i];
        extend_gcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
