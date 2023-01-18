#include<bits/stdc++.h>
using namespace std;

int main(){
    string strs[5] = {"flower","flow","flight"};
    string ans = strs[0];
    ans.erase(ans.begin()+2);
    cout<<ans;
    // string ans = strs[0];
    // for(int i = 1; i<3; i++){
    //     for(int j = 0; j<strs[i].length(); j++){
    //         int posi = 0;
    //         while(posi!=ans.length()-1){
    //             if(ans[posi] == strs[i][j]) posi++;
    //             else {
    //                 ans.erase(ans.begin()+posi);
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<'\n';
}