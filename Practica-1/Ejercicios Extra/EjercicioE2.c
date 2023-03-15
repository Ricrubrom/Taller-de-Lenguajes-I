#include <stdio.h>

int BinarioIterativo(int num);
int BinarioRecursivo(int num,int repeticion);

int invertir(int num){
  int aux=0;
  while(num!=0){
    aux = aux * 10 + (num % 10);
    num /= 10;
  }
  return aux;
}

int main(){
  printf("El numero %d en binario es %08d", 5, invertir(BinarioRecursivo(25,0)));
  return 0;
}

int BinarioIterativo(int num){
  int res=0;
  while (num!=0){
    res = res * 10 + num % 2;
    num/=2;
  }
  return res;
}

int BinarioRecursivo(int num, int res){
  if (num<=1)
    return res*10+num;
  else {
    return BinarioRecursivo(num / 2, res * 10 + num % 2);
  }
}