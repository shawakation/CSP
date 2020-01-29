#include <bits/stdc++.h>
using namespace std;
bool seat[21][6]= {0};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			bool flag=0;
			for (int a1=1; a1<=20; a1++) {
				for (int a2=1; a2<=5; a2++) if (seat[a1][a2]==0) {
						seat[a1][a2]=1;
						printf("%d\n",(a1-1)*5+a2);
						flag=1;
						break;
					}
				if (flag) break;
			}
		} else if (t>1) {
			bool flag=0;
			for (int a1=1; a1<=20; a1++) {
				for (int a2=1; a2<=6-t; a2++) {
					bool flag2=1;
					for (int h=a2; h<a2+t; h++) if (seat[a1][h]) flag2=0;
					if (flag2) {
						for (int h=a2; h<a2+t; h++) {
							seat[a1][h]=1;
							printf("%d",(a1-1)*5+h);
							if (h<a2+t-1) printf(" ");
						}
						printf("\n");
						flag=1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag==0) {
				for (int a1=1; a1<=20&&t>0; a1++) {
					for (int a2=1; a2<=5&&t>0; a2++) {
						if (seat[a1][a2]==0) {
							printf("%d",(a1-1)*5+a2);
							seat[a1][a2]=1;
							t--;
							if (t>0) printf(" ");
							else printf("\n");
						}
					}
				}
			}
		}
	}
	return 0;
}
