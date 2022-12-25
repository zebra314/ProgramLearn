#include<bits/stdc++.h>
using namespace std;


int main()
{
    stringstream ss;
    int time, num, sum, times = 1;
    vector<int>nums;
    set<int>sums;
    string innum;
    while(cin>>time)
    {
        nums.clear();
        sums.clear();
        ss.clear();
        ss.str("");
        cin.get();
        getline(cin,innum);
        ss<<innum;
        while(ss>>num)
        {
            // 自己跟自己香家也不能有重複的和
            // 所以都先放進nums裡 才能檢查和自己相加的項
            nums.push_back(num); 
            for(const auto ele:nums)
            {
                sum = ele + num;
                if(sums.count(sum)!=0)
                    break;
                else 
                    sums.insert(sum);
            }
        }
        cout<<"Case #"<<times<<": ";
        times++;
        if(sums.size() == (time*(time-1)/2+time))
            cout<<"It is a B2-Sequence."<<'\n';
        else    
            cout<<"It is not a B2-Sequence."<<'\n';
        cout<<'\n';
    }
}