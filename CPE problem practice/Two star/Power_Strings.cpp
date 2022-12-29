#include<bits/stdc++.h>
using namespace std;

bool check(string input, string ans){
    int sub_len = ans.length();
    int main_len = input.length();
    if((main_len % sub_len)!= 0) return false;
    for(int i = 0; i<main_len; i+=sub_len){ // the position of main string for sub string to start comparison
        for(int j = 0; j<sub_len; j++){
            if(ans[j] != input[i+j]) return false;
        }
    }
    return true;
}

int solve(string input){
    int len = input.length();
    string ans = "";
    int posi = 0;
    while(posi != input.length()){
        ans += input[posi];
        if(check(input, ans) == true) return (len/(posi+1));
        posi++;
    }
    return 1;
}
int main(){
    string input;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>input){
        if(input == ".") break;
        cout<<solve(input)<<'\n';
    }
}