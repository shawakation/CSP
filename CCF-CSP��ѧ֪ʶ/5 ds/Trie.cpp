#define CHARSET 26
#define MAX_NODE 10000
using namespace std;
const int BASE='a';
struct Trie
{
    int tot,root,child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    Trie()
    {
        memset(child[1],0,sizeof(child[1]));
        flag[1]=false;
        root=tot=1;
    }
    void insert(const char *str)
    {
        int *cur=&root;
        for(const char *p=str;*p;p++)
        {
            cur=&child[*cur][*p-BASE];
            if(!(*cur))
            {
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=false;
            }
        }
        flag[*cur]=true;
    }
    bool query(const char *str)
    {
        int *cur=&root;
        for(const char *p=str;*p&&*cur;p++)
            cur=&child[*cur][*p-BASE];
        return (*cur&&flag[*cur]);
    }
};
