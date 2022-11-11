#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    string country;
    string firstNam, lastNam, women;
    map<string, set<string>> data;
    cin>>times;
    while(times--)
    {
        cin>>country>>firstNam>>lastNam;
        women = firstNam + " " + lastNam;
        data[country].insert(women);
    }
    for(const auto ele:data)
    {
        cout<<ele.first<<" "<<ele.second.size()<<'\n';
    }
}
