#include<stdio.h>
int prime(int p){
   int i;
   for(i=2;i*i<=p;i++)
      if(p%i==0)
         return 0;
   return 1;
}
char t[10000];
int main(){
   int i,a,b,c,num;
   memset(t,0,sizeof(t));
   while(scanf("%d %d",&a,&b)!=EOF){
      c=0;
      for(i=a;i<=b;i++){
         if(t[i]==0){
            num=i*i+i+41;
            if(prime(num)){
               t[i]=1;
               c++;
            }else{
               t[i]=2;
            }
         }else if(t[i]==1)
            c++;
      }
      printf("%.2lf\n",((double)c/(b-a+1)*100)+0.00001);
   }
   return 0;
}
