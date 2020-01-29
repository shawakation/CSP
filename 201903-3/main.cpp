#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
vector<string> disks[maxn];
unordered_set<int> exist;
int blocknum;
int main()
{
	int n,s,l,m;
    scanf("%d%d%d",&n,&s,&l);
    for (int i=0;i<l;i++) {
        int num;
        string s;
        scanf("%d",&num);
		cin>>s;
		exist.insert(num);
        for (int j=0;j<s.length();j+=8) disks[num].push_back(s.substr(j,8));
    }
    blocknum=disks[*exist.begin()].size();
	scanf("%d",&m);
    for (int i=0;i<m;i++) {
        int b;
        scanf("%d",&b);
        if (b>=blocknum) puts("-");
        else printf("%s\n",disks[0][b].c_str());
    }
    return 0;
}
