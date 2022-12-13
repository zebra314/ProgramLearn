#include<bits/stdc++.h>
using namespace std;

unsigned long long int trans(unsigned long long int i)
{
    unsigned long long int ans = 0;
    unsigned long long int dig = 0;
    while(i != 0)
    {
        ans += (i%10)*pow(2,dig);
        i/=10;
        dig++;
    }
    return ans;
}
int main()
{
    stringstream ss;
    int count = 1;
    int times;
    unsigned long long int a, b;
    string c, d;
    cin>>times;
    while(times--)
    {
        ss.clear();
        ss.str("");
        cin>>c>>d;
        ss<<c;
        ss>>a;
        ss.clear();
        ss.str("");
        ss<<d;
        ss>>b;
        // cout<<trans(a)<<" "<<trans(b)<<'\n';
        cout<<"Pair #"<<count<<": ";
        count ++;
        if(c[0]=='0' or d[0]=='0' or c.length() == 1 or d.length() == 1)
        {
            cout<<"Love is not all you need!"<<'\n';
            continue;
        }
        a = trans(a);
        b = trans(b);
        while(a>0 and b>0) 
        {
            if(a>b)
            {
                a = a%b;
            }
            else 
            {
                b = b%a;
            }
        }
        if(max(a, b) == 1)
        {
            cout<<"Love is not all you need!"<<'\n';
        }
        else 
        {
            cout<<"All you need is love!"<<'\n';
        }
    }
}