#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times, days, total, num;
    vector<int> day;
    map<int,int> ans; // key = date, value = 1 or 0 
    cin>>times;
    int temp;
    int out;
    while(times--)
    {
        day.clear();
        ans.clear();
        out = 0;
        cin>>days;
        cin>>total;
        while(total--)
        {
            cin>>num;
            day.push_back(num);
        }
        for(int i = 0; i<day.size(); i++)
        {
            temp = 0;
            while(true)
            {
                temp += day[i];
                if(temp>days)
                    break;
                if(temp%7 == 0 or (temp-6)%7 == 0)
                    continue;
                ans[temp] = 1;
            }
        }
        for(const auto &ele : ans)
        {
            out += ele.second;
        }
        cout<<out<<'\n';
    }
}