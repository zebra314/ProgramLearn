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