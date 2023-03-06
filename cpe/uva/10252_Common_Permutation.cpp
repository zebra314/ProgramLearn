//分別對兩個字串,以字母元素為索引,儲存數量
//比對兩個map,若有相同元素則匯入multiset
//同元素重複出現,則匯入多次
//遍歷multiset
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int>a,c;
    multiset<char>b;
    string i,j;
    int m;
    while(getline(cin,i),getline(cin,j))
    {
        m=0;
        a.clear();
        c.clear();
        b.clear();
        for(int l=0;l<i.length();l++)
        {
            a[i[l]]++;
        }
        for(int l=0;l<j.length();l++)
        {
            c[j[l]]++;
        }
        for(const auto &l:a)//l.first字母 l.second數量
        {
            if(c[l.first]>=1)
            {
                for(int i=1;i<=min(c[l.first],l.second);i++)
                {
                    b.insert(l.first);
                }
            }
        }
        for(const auto&l :b)
        {
            cout<<l;
        }
        cout<<"\n";
    }
}