#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int b,i;
    vector<int> a,d; 
    a.push_back(0); 
    a.push_back(1); 
    for(i=0;i<20;i++){a.push_back(a[i]+a[i+1]);}
    cin>>b;
    while(cin>>b)
    {
        cout<<b<<" = ";
        d.clear();
        while(b>a.back()){a.push_back(a.back()+a[a.size()-2]);}
        for(i=a.size()-1;i>=0 and b<a[i] ;i--){;}
        for(i;i>1;i--)
        {
            if(b<a[i] or b==0)
                d.push_back(0);
            else if (b>=a[i])
            {
                b-=a[i];
                d.push_back(1);
            }
        }
        for(i=0;i<d.size();i++){cout<<d[i];}
        cout<<" (fib)"<<"\n";
    }
}