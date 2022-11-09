#include<bits/stdc++.h>
using namespace std;

bool solve1(int i)
{
    if(i%11 == 0) 
        return true;
    else 
        return false;
}

bool solve2(string i)
{
    int odd = 0, even = 0;
    for(int j = 0;j<i.length();j+=2)
    {
        odd += int(i[j]-'0');
    }
    for(int j = 1;j<i.length();j+=2)
    {
        even += int(i[j]-'0');
    }
    if(abs(odd - even)%11 == 0)
        return true;
    else 
        return false;
}

int main()
{
    string a;
    while(cin>>a)
    {
        if(a=="0")break;
        if(solve2(a) == true)
            cout<<a<<" is a multipule of 11."<<'\n';
        else 
            cout<<a<<" is not a multipule of 11."<<'\n';
    }
}