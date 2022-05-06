#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a{1,2,3,4,5,6,7,8};
    vector<int>b = a;
    a.clear();
    for(const auto&i:b)cout<<i;
}