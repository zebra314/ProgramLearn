#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    int c;
    int ans;
    while(cin>>a>>b)
    {
        ans = 0;
        if(a==0 and b==0)
            break;
        c = ceil(pow(min(a, b), 0.5));
        while(true)
        {
            if(c*c>max(a,b))
                break;
            c++;
            ans++;
        }
        cout<<ans<<'\n';
    }
}