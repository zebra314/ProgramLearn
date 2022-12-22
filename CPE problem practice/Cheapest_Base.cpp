#include<bits/stdc++.h>
using namespace std;

int main(){
    int case_1, case_2, price, ans;
    int cheapest_price, cheapest;
    vector<int> cost;
    cin>>case_1;
    int i = 0;
    while(i<case_1 and ++i){
        cout<<"Case "<<i<<": \n";
        for(int j = 0;j<36; j++){
            cin>>price;
            cost.push_back(price);
        }
        cin>>case_2;
        int num;
        int base;
        int coco; // the copy of num
        while(case_2--){
            cin>>num;
            cheapest = 1000000;
            for(int j = 2; j<=36; j++){
                price = 0;
                coco = num;
                while(coco!=0){
                    price += cost[coco%j];
                    coco /= j;
                }
                if(price < cheapest) {
                    cheapest = price;
                    base = j;
                }
            }
            cout<<base<<'\n';
        }
    }
}