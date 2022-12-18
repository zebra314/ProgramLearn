#include<bits/stdc++.h>
using namespace std;

int solve(int num)
{
    int ans = num;
    while(num>=3)
    {
        ans+=num/3;
        num = (num/3)+(num%3);  
        // if(num == 2) ans++; // 不可以放在這裡 num == 4 會有一樣的結果(num == 2)
    }
    if(num == 2) ans++; 
    return ans;
}
int main()
{
    int ori;
    while(cin>>ori)
    {
        cout<<solve(ori)<<'\n';
    }
}