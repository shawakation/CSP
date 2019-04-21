#include <bits/stdc++.h>
using namespace std;
int l,t;
bool isleft;
int gofinal(int cur,int h)
{
	if (cur==l) isleft=1;
	while (h>0) {
		if (isleft) {
			cur--;
			if (cur==0) isleft=0;
		} else {
			cur++;
			if (cur==l) isleft=1;
		}
		h--;
	}
	return cur;
}
struct ball {
	int pos,id;
	ball() {
		pos=id=-1;
	}
	friend bool operator < (const ball &a,const ball &b) {
		return a.pos<b.pos;
	}
};
int main()
{
	int n;
	scanf("%d%d%d",&n,&l,&t);
	vector<ball> arr(n);
	vector<int> post(n),ans(n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i].pos);
		arr[i].id=i;
	}
	sort(arr.begin(),arr.end());
	for (int i=0; i<n; i++) post[i]=arr[i].id;
	for (int i=0; i<n; i++) {
		isleft=0;
		arr[i].pos=gofinal(arr[i].pos,t);
	}
	sort(arr.begin(),arr.end());
	for (int i=0; i<n; i++) ans[post[i]]=arr[i].pos;
	for (int i=0; i<n; i++) {
		printf("%d",ans[i]);
		if (i<n-1) printf(" ");
	}
	return 0;
}
