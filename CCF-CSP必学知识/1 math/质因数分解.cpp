int tot,a[MAXN],b[MAXN];
void factor(int n)
{
    int temp=(int)((double)sqrt(n)+1),now=n;
    tot=0;
    for(int i=2; i<=temp; i++)
        if(!(now%i))
        {
            a[++tot]=i;
            b[tot]=0;
            while(!(now%i))
            {
                ++b[tot];
                now/=i;
            }
        }
    if(now!=1)
    {
        a[++tot]=now;
        b[tot]=1;
    }
    return;
}
