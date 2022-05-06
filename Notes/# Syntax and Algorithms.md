# Syntax

## ```set``` , ```multiset```

1. STL容器
2. ```.insert()```插入元素
3. ```set```會自動消除重複元素, ```multiset```會保留
4. 元素插入後會自動排序
5. ```.clear()```初始化
6. ```.earse()```刪除指定元素
7. ```.count()```判斷元素是否存在,回傳 0 or 1
8. ```.find()```也是用來判斷元素是存在,但回傳的是指向其儲存位址的指標

## ```lower_bound()``` ,  ```upper_bound()```

1. ```lower_bound(``` _.begin()_ ```,``` _.end()_ ```,``` _value_ ```)```
2. 返回數值  
3. Binary Search
4. ```*lower_bound()``` 指向該數值的儲存位置
5. 可用來取代數值

## ```find()```

1. 檢查, 搜尋位置
2. 返回位址
3. Code:

```c++
 auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {
        // calculating the index
        // of K
        int index = it - v.begin();
        cout << index << endl;
    }
    else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
```

## ```.end()```  ```.back()```  ```.front()```  ```.begin()``` 差別

```c++
v: [ 1 | 2 | 3 | 4 | ... | 999 ]
     🡑                      🡑     🡑
   front()                back() end()
     🡑
   begin()
```

# Algorithms

## LIS基礎演算法

1. 時間複雜度:O(n<sup>2</sup>)
2. Code:

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
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
    }
}
```

## LIS進階演算法(只求長度)

1. 時間複雜度:O(n*log*n)
2. DP, Greedy, Binary search
3. Code:

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,d,i;
    vector<long int>b,c;
    while(cin>>a){b.push_back(a);}
    for(i=1;i<b.size();i++)
    {
        if(c.empty() or b[i]>c.back())  c.push_back(b[i]);      //置入
        else {  *lower_bound(c.begin(),c.end(),b[i])=b[i];    } //取代
    }
    cout<<c.size()<<"\n"<<"-"<<"\n";
}
```

## Binary Search

```c++
int binary_search(vector<int>v,int target) //find the position 
{
    int left=0;
    int right=v.size()-1;
    while(right=>left)
    {
        int mid=(right+left)/2;
        if(target==v[mid])  return left; //最後的解 left下界 right上界
        if(target>v[mid])   left=mid+1;
        else    // target<v[mid] 
            right=mid-1;
    }
    return -1;//fail
}
```

## 輾轉相除法

1. 求最大公因數

```c++
    while(b!=0 and c!=0)
    {
        if(b>=c)
            b=b%c;
        else
            c=c%b;
    }
    //最大公因數為max(b,c)
```
