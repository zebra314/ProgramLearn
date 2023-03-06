#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{
   double a;
   double x,y,z;
   double eq1,eq2,eq3,eq4,eq5,triangle;
   while(scanf("%lf",&n)==1){
      eq1=a*a;
      eq2=PI*a*a/4;
      triangle=a*a*sqrt(3)/2/2;
      eq3=PI*a*a/6*2-triangle;
      eq4=eq2-eq3;
      eq5=eq1-eq2;
      z=eq5-eq4;
      z=eq1-2*eq2+eq3;
      y=eq4-z;
      x=eq1-4*y-4*z;
      printf("%.3lf %.3lf %.3lf\n",
         x,4*y,4*z);
   }
   return 0;
}
