#include<bits/stdc++.h>
using namespace std;

int main()
{
    int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string week[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
    int times = 0;
    int inmonth, inday;
    int dis;
    // 1/6 Thrusday
    // 12/31 Friday

    cin>>times;
    while(times --)
    {
        dis = 0;
        cin>>inmonth>>inday;
        for(int i = 0;i<inmonth-1;i++)
        {
            dis +=month[i];
        }
        dis +=inday;
        cout<<week[dis%7]<<'\n';
    }
}