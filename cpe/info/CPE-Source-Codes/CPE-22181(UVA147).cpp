#include <iostream>
#include <iomanip>
using namespace std;
const int MAX=300*10+1,NUM_COIN=11;
long long int ans[MAX];
int coin[NUM_COIN]=
   {0,1,2,5,10,20,50,100,200,500,1000};
int main(){
   for(int i=0;i<MAX;i++)
      ans[i]=1;
   for(int j=1;j<NUM_COIN;j++){
      for(int i=coin[j];i<MAX;i++){
         ans[i]+=ans[i-coin[j]];
      }
   }
   double x;
   cout<<fixed<<setprecision(2);
   while(cin>>x){
      if(x==0.00)
         break;
      cout<<setw(6)<<x;
      cout<<setw(17)<<ans[int(x*10.0)]<<endl;
   }
   return 0;
}
