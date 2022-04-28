# Uva solved problem records

## 481 - What Goes Up

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=422)
>[LIS,高等演算法整理](https://alan23273850.github.io/Online-Judge-Problems/algorithms/%E5%BA%8F%E5%88%97/2.-%E6%9C%80%E9%95%B7%E9%81%9E%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97/)
>[Binary Search (1)](https://medium.com/@lindingchi/binary-search-%E9%82%A3%E4%BA%9B%E8%97%8F%E5%9C%A8%E7%B4%B0%E7%AF%80%E8%A3%A1%E7%9A%84%E9%AD%94%E9%AC%BC-%E4%B8%80-%E5%9F%BA%E7%A4%8E%E4%BB%8B%E7%B4%B9-dd2cd804aee1)
>[Binary Search (2)](https://medium.com/appworks-school/binary-search-%E9%82%A3%E4%BA%9B%E8%97%8F%E5%9C%A8%E7%B4%B0%E7%AF%80%E8%A3%A1%E7%9A%84%E9%AD%94%E9%AC%BC-%E4%BA%8C-%E6%89%BE%E4%B8%8D%E5%88%B0%E6%80%8E%E9%BA%BC%E8%BE%A6-a308f5b9ce12)
>[find()函式](https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/)

### Code

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, i, j, l, r,n;
    vector<pair<int, int>> b; 
    vector<int> c;            
    stack<int>d;             
    while (cin >> a)          
    {
        b.push_back(make_pair(a, 1));
    }
    for (i = 0; i < b.size(); i++)
    {
        if (c.empty() or c.back() < b[i].first)
        {
            c.push_back(b[i].first);
            b[i].second = c.size();
        }
        else    
        {
            *lower_bound(c.begin(), c.end(), b[i].first) = b[i].first; 
            auto m = find(c.begin(), c.end(), b[i].first); 
            b[i].second = int(m - c.begin()) + 1; 
        }
    }
    n=c.size();
    for (i = b.size() - 1; i >= 0; i--)
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
```



 




