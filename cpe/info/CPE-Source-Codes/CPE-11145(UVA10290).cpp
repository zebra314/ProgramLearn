#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 30000000
char n[MAX]={};
long long primes[2000000];
int pcount=0;
void setprimes(){
int i,j,k,m;
m=sqrt(MAX);
primes[0]=2;	
for(i=3;i<m;i+=2){
if(n[i]==0){
k=2*i;
for(j=i*i;j<MAX;j+=k){
n[j]='1';	
}	
}
}
j=1;
for(i=3;i<MAX;i+=2){
if(n[i]==0){
primes[j]=i;
j++;
}
}
pcount=j;	
}
int main(){
long long n;
int count,i,tmp,ans;
setprimes();
while(scanf("%lld",&n)!=EOF){
if(n == 0){
printf("1\n");;	
}
else{
ans=1;
while(n%2 == 0){
n/=2;
}
for(i=1;i<pcount;i++){ 
            if((primes[i]*primes[i])>n){
break;
}
count=0;
	while(n%primes[i] == 0){
n/=primes[i];
count++;
}
ans*=(count+1);	
   }
if(n!=1){
ans*=2;
}
printf("%d\n",ans);
}
}	
return 0;	
}
