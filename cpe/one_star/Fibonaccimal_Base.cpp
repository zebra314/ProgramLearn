#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long int>F = {0,1};
    for(int i=1;F[i]<100000000;i++)
    {
        F.push_back(F[i-1]+F[i]);
    }
    int time;
    long long int j;
    int posi;
    cin>>time;
    while(time--)
    {
        cin>>j;
        cout<<j<<" = ";
        if(j == 1)
        {
            cout<<1<<" (fib)"<<'\n';
            continue;
        }
        if(F[lower_bound(F.begin(),F.end(),j)-F.begin()]>j)
            posi = lower_bound(F.begin(),F.end(),j)-F.begin()-1;
        else 
            posi = lower_bound(F.begin(),F.end(),j)-F.begin();
        while(posi>1)
        {
            if(j>=F[posi])
            {
                cout<<1;
                j-=F[posi];
            }
            else cout<<0;
            posi--;
        }
        cout<<" (fib)"<<'\n';
    }
}