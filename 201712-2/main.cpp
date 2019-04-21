#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,countt=1;
	scanf("%d%d",&n,&k);
	queue<int> q;
	for (int i=1;i<=n;i++) q.push(i);
	while (q.size()>1) {
		int t=q.front();
		q.pop();
		if (!(countt%k==0||countt%10==k)) q.push(t);
		countt++;
	}
	printf("%d",q.front());
	return 0;
}
