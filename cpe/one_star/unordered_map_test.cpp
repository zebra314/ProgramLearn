#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> num = {1,2,5,4,3,6,5,7,9};
    unordered_map<int, int> ans; // key: the value in num // value: the position of the value in num
    int target =  10;
    // for(int i = 0; i<num.size(); i++){
    //     ans[num[i]] = i;
    // }
    for(int j = 0; j<num.size(); j++){
        auto posi = ans.find(target - num[j]);
        if( posi != ans.end()){ // 如果有找到(target - i[j]) ， 代表兩個數都有找到
            cout<<"value: "<<num[j]<<" "<<posi ->first<<'\n'; // cout the value
            cout<<"position: "<<j<<" "<<posi ->second<<'\n'; // cout the position
            break;
        } 
        ans[num[j]] = j;
        // 搜尋自己前面的數字 如果沒有找到 就放進ans裡 
        // 第一組搜尋到的會是 6, 4
        // 也可以先建好 ans
    }

    // ans[1] = 2;
    // ans[2] = 3;
    // ans[4] = 5;
    // auto i = ans.find(1);
    // cout<< i->first; // i->first // i->second
}