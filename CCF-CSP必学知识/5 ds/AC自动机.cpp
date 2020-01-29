#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#define MAX_N 1000006
#define MAX_Tot 500005
using namespace std;
struct Aho
{
    struct state
    {
        int next[26];
        int fail,cnt;
    } stateTable[MAX_Tot];
    int size;
    queue <int> que;
    void init()
    {
        for(int i=0; i<MAX_Tot; i++)
        {
            memset(stateTable[i].next,0,sizeof(stateTable[i].next));
            stateTable[i].fail=stateTable[i].cnt=0;
        }
        size=1;
    }
    void insert(char *S)
    {
        int n=strlen(S);
        int now=0;
        for(int i=0; i<n; i++)
        {
            char c=S[i];
            if(!stateTable[now].next[c-'a'])
                stateTable[now].next[c-'a']=size++;
            now=stateTable[now].next[c-'a'];
        }
        stateTable[now].cnt++;
    }
    void build()
    {
        stateTable[0].fail=-1;
        que.push(0);
        while(que.size())
        {
            int u=que.front();
            que.pop();
            for(int i=0; i<26; i++)
                if(stateTable[u].next[i])
                {
                    if(u==0) stateTable[stateTable[u].next[i]].fail=0;
                    else
                    {
                        int v=stateTable[u].fail;
                        while(v!=-1)
                        {
                            if(stateTable[v].next[i])
                            {
                                stateTable[stateTable[u].next[i]].fail=stateTable[v].next[i];
                                break;
                            }
                            v=stateTable[v].fail;
                        }
                        if(v==-1) stateTable[stateTable[u].next[i]].fail=0;
                    }
                    que.push(stateTable[u].next[i]);
                }
        }
    }
    int Get(int u)
    {
        int res=0;
        while(u)
        {
            res+=stateTable[u].cnt;
            stateTable[u].cnt=0;
            u=stateTable[u].fail;
        }
        return res;
    }
    int match(char *S)
    {
        int n=strlen(S);
        int res=0,now=0;
        for(int i=0; i<n; i++)
        {
            char c=S[i];
            if(stateTable[now].next[c-'a']) now=stateTable[now].next[c-'a'];
            else
            {
                int p=stateTable[now].fail;
                while(p!=-1&&stateTable[p].next[c-'a']==0)
                    p=stateTable[p].fail;
                if(p==-1) now=0;
                else now=stateTable[p].next[c-'a'];
            }
            if(stateTable[now].cnt)
                res+=Get(now);
        }
        return res;
    }
} aho;
int T,N;
char S[MAX_N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        aho.init();
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%s",S);
            aho.insert(S);
        }
        aho.build();
        scanf("%s",S);
        printf("%d\n",aho.match(S));
    }
    return 0;
}
