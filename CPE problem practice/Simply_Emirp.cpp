#include<bits/stdc++.h>
using namespace std;

string reverse(string num)
{
    string out;
    for(int i = num.length()-1; i>=0; i--)
        out+=num[i];
    return out;
}

bool solve(string num)
{
    int i = 0;
    for(int j = num.length()-1,k=0; j>=0; j--,k++)
        i += int(num[j]-'0')*pow(10,k);
    for(int j = 2; j<=pow(i,0.5); j++)
    {
        if(i%j == 0)
            return false;
    }
    return true;
}

int main()
{
    string num;
    while(cin>>num)
    {
        if(solve(num) == false)
            cout<<num<<" is not prime.\n";
        else if(solve(num) == true and solve(reverse(num)) == true and num!=reverse(num))
            cout<<num<<" is emirp.\n";
        else 
            cout<<num<<" is prime.\n";
    }
}