#include<bits/stdc++.h>
using namespace std;

double solve(double total, double odd, double the)
{
    double output = pow(1-odd,the -1)*odd/(1-pow(1-odd,total));
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
        // if(solve(total, odd, the)<0.00001)
        //     cout<<"0.0000"<<'\n';
        // else 
            cout<<setprecision(4) << setiosflags(ios::fixed);
            cout<<solve(total, odd, the)<<'\n';
    }
}