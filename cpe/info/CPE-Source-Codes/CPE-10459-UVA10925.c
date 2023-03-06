#include <stdio.h>
#include <string.h>
#define MAX 102
#define MAXFIB 500
char bigNumA[MAX];
char bigNumB[MAX];
char bigNumC[MAX];
char bigFibNum[MAXFIB][MAX];
char bigzero[MAX];

void bigNumPrint(char *bigNum)
{
    int i;
    for(i=MAX-1;i>0 && bigNum[i]==0; --i);
    while(i>=0) printf("%d", bigNum[i]), --i;
}

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

void bigNumSub(char *c, char *a, char *b){
    int i, borrow;
    for(borrow=i=0; i<MAX; ++i) {
        c[i] = a[i]-b[i]-borrow; 
        if(c[i]<0) {
            borrow=1, c[i]+=10; 
        } else {
            borrow=0; 
        }
    }
}

void bigNumMul(char *tc, char *a, char *b){
    int i, j, carry;
    char c[MAX];
    memset(c, 0, MAX); 
    for(i=0; i<MAX; ++i) {
        if(a[i]==0) continue;
        for(j=0; i+j<MAX; ++j)
            c[i+j] += a[i]*b[j];
    }
    for(carry=i=0; i<MAX; ++i) {
        c[i]+=carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }
    memcpy(tc, c, MAX);
}

int simpleDiv(char *a, char *b) {
     int i;
     char tmp[MAX];
     memcpy(tmp,a,MAX);
     for (i=0;;i++) {
        if (bigNumCmp(tmp, b) <0) break;
        bigNumSub(tmp,tmp,b);
     }
     return i;
}

int calDiff(char *a, char *b) {

   int i,j;
   for (i=MAX-1; i>0 && a[i]==0; --i);
   for (j=MAX-1; j>0 && b[j]==0; --j);
   return (i-j);
}

void shiftDiff(char *r, char *a, int diff) {
   int i;
   memset(r, 0, MAX); 
   for (i=MAX-1; i>0 && a[i]==0; --i);
   for (; i>=0; i--) 
      r[i+diff] = a[i];
}

void bigNumDiv(char *tr, char *a, char *b) {
   char tmpa[MAX];
   char tmpb[MAX];
   char tmpq[MAX];
   char r[MAX];
   int Q;
   int diff;

   memcpy(tmpa,a,MAX);
   memset(r, 0, MAX); 
   
   for (diff=calDiff(a,b);diff >= 0;diff--) {
     shiftDiff(tmpb, b, diff);
     Q = simpleDiv(tmpa, tmpb);
     bigAssign(tmpq, Q);
     bigNumMul(tmpq, tmpq, tmpb);
     bigNumSub(tmpa,tmpa,tmpq);
     r[diff] = Q;
   } 
   memcpy(tr, r, MAX);

}
 

int main() 
{ 
  int  N, F, i, turn=1; 
  char inbuf[MAX+1], price[MAX], sum[MAX], bigF[MAX], divsum[MAX] ;

  bigAssign(bigzero, 0);

  for (;;) {
    scanf("%d %d",&N,&F); 
    if (N==0 && F==0) break;
    bigAssign(price, 0);
    bigAssign(sum, 0);
    bigAssign(bigF,F);
    for (i=0;i<N;i++) {
      scanf("%s",inbuf);
      readBigNum(price, inbuf);
      bigAdd(sum, sum, price);
    }
    printf("Bill #%d costs ", turn++);
    bigNumPrint(sum);
    printf(": each friend should pay ");
    bigNumDiv(divsum,sum,bigF);
    bigNumPrint(divsum);
    printf("\n\n"); 
  } 
  return 0;
} 

