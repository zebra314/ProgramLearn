#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int times, total, num, ans = 0;
    vector<int> train;
    cin>>times;
    while(times--)
    {
        ans = 0;
        train.clear();
        cin>>total;
        while(total--)
        {
            cin>>num;
            for(int j= 0;j<train.size();j++)
            {
                if(train[j]>num)
                    ans++;
            }
            train.push_back(num);
        }
        cout<<"Optimal train swapping takes ";
        cout<<ans<<" swaps."<<'\n';
    }
}