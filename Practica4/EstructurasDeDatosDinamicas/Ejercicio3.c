#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  printf("Inserte un numero: ");
  int n;
  scanf("%d", &n);
  int *p = (int *)malloc(sizeof(int) * n);
  int max = -999999;
  for (int i = 0; i < n; i++)
  {
    p[i] = rand();
    if (p[i]>max)
      max = p[i];
  }
  printf("El maximo numero es %d", max) ;
  return 0;
}