#include<bits/stdc++.h>
using namespace std;

void Find_cheapest_set(long long int num, vector<int> cost){
    int base, price; // the copy of num
    long long int coco;
    map<int, set<int>> price2base; // key->price, value->base
    set<int> coprice; // the base with same price
    cout<<"Cheapest base(s) for number "<<num<<":";
    int cheapest ;
    for(int j = 2; j<=36; j++){ // base
        price = 0;
        coco = num;
        while(coco!=0){
            price += cost[coco%j];
            coco /= j;
        }
        price2base[price].insert(j);
        if(j == 2){
            cheapest = price;
        }
        else if(price < cheapest) {
            cheapest = price;
        }
    }
    for(const auto &ele : price2base[cheapest])
        cout<<" "<<ele;
    cout<<'\n';
}
int main(){
 
    int case_1, case_2, price;
    int cheapest;
    long long int num;
    vector<int> cost;
    cin>>case_1;
    int i = 0;
    while(i<case_1 and ++i){
        cost.clear();
        if(i>1) cout<<'\n';
        cout<<"Case "<<i<<":"<<'\n';
        for(int j = 0;j<36; j++){
            cin>>price;
            cost.push_back(price);
        }
        cin>>case_2;
        while(case_2--){
            cin>>num;
            Find_cheapest_set(num, cost);
        }
    }
}