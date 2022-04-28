#include <bits/stdc++.h>
using namespace std;
char f1(stack<char> &a) //取得倒數第二個(d.push前的最後一個)
{
    char b, c;
    b = a.top();
    a.pop();
    c = a.top();
    a.push(b);
    return c;
}
char f2(stack<char> &a) //取得倒數第三個(d.push前的倒數第二個)
{
    char b, c, d;
    b = a.top();
    a.pop();
    c = a.top();
    a.pop();
    d = a.top();
    a.push(c);
    a.push(b);
    return d;
}
int main()
{
    stringstream s;
    int i, j, k; // k總組數
    char a, b, c;
    string f;
    vector<char> d;
    stack<char> e;
    cin >> i;
    getchar();
    while (i--)
    {
        b='0', c='0';
        k = 0;
        d.clear();
        while (!e.empty())
        {
            e.pop();
        }
        s.clear();
        s.str("");
        getline(cin, f);
        s << f;
        while (s >> a)
        {
            d.push_back(a);
            e.push(a);
        }
        for (j = 0; j < d.size(); j++)
        {
            e.push(d[j]);
            if (e.size() >= 2)
            {
                b = f1(e);
                if (e.size() >= 3)
                    c = f2(e);
            }
            if (b == d[j] )
            {
                e.pop();
                e.pop();
                j++;
                k++; //至少有一組
                while (!e.empty())
                {
                    if (e.top() == d[j])
                    {
                        e.pop();
                        j++;
                    }
                    else
                    {
                        k += e.size();
                        while (!e.empty())
                        {
                            e.pop();
                        }
                        break;
                    }
                }
            }
            else if (c == a)
            {
                e.pop();
                e.pop();
                e.pop();
                j++;
                k++;
                while(!e.empty())
                {
                    if(e.top() == d[j])
                    {
                        e.pop();
                        j++;
                    }
                    else
                    {
                        k += e.size();
                        while (!e.empty())
                        {
                            e.pop();
                        }
                        break;
                    }
                }
            }
        }
        cout<<k<<"\n";
    }
}