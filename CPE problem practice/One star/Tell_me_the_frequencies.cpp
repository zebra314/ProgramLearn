#include<bits/stdc++.h>
using namespace std;

bool rule(pair<int,int> i, pair<int,int>j)
{
    if(i.second != j.second)
        return i.second < j.second;
    else 
        return i.first > j.first;
}

int main()
{
    map<int, int> ans;
    string input;
    vector<pair<int,int>> ans_1;
    pair<int,int> temp;
    while(getline(cin,input))
    {
        ans.clear();
        ans_1.clear();
        for(const auto &ele :input)
            ans[int(ele)] ++;
        for(const auto &ele :ans)
        {   
            temp = make_pair(ele.first,ele.second);
            ans_1.push_back(temp);
        }
        sort(ans_1.begin(), ans_1.end(), rule);
        for(const auto &ele :ans_1)
        {
            cout<<ele.first<<" "<<ele.second<<'\n';
        }
        cout<<'\n';
    }
}