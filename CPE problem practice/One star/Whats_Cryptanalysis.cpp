#include<bits/stdc++.h>
using namespace std;

//要排序vector裡的pair 要另外寫rule
bool rule(pair<char, int> i, pair<char, int> j)
{
    if(i.second != j.second)
    {
        return i.second > j.second ;
    }
    else
    {
        return int(i.first) < int(j.first);
    }
}

void solve(map<char, int> &inmap, string intxt)
{
    for(int i = 0; i<intxt.length(); i++)
    {
        if(int(intxt[i])>=65 and int(intxt[i])<=90) 
        {
            inmap[intxt[i]]++;
        }
        else if(int(intxt[i])>=97 and int(intxt[i])<=122)
        {
            inmap[char(int(intxt[i])-32)]++;
        }
    }
}

int main()
{
    int times;
    string txt;
    map<char,int> ans;
    vector<pair<char,int>> ans2;
    pair<char, int> temp;
    cin>>times;
    cin.get(); // 吃掉enter
    while(times--)
    {
        getline(cin,txt);
        solve(ans, txt);
    }
    for(const auto &ele :ans)
    {
        temp = make_pair(ele.first, ele.second); // char, int
        ans2.push_back(temp);
    }
    sort(ans2.begin(), ans2.end(), rule);
    for(const auto ele: ans2)
    {
        cout<<ele.first<<" "<<ele.second<<'\n';
    }
}