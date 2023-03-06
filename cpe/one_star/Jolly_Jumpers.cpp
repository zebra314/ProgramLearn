#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> div;
    int num, temp;
    int times, const_times;
    while(cin>>times)
    {
        const_times = times;
        cin>>num;
        times--;
        while(times--)
        {
            temp = num;
            cin>>num;
            div.insert(abs(num - temp));
        }
        if(div.size() == const_times -1)
            cout<<"Jolly"<<'\n';
        else 
            cout<<"Not jolly"<<'\n';

        div.clear();
    }
}