#include<bits/stdc++.h>
using namespace std;

long long int solve(long long int num, long long int day)
{
    long long int total_day = 0;
    while(total_day<day)
    {
        total_day+=num;
        num++;
    }
    num--;
    return num;
}

int main()
{
    long long int num, day;
    while(cin>>num>>day)
    {
        cout<<solve(num, day)<<'\n';
    }
} 