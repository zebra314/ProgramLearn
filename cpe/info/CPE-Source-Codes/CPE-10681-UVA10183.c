#include <stdio.h>
#include <string.h>
#define MAX 102
#define MAXFIB 500
char bigNumA[MAX];
char bigNumB[MAX];
char bigNumC[MAX];
char bigFibNum[MAXFIB][MAX];

void readBigNum(char *bignum, char *input) {
 int i, inputlen;
 inputlen=strlen(input);
 memset(bignum, 0, MAX);
 for(i=inputlen-1; i>=0; --i)
     bignum[inputlen - i - 1] = input[i] - '0';
}

void bigAssign(char *bignum, int n) {
   int i=0;
   memset(bignum, 0, MAX); 
   while(n!=0){
        bignum[i++]=n%10;
        n/=10;
   }
}


void bigAdd(char *sum, char *a, char *b)
{
    int i, carry;
    for(carry=i=0; i<MAX; ++i){
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 10;
        sum[i]%=10;
    }
}

int bigNumCmp(char *a, char *b)
{
    int i=MAX-1;
    while(i>0 && a[i]==b[i]) --i;
    return a[i]-b[i];
}


void preCalculateFib() 
{ 
   int i=2,count=2; 

   bigAssign(bigFibNum[0],1);
   bigAssign(bigFibNum[1],1);
   bigAssign(bigNumA,1);
   bigAssign(bigNumB,1);

   for(;;) { 
      if (count> 500) break; 
      bigAdd(bigNumC, bigNumA, bigNumB);
      memcpy(bigFibNum[i], bigNumC, MAX);
      i++; 
      memcpy(bigNumA, bigNumB, MAX);
      memcpy(bigNumB, bigNumC, MAX);
      count++;	 
   } 
}
void bigNumPrint(char *bigNum)
{
    int i=MAX-1;
    for(i=MAX-1;i>0 && bigNum[i]==0; --i);
    while(i>=0) printf("%d", bigNum[i]), --i;
}

int main() 
{ 
  int count; 
  int i; 
  char from[MAX],to[MAX]; 
  char bfrom[MAX], bto[MAX];
  char bzero[MAX];

  preCalculateFib();
  bigAssign(bzero,0);

  for (;;) {
    scanf("%s %s",from,to); 
    readBigNum(bfrom, from);
    readBigNum(bto, to);
    if (bigNumCmp(bfrom,bzero)==0 && bigNumCmp(bto, bzero)==0) break;
    count=0; 
    for(i=1;i<MAXFIB; ++i) { 
      if (bigNumCmp(bigFibNum[i], bfrom) < 0) continue;
      if (bigNumCmp(bigFibNum[i], bto) > 0) break;
      count++; 
    } 
    printf("%d\n",count); 
  } 
  return 0;
} 

