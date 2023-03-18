#include <stdio.h>
int invertir(int num);
int main(){
  printf("%d",invertir(13923));
  return 0;
}

int invertir(int num){
  int aux=0;
  while(num!=0){
    aux = aux * 10 + (num % 10);
    num /= 10;
  }
  return aux;
}