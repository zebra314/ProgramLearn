#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i=0,j=0,charnumber=0;
   int indexToBinary=0;
   char input[4];
   char in,pre;
   char base64[]="ABCDEFGHIJKLMNOPQRS
        TUVWXYZabcdefghijklmnopqrstuv
        wxyz0123456789+/=";
   while(scanf("%c",&in)==1)
   {
      for(j=0;in!=base64[j] && j<66;j++);
      if(j<65)
      {
         input[charnumber]=in;
         pre=in;
         charnumber++;
      }
      else if(in=='#')
      {
         if(pre!='#')
         {
            printf("#");
            pre='#';
         }
      }
      if(charnumber==4)
      {
         for(i=0;i<4;i++)
         {
            if(input[i]=='=')
               indexToBinary <<=6;
            else
            {
               for(j=0;input[i]!=base64[j]
                  &&j<66;j++);
                  indexToBinary =
                  ((indexToBinary <<6)+j);
            }
         }
         printf("%c", indexToBinary >>16);
         if(input[2]!='=')
            printf("%c",indexToBinary >>8);
         if(input[3]!='=')
            printf("%c",indexToBinary);
         charnumber=0;
         indexToBinary =0;
      }
   }
   return 0;
}
