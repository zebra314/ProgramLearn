#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int num, i;
    char buf[10240], tmp[10240];
    while(scanf("%s", tmp) != EOF){
        buf[0] = '\0';
        strcat(buf, tmp);
        while(buf[strlen(buf)-1] != '#'){
            scanf("%s", tmp);
            strcat(buf, tmp);
        }
        buf[strlen(buf)-1] = '\0';
        num = 0;
        for(i=strlen(buf)-1;i>=0; i--){            num *= 2;
            if(buf[i] == '1')
                num++;
            while(num >= 131071)
                num -= 131071;
        }
        if(num == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
