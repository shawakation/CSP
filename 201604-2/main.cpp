#include <bits/stdc++.h>
using namespace std;
short graph[16][11]= {0},kuai[5][5]= {0};
vector<pair<int,int> > backup;
int main()
{
	int n,minh=INT_MAX;
	for (int i=1; i<=15; i++) for (int j=1; j<=10; j++) scanf("%d",&graph[i][j]);
	for (int i=1; i<=4; i++) for (int j=1; j<=4; j++) scanf("%d",&kuai[i][j]);
	scanf("%d",&n);
	for (int i=1; i<=4; i++) for (int j=n; j<=n+3; j++) {
			graph[i][j]=kuai[i][j-n+1];
			if (graph[i][j]==1) backup.push_back(make_pair(i,j));
		}
	for (int i=n; i<=n+3; i++) {
		int j=4,g=5;
		while (j>=1&&graph[j][i]==0) j--;
		while (g<=15&&graph[g][i]==0) g++;
		int height=g-j-1;
		minh=min(minh,height);
	}
	while (!backup.empty()) {
		pair<int,int> p=backup[backup.size()-1];
		backup.pop_back();
		graph[p.first][p.second]=0;
		graph[p.first+minh][p.second]=1;
	}
	for (int i=1; i<=15; i++) {
		for (int j=1; j<=10; j++) {
			printf("%d",graph[i][j]);
			if (j<10) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
