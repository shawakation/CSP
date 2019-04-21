#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,countt=0;
	scanf("%d",&n);
	while (n>0) {
		if (n>=50) {
			n-=50;
			countt+=7;
		}
		else if (n>=30&&n<50) {
			n-=30;
			countt+=4;
		}
		else {
			n-=10;
			countt++;
		}
	}
	printf("%d",countt);
	return 0;
}
