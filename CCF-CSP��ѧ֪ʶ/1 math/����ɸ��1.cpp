bool judge[MAXN]; int tot,ans[MAXN];
void getPrime(int n)
{
    tot=0;
    memset(judge,true,sizeof(judge));
    for(int i=2;i<=n;i++)
        if(judge[i])
        {
            if(n/i<i) break;
            for(int j=i*i;j<=n;j+=i)
                judge[j]=false;
        }
    for(int i=2;i<=n;i++) if(judge[i]) ans[++tot]=i;
}
