#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &map)
{
    for(int i = 0; i<map.size(); i++)
    {
        for(int j = 0; j<map[i].size(); j++)
        {
            if(map[i][j] == '0')
                return;
            if(map[i][j] == '.')
            {
                map[i][j] = '0';

                if(j<map[i].size()-1)
                {
                    if(map[i][j+1] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                }
                if(i<map.size()-2) //多一個用來測最後一行的<vector>row 導致<vector>map長度多一 原本減一變成減二
                {
                    if(map[i+1][j] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                    if(j<map[i].size()-1)
                    {
                        if(map[i+1][j+1] == '*')
                            map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                    }
                }
                if(j>0)
                {
                    if(i<map.size()-2)
                    {
                        if(map[i+1][j-1] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                    }
                    if(map[i][j-1] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                }
                if(i>0)
                {
                    if(map[i-1][j] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                    if(j<map[i].size()-1)
                    {
                        if(map[i-1][j+1] == '*')
                            map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                    }
                }
                if(i>0 and j>0)
                {
                    if(map[i-1][j-1] == '*')
                        map[i][j] = char(int(map[i][j] -'0')+1+int('0'));
                }
            }
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    vector<vector<char>> map;
    vector<char> row;
    int max_x, max_y, i;
    char point;
    int times = 1;
    while(cin>>max_x>>max_y)
    {
        if(max_x == 0 and max_y == 0)
            break;
        map.clear();
        while(max_x--)
        {
            row.clear();
            i = max_y;
            while(i--)
            {
                cin>>point;
                row.push_back(point);
            }
            map.push_back(row);
            row.clear();
        }
        row.push_back('0');
        map.push_back(row);
        cout<<"Field #"<<times++<<":"<<'\n';
        solve(map);
        cout<<'\n';
    }
}