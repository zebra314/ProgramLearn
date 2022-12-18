#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    map<int,int> ans;
    string status;
// c: finger 2~4, 7~10
// d: finger 2~4, 7~9
// e: finger 2~4, 7, 8
// f: finger 2~4, 7
// g: finger 2~4
// a: finger 2, 3
// b: finger 2
// C: finger 3
// D: finger 1~4, 7~9
// E: finger 1~4, 7, 8
// F: finger 1~4, 7
// G: finger 1~4
// A: finger 1~3
// B: finger 1~2
// cdefgab
// 0 1 1 1 0 0 1 1 1 1
    string c = "0111001111";
    string d = "0111001110";
    string e = "0111001100";
    string f = "0111001000";
    string g = "0111000000";
    string a = "0110000000";
    string b = "0100000000";
    string C = "0010000000";
    string D = "1111001110";
    string E = "1111001100";
    string F = "1111001000";
    string G = "1111000000";
    string A = "1110000000";
    string B = "1100000000";
    map<char, string> ref;
    ref =  {{'c',c},
            {'d',d},
            {'e',e},
            {'f',f},
            {'g',g},
            {'a',a},
            {'b',b},
            {'C',C},
            {'D',D},
            {'E',E},
            {'F',F},
            {'G',G},
            {'A',A},
            {'B',B}};
    string song;
    cin>>times;
    cin.get();
    while(times--)
    {
        getline(cin,song);
        if(song.length() == 0)
        {
            cout<<"0 0 0 0 0 0 0 0 0 0\n";
            continue;
        } 
        ans.clear();
        status = "0000000000";
        for(int i = 0; i<= 9; i++)
            ans[i] = 0;
        for(int i = 0; i<song.length(); i++)
        {
            if(song[i] == song[i-1])continue;
            for(int j = 0;j<=9; j++)
            {
                if(ref[song[i]][j] == '1' and status[j] == '0')
                {
                    ans[j]++;
                    status[j] = '1';
                }
                if(ref[song[i]][j] == '0')
                    status[j] = '0';
                    
            }
        }
        for(const auto &ele:ans)
            cout<<ele.second<<" ";
        cout<<'\n';
    }
}