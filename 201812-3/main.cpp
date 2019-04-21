#include <bits/stdc++.h>
using namespace std;
struct ipaddr {
	int num1,num2,num3,num4,suffix;
	ipaddr(int a,int b,int c,int d,int e) {
		num1=a;
		num2=b;
		num3=c;
		num4=d;
		suffix=e;
	}
	void print() {
		printf("%d.%d.%d.%d/%d\n",num1,num2,num3,num4,suffix);
	}
	friend bool operator < (const ipaddr &a,const ipaddr &b) {
		if (a.num1!=b.num1) return a.num1<b.num1;
		else if (a.num2!=b.num2) return a.num2<b.num2;
		else if (a.num3!=b.num3) return a.num3<b.num3;
		else if (a.num4!=b.num4) return a.num4<b.num4;
		else return a.suffix<b.suffix;
	}
	friend bool operator == (const ipaddr &a,const ipaddr &b) {
		return a.num1==b.num1&&a.num2==b.num2&&a.num3==b.num3&&a.num4==b.num4&&a.suffix==b.suffix;
	}
};
struct ipaddrHash
{
	size_t operator () (const ipaddr &a) const {
		return a.num1*30000+a.num2*3000+a.num3*300+a.num4*30+a.suffix;
	}
};
char* strtochar(string s)
{
	char *t=new char[30];
	strcpy(t,s.c_str());
	return t;
}
int calcdotnum(string s)
{
	int dotnum=0;
	for (int i=0; i<s.length(); i++) if (s[i]=='.') dotnum++;
	return dotnum;
}
ipaddr convert(string ip)
{
	int t1,t2,t3,t4,t5,dotnum=calcdotnum(ip);
	if (ip.find('/')==string::npos) {
		switch (dotnum) {
			case 0: {
					sscanf(ip.c_str(),"%d",&t1);
					t2=t3=t4=0;
					t5=8;
					break;
				}
			case 1: {
					sscanf(ip.c_str(),"%d.%d",&t1,&t2);
					t3=t4=0;
					t5=16;
					break;
				}
			case 2: {
					sscanf(ip.c_str(),"%d.%d.%d",&t1,&t2,&t3);
					t4=0;
					t5=24;
					break;
				}
			case 3: {
					sscanf(ip.c_str(),"%d.%d.%d.%d",&t1,&t2,&t3,&t4);
					t5=32;
					break;
				}
		}
	} else {
		switch (dotnum) {
			case 0: {
					sscanf(ip.c_str(),"%d/%d",&t1,&t5);
					t2=t3=t4=0;
					break;
				}
			case 1: {
					sscanf(ip.c_str(),"%d.%d/%d",&t1,&t2,&t5);
					t3=t4=0;
					break;
				}
			case 2: {
					sscanf(ip.c_str(),"%d.%d.%d/%d",&t1,&t2,&t3,&t5);
					t4=0;
					break;
				}
			case 3: {
					sscanf(ip.c_str(),"%d.%d.%d.%d/%d",&t1,&t2,&t3,&t4,&t5);
					break;
				}
		}
	}
	return ipaddr(t1,t2,t3,t4,t5);
}
vector<ipaddr> getmatchset(ipaddr &a)
{
	
}
vector<ipaddr> ans;
unordered_set<ipaddr,ipaddrHash> my;
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		ans.push_back(convert(s));
	}
	sort(ans.begin(),ans.end());
	for (auto &p:ans) p.print();
	return 0;
}
