#include <bits/stdc++.h>
#define maxn 110
using namespace std;
int nodenum=1;
struct node {
	string id,attrib;
	int layer,pre;
	vector<int> childs;
	node() {
		layer=pre=-1;
	}
} nodes[maxn];
unordered_set<int> roots;
void convert(string s)
{
	int t=0;
	while (s[t]=='.') t+=2;
	nodes[nodenum].layer=t/2;
	if (t>0) s.erase(0,t);
	else roots.insert(nodenum);
	stringstream ss(s);
	ss>>nodes[nodenum].id>>nodes[nodenum].attrib;
	nodenum++;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	for (int i=0; i<n; i++) {
		string s;
		getline(cin,s,'\n');
		convert(s);
	}
	for (int i=1; i<=n; i++) {
		if (roots.find(i)==roots.end()) {
			int j=i-1;
			while (j>=1) {
				if (nodes[j].layer<nodes[i].layer) break;
				j--;
			}
			nodes[j].childs.push_back(i);
			nodes[i].pre=j;
		}
	}
	for (int i=1; i<=m; i++) {
		string s,q1,q2,q3;
		set<int> ans;
		getline(cin,s,'\n');
		stringstream ss(s);
		ss>>q1>>q2>>q3;
		if (q2==""&&q3=="") {
			if (q1[0]=='#') {
				for (int h=1; h<=n; h++) if (nodes[h].attrib==q1) ans.insert(h);
			} else {
				for (int h=1; h<=n; h++) if (nodes[h].id==q1) ans.insert(h);
			}
		} else if (q3=="") {
			for (int h=1; h<=n; h++) if (nodes[h].id==q2) {
					if (nodes[nodes[h].pre].id==q1) ans.insert(h);
				}
		} else {
			for (int h=1; h<=n; h++) if (nodes[h].id==q3) {
					if (nodes[nodes[h].pre].id==q2) {
						if (nodes[nodes[nodes[h].pre].pre].id==q1) ans.insert(h);
					}
				}
		}
		printf("%d",ans.size());
		for (auto &p:ans) printf(" %d",p);
		printf("\n");
	}
	return 0;
}
