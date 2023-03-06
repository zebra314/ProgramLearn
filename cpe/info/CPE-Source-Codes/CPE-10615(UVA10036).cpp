#include<iostream>
using namespace std;
int main()
{
   int m = 0;
   cin>> m;
   while(m--){
      int n,k;
      cin>>n>>k;
      int input[10001]={};
      for(int i=1;i<=n;++i)
         cin>>input[i];
      bool arr[100]={};
      int x=input[1]%k;
      if(x<0)
         x=k+x;
      arr[x] = 1;
      for(int i=2;i<= n;i++){
         int arrTmp[100]={};
         for(int j=0;j<k;j++){
            if(arr[j]==true){
               int m1=(j+input[i])%k;
               if(m1<0)
                  m1=k+m1;
               int m2=(j-input[i])%k;
               if(m2<0)
                  m2=k+m2;
               arrTmp[m1]=true;
               arrTmp[m2]=true;
            }
         }
         for(int i=0;i<k;++i)
            arr[i]=arrTmp[i];
      }
      if(arr[0]==true)
         cout<<"Divisible\n";
      else
         cout<<"Not divisible\n";
   }
}
