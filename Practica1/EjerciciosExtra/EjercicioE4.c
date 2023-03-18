#include <stdio.h>

int suma(int num);

int main(){
  int num;
  do
  {
    printf("\nInserte un numero entero (0 Finaliza la carga): ");
    scanf("%d", &num);
    if (num!=0)
      suma(num);
  } while (num!=0);
  return 0;
}

int suma(int num){
  int aux;
  printf("\n%d", num);
  while(num>=10){
    aux=0;
    while (num!=0)
    {
    aux += (num % 10);
    num /= 10;
    }
  printf(" -> %d", aux);
  num = aux;
  }
  return aux;
}