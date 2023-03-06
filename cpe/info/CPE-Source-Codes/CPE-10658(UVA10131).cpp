#include<stdio.h>
#include<limits.h>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define SIZE 1000

void initArra(int *ptr, int size, int
InitVal ){
int i;
for(i=0 ; i<size ; i++)
*(ptr+i)=InitVal;
}

int selector(int *iq, int *weight, int from,
 int count){
int i;
int indextmp=0, iqtmp=INT_MIN,
weighttmp=INT_MAX;
for(i=from ; i<count ; i++){
if(*(iq+i)>iqtmp){
iqtmp=*(iq+i);
weighttmp=*(weight+i);
indextmp=i;
}
else if(*(iq+i)==(iqtmp))	{
if(*(weight+i)<weighttmp){
weighttmp=*(weight+i);
indextmp=i;
}
}
}
return indextmp;
}

void swap(int *ptr, int i, int j){
int tmp=*(ptr+j);
*(ptr+j)=*(ptr+i);
*(ptr+i)=tmp;
}

void sortByIQWeight(int *iq, int *weight,
 int *id, int count){
int i, swapIndex;

for(i=0 ; i<count ; i++){
swapIndex=selector(iq, weight, i,
count);
swap(iq, i, swapIndex);
swap(weight, i, swapIndex);
swap(id, i, swapIndex);
}
}

int LIS(int *iq, int *weight, int
*predecessor, int *length, int count){
int i, j;
int maxLength=0, maxLengthIndex=-1;

for(i=0 ; i<count ; i++){
for(j=0 ; j<i ; j++){
if(*(weight+i)>*(weight+j) &&
*(iq+i)<*(iq+j) &&
*(length+i)<=*(length+j)){
*(predecessor+i)=j;
*(length+i)=*(length+j)+1;
if(maxLength<*(length+i)){
maxLength=*(length+i);
maxLengthIndex=i;
}
}
}
}
return maxLengthIndex;
}

void printLISid(int *id, int *predecessor,
 int *length, int LISmaxLengthIndex){
int i;
int *resultID=(int*)malloc(*(length
+LISmaxLengthIndex)*sizeof(int));
int indextmp=LISmaxLengthIndex;
printf("%d\n", *(length+
LISmaxLengthIndex));
for(i=*(length+LISmaxLengthIndex)-1 ;
 i>=0 ; i--){
resultID[i]=id[indextmp];
indextmp=predecessor[indextmp];
}

for(i=0 ; i<*(length+
LISmaxLengthIndex) ; i++)
printf("%d\n", resultID[i]);

free(resultID);
}

int main(){
int iq[SIZE];
int weight[SIZE];
int id[SIZE];
int count=0;
int predecessor[SIZE];
int length[SIZE];
int LISlastIndex=-1;

initArr(iq, SIZE, 0);
initArr(weight, SIZE, 0);
initArr(id, SIZE, 0);
initArr(predecessor, SIZE, -1);
initArr(length, SIZE, 1);

while(scanf("%d%d", (weight+count),
(iq+count))!=EOF)	{
id[count]=count+1;
count++;

if(count>SIZE)
return 1;
	}
sortByIQWeight(iq, weight, id, count);
LISlastIndex=LIS(iq, weight,
predecessor, length, count);
printLISid(id, predecessor, length,
LISlastIndex);

	return 0;
}

