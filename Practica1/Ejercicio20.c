#include <stdio.h>

int damePar(int num);

int main(){
  int num, cant;
  printf("Inserte la cantidad de numeros pares deseados: ");
  scanf("%d", &cant);
  for ( num = 0; num < cant; num++)
  {
    printf("%d \n", damePar(num));
  }
  
  return 0;
}

int damePar(int num){
  return 2 * num;
}