#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input, str1, str2;
    stringstream ss;
    bool in;
    while(getline(cin,input) and input !=""){
        ss.clear();
        ss.str("");
        ss<<input;
        ss>>str1;ss>>str2;
        int j = 0;
        in = true;
        for(int i = 0; i<str1.length(); i++){
            for(j; j<str2.length(); j++){
                if(str1[i] == str2[j]) break;
                if(j == str2.length()-1) in = false;
            }
        }
        if(in == true) cout<<"Yes\n";
        else cout<<"No\n";
    }
}