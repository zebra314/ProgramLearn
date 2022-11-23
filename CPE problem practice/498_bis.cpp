#include<bits/stdc++.h>
using namespace std;

int main()
{
    stringstream ss;
    long long int x, dig;
    long long int output = 0;
    string func;
    long long int  temp_num;
    vector<long long int>num;
    while(cin>>x)
    {
        ss.clear();
        ss.str("");
        num.clear();
        output = 0;
        cin.get(); // get the enter
        getline(cin,func);
        ss<<func;
        while(ss>>temp_num)
        {
            num.push_back(temp_num);
        }
        dig = num.size() - 1;
        for(int i = 0; i<num.size()-1; i++)
        {
            output += dig*pow(x,dig-1)*num[i];
            dig = dig - 1;
        }
        cout<<output<<'\n';
    }
}