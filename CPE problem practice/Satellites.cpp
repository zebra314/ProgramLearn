#include<bits/stdc++.h>
using namespace std;

int main(){
    double distance, angular_displacement, R = 6440, pi = 3.141592653589793238462643383;
    string unit;
    while(cin>>distance>>angular_displacement>>unit){
        if(unit == "min"){
           angular_displacement /= 60;
        }
        while(angular_displacement >= 360){
            angular_displacement -= 360;
        }
        if(angular_displacement > 180){
            angular_displacement = 360 - angular_displacement;
        }
        cout<<fixed<<setprecision(6)<<2*pi*(distance+R)*angular_displacement/360<<" ";
        cout<<fixed<<setprecision(6)<<2*(distance+R)*sin(angular_displacement*pi/360)<<'\n';
    }
}