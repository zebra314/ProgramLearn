# Uva solved problem records

&nbsp;

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
}
```

&nbsp;

## 11286 - Conformity

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2261)

### Steps

1. stringstream 分割字串 轉數字
2. algorithm 排序數字
3. ostringstream 合併數字成一個文字
4. map 以文字為索引 儲存數量
5. 儲存的同時尋找最大值
6. 遍歷 加總擁有最大值組合的人數
(可能課程組合不同 但同時都是最大的人數 要加一起)

### Code

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stringstream s;
    ostringstream o;
    vector<int> b;
    map<string, int> q;
    int i, j, a, e, p, m, r;
    string c;
    while (cin >> i)
    {
        q.clear();
        r = 0;
        m = 1;
        p = i;
        getchar();
        if (i == 0)
            break;
        for (i; i > 0; i--)
        {
            getline(cin, c);
            b.clear();
            s.str("");
            s.clear();
            o.clear();
            o.str("");
            s << c;
            while (s >> a)
            {
                b.push_back(a);
            }
            sort(b.begin(), b.end());
            for (j = 0; j < b.size(); j++)
            {
                o << b[j];
            }
            q[o.str()]++;
            if (q[o.str()] > m)
            {
                m = q[o.str()];
            }
        }
        for (const auto &n : q)
        {
            if (n.second == m)
            {
                r += m;
            }
        }
        cout << r << "\n";
    }
}
```

&nbsp;

## 10035 - Primary Arithmetic

>2022/5/6

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=976)

### Code - 1

```c++
//判斷式多 不簡潔
#include<bits/stdc++.h>
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
}
```

&nbsp;

### Code - 2

```c++
//Better solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j;
    while(cin>>a>>b)
    {
        i=0;
        j=0;
        while(a>=0 or b>=0)
        {
            if(a==0 and b==0)break;
            else if(a %10+b%10+i>=10)
            {
                i=1;
                j++;
            }
            else
            {
                i=0;
            }
            a=a/10;
            b=b/10;
        }
        if(j==0)cout<<"No carry operation."<<"\n";
        else if (j==1)cout<<"1 carry operation."<<"\n";
        else cout<<j<<" carry operations."<<"\n";
    }
}
```

&nbsp;

## 10252 - Common Permutation

>2022/5/6

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1193)

### Steps

1. 分別對兩個字串,以字母元素為索引,儲存數量
2. 比對兩個map,若有相同元素則匯入multiset
3. 同元素重複出現,則匯入多次
4. 遍歷multiset

### Code

```c++
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
```

&nbsp;

## 793 - Network Connections

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=734)

### Code

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, map<int, int>> e;
    vector<pair<int, int>> h;
    int a, b, g, d, m;
    char c;
    cin >> a;
    while (a--)
    {
        m = 0;
        h.clear();
        e.clear();
        cin >> b;
        getchar();
        while (cin.get(c))
        {
            if (c == '\n')
            {
                break;
            }
            else if (c == 'c')
            {
                cin >> g >> d;
                getchar();
                e[g][d] = 1;
                e[d][g] = 1;
            }
            else if (c == 'q')
            {
                cin >> g >> d;
                getchar();
                h.push_back(make_pair(g, d));
            }
        }
        for (const auto n : e)
        {
            e[n.first][n.first] = 1;
        }
        for (const auto t : h)
        {
            for (const auto n : e[t.first])
            {
                if (e[t.second][n.first] == 1)
                {
                    m++;
                    break;
                }
            }
        }
        cout << m << "," << h.size() - m << "\n\n";
    }
}
```

&nbsp;

## 245 - Uncompress

>2022/6/19

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=181)

### Code

```c++
#include<bits/stdc++.h>
using namespace std;
vector<string> b;
string c,w;
int d=0;
int main()
{   
    while(getline(cin,c))
    {
        if(c =="0")break;
        c+='\n';
        for(int i=0;i<c.length();i++)
        {
            if(isalpha(c[i]))
            {
                w+=c[i];
            }
            else if(isdigit(c[i]))
            {
                d*=10; //進一位
                d+=int(c[i]-'0'); //新增一位
            }
            else //空格 標點符號
            {
                //判斷前一個是數字or單字
                if(d!=0)
                {
                    //是數字 讀取vector裡面的單字
                    cout<<b[d-1];
                    w=b[d-1];
                    b.erase(b.begin()+d-1);
                    b.insert(b.begin(),w);
                    w="";
                    d=0;
                }
                if(w!="")
                {
                    //是單字 新增到vector裡面
                    cout<<w; 
                    b.insert(b.begin(),w);
                    w="";
                }
                cout<<c[i];
            }
        }
    }
}
```

&nbsp;

## 10242 - Fourth Point

>2022/7/1

### Websites

>[online judge 題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1183)

### Steps

1. 輸入兩組點 , 共八個座標 , 兩組中各有一個相同的座標 (因為是兩條相鄰的邊)
2. 只有四種排列方式 用判斷式與```swap()``` 函式 , 將數據整理成同一種
3. 利用向量概念求出第個點
4. ```cout << fixed << setprecision(3)<<``` , 控制輸出三位小數

### Warning 

+ 要用```double``` , ```float``` 不夠精 , 會有四捨五入的問題

### Code

```c++
#include <bits/stdc++.h>
using namespace std;
vector<double> po; // points
string i;
double j;
double nex, ney;
stringstream ss;
int main()
{
    while (getline(cin, i))
    {
        ss.str("");
        ss.clear();
        ss << i;
        while (ss >> j)
        {
            po.push_back(j);
        }
        if (po[0] == po[4] and po[1] == po[5])
        {
            swap(po[0], po[2]);
            swap(po[1], po[3]);
        }
        else if (po[2] == po[6] and po[3] == po[7])
        {
            swap(po[4], po[6]);
            swap(po[5], po[7]);
        }
        else if (po[0] == po[6] and po[1] == po[7])
        {
            swap(po[0], po[2]);
            swap(po[1], po[3]);
            swap(po[4], po[6]);
            swap(po[5], po[7]);
        }
        nex = po[6] + po[0] - po[2];
        ney = po[7] + po[1] - po[3];
        cout << fixed << setprecision(3) << nex << " " << ney << "\n";
        po.clear();
    }
}

```

&nbsp;

## Problem

>Date

### Websites

>[online judge 題目連結]()

### Code

```c++

```

&nbsp;

## Problem

>Date

### Websites

>[online judge 題目連結]()

### Code

```c++

```

&nbsp;

## Problem

>Date

### Websites

>[online judge 題目連結]()

### Code

```c++

```

&nbsp;

## Problem

>Date

### Websites

>[online judge 題目連結]()

### Code

```c++

```

&nbsp;

## Problem

>Date

### Websites

>[online judge 題目連結]()

### Code

```c++

```

&nbsp;
