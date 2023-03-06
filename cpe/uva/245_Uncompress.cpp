#include<bits/stdc++.h>
using namespace std;
vector<string> b;
string c,w;
int d=0;
int main()
{   
    while(getline(cin,c))
    {
        if(c =="0")break;
        c+='\n';
        for(int i=0;i<c.length();i++)
        {
            if(isalpha(c[i]))
            {
                w+=c[i];
            }
            else if(isdigit(c[i]))
            {
                d*=10;
                d+=int(c[i]-'0');
            }
            else //空格 標點符號
            {
                if(d!=0)
                {
                    cout<<b[d-1];
                    w=b[d-1];
                    b.erase(b.begin()+d-1);
                    b.insert(b.begin(),w);
                    w="";
                    d=0;
                }
                if(w!="")
                {
                    cout<<w; 
                    b.insert(b.begin(),w);
                    w="";
                }
                cout<<c[i];
            }
        }
    }
}