int minDiv[MAIN],phi[MAIN],sum[MAIN];
void genPhi()
{
    for(int i=1;i<MAIN;i++)
        minDiv[i]=i;
    for(int i=2;i*i<MAIN;i++)
    {
        if(minDiv[i]==i)
        {
            for(int j=i*i;j<MAIN;j+=i)
                minDiv[j]=i;
        }
    }
    phi[1]=1;
    for(int i=2;i<MAIN;i++)
    {
        phi[i]=phi[i/minDiv[i]];
        if(!((i/minDiv[i])%minDiv[i])) phi[i]*=minDiv[i];
            else phi[i]*=minDiv[i]-1;
    }
}
