#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,score=0,num=2;
	bool flag=0;
	while (1) {
		scanf("%d",&k);
		if (k==0) break;
		else if (k==1) {
			score++;
			num=2;
			flag=0;
		}
		else if (k==2) {
			if (!flag) {
				score+=2;
				flag=1;
			}
			else {
				num+=2;
				score+=num;
			}
		}
	}
	printf("%d",score);
	return 0;
}
