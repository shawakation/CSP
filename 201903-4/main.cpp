#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
short graph[maxn][maxn]= {0};
deque<char*> process[maxn];
unordered_set<int> blocking,finished;
int n,cur=0;
void nextcur()
{
	cur=(cur+1)%n;
}
void reset()
{
	for(int i=0; i<n; i++) process[i].clear();
	memset(graph,0,sizeof(graph));
	blocking.clear();
	finished.clear();
	cur=0;
}
int main()
{
	int T;
	scanf("%d%d",&T,&n);
	getchar();
	for(int y=0; y<T; y++) {
		for(int h=0; h<n; h++) {
			char cc='\0';
			while(1) {
				if(cc=='\n') break;
				char* order=new char[5];
				scanf("%s",order);
				process[h].push_back(order);
				cc=getchar();
			}
		}
		bool islock=0;
		while(1) {
			if(finished.size()==n||islock) break;
			if(finished.find(cur)!=finished.end()||blocking.find(cur)!=blocking.end()) nextcur();
			char* t=process[cur].front();
			if(t[0]=='R') {
				int renum=t[1]-'0';
				graph[renum][cur]--;
				if(graph[renum][cur]==-1) blocking.insert(cur);
				else
					if(graph[renum][cur]==0) {
						blocking.erase(renum);
						process[renum].pop_front();
						if(process[renum].size()==0) finished.insert(renum);
						process[cur].pop_front();
						if(process[cur].size()==0) finished.insert(cur);
					}
			} else
				if(t[0]=='S') {
					int tonum=t[1]-'0';
					graph[cur][tonum]++;
					if(graph[cur][tonum]==1) blocking.insert(cur);
					else
						if(graph[cur][tonum]==0) {
							blocking.erase(tonum);
							process[tonum].pop_front();
							if(process[tonum].size()==0) finished.insert(tonum);
							process[cur].pop_front();
							if(process[cur].size()==0) finished.insert(cur);
						}
				}
			if(finished.size()<n&&n-finished.size()==blocking.size()) islock=1;
			nextcur();
		}
		if(islock) printf("1\n");
		else printf("0\n");
		if(y<T) reset();
	}
	return 0;
}
