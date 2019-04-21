#include <bits/stdc++.h>
#define maxn 110
using namespace std;
struct ruler {
	deque<string> arr;
	string name;
} rulers[maxn];
deque<string> convert(string s)
{
	deque<string> tt;
	int i=0,j=i+1;
	while (i<s.length()) {
		while (s[j]!='/'&&j<s.length()) j++;
		tt.push_back(s.substr(i+1,j-i-1));
		i=j;
		j=i+1;
		if (i==s.length()-1&&s[i]=='/') break;
	}
	return tt;
}
bool judgenum(string s)
{
	for (auto &p:s) if (!isdigit(p)) return 0;
	return 1;
}
bool judgestr(string s)
{
	for (auto &p:s) if (isalpha(p)) return 1;
	return 0;
}
bool judgeok(string s)
{
	for (auto &p:s) if (!(isalnum(p)||p=='-'||p=='_'||p=='.')) return 0;
	return 1;
}
bool comparet(string r,string a)
{
	if (r[0]=='<') {
		if (r=="<int>") {
			if (judgenum(a)) return 1;
			else return 0;
		} else if (r=="<str>") {
			if (judgestr(a)) return 1;
			else return 0;
		} else if (r=="<path>") {
			if (a!="") return 1;
			else return 0;
		}
	} else {
		if (r==a) return 1;
		else return 0;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0; i<n; i++) {
		string s,n;
		cin>>s>>n;
		rulers[i].arr=convert(s);
		rulers[i].name=n;
	}
	for (int y=0; y<m; y++) {
		string s;
		bool flag=0;
		cin>>s;
		deque<string> words=convert(s);
		for (int i=0; i<n; i++) {
			bool ismatch=1;
			deque<string> r1=rulers[i].arr,r2=words,ans;
			while (!r1.empty()&&!r2.empty()) {
				if (!judgeok(r2[0])) {
					ismatch=0;
					break;
				}
				if (comparet(r1[0],r2[0])) {
					if (r1[0][0]=='<') {
						if (r1[0]=="<int>") {
							string num=r2[0];
							while (num[0]=='0'&&num.length()>1) num.erase(0,1);
							ans.push_back(num);
						} else if (r1[0]=="<str>") ans.push_back(r2[0]);
						else if (r1[0]=="<path>") {
							string res;
							while (r2.size()>1) {
								res+=r2[0];
								res+="/";
								r2.pop_front();
							}
							res+=r2[0];
							ans.push_back(res);
						}
					}
					r1.pop_front();
					r2.pop_front();
				} else {
					ismatch=0;
					break;
				}
			}
			if (!(r1.empty()&&r2.empty())) ismatch=0;
			if (ismatch) {
				flag=1;
				printf("%s",rulers[i].name.c_str());
				for (auto &p:ans) printf(" %s",p.c_str());
				printf("\n");
			}
		}
		if (flag==0) printf("404\n");
	}
	return 0;
}
