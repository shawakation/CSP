#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MAXN 100
using namespace std;
struct arcnode
{
    int to;
    struct arcnode *next;
};
int m,n;
arcnode* list[MAXN];
int count[MAXN];
int output[MAXN],num;
void topsort()
{
    stack <int> st;
    arcnode* temp;
    bool bcycle=false;
    for(int i=1;i<=n;i++)
        if(!count[i])
            st.push(i);
    for(int i=1;i<=n;i++)
    {
        if(st.empty())
        {
            bcycle=true; break;
        }
        else
        {
            int j=st.top(); st.pop();
            output[++num]=j;
            temp=list[j];
            while(temp!=NULL)
            {
                int k=temp->to; count[k]--;
                if(!count[k]) st.push(k);
                temp=temp->next;
            }
        }
    }
    if(bcycle) printf("Network has a cycle!\n");
    else
    {
        for(int i=1;i<=num;i++)
            printf("%d ",output[i]);
    }
}
int main()
{
    int u,v;
    while(1)
    {
        scanf("%d%d",&n,&m); if(!n&&!m) break; num=0;
        memset(list,0,sizeof(list)); memset(count,0,sizeof(count)); memset(output,0,sizeof(output));
        arcnode* temp;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v); count[v]++; temp=new arcnode; temp->to=v; temp->next=NULL;
            if(list[u]==NULL) list[u]=temp; else { temp->next=list[u]; list[u]=temp; }
        }
        topsort();
        for(int i=1;i<=n;i++)
        {
            temp=list[i];
            while(temp!=NULL)
            {
                list[i]=temp->next;
                delete temp;
                temp=list[i];
            }
        }
    }
    return 0;
}
