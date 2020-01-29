#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,c=0;
	scanf("%d%d",&n,&k);
	queue<int> q;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	while (!q.empty()) {
		int sum=0;
		while (sum<k&&!q.empty()) {
			sum+=q.front();
			q.pop();
		}
		c++;
	}
	printf("%d",c);
	return 0;
}
