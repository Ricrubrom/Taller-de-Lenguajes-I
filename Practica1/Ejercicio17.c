#include <stdio.h>
void minMax (int n, float *min, float *max){
  float num;
  *min = 99999;
  *max = 0;
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero flotante: ");
    scanf("%f", &num);
    if (num>*max)
      *max = num;
    else if (num<*min)
      *min = num;
  }
}

int main(){
  float min, max;
  minMax(3, &min, &max);
  printf("min: %.2f \n max: %.2f", min, max );
  return 0;
}