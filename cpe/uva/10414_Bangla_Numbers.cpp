#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
int main()
{
    queue <char> c;
    stringstream ss;
    string a;
    char b;
    int i=1;
    while(getline(cin,a))
    {
        cout<<"   "<<i<<"."<<" ";
        ss.str("");
        ss.clear();
        ss<<a;
        while(ss>>b)
        {
            c.push(b);
        }
        while(c.size()!=0)
        {
            if(c.front()=='0')
            {
                c.pop();
                continue;
            }
            else if(c.size()%7==0 or c.size()%7==5 or c.size()%7==2 )
            {
                cout<<c.front();
                c.pop();
            }
            else if(c.size()%7==6)
            {
                cout<<c.front()<<" lakh ";
                c.pop();
            }
            else if(c.size()%7==4)
            {
                cout<<c.front()<<" hajar ";
                c.pop();
            }
            else if(c.size()%7==3)
            {
                cout<<c.front()<<" shata ";
                c.pop();
            }
            else if(c.size()%7==1 and c.size()!=1)
            {
                cout<<c.front()<<" kuti ";
                c.pop();
            }
            else if (c.size()==1)
            {
                cout<<c.front();
                c.pop();
            }
        }
        i++;
        cout<<"\n";
    }
}