bool judge[MAXN]; int tot,ans[MAXN];
void getPrime(int n)
{
    tot=0;
    memset(judge,true,sizeof(judge));
    for(int i=2;i<=n;i++)
    {
        if(judge[i]) { tot++; ans[tot]=i; }
        for(int j=1;j<=tot&&i*ans[j]<=n;j++)
        {
            judge[i*ans[j]]=false;
            if(!(i%ans[j])) break;
        }
    }
}
