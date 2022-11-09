#include<bits/stdc++.h>
using namespace std;

/*
    題目:
    世界聞名的黑社會老大Vito Deadstone要搬到紐約來了。在那裡他有一個大家族，並且他們都住在Lamafia大道上。
    因為Vito時常要拜訪所有的親戚，他想要找一間離他們最近的房子，也就是說他希望從他的家到所有的親戚的家的距離的和為最小。
    他恐嚇你寫一個程式來幫助幫助他解決這個問題。

    1. 找出某一個位置到每一家的最短距離
    2. 這個位置 平均 or 中位數
    3. 中位數一定會比平均來的短, 因為中位數本來就包含在群集中, 和每個元素相減, 會有一筆是0, 平均數則不一定

*/
int solve(vector<int> addr)
{
    sort(addr.begin(),addr.end());
    int mid = addr.size()/2;
    int distance = 0;
    for(const auto &ele :addr)
    {
        distance = distance + abs(ele - addr[mid]);
    }
    return distance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tim1, tim2;
    int hous;
    cin>>tim1;
    vector<int> addrs;
    while(tim1--)
    {
        cin>>tim2;
        while(tim2--)
        {
            cin>>hous;
            addrs.push_back(hous);
        }
        cout<<solve(addrs)<<'\n';
        addrs.clear();
    }
}