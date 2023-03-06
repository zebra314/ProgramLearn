#include <stdio.h>
#include <math.h>
#define MIN(X,Y) ((X>Y)?Y:X)

int main()
{
  float L,W;
  float MaxX,MinX;
  while(scanf("%f %f",&L,&W)==2){
    MaxX=((L+W)-sqrt(L*L-L*W+W*W))/6.0;
    MinX=MIN(L,W)*0.5;
    printf("%.3f %.3f %.3f\n", 
      MaxX, 0.0, MinX);
  }
  return 0;
}
