#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num,id;
    node(int num1,int id1)
    {
        num=num1;
        id=id1;
    }
};
int main()
{
    int n,k;
    cin>>n>>k;
    deque <node> q;
    q.clear();
    for(int i=1; i<=n; i++)
    {
        int number;
        cin>>number;
        node temp(number,i);
        while(1)
        {
            if(q.empty()) break;
            else if(q.back().num>number) break;
                else q.pop_back();
        }
        while(1)
        {
            if(q.empty()) break;
            else if(i-q.front().id<k) break;
                else q.pop_front();
        }
        q.push_back(temp);
        cout<<q.front().num<<endl;
    }
    return 0;
}
