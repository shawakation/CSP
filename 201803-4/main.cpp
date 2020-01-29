#include <bits/stdc++.h>
using namespace std;
short graph[4][4]= {0};
int countzero()
{
	int sum=0;
	for (int i=1; i<=3; i++) for (int j=1; j<=3; j++) if (graph[i][j]==0) sum++;
	return sum;
}
bool judgerow(int row,int num)
{
	if (graph[row][1]==num&&graph[row][2]==graph[row][1]&&graph[row][3]==graph[row][2])
		return 1;
	else return 0;
}
bool judgecol(int col,int num)
{
	if (graph[1][col]==num&&graph[2][col]==graph[1][col]&&graph[3][col]==graph[2][col])
		return 1;
	else return 0;
}
bool judgetilt(int num)
{
	if (graph[1][1]==num&&graph[2][2]==graph[1][1]&&graph[3][3]==graph[2][2]) return 1;
	if (graph[2][2]==num&&graph[3][1]==graph[2][2]&&graph[1][3]==graph[2][2]) return 1;
	return 0;
}
int getscore(int num)
{
	bool iswin=0;
	if (judgerow(1,num)||judgerow(2,num)||judgerow(3,num)) iswin=1;
	if (judgecol(1,num)||judgecol(2,num)||judgecol(3,num)) iswin=1;
	if (judgetilt(num)) iswin=1;
	if (iswin) {
		if (num==1) return countzero()+1;
		else return -(countzero()+1);
	} else return 0;
}
int search(int num)
{
	if (countzero()==0) return 0;
	int maxscore=-10,minscore=10;
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++) {
			if (graph[i][j]==0) {
				graph[i][j]=num;
				int w=getscore(num);
				if (w) {
					graph[i][j]=0;
					return w>0?max(maxscore,w):min(minscore,w);
				}
				if (num==1) maxscore=max(maxscore,search(2));
				else minscore=min(minscore,search(1));
				graph[i][j]=0;
			}
		}
	return num==1?maxscore:minscore;
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int i=0; i<t; i++) {
		memset(graph,0,sizeof(graph));
		for (int j=1; j<=3; j++) for (int g=1; g<=3; g++) scanf("%d",&graph[j][g]);
		int alice=getscore(1),bob=getscore(2);
		if (alice>0) printf("%d\n",alice);
		else if (bob<0) printf("%d\n",bob);
		else printf("%d\n",search(1));
	}
	return 0;
}
