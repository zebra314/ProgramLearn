#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
   int n;
   while(cin>>n,n){
      int *nbs=new int[n*n];
      #define nbs(x,y) nbs[x*n+y]
      for(int i=0;i<n*n;i++)nbs[i]=0;
      int m;cin>>m;
      while(m--){
         int x,y;cin>>x>>y;
         nbs(x,y)=nbs(y,x)=1;
      }
      vector<int> clr(n);clr[0]=1;
      stack<int> stk;stk.push(0);
      bool ans=true;
      while(stk.size()){
         int a=stk.top();stk.pop();
         for(int k=0;k<n;k++){
            if(!nbs(a,k))continue;
            if(clr[k]==0){
               clr[k]=-1*clr[a];
               stk.push(k);
            }else if(clr[k]==clr[a]){
               ans=false;
               break;
            }
         }
         if(ans==false)break;
      }
      delete[] nbs;
      if(ans)cout<<"BICOLORABLE."<<endl;
      else cout<<"NOT BICOLORABLE."<<endl;
   }
   return 0;
}
