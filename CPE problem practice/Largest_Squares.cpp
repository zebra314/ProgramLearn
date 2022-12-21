#include<bits/stdc++.h>
using namespace std;
vector<string> squar;
int W, H;
bool is_squar(int y, int x, int radius){
    char center = squar[y][x];
    // cout<<center;
    int top = y - radius ; // 1 - 0 = 1
    int bottom = y + radius ; // 1 + 0 = 1
    int left = x - radius ; // 2 - 0 = 2
    int right = x + radius ; // 2 + 0 = 2
    if(bottom > H -1 || top < 0 || left <0 || right > W-1) return false;
    for(int i = top; i<= bottom; i++){
        for(int j = left; j<= right; j++){
            if(squar[i][j] != center) return false;
        }
    }
    return true;
}

int main() {
    int times, Q, x, y, radius,h;
    string data;
    cin>>times;
    while(times--) {
        squar.clear();
        cin>>H>>W>>Q;
        cout<<H<<" "<<W<<" "<<Q<<'\n';
        cin.get();
        h = H;
        while(h--) {
            getline(cin,data);
            squar.push_back(data);
        }
        while(Q--) {
            cin>>y>>x;
            radius = 0;
            while(is_squar(y, x, radius)){
                radius++;
            }
            radius --;
            cout<<radius*2+1<<'\n';
        }
    }
}