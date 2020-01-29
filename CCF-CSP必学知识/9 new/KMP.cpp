#include<bits/stdc++.h>
#define MAIN 110
using namespace std;
int next[MAIN];
void get_next(string s,string t)
{
    int n=s.length(),m=t.length();
    next[0]=0;
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(s[i]==s[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}
void KMP(string s,string t)
{
    int n=s.length(),m=t.length();
    for(int i=0,j=0; i<m; i++)
    {
        if(j<n&&t[i]==s[j]) j++;
        else
        {
            while(j>0)
            {
                j=next[j];
                if(t[i]==s[j])
                {
                    j++;
                    break;
                }
            }
        }
        if(j==n) cout<<i<<endl;
    }
}
int main()
{
    string s,t;
    cin>>s>>t;
    get_next(s,t);
    KMP(s,t);
    return 0;
}
