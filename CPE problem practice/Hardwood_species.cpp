#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); //快了約0.8秒
    cin.tie(0);
    double times, total;
    string name;
    map<string, double>trees;
    cin>>times;
    cin.get(); cin.get(); // 接收兩次'\n'
    while(times --)
    {
        trees.clear();
        total = 0;
        while(getline(cin,name) and name !="") //次數之間的換行與最後一次到底的 輸入為空 
        {   
            trees[name] ++;
            total++;
        }
        for(const auto &ele:trees)
            cout<<setprecision(4)<<setiosflags(ios::fixed)<<ele.first<<" "<<ele.second*100/total<<'\n';
    }

}

