#include <stdio.h>
float * minMax (int n){
  int num, min = 0, max = 0;
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero flotante: ");
    scanf("%f", &num);
    if (num>max)
      max = num;
    else if (num<min)
      min = num;
  }
  static float res[2];
  res[0] = min;
  res[1] = max;
  return res;
}

int main(){
  float * res[2] = minMax(5);
  printf("min: %f \n max: %f", res[0], res[1] );
  return 0;
}