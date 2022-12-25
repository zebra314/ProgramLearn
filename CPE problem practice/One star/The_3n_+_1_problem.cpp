#include<bits/stdc++.h>
using namespace std;
/*
    題目:
    1.         輸入 n
    2.         印出 n
    3.         如果 n = 1 結束
    4.         如果 n 是奇數 那麼 n=3*n+1
    5.         否則 n=n/2
    6.         GOTO 2
    例如輸入 22, 得到的數列： 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1 

    對每一對輸入 i , j 你應該要輸出 i, j 和介於 i, j 之間的數所產生的數列中最大的 cycle length。
*/

int solve(int a)
{
    if(a == 1)
    {
        return 1; // 遞迴到1時return 會沿一開始遞迴的路 一路傳回去
    }
    else if(a%2 == 1)
    {
        return solve(a*3+1)+1; // 遞迴到一之後 開始回傳 經過就加一
    }
    else // a%2 == 0
    {
        return solve(a/2)+1;
    }
}
int main()
{

    int a1,b1,a,b;
    int maxi = 0;
    while(cin>>a1>>b1)
    {
        a = max(a1,b1);
        b = min(a1,b1);
        for(int i = b;i<=a;i++)
        {
            if(solve(i)>maxi)
            {
                maxi = solve(i);
            }
        }
        cout<<a1<<" "<<b1<<" "<<maxi<<'\n';
        maxi = 0;
    }
}