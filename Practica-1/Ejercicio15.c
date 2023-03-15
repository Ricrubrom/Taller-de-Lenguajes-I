#include <stdio.h>
int FacIt(long unsigned int num);
int FacRec(long unsigned int num);
int main(){
  printf("%d \n", FacIt(4));
  printf("%d", FacRec(4));
  return 0;
}

int FacIt(long unsigned int num){
  int i, aux = 1;
  for ( i = 1; i <= num; i++)
  {
    aux *= i;
  }
  return aux;
}

int FacRec(long unsigned int num){
  if (num!=1)
    return (num * (FacRec(num - 1)));
  return num;
}