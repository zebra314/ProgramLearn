#include<bits/stdc++.h>
using namespace std;


//vec
void solve(vector<int> nums, multiset<int> mins)
{
    int A, A_1, A_2, minn;
    int ans_2;
    multiset<int> ans2;
    sort(nums.begin(),nums.end());
    if(nums.size()%2 == 1)
    {
        A = nums[(nums.size()-1)/2];
        cout<<A<<" "<<mins.count(A)<<" "<<1;
        cout<<'\n';
    }
    else 
    {
        A_1 = nums[(nums.size()/2)-1];
        A_2 = nums[(nums.size()/2)];
        A = A_1;
        if(A_1 != A_2)
            cout<<A<<" "<<mins.count(A_1)+mins.count(A_2)<<" "<<(A_2 - A_1+1);
        else //A_1 == A_2
        {
            cout<<A<<" "<<mins.count(A_1)<<" "<<1;
        }
            
        cout<<'\n';
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int times, num;
    vector<int> nums;
    multiset<int>mins;
    while(cin>>times)
    {
        nums.clear();
        mins.clear();
        while(times--)
        {
            cin>>num;
            nums.push_back(num);
            mins.insert(num);
        }
        solve(nums,mins);
    }
}