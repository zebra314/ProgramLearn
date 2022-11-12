#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    map<char,int> amap, bmap;
    set<char> ans;
    while(cin>>a>>b)
    {
        amap.clear();
        bmap.clear();
        ans.clear();
        for(const auto ele : a)
        {
            amap[ele] ++;
        }
        for(const auto ele : b)
        {
            if(amap[ele] >= 1)
            {
                ans.insert(ele);
            }
            bmap[ele]++;
        }
        for(const auto ele : ans)
        {
            for(int i = 0; i<min(bmap[ele],amap[ele]); i++)
            {
                cout<<ele;
            }
        }
        cout<<'\n';
    }
}