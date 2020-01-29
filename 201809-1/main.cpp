#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n),ans(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	for (int i=0;i<n;i++) {
		if (i==0) ans[i]=(arr[i]+arr[i+1])/2;
		else if (i==n-1) ans[i]=(arr[i]+arr[i-1])/2;
		else ans[i]=(arr[i-1]+arr[i]+arr[i+1])/3;
	}
	for (int i=0;i<n;i++) {
		printf("%d",ans[i]);
		if (i<n-1) printf(" ");
	}
	return 0;
}
