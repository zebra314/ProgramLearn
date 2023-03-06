#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926535
int main()
{
   double s,a;
   char unit[4];
   double arc,chord;
   while(scanf("%lf %lf %s",
         &s,&a,unit)>0){
      arc=2*PI*(s+6440)*a/360.0;
      chord=(s+6440)*sin(a*PI/2/180)*2;
      if(strcmp(unit,"min")==0){
         arc=arc/60;
         chord=chord/60;
      }
      printf("%.6lf %.6lf\n",arc,chord);
   }
   return 0;
}
