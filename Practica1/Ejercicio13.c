#include <stdio.h>

int nashe(int num);
int main(){
  int cant=0,num;
  while (cant<5)
  {
    printf("Inserte un numero entero: ");
    scanf("%d", &num);
    if (nashe(num))
      cant++;
  }
  printf("Felicidades has salido del videojuego brrrrrrrr ");
  return 0;
}

int nashe(int num){
  int i;
  for (i = 2; i < num; i++){
    if (num%i==0)
      return 0;
  }
  return 1;
}