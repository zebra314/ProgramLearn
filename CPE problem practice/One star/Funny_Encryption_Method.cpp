#include<bits/stdc++.h>
using namespace std;
int solve1(int i)
{
    int out = 0;
    while(i > 0)
    {
        out += i%2;
        i = i/2;
    }
    return out;
}

int solve2(int i)
{
    int hex = 0, dig = 0;
    while(i>0)
    {
        hex += (i%10)*pow(16,dig);
        dig++;
        i/=10;
    }
    return hex;
}

int main()
{
    int i, time;
    cin>>time;
    while(time--)
    {
        cin>>i;
        cout<<solve1(i)<<" "<<solve1(solve2(i));
        cout<<'\n';
    }

}