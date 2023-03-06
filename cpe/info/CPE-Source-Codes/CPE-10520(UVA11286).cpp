#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cp(const void *a, const void *b){
    return (*(int*)a - *(int*)b ); 
}
struct node{
    int num;
    struct node *next[500];
};

int main(){
    int i, j, k, n, num[8], max, cnt;
    struct node *root, *tmp1, *tmp2;
    while(scanf("%d", &n)){
        if(n==0)
            return 0;
        root = new node;
        for(i=100; i<500; i++)
            root->next[i] = NULL;
        root->num = 0;
        max = 0;
        cnt = 0;

        for(i=0; i<n; i++){
            for(j=0; j<5; j++)
                scanf("%d", &num[j]);
            qsort(num, 5, sizeof(int), cp);
            tmp1 = root;
            for(j=0; j<5; j++){
                if(tmp1->next[num[j]] 
== NULL){
                    tmp2 = new node;
                    for(k=100; k<500; k++){
                        tmp2->next[k] =
NULL;
                        tmp2->num = 0;
                    }
                    tmp1->next[num[j]] =
 tmp2;
                }
                tmp1 = tmp1->next[num[j]];
            }
            tmp1->num++;
            if(tmp1->num > max){
                max = tmp1->num;
                cnt = max;
            }else if(tmp1->num == max){
                cnt += max;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
