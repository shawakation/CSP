bool prime(int temp)
{
    for(int i=2;i<=sqrt(temp);i++) if(!(temp%i)) return false;
    return true;
}
