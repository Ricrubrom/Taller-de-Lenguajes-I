#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void Retorno(float array[], float *prom, float *min, int *maxPos);

int main(){
  float array[SIZE];
  float prom;
  float min;
  int maxPos;
  srand(time(0));
  for (int i = 0; i < SIZE; i++)
  {
    array[i] = (float)rand()/(rand()+1);
  }
  Retorno(array, &prom, &min, &maxPos);
  printf("El promedio es %f \n", prom);
  printf("El minimo es %f \n", min);
  printf("La posicion del maximo es %d \n", maxPos);
  return 0;
}


void Retorno(float array[], float *prom, float *min, int *maxPos){
  *prom = 0;
  *min = array[0];
  *maxPos = 0;
  for (int i = 0; i < SIZE; i++)
  {
    *prom += array[i];
    if (array[i] < *min)
      *min = array[i];
    if (array[i] > array[*maxPos])
      *maxPos = i;
  }
  *prom /= SIZE;
}
