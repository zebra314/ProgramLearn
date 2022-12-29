#include<bits/stdc++.h>
using namespace std;

int solve(string input){
    int len = input.length();
    bool next = false;
    for(int ans = 1; ans<=len; ans++){ // 重複的長度
        if((len%ans) > 0 ) continue;
        next = false;
        for(int posi = 0; posi<ans; posi++){ // 以第一組重複單位為起始點
            for(int i = posi; i<(len-ans); i+=ans){ // 比較每一組重複單位的同一個位置
                if(input[i] != input[i+ans]){
                    next = true;
                    break;
                } 
            }
            if(next == true) break;
        }
        if (next == false) return len/ans;
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