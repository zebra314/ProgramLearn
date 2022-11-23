#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    int time = 1;
    int a, b;
    int outp;
    cin>>times;
    while(times -- )
    {
        
        outp = 0;
        cin>>a>>b;
        if(a%2 == 0) a++;
        if(b%2 == 0) b--;
        for(int i = a; i<=b; i = i+2)
        {
            outp+=i;
        }
        cout<<"Case "<<time<<": ";
        cout<<outp<<'\n';
        time++;
    }
}