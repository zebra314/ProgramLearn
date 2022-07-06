#include<bits/stdc++.h>
using namespace std;
//數據格式 
//人的編號 題號 時間點 成績
//創建一個map  紀錄懲罰 答錯次數 
int am;//amount
string a,b;
string c; //the person
int flag;
int cu=0;//current time
map <string ,int > ti; //fail times use the number of  problem as the key
map <string ,int > sol; //solved use the person as key
map <string ,int > fiti; //防呆 use the number of problem as the key
map <string ,int > fipe; //total penalty use the person as the key
int main()
{
    cin>>am;
    getchar();
    getchar();
    while(am--)
    {
        ti.clear();
        sol.clear();
        fiti.clear();
        fipe.clear(); 
        while(getline(cin,a)) //取得每組成績
        {
            if(a=="")
            {
                break;
            }
            flag=0;
            cu=0;
            b="";
            c="";
            for(int i=0;i<a.length();i++)
            {
                
                if(a[i]==' ')
                {
                    flag++;
                }
                if (flag==0)
                {
                    c+=a[i];
                }
                if(flag<2)
                {
                    b+=a[i];
                }
                else if(flag>=2 and flag<3 and a[i]!=' ')
                {
                    cu=cu*10+int(a[i]-'0');
                }
            }
            if(sol[c]==0)
            {
                sol[c]=0;
            }
            if(a.back() == 'I' and fiti[b]==0 )
            {
                ti[b]+=1;
            }
            else if(a.back() == 'C' and fiti[b]==0)
            {
                fiti[b]=ti[b]*20 + cu ; 
                fipe[c]+=fiti[b];
                sol[c]+=1; //總共解了多少題
            }
        }
        for(const auto &m : sol)
        {
            cout<<m.first<<" "<<m.second<< " " <<fipe[m.first]<<"\n";
        }
        if (am!= 0)cout<<"\n";
    }
}