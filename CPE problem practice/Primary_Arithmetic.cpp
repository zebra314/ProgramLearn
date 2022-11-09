#include<bits/stdc++.h>
using namespace std;
/*
    題目:
        每一列測試資料有2個正整數，長度均小於10位。最後一列有2個0代表輸入結束。
        每列測試資料輸出該2數相加時產生多少次進位，請參考Sample Output。注意進位超過1次時operation有加s

    1. 透過%10得到個位數 
    2. 透過/10前往下一位數
*/
int solve(int a, int b)
{
    int times = 0;
    int next = 0;
    while(a>0 or b>0)
    {
        if((a%10+b%10+next) > 9)
        {
            next = 1;
            times++;
        }else
        {
            next = 0;
        }
        a = a/10;
        b = b/10;
    }
    return times;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int  a, b;
    while(cin>>a>>b)
    {
        if(a== 0 and b== 0) break;
        if(solve(a,b)==0)
        {
            cout<<"No carry operation."<<'\n';
        }
        else if (solve(a,b)==1)
        {
            cout<<"1 carry operation."<<'\n';
        }
        else
        {
            cout<<solve(a,b)<<" carry operations."<<'\n';
        }
    }
}