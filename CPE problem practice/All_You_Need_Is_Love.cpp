#include<bits/stdc++.h>
using namespace std;

// 輾轉相除法 
int GCD(int a, int b)
{
    if(a<b) swap(a,b); // make a to be the bigger one // not necessary
    return a%b==0 ? b : GCD(b, a%b);
}

// bin to dec
int trans(string i) // 必須用string輸入, 再轉為int, int沒有支援到30位元, 以int輸入會爆掉
{
    int ans = 0;
    for(int j = i.length()-1, k = 0; j>=0; j--, k++)
        ans += int(i[j] - '0')*pow(2,k); 
    return ans;
}

int main()
{
    stringstream ss;
    int count = 1;
    int times;
    int a, b;
    string c, d;
    cin>>times;
    while(times--)
    {

        // a = stoi(c, nullptr, 2);
        // b = stoi(d, nullptr, 2);

        cin>>c>>d;
        a = trans(c);
        b = trans(d);

        cout<<"Pair #"<<count<<": ";
        count ++;
        if(GCD(a,b) == 1)
            cout<<"Love is not all you need!"<<'\n';
        else 
            cout<<"All you need is love!"<<'\n';
    }
}