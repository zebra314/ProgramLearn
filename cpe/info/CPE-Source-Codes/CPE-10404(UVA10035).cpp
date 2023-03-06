#include<iostream>
using namespace std;
int divide(int n,int arr[],int &cnt){
   for(cnt=0;n!=0;cnt++){
      arr[cnt]=n%10;
      n/=10;
   }
}
int main(){
   int a, b;
   while(cin>>a>>b && (a!=0||b!=0)){
      int lenA, lenB;
      int arrA[11]={},arrB[11]={};
      int sum[12]={};
      divide(a,arrA,lenA);
      divide(b,arrB,lenB);
      int lenM=max(lenA,lenB);
      int ans=0;
      for(int i=0;i<lenM;++i){
         sum[i]+=(arrA[i]+arrB[i]);
         if(sum[i]>=10){
            sum[i]-=10;
sum[i+1]++;
            ++ans;
         }
      }
      if(ans==0)
         cout<<"No carry operation.\n";
      else if(ans==1)
         cout<<"1 carry operation.\n";
      else
         cout<<ans<<" carry operations.\n";
   }
   return 0;
}
