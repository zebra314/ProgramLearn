#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int sequence[2][50];
int *seqOld,*seqNew;
int main()
{
   string str;
   int N;
   char left,op;
   int num;
   while(cin>>str>>N){
      stack<int>stack_num;
      stack<char>stack_op;
      stringstream ss(str);
      while(1){
         ss>>left>>num>>op;
         stack_num.push(num);
         stack_op.push(op);
         if(op==']')   break;
      }
      while(1){
         num=stack_num.top(); 
         stack_num.pop();
         op=stack_op.top(); 
         stack_op.pop();
         if(op==']'){
            seqOld=sequence[0];
            seqNew=sequence[1];
            for(int i=0;i<N;i++){
               seqNew[i]=num;
            }
         }else if(op=='+'){
            swap(seqOld,seqNew);
            seqNew[0]=num;
            for(int i=1;i<N;i++){
               seqNew[i]=seqNew[i-1]
                  +seqOld[i-1];
            }
         }else if(op=='*'){
            swap(seqOld,seqNew);
            seqNew[0]=num*seqOld[0];
            for(int i=1;i<N;i++){
               seqNew[i]=seqNew[i-1]
                  *seqOld[i];
            }
         }
         if(stack_num.empty()) break;
      }
      cout<<seqNew[0];
      for(int i=1;i<N;i++){
         cout<<" "<<seqNew[i];
      }
      cout<<endl;
   }
   return 0;
}
