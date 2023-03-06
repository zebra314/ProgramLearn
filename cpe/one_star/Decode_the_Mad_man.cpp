#include<bits/stdc++.h>
using namespace std;

int main()
{
    string code = "23edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-['=]";
    string decode = "`1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol0p";
    map<char,char> tabl;
    tabl['\\'] = '[';
    
    for(int i = 0; i<code.length(); i++)
    {
        tabl[code[i]] = decode[i];
    }
    string txt;
    while(getline(cin,txt))
    {
        for(int i = 0; i<txt.length(); i++)
        {
            if(txt[i] == ' ') cout<<" ";
            else cout<<tabl[txt[i]];
        }
        cout<<'\n';
    }
}