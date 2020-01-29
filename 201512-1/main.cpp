#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int sum=0;
	for (int i=0;i<s.length();i++) sum+=s[i]-'0';
	printf("%d",sum);
	return 0;
}
