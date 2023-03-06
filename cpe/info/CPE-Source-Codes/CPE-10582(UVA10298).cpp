#include<stdio.h>
#include<string.h>
int main(){
   char s[1000001];

   int i,j,k,len,flag;
   while(scanf("%s",(char*)&s)!=EOF){
      if(s[0]=='.'&&s[1]=='\0'){
         break;
      }
      len=strlen(s);
      flag=0;
      for(i=1;i<=len&&flag==0;i++){
         flag=1;

         for(j=i;j<len&&flag==1;j+=i){
            for(k=0;k<i&&flag==1;k++){
               if(s[k]!=s[j+k]){
                  flag=0;
               }
            }
         }
         if(flag){
            printf("%d\r\n",len/i);
            break;
         }
      }
   }
   return 0;
}
