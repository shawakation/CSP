#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,mincha=INT_MAX;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	for (int i=0;i<n-1;i++) mincha=min(mincha,arr[i+1]-arr[i]);
	printf("%d",mincha);
	return 0;
}
