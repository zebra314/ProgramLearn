#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    int a, b;
    int big, sma;
    cin>>times;
    while(times -- )
    {
        cin>>a>>b;
        // a = 1 + 2
        // b = 1 - 2
        if((a-b)<0 or (a-b)%2 == 1 or (a+b)%2 == 1) 
        {
            cout<<"impossible"<<'\n';
            continue;
        }
        cout<<(a+b)/2<<" "<<abs(a-b)/2<<'\n';
    }
}
