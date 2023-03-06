#include <bits/stdc++.h>
using namespace std;
stringstream s;
int trans(vector<char> &a)
{
    s.str("");
    s.clear();
    int b;
    for (const auto &i : a)
    {
        s << i;
    }
    s >> b;
    return b;
}
void plu(int top,vector<int>&a)
{
    int i;
    vector<int>b=a;
    a.clear();
    a.push_back(top);
    for(i=0;i<b.size();i++)
    {
        a.push_back(a[i]+b[i]);
    }
    b.clear();
}
void tim(int top,vector<int>&a)
{
    int i;
    vector<int>b=a;
    a.clear();
    a.push_back(top*b[0]);
    for(i=0;i<b.size()-1;i++)
    {
        a.push_back(a[i]*b[i+1]);
    }
    b.clear();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    int b, i, k, l, m; // k紀錄要計算幾次數列 l暫存
    vector<char> c;
    vector<int> f;
    stack<int> d;
    stack<char> e;
    while (cin >> a >> b)
    {
        i=0;
        k = 0;
        while(!d.empty())
            d.pop();
        while(!e.empty())
            e.pop();
        c.clear();
        f.clear();
        while (a[i] == '[') //讀取數字和運算子
        {
            k++;
            i++;
            while (a[i] != '+' and a[i] != '*' and a[i] != ']')
            {
                c.push_back(a[i]);
                i++;
            } // i停在+ or * 上
            d.push(trans(c));
            c.clear();
            if (a[i] == ']')
                break;
            e.push(a[i]); // push + *
            i++;
        }
        l = d.top(); //第一組[] 另外處理
        d.pop();
        if (e.top() == '+')
        {
            f.push_back(d.top());
            for (m = 1; m < b; m++)
            {
                f.push_back(f[m - 1] +  l);
            }
        }
        else
        {
            f.push_back(d.top()*l);
            for (m = 1; m < b; m++)
            {
                f.push_back(f[m - 1] * l);
            }
        }
        d.pop();
        e.pop();
        k -= 2;
        while (k--) //剩餘的[]
        {
            if (e.top() == '+')
            {
                plu(d.top(),f);
            }
            else
            {
                tim(d.top(),f);
            }
            e.pop();
            d.pop();
        }
        cout<<f[0];
        for(m=1;m<b;m++)
        {
            cout<<" "<<f[m];
        }
        cout<<"\n";
    }
}
