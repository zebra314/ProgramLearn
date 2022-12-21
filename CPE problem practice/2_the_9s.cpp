#include<bits/stdc++.h>
using namespace std;

stringstream ss;
int digitSum (string num){
    int ans = 0;
    for(const auto &ele : num){
        ans += int(ele - '0');
    }
    ss.str("");
    ss.clear();
    ss<<ans;
    ss>>num;
    if(ans%9 != 0 ) return 0;
    else if(ans == 9) return 1;
    return digitSum(num)+1;
}

int main(){
    string num;
    while(cin>>num){
        if(num == "0") break;
        if(digitSum(num) != 0){
            cout<<num<<" "<<"is a multiple of 9 and has 9-degree ";
            cout<<digitSum(num)<<'.'<<'\n';
        }
        else {
            cout<<num<<" is not a multiple of 9."<<'\n';
        }
        
    }
}