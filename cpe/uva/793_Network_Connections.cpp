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