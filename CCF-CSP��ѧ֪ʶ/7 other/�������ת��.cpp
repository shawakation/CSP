string rome(int a)
{
    string s;
    int i,j;
    if(a>=1000)
    {
        i=a/1000;
        for(int j=0;j<i;j++)
            s=s+"M";
        a-=1000*i;
    }
    if(a>=900) { s=s+"CM"; a-=900; }
    if(a>=500) { s=s+"D"; a-=500; }
    if(a>=400) { s=s+"CD"; a-=400; }
    if(a>=100)
    {
        i=a/100;
        for(j=0;j<i;j++)
            s=s+"C";
        a-=100*i;
    }
    if(a>=90) { s=s+"XC"; a-=90; }
    if(a>=50) { s=s+"L"; a-=50; }
    if(a>=40) { s=s+"XL"; a-=40; }
    if(a>=10)
    {
        i=a/10;
        for(j=0;j<i;j++)
            s=s+"X";
        a-=10*i;
    }
    if(a>=9) { s=s+"IX"; a-=9; }
    if(a>=5) { s=s+"V"; a-=5; }
    if(a>=4) { s=s+"IV"; a-=4; }
    for(j=0;j<a;j++)
        s=s+"I";
    return s;
}
