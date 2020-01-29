#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,maxt=-1;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
	for (int i=1; i<n; i++) maxt=max(maxt,abs(arr[i]-arr[i-1]));
	printf("%d",maxt);
	return 0;
}
