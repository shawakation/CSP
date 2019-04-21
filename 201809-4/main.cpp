#include <bits/stdc++.h>
#define maxn 310
using namespace std;
int n;
vector<int> ans,arr;
bool vis[maxn][maxn][maxn]= {0};
void printans()
{
	for (int i=0; i<n; i++) {
		printf("%d",ans[i]);
		if (i<n-1) printf(" ");
	}
}
void search(int index)
{
	if (index==n) {
		if ((ans[n-1]+ans[n-2])/2==arr[n-1]) {
			printans();
			exit(0);
		}
		return;
	}
	if (index==1) {
		int t=arr[0]*2-ans[0];
		for (int h=t; h<t+2; h++) {
			if (h<=0||vis[index][h][ans[index-1]]) continue;
			vis[index][h][ans[index-1]]=1;
			ans[index]=h;
			search(index+1);
		}
	} else {
		int t=arr[index-1]*3-ans[index-1]-ans[index-2];
		for (int h=t; h<t+3; h++) {
			if (h<=0||vis[index][h][ans[index-1]]) continue;
			vis[index][h][ans[index-1]]=1;
			ans[index]=h;
			search(index+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	arr.resize(n);
	ans.resize(n);
	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
	for (int i=1; i<2*arr[0]; i++) {
		ans[0]=i;
		search(1);
	}
	return 0;
}
