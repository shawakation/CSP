#include<iostream>
#include<cstdio>
#define MAIN 110
using namespace std;
int n,data[MAIN];
void heap(int h,int r)
{
    int i=h,j=2*i,x=data[i];
    while(j<=r)
    {
        bool flag=0;
        if(j+1<=r&&data[j]<data[j+1]) j++;
        if(data[j]>x)
        {
            data[i]=data[j];
            i=j; j=2*i;
            flag=1;
        }
        if(!flag) break;
    }
    data[i]=x;
}
void heapsort()
{
    for(int i=n/2;i>0;i--) heap(i,n);
    for(int i=n;i>1;i--)
    {
        swap(data[1],data[i]);
        heap(1,i-1);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    heapsort();
    for(int i=1;i<=n;i++) printf("%d ",data[i]);
    return 0;
}
