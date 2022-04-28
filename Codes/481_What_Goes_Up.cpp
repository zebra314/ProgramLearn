//LIS,DP,Binary search
//lower_bound, find(), stack, 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, i, j, l, r,n;
    vector<pair<int, int>> b; //總序列 <b[n],以b[n]結尾的LIS長度>
    vector<int> c;            //第n個為,長度為n+1,以最小c[n]結尾的LIS長度
    stack<int>d;              //由後往前蒐集,蒐集完後,從最後蒐集到的開始輸出
    while (cin >> a)          //輸入
    {
        b.push_back(make_pair(a, 1));
    }
    for (i = 0; i < b.size(); i++)
    {
        if (c.empty() or c.back() < b[i].first) //b[n]比c.back()大,就把b[n] push_back進去c
        {
            c.push_back(b[i].first);
            b[i].second = c.size();
        }
        else    //b[n]比c.back小,就在c中往前找到最後一個不比自己小的數字並取代掉,此位置可表達以b[n]結尾的LIS長度
        {
            *lower_bound(c.begin(), c.end(), b[i].first) = b[i].first; //lower_bound會返回該數值,加一個*,指向其儲存位址
            auto m = find(c.begin(), c.end(), b[i].first); //取得在vector中的位置
            b[i].second = int(m - c.begin()) + 1;  //第一個順序上為0,要加一(表實際長度)
        }
    }
    n=c.size();
    for (i = b.size() - 1; i >= 0; i--) //由後往前蒐集
    {
        if(b[i].second==n)
        {
            d.push(b[i].first);
            n--;
        }
    }
    cout << c.size() << "\n"
         << "-"
         << "\n";
    while(!d.empty())
    {
        cout<<d.top()<<"\n";
        d.pop();
    }
    /*DP+Greedy+Binary search O(nlogn) 只能求長度 元素要另外找
    int a,d,i;
    vector<long int>b,c;
    while(cin>>a){b.push_back(a);}
    for(i=1;i<b.size();i++)
    {
        if(c.empty() or b[i]>c.back())  c.push_back(b[i]);      //置入
        else {  *lower_bound(c.begin(),c.end(),b[i])=b[i];    } //取代
    }
    cout<<c.size()<<"\n"<<"-"<<"\n";*/

    /*時間複雜度 O(n^2)
    int i, j, k;
    vector<pair<int, int>> a;
    map<int, int> b;
    while (cin >> k)
    {
        a.push_back(make_pair(k, 1));
        for (i = 0; i < a.size(); i++)
        {
            for (j = 0; j <= i; j++)
            {
                if (a[i] > a[j])
                {
                    a[i].second = max(a[i].second, a[j].second + 1);
                }
            }
            b[a[i].second] = a[i].first;
        }
    }
    cout << b.size() << "\n"
         << "-"
         << "\n";
    for (auto l : b)
    {
        cout << l.second << "\n";
    }*/
}


