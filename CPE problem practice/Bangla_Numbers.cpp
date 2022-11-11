#include<bits/stdc++.h>
using namespace std;


/*
    題目:
    Bangla numbers normally use 'kuti' (10000000), 'lakh' (100000), 'hajar' (1000), 'shata' (100) while expanding and converting to text.
    You are going to write a program to convert a given number to text with them.
    
    沒通過zerojudge隱藏測資
*/

void solve(string inp)
{
    int stage;
    for(int i = 0; i<inp.length(); i++)
    {
        // 從後面數來第七個 若前面有數字 插入kuti
        if((inp.length() - i)%7 == 0 and inp[i-1])
        {
            cout<<" kuti";
        } 

        // 從後面數來第六個 若前面兩個數字皆非零 輸出數字與插入lakh
        if((inp.length() - i)%7 == 6 and not (inp[i] == '0' and inp[i-1] == '0'))
        {
            cout<<" "<<inp[i-1]<<inp[i]<<" lakh";
        }
        else if((inp.length() - i)%7 == 4 and not (inp[i] == '0' and inp[i-1] == '0'))
        {
            cout<<" "<<inp[i-1]<<inp[i]<<" hajar";
        }
        else if((inp.length() - i)%7 == 3 and inp[i] != '0')
        {
            cout<<" "<<inp[i]<<" shata";
        }
        else if((inp.length() - i)%7 == 1 and not (inp[i] == '0' and inp[i-1] == '0'))
        {
            cout<<" "<<inp[i-1]<<inp[i];
        }
        // else if((inp.length() - i)%7 == 1 and (inp[i] == '0' and inp[i-1] == '0'))
        // {
        //     cout<<'0';
        // }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string inp;
    int times = 1;
    while(cin>>inp)
    {   
        cout<<times<<".";
        solve(inp);
        cout<<'\n';
        times ++;
    }
}