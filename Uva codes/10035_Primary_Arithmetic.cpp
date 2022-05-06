/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int i,j,k,l=0;
    while(cin>>a>>b)
    {
        l=0;
        k=0;
        if(a=="0" and b=="0")break;
        i=a.length()-1;
        j=b.length()-1;
        while(1)
        {
            if(j<0 and i<0 )break;
            if(min(i,j)<0 and max(i,j)>=0 and l==1)
            {
                if(i>j)
                {
                    if(int(a[i]-'0')+1>=10)k++;
                    else l=0;
                }
                else
                {
                    if(int(b[j]-'0')+1>=10)k++;
                    else l=0;
                }
            }
            else if(i>=0 and j>=0)
            {
                if(int(a[i]-'0')+int(b[j]-'0')+l>=10)
                {
                    k++;
                    l=1;
                }
                else
                {
                    l=0;
                }
            }else
                break;
            j--;
            i--;
        }
        if(k==0)cout<<"No carry operation."<<"\n";
        else if (k==1)cout<<"1 carry operation."<<"\n";
        else cout<<k<<" carry operations."<<"\n";
    }
}*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, i, j;
    while (cin >> a >> b)
    {
        i = 0;
        j = 0;
        while (a >= 0 or b >= 0)
        {
            if (a == 0 and b == 0)
                break;
            else if (a % 10 + b % 10 + i >= 10)
            {
                i = 1;
                j++;
            }
            else
            {
                i = 0;
            }
            a = a / 10;
            b = b / 10;
        }
        if (j == 0)
            cout << "No carry operation."
                 << "\n";
        else if (j == 1)
            cout << "1 carry operation."
                 << "\n";
        else
            cout << j << " carry operations."
                 << "\n";
    }
}