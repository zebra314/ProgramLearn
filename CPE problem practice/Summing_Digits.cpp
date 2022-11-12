#include<bits/stdc++.h>
using namespace std;

int solve(int in)
{
    int temp;
    while(in>=10)
    {
        temp = 0;
        while(in>0)
        {
            temp += in%10;
            in /= 10;
        }
        in = temp;    
    }
    return in;
}

int main()
{
    int i;
    while(cin>>i)
    {
        if(i == 0) break;
        cout<<solve(i)<<'\n';
    }
}