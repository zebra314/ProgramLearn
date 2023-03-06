#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void findMiddleValue(int n)
{
int i;
int *value;
int middleValue;
int possibleValues=1;
int mid, num;

value=(int*)malloc(n*sizeof(int));
for(i=0 ; i<n ; i++)
scanf("%d", &(value[i]));

qsort (value, n, sizeof(int), compare);

mid = n / 2;
if(n%2==1){
num=findOccurrence(value, 
value[mid], n);
middleValue=*(value+mid);
}
else if(value[mid-1]==value[mid]){
num=findOccurrence(value, value
[mid - 1], n);
middleValue=*(value+mid-1);
}
else{
num = findOccurrence(value, value
[mid - 1], n) + findOccurrence(value,
 value[mid], n);
middleValue=*(value+mid-1);
possibleValues=*(value+mid)-*(value+
mid-1)+1;
}

printf("%d %d %d\n", middleValue, num,
possibleValues);

	free(value);
}

int compare (const void * a, const void * b)
{
return ( *(int*)a - *(int*)b );
}

int findOccurrence(int* value, int 
middleValue, int n)
{
int i=-1, count=0;
for(i=0 ; i<n && (*(value+i)<=
middleValue); i++)
if(*(value+i)==middleValue)
count++;

	return count;
}

int main()
{
int n;
while(scanf("%d", &n)!=EOF )
findMiddleValue(n);
return 0;
}
