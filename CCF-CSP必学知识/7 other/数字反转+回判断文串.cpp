int change(int num)
{
    int ans=0,temp=0;
    while(num)
    {
        temp=num%10;
        ans=ans*10+temp;
        num/=10;
    }
    return ans;
}
bool judge(int num)
{
    int temp=0,ori=num;
    while(num)
    {
        temp=temp*10+num%10;
        num/=10;
    }
    return temp==ori;
}
