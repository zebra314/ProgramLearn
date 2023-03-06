#include<stdio.h>
bool find(int n,int m){
   int crisis[100],last,cnt,i,k;
   for(i=0;i<100;i++)
      crisis[i]=0;
      for(i=1,k=m,cnt=0;cnt<n;){
         if(!crisis[i]&&i<=n){
            if(k==m){
               last=i;
               cnt++;
               k=crisis[i]=1;
            }
            else{
               i++;
               k++;
            }
         }
      else{
         i++;
         if(i>n)
            i=1;
      }
   }
   if(last==13)
      return true;
   return false;
}
int main(){
   int n,m;
   while(scanf("%d",&n)==1&&n!=0){
      for(m=1;;m++)
         if(find(n,m)){
            printf("%d\n",m);
          break;
         }
   }
   return 0;
}
