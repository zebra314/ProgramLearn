/*
stringstream 分割字串 轉數字
algorithm 排序數字
ostringstream 合併數字成一個文字
map 以文字為索引 儲存數量
儲存的同時尋找最大值
遍歷 加總擁有最大值組合的人數(可能課程組合不同 但同時都是最大的人數 要加一起)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
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