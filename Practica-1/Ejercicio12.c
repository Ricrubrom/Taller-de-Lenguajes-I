#include <stdio.h>
#include <math.h>

int main(){
  int i;
  for (i = 1; i <= 10; i++)
  {
    printf("La raiz de %d es: %5.2f \n", i , sqrt(i));
    printf("el cuadrado de %d es: %5.2f \n", i , pow(i,2));
    printf("La cubo de %d es: %5.2f \n", i , pow(i,3));
  }
  return 0;
}