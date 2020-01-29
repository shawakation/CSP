#include <bits/stdc++.h>
using namespace std;
struct process {
	queue<int> order;
	int last;
	process():last(INT_MAX) {}
};
int convert(char* a,int i)
{
	int num=a[1]-'0';
	if(a[0]=='R') return -(num*10000+i);
	else if(a[0]=='S') return i*10000+num;
}
int main()
{
	int T,n;
	scanf("%d%d",&T,&n);
	getchar();
	while(T--) {
		list<process> arr;
		for(int i=0; i<n; i++) {
			process t;
			char c='\0';
			while(1) {
				char order[3];
				scanf("%s",order);
				c=getchar();
				t.order.push(convert(order,i));
				if(c=='\n') break;
			}
			arr.push_back(t);
		}
		unordered_set<int> curorders;
		while(!arr.empty()) {
			bool islock=1;
			for(auto it=arr.begin(); it!=arr.end(); it++) {
				if(curorders.find(it->last)!=curorders.end()) continue;
				if((it->order).empty()) {
					it=arr.erase(it);
					it--;
					continue;
				}
				while(!(it->order).empty()) {
					int t=(it->order).front();
					(it->order).pop();
					if(curorders.find(-t)==curorders.end()) {
						curorders.insert(t);
						it->last=t;
						break;
					} else {
						curorders.erase(-t);
						islock=0;
					}
				}
			}
			if(islock) break;
		}
		printf("%d\n",arr.empty()?0:1);
	}
	return 0;
}
