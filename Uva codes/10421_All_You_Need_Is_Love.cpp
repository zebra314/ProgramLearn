//轉十進位 輾轉相除法
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int i, j = 1,b,c;
    string a;
    cin >> i;
    while (i--)
    {
        b=0;c=0;
        cin>>a;
        for(int i=0; i<a.length();i++)
        {
            if(a[i]=='1')
                b+=pow(2,a.length()-i-1);
        }
        cin>>a;
        for(int i=0; i<a.length();i++)
        {
            if(a[i]=='1')
                c+=pow(2,a.length()-i-1);
        }
        while(b!=0 and c!=0)
        {
            if(b>=c)
                b=b%c;
            else
                c=c%b;
        }
        if(max(b,c)!=1)
            cout<<"Pair #"<<j<<": All you need is love!"<<"\n";
        else    
            cout<<"Pair #"<<j<<": Love is not all you need!"<<"\n";
        j++;  
    }
}