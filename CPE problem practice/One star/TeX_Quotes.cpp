#include<bits/stdc++.h>
using namespace std;

int main()
{
    string intxt;
    int times = 0;
    while(getline(cin, intxt))
    {
        for(const auto ele : intxt)
        {
            if(ele == '"')
            {
                times++;
                if(times%2 == 1)
                {
                    cout<<"``";
                }
                else // times%2 == 0
                {
                    cout<<"''";
                }
            }
            else
            {
                cout<<ele;
            }
        }
        cout<<'\n';
    }   
}