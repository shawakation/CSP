#include<iostream>
#include<cstdio>
#define MAIN 110
#define MAX 0xffffff
using namespace std;
int n,data[MAIN],cunt=0;
void merge(int left,int middle,int right)
{
	int L[MAIN],R[MAIN];
	int n1=middle-left+1,n2=right-middle;
	for(int i=1; i<=n1; i++) L[i]=data[left+i-1];
	for(int i=1; i<=n2; i++) R[i]=data[middle+i];
	L[n1+1]=MAX;
	R[n2+1]=MAX;
	int templ=1,tempr=1;
	for(int i=left; i<=right; i++)
		if(L[templ]<=R[tempr]) data[i]=L[templ++];
		else { data[i]=R[tempr++]; cunt+=n1-templ+1; }
}
void merge_sort(int left,int right)
{
	if(left<right) {
		int middle=(left+right)/2;
		merge_sort(left,middle);
		merge_sort(middle+1,right);
		merge(left,middle,right);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&data[i]);
	merge_sort(1,n);
	for(int i=1; i<=n; i++) printf("%d ",data[i]);
	printf("\n");
	printf("%d\n",cunt);
	return 0;
}
