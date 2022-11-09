#include<bits/stdc++.h>
using namespace std;

int solve(int a)
{
    if(a == 1)
    {
        return 1; // 遞迴到1時return 會沿一開始遞迴的路 一路傳回去
    }
    else if(a%2 == 1)
    {
        return solve(a*3+1)+1; // 遞迴到一之後 開始回傳 經過就加一
    }
    else // a%2 == 0
    {
        return solve(a/2)+1;
    }
}
int main()
{

    int a1,b1,a,b;
    int maxi = 0;
    while(cin>>a1>>b1)
    {
        a = max(a1,b1);
        b = min(a1,b1);
        for(int i = a;i<=b;i++)
        {
            if(solve(i)>maxi)
            {
                maxi = solve(i);
            }
        }
        cout<<a<<" "<<b<<" "<<maxi<<'\n';
    }
}