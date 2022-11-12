#include<bits/stdc++.h>
using namespace std;

int mod;
bool rule(int i, int j) // i在j前面
{
    //餘數不同
    if((i%mod) != (j%mod))
    {
        return (i%mod) < (j%mod);
    } 
    //餘數相同 奇偶不同
    else if(abs(i%2) != abs(j%2))
    {
        return (abs(i%2) == 1 and abs(j%2) == 0);
    }   
    //餘數相同 皆為奇數
    else if(abs(i%2) == 1) 
    {
        return i>j;
    }
    //餘數相同 皆為偶數
    else 
    {
        return i<j;
    }
}

int main()
{
    int times, num;
    vector<int> ans;
    while (1)
    {
        cin>>times>>mod;
        cout<<times<<" "<<mod<<'\n';
        if(times == 0 and mod == 0) break;
        while(times--)
        {
            cin>>num;
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end(), rule);
        for(const auto &ele : ans)
        {
            cout<<ele<<'\n';
        }
        ans.clear();
    }
}