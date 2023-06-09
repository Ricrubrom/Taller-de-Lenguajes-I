#include <stdio.h>
#include <stdlib.h>
#define SIZE 25

void imprimir(int * v, int size){
  int i;
  for (i=0; i<size; i++){
  printf("v[%d]= %d\n", i, v[i]);
  }
}
int main(){
  int v[SIZE];
  imprimir(v, SIZE);
  return 0;
}