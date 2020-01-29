#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,c=0;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	for (int i=1;i<n-1;i++)
		if (arr[i-1]>arr[i]&&arr[i+1]>arr[i]||arr[i-1]<arr[i]&&arr[i+1]<arr[i]) c++;
	printf("%d",c);
	return 0;
}
