#include <stdio.h>
#include <stdlib.h>
int main(){
  int rows = 2;
  int columns = 3;
  int **matrix = (int **)malloc(rows*sizeof(int *));
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = (int *)malloc(columns * sizeof(int));
  }
  
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("Inserte un numero: ");
      scanf("%d", &(matrix[i][j]));
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  for (int i = 0; i < rows; i++)
  {
    free(matrix[i]);
  }

  free(matrix);

  return 0;
}