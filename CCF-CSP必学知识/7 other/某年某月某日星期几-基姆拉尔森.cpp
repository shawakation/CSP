int whatday(int d,int m,int y)
{
	if(m==1||m==2) m+=12,y--;
	int ans=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return ans+1;
}
int main()
{
	int day,month,year;
	cin>>year>>month>>day;
	cout<<whatday(day,month,year);
	return 0;
}