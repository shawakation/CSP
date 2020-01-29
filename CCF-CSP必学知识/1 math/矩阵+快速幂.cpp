#define MAXN 10
using namespace std;
struct Matrix
{
    int n,m;
    int a[MAXN][MAXN];
    void clear()
    {
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator + (const Matrix &b) const
    {
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }
    Matrix operator - (const Matrix &b) const
    {
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }
    Matrix operator * (const Matrix &b) const
    {
        Matrix tmp; tmp.clear();
        tmp.n=n; tmp.m=b.m;
        for(int i=0;i<n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<m;k++)
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
        return tmp;
    }
};
Matrix power(Matrix tmp,int num)
{
    Matrix odd; odd=first(odd);
    while(num>0)
    {
        if(num&1) odd=odd*tmp;
        tmp=tmp*tmp; num>>=1;
    }
    return odd;
}
