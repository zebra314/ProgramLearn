#include<bits/stdc++.h>
using namespace std;

int GCD(int i, int j)
{
    if(i<j)swap(i,j); // make i to be the bigger one.
    return (i%j == 0) ? j:GCD(i%j,j);
}

int main()
{
    int num;
    int ans;
    map<int, int> G_table;
    // 觀察 G[i] 和 G[i-1] 的關係 先建表
    for(int i = 1; i<2; i++)
    {
        for(int j = i+1; j<=2; j++)
            ans+=GCD(i,j);
    }
    G_table[2] = ans;

    // 4
    // 1 (2 3 4 
    // 2 (3 4 
    // 3 (4

    // 5
    // 1 (2 3 4 5
    // 2 (3 4 5
    // 3 (4 5
    // 4 (5

    for(int i = 3; i<501; i++)
    {
        int add = 0;
        for(int k = 1; k<i; k++)
        {
            add+=GCD(i,k);
        }
        G_table[i] += G_table[i-1]+add;
    }

    while(cin>>num)
    {
        if(num == 0)break;
        // ans = 0;
        // for(int i = 1; i<num; i++)
        // {
        //     for(int j = i+1; j<=num; j++)
        //         ans+=GCD(i,j);
        // }
        // cout<<ans<<'\n';
        cout<<G_table[num]<<'\n';
    }
}