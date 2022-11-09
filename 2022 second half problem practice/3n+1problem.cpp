// https://zerojudge.tw/ShowProblem?problemid=c039
#include<bits/stdc++.h>

using namespace std;

map<int,int> tab;
int tim = 1;

int how (int i ) //一直遞回到i變成1, 所以只會輸出1
{
    if(i == 1) 
    {
        return 1;
    }
    else if (i %2 == 0) 
    {
        i= i/2;
    }
    else 
    {
        i= i*3+1;
    }
    tim ++ ;
    return how(i);
}

int tims(int i) //一直遞回到i變成1, 再一層層加1加出來, 所以最後會回傳次數
{
    if (i== 1)
    {
        return 1;
    }
    else if(i%2==0)
    {
        return tims(i/2) +1;
    }else
    {
        return tims(i*3+1)+1;
    }
}

int main()
{
    int a;
    while(cin>>a)
    {
        cout<<tims(a)<<"\n";
    }
}