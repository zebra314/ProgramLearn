#include<bits/stdc++.h>
using namespace std;    
//      2   
//  4   1   3   6
//      5   

// 1:[上 後 下 前] 2:[左 右]
// 往前或往後滾 更動 1
// 往左或往右滾 將左右與上下對調
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int times;
    string dir;
    while(cin>>times)
    {
        if(times == 0) break;
        vector<int> pos_1 = {1, 5, 6, 2}; // [上 後 下 前]
        vector<int> pos_2 = {1, 4, 6, 3}; // [上 右 下 左]
        // int pos_1[4] = {1, 5, 6, 2}; // [上 後 下 前]
        // int pos_2[4] = {1, 4, 6, 3}; // [上 右 下 左]
        while(times--)
        {
            cin>>dir;
            if(dir == "north")
            {
                pos_1.push_back(pos_1[0]);
                pos_1.erase(pos_1.begin());
                // swap(pos_1[0],pos_1[1]);
                // swap(pos_1[2],pos_1[1]);
                // swap(pos_1[2],pos_1[3]);
                pos_2[0] = pos_1[0];
                pos_2[2] = pos_1[2];

            }
            else if(dir == "east")
            {
                pos_2.insert(pos_2.begin(),pos_2.back());
                pos_2.pop_back();
                // swap(pos_2[3],pos_2[2]);
                // swap(pos_2[2],pos_2[1]);
                // swap(pos_2[0],pos_2[1]);
                pos_1[0] = pos_2[0];
                pos_1[2] = pos_2[2];
            }
            else if(dir == "west")
            {
                pos_2.push_back(pos_2[0]);
                pos_2.erase(pos_2.begin());
                // swap(pos_2[0],pos_2[1]);
                // swap(pos_2[2],pos_2[1]);
                // swap(pos_2[2],pos_2[3]);
                pos_1[0] = pos_2[0];
                pos_1[2] = pos_2[2];
            }
            else if(dir == "south")
            {   
                pos_1.insert(pos_1.begin(),pos_1.back());
                pos_1.pop_back();
                // swap(pos_1[3],pos_1[2]);
                // swap(pos_1[2],pos_1[1]);
                // swap(pos_1[0],pos_1[1]);
                pos_2[0] = pos_1[0];
                pos_2[2] = pos_1[2];
            } 
        }
        cout<<pos_1[0]<<'\n';
    }
}