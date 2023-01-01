#include<bits/stdc++.h>
using namespace std;

bool find_prime(int num){
    for(int i =2; i<=pow(num,0.5); i++){
        if(num%i == 0) return false;
    }
    return true;
}

int main(){
    vector<int> nums;
    set<int> ans;
    int times, num;
    cin>>times;
    while(times--){
        cin>>num;
        nums.push_back(num);
    }
    for(const auto &ele :nums){
        for(int i = 2; i <= ele; i++){
            if(find_prime(i) == true and (ele%i == 0))
                ans.insert(i);
        }
    }
    cout<<ans.size();

}