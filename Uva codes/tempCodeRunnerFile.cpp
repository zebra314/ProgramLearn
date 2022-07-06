//find the center
//compare two sides
//if can reach the botton fill the incompleted side
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    int b,i,j;
    while(getline(cin,a))
    {
        if(a.length()==1)
        {
            cout<<a<<"\n";
            continue;
        }
        for(i=(a.length()/2)-1;i<a.length();i++)
        { 
            if(a[i-1]==a[i])
            {
                j=0;
                while(a[i-j-1]==a[i+j] and i-j-1>=0 and i+j<a.length())
                {
                    j++;
                }
                j--;
                if(i+j==a.length()-1) 
                {
                    for(j=0;j<i;j++)
                    {
                        cout<<a[j];
                    }
                    for(j=i-1;j>=0;j--)
                    {
                        cout<<a[j];
                    }
                    cout<<"\n";
                    break;
                }
            }
            else if(a[i-1]==a[i+1])//奇數
            {
                j=1;
                while(a[i-j]==a[i+j] and i-j>=0 and i+j<a.length())
                {
                    j++;
                }
                j--;
                if(i+j == a.length()-1)//有辦法配到底
                {
                    //補齊 輸出
                    for(j=0;j<=i;j++) 
                    {
                        cout<<a[j];
                    }
                    for(j=i-1;j>=0;j--)
                    {
                        cout<<a[j];
                    }
                    cout<<"\n";
                    break;
                }
            }
            else if(i==a.length()-1)
            {
                for(i=0;i<a.length();i++)
                {
                    cout<<a[i];
                }
                for(i-=2;i>=0;i--)
                {
                    cout<<a[i];
                }
                cout<<"\n";
                break;
            }
        }
    }
}