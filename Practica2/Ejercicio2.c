#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

float prom(float array[]);
float min(float array[]);
int maxPos(float array[]);

int main(){
  float array[SIZE];
  srand(time(0));
  for (int i = 0; i < SIZE; i++)
  {
    array[i] = (float)rand()/(rand()+1);
  }
  printf("Promedio: %f \n", prom(array));
  printf("Minimo: %f \n", min(array));
  printf("Posicion del maximo: %d \n", maxPos(array));
  return 0;
}


float prom(float array[]){
  float tot = 0;
  for (int i = 0; i < SIZE; i++)
  {
    tot += array[i];
  }
  return tot / SIZE;
}

float min(float array[]){
  float min = array[0];
  for (int i = 1; i < SIZE; i++)
  {
    if (array[i] < min)
      min = array[i];
  }
  return min;
}

int maxPos(float array[]){
  int maxPos = 0;
  for (int i = 1; i < SIZE; i++)
  {
    if (array[i] > array[maxPos])
      maxPos = i;
  }
  return maxPos;
}
