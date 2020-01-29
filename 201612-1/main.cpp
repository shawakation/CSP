#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int countt[maxn]= {0};
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		countt[arr[i]]++;
	}
	sort(arr.begin(),arr.end());
	int t,left=0,right=0;
	if (n&1) t=arr[n/2];
	else t=arr[n/2-1];
	for (int i=1; i<t; i++) left+=countt[i];
	for (int i=t+1; i<=1000; i++) right+=countt[i];
	if (left==right) printf("%d",t);
	else printf("-1");
	return 0;
}
