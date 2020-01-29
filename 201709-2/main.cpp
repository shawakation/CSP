#include <bits/stdc++.h>
using namespace std;
map<int,set<int> > my;
int n;
struct teacher {
	int num,starttime,endtime;
	friend bool operator < (const teacher &a,const teacher &b) {
		return a.starttime<b.starttime;
	}
};
deque<teacher> arr;
vector<int> keys,keypos;
set<int> emptypos;
void borrowkey(int p)
{
	keys[keypos[p]]=0;
	emptypos.insert(keypos[p]);
	keypos[p]=0;
}
void returnkey(int p)
{
	int leftpos=*emptypos.begin();
	emptypos.erase(emptypos.begin());
	keys[leftpos]=p;
	keypos[p]=leftpos;
}
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	keys.resize(n+1);
	keypos.resize(n+1);
	for (int i=1; i<=n; i++) keys[i]=keypos[i]=i;
	for (int i=0; i<k; i++) {
		teacher tt;
		scanf("%d%d%d",&tt.num,&tt.starttime,&tt.endtime);
		tt.endtime+=tt.starttime;
		arr.push_back(tt);
	}
	sort(arr.begin(),arr.end());
	while (!arr.empty()) {
		int startt=arr[0].starttime,endt=arr[0].endtime;
		while (!my.empty()&&(*my.begin()).first<=startt) {
			for (int p:((*my.begin()).second)) returnkey(p);
			my.erase(my.begin());
		}
		borrowkey(arr[0].num);
		my[endt].insert(arr[0].num);
		arr.pop_front();
	}
	for (auto &p:my) for (int p1:p.second) returnkey(p1);
	for (int i=1; i<=n; i++) {
		printf("%d",keys[i]);
		if (i<n) printf(" ");
	}
	return 0;
}
