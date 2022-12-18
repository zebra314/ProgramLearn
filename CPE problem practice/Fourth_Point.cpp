#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
        // 1 2 3 4 
        if(x2 == x4 and y2 == y4)
        {
            swap(x3,x4);
            swap(y3,y4);
        }
        else if(x1 == x3 and y1 == y3)
        {
            swap(x1,x2);
            swap(y1,y2);
        }
        else if(x1 == x4 and y1 == y4)
        {
            swap(x1,x2);
            swap(y1,y2);
            swap(x3,x4);
            swap(y3,y4);
        }
        cout<<setprecision(3)<<setiosflags(ios::fixed)<<x1+(x4-x3)<<" "<<y1+(y4-y3)<<'\n';
    }
}