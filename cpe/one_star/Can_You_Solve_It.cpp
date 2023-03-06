#include<bits/stdc++.h>
using namespace std;

int main(){
    int times;
    int x_1, y_1, x_2, y_2;
    cin>>times;
    long long int steps;
    int i = 1;
    while(times--){
        steps = 0;
        cin>>y_1>>x_1>>y_2>>x_2;
        // set x_2, y_2 to be the bigger one.
        if((x_1+y_1)>(x_2+y_2)){
            swap(x_1, x_2);
            swap(y_1, y_2);
        }
        steps += abs(x_1+y_1-x_2-y_2);
        if((x_1 + y_1)!= (x_2+y_2)){
            steps += y_2 + x_1;
            for(int i = x_1+y_1+1; i<x_2+y_2; i++){
                steps+=i;
            }
        }
        else {
            steps+= abs(y_2-y_1);
        }
            
        cout<<"Case "<<i++<<": ";
        cout<<steps<<'\n';
    }
}