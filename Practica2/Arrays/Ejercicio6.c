#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int digitos[10]={0};
  printf("Ingrese un numero: ");
  int n,aux;
  scanf("%d", &n);
  while (n > 0)
  {
    digitos[n%10]++;
    n /= 10;
  }
  for (int i = 0; i < 10; i++)
  {
    printf("%d: %d \n", i, digitos[i]);
  }
  return 0;
}