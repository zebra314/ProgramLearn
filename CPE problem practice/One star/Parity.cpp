#include<bits/stdc++.h>
using namespace std;

void solve(unsigned long long int input){
    string ans_str;
    int one_amount = 0;
    unsigned long long int times = 0;
    unsigned long long int ans = 0;
    while (input != 0){
        ans_str =  ( input % 2 == 0 ? "0" : "1" )+ ans_str;
        if(input % 2 == 1) one_amount++;
        input /= 2;
    }
    cout<<"The parity of "; 
    cout<<ans_str;
    cout<<" is "<<one_amount<<" (mod 2)."<<'\n'; 
}
int main(){
    unsigned long long input;
    while(cin>>input){
        if(input == 0) break;
        solve(input);
    }
}