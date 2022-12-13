#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int ori, base;
    vector<long long int>ans;
    bool boring;
    while(cin>>ori>> base)
    {
        if(base == 0 or base == 1 )
        {
            cout<<"Boring!"<<'\n';
            continue;
        }
        boring = false ;
        ans.clear();
        while(ori > 1)
        {
            ans.push_back(ori);
            if(ori%base != 0)
            {
                cout<<"Boring!"<<'\n';
                boring  = true;
                break;
            }
            ori/=base; // 要放對位置 
        }
        if(boring == false)
        {
            ans.push_back(1);
            for(const auto &ele :ans)
            {
                cout<<ele<<" ";
            }
            cout<<'\n';
        }
    }
}