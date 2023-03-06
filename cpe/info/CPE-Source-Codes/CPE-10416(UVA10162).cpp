#include <iostream>
using namespace std;
char bigN[101]; 
int table[200]; 
int NPowerOfN(int n){
   int nn=1;
   for(int i=1;i<=n;i++){
      nn = nn*n;
      nn %= 10;
   }
   return nn;
}
int sumN(int n){
   int sum=0;
   for(int i=1;i<=n;i++){
      sum += NPowerOfN(i);
      sum %= 10; 
   }
   return sum;
}
void tryRule(int firstN)
{
   for(int n=1;n<=firstN;n++){
      cout<<"«en¶µ:"<<n
          << " NPowerOfN:"<<NPowerOfN(n)
          << " sum:"<<sumN(n)<<endl;}
   }
}
int main()
{
   //tryRule(100); 
   //tryRule(200); 
   for(int i=1;i<=100;i++){
      table[i%100]=sumN(i);
   }
   while(cin>>bigN){
      int len=strlen(bigN);
      int n=bigN[len-1]-'0' 
          +(bigN[len-2]-'0')*10; 
      cout<<table[n]<<endl; 
   }
   return 0;
}
