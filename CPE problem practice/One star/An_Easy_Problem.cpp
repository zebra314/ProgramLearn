#include<bits/stdc++.h>
using namespace std;
map<char,unsigned long long int>dig;
unsigned long long int trans(string num, unsigned long long int base)
{
    unsigned long long int ans = 0;
    for(int i = num.length()-1; i>=0; i--)
    {
        // cout<<dig[num[i]]<<" * ("<<base<<"^"<<num.length()-1-i<<'\n';
        ans += dig[num[i]]*pow(base,num.length()-1-i);
    }
    return ans;
}

int main()
{
    string in;
    string cha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unsigned long long int j;
    bool a;
    for(unsigned long long int i = 0;i<cha.length();i++)
    {
        dig[cha[i]] = i;
    }
    while(cin>>in)
    {  
        a = false;
        j=0; 
        for(unsigned long long int i = 0;i<in.length();i++)
        {
            j = max(j,dig[in[i]]);
        }
        j++;
        // cout<<trans(in,j)<<'\n';
        for(long long int i = j;i<=62;i++)
        {
            if(trans(in,i)%(i-1) == 0)
            {
                cout<<i<<'\n';
                a = true;
                break;
            }
        }
        if(a == false )
        {
            cout<<"such number is impossible!"<<'\n';
        }   
    }
}