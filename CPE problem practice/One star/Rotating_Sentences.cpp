#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    vector<string> txts;
    string intxt;
    int maxi = 0;
    while(getline(cin,intxt))
    {
        while(intxt.length()<maxi)
        {
            intxt+=" ";
        }
        maxi = max(int(intxt.length()),maxi);
        txts.push_back(intxt);
    } 

    for(int i = 0; i<maxi; i++) // 左到右
    {
        for(int j = txts.size()-1; j>=0; j--) // 下到上
        {
            if(txts[j][i])
                cout<<txts[j][i];
            else if (i != maxi -1) //如果沒東西 且不是最後一個 補空格
                cout<<" ";
        }
        if (i != maxi -1)
            cout<<'\n';
    }  
}