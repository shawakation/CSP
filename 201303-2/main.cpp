#include <bits/stdc++.h>
using namespace std;
list<int> lst;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) lst.push_back(i);
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (b>0) {
			for (auto it=lst.begin(); it!=lst.end(); it++) {
				if (*it==a) {
					auto it2=next(it);
					for (int f=0; f<b; f++) it2++;
					lst.insert(it2,a);
					lst.erase(it);
					break;
				}
			}
		} else if (b<0) {
			b=abs(b);
			for (auto it=lst.begin(); it!=lst.end(); it++) {
				if (*it==a) {
					auto it2=it;
					for (int f=0; f<b; f++) it2--;
					lst.insert(it2,a);
					lst.erase(it);
					break;
				}
			}
		}
	}
	int countt=lst.size();
	for (auto it=lst.begin(); it!=lst.end(); it++) {
		printf("%d",*it);
		countt--;
		if (countt>0) printf(" ");
	}
	return 0;
}
