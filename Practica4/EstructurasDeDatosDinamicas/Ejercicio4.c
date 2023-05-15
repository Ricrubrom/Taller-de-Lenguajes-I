#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Inserte un numero: ");
  int n;
  scanf("%d", &n);
  float *p = (float *)malloc(sizeof(float) * n);
  float tot = 0;
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero: ");
    scanf("%f", &p[i]);
    tot += p[i];
  }
  printf("El promedio es %f", tot/n) ;
  return 0;
}