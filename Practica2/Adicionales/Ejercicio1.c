#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int array[], int len);

int main(){
  int array[10];
  srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    array[i] = rand() % 10;
  }
  printf("Array desordenado: ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  sort(array, 10);
  printf("Array ordenado: ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  return 0;
}

void sort(int array[], int len){
    int i, key, j;
    for (i = 1; i < len; i++) {                     
        key = array[i];                             
        j = i-1;                                    
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}