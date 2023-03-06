#include<bits/stdc++.h>
using namespace std;


int main()
{
    bool ans;
    long long int time = 1;
    int times;
    long long int N,num;
    long long int stage;
    cin>>times;
    stack<long long int>nums;
    getchar();
    while(times --)
    {
        ans = true;
        while(!nums.empty())
        {
            nums.pop();
        }
        getchar();
        getchar();
        getchar();
        getchar();
        cin>>N;
        if(N%2 == 0)
        {
            stage = N*N/2;
            while(stage--)
            {
                cin>>num;
                if(num<0)
                    ans = false;
                nums.push(num);
            }
            stage = N*N/2;
            while(stage--)
            {
                cin>>num;
                if(num<0)
                    ans = false;
                if(num == nums.top())
                    nums.pop();
            }
        }
        else if(N%2 == 1)
        {
            stage = (N*N-1)/2;
            while(stage--)
            {
                cin>>num;
                if(num<0)
                    ans = false;
                nums.push(num);
            }
            cin>>num;
            if(num<0)
                ans = false;
            stage = (N*N-1)/2;
            while(stage--)
            {
                cin>>num;
                if(num<0)
                    ans = false;
                if(num == nums.top())
                    nums.pop();
            }
        }
        cout<<"Test #"<<time<<": ";
        time++;
        if(nums.empty() and ans == true)
            cout<<"Symmetric."<<'\n';
        else 
            cout<<"Non-symmetric."<<'\n';
    }
}