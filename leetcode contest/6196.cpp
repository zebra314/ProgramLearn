#include<bits/stdc++.h>
using namespace std;

// 165462 60
// 238182 5
int main(){
    int num = 0,temp = 0, ans = 0;
    string s;
    int k;
    cin>>s>>k;
    bool flag = false;
    for(const auto &ele :s){
        temp = num*10+int(ele-'0');
        cout<<temp<<" ";
        if(temp <= k) { 
            // cout<<num<<" ";
            num = temp;
            flag = true;
        }
        else if(temp>k and flag == true){
            num = int(ele-'0');
            if(num<=k) flag =true;
            else flag = false;
            temp = num;
            ans++;
        }
        else if(temp>k and flag == false){
            cout<< -1;
        }
    }
    // if(num<=k) ans++;
    // cout<<ans<<'\n';
}