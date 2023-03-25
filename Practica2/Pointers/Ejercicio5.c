#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *p, int length);

int main(){
  int A[5]={1,2,3,4,5};
  int *p = A;
  Swap(p, sizeof(A)/sizeof(A[0]));
  printf("El arreglo invertido es: ");
  for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
  {
    printf("%d ", A[i]);
  }
  return 0;
}

void Swap(int *p, int length){
  int aux;
  int *p2 = p + length - 1;
  for (int i = 0; i < length/2; i++)
  {
    aux = *p;
    *p = *p2;
    *p2 = aux;
    p++;
    p2--;
  }