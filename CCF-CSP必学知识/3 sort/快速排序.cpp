#include<iostream>
#include<cstdio>
#define MAIN 110
using namespace std;
int n,data[MAIN];
void quickst(int low,int hig)
{
    int i=low,j=hig,temp=data[i];
    while(i<j)
    {
        while((i<j)&&(temp<=data[j])) j--;
        if(i<j)
        {
            data[i]=data[j],i++;
            while((i<j)&&(data[i]<=temp)) i++;
            if(i<j) data[j]=data[i],j--;
        }
    }
    data[i]=temp;
    if(i-1>low) quickst(low,i-1);
    if(hig>i+1) quickst(i+1,hig);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    quickst(1,n);
    for(int i=1;i<=n;i++) printf("%d ",data[i]);
    return 0;
}
