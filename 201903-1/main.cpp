#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double ans[3];
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d",&arr[i]);
	ans[0]=(double)arr[0];
	ans[1]=(double)arr[arr.size()-1];
	if(n&1) ans[2]=(double)arr[n/2];
	else ans[2]=((double)arr[n/2]+(double)arr[n/2-1])/2.0f;
	sort(ans,ans+3,greater<double>());
	for(int i=0; i<3; i++) {
		if(ans[i]==(int)ans[i]) printf("%d",(int)ans[i]);
		else printf("%.1f",ans[i]);
		if(i<3) printf(" ");
	}
	return 0;
}
