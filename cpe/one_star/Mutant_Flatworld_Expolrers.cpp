#include<bits/stdc++.h>
using namespace std;
map<int, char> dir; // 0123 -> NESW
map<char, int> re_dir; // NESW -> 0123
set<pair<int,int>> ignor;
void move(int x_max, int y_max, int x, int y, char direction, string action)
{
    //  dir 0123 -> NESW
    //  re_dir NESW -> 0123

    int current_dir = re_dir[direction];
    int current_x = x;
    int current_y = y;
    pair<int, int> lost_cor;
    pair<int, int> curr_cor;

    // 走 -> 檢查是否掉落 -> 
    // 機器人是檢查掉落前的最後一個點
    // 若之前有機器人往這一個點的任何一個方向掉落，則下一次會避開
    // 在邊上掉落只有一個方向，但角落的掉落有兩個方向
    // 如果用掉落之後的點來記憶，在角落會有掉第二次的情況發生
    for(int i = 0;i<action.length(); i++) // go through the commands
    {
        switch(action[i])
        {
            case 'L':
                current_dir--;
                if(current_dir == -1)
                    current_dir = 3;
                break;
            case 'R':
                current_dir++;
                if(current_dir == 4)
                    current_dir = 0;
                break;
            case 'F': //according to the current_dir
                if(current_dir == 0) //N
                    current_y++;
                else if(current_dir == 1) //E
                    current_x++;
                else if(current_dir == 2) //S
                    current_y--;
                else if(current_dir == 3) //W
                    current_x--;
                
                 // 發生掉落
                if(current_x>x_max || current_x<0 || current_y>y_max || current_y<0)
                {
                    // 回到掉落之前的點
                    if(current_dir == 0) //N
                        current_y--;
                    else if(current_dir == 1) //E
                        current_x--;
                    else if(current_dir == 2) //S
                        current_y++;
                    else if(current_dir == 3) //W
                        current_x++;

                    // 檢查是否有紀錄
                    curr_cor = make_pair(current_x ,current_y);
                    if(ignor.count(curr_cor)>0)
                        continue;
                        
                    // 無紀錄
                    lost_cor = make_pair(current_x, current_y);
                    ignor.insert(lost_cor);

                    cout<<current_x<<" "<<current_y<<" "<<dir[current_dir]<<" "<<"LOST"<<'\n';
                    return;
                }
                break;
        }
    }
    cout<<current_x<<" "<<current_y<<" "<<dir[current_dir]<<'\n';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x_max, y_max;
    string init, action;
    int x, y;
    char dire;
    dir[0] = 'N'; dir[1] = 'E'; dir[2] = 'S'; dir[3] = 'W';
    re_dir['N'] = 0; re_dir['E'] = 1; re_dir['S'] = 2; re_dir['W'] = 3;
    cin>>x_max>>y_max;
    while(cin>>x>>y>>dire>>action)
    {
        move(x_max, y_max, x, y, dire, action);
    }
} 