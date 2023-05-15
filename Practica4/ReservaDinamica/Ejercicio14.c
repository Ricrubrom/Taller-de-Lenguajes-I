#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** reserveMem(int * n){
  printf("Ingrese de que orden quiere la matriz triangular inferior: ");
  scanf("%d", n);
  int columns = 1;
  int** array;
  array = (int**) malloc((*n)*sizeof(int*));
  for (int i = 0; i<(*n); i++) {
    array[i] = (int*) malloc(columns*sizeof(int));
    columns++;
  }
  return array;
}

void initArray(int **array, int n){
  srand(time(0));
  int columns=0;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j <= columns; j++)
    {
      array[i][j] = rand()%21;
    }
    columns++;
  }
}

void printArray(int **array, int n){
  int columns=0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= columns; j++)
    {
      printf("%d ", array[i][j]);
    }
    columns++;
    printf("\n");
  }
}

void freeMem(int ***array, int n){
  for (int i = 0; i < n; i++)
  {
    free(*array[i]);
  }

  free(*array);
}

int main(){
  int n;
  int **array = reserveMem(&n);
  initArray(array, n);
  printArray(array, n);
  freeMem(&array, n);
  return 0;
}