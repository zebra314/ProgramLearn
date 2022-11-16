#include<bits/stdc++.h>
using namespace std;

double solve(double total, double odd, double the)
{
    double output = pow(1-odd,the -1)*odd/(1-pow(1-odd,2));
    return output;
}

int main()
{
    int times;
    double total, the;
    double odd;
    cin>>times;
    while(times--)
    {
        cin>>total>>odd>>the;
        cout<<solve(total, odd, the)<<'\n';
    }
}