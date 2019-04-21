#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,y,g,n,timet=0;
	scanf("%d%d%d",&r,&y,&g);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		switch (a) {
			case 0:{
				timet+=b;
				break;
			}
			case 1:{
				timet+=b;
				break;
			}
			case 2:{
				timet+=b+r;
				break;
			}
			case 3:break;
		}
	}
	printf("%d",timet);
	return 0;
}
